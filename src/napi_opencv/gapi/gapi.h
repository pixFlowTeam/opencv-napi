#ifndef NAPI_OPENCV_GAPI_H
#define NAPI_OPENCV_GAPI_H

#include <napi.h>

namespace NapiOpenCV {
namespace Gapi {

    // 注册所有GAPI模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== G-API计算图函数 ====================
    Napi::Value GComputation_Create(const Napi::CallbackInfo &info);
    Napi::Value GComputation_Apply(const Napi::CallbackInfo &info);
    Napi::Value GComputation_ApplyWithArgs(const Napi::CallbackInfo &info);
    Napi::Value GComputation_Compile(const Napi::CallbackInfo &info);

    // ==================== G-API操作函数 ====================
    Napi::Value GApiAdd(const Napi::CallbackInfo &info);
    Napi::Value GApiSubtract(const Napi::CallbackInfo &info);
    Napi::Value GApiMultiply(const Napi::CallbackInfo &info);
    Napi::Value GApiDivide(const Napi::CallbackInfo &info);
    Napi::Value GApiResize(const Napi::CallbackInfo &info);
    Napi::Value GApiFilter2D(const Napi::CallbackInfo &info);
    Napi::Value GApiBlur(const Napi::CallbackInfo &info);
    Napi::Value GApiCvtColor(const Napi::CallbackInfo &info);

    // ==================== G-API后端函数 ====================
    Napi::Value GApiCPU(const Napi::CallbackInfo &info);
    Napi::Value GApiOCL(const Napi::CallbackInfo &info);
    Napi::Value GApiIE(const Napi::CallbackInfo &info);

    // ==================== G-API流水线函数 ====================
    Napi::Value GStreamingCompile(const Napi::CallbackInfo &info);
    Napi::Value GStreamingApply(const Napi::CallbackInfo &info);

} // namespace Gapi
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_GAPI_H
