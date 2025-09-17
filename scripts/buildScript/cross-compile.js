const fs = require("fs");
const path = require("path");
const { execSync } = require("child_process");
const os = require("os");

class OpenCVCrossCompiler {
  constructor() {
    this.platform = os.platform();
    this.arch = os.arch();
    this.opencvSourceDir = path.join(__dirname, "../../deps/OpenCV-Source/opencv-4.12.0");
    this.buildDir = path.join(this.opencvSourceDir, "build");
    
    // 交叉编译目标平台配置
    this.targets = {
      'win32': {
        host: 'x86_64-w64-mingw32',
        toolchain: {
          CC: 'x86_64-w64-mingw32-gcc',
          CXX: 'x86_64-w64-mingw32-g++',
          AR: 'x86_64-w64-mingw32-ar',
          RANLIB: 'x86_64-w64-mingw32-ranlib',
          STRIP: 'x86_64-w64-mingw32-strip'
        },
        cmakeArgs: [
          '-DCMAKE_SYSTEM_NAME=Windows',
          '-DCMAKE_SYSTEM_PROCESSOR=x86_64',
          '-DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc',
          '-DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++',
          '-DCMAKE_RC_COMPILER=x86_64-w64-mingw32-windres',
          '-DCMAKE_FIND_ROOT_PATH=/opt/homebrew',
          '-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER',
          '-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY',
          '-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY'
        ]
      },
      'darwin': {
        'x64': {
          host: 'x86_64-apple-darwin',
          toolchain: {
            CC: 'clang',
            CXX: 'clang++',
            AR: 'ar',
            RANLIB: 'ranlib',
            STRIP: 'strip'
          },
          cmakeToolchain: null // 使用系统工具链
        },
        'arm64': {
          host: 'aarch64-apple-darwin',
          toolchain: {
            CC: 'clang',
            CXX: 'clang++',
            AR: 'ar',
            RANLIB: 'ranlib',
            STRIP: 'strip'
          },
          cmakeArgs: [
            '-DCMAKE_SYSTEM_NAME=Darwin',
            '-DCMAKE_SYSTEM_PROCESSOR=arm64',
            '-DCMAKE_C_COMPILER=clang',
            '-DCMAKE_CXX_COMPILER=clang++',
            '-DCMAKE_OSX_ARCHITECTURES=arm64',
            '-DCMAKE_OSX_DEPLOYMENT_TARGET=11.0'
          ]
        }
      },
      'linux': {
        'x64': {
          host: 'x86_64-linux-gnu',
          toolchain: {
            CC: 'x86_64-linux-musl-gcc',
            CXX: 'x86_64-linux-musl-g++',
            AR: 'x86_64-linux-musl-ar',
            RANLIB: 'x86_64-linux-musl-ranlib',
            STRIP: 'x86_64-linux-musl-strip'
          },
          cmakeArgs: [
            '-DCMAKE_SYSTEM_NAME=Linux',
            '-DCMAKE_SYSTEM_PROCESSOR=x86_64',
            '-DCMAKE_C_COMPILER=x86_64-linux-musl-gcc',
            '-DCMAKE_CXX_COMPILER=x86_64-linux-musl-g++',
            '-DCMAKE_C_FLAGS=-m64 -DSIZEOF_SIZE_T=8 -D_GNU_SOURCE=1 -D__GLIBC__=1 -D__MUSL__=1',
            '-DCMAKE_CXX_FLAGS=-m64 -DSIZEOF_SIZE_T=8 -D_GNU_SOURCE=1 -D__GLIBC__=1 -D__MUSL__=1',
            '-DCMAKE_INCLUDE_PATH=/Users/fuguoqiang/Documents/workspace/infra/opencvspeed/deps/OpenCV-Source/opencv-4.12.0/build/linux-x64',
            '-DCMAKE_FIND_ROOT_PATH=/opt/homebrew/x86_64-linux-musl',
            '-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER',
            '-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY',
            '-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY',
            '-DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY',
            '-DWITH_TIFF=OFF',
            '-DBUILD_TIFF=OFF',
            '-DOPENCV_DISABLE_TIFF=ON',
            '-DCMAKE_CXX_STANDARD=11'
          ]
        },
        'arm64': {
          host: 'aarch64-linux-gnu',
          toolchain: {
            CC: 'aarch64-linux-musl-gcc',
            CXX: 'aarch64-linux-musl-g++',
            AR: 'aarch64-linux-musl-ar',
            RANLIB: 'aarch64-linux-musl-ranlib',
            STRIP: 'aarch64-linux-musl-strip'
          },
          cmakeArgs: [
            '-DCMAKE_SYSTEM_NAME=Linux',
            '-DCMAKE_SYSTEM_PROCESSOR=aarch64',
            '-DCMAKE_C_COMPILER=aarch64-linux-musl-gcc',
            '-DCMAKE_CXX_COMPILER=aarch64-linux-musl-g++',
            '-DCMAKE_C_FLAGS=-march=armv8-a -DSIZEOF_SIZE_T=8 -D_GNU_SOURCE=1 -D__GLIBC__=1 -D__MUSL__=1',
            '-DCMAKE_CXX_FLAGS=-march=armv8-a -DSIZEOF_SIZE_T=8 -D_GNU_SOURCE=1 -D__GLIBC__=1 -D__MUSL__=1',
            '-DCMAKE_FIND_ROOT_PATH=/opt/homebrew/aarch64-linux-musl',
            '-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER',
            '-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY',
            '-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY',
            '-DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY',
            '-DWITH_TIFF=OFF',
            '-DBUILD_TIFF=OFF',
            '-DOPENCV_DISABLE_TIFF=ON',
            '-DCMAKE_CXX_STANDARD=11'
          ]
        }
      }
    };
  }

