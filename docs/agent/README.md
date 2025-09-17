# Agent 协作文档

**重要说明：本项目所有 Agent 协作相关文档和代码注释必须使用中文。**

## 文档结构

### 核心协议
- [Agent 协作协议](AGENT_PROTOCOL.md) - Agent 协作的基本规范和语言要求
- [Agent 开发模板](AGENT_DEVELOPMENT_TEMPLATE.md) - 标准化的开发模板和检查清单

### 架构设计
- [NAPI 多 Agent 架构设计](NAPI_AGENT_ARCHITECTURE.md) - 整体架构设计和技术规范
- [Agent 工作流程指南](AGENT_WORKFLOW.md) - 详细的开发工作流程
- [Agent 任务分配表](AGENT_TASK_ASSIGNMENT.md) - 具体的任务分配和进度跟踪

## Agent 身份标识

| Agent | 中文名称 | 英文标识 | 负责模块 | 专业领域 |
|-------|----------|----------|----------|----------|
| Agent A | 核心模块专家 | Agent-A-Core | core | Mat 操作、基础数学运算、数组操作 |
| Agent B | 图像处理专家 | Agent-B-ImgProc | imgproc | 图像滤波、几何变换、形态学操作 |
| Agent C | 图像编解码专家 | Agent-C-ImgCodecs | imgcodecs | 图像读取、保存、格式转换 |
| Agent D | 目标检测专家 | Agent-D-ObjDetect | objdetect | 人脸检测、物体检测、级联分类器 |
| Agent E | 特征检测专家 | Agent-E-Features2D | features2d | 特征点检测、描述符、匹配 |
| Agent F | 计算摄影专家 | Agent-F-Photo | photo | 图像修复、HDR、去噪 |
| Agent G | 相机标定专家 | Agent-G-Calib3D | calib3d | 相机标定、立体视觉、PnP |
| Agent H | 视频处理专家 | Agent-H-VideoIO | videoio | 视频读取、保存、摄像头操作 |
| Agent I | 机器学习专家 | Agent-I-ML | ml | 机器学习算法、分类器、回归 |
| Agent J | G-API 专家 | Agent-J-GAPI | gapi | 图API、流水线处理、GPU加速 |

## 快速开始

### 1. 阅读协议
首先阅读 [Agent 协作协议](AGENT_PROTOCOL.md)，了解基本规范和语言要求。

### 2. 了解架构
阅读 [NAPI 多 Agent 架构设计](NAPI_AGENT_ARCHITECTURE.md)，理解整体技术架构。

### 3. 查看任务
查看 [Agent 任务分配表](AGENT_TASK_ASSIGNMENT.md)，了解自己的具体任务。

### 4. 遵循流程
按照 [Agent 工作流程指南](AGENT_WORKFLOW.md) 进行开发。

## 重要提醒

1. **语言规范**: 所有文档和代码注释必须使用中文
2. **身份标识**: 每个 Agent 都有明确的中文名称和英文标识
3. **协作规范**: 遵循统一的代码提交、分支命名和文档更新规范
4. **质量保证**: 确保代码审查、测试和文档维护都使用中文

## 联系方式

- 项目仓库: https://github.com/your-org/opencv-napi
- 问题跟踪: https://github.com/your-org/opencv-napi/issues
- 文档站点: https://your-org.github.io/opencv-napi
