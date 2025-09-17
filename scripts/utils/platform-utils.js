const os = require('os');
const path = require('path');

/**
 * 获取当前平台和架构
 */
function getCurrentPlatform() {
  const platform = os.platform();
  const arch = os.arch();
  
  if (platform === 'darwin') {
    return arch === 'arm64' ? 'darwin-arm64' : 'darwin-x64';
  } else if (platform === 'linux') {
    return arch === 'arm64' ? 'linux-arm64' : 'linux-x64';
  } else if (platform === 'win32') {
    return arch === 'x64' ? 'win32-x64' : 'win32-x86';
  }
  
  throw new Error(`Unsupported platform: ${platform}-${arch}`);
}

/**
 * 获取 OpenCV 包含路径
 */
function getOpenCVIncludePath() {
  const platform = getCurrentPlatform();
  return `deps/OpenCV-Source/opencv-4.12.0/build/${platform}/include/opencv4`;
}

/**
 * 获取 OpenCV 库目录
 */
function getOpenCVLibDir() {
  const platform = getCurrentPlatform();
  const path = require('path');
  return path.resolve(process.cwd(), `deps/OpenCV-Source/opencv-4.12.0/build/${platform}/lib`);
}

/**
 * 获取 OpenCV 库路径
 */
function getOpenCVLibPath() {
  const platform = getCurrentPlatform();
  return `-Ldeps/OpenCV-Source/opencv-4.12.0/build/${platform}/lib`;
}

/**
 * 获取 OpenCV 3rdparty 库路径
 */
function getOpenCV3rdPartyLibPath() {
  const platform = getCurrentPlatform();
  return `-Ldeps/OpenCV-Source/opencv-4.12.0/build/${platform}/lib/opencv4/3rdparty`;
}

/**
 * 获取 OpenCV 3rdparty 库目录
 */
function getOpenCV3rdPartyLibDir() {
  const platform = getCurrentPlatform();
  const path = require('path');
  return path.resolve(process.cwd(), `deps/OpenCV-Source/opencv-4.12.0/build/${platform}/lib/opencv4/3rdparty`);
}

/**
 * 获取 OpenCV rpath 标志
 */
function getOpenCVRpathFlags() {
  const platform = getCurrentPlatform();
  const libDir = `deps/OpenCV-Source/opencv-4.12.0/build/${platform}/lib`;
  
  if (os.platform() === 'darwin') {
    return `-Wl,-rpath,${libDir} -Wl,-install_name,@rpath/libopencv_world.4.12.0.dylib`;
  } else {
    return `-Wl,-rpath,${libDir}`;
  }
}

module.exports = {
  getCurrentPlatform,
  getOpenCVIncludePath,
  getOpenCVLibDir,
  getOpenCVLibPath,
  getOpenCV3rdPartyLibPath,
  getOpenCV3rdPartyLibDir,
  getOpenCVRpathFlags
};
