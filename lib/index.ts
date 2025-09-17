import { createRequire } from "module";

const require = createRequire(import.meta.url);

let opencvAddon: any;

try {
  opencvAddon = require("../build/Release/opencv_napi");
} catch (err) {
  try {
    opencvAddon = require("../build/Debug/opencv_napi");
  } catch (err2) {
    throw new Error('OpenCV 插件未构建。请先运行 "npm run build"。');
  }
}

// OpenCV 模块导出
export default opencvAddon;
