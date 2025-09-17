#ifndef NAPI_OPENCV_FLANN_H
#define NAPI_OPENCV_FLANN_H

#include <napi.h>

namespace NapiOpenCV {
namespace Flann {

    // 注册所有FLANN模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== FLANN索引函数 ====================
    Napi::Value Index_Create(const Napi::CallbackInfo &info);
    Napi::Value Index_Build(const Napi::CallbackInfo &info);
    Napi::Value Index_KnnSearch(const Napi::CallbackInfo &info);
    Napi::Value Index_RadiusSearch(const Napi::CallbackInfo &info);
    Napi::Value Index_Save(const Napi::CallbackInfo &info);
    Napi::Value Index_Load(const Napi::CallbackInfo &info);
    Napi::Value Index_Release(const Napi::CallbackInfo &info);
    Napi::Value Index_GetDistance(const Napi::CallbackInfo &info);
    Napi::Value Index_GetAlgorithm(const Napi::CallbackInfo &info);

    // ==================== 搜索参数函数 ====================
    Napi::Value SearchParams_Create(const Napi::CallbackInfo &info);
    Napi::Value SearchParams_SetChecks(const Napi::CallbackInfo &info);
    Napi::Value SearchParams_SetEps(const Napi::CallbackInfo &info);
    Napi::Value SearchParams_SetSorted(const Napi::CallbackInfo &info);

    // ==================== 索引参数函数 ====================
    Napi::Value LinearIndexParams_Create(const Napi::CallbackInfo &info);
    Napi::Value KDTreeIndexParams_Create(const Napi::CallbackInfo &info);
    Napi::Value KMeansIndexParams_Create(const Napi::CallbackInfo &info);
    Napi::Value CompositeIndexParams_Create(const Napi::CallbackInfo &info);
    Napi::Value AutotunedIndexParams_Create(const Napi::CallbackInfo &info);
    Napi::Value SavedIndexParams_Create(const Napi::CallbackInfo &info);

} // namespace Flann
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_FLANN_H
