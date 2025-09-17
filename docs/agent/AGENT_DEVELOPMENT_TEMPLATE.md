# Agent 开发模板

**重要说明：本项目所有 Agent 协作相关文档和代码注释必须使用中文。**

## Agent 身份信息

- **Agent 标识**: Agent-{标识}-{模块名}
- **中文名称**: {模块名}专家
- **负责模块**: {模块名}
- **专业领域**: {具体领域描述}

## 开发任务清单

### 阶段 1: 环境准备
- [ ] 克隆项目仓库
- [ ] 安装依赖: `npm install`
- [ ] 构建项目: `npm run build`
- [ ] 运行测试: `npm test`
- [ ] 阅读 [Agent 协作协议](AGENT_PROTOCOL.md)

### 阶段 2: 模块开发
- [ ] 创建模块头文件: `src/napi_modules/{模块名}/{模块名}_module.h`
- [ ] 创建模块实现: `src/napi_modules/{模块名}/{模块名}_module.cpp`
- [ ] 实现 `ModuleInterface` 接口
- [ ] 使用 `REGISTER_NAPI_MODULE` 宏注册模块
- [ ] 实现所有导出的函数

### 阶段 3: 测试开发
- [ ] 创建测试文件: `test/{模块名}.test.ts`
- [ ] 编写单元测试
- [ ] 编写集成测试
- [ ] 测试边界情况
- [ ] 确保测试覆盖率 > 90%

### 阶段 4: 文档更新
- [ ] 更新 API 文档
- [ ] 添加使用示例
- [ ] 更新 README
- [ ] 记录变更日志

## 代码规范

### 1. 文件头注释
```cpp
/**
 * @file {模块名}_module.h
 * @brief {模块名}模块实现
 * 
 * 实现 OpenCV {模块名}模块的功能，包括：
 * - {功能1}
 * - {功能2}
 * - {功能3}
 * 
 * 由 Agent-{标识}-{模块名} ({中文名称}) 负责实现
 * 重要说明：本项目所有 Agent 协作相关文档和代码注释必须使用中文。
 */
```

### 2. 类注释
```cpp
/**
 * @brief {模块名}模块实现
 * 
 * 实现 OpenCV {模块名}模块的基本功能，包括：
 * - {功能1}
 * - {功能2}
 * - {功能3}
 * 
 * 由 Agent-{标识}-{模块名} ({中文名称}) 负责实现
 * 重要说明：本项目所有 Agent 协作相关文档和代码注释必须使用中文。
 */
class {模块名}Module : public NapiCore::ModuleInterface
```

### 3. 函数注释
```cpp
/**
 * @brief 注册模块函数到 NAPI exports
 * @param env NAPI 环境
 * @param exports 导出对象
 * 
 * 由 Agent-{标识}-{模块名} ({中文名称}) 实现
 * 负责 {模块名} 模块的所有函数注册
 */
void RegisterFunctions(Napi::Env env, Napi::Object exports) override;
```

### 4. 提交信息格式
```
feat({模块名}): 添加新功能描述

- 具体变更1
- 具体变更2

由 Agent-{标识}-{模块名} ({中文名称}) 实现
```

### 5. 分支命名
```
feature/agent-{标识}-{模块名}-{功能描述}
fix/agent-{标识}-{模块名}-{问题描述}
docs/agent-{标识}-{文档类型}
```

## 质量检查清单

### 代码质量
- [ ] 所有注释使用中文
- [ ] 函数长度 < 50 行
- [ ] 代码复杂度 < 10
- [ ] 无内存泄漏
- [ ] 错误处理完善

### 测试质量
- [ ] 测试覆盖率 > 90%
- [ ] 单元测试完整
- [ ] 集成测试通过
- [ ] 边界情况测试
- [ ] 性能测试通过

### 文档质量
- [ ] API 文档完整
- [ ] 示例代码正确
- [ ] 变更日志更新
- [ ] 中文描述清晰

## 协作规范

### 1. 代码审查
- 使用中文进行代码审查
- 重点检查接口一致性
- 确保错误处理完善
- 验证性能要求

### 2. 问题报告
- 使用中文描述问题
- 包含 Agent 标识信息
- 提供详细复现步骤
- 附上相关日志

### 3. 进度同步
- 定期汇报开发进度
- 说明遇到的问题
- 记录解决方案
- 更新任务状态

## 常用命令

### 构建和测试
```bash
# 构建项目
npm run build

# 运行测试
npm test

# 运行特定模块测试
npm run test:module -- --module={模块名}

# 性能测试
npm run test:performance -- --module={模块名}
```

### 代码质量检查
```bash
# 代码风格检查
npm run lint

# 类型检查
npm run type-check

# 内存泄漏检查
npm run test:memory -- --module={模块名}
```

### 文档生成
```bash
# 生成 API 文档
npm run docs:generate

# 生成示例代码
npm run examples:generate -- --module={模块名}
```

## 总结

遵循本模板可以确保 Agent 开发过程标准化和高质量。记住始终使用中文进行文档编写和代码注释，这是项目的重要规范。
