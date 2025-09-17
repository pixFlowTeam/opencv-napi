#ifndef NAPI_OPENCV_PHOTO_H
#define NAPI_OPENCV_PHOTO_H

#include <napi.h>

namespace NapiOpenCV
{
    namespace Photo
    {

        // 注册所有PHOTO模块函数
        void RegisterFunctions(Napi::Env env, Napi::Object exports);

        // ==================== 去噪函数 ====================
        Napi::Value FastNlMeansDenoising(const Napi::CallbackInfo &info);
        Napi::Value FastNlMeansDenoisingColored(const Napi::CallbackInfo &info);
        Napi::Value FastNlMeansDenoisingMulti(const Napi::CallbackInfo &info);
        Napi::Value FastNlMeansDenoisingColoredMulti(const Napi::CallbackInfo &info);
        Napi::Value EdgePreservingFilter(const Napi::CallbackInfo &info);
        Napi::Value DetailEnhance(const Napi::CallbackInfo &info);
        Napi::Value StylizationFilter(const Napi::CallbackInfo &info);
        Napi::Value PencilSketch(const Napi::CallbackInfo &info);

        // ==================== 图像修复函数 ====================
        Napi::Value Inpaint(const Napi::CallbackInfo &info);
        Napi::Value FastInpaint(const Napi::CallbackInfo &info);

        // ==================== HDR成像函数 ====================
        Napi::Value CreateCalibrateDebevec(const Napi::CallbackInfo &info);
        Napi::Value CreateCalibrateRobertson(const Napi::CallbackInfo &info);
        Napi::Value CreateMergeDebevec(const Napi::CallbackInfo &info);
        Napi::Value CreateMergeMertens(const Napi::CallbackInfo &info);
        Napi::Value CreateMergeRobertson(const Napi::CallbackInfo &info);
        Napi::Value CreateTonemapDrago(const Napi::CallbackInfo &info);
        Napi::Value CreateTonemapDurand(const Napi::CallbackInfo &info);
        Napi::Value CreateTonemapReinhard(const Napi::CallbackInfo &info);
        Napi::Value CreateTonemapMantiuk(const Napi::CallbackInfo &info);

        // ==================== 无缝克隆函数 ====================
        Napi::Value SeamlessClone(const Napi::CallbackInfo &info);
        Napi::Value ColorChange(const Napi::CallbackInfo &info);
        Napi::Value IlluminationChange(const Napi::CallbackInfo &info);
        Napi::Value TextureFlattening(const Napi::CallbackInfo &info);

        // ==================== 曝光融合函数 ====================
        Napi::Value CreateAlignMTB(const Napi::CallbackInfo &info);

        // ==================== 白平衡函数 ====================
        Napi::Value CreateSimpleWB(const Napi::CallbackInfo &info);
        Napi::Value CreateGrayworldWB(const Napi::CallbackInfo &info);
        Napi::Value CreateLearningBasedWB(const Napi::CallbackInfo &info);

        // ==================== 对比度增强 ====================
        Napi::Value CreateBRIEF(const Napi::CallbackInfo &info);
        Napi::Value CLAHE_Apply(const Napi::CallbackInfo &info);

        // ==================== 图像融合函数 ====================
        Napi::Value DenoiseTV2(const Napi::CallbackInfo &info);
        Napi::Value DenoiseBayesian(const Napi::CallbackInfo &info);

    } // namespace Photo
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_PHOTO_H
