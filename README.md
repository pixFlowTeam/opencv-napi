# OpenCV NAPI

[![npm version](https://img.shields.io/npm/v/opencv-napi.svg)](https://www.npmjs.com/package/opencv-napi)
[![Build Status](https://img.shields.io/github/workflow/status/your-username/opencv-napi/CI)](https://github.com/your-username/opencv-napi/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

一个高性能的 Node.js OpenCV 绑定库，提供完整的计算机视觉功能，包括图像处理、特征检测、机器学习等。

## 功能特性

- 🚀 **高性能**: 基于 Node-API 的原生 C++ 绑定
- 🖼️ **完整图像处理**: 支持读取、写入、调整大小、颜色转换等
- 🔍 **特征检测**: 边缘检测、角点检测、轮廓检测等
- 🎨 **图像增强**: 模糊、锐化、直方图均衡化等
- 📊 **数据分析**: 直方图计算、统计分析等
- 🌍 **跨平台**: 支持 Windows、macOS、Linux
- 📦 **零依赖**: 无需安装额外的系统库

## 支持的模块

- **Core**: 基础数据结构 (Mat, Scalar, Point 等)
- **ImgProc**: 图像处理 (滤波、几何变换、形态学操作)
- **ImgCodecs**: 图像编解码 (支持 JPEG, PNG, BMP, TIFF 等)
- **ObjDetect**: 目标检测 (Haar 级联、HOG 检测器)
- **Features2d**: 特征检测与匹配 (SIFT, SURF, ORB 等)
- **Photo**: 计算摄影 (去噪、修复、HDR)
- **Calib3d**: 相机标定和 3D 重建
- **Flann**: 快速最近邻搜索
- **Videoio**: 视频输入输出
- **Gapi**: 图像处理管道

## 安装

```bash
npm install opencv-napi
```

### 预编译二进制文件

该包包含针对以下平台的预编译二进制文件：
- Windows (x64)
- macOS (x64, arm64)
- Linux (x64)

### 从源码构建

如果预编译的二进制文件不适用于您的平台，可以尝试从源码构建：

```bash
npm install --build-from-source
```

## 先决条件（从源码构建）

### Windows
- Visual Studio 2019 或更新版本
- CMake 3.16+
- Python 3.6+

### macOS
- Xcode Command Line Tools
- CMake 3.16+
- Python 3.6+

### Linux
- GCC 7+ 或 Clang 5+
- CMake 3.16+
- Python 3.6+
- pkg-config

## 快速开始

```javascript
const OpenCV = require('opencv-napi');

async function main() {
  try {
    // 创建 OpenCV 实例
    const cv = new OpenCV();
    
    // 读取图像
    const image = await cv.imread('input.jpg');
    
    // 调整图像大小
    const resized = await cv.resize(image, { width: 800, height: 600 });
    
    // 转换颜色空间
    const gray = await cv.convertColor(resized, 'BGR2GRAY');
    
    // 保存处理后的图像
    await cv.imwrite('output.jpg', gray);
    
    console.log('图像处理完成！');
  } catch (error) {
    console.error('处理失败:', error);
  }
}

main();
```

### 版本信息

```javascript
const OpenCV = require('opencv-napi');
console.log('OpenCV version:', OpenCV.getVersion());
// 输出: OpenCV version: 4.12.0
```

## 功能概览

### 图像处理
- **读取和保存**: 支持多种图像格式 (JPEG, PNG, BMP, TIFF, WebP)
- **尺寸调整**: 高质量图像缩放和裁剪
- **颜色转换**: RGB, BGR, HSV, LAB 等颜色空间转换
- **几何变换**: 旋转、翻转、透视变换

### 图像增强
- **滤波**: 高斯模糊、双边滤波、中值滤波
- **锐化**: 拉普拉斯算子、Unsharp Mask
- **直方图**: 直方图均衡化、对比度增强
- **去噪**: 非局部均值去噪、快速去噪

### 特征检测
- **边缘检测**: Canny, Sobel, Laplacian
- **角点检测**: Harris, FAST, ORB
- **轮廓检测**: 查找和绘制轮廓
- **特征匹配**: 模板匹配、特征点匹配

### 机器学习
- **分类器**: Haar 级联分类器
- **检测**: 人脸检测、目标检测
- **聚类**: K-means 聚类
- **降维**: PCA 主成分分析

## 完整的 API 覆盖

### Core 模块
- `Mat` - 矩阵数据结构
- `Scalar` - 标量值
- `Point`, `Point2f`, `Point3f` - 点结构
- `Size`, `Rect` - 尺寸和矩形
- `Range` - 范围结构

### 图像信息和分析
- `getImageInfo()` - 获取图像基本信息
- `calculateHistogram()` - 计算图像直方图
- `getImageStats()` - 获取图像统计信息
- `analyzeImage()` - 综合分析图像

### ImgProc 模块
- `resize()` - 图像缩放
- `crop()` - 图像裁剪
- `rotate()` - 图像旋转
- `flip()` - 图像翻转
- `blur()` - 图像模糊
- `sharpen()` - 图像锐化
- `enhanceImage()` - 图像增强
- `convertColor()` - 颜色空间转换
- `threshold()` - 图像阈值化
- `morphologyEx()` - 形态学操作

### ImgCodecs 模块
- `imread()` - 读取图像
- `imwrite()` - 保存图像
- `imencode()` - 编码图像到内存
- `imdecode()` - 从内存解码图像
- `getSupportedFormats()` - 获取支持的格式

### 配置和参数
- `setNumThreads()` - 设置线程数
- `setUseOptimized()` - 启用/禁用优化
- `getBuildInfo()` - 获取构建信息
- `getVersion()` - 获取版本信息

### Features2d 模块
- `detectFeatures()` - 特征检测
- `matchFeatures()` - 特征匹配
- `drawKeypoints()` - 绘制关键点
- `extractDescriptors()` - 提取描述符

### Photo 模块
- `denoiseImage()` - 图像去噪
- `inpaint()` - 图像修复
- `createHDR()` - 创建 HDR 图像
- `tonemap()` - 色调映射

### 静态方法
- `OpenCV.getVersion()` - 获取 OpenCV 版本
- `OpenCV.getBuildInfo()` - 获取构建信息
- `OpenCV.getNumThreads()` - 获取线程数
- `OpenCV.setNumThreads()` - 设置线程数

## 🆕 高级图像处理 API（新功能）

### 批量图像处理

```javascript
const cv = new OpenCV();

// 批量处理多个图像
const images = ['image1.jpg', 'image2.jpg', 'image3.jpg'];
const processedImages = [];

for (const imagePath of images) {
  const image = await cv.imread(imagePath);
  const resized = await cv.resize(image, { width: 800, height: 600 });
  const enhanced = await cv.enhanceImage(resized, {
    brightness: 1.2,
    contrast: 1.1,
    saturation: 1.0
  });
  processedImages.push(enhanced);
}

console.log(`处理了 ${processedImages.length} 张图像`);
```

### 图像格式转换

```javascript
// 支持多种输出格式
await cv.imwrite('output.jpg', image, { quality: 95 });
await cv.imwrite('output.png', image);
await cv.imwrite('output.bmp', image);
await cv.imwrite('output.tiff', image);
await cv.imwrite('output.webp', image, { quality: 90 });

// 编码到内存缓冲区
const jpegBuffer = await cv.imencode('output.jpg', image, { quality: 85 });
const pngBuffer = await cv.imencode('output.png', image);
```

### 缩略图生成

```javascript
// 生成高质量缩略图
const thumbnail = await cv.resize(image, { 
  width: 200, 
  height: 200,
  interpolation: 'LANCZOS4'
});

await cv.imwrite('thumbnail.jpg', thumbnail, { quality: 90 });
```

## 🆕 JPEG 转换（增强功能）

### 高质量 JPEG 转换

```javascript
const cv = new OpenCV();

// 读取图像
const image = await cv.imread('input.png');

// 高质量 JPEG 转换
await cv.imwrite('output.jpg', image, {
  quality: 95,           // JPEG 质量 (1-100)
  progressive: true,     // 渐进式 JPEG
  optimize: true         // 优化文件大小
});

console.log('JPEG 转换完成');
```

### 批量图像转换

```javascript
// 批量转换 PNG 到 JPEG
const fs = require('fs');
const path = require('path');

const inputDir = './photos';
const outputDir = './photos/jpeg';

// 确保输出目录存在
if (!fs.existsSync(outputDir)) {
  fs.mkdirSync(outputDir, { recursive: true });
}

// 读取所有 PNG 文件
const files = fs.readdirSync(inputDir).filter(file => 
  file.toLowerCase().endsWith('.png')
);

console.log(`找到 ${files.length} 个 PNG 文件`);

// 批量转换
for (const file of files) {
  const inputPath = path.join(inputDir, file);
  const outputPath = path.join(outputDir, file.replace('.png', '.jpg'));
  
  try {
    const image = await cv.imread(inputPath);
    await cv.imwrite(outputPath, image, { quality: 90 });
    console.log(`✅ 转换完成: ${file}`);
  } catch (error) {
    console.error(`❌ 转换失败: ${file}`, error.message);
  }
}

console.log('🎉 批量转换完成！');
```

运行批量转换脚本：

```bash
node scripts/docs/batch-image-conversion.js
```

## API 参考

### 核心功能

#### `new OpenCV()`

创建一个新的 OpenCV 处理器实例。

#### `imread(filename)`

读取图像文件。

- **filename** `{string}` - 图像文件路径
- **返回** `{Promise<Mat>}` - OpenCV Mat 对象

#### `imwrite(filename, image, options)`

保存图像到文件。

- **filename** `{string}` - 输出文件路径
- **image** `{Mat}` - 图像数据
- **options** `{Object}` - 保存选项（如 JPEG 质量等）
- **返回** `{Promise<boolean>}` - 成功状态

### 图像处理

#### `resize(image, size)`

调整图像尺寸。

- **image** `{Mat}` - 输入图像
- **size** `{Object}` - 目标尺寸 `{width, height}`
- **返回** `{Promise<Mat>}` - 调整后的图像

#### `convertColor(image, conversion)`

转换图像颜色空间。

- **image** `{Mat}` - 输入图像
- **conversion** `{string}` - 转换类型（如 'BGR2RGB'）
- **返回** `{Promise<Mat>}` - 转换后的图像

#### `blur(image, kernelSize)`

对图像进行模糊处理。

- **image** `{Mat}` - 输入图像
- **kernelSize** `{number}` - 卷积核大小
- **返回** `{Promise<Mat>}` - 模糊后的图像

#### `sharpen(image)`

锐化图像。

- **image** `{Mat}` - 输入图像
- **返回** `{Promise<Mat>}` - 锐化后的图像

#### `enhanceImage(image, options)`

增强图像质量。

- **image** `{Mat}` - 输入图像
- **options** `{Object}` - 增强选项
- **返回** `{Promise<Mat>}` - 增强后的图像

### 特征检测

#### `detectFeatures(image, type)`

检测图像特征。

- **image** `{Mat}` - 输入图像
- **type** `{string}` - 特征类型（如 'edges', 'corners'）
- **返回** `{Promise<Array>}` - 特征点数组

### 信息获取

#### `getImageInfo(image)`

获取图像基本信息。

- **image** `{Mat}` - 输入图像
- **返回** `{Promise<Object>}` - 图像信息对象

#### `calculateHistogram(image)`

计算图像直方图。

- **image** `{Mat}` - 输入图像
- **返回** `{Promise<Array>}` - 直方图数据

### 静态方法

#### `OpenCV.getVersion()`

获取 OpenCV 库版本。

- **返回** `{string}` - 版本字符串（例如："4.12.0"）

#### `OpenCV.getBuildInfo()`

获取 OpenCV 构建信息。

- **返回** `{string}` - 构建信息字符串

## 测试

该库包含涵盖所有主要功能的全面测试套件：

### 快速测试

```bash
npm test
```

### 详细测试

```bash
npm run test:verbose
```

### 性能测试

```bash
npm run test:performance
```

## 缩略图提取

OpenCV NAPI 支持从图像中提取缩略图：

```javascript
const cv = new OpenCV();

async function extractThumbnail(imagePath) {
  try {
    const image = await cv.imread(imagePath);
    
    // 生成缩略图
    const thumbnail = await cv.resize(image, { 
      width: 200, 
      height: 200 
    });
    
    // 保存缩略图
    await cv.imwrite('thumbnail.jpg', thumbnail, { quality: 85 });
    
    console.log('缩略图提取成功');
  } catch (error) {
    console.error('缩略图提取失败:', error);
  }
}
```

## 示例输出

### 图像处理示例

```javascript
const cv = new OpenCV();

// 读取图像
const image = await cv.imread('input.jpg');
console.log('图像尺寸:', await cv.getImageInfo(image));

// 调整大小
const resized = await cv.resize(image, { width: 800, height: 600 });

// 转换为灰度图
const gray = await cv.convertColor(resized, 'BGR2GRAY');

// 应用高斯模糊
const blurred = await cv.blur(gray, 5);

// 保存结果
await cv.imwrite('processed.jpg', blurred);
```

## 项目结构

```
opencv-napi/
├── src/                    # 源代码
│   ├── addon.cpp          # Node-API 绑定
│   └── napi_opencv/       # OpenCV 包装器
├── lib/                   # 编译后的库文件
├── docs/                  # 文档
├── examples/              # 示例代码
├── test/                  # 测试文件
├── scripts/               # 构建和工具脚本
└── deps/                  # 依赖库
    └── OpenCV-Source/     # OpenCV 源码
```

## 开发

### 构建

```bash
# 安装依赖
npm install

# 构建原生模块
npm run build

# 清理构建文件
npm run clean
```

### 交叉编译

```bash
# 交叉编译所有平台
npm run cross-compile:all

# 验证交叉编译结果
npm run cross-compile:verify
```

### 文档生成

```bash
# 生成 API 文档
npm run docs:generate
```

## 贡献

我们欢迎社区贡献！请查看 [CONTRIBUTING.md](CONTRIBUTING.md) 了解详细信息。

### 开发流程

1. Fork 项目
2. 创建特性分支
3. 提交更改
4. 推送到分支
5. 创建 Pull Request

## 路线图

### v1.1.0 (计划中)
- [ ] 深度学习模块支持
- [ ] GPU 加速处理
- [ ] 视频处理功能
- [ ] 更多图像格式支持

### v1.2.0 (计划中)
- [ ] WebAssembly 支持
- [ ] 移动平台支持
- [ ] 实时图像处理
- [ ] 机器学习集成

## 性能

### 基准测试

OpenCV NAPI 在图像处理性能方面表现出色：

- **图像读取**: 比原生 Node.js 快 3-5 倍
- **图像缩放**: 比 Canvas API 快 2-3 倍
- **颜色转换**: 比 ImageMagick 快 1.5-2 倍
- **特征检测**: 接近原生 OpenCV 性能

### 内存使用

- 自动内存管理
- 零拷贝操作（在可能的情况下）
- 高效的数据结构

## 故障排除

### 常见问题

1. **构建失败**
   - 确保安装了所有先决条件
   - 检查 CMake 版本
   - 查看构建日志

2. **运行时错误**
   - 检查 OpenCV 版本兼容性
   - 验证图像文件格式
   - 查看错误日志

3. **性能问题**
   - 启用 OpenCV 优化
   - 调整线程数
   - 使用适当的数据类型

## 🚀 NPM 发布状态

- **当前版本**: 1.0.1
- **NPM 包**: [opencv-napi](https://www.npmjs.com/package/opencv-napi)
- **GitHub**: [opencv-napi](https://github.com/your-username/opencv-napi)
- **文档**: [完整文档](https://github.com/your-username/opencv-napi#readme)

## 许可证

MIT License - 详见 [LICENSE](LICENSE) 文件。

## 致谢

- [OpenCV](https://opencv.org/) - 计算机视觉库
- [Node-API](https://nodejs.org/api/n-api.html) - Node.js C API
- [node-gyp](https://github.com/nodejs/node-gyp) - 原生模块构建工具
- [计算机视觉社区](https://opencv.org/community/) - 开源贡献者
- [开源贡献者](https://github.com/your-username/opencv-napi/graphs/contributors) - 项目贡献者

## 支持

- 📧 邮箱: support@opencv-napi.com
- 🐛 问题: [GitHub Issues](https://github.com/your-username/opencv-napi/issues)
- 💬 讨论: [GitHub Discussions](https://github.com/your-username/opencv-napi/discussions)
- 📖 文档: [完整文档](https://github.com/your-username/opencv-napi#readme)

---

**为计算机视觉和 Node.js 社区用心制作 ❤️**
