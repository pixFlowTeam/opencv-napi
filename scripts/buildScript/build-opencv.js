const fs = require("fs");
const path = require("path");
const { execSync } = require("child_process");
const os = require("os");

class OpenCVBuilder {
  constructor() {
    this.platform = os.platform();
    this.arch = os.arch();
    this.opencvSourceDir = path.join(__dirname, "../deps/OpenCV-Source/opencv-4.12.0");
    this.buildDir = path.join(this.opencvSourceDir, "build");
  }

  getPlatformName() {
    if (this.platform === 'win32') {
      return 'win32';
    } else if (this.platform === 'darwin') {
      return this.arch === 'arm64' ? 'darwin-arm64' : 'darwin-x64';
    } else if (this.platform === 'linux') {
      return this.arch === 'arm64' ? 'linux-arm64' : 'linux-x64';
    }
    return 'unknown';
  }

  log(message) {
    console.log(`[OpenCV 构建器] ${message}`);
  }

  async ensureDirectories() {
    const platformBuildDir = path.join(this.buildDir, this.getPlatformName());
    if (!fs.existsSync(platformBuildDir)) {
      fs.mkdirSync(platformBuildDir, { recursive: true });
      this.log(`已创建目录: ${platformBuildDir}`);
    }
  }

  getCMakeConfig() {
    return {
      // 核心模块
      'BUILD_opencv_core': 'ON',
      'BUILD_opencv_imgproc': 'ON',
      'BUILD_opencv_imgcodecs': 'ON',
      
      // 特定功能模块
      'BUILD_opencv_objdetect': 'ON',
      'BUILD_opencv_features2d': 'ON',
      'BUILD_opencv_flann': 'ON',
      'BUILD_opencv_photo': 'ON',
      
      // GAPI 模块配置
      'BUILD_opencv_gapi': 'ON',
      'WITH_ADE': 'ON',
      'WITH_FREETYPE': 'OFF',
      'WITH_PLAIDML': 'OFF',
      'WITH_OAK': 'OFF',
      'OPENCV_GAPI_WITH_OPENVINO': 'OFF',
      
      // 禁用的模块
      'BUILD_opencv_dnn': 'OFF',
      'BUILD_opencv_ml': 'OFF',
      'BUILD_opencv_video': 'OFF',
      'BUILD_opencv_videoio': 'ON',        // 视频I/O：读取/写入视频文件
      'BUILD_opencv_calib3d': 'ON',        // 相机标定：立体视觉、相机标定、3D重建
      'BUILD_opencv_stitching': 'OFF',     // 图像拼接：全景图拼接
      'BUILD_opencv_highgui': 'OFF',       // 高级GUI：窗口显示、鼠标交互
      'BUILD_opencv_ts': 'ON',             // 测试模块：单元测试
      'BUILD_opencv_world': 'ON',          // 世界模块：将所有模块合并为单个库
      'BUILD_opencv_java': 'OFF',
      'BUILD_opencv_js': 'OFF',
      'BUILD_opencv_python': 'OFF',
      'BUILD_opencv_objc': 'OFF',
      
      // 禁用 Python 绑定以避免依赖问题
      'BUILD_opencv_python2': 'OFF',
      'BUILD_opencv_python3': 'OFF',
      
      // 其他优化配置
      'BUILD_opencv_apps': 'OFF',
      'BUILD_TESTS': 'OFF',
      'BUILD_PERF_TESTS': 'OFF',
      'BUILD_EXAMPLES': 'OFF',
      'CMAKE_BUILD_TYPE': 'Release',
      'BUILD_SHARED_LIBS': 'ON',
      'CMAKE_POSITION_INDEPENDENT_CODE': 'ON',
      
      // 第三方库配置
      'WITH_FFMPEG': 'OFF',
      'WITH_GSTREAMER': 'OFF',
      'WITH_1394': 'OFF',
      'WITH_V4L': 'OFF',
      'WITH_GTK': 'OFF',
      'WITH_QT': 'OFF',
      'WITH_WEBP': 'OFF',
      'WITH_OPENEXR': 'OFF',
      'WITH_JPEG': 'ON',
      'WITH_PNG': 'ON',
      'WITH_TIFF': 'ON',
      'WITH_OPENJPEG': 'ON',
      'WITH_JASPER': 'OFF'
    };
  }

  async build() {
    this.log("开始 OpenCV 构建...");
    
    try {
      // 确保目录存在
      await this.ensureDirectories();
      
      // 检查构建工具
      this.checkBuildTools();
      
      // 配置构建
      const platformBuildDir = path.join(this.buildDir, this.getPlatformName());
      const cmakeConfig = this.getCMakeConfig();
      
      // 构建 CMake 参数
      const cmakeArgs = [
        `-DCMAKE_INSTALL_PREFIX=${platformBuildDir}`,
        `-DCMAKE_BUILD_TYPE=Release`
      ];
      
      // 添加所有配置选项
      for (const [key, value] of Object.entries(cmakeConfig)) {
        cmakeArgs.push(`-D${key}=${value}`);
      }
      
      // 添加源目录
      cmakeArgs.push(this.opencvSourceDir);
      
      this.log("配置 OpenCV...");
      this.log(`CMake 参数: ${cmakeArgs.join(' ')}`);
      
      execSync(`cmake ${cmakeArgs.join(' ')}`, {
        cwd: platformBuildDir,
        stdio: 'inherit'
      });

      this.log("构建 OpenCV...");
      execSync(`make -j${os.cpus().length}`, {
        cwd: platformBuildDir,
        stdio: 'inherit'
      });

      this.log("安装 OpenCV...");
      execSync('make install', {
        cwd: platformBuildDir,
        stdio: 'inherit'
      });

      this.log("OpenCV 构建成功完成!");
      this.log(`构建输出: ${platformBuildDir}`);
      
    } catch (error) {
      this.log(`构建失败: ${error.message}`);
      throw error;
    }
  }

  checkBuildTools() {
    try {
      // 检查基本构建工具
      execSync('which cmake', { stdio: 'ignore' });
      execSync('which make', { stdio: 'ignore' });
      execSync('which gcc', { stdio: 'ignore' });
      execSync('which g++', { stdio: 'ignore' });
      this.log("找到构建工具");
    } catch (error) {
      throw new Error(`未找到 ${this.platform} 平台所需的构建工具`);
    }
  }
}

// 主执行逻辑
async function main() {
  const builder = new OpenCVBuilder();
  try {
    await builder.build();
  } catch (error) {
    console.error(`OpenCV 构建失败: ${error.message}`);
    process.exit(1);
  }
}

// 如果直接运行此脚本
if (require.main === module) {
  main();
}

module.exports = OpenCVBuilder;