  log(message) {
    console.log(`[OpenCV 交叉编译器] ${message}`);
  }

  // 检查工具链是否可用
  checkToolchain(toolchain) {
    this.log("检查交叉编译工具链...");
    
    for (const [key, value] of Object.entries(toolchain)) {
      try {
        // 对于 ar, ranlib, strip 等工具，使用 which 检查
        if (['ar', 'ranlib', 'strip'].includes(value)) {
          execSync(`which ${value}`, { stdio: 'pipe' });
        } else {
          // 对于交叉编译工具链，先尝试 --version，如果失败则尝试 -v
          try {
            execSync(`${value} --version`, { stdio: 'pipe' });
          } catch (versionError) {
            try {
              execSync(`${value} -v`, { stdio: 'pipe' });
            } catch (vError) {
              // 如果都失败，尝试 which 检查
              execSync(`which ${value}`, { stdio: 'pipe' });
            }
          }
        }
        this.log(`✅ ${key}: ${value}`);
      } catch (error) {
        this.log(`❌ ${key}: ${value} - 未找到`);
        this.log(`   请安装相应的交叉编译工具链:`);
        if (value.includes('x86_64-linux-musl')) {
          this.log(`   brew install filosottile/musl-cross/musl-cross`);
        } else if (value.includes('aarch64-linux-musl')) {
          this.log(`   brew install filosottile/musl-cross/musl-cross`);
        }
        return false;
      }
    }
    return true;
  }

  // 设置交叉编译环境
  setCrossCompileEnv(toolchain) {
    this.log("设置交叉编译环境...");
    
    for (const [key, value] of Object.entries(toolchain)) {
      process.env[key] = value;
      this.log(`  ${key}=${value}`);
    }
  }

