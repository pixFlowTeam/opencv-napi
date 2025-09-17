#ifndef NAPI_OPENCV_FEATURES2D_H
#define NAPI_OPENCV_FEATURES2D_H

#include <napi.h>

namespace NapiOpenCV {
namespace Features2d {

    // 注册所有FEATURES2D模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== 通用特征检测器接口 ====================
    Napi::Value Feature2D_Detect(const Napi::CallbackInfo &info);
    Napi::Value Feature2D_Compute(const Napi::CallbackInfo &info);
    Napi::Value Feature2D_DetectAndCompute(const Napi::CallbackInfo &info);
    Napi::Value Feature2D_GetDefaultName(const Napi::CallbackInfo &info);

    // ==================== SIFT特征检测器 ====================
    Napi::Value SIFT_Create(const Napi::CallbackInfo &info);
    Napi::Value SIFT_SetNFeatures(const Napi::CallbackInfo &info);
    Napi::Value SIFT_SetNOctaveLayers(const Napi::CallbackInfo &info);
    Napi::Value SIFT_SetContrastThreshold(const Napi::CallbackInfo &info);
    Napi::Value SIFT_SetEdgeThreshold(const Napi::CallbackInfo &info);
    Napi::Value SIFT_SetSigma(const Napi::CallbackInfo &info);

    // ==================== ORB特征检测器 ====================
    Napi::Value ORB_Create(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetMaxFeatures(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetScaleFactor(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetNLevels(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetEdgeThreshold(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetFirstLevel(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetWTA_K(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetScoreType(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetPatchSize(const Napi::CallbackInfo &info);
    Napi::Value ORB_SetFastThreshold(const Napi::CallbackInfo &info);

    // ==================== AKAZE特征检测器 ====================
    Napi::Value AKAZE_Create(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetDescriptorType(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetDescriptorSize(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetDescriptorChannels(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetThreshold(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetNOctaves(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetNOctaveLayers(const Napi::CallbackInfo &info);
    Napi::Value AKAZE_SetDiffusivity(const Napi::CallbackInfo &info);

    // ==================== BRISK特征检测器 ====================
    Napi::Value BRISK_Create(const Napi::CallbackInfo &info);
    Napi::Value BRISK_CreateWithPattern(const Napi::CallbackInfo &info);

    // ==================== FAST角点检测 ====================
    Napi::Value FastFeatureDetector_Create(const Napi::CallbackInfo &info);
    Napi::Value FastFeatureDetector_SetThreshold(const Napi::CallbackInfo &info);
    Napi::Value FastFeatureDetector_SetNonmaxSuppression(const Napi::CallbackInfo &info);
    Napi::Value FastFeatureDetector_SetType(const Napi::CallbackInfo &info);

    // ==================== MSER区域检测 ====================
    Napi::Value MSER_Create(const Napi::CallbackInfo &info);
    Napi::Value MSER_DetectRegions(const Napi::CallbackInfo &info);
    Napi::Value MSER_SetDelta(const Napi::CallbackInfo &info);
    Napi::Value MSER_SetMinArea(const Napi::CallbackInfo &info);
    Napi::Value MSER_SetMaxArea(const Napi::CallbackInfo &info);
    Napi::Value MSER_SetMaxVariation(const Napi::CallbackInfo &info);
    Napi::Value MSER_SetMinDiversity(const Napi::CallbackInfo &info);

    // ==================== SimpleBlobDetector ====================
    Napi::Value SimpleBlobDetector_Create(const Napi::CallbackInfo &info);
    Napi::Value SimpleBlobDetector_SetParams(const Napi::CallbackInfo &info);

    // ==================== 特征匹配器 ====================
    Napi::Value BFMatcher_Create(const Napi::CallbackInfo &info);
    Napi::Value BFMatcher_Match(const Napi::CallbackInfo &info);
    Napi::Value BFMatcher_KnnMatch(const Napi::CallbackInfo &info);
    Napi::Value BFMatcher_RadiusMatch(const Napi::CallbackInfo &info);
    Napi::Value BFMatcher_IsCrossCheck(const Napi::CallbackInfo &info);

    // ==================== FLANN匹配器 ====================
    Napi::Value FlannBasedMatcher_Create(const Napi::CallbackInfo &info);
    Napi::Value FlannBasedMatcher_Match(const Napi::CallbackInfo &info);
    Napi::Value FlannBasedMatcher_KnnMatch(const Napi::CallbackInfo &info);
    Napi::Value FlannBasedMatcher_RadiusMatch(const Napi::CallbackInfo &info);

    // ==================== 关键点处理函数 ====================
    Napi::Value KeyPoint_Convert(const Napi::CallbackInfo &info);
    Napi::Value KeyPoint_Overlap(const Napi::CallbackInfo &info);
    Napi::Value DrawKeypoints(const Napi::CallbackInfo &info);
    Napi::Value DrawMatches(const Napi::CallbackInfo &info);
    Napi::Value DrawMatchesKnn(const Napi::CallbackInfo &info);

    // ==================== 描述符匹配评估 ====================
    Napi::Value EvaluateFeatureDetector(const Napi::CallbackInfo &info);
    Napi::Value ComputeRecallPrecisionCurve(const Napi::CallbackInfo &info);
    Napi::Value GetRecall(const Napi::CallbackInfo &info);

    // ==================== 单应性和基础矩阵 ====================
    Napi::Value FindHomography(const Napi::CallbackInfo &info);
    Napi::Value FindFundamentalMat(const Napi::CallbackInfo &info);
    Napi::Value ComputeCorrespondEpilines(const Napi::CallbackInfo &info);

} // namespace Features2d
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_FEATURES2D_H
