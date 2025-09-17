# OpenCV 交叉编译验证指南

## 📋 概述

本文档介绍如何使用验证脚本来检查 OpenCV 交叉编译产物的完整性和正确性。

## 🚀 快速开始

### 基本验证
```bash
# 验证所有平台的 OpenCV 交叉编译产物
node scripts/verify-cross-compile.js

# 查看构建摘要
node scripts/verify-cross-compile.js --summary

# 检查依赖关系
node scripts/verify-cross-compile.js --deps
```

### 清理构建产物
```bash
# 清理 OpenCV 构建中间产物（节省空间）
npm run cross-compile:opencv:clean

# 查看清理后的文件结构
npm run cross-compile:opencv:clean:structure
```

## 🔍 验证功能详解

### 1. 库文件验证
验证脚本会检查每个平台的 `libopencv_world` 统一库文件：

| 平台 | 期望的库文件 | 文件类型 |
|------|-------------|----------|
| Windows x64 | `libopencv_world4120.dll` | PE32+ DLL (x86-64) |
| macOS x64 | `libopencv_world.4.12.0.dylib` | Mach-O 64-bit (x86_64) |
| macOS ARM64 | `libopencv_world.4.12.0.dylib` | Mach-O 64-bit (arm64) |
| Linux x64 | `libopencv_world.so.4.12.0` | ELF 64-bit LSB (x86-64) |
| Linux ARM64 | `libopencv_world.so.4.12.0` | ELF 64-bit LSB (ARM aarch64) |

### 2. 头文件验证
- 检查 OpenCV 头文件目录是否存在
- 统计头文件数量（期望：312 个）
- 验证头文件完整性

### 3. 文件类型验证
使用 `file` 命令检查库文件的架构和格式：
- **Windows**: PE32+ DLL (x86-64)
- **macOS**: Mach-O 64-bit (x86_64/arm64)
- **Linux**: ELF 64-bit LSB (x86-64/ARM aarch64)

### 4. 依赖关系检查
- 检查 Linux 平台的库依赖关系
- 使用 `ldd` 命令验证动态链接
- 检测缺失的依赖项

## 📊 验证输出示例

### 成功验证输出
```
🔍 验证 OpenCV 交叉编译产物...

📦 检查 darwin-arm64 平台...
  ✅ libopencv_world.4.12.0.dylib: 18.58 MB
  📊 找到 1/1 个库文件
  ✅ 头文件: 312 个
  ✅ 文件类型: Mach-O 64-bit dynamically linked shared library arm64

📦 检查 darwin-x64 平台...
  ✅ libopencv_world.4.12.0.dylib: 18.78 MB
  📊 找到 1/1 个库文件
  ✅ 头文件: 312 个
  ✅ 文件类型: Mach-O 64-bit dynamically linked shared library arm64

📦 检查 linux-arm64 平台...
  ✅ libopencv_world.so.4.12.0: 21.48 MB
  📊 找到 1/1 个库文件
  ✅ 头文件: 312 个
  ✅ 文件类型: ELF 64-bit LSB shared object, ARM aarch64

📦 检查 linux-x64 平台...
  ✅ libopencv_world.so.4.12.0: 55.41 MB
  📊 找到 1/1 个库文件
  ✅ 头文件: 312 个
  ✅ 文件类型: ELF 64-bit LSB shared object, x86-64

📦 检查 win32 平台...
  ✅ libopencv_world4120.dll: 46.89 MB
  📊 找到 1/1 个库文件
  ✅ 头文件: 312 个
  ✅ 文件类型: PE32+ executable (DLL) (console) x86-64

🎉 所有 OpenCV 交叉编译产物验证通过！
```

### 摘要输出
```
📊 OpenCV 交叉编译产物摘要:
============================
✅ darwin-arm64: 3 个库文件, 55.73 MB
✅ darwin-x64: 3 个库文件, 56.34 MB
✅ linux-arm64: 1 个库文件, 21.48 MB
✅ linux-x64: 1 个库文件, 55.41 MB
✅ win32: 1 个库文件, 3.80 MB
```

### 依赖检查输出
```
🔍 检查 OpenCV 依赖...

✅ 依赖检查通过
```

## ⚠️ 常见问题与解决方案

### 1. 库文件未找到
**问题**: 验证时显示 "未找到" 错误
**解决方案**:
```bash
# 检查构建目录是否存在
ls -la deps/OpenCV-Source/opencv-4.12.0/build/

# 重新构建特定平台
node scripts/cross-compile.js <platform> <arch>
```

### 2. 文件类型不匹配
**问题**: 库文件的架构与期望不符
**解决方案**:
```bash
# 检查交叉编译工具链
x86_64-linux-musl-gcc --version
aarch64-linux-musl-gcc --version

# 重新构建
rm -rf deps/OpenCV-Source/opencv-4.12.0/build/<platform>
node scripts/cross-compile.js <platform> <arch>
```

### 3. 头文件数量不正确
**问题**: 头文件数量不是 312 个
**解决方案**:
```bash
# 检查头文件目录
ls -la deps/OpenCV-Source/opencv-4.12.0/build/<platform>/include/

# 重新构建
node scripts/cross-compile.js <platform> <arch>
```

### 4. 依赖关系问题
**问题**: Linux 平台缺少依赖
**解决方案**:
```bash
# 检查系统依赖
ldd deps/OpenCV-Source/opencv-4.12.0/build/linux-x64/lib/libopencv_world.so.4.12.0

# 安装缺失的依赖
# Ubuntu/Debian
sudo apt-get install libc6-dev

# CentOS/RHEL
sudo yum install glibc-devel
```

## 🧹 构建产物清理

### 清理脚本功能
清理脚本 (`scripts/clean-opencv-build.js`) 用于删除 OpenCV 构建过程中的中间产物，保留必要的库文件和头文件：

**删除的内容：**
- `CMakeFiles/` - CMake 构建文件
- `modules/` - 模块构建目录
- `3rdparty/` - 第三方库构建
- `*.o`, `*.obj` - 目标文件
- `*.log` - 日志文件
- `Makefile` - 构建文件

**保留的内容：**
- `lib/` - 库文件目录
- `include/` - 头文件目录
- `bin/` - Windows DLL 目录
- `*.dll`, `*.dylib`, `*.so*` - 动态库文件
- `*.a`, `*.lib` - 静态库和导入库
- `OpenCVConfig*.cmake` - OpenCV 配置文件

### 清理效果
- **清理前**: ~1.65 GB
- **清理后**: ~470 MB
- **节省空间**: ~1.19 GB (72% 减少)

### 清理后文件结构
```
deps/OpenCV-Source/opencv-4.12.0/build/
├── win32/
│   ├── bin/
│   │   └── libopencv_world4120.dll (46.89 MB)
│   ├── include/ (240 个头文件)
│   └── OpenCVConfig*.cmake
├── darwin-x64/
│   ├── lib/
│   │   ├── libopencv_world.4.12.0.dylib (18.78 MB)
│   │   ├── libopencv_world.412.dylib
│   │   └── libopencv_world.dylib
│   ├── include/ (240 个头文件)
│   └── OpenCVConfig*.cmake
├── darwin-arm64/
│   ├── lib/
│   │   ├── libopencv_world.4.12.0.dylib (18.58 MB)
│   │   ├── libopencv_world.412.dylib
│   │   └── libopencv_world.dylib
│   ├── include/ (240 个头文件)
│   └── OpenCVConfig*.cmake
├── linux-x64/
│   ├── lib/
│   │   └── libopencv_world.so.4.12.0 (55.41 MB)
│   ├── include/ (240 个头文件)
│   └── OpenCVConfig*.cmake
└── linux-arm64/
    ├── lib/
    │   └── libopencv_world.so.4.12.0 (21.48 MB)
    ├── include/ (240 个头文件)
    └── OpenCVConfig*.cmake
```

## 🔧 验证脚本配置

### 脚本位置
- 主脚本: `scripts/verify-cross-compile.js`
- 构建目录: `deps/OpenCV-Source/opencv-4.12.0/build/`

### 支持的参数
- `--summary`: 显示构建摘要
- `--deps`: 检查依赖关系
- 无参数: 执行完整验证

### 自定义验证
如果需要修改验证逻辑，可以编辑 `scripts/verify-cross-compile.js` 文件：

```javascript
// 修改期望的库文件
getExpectedLibs(platform) {
  if (platform.startsWith('darwin')) {
    return ['libopencv_world.4.12.0.dylib'];
  } else if (platform.startsWith('win32')) {
    return ['libopencv_world4120.dll'];
  } else {
    return ['libopencv_world.so.4.12.0'];
  }
}
```

## 📈 性能基准

### 验证时间
- 基本验证: ~2-5 秒
- 依赖检查: ~1-3 秒
- 完整验证: ~5-10 秒

### 库文件大小基准
| 平台 | 最小大小 | 典型大小 | 最大大小 |
|------|----------|----------|----------|
| Windows x64 | 40 MB | 47 MB | 55 MB |
| macOS x64 | 15 MB | 19 MB | 25 MB |
| macOS ARM64 | 15 MB | 19 MB | 25 MB |
| Linux x64 | 50 MB | 55 MB | 65 MB |
| Linux ARM64 | 18 MB | 21 MB | 28 MB |

## 🚀 自动化集成

### CI/CD 集成
```yaml
# GitHub Actions 示例
- name: Verify OpenCV Cross Compilation
  run: |
    node scripts/verify-cross-compile.js
    node scripts/verify-cross-compile.js --summary
    node scripts/verify-cross-compile.js --deps
```

### 预提交钩子
```bash
#!/bin/bash
# .git/hooks/pre-commit
echo "验证 OpenCV 交叉编译产物..."
node scripts/verify-cross-compile.js
if [ $? -ne 0 ]; then
  echo "验证失败，请检查构建产物"
  exit 1
fi
```

## 📚 相关文档

- [OpenCV 交叉编译状态](OPENCV_CROSS_COMPILE_STATUS.md)
- [交叉编译指南](CROSS_COMPILATION.md)
- [故障排除指南](TROUBLESHOOTING.md)
- [API 文档](API.md)

---

**最后更新**: 2025年1月16日  
**维护者**: OpenCV Speed 项目团队
