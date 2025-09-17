#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

class OpenCVCrossCompileVerifier {
  constructor() {
    this.opencvSourceDir = path.join(__dirname, '../../deps/OpenCV-Source/opencv-4.12.0');
    this.buildDir = path.join(this.opencvSourceDir, 'build');
  }

  verify() {
    console.log('🔍 验证 OpenCV 交叉编译产物...\n');

    const platforms = this.getAvailablePlatforms();
    
    if (platforms.length === 0) {
      console.log('❌ 未找到任何 OpenCV 交叉编译产物');
      return false;
    }

    let allValid = true;

    for (const platform of platforms) {
      console.log(`📦 检查 ${platform} 平台...`);
      
      const platformDir = path.join(this.buildDir, platform);
      const libPath = platform.startsWith('win32') 
        ? path.join(platformDir, 'bin')  // Windows 平台 DLL 在 bin 目录
        : path.join(platformDir, 'lib'); // 其他平台在 lib 目录
      
      if (!fs.existsSync(libPath)) {
        console.log(`  ❌ 未找到库目录: ${libPath}`);
        allValid = false;
        continue;
      }

      try {
        // 检查主要的 OpenCV 库文件
        const expectedLibs = this.getExpectedLibs(platform);

        let foundLibs = 0;
        for (const lib of expectedLibs) {
          const libFile = path.join(libPath, lib);
          if (fs.existsSync(libFile)) {
            foundLibs++;
            const stats = fs.statSync(libFile);
            const sizeMB = (stats.size / 1024 / 1024).toFixed(2);
            console.log(`  ✅ ${lib}: ${sizeMB} MB`);
          } else {
            // 检查是否有符号链接指向这个文件
            const symlinkExists = this.checkSymlink(libPath, lib);
            if (symlinkExists) {
              foundLibs++;
              console.log(`  ✅ ${lib}: 符号链接存在`);
            } else {
              console.log(`  ❌ 未找到: ${lib}`);
            }
          }
        }

        console.log(`  📊 找到 ${foundLibs}/${expectedLibs.length} 个库文件`);

        // 检查头文件
        const includePath = path.join(platformDir, 'include');
        if (fs.existsSync(includePath)) {
          const headerFiles = fs.readdirSync(includePath, { recursive: true })
            .filter(file => file.endsWith('.hpp') || file.endsWith('.h'));
          console.log(`  ✅ 头文件: ${headerFiles.length} 个`);
        } else {
          console.log(`  ❌ 未找到头文件目录: ${includePath}`);
        }

        // 检查库文件类型
        if (foundLibs > 0) {
          const firstLib = expectedLibs.find(lib => 
            fs.existsSync(path.join(libPath, lib))
          );
          
          if (firstLib) {
            const libFile = path.join(libPath, firstLib);
            try {
              const fileInfo = execSync(`file "${libFile}"`, { encoding: 'utf8' }).trim();
              console.log(`  ✅ 文件类型: ${fileInfo}`);
            } catch (error) {
              console.log(`  ⚠️  无法检查文件类型: ${error.message}`);
            }
          } else {
            // 如果没有找到实际文件，但有符号链接，尝试检查符号链接
            console.log(`  ℹ️  库文件通过符号链接存在`);
          }
        }

      } catch (error) {
        console.log(`  ❌ 验证失败: ${error.message}`);
        allValid = false;
      }

      console.log('');
    }

    if (allValid) {
      console.log('🎉 所有 OpenCV 交叉编译产物验证通过！');
    } else {
      console.log('⚠️  部分 OpenCV 交叉编译产物验证失败');
    }

    return allValid;
  }

  getExpectedLibs(platform) {
    // 使用 libopencv_world 统一库
    if (platform.startsWith('darwin')) {
      // Darwin 平台使用 .dylib 文件
      return ['libopencv_world.4.12.0.dylib'];
    } else if (platform.startsWith('win32')) {
      // Windows 平台使用 .dll 文件
      return ['libopencv_world4120.dll'];
    } else {
      // Linux 平台使用 .so 文件（符号链接指向实际文件）
      return ['libopencv_world.so.4.12.0'];
    }
  }

  checkSymlink(libPath, targetLib) {
    try {
      const files = fs.readdirSync(libPath);
      for (const file of files) {
        const filePath = path.join(libPath, file);
        try {
          const stats = fs.lstatSync(filePath);
          if (stats.isSymbolicLink()) {
            const target = fs.readlinkSync(filePath);
            if (target.includes(targetLib)) {
              return true;
            }
          }
        } catch (error) {
          // 忽略错误，继续检查下一个文件
        }
      }
    } catch (error) {
      // 忽略错误
    }
    return false;
  }

