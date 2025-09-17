#include "objdetect.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Objdetect
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            // 级联分类器函数
            exports.Set("cascadeClassifierCreate", Napi::Function::New(env, CascadeClassifier_Create));
            exports.Set("cascadeClassifierLoad", Napi::Function::New(env, CascadeClassifier_Load));
            exports.Set("cascadeClassifierDetectMultiScale", Napi::Function::New(env, CascadeClassifier_DetectMultiScale));
            exports.Set("cascadeClassifierDetectMultiScale2", Napi::Function::New(env, CascadeClassifier_DetectMultiScale2));
            exports.Set("cascadeClassifierDetectMultiScale3", Napi::Function::New(env, CascadeClassifier_DetectMultiScale3));
            exports.Set("cascadeClassifierEmpty", Napi::Function::New(env, CascadeClassifier_Empty));
            exports.Set("cascadeClassifierGetFeatureType", Napi::Function::New(env, CascadeClassifier_GetFeatureType));
            exports.Set("cascadeClassifierGetOriginalWindowSize", Napi::Function::New(env, CascadeClassifier_GetOriginalWindowSize));
            exports.Set("cascadeClassifierIsOldFormatCascade", Napi::Function::New(env, CascadeClassifier_IsOldFormatCascade));

            // HOG描述符函数
            exports.Set("hogDescriptorCreate", Napi::Function::New(env, HOGDescriptor_Create));
            exports.Set("hogDescriptorSetSVMDetector", Napi::Function::New(env, HOGDescriptor_SetSVMDetector));
            exports.Set("hogDescriptorGetDefaultPeopleDetector", Napi::Function::New(env, HOGDescriptor_GetDefaultPeopleDetector));
            exports.Set("hogDescriptorGetDaimlerPeopleDetector", Napi::Function::New(env, HOGDescriptor_GetDaimlerPeopleDetector));
            exports.Set("hogDescriptorDetectMultiScale", Napi::Function::New(env, HOGDescriptor_DetectMultiScale));
            exports.Set("hogDescriptorDetect", Napi::Function::New(env, HOGDescriptor_Detect));
            exports.Set("hogDescriptorCompute", Napi::Function::New(env, HOGDescriptor_Compute));
            exports.Set("hogDescriptorComputeGradient", Napi::Function::New(env, HOGDescriptor_ComputeGradient));

            // QR码检测函数
            exports.Set("qrCodeDetectorCreate", Napi::Function::New(env, QRCodeDetector_Create));
            exports.Set("qrCodeDetectorDecode", Napi::Function::New(env, QRCodeDetector_Decode));
            exports.Set("qrCodeDetectorDetect", Napi::Function::New(env, QRCodeDetector_Detect));
            exports.Set("qrCodeDetectorDetectAndDecode", Napi::Function::New(env, QRCodeDetector_DetectAndDecode));
            exports.Set("qrCodeDetectorSetEpsX", Napi::Function::New(env, QRCodeDetector_SetEpsX));
            exports.Set("qrCodeDetectorSetEpsY", Napi::Function::New(env, QRCodeDetector_SetEpsY));

            // 其他函数
            exports.Set("groupRectangles", Napi::Function::New(env, GroupRectangles));
            exports.Set("groupRectanglesMeanshift", Napi::Function::New(env, GroupRectangles_Meanshift));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name)                                                            \
    Napi::Value func_name(const Napi::CallbackInfo &info)                                      \
    {                                                                                          \
        Napi::Error::New(info.Env(), #func_name " 函数尚未实现").ThrowAsJavaScriptException(); \
        return info.Env().Undefined();                                                         \
    }

        PLACEHOLDER_IMPL(CascadeClassifier_Create)
        PLACEHOLDER_IMPL(CascadeClassifier_Load)
        PLACEHOLDER_IMPL(CascadeClassifier_DetectMultiScale)
        PLACEHOLDER_IMPL(CascadeClassifier_DetectMultiScale2)
        PLACEHOLDER_IMPL(CascadeClassifier_DetectMultiScale3)
        PLACEHOLDER_IMPL(CascadeClassifier_Empty)
        PLACEHOLDER_IMPL(CascadeClassifier_GetFeatureType)
        PLACEHOLDER_IMPL(CascadeClassifier_GetOriginalWindowSize)
        PLACEHOLDER_IMPL(CascadeClassifier_IsOldFormatCascade)
        PLACEHOLDER_IMPL(HOGDescriptor_Create)
        PLACEHOLDER_IMPL(HOGDescriptor_SetSVMDetector)
        PLACEHOLDER_IMPL(HOGDescriptor_GetDefaultPeopleDetector)
        PLACEHOLDER_IMPL(HOGDescriptor_GetDaimlerPeopleDetector)
        PLACEHOLDER_IMPL(HOGDescriptor_DetectMultiScale)
        PLACEHOLDER_IMPL(HOGDescriptor_Detect)
        PLACEHOLDER_IMPL(HOGDescriptor_Compute)
        PLACEHOLDER_IMPL(HOGDescriptor_ComputeGradient)
        PLACEHOLDER_IMPL(QRCodeDetector_Create)
        PLACEHOLDER_IMPL(QRCodeDetector_Decode)
        PLACEHOLDER_IMPL(QRCodeDetector_Detect)
        PLACEHOLDER_IMPL(QRCodeDetector_DetectAndDecode)
        PLACEHOLDER_IMPL(QRCodeDetector_SetEpsX)
        PLACEHOLDER_IMPL(QRCodeDetector_SetEpsY)
        PLACEHOLDER_IMPL(GroupRectangles)
        PLACEHOLDER_IMPL(GroupRectangles_Meanshift)

    } // namespace Objdetect
} // namespace NapiOpenCV