  getCMakeConfig(targetPlatform = null) {
    const baseConfig = {
      // ==================== 核心模块 ====================
      'BUILD_opencv_core': 'ON',           // 核心模块：基础数据结构、数学运算、内存管理
      'BUILD_opencv_imgproc': 'ON',        // 图像处理：滤波、几何变换、形态学操作、颜色空间转换
      'BUILD_opencv_imgcodecs': 'ON',      // 图像编解码：读取/保存各种图像格式（JPEG、PNG、TIFF等）
      
      // ==================== 计算机视觉模块 ====================
      'BUILD_opencv_objdetect': 'ON',      // 目标检测：人脸检测、物体检测、级联分类器
      'BUILD_opencv_features2d': 'ON',     // 特征检测：角点检测、特征匹配、描述符
      'BUILD_opencv_flann': 'ON',          // 快速最近邻搜索：用于特征匹配和聚类
      'BUILD_opencv_photo': 'ON',          // 计算摄影：去噪、HDR、无缝克隆、色调映射
      'BUILD_opencv_calib3d': 'ON',        // 相机标定：立体视觉、相机标定、3D重建
      
      // ==================== 高级模块 ====================
      'BUILD_opencv_gapi': 'ON',           // 图API：高性能图像处理管道，支持异构计算
      'WITH_ADE': 'ON',                    // ADE库：GAPI的依赖，用于图执行引擎
      
      // ==================== 禁用的模块 ====================
      'BUILD_opencv_dnn': 'OFF',           // 深度学习：神经网络推理（需要大量依赖）
      'BUILD_opencv_ml': 'OFF',            // 机器学习：传统ML算法（SVM、KNN等）
      'BUILD_opencv_video': 'OFF',         // 视频分析：光流、背景减除、跟踪
      'BUILD_opencv_videoio': 'ON',        // 视频I/O：读取/写入视频文件（启用以支持GAPI）
      'BUILD_opencv_stitching': 'OFF',     // 图像拼接：全景图拼接
      'BUILD_opencv_highgui': 'OFF',       // 高级GUI：窗口显示、鼠标交互（服务器环境不需要）
      'BUILD_opencv_ts': 'ON',             // 测试模块：单元测试
      'BUILD_opencv_world': 'ON',          // 世界模块：将所有模块合并为单个库（增加大小）
      
      // ==================== 语言绑定 ====================
      'BUILD_opencv_java': 'OFF',          // Java绑定
      'BUILD_opencv_js': 'OFF',            // JavaScript绑定
      'BUILD_opencv_python': 'OFF',        // Python绑定
      'BUILD_opencv_objc': 'OFF',          // Objective-C绑定
      
      // ==================== 构建配置 ====================
      'BUILD_opencv_apps': 'OFF',          // 示例应用程序
      'BUILD_TESTS': 'OFF',                // 测试程序
      'BUILD_PERF_TESTS': 'OFF',           // 性能测试
      'BUILD_EXAMPLES': 'OFF',             // 示例代码
      'CMAKE_BUILD_TYPE': 'Release',       // 构建类型：Release优化版本
      'BUILD_SHARED_LIBS': 'ON',           // 构建共享库（.dll/.so/.dylib）
      'CMAKE_POSITION_INDEPENDENT_CODE': 'ON', // 位置无关代码（PIC）
      
          // ==================== 平台特定编译器选项 ====================
          // Linux 平台使用 GCC 9.2.0，使用最基本的兼容选项
          'CMAKE_C_FLAGS_LINUX': '-O3 -Wall -Wreturn-type -Waddress -Wsequence-point -Wformat -Wformat-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wuninitialized -Wno-comment -Wno-strict-overflow',
          'CMAKE_CXX_FLAGS_LINUX': '-O3 -Wall -Wreturn-type -Wnon-virtual-dtor -Waddress -Wsequence-point -Wformat -Wformat-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wuninitialized -Wno-delete-non-virtual-dtor -Wno-comment -Wno-strict-overflow -Wno-deprecated -Wno-missing-declarations -Wno-shadow -Wno-unused-parameter -Wno-unused-local-typedefs -Wno-sign-compare -Wno-sign-promo -Wno-undef -Wno-ignored-qualifiers -Wno-extra -Wno-unused-function -Wno-unused-const-variable -Wno-invalid-offsetof -Wno-suggest-override -Wno-implicit-fallthrough -Wno-array-bounds -Wno-stringop-overflow',
      
      // 禁用有问题的编译器检查
      'OPENCV_DISABLE_COMPILER_WARNINGS': 'ON',
      'OPENCV_DISABLE_COMPILER_WARNINGS_ABSOLUTE_PATHS': 'ON',
      
      // ==================== 第三方库配置 ====================
      // 视频处理库
      'WITH_FFMPEG': 'OFF',                // FFmpeg：视频编解码（增加依赖）
      'WITH_GSTREAMER': 'OFF',             // GStreamer：多媒体框架
      'WITH_1394': 'OFF',                  // IEEE 1394：火线接口
      'WITH_V4L': 'OFF',                   // Video4Linux：Linux视频接口
      
      // GUI框架
      'WITH_GTK': 'OFF',                   // GTK：Linux GUI框架
      'WITH_QT': 'OFF',                    // Qt：跨平台GUI框架
      
      // 图像格式支持
      'WITH_WEBP': 'ON',                   // WebP：Google的现代图像格式
      'WITH_OPENEXR': 'OFF',               // OpenEXR：HDR图像格式（电影工业）
      'WITH_JPEG': 'ON',                   // JPEG：标准JPEG格式支持
      'WITH_PNG': 'ON',                    // PNG：无损压缩图像格式
      'WITH_TIFF': 'ON',                   // TIFF：标签图像文件格式
      'WITH_OPENJPEG': 'ON',               // OpenJPEG：JPEG-2000编解码（现代实现）
      'WITH_JASPER': 'OFF',                // JasPer：JPEG-2000编解码（旧实现，已被OpenJPEG替代）
      
      // 其他依赖
      'WITH_FREETYPE': 'OFF',              // FreeType：字体渲染
      'WITH_PLAIDML': 'OFF',               // PlaidML：机器学习加速
      'WITH_OAK': 'OFF',                   // OAK：OpenCV AI Kit
      'OPENCV_GAPI_WITH_OPENVINO': 'OFF'   // OpenVINO：Intel推理引擎
    };

    // 为 Linux 平台添加特定的编译器选项
    if (targetPlatform && targetPlatform.startsWith('linux')) {
      baseConfig['CMAKE_C_FLAGS'] = baseConfig['CMAKE_C_FLAGS_LINUX'];
      baseConfig['CMAKE_CXX_FLAGS'] = baseConfig['CMAKE_CXX_FLAGS_LINUX'];
      // 删除临时的 Linux 特定选项
      delete baseConfig['CMAKE_C_FLAGS_LINUX'];
      delete baseConfig['CMAKE_CXX_FLAGS_LINUX'];
    }

    return baseConfig;
  }

