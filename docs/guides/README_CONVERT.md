# RAW 转 JPEG 转换工具

## 使用方法

### 转换单个文件
```bash
node ./test/convert-raw-to-jpg.js <输入RAW文件> <输出JPG文件>
```

### 转换所有文件
```bash
node convert-raw-to-jpg.js --all
```

## 示例

```bash
# 转换 Sony ARW 文件
node ./test/convert-raw-to-jpg.js raw-samples-repo/ARW/DSC02975.ARW output/sony_photo.jpg

# 转换所有 图像文件
node ./test/convert-raw-to-jpg.js --all
```

## 支持的格式

- Sony ARW
- Canon CR2/CR3
- Nikon NEF
- Leica DNG
- Panasonic RW2
- Pentax PEF
- 其他 OpenCV 支持的 图像格式

## 特点

- ✅ 使用 OpenCV 默认参数，确保颜色正确
- ✅ 完全模仿 `safe_` 脚本的处理方式
- ✅ 支持所有主流相机厂商的 图像格式
- ✅ 自动处理，无需手动调参
