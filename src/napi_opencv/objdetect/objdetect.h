#ifndef NAPI_OPENCV_OBJDETECT_H
#define NAPI_OPENCV_OBJDETECT_H

#include <napi.h>

namespace NapiOpenCV {
namespace Objdetect {

    // 注册所有OBJDETECT模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== 级联分类器函数 ====================
    Napi::Value CascadeClassifier_Create(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_Load(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_DetectMultiScale(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_DetectMultiScale2(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_DetectMultiScale3(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_Empty(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_GetFeatureType(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_GetOriginalWindowSize(const Napi::CallbackInfo &info);
    Napi::Value CascadeClassifier_IsOldFormatCascade(const Napi::CallbackInfo &info);

    // ==================== HOG描述符函数 ====================
    Napi::Value HOGDescriptor_Create(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_SetSVMDetector(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_GetDefaultPeopleDetector(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_GetDaimlerPeopleDetector(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_DetectMultiScale(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_Detect(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_Compute(const Napi::CallbackInfo &info);
    Napi::Value HOGDescriptor_ComputeGradient(const Napi::CallbackInfo &info);

    // ==================== QR码检测函数 ====================
    Napi::Value QRCodeDetector_Create(const Napi::CallbackInfo &info);
    Napi::Value QRCodeDetector_Detect(const Napi::CallbackInfo &info);
    Napi::Value QRCodeDetector_Decode(const Napi::CallbackInfo &info);
    Napi::Value QRCodeDetector_DetectAndDecode(const Napi::CallbackInfo &info);
    Napi::Value QRCodeDetector_SetEpsX(const Napi::CallbackInfo &info);
    Napi::Value QRCodeDetector_SetEpsY(const Napi::CallbackInfo &info);

    // ==================== 分组矩形函数 ====================
    Napi::Value GroupRectangles(const Napi::CallbackInfo &info);
    Napi::Value GroupRectangles_Meanshift(const Napi::CallbackInfo &info);

} // namespace Objdetect
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_OBJDETECT_H
