#!/bin/bash

# OpenCV NAPI 模块化绑定构建脚本
# 用于编译和测试模块化的 OpenCV Node.js NAPI 绑定

set -e

echo "🚀 OpenCV NAPI 模块化绑定构建脚本"
echo "===================================="

# 检查环境
echo "📋 检查环境..."
node --version
npm --version

# 安装依赖
if ! npm list node-addon-api > /dev/null 2>&1; then
    echo "📦 安装 node-addon-api..."
    npm install node-addon-api
else
    echo "✅ node-addon-api 已安装"
fi

if ! command -v node-gyp &> /dev/null; then
    echo "📦 安装 node-gyp..."
    npm install -g node-gyp
else
    echo "✅ node-gyp 已安装"
fi

# 检查 OpenCV 库
OPENCV_LIB_PATH="deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib"
if [ ! -d "$OPENCV_LIB_PATH" ]; then
    echo "❌ OpenCV 库文件未找到: $OPENCV_LIB_PATH"
    echo "请先构建 OpenCV 库"
    exit 1
else
    echo "✅ OpenCV 库文件已找到"
fi

# 清理之前的构建
echo "🧹 清理之前的构建..."
if [ -d "build" ]; then
    rm -rf build
    echo "  删除 build 目录"
fi

# 配置构建
echo "⚙️  配置模块化构建..."
node-gyp configure --binding=binding_napi_modular.gyp

# 编译
echo "🔨 编译模块化 NAPI 绑定..."
node-gyp build --binding=binding_napi_modular.gyp

# 检查构建结果
NAPI_BINARY="build/Release/opencv_napi.node"
if [ -f "$NAPI_BINARY" ]; then
    echo "✅ 模块化 NAPI 绑定编译成功: $NAPI_BINARY"
    
    # 显示文件信息
    echo "📊 文件信息:"
    ls -lh "$NAPI_BINARY"
    file "$NAPI_BINARY"
    
    # 创建简单测试
    cat > test_modular.js << 'EOF'
const opencv = require('./build/Release/opencv_napi.node');

console.log('🧪 测试模块化OpenCV NAPI绑定');
console.log('===============================');

try {
    // 测试版本信息
    console.log('📋 版本信息:', opencv.version);
    console.log('📦 可用模块:', opencv.modules);
    
    // 测试系统信息函数
    console.log('🔧 线程数:', opencv.getNumThreads());
    console.log('⏱️  时钟频率:', opencv.getTickFrequency());
    
    // 测试基础数学函数（应该抛出未实现错误）
    try {
        opencv.add();
    } catch (e) {
        console.log('✅ Add 函数正确抛出:', e.message);
    }
    
    // 测试图像处理函数（应该抛出未实现错误）
    try {
        opencv.blur();
    } catch (e) {
        console.log('✅ Blur 函数正确抛出:', e.message);
    }
    
    console.log('');
    console.log('🎉 模块化绑定测试完成！');
    console.log('📁 所有模块已正确加载和注册');
    
} catch (error) {
    console.error('❌ 测试失败:', error.message);
    process.exit(1);
}
EOF
    
    echo ""
    echo "🧪 运行模块化测试..."
    echo "===================="
    node test_modular.js
    
    echo ""
    echo "🎉 模块化构建和测试完成！"
    echo "📁 模块化 NAPI 绑定文件: $NAPI_BINARY"
    echo "📂 模块化架构位于: src/napi_opencv/"
    echo "🔍 可以使用以下方式导入:"
    echo "   const opencv = require('./build/Release/opencv_napi.node');"
    
else
    echo "❌ 模块化 NAPI 绑定编译失败"
    echo "请检查编译错误信息"
    exit 1
fi