#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

class CrossCompileStatusUpdater {
  constructor() {
    this.opencvSourceDir = path.join(__dirname, '../deps/OpenCV-Source/opencv-4.12.0');
    this.buildDir = path.join(this.opencvSourceDir, 'build');
    this.docsDir = path.join(__dirname, '../docs');
  }

  async updateStatus() {
    console.log('🔄 更新交叉编译状态...\n');

    // 运行验证脚本获取当前状态
    const verifier = require('./verify-cross-compile.js');
    const verifierInstance = new verifier();
    
    // 获取平台状态
    const platforms = this.getPlatformStatus();
    
    // 更新状态文档
    await this.updateStatusDocument(platforms);
    
    // 更新 README
    await this.updateReadme(platforms);
    
    console.log('✅ 状态更新完成！');
  }

  getPlatformStatus() {
    const platforms = {};
    const platformDirs = ['darwin-arm64', 'darwin-x64', 'linux-arm64', 'linux-x64', 'win32'];
    
    for (const platform of platformDirs) {
      const platformDir = path.join(this.buildDir, platform);
      const libPath = platform.startsWith('win32') 
        ? path.join(platformDir, 'bin')
        : path.join(platformDir, 'lib');
      
      if (fs.existsSync(libPath)) {
        const libFiles = fs.readdirSync(libPath)
          .filter(file => file.endsWith('.so') || file.endsWith('.a') || file.endsWith('.dll') || file.endsWith('.dylib'));
        
        let totalSize = 0;
        for (const libFile of libFiles) {
          const stats = fs.statSync(path.join(libPath, libFile));
          totalSize += stats.size;
        }
        
        platforms[platform] = {
          status: 'success',
          libCount: libFiles.length,
          totalSize: (totalSize / 1024 / 1024).toFixed(2),
          lastBuild: this.getLastBuildTime(platformDir)
        };
      } else {
        platforms[platform] = {
          status: 'not_built',
          libCount: 0,
          totalSize: '0.00',
          lastBuild: 'N/A'
        };
      }
    }
    
    return platforms;
  }

  getLastBuildTime(platformDir) {
    try {
      const stats = fs.statSync(platformDir);
      return stats.mtime.toISOString().split('T')[0];
    } catch (error) {
      return 'N/A';
    }
  }

  async updateStatusDocument(platforms) {
    const statusDocPath = path.join(this.docsDir, 'OPENCV_CROSS_COMPILE_STATUS.md');
    
    if (!fs.existsSync(statusDocPath)) {
      console.log('❌ 状态文档不存在，请先创建');
      return;
    }
    
    let content = fs.readFileSync(statusDocPath, 'utf8');
    
    // 更新状态表格
    const statusTable = this.generateStatusTable(platforms);
    content = content.replace(
      /\| 平台 \| 架构 \| 状态 \| 库文件数 \| 总大小 \| 最后构建时间 \|[\s\S]*?\|/g,
      statusTable
    );
    
    // 更新构建输出结构中的文件大小
    content = this.updateFileSizes(content, platforms);
    
    fs.writeFileSync(statusDocPath, content);
    console.log('✅ 更新了 OpenCV 交叉编译状态文档');
  }

  generateStatusTable(platforms) {
    const platformNames = {
      'darwin-arm64': 'macOS ARM64',
      'darwin-x64': 'macOS x64', 
      'linux-arm64': 'Linux ARM64',
      'linux-x64': 'Linux x64',
      'win32': 'Windows x64'
    };
    
    const archNames = {
      'darwin-arm64': 'ARM64',
      'darwin-x64': 'x64',
      'linux-arm64': 'ARM64', 
      'linux-x64': 'x64',
      'win32': 'x64'
    };
    
    let table = '| 平台 | 架构 | 状态 | 库文件数 | 总大小 | 最后构建时间 |\n';
    table += '|------|------|------|----------|--------|-------------|\n';
    
    for (const [platform, info] of Object.entries(platforms)) {
      const status = info.status === 'success' ? '✅ 成功' : '❌ 未构建';
      const platformName = platformNames[platform] || platform;
      const archName = archNames[platform] || 'Unknown';
      
      table += `| ${platformName} | ${archName} | ${status} | ${info.libCount} | ${info.totalSize} MB | ${info.lastBuild} |\n`;
    }
    
    return table;
  }

  updateFileSizes(content, platforms) {
    // 这里可以根据实际需要更新文件大小信息
    // 目前保持原有内容不变
    return content;
  }

  async updateReadme(platforms) {
    const readmePath = path.join(__dirname, '../README.md');
    let content = fs.readFileSync(readmePath, 'utf8');
    
    // 更新 OpenCV 交叉编译状态部分
    const opencvStatus = this.generateOpenCVStatus(platforms);
    content = content.replace(
      /\*\*OpenCV 交叉编译状态：\*\*[\s\S]*?📊 \[查看详细的 OpenCV 交叉编译状态报告\]/g,
      opencvStatus
    );
    
    fs.writeFileSync(readmePath, content);
    console.log('✅ 更新了 README.md');
  }

  generateOpenCVStatus(platforms) {
    const platformNames = {
      'darwin-arm64': 'macOS ARM64',
      'darwin-x64': 'macOS x64',
      'linux-arm64': 'Linux ARM64', 
      'linux-x64': 'Linux x64',
      'win32': 'Windows x64'
    };
    
    let status = '**OpenCV 交叉编译状态：**\n';
    
    for (const [platform, info] of Object.entries(platforms)) {
      const platformName = platformNames[platform] || platform;
      const statusIcon = info.status === 'success' ? '✅' : '❌';
      const sizeInfo = info.status === 'success' ? ` (${info.totalSize} MB)` : '';
      
      status += `- ${statusIcon} ${platformName}${sizeInfo}\n`;
    }
    
    status += '\n📊 [查看详细的 OpenCV 交叉编译状态报告](docs/OPENCV_CROSS_COMPILE_STATUS.md)';
    
    return status;
  }
}

// 主程序
if (require.main === module) {
  const updater = new CrossCompileStatusUpdater();
  updater.updateStatus().catch(error => {
    console.error('❌ 更新状态失败:', error.message);
    process.exit(1);
  });
}

module.exports = CrossCompileStatusUpdater;
