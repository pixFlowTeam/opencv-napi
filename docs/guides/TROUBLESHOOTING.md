# 故障排除指南

本文档记录了在 OpenCV 交叉编译过程中可能遇到的常见问题及其解决方案。

## 🔧 常见问题及解决方案

### 1. Linux ARM64 缺少 core 库问题

**问题描述**: 
Linux ARM64 平台构建时缺少 `libopencv_core.so` 文件，导致验证失败，显示 "7/8 个库文件 - 部分成功（缺少 core 库）"。

**症状**:
- 验证脚本显示 Linux ARM64 平台缺少 core 库
- 其他模块（imgproc、objdetect 等）正常构建
- 只有 core 模块的库文件缺失

**解决方案**:
```bash
# 1. 进入 core 模块构建目录
cd deps/OpenCV-Source/opencv-4.12.0/build/linux-arm64/modules/core

# 2. 重新构建 core 模块
make

# 3. 验证修复结果
cd /Users/fuguoqiang/Documents/workspace/infra/opencvspeed
node scripts/verify-cross-compile.js
```

**原因分析**:
- **构建过程中的依赖问题**: core 模块可能因为某些依赖问题没有完全构建完成
- **构建顺序问题**: 其他模块（如 imgproc、objdetect 等）依赖于 core 模块，但 core 模块的构建可能被中断
- **交叉编译工具链问题**: ARM64 交叉编译工具链可能在某些情况下导致 core 模块构建失败

**预防措施**:
- 确保构建环境稳定
- 在构建过程中监控 core 模块的构建状态
- 如果发现 core 模块构建失败，及时重新构建

### 2. 目标检测模块被禁用问题

**问题描述**: 
验证脚本显示 `opencv_objdetect` 模块未找到，但实际上配置中已启用。

**解决方案**:
```bash
# 1. 检查配置
grep -i "BUILD_opencv_objdetect" scripts/cross-compile.js

# 2. 确保依赖模块也被启用
# 在 scripts/cross-compile.js 中确保：
# - BUILD_opencv_objdetect: 'ON'
# - BUILD_opencv_calib3d: 'ON'  # objdetect 的依赖

# 3. 重新编译
node scripts/cross-compile.js <platform>
```

### 3. 验证脚本报告文件格式错误

**问题描述**: 
验证脚本无法正确识别不同平台的库文件格式（.so、.dylib、.dll）。

**解决方案**:
```bash
# 1. 检查文件是否存在
ls -la deps/OpenCV-Source/opencv-4.12.0/build/*/lib/

# 2. 检查文件格式
file deps/OpenCV-Source/opencv-4.12.0/build/*/lib/libopencv_core*

# 3. 更新验证脚本（如果需要）
# 确保 getExpectedLibs 方法正确识别平台特定的文件扩展名
```

### 4. 构建过程中断问题

**问题描述**: 
构建过程在某个阶段中断，导致部分模块未完成构建。

**解决方案**:
```bash
# 1. 清理构建目录
rm -rf deps/OpenCV-Source/opencv-4.12.0/build/<platform>

# 2. 重新构建
node scripts/cross-compile.js <platform>

# 3. 如果问题持续，检查系统资源
# - 确保有足够的磁盘空间
# - 检查内存使用情况
# - 确保构建工具链完整
```

### 5. 交叉编译工具链问题

**问题描述**: 
交叉编译工具链不可用或配置错误。

**解决方案**:
```bash
# 1. 检查工具链是否安装
which aarch64-linux-gnu-gcc
which x86_64-linux-musl-gcc

# 2. 安装缺失的工具链
# macOS:
brew install FiloSottile/musl-cross/musl-cross

# 3. 验证工具链
aarch64-linux-gnu-gcc --version
x86_64-linux-musl-gcc --version
```

### 6. opencv_ts 模块禁用导致 core 库构建问题

**问题描述**: 
禁用 `opencv_ts` 模块可能导致其他模块（特别是 `opencv_core`）构建不完整。

**症状**:
- 验证脚本显示缺少 core 库文件
- 其他模块正常构建，但 core 模块缺失
- 构建过程中没有明显的错误信息

**解决方案**:
```bash
# 方案1: 启用 opencv_ts 模块（推荐）
# 在 scripts/cross-compile.js 中修改：
'BUILD_opencv_ts': 'ON',  // 启用 ts 模块以支持其他模块的构建

# 然后重新编译
node scripts/cross-compile.js <platform>

# 方案2: 手动重新构建 core 模块
cd deps/OpenCV-Source/opencv-4.12.0/build/<platform>/modules/core
make

# 验证修复结果
node scripts/verify-cross-compile.js
```

**原因分析**:
- `opencv_ts` 模块是 OpenCV 构建系统的重要组成部分
- 即使禁用了测试，其他模块的构建过程仍可能依赖 `opencv_ts`
- `opencv_ts` 模块依赖 `opencv_core`，其构建状态可能影响 core 模块的完整性
- 交叉编译环境下，模块间的依赖关系更加敏感

## 🔍 调试技巧

### 检查构建日志
```bash
# 查看详细构建日志
node scripts/cross-compile.js <platform> 2>&1 | tee build.log

# 搜索错误信息
grep -i "error\|failed\|fatal" build.log
```

### 验证库文件
```bash
# 检查库文件是否存在
find deps/OpenCV-Source/opencv-4.12.0/build/ -name "*.so" -o -name "*.dylib" -o -name "*.dll"

# 检查库文件格式
file deps/OpenCV-Source/opencv-4.12.0/build/*/lib/*

# 检查库文件大小
ls -lh deps/OpenCV-Source/opencv-4.12.0/build/*/lib/
```

### 检查依赖关系
```bash
# 检查 CMake 配置
grep -i "opencv_core" deps/OpenCV-Source/opencv-4.12.0/build/*/CMakeCache.txt

# 检查模块依赖
grep -i "opencv_core.*DEPS" deps/OpenCV-Source/opencv-4.12.0/build/*/CMakeCache.txt
```

## 📞 获取帮助

如果遇到本文档未涵盖的问题，请：

1. 检查构建日志中的错误信息
2. 确认系统环境和工具链配置
3. 参考 [OpenCV 官方文档](https://docs.opencv.org/)
4. 查看项目的 [Issues](https://github.com/your-repo/issues) 页面

## 📚 相关文档

- [OpenCV 交叉编译状态](OPENCV_CROSS_COMPILE_STATUS.md)
- [交叉编译指南](CROSS_COMPILATION.md)
- [构建策略](BUILD_STRATEGIES.md)
- [API 文档](API.md)

---

**最后更新**: 2025年9月16日
