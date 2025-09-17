#ifndef NAPI_OPENCV_IMGCODECS_H
#define NAPI_OPENCV_IMGCODECS_H

#include <napi.h>

namespace NapiOpenCV {
namespace ImgCodecs {

    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== 基础图像I/O函数 ====================
    Napi::Value Imread(const Napi::CallbackInfo &info);
    Napi::Value Imwrite(const Napi::CallbackInfo &info);
    Napi::Value Imdecode(const Napi::CallbackInfo &info);
    Napi::Value Imencode(const Napi::CallbackInfo &info);
    
    // ==================== 格式支持检测函数 ====================
    Napi::Value HaveImageReader(const Napi::CallbackInfo &info);
    Napi::Value HaveImageWriter(const Napi::CallbackInfo &info);
    
    // ==================== 多页面图像处理 ====================
    Napi::Value ImreadMulti(const Napi::CallbackInfo &info);
    Napi::Value ImcountPages(const Napi::CallbackInfo &info);
    
    // ==================== 图像属性函数 ====================
    Napi::Value ImwriteMulti(const Napi::CallbackInfo &info);

} // namespace ImgCodecs
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_IMGCODECS_H