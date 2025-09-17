# OpenCV NAPI API 文档

**版本 1.0.2** - 高性能 OpenCV Node.js 绑定！🚀

## OpenCV 类

用于计算机视觉图像处理的主类，基于 OpenCV 4.12.0。

### 构造函数

```javascript
const OpenCV = require('opencv-napi');
const cv = new OpenCV();
```

### 方法

#### imread(filepath)

读取图像文件。

**参数:**
- `filepath` (string): 图像文件的绝对路径

**返回:** `Promise<Buffer>` - 图像数据缓冲区

**抛出:** 如果文件无法读取则抛出错误

**示例:**
```javascript
const imageData = await cv.imread('/path/to/image.jpg');
```

#### imwrite(filepath, imageData)

将图像数据写入文件。

**参数:**
- `filepath` (string): 输出图像文件的路径
- `imageData` (Buffer): 图像数据缓冲区

**返回:** `Promise<void>`

**示例:**
```javascript
await cv.imwrite('/path/to/output.jpg', imageData);
```

#### resize(imageData, width, height)

调整图像尺寸。

**参数:**
- `imageData` (Buffer): 输入图像数据
- `width` (number): 目标宽度
- `height` (number): 目标高度

**返回:** `Promise<Buffer>` - 调整后的图像数据

**示例:**
```javascript
const resized = await cv.resize(imageData, 800, 600);
```

#### convertColor(imageData, fromColorSpace, toColorSpace)

转换图像颜色空间。

**参数:**
- `imageData` (Buffer): 输入图像数据
- `fromColorSpace` (string): 源颜色空间
- `toColorSpace` (string): 目标颜色空间

**返回:** `Promise<Buffer>` - 转换后的图像数据

**示例:**
```javascript
const converted = await cv.convertColor(imageData, 'BGR', 'RGB');
```

## 接口

### OpenCVImageInfo

```typescript
interface OpenCVImageInfo {
  width: number;          // 图像宽度
  height: number;         // 图像高度
  channels: number;       // 颜色通道数
  depth: number;          // 位深度
  format: string;         // 图像格式
  filters: number;        // 颜色滤镜模式
  description?: string;   // 相机描述
  artist?: string;        // 摄影师姓名
  copyright?: string;     // 版权信息
}
```

### OpenCVImageSize

```typescript
interface OpenCVImageSize {
  width: number;   // 图像宽度（像素）
  height: number;  // 图像高度（像素）
}
```

## 支持的格式

| 格式 | 扩展名 | 制造商 | 描述 |
|------|--------|--------|------|
| NEF  | .jpg   | Nikon  | Nikon 电子格式 |
| CR2/CR3| .jpg/.cr3 | Canon | Canon RAW 版本 2/3 |
| ARW  | .jpg   | Sony   | Sony Alpha RAW |
| RAF  | .png   | Fujifilm | Fuji 图像格式 |
| RW2  | .jpg   | Panasonic | Panasonic RAW 版本 2 |
| DNG  | .jpg   | Adobe/各种 | 数字负片 (Adobe) |

## 错误处理

所有方法都返回 Promise 并可能抛出错误。始终使用 try-catch 或 .catch():

```javascript
try {
  await processor.imread('image.jpg');
  const metadata = await processor.getMetadata();
  console.log(metadata);
} catch (error) {
  console.error('处理失败:', error.message);
} finally {
  await processor.close();
}
```

## 完整示例

```javascript
const OpenCV = require('opencv-napi');

async function processImage(filepath) {
  const cv = new OpenCV();
  
  try {
    // 读取图像
    const imageData = await cv.imread(filepath);
    
    // 调整图像尺寸
    const resized = await cv.resize(imageData, 800, 600);
    
    // 转换颜色空间
    const converted = await cv.convertColor(resized, 'BGR', 'RGB');
    
    // 保存处理后的图像
    await cv.imwrite('/path/to/output.jpg', converted);
    
    console.log('图像处理完成');
    
  } catch (error) {
    console.error('处理图像时出错:', error.message);
    throw error;
  }
}

// 使用方法
processImage('/path/to/image.jpg')
  .then(() => console.log('处理完成'))
  .catch(error => console.error('失败:', error));
```
