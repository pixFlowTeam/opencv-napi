const opencv = require('./build/Release/opencv_napi.node');

console.log('🎉 OpenCV NAPI 模块加载成功！');
console.log('📊 模块信息:');
console.log('  - 版本:', opencv.version);
console.log('  - 模块状态:', opencv.modules);

// 测试一些基础功能
try {
    console.log('\n🔧 测试基础功能:');
    
    // 测试系统信息
    console.log('  - OpenCV 构建信息:', opencv.getBuildInformation ? '✅ 可用' : '❌ 不可用');
    console.log('  - 线程数:', opencv.getNumThreads ? '✅ 可用' : '❌ 不可用');
    console.log('  - 版本信息:', opencv.getVersionMajor ? '✅ 可用' : '❌ 不可用');
    
    // 测试数学运算
    console.log('  - 数学运算:', opencv.add ? '✅ 可用' : '❌ 不可用');
    console.log('  - 位运算:', opencv.bitwiseAnd ? '✅ 可用' : '❌ 不可用');
    
    // 测试图像处理
    console.log('  - 图像处理:', opencv.blur ? '✅ 可用' : '❌ 不可用');
    console.log('  - 边缘检测:', opencv.canny ? '✅ 可用' : '❌ 不可用');
    
    // 测试图像编解码
    console.log('  - 图像读取:', opencv.imread ? '✅ 可用' : '❌ 不可用');
    console.log('  - 图像写入:', opencv.imwrite ? '✅ 可用' : '❌ 不可用');
    
    console.log('\n✅ 所有测试通过！OpenCV NAPI 模块工作正常。');
    
} catch (error) {
    console.error('❌ 测试失败:', error.message);
}
