#!/usr/bin/env node

const fs = require('fs');
const path = require('path');

class OpenCVBuildCleaner {
  constructor() {
    this.opencvSourceDir = path.join(__dirname, '../../deps/OpenCV-Source/opencv-4.12.0');
    this.buildDir = path.join(this.opencvSourceDir, 'build');
  }

  async clean() {
    console.log('🧹 清理 OpenCV 构建中间产物...\n');

    if (!fs.existsSync(this.buildDir)) {
      console.log('❌ 构建目录不存在，无需清理');
      return;
    }

    // 获取清理前的目录大小
    const beforeSize = await this.getDirectorySize(this.buildDir);
    console.log(`📊 清理前大小: ${this.formatSize(beforeSize)}`);

    const platforms = this.getAvailablePlatforms();
    
    if (platforms.length === 0) {
      console.log('❌ 未找到任何构建平台');
      return;
    }

    let totalCleaned = 0;
    let totalKept = 0;

    for (const platform of platforms) {
      console.log(`\n📦 清理 ${platform} 平台...`);
      
      const platformDir = path.join(this.buildDir, platform);
      const platformSize = await this.getDirectorySize(platformDir);
      
      const { cleaned, kept } = await this.cleanPlatform(platform, platformDir);
      
      totalCleaned += cleaned;
      totalKept += kept;
      
      console.log(`  ✅ 清理完成: ${this.formatSize(cleaned)} 已删除, ${this.formatSize(kept)} 保留`);
    }

    // 获取清理后的目录大小
    const afterSize = await this.getDirectorySize(this.buildDir);
    const saved = beforeSize - afterSize;
    
    console.log(`\n📊 清理结果:`);
    console.log(`  🗑️  总删除: ${this.formatSize(totalCleaned)}`);
    console.log(`  💾 总保留: ${this.formatSize(totalKept)}`);
    console.log(`  💰 节省空间: ${this.formatSize(saved)}`);
    console.log(`  📁 最终大小: ${this.formatSize(afterSize)}`);
    
    console.log(`\n🎉 OpenCV 构建清理完成！`);
  }

  async cleanPlatform(platform, platformDir) {
    let cleaned = 0;
    let kept = 0;

    // 保留的文件和目录
    const keepPatterns = [
      'lib/',           // 库文件目录
      'include/',       // 头文件目录
      'bin/',           // Windows DLL 目录
      '*.dll',          // Windows DLL 文件
      '*.dylib',        // macOS 动态库
      '*.so*',          // Linux 共享库
      '*.a',            // 静态库
      '*.lib',          // Windows 导入库
      'CMakeCache.txt', // CMake 缓存
      'cmake_install.cmake', // CMake 安装脚本
      'OpenCVConfig*.cmake', // OpenCV 配置文件
      'opencv-config.cmake', // OpenCV 配置
    ];

    // 删除的目录和文件
    const deletePatterns = [
      'CMakeFiles/',    // CMake 构建文件
      'modules/',       // 模块构建目录
      '3rdparty/',      // 第三方库构建
      'apps/',          // 应用程序构建
      'samples/',       // 示例程序构建
      'test/',          // 测试构建
      '*.o',            // 目标文件
      '*.obj',          // Windows 目标文件
      '*.lo',           // 库目标文件
      '*.la',           // 库存档
      '*.tmp',          // 临时文件
      '*.log',          // 日志文件
      'Makefile',       // Makefile
      'cmake_install.cmake', // 安装脚本（如果不需要）
    ];

    // 递归清理目录
    const result = await this.cleanDirectory(platformDir, keepPatterns, deletePatterns);

    return { cleaned: result.cleaned, kept: result.kept };
  }

  async cleanDirectory(dir, keepPatterns, deletePatterns) {
    if (!fs.existsSync(dir)) return { cleaned: 0, kept: 0 };

    let cleaned = 0;
    let kept = 0;

    const items = fs.readdirSync(dir);
    
    for (const item of items) {
      const itemPath = path.join(dir, item);
      let stat;
      
      try {
        stat = fs.statSync(itemPath);
      } catch (error) {
        // 忽略无法访问的文件（如符号链接指向不存在的文件）
        continue;
      }
      
      if (stat.isDirectory()) {
        // 检查是否应该删除目录
        const shouldDelete = deletePatterns.some(pattern => 
          pattern.endsWith('/') && item.includes(pattern.slice(0, -1))
        );
        
        if (shouldDelete) {
          const size = await this.getDirectorySize(itemPath);
          fs.rmSync(itemPath, { recursive: true, force: true });
          cleaned += size;
          console.log(`    🗑️  删除目录: ${item} (${this.formatSize(size)})`);
        } else {
          // 递归处理子目录
          const subResult = await this.cleanDirectory(itemPath, keepPatterns, deletePatterns);
          cleaned += subResult.cleaned;
          kept += subResult.kept;
        }
      } else {
        // 检查是否应该删除文件
        const shouldDelete = deletePatterns.some(pattern => {
          if (pattern.includes('*')) {
            const regex = new RegExp(pattern.replace(/\*/g, '.*'));
            return regex.test(item);
          }
          return item === pattern;
        });
        
        const shouldKeep = keepPatterns.some(pattern => {
          if (pattern.includes('*')) {
            const regex = new RegExp(pattern.replace(/\*/g, '.*'));
            return regex.test(item);
          }
          return item === pattern || item.startsWith(pattern);
        });
        
        if (shouldDelete && !shouldKeep) {
          const size = stat.size;
          fs.unlinkSync(itemPath);
          cleaned += size;
          console.log(`    🗑️  删除文件: ${item} (${this.formatSize(size)})`);
        } else {
          kept += stat.size;
        }
      }
    }
    
    return { cleaned, kept };
  }

