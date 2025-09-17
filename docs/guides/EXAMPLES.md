# OpenCV 使用示例

**版本 1.0.9** - 高性能 OpenCV Node.js 绑定！🚀

## 基础图像处理

```javascript
const OpenCV = require('opencv-napi');

async function basicExample() {
  const cv = new OpenCV();
  
  try {
    // 读取图像
    const imageData = await cv.imread('photo.jpg');
    
    // 调整图像尺寸
    const resized = await cv.resize(imageData, 800, 600);
    
    // 保存处理后的图像
    await cv.imwrite('photo_resized.jpg', resized);
    
    console.log('📷 图像处理完成');
    console.log('📐 已调整为 800x600 像素');
    
  } catch (error) {
    console.error('处理失败:', error.message);
  }
}
```

## 批量处理多个文件

```javascript
const fs = require('fs');
const path = require('path');

async function batchProcess(directory) {
  const files = fs.readdirSync(directory)
    .filter(file => ['.jpg', '.png', '.bmp'].includes(path.extname(file).toLowerCase()));
  
  const results = [];
  
  for (const file of files) {
    const cv = new OpenCV();
    try {
      const inputPath = path.join(directory, file);
      const outputPath = path.join(directory, 'processed_' + file);
      
      // 读取并处理图像
      const imageData = await cv.imread(inputPath);
      const resized = await cv.resize(imageData, 1024, 768);
      await cv.imwrite(outputPath, resized);
      
      results.push({
        filename: file,
        processed: true,
        outputPath
      });
      
    } catch (error) {
      console.error(`处理 ${file} 失败: ${error.message}`);
    }
  }
  
  return results;
}
```

## 照片画廊元数据提取

```javascript
async function extractGalleryMetadata(photoPath) {
  const processor = new OpenCV();
  
  try {
    await processor.imread(photoPath);
    const metadata = await processor.getMetadata();
    const size = await processor.getImageSize();
    
    return {
      // 基本信息
      camera: {
        make: metadata.make,
        model: metadata.model
      },
      
      // 技术设置
      settings: {
        iso: metadata.iso,
        aperture: metadata.aperture,
        shutterSpeed: metadata.shutterSpeed,
        focalLength: metadata.focalLength
      },
      
      // 图像规格
      image: {
        width: size.width,
        height: size.height,
        megapixels: Number((size.width * size.height / 1000000).toFixed(1)),
        aspectRatio: (size.width / size.height).toFixed(2)
      },
      
      // 拍摄信息
      capture: {
        timestamp: metadata.timestamp,
        date: new Date(metadata.timestamp * 1000).toISOString(),
        artist: metadata.artist,
        copyright: metadata.copyright
      }
    };
    
  } finally {
    await processor.close();
  }
}
```

## 性能监控

```javascript
async function monitoredProcessing(filepath) {
  const processor = new OpenCV();
  const startTime = Date.now();
  
  try {
    console.time('总处理时间');
    
    console.time('文件加载');
    await processor.imread(filepath);
    console.timeEnd('文件加载');
    
    console.time('元数据提取');
    const metadata = await processor.getMetadata();
    console.timeEnd('元数据提取');
    
    console.time('尺寸检测');
    const size = await processor.getImageSize();
    console.timeEnd('尺寸检测');
    
    console.timeEnd('总处理时间');
    
    const fileStats = require('fs').statSync(filepath);
    const throughput = fileStats.size / (Date.now() - startTime) * 1000 / 1024 / 1024;
    
    console.log(`📊 吞吐量: ${throughput.toFixed(2)} MB/s`);
    
    return { metadata, size };
    
  } finally {
    await processor.close();
  }
}
```

## 错误处理最佳实践

```javascript
async function robustProcessing(filepath) {
  const processor = new OpenCV();
  
  try {
    // 验证文件存在
    if (!require('fs').existsSync(filepath)) {
      throw new Error(`文件未找到: ${filepath}`);
    }
    
    // 检查文件扩展名
    const ext = require('path').extname(filepath).toLowerCase();
    const supported = ['.jpg', '.jpg', '.cr3', '.jpg', '.png', '.jpg', '.jpg'];
    if (!supported.includes(ext)) {
      throw new Error(`不支持的格式: ${ext}`);
    }
    
    await processor.imread(filepath);
    
    // 带超时的提取
    const timeout = new Promise((_, reject) => 
      setTimeout(() => reject(new Error('处理超时')), 30000)
    );
    
    const processing = Promise.all([
      processor.getMetadata(),
      processor.getImageSize()
    ]);
    
    const [metadata, size] = await Promise.race([processing, timeout]);
    
    return { metadata, size, success: true };
    
  } catch (error) {
    console.error(`处理 ${filepath} 时出错:`, error.message);
    return { error: error.message, success: false };
  } finally {
    try {
      await processor.close();
    } catch (closeError) {
      console.warn('警告: 关闭处理器失败:', closeError.message);
    }
  }
}
```

## 与 Express.js 集成

```javascript
const express = require('express');
const multer = require('multer');
const OpenCV = require('opencv-napi');

const app = express();
const upload = multer({ dest: 'uploads/' });

app.post('/analyze-raw', upload.single('rawFile'), async (req, res) => {
  if (!req.file) {
    return res.status(400).json({ error: '未上传文件' });
  }
  
  const processor = new OpenCV();
  
  try {
    await processor.imread(req.file.path);
    const metadata = await processor.getMetadata();
    const size = await processor.getImageSize();
    
    res.json({
      success: true,
      data: {
        camera: `${metadata.make} ${metadata.model}`,
        resolution: `${size.width}x${size.height}`,
        settings: {
          iso: metadata.iso,
          aperture: metadata.aperture,
          shutterSpeed: metadata.shutterSpeed,
          focalLength: metadata.focalLength
        },
        captureDate: new Date(metadata.timestamp * 1000).toISOString()
      }
    });
    
  } catch (error) {
    res.status(500).json({
      success: false,
      error: error.message
    });
  } finally {
    await processor.close();
    // 清理上传的文件
    require('fs').unlinkSync(req.file.path);
  }
});
```
