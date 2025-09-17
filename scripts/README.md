# OpenCV Speed 脚本中心

欢迎来到 OpenCV Speed 项目的脚本中心！这里包含了项目的所有构建、测试、工具和文档生成脚本。

## 📁 脚本结构

### 🏗️ 构建脚本 (`build/`)
- [build-opencv-unified.sh](build/build-opencv-unified.sh) - 统一 OpenCV 构建脚本
- [build-opencv.js](build/build-opencv.js) - OpenCV 构建工具
- [build_napi.sh](build/build_napi.sh) - NAPI 构建脚本
- [build_napi_modular.sh](build/build_napi_modular.sh) - 模块化 NAPI 构建脚本
- [clean-opencv-build.js](build/clean-opencv-build.js) - 清理 OpenCV 构建文件
- [cross-compile.js](build/cross-compile.js) - 交叉编译工具
- [update-cross-compile-status.js](build/update-cross-compile-status.js) - 更新交叉编译状态
- [verify-cross-compile.js](build/verify-cross-compile.js) - 验证交叉编译结果
- [verify-cross-compile.js](build/verify-cross-compile.js) - 验证 OpenCV 交叉编译

### 🧪 测试脚本 (`test/`)
- [test-fixed.js](test/test-fixed.js) - 修复后的测试脚本
- [test-rebuild.js](test/test-rebuild.js) - 重建测试脚本
- [test_mat_napi.js](test/test_mat_napi.js) - Mat NAPI 测试
- [test_napi_opencv.js](test/test_napi_opencv.js) - OpenCV NAPI 测试

### 🛠️ 工具脚本 (`utils/`)
- [check-environment.js](utils/check-environment.js) - 环境检查工具
- [fix-try-catch.js](utils/fix-try-catch.js) - 修复 try-catch 语句
- [release.js](utils/release.js) - 发布工具
- [remove-catch.js](utils/remove-catch.js) - 移除 catch 语句
- [remove-try-catch.js](utils/remove-try-catch.js) - 移除 try-catch 语句

### 📖 文档脚本 (`docs/`)
- [batch-jpeg-conversion.js](docs/batch-jpeg-conversion.js) - 批量 JPEG 转换工具
- [extract-thumbnails.js](docs/extract-thumbnails.js) - 缩略图提取工具
- [generate-docs.js](docs/generate-docs.js) - 文档生成工具

## 🚀 快速使用

### 构建相关
```bash
# 构建 OpenCV
node scripts/buildScript/build-opencv.js

# 交叉编译所有平台
node scripts/buildScript/cross-compile.js

# 清理构建文件
node scripts/buildScript/clean-opencv-build.js
```

### 测试相关
```bash
# 运行 NAPI 测试
node scripts/test/test_napi_opencv.js

# 运行 Mat 测试
node scripts/test/test_mat_napi.js
```

### 工具相关
```bash
# 检查环境
node scripts/utils/check-environment.js

# 发布项目
node scripts/utils/release.js
```

### 文档相关
```bash
# 生成文档
node scripts/docs/generate-docs.js

# 提取缩略图
node scripts/docs/extract-thumbnails.js

# 批量 JPEG 转换
node scripts/docs/batch-jpeg-conversion.js
```

## 📝 脚本维护

所有脚本都按功能分类组织，便于查找和维护。每个脚本都包含详细的注释和使用说明。

### 添加新脚本

1. 根据功能选择合适的子目录
2. 添加详细的注释和文档
3. 更新此 README 文件
4. 确保脚本有适当的错误处理

---

*最后更新：2024年9月17日*