  // 交叉编译 OpenCV
  async crossCompile(targetPlatform, targetArch = null) {
    this.log(`为 ${targetPlatform}${targetArch ? ` (${targetArch})` : ''} 进行交叉编译...`);
    
    // 获取目标配置
    let target;
    if (targetArch && this.targets[targetPlatform] && this.targets[targetPlatform][targetArch]) {
      target = this.targets[targetPlatform][targetArch];
    } else if (this.targets[targetPlatform] && this.targets[targetPlatform].host) {
      target = this.targets[targetPlatform];
    } else {
      throw new Error(`不支持的目标: ${targetPlatform}${targetArch ? ` (${targetArch})` : ''}`);
    }

    // 检查工具链
    if (!this.checkToolchain(target.toolchain)) {
      throw new Error(`${targetPlatform} 的交叉编译工具链不可用`);
    }

    // 设置环境
    this.setCrossCompileEnv(target.toolchain);

    // 统一使用 build 目录
    const platformBuildDir = path.join(this.buildDir, `${targetPlatform}${targetArch ? `-${targetArch}` : ''}`);
    
    // 清理之前的构建
    if (fs.existsSync(platformBuildDir)) {
      execSync(`rm -rf ${platformBuildDir}`, { stdio: 'inherit' });
    }

    // 创建构建目录
    fs.mkdirSync(platformBuildDir, { recursive: true });

    // 构建 CMake 参数
    const cmakeArgs = [
      `-DCMAKE_INSTALL_PREFIX=${platformBuildDir}`,
      `-DCMAKE_BUILD_TYPE=Release`
    ];

    // 添加工具链文件
    if (target.cmakeToolchain) {
      const toolchainPath = path.join(this.opencvSourceDir, target.cmakeToolchain);
      cmakeArgs.push(`-DCMAKE_TOOLCHAIN_FILE=${toolchainPath}`);
    }

    // 添加额外的 CMake 参数
    if (target.cmakeArgs) {
      cmakeArgs.push(...target.cmakeArgs);
    }

    // 添加所有配置选项
    const cmakeConfig = this.getCMakeConfig(targetPlatform);
    for (const [key, value] of Object.entries(cmakeConfig)) {
      cmakeArgs.push(`-D${key}=${value}`);
    }

    // 添加源目录
    cmakeArgs.push(this.opencvSourceDir);

    // 配置构建
    this.log("配置 OpenCV...");
    this.log(`CMake 参数: ${cmakeArgs.join(' ')}`);
    
    execSync(`cmake ${cmakeArgs.join(' ')}`, {
      cwd: platformBuildDir,
      stdio: 'inherit'
    });

    // 编译
    this.log("编译 OpenCV...");
    execSync(`make -j${os.cpus().length}`, {
      cwd: platformBuildDir,
      stdio: 'inherit'
    });

    // 安装
    this.log("安装 OpenCV...");
    execSync('make install', {
      cwd: platformBuildDir,
      stdio: 'inherit'
    });

    this.log(`✅ ${targetPlatform}${targetArch ? ` (${targetArch})` : ''} 交叉编译完成`);
    this.log(`构建输出: ${platformBuildDir}`);
  }

  // 列出支持的目标平台
  listTargets() {
    this.log("支持的交叉编译目标:");
    
    for (const [platform, config] of Object.entries(this.targets)) {
      if (config.host) {
        this.log(`  ${platform}: ${config.host}`);
      } else {
        for (const [arch, archConfig] of Object.entries(config)) {
          this.log(`  ${platform} (${arch}): ${archConfig.host}`);
        }
      }
    }
  }
}

// 如果直接运行此脚本
if (require.main === module) {
  const compiler = new OpenCVCrossCompiler();
  
  const args = process.argv.slice(2);
  
  if (args.length === 0 || args[0] === '--help') {
    console.log("用法: node cross-compile.js <目标平台> [目标架构]");
    console.log("示例:");
    console.log("  node cross-compile.js win32");
    console.log("  node cross-compile.js darwin arm64");
    console.log("  node cross-compile.js linux x64");
    console.log("");
    compiler.listTargets();
  } else {
    const targetPlatform = args[0];
    const targetArch = args[1] || null;
    
    compiler.crossCompile(targetPlatform, targetArch).catch(error => {
      console.error("交叉编译失败:", error.message);
      process.exit(1);
    });
  }
}

module.exports = OpenCVCrossCompiler;
