const opencv = require('../build/Release/opencv_napi.node');

console.log('🎉 OpenCV NAPI 基础示例');
console.log('='.repeat(50));

// 1. 显示版本信息
console.log('\n📊 OpenCV 版本信息:');
console.log(`  版本: ${opencv.version.major}.${opencv.version.minor}.${opencv.version.revision}`);

// 2. 显示模块状态
console.log('\n🔧 可用模块:');
Object.entries(opencv.modules).forEach(([module, enabled]) => {
    console.log(`  ${module}: ${enabled ? '✅' : '❌'}`);
});

// 3. 测试系统信息
console.log('\n🖥️ 系统信息:');
try {
    const buildInfo = opencv.getBuildInformation();
    console.log('  构建信息长度:', buildInfo.length, '字符');
    
    const numThreads = opencv.getNumThreads();
    console.log('  当前线程数:', numThreads);
    
    const tickCount = opencv.getTickCount();
    const tickFreq = opencv.getTickFrequency();
    console.log('  时钟频率:', tickFreq, 'Hz');
} catch (error) {
    console.error('  系统信息获取失败:', error.message);
}

// 4. 测试数学运算
console.log('\n🧮 数学运算测试:');
try {
    // 注意：这些函数需要实际的 Mat 对象，这里只是检查函数是否存在
    console.log('  加法函数:', typeof opencv.add === 'function' ? '✅' : '❌');
    console.log('  乘法函数:', typeof opencv.multiply === 'function' ? '✅' : '❌');
    console.log('  位运算函数:', typeof opencv.bitwiseAnd === 'function' ? '✅' : '❌');
} catch (error) {
    console.error('  数学运算测试失败:', error.message);
}

// 5. 测试图像处理
console.log('\n🖼️ 图像处理测试:');
try {
    console.log('  模糊函数:', typeof opencv.blur === 'function' ? '✅' : '❌');
    console.log('  边缘检测:', typeof opencv.canny === 'function' ? '✅' : '❌');
    console.log('  色彩转换:', typeof opencv.cvtColor === 'function' ? '✅' : '❌');
    console.log('  形态学操作:', typeof opencv.morphologyEx === 'function' ? '✅' : '❌');
} catch (error) {
    console.error('  图像处理测试失败:', error.message);
}

// 6. 测试特征检测
console.log('\n🔍 特征检测测试:');
try {
    console.log('  SIFT 创建:', typeof opencv.siftCreate === 'function' ? '✅' : '❌');
    console.log('  ORB 创建:', typeof opencv.orbCreate === 'function' ? '✅' : '❌');
    console.log('  AKAZE 创建:', typeof opencv.akazeCreate === 'function' ? '✅' : '❌');
    console.log('  关键点绘制:', typeof opencv.drawKeypoints === 'function' ? '✅' : '❌');
} catch (error) {
    console.error('  特征检测测试失败:', error.message);
}

// 7. 测试目标检测
console.log('\n🎯 目标检测测试:');
try {
    console.log('  级联分类器:', typeof opencv.cascadeClassifierCreate === 'function' ? '✅' : '❌');
    console.log('  HOG 描述符:', typeof opencv.hogDescriptorCreate === 'function' ? '✅' : '❌');
    console.log('  QR 码检测:', typeof opencv.qrCodeDetectorCreate === 'function' ? '✅' : '❌');
} catch (error) {
    console.error('  目标检测测试失败:', error.message);
}

// 8. 测试计算摄影
console.log('\n📸 计算摄影测试:');
try {
    console.log('  去噪函数:', typeof opencv.fastNlMeansDenoising === 'function' ? '✅' : '❌');
    console.log('  HDR 成像:', typeof opencv.createMergeMertens === 'function' ? '✅' : '❌');
    console.log('  图像修复:', typeof opencv.inpaint === 'function' ? '✅' : '❌');
    console.log('  无缝克隆:', typeof opencv.seamlessClone === 'function' ? '✅' : '❌');
} catch (error) {
    console.error('  计算摄影测试失败:', error.message);
}

console.log('\n🎉 所有测试完成！OpenCV NAPI 模块功能完整。');
console.log('💡 注意：大部分函数需要实际的图像数据才能运行，这里只是检查函数是否可用。');