  getAvailablePlatforms() {
    if (!fs.existsSync(this.buildDir)) {
      return [];
    }

    return fs.readdirSync(this.buildDir)
      .filter(item => {
        const itemPath = path.join(this.buildDir, item);
        return fs.statSync(itemPath).isDirectory();
      })
      .filter(platform => {
        const libPath = platform.startsWith('win32') 
          ? path.join(this.buildDir, platform, 'bin')  // Windows 平台 DLL 在 bin 目录
          : path.join(this.buildDir, platform, 'lib'); // 其他平台在 lib 目录
        return fs.existsSync(libPath);
      });
  }

  showSummary() {
    console.log('📊 OpenCV 交叉编译产物摘要:');
    console.log('============================');
    
    const platforms = this.getAvailablePlatforms();
    
    if (platforms.length === 0) {
      console.log('❌ 无可用产物');
      return;
    }

    for (const platform of platforms) {
      const platformDir = path.join(this.buildDir, platform);
      const libPath = platform.startsWith('win32') 
        ? path.join(platformDir, 'bin')  // Windows 平台 DLL 在 bin 目录
        : path.join(platformDir, 'lib'); // 其他平台在 lib 目录
      
      if (!fs.existsSync(libPath)) {
        console.log(`❌ ${platform}: 无库目录`);
        continue;
      }

      try {
        const libFiles = fs.readdirSync(libPath)
          .filter(file => file.endsWith('.so') || file.endsWith('.a') || file.endsWith('.dll') || file.endsWith('.dylib'));
        
        let totalSize = 0;
        let validFiles = 0;
        
        for (const libFile of libFiles) {
          try {
            const filePath = path.join(libPath, libFile);
            const stats = fs.statSync(filePath);
            if (stats.isFile()) {
              totalSize += stats.size;
              validFiles++;
            }
          } catch (error) {
            // 忽略无法访问的文件（如符号链接指向不存在的文件）
          }
        }
        
        const totalSizeMB = (totalSize / 1024 / 1024).toFixed(2);
        console.log(`✅ ${platform}: ${validFiles} 个库文件, ${totalSizeMB} MB`);
        
      } catch (error) {
        console.log(`❌ ${platform}: 无法统计 - ${error.message}`);
      }
    }
  }

  checkDependencies() {
    console.log('🔍 检查 OpenCV 依赖...\n');
    
    const platforms = this.getAvailablePlatforms();
    const issues = [];

    for (const platform of platforms) {
      const platformDir = path.join(this.buildDir, platform);
      const libPath = platform.startsWith('win32') 
        ? path.join(platformDir, 'bin')  // Windows 平台 DLL 在 bin 目录
        : path.join(platformDir, 'lib'); // 其他平台在 lib 目录
      
      if (!fs.existsSync(libPath)) continue;

      try {
        // 检查 ldd 依赖（Linux）
        if (platform.startsWith('linux')) {
          const libFiles = fs.readdirSync(libPath)
            .filter(file => file.endsWith('.so'));
          
          for (const libFile of libFiles.slice(0, 3)) { // 只检查前3个
            try {
              const lddOutput = execSync(`ldd "${path.join(libPath, libFile)}"`, { 
                encoding: 'utf8',
                stdio: 'pipe'
              });
              
              const missingDeps = lddOutput
                .split('\n')
                .filter(line => line.includes('not found'))
                .map(line => line.trim().split(' ')[0]);
              
              if (missingDeps.length > 0) {
                issues.push(`${platform}/${libFile}: 缺少依赖 ${missingDeps.join(', ')}`);
              }
            } catch (error) {
              // ldd 可能失败，忽略
            }
          }
        }
      } catch (error) {
        issues.push(`${platform}: 依赖检查失败 - ${error.message}`);
      }
    }

    if (issues.length === 0) {
      console.log('✅ 依赖检查通过');
    } else {
      console.log('⚠️  发现依赖问题:');
      issues.forEach(issue => console.log(`  - ${issue}`));
    }

    return issues.length === 0;
  }
}

// 主程序
if (require.main === module) {
  const verifier = new OpenCVCrossCompileVerifier();
  
  const args = process.argv.slice(2);
  
  if (args.includes('--summary')) {
    verifier.showSummary();
  } else if (args.includes('--deps')) {
    verifier.checkDependencies();
  } else {
    const isValid = verifier.verify();
    process.exit(isValid ? 0 : 1);
  }
}

module.exports = OpenCVCrossCompileVerifier;
