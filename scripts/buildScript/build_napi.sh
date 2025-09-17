#!/bin/bash

# OpenCV NAPI 绑定构建脚本
# 用于编译和测试 OpenCV 的 Node.js NAPI 绑定

set -e  # 遇到错误时退出

echo "🚀 OpenCV NAPI 绑定构建脚本"
echo "================================"

# 检查 Node.js 和 npm
echo "📋 检查环境..."
node --version
npm --version

# 检查是否安装了 node-addon-api
if ! npm list node-addon-api > /dev/null 2>&1; then
    echo "📦 安装 node-addon-api..."
    npm install node-addon-api
else
    echo "✅ node-addon-api 已安装"
fi

# 检查是否安装了 node-gyp
if ! command -v node-gyp &> /dev/null; then
    echo "📦 安装 node-gyp..."
    npm install -g node-gyp
else
    echo "✅ node-gyp 已安装"
fi

# 检查 OpenCV 构建是否存在
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
echo "⚙️  配置构建..."
node-gyp configure --binding=binding_napi.gyp

# 编译
echo "🔨 编译 NAPI 绑定..."
node-gyp build --binding=binding_napi.gyp

# 检查构建结果
NAPI_BINARY="build/Release/opencv_napi.node"
if [ -f "$NAPI_BINARY" ]; then
    echo "✅ NAPI 绑定编译成功: $NAPI_BINARY"
    
    # 显示文件信息
    echo "📊 文件信息:"
    ls -lh "$NAPI_BINARY"
    file "$NAPI_BINARY"
    
    # 运行基础测试
    echo ""
    echo "🧪 运行基础测试..."
    echo "================================"
    
    if [ -f "test_napi_opencv.js" ]; then
        echo "运行主测试文件..."
        node test_napi_opencv.js
    else
        echo "⚠️  测试文件 test_napi_opencv.js 未找到"
    fi
    
    echo ""
    
    if [ -f "test_mat_napi.js" ]; then
        echo "运行 Mat 类测试..."
        node test_mat_napi.js
    else
        echo "⚠️  测试文件 test_mat_napi.js 未找到"
    fi
    
    echo ""
    echo "🎉 构建和测试完成！"
    echo "📁 NAPI 绑定文件: $NAPI_BINARY"
    echo "🔍 可以使用以下方式导入:"
    echo "   const opencv = require('./build/Release/opencv_napi.node');"
    
else
    echo "❌ NAPI 绑定编译失败"
    echo "请检查编译错误信息"
    exit 1
fi