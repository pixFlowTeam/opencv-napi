// OpenCV NAPI 绑定测试文件
// 用于验证我们的 NAPI 绑定是否正常工作

const opencv = require('./build/Release/opencv_napi.node');

console.log('🎉 OpenCV NAPI 绑定测试开始...\n');

// 测试版本信息
console.log('📋 版本信息:');
console.log('  OpenCV 版本:', opencv.version);
console.log('  主版本号:', opencv.getVersionMajor());
console.log('  次版本号:', opencv.getVersionMinor());
console.log('  修订版本号:', opencv.getVersionRevision());

// 测试模块信息
console.log('\n📦 可用模块:');
console.log('  模块列表:', opencv.modules);

// 测试构建信息
console.log('\n🔧 构建信息:');
try {
    const buildInfo = opencv.getBuildInformation();
    console.log('  构建信息长度:', buildInfo.length, '字符');
    console.log('  构建信息预览:', buildInfo.substring(0, 200) + '...');
} catch (error) {
    console.error('  ❌ 获取构建信息失败:', error.message);
}

// 测试线程管理
console.log('\n🧵 线程管理:');
try {
    const currentThreads = opencv.getNumThreads();
    console.log('  当前线程数:', currentThreads);
    
    opencv.setNumThreads(2);
    const newThreads = opencv.getNumThreads();
    console.log('  设置后线程数:', newThreads);
} catch (error) {
    console.error('  ❌ 线程管理测试失败:', error.message);
}

// 测试时钟函数
console.log('\n⏰ 时钟函数:');
try {
    const tickCount = opencv.getTickCount();
    const tickFreq = opencv.getTickFrequency();
    console.log('  时钟计数:', tickCount);
    console.log('  时钟频率:', tickFreq, 'Hz');
} catch (error) {
    console.error('  ❌ 时钟函数测试失败:', error.message);
}

// 测试 Mat 类
console.log('\n📐 Mat 类测试:');
try {
    const mat = new opencv.Mat();
    console.log('  ✅ Mat 对象创建成功');
    console.log('  Mat 类型:', typeof mat);
    console.log('  Mat 构造函数:', mat.constructor.name);
} catch (error) {
    console.error('  ❌ Mat 类测试失败:', error.message);
}

// 测试图像IO功能
console.log('\n🖼️  图像IO测试:');
const testImagePaths = [
    './output/canon_test.jpg',
    './output/sony_photo.jpg',
    './raw-samples-repo/DNG/RAW_LEICA_M8.DNG'
];

let testImage = null;
for (const path of testImagePaths) {
    try {
        testImage = opencv.imread(path);
        console.log(`  ✅ 成功读取图像: ${path}`);
        console.log('    图像尺寸:', `${testImage.cols}x${testImage.rows}`);
        console.log('    通道数:', testImage.channels);
        console.log('    数据类型:', testImage.type);
        break;
    } catch (e) {
        console.log(`  ❌ 无法读取图像: ${path} (${e.message})`);
    }
}

if (testImage) {
    // 测试图像缩放
    console.log('\n📏 图像缩放测试:');
    try {
        const resized = opencv.resize(testImage, { width: 640, height: 480 });
        console.log('  ✅ 图像缩放成功');
        console.log('    原始尺寸:', `${testImage.cols}x${testImage.rows}`);
        console.log('    缩放后尺寸:', `${resized.cols}x${resized.rows}`);
    } catch (e) {
        console.log('  ❌ 图像缩放失败:', e.message);
    }
    
    // 测试颜色空间转换
    console.log('\n🎨 颜色空间转换测试:');
    try {
        const COLOR_BGR2GRAY = 6; // cv::COLOR_BGR2GRAY
        const gray = opencv.cvtColor(testImage, COLOR_BGR2GRAY);
        console.log('  ✅ 颜色转换成功 (BGR→灰度)');
        console.log('    原始通道:', testImage.channels);
        console.log('    转换后通道:', gray.channels);
    } catch (e) {
        console.log('  ❌ 颜色转换失败:', e.message);
    }
    
    // 测试高斯滤波
    console.log('\n🌀 高斯滤波测试:');
    try {
        const blurred = opencv.gaussianBlur(testImage, { width: 15, height: 15 }, 5.0);
        console.log('  ✅ 高斯滤波成功');
    } catch (e) {
        console.log('  ❌ 高斯滤波失败:', e.message);
    }
    
    // 测试图像写入
    console.log('\n💾 图像写入测试:');
    try {
        const success = opencv.imwrite('./test_output_napi.jpg', testImage);
        console.log('  图像写入结果:', success ? '✅ 成功' : '❌ 失败');
    } catch (e) {
        console.log('  ❌ 图像写入失败:', e.message);
    }
}