  getAvailablePlatforms() {
    if (!fs.existsSync(this.buildDir)) {
      return [];
    }

    return fs.readdirSync(this.buildDir)
      .filter(item => {
        const itemPath = path.join(this.buildDir, item);
        return fs.statSync(itemPath).isDirectory();
      });
  }

  async getDirectorySize(dir) {
    let size = 0;
    
    if (!fs.existsSync(dir)) return 0;
    
    const items = fs.readdirSync(dir);
    
    for (const item of items) {
      const itemPath = path.join(dir, item);
      try {
        const stat = fs.statSync(itemPath);
        
        if (stat.isDirectory()) {
          size += await this.getDirectorySize(itemPath);
        } else {
          size += stat.size;
        }
      } catch (error) {
        // 忽略无法访问的文件（如符号链接指向不存在的文件）
        continue;
      }
    }
    
    return size;
  }

  formatSize(bytes) {
    if (bytes === 0) return '0 B';
    
    const k = 1024;
    const sizes = ['B', 'KB', 'MB', 'GB'];
    const i = Math.floor(Math.log(bytes) / Math.log(k));
    
    return parseFloat((bytes / Math.pow(k, i)).toFixed(2)) + ' ' + sizes[i];
  }

  // 显示清理后的文件结构
  showCleanStructure() {
    console.log('\n📁 清理后的文件结构:');
    console.log('========================');
    
    const platforms = this.getAvailablePlatforms();
    
    for (const platform of platforms) {
      const platformDir = path.join(this.buildDir, platform);
      console.log(`\n${platform}/`);
      
      // 显示库文件
      const libPath = platform.startsWith('win32') 
        ? path.join(platformDir, 'bin')
        : path.join(platformDir, 'lib');
      
      if (fs.existsSync(libPath)) {
        const libFiles = fs.readdirSync(libPath)
          .filter(file => file.endsWith('.dll') || file.endsWith('.dylib') || file.endsWith('.so') || file.endsWith('.a'));
        
        libFiles.forEach(file => {
          const filePath = path.join(libPath, file);
          try {
            const stats = fs.statSync(filePath);
            const size = this.formatSize(stats.size);
            console.log(`  📄 ${file} (${size})`);
          } catch (error) {
            // 处理符号链接指向不存在文件的情况
            console.log(`  🔗 ${file} (符号链接)`);
          }
        });
      }
      
      // 显示头文件
      const includePath = path.join(platformDir, 'include');
      if (fs.existsSync(includePath)) {
        const headerCount = this.countFiles(includePath, ['.h', '.hpp']);
        console.log(`  📁 include/ (${headerCount} 个头文件)`);
      }
      
      // 显示配置文件
      const configFiles = fs.readdirSync(platformDir)
        .filter(file => file.endsWith('.cmake') || file.endsWith('.txt'));
      
      if (configFiles.length > 0) {
        console.log(`  📄 配置文件: ${configFiles.join(', ')}`);
      }
    }
  }

  countFiles(dir, extensions) {
    let count = 0;
    
    if (!fs.existsSync(dir)) return 0;
    
    const items = fs.readdirSync(dir);
    
    for (const item of items) {
      const itemPath = path.join(dir, item);
      const stat = fs.statSync(itemPath);
      
      if (stat.isDirectory()) {
        count += this.countFiles(itemPath, extensions);
      } else if (extensions.some(ext => item.endsWith(ext))) {
        count++;
      }
    }
    
    return count;
  }
}

// 主程序
if (require.main === module) {
  const cleaner = new OpenCVBuildCleaner();
  
  const args = process.argv.slice(2);
  
  if (args.includes('--structure')) {
    cleaner.showCleanStructure();
  } else {
    cleaner.clean().then(() => {
      if (args.includes('--show-structure')) {
        cleaner.showCleanStructure();
      }
    }).catch(error => {
      console.error('❌ 清理失败:', error.message);
      process.exit(1);
    });
  }
}

module.exports = OpenCVBuildCleaner;
