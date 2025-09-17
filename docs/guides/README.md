# 文档索引

欢迎来到 opencv-napi 项目文档中心！

## 📚 核心文档

### 交叉编译
- [交叉编译指南](CROSS_COMPILATION.md) - OpenCV 和 OpenCV 交叉编译完整指南
- [OpenCV 交叉编译状态](OPENCV_CROSS_COMPILE_STATUS.md) - OpenCV 所有平台构建状态详情
- [验证指南](VERIFICATION_GUIDE.md) - OpenCV 交叉编译产物验证完整指南

### API 文档
- [API 文档](API.md) - 完整的 API 参考
- [缓冲区 API](BUFFER_API.md) - 内存缓冲区操作 API
- [支持的格式](FORMATS.md) - 支持的 图像格式列表

### 构建和部署
- [构建策略](BUILD_STRATEGIES.md) - 构建配置和优化策略
- [简单构建要求](SIMPLE_BUILD_REQUIREMENTS.md) - 最小化构建环境要求
- [跨平台编译](CROSS_COMPILATION.md) - 多平台交叉编译指南

### 发布和分发
- [NPM 发布指南](NPM_PUBLISH_GUIDE.md) - 如何发布到 NPM
- [NAPI 发布策略](NAPI_PUBLISH_STRATEGY.md) - NAPI 模块发布策略
- [NAPI 构建答案](NAPI_BUILD_ANSWER.md) - NAPI 构建常见问题解答

### 集成和扩展
- [BUMPP 集成](BUMPP_INTEGRATION.md) - BUMPP 构建系统集成
- [Chroma.js 集成](CHROMA_JS_INTEGRATION.md) - 色彩处理集成

### 测试和示例
- [测试指南](TESTING.md) - 完整的测试说明
- [示例代码](EXAMPLES.md) - 使用示例和最佳实践

### 故障排除
- [故障排除指南](TROUBLESHOOTING.md) - 常见问题及解决方案

## 🚀 快速开始

### 1. 安装和构建
```bash
# 检查环境
npm run check:env

# 构建项目
npm run build

# 交叉编译所有平台
npm run cross-compile:all
```

### 2. 验证构建
```bash
# 验证 OpenCV 交叉编译
npm run cross-compile:verify

# 验证 OpenCV 交叉编译
node scripts/verify-cross-compile.js

# 查看构建摘要
node scripts/verify-cross-compile.js --summary

# 检查依赖关系
node scripts/verify-cross-compile.js --deps
```

### 3. 清理构建产物
```bash
# 清理 OpenCV 构建中间产物（节省空间）
npm run cross-compile:opencv:clean

# 查看清理后的文件结构
npm run cross-compile:opencv:clean:structure
```

### 4. 更新状态
```bash
# 更新交叉编译状态文档
npm run cross-compile:status:update
```

## 📊 当前状态

### OpenCV 交叉编译
- ✅ Windows x64
- ✅ macOS x64
- ✅ macOS ARM64
- ✅ Linux x64
- ✅ Linux ARM64

### OpenCV 交叉编译
- ✅ Windows x64 (46.89 MB) - libopencv_world4120.dll
- ✅ macOS x64 (18.78 MB) - libopencv_world.4.12.0.dylib
- ✅ macOS ARM64 (18.58 MB) - libopencv_world.4.12.0.dylib
- ✅ Linux x64 (55.41 MB) - libopencv_world.so.4.12.0
- ✅ Linux ARM64 (21.48 MB) - libopencv_world.so.4.12.0

## 🔧 维护

### 定期任务
- **每周**: 检查构建状态
- **每月**: 更新工具链版本
- **每季度**: 重新构建所有平台

### 状态更新
使用以下命令更新所有状态文档：
```bash
npm run cross-compile:status:update
```

## 🤝 贡献

如果您发现文档中的问题或需要添加新内容：

1. 检查现有文档是否已覆盖您的需求
2. 在 GitHub 上创建 Issue 描述问题
3. 提交 Pull Request 包含您的改进

## 📞 支持

- 📖 [GitHub 仓库](https://github.com/pixFlowTeam/opencv-napi)
- 🐛 [问题报告](https://github.com/pixFlowTeam/opencv-napi/issues)
- 💬 [讨论区](https://github.com/pixFlowTeam/opencv-napi/discussions)

---

**最后更新**: 2025年1月16日  
**维护者**: opencv-napi 团队