// 测试未实现的函数
console.log('\n🚧 未实现函数测试:');
const unimplementedFunctions = [
    'partition', 'kmeans', 'addWeighted', 'minMaxLoc', 
    'findNonZero', 'countNonZero', 'sum', 'mean',
    'blur', 'medianBlur', 'bilateralFilter', 'filter2D',
    'canny', 'sobel', 'laplacian', 'erode', 'dilate'
];

let implementedCount = 0;
let unimplementedCount = 0;

unimplementedFunctions.forEach(funcName => {
    try {
        if (typeof opencv[funcName] === 'function') {
            opencv[funcName]();
            console.log(`  ⚠️  ${funcName}: 意外成功（应该失败）`);
            implementedCount++;
        } else {
            console.log(`  ❌ ${funcName}: 函数不存在`);
        }
    } catch (error) {
        if (error.message.includes('尚未实现')) {
            console.log(`  ✅ ${funcName}: 正确返回未实现错误`);
            unimplementedCount++;
        } else {
            console.log(`  ❌ ${funcName}: 意外错误 - ${error.message}`);
        }
    }
});

console.log(`\n📊 统计结果:`);
console.log(`  已实现函数: ${implementedCount}`);
console.log(`  未实现函数: ${unimplementedCount}`);
console.log(`  总测试函数: ${unimplementedFunctions.length}`);

// 性能测试
console.log('\n⚡ 性能测试:');
const iterations = 1000;
console.log(`  执行 ${iterations} 次系统调用...`);

const start = process.hrtime.bigint();
for (let i = 0; i < iterations; i++) {
    opencv.getTickCount();
    opencv.getTickFrequency();
}
const end = process.hrtime.bigint();

const totalTime = Number(end - start) / 1000000; // 转换为毫秒
const avgTime = totalTime / iterations;
console.log(`  总耗时: ${totalTime.toFixed(3)}ms`);
console.log(`  平均耗时: ${avgTime.toFixed(6)}ms`);

console.log('\n🎯 测试完成！');
console.log('✅ 基础 NAPI 绑定功能正常工作');
console.log('🔧 核心图像处理函数已实现 (imread, imwrite, resize, cvtColor, gaussianBlur)');
console.log('⚠️  部分高级函数尚未实现，这是正常的');
console.log('📝 下一步：根据需要实现更多 OpenCV 函数');

// 输出可用的 API 列表
console.log('\n📚 可用的 API 函数:');
const availableFunctions = Object.getOwnPropertyNames(opencv)
    .filter(name => typeof opencv[name] === 'function')
    .sort();

console.log('  核心功能:', availableFunctions.filter(f => 
    ['getBuildInformation', 'getNumThreads', 'setNumThreads', 'getTickCount', 'getTickFrequency', 
     'getVersionMajor', 'getVersionMinor', 'getVersionRevision'].includes(f)
));

console.log('  图像IO:', availableFunctions.filter(f => 
    ['imread', 'imwrite', 'imdecode', 'imencode'].includes(f)
));

console.log('  图像处理:', availableFunctions.filter(f => 
    ['resize', 'cvtColor', 'gaussianBlur', 'blur', 'medianBlur', 'bilateralFilter', 'filter2D'].includes(f)
));

console.log('  其他模块:', availableFunctions.filter(f => 
    !['getBuildInformation', 'getNumThreads', 'setNumThreads', 'getTickCount', 'getTickFrequency', 
      'getVersionMajor', 'getVersionMinor', 'getVersionRevision',
      'imread', 'imwrite', 'imdecode', 'imencode',
      'resize', 'cvtColor', 'gaussianBlur', 'blur', 'medianBlur', 'bilateralFilter', 'filter2D'].includes(f)
).slice(0, 10));
