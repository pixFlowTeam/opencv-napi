# Agent 工作流程指南

## 概述

本文档描述了如何使用多个 AI Agent 协作开发 OpenCV NAPI 接口的具体工作流程。

**重要说明：本项目所有 Agent 协作相关文档和代码注释必须使用中文。**

## Agent 角色分配

### Agent A: Core 模块专家
- **负责模块**: `core`
- **主要功能**: Mat 操作、基础数学运算、数组操作
- **优先级**: 1 (最高)
- **依赖**: 无

### Agent B: 图像处理专家
- **负责模块**: `imgproc`
- **主要功能**: 图像滤波、几何变换、形态学操作
- **优先级**: 2
- **依赖**: `core`

### Agent C: 图像编解码专家
- **负责模块**: `imgcodecs`
- **主要功能**: 图像读取、保存、格式转换
- **优先级**: 2
- **依赖**: `core`

### Agent D: 目标检测专家
- **负责模块**: `objdetect`
- **主要功能**: 人脸检测、物体检测、级联分类器
- **优先级**: 3
- **依赖**: `core`, `imgproc`

### Agent E: 特征检测专家
- **负责模块**: `features2d`
- **主要功能**: 特征点检测、描述符、匹配
- **优先级**: 3
- **依赖**: `core`, `imgproc`

### Agent F: 计算摄影专家
- **负责模块**: `photo`
- **主要功能**: 图像修复、HDR、去噪
- **优先级**: 4
- **依赖**: `core`, `imgproc`

### Agent G: 相机标定专家
- **负责模块**: `calib3d`
- **主要功能**: 相机标定、立体视觉、PnP
- **优先级**: 4
- **依赖**: `core`, `imgproc`, `features2d`

### Agent H: 视频处理专家
- **负责模块**: `videoio`
- **主要功能**: 视频读取、保存、摄像头操作
- **优先级**: 3
- **依赖**: `core`, `imgcodecs`

### Agent I: 机器学习专家
- **负责模块**: `ml`
- **主要功能**: 机器学习算法、分类器、回归
- **优先级**: 5
- **依赖**: `core`

### Agent J: G-API 专家
- **负责模块**: `gapi`
- **主要功能**: 图API、流水线处理、GPU加速
- **优先级**: 6
- **依赖**: `core`, `imgproc`, `imgcodecs`

## 开发流程

### 1. 任务初始化
```bash
# 每个 Agent 在开始工作前需要：
1. 克隆项目仓库
2. 安装依赖: npm install
3. 构建项目: npm run build
4. 运行测试: npm test
```

### 2. 模块开发步骤

#### 步骤 1: 创建模块骨架
```cpp
// 1. 创建模块头文件: src/napi_modules/{module_name}/{module_name}_module.h
// 2. 创建模块实现: src/napi_modules/{module_name}/{module_name}_module.cpp
// 3. 实现 ModuleInterface 接口
// 4. 使用 REGISTER_NAPI_MODULE 宏注册模块
```

#### 步骤 2: 实现核心功能
```cpp
// 1. 实现 RegisterFunctions 方法
// 2. 实现所有导出的函数
// 3. 添加错误处理和参数验证
// 4. 实现类型转换
```

#### 步骤 3: 添加测试
```typescript
// 1. 创建测试文件: test/{module_name}.test.ts
// 2. 编写单元测试
// 3. 编写集成测试
// 4. 测试边界情况
```

#### 步骤 4: 更新文档
```markdown
// 1. 更新 API 文档
// 2. 添加使用示例
// 3. 更新 README
// 4. 记录变更日志
```

### 3. 代码提交规范

#### 提交信息格式
```
feat({module}): 添加新功能描述

- 具体变更1
- 具体变更2

Closes #issue_number
```

#### 分支命名规范
```
feature/{module}-{feature_name}
fix/{module}-{issue_description}
docs/{module}-{documentation_type}
```

### 4. 代码审查流程

#### 自动检查
- [ ] 代码编译通过
- [ ] 所有测试通过
- [ ] 代码风格符合规范
- [ ] 没有内存泄漏
- [ ] 性能测试通过

#### 人工审查
- [ ] 接口设计合理
- [ ] 错误处理完善
- [ ] 文档更新及时
- [ ] 示例代码正确

### 5. 集成测试

#### 模块间集成
```typescript
// 测试模块间的依赖关系
import { core, imgproc } from 'opencv-napi';

const mat = core.Mat_Create(100, 100, core.CV_8UC3);
const blurred = imgproc.GaussianBlur(mat, [5, 5], 0);
```

#### 端到端测试
```typescript
// 测试完整的图像处理流程
import { imgcodecs, imgproc, objdetect } from 'opencv-napi';

const image = imgcodecs.imread('test.jpg');
const gray = imgproc.cvtColor(image, imgproc.COLOR_BGR2GRAY);
const faces = objdetect.detectMultiScale(gray);
```

## 开发工具

### 1. 代码生成器
```bash
# 生成模块骨架
npm run generate:module -- --name=imgproc --agent=B

# 生成函数模板
npm run generate:function -- --module=imgproc --function=GaussianBlur
```

### 2. 测试工具
```bash
# 运行特定模块测试
npm run test:module -- --module=core

# 运行性能测试
npm run test:performance -- --module=imgproc

# 运行内存测试
npm run test:memory -- --module=all
```

### 3. 文档生成
```bash
# 生成 API 文档
npm run docs:generate

# 生成示例代码
npm run examples:generate -- --module=imgproc
```

## 质量保证

### 1. 代码质量指标
- 测试覆盖率 > 90%
- 代码复杂度 < 10
- 函数长度 < 50 行
- 注释覆盖率 > 80%

### 2. 性能指标
- 内存使用 < 100MB
- 函数调用延迟 < 1ms
- 并发安全性
- 无内存泄漏

### 3. 兼容性要求
- Node.js 18+
- OpenCV 4.12.0
- 跨平台支持 (macOS, Linux, Windows)

## 协作机制

### 1. 沟通渠道
- 使用 GitHub Issues 跟踪任务
- 使用 Pull Request 进行代码审查
- 定期同步会议讨论架构问题

### 2. 冲突解决
- 接口冲突: 通过设计讨论解决
- 代码冲突: 通过代码审查解决
- 依赖冲突: 通过依赖分析解决

### 3. 版本管理
- 使用语义化版本号
- 主版本号: 重大架构变更
- 次版本号: 新功能添加
- 修订版本号: 错误修复

## 总结

这个工作流程确保了多个 AI Agent 能够高效协作开发 OpenCV NAPI 接口，通过标准化的流程、工具和规范保证代码质量和开发效率。
