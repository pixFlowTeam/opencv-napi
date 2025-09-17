#!/usr/bin/env node

const { execSync } = require('child_process');
const OpenCVBuildCleaner = require('../buildScript/clean-opencv-build.js');

console.log('🚀 开始发布流程...\n');

// 创建 OpenCV 构建清理器实例
const cleaner = new OpenCVBuildCleaner();

const steps = [
  { name: '运行测试', command: 'npm run test' },
  // { name: '交叉编译', command: 'npm run cross-compile:all' },
  { name: '验证产物', command: 'npm run cross-compile:verify' },
  { name: '清理构建中间产物', command: 'clean-opencv-build' },
  { name: '生成文档', command: 'npm run docs:generate' },
  { name: '暂存文档文件', command: 'git add docs/api/API.md docs/guides/EXAMPLES.md docs/guides/FORMATS.md' },
];

async function runReleaseSteps() {
  try {
    for (const step of steps) {
      console.log(`📦 ${step.name}...`);
      
      if (step.command === 'clean-opencv-build') {
        // 特殊处理：运行 OpenCV 构建清理
        await cleaner.clean();
      } else {
        // 普通命令执行
        execSync(step.command, { stdio: 'inherit' });
      }
      
      console.log(`✅ ${step.name} 完成\n`);
    }
  } catch (error) {
    throw error;
  }
}

// 执行发布流程
runReleaseSteps()
  .then(() => {
    console.log('🎉 所有步骤完成！');
  })
  .catch(error => {
    console.error(`❌ 步骤失败: ${error.message}`);
    process.exit(1);
  });
