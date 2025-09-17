#include "features2d.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Features2d
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            // AKAZE 函数
            exports.Set("akazeCreate", Napi::Function::New(env, AKAZE_Create));
            exports.Set("akazeSetDescriptorChannels", Napi::Function::New(env, AKAZE_SetDescriptorChannels));
            exports.Set("akazeSetDescriptorSize", Napi::Function::New(env, AKAZE_SetDescriptorSize));
            exports.Set("akazeSetDescriptorType", Napi::Function::New(env, AKAZE_SetDescriptorType));
            exports.Set("akazeSetDiffusivity", Napi::Function::New(env, AKAZE_SetDiffusivity));
            exports.Set("akazeSetNOctaveLayers", Napi::Function::New(env, AKAZE_SetNOctaveLayers));
            exports.Set("akazeSetNOctaves", Napi::Function::New(env, AKAZE_SetNOctaves));
            exports.Set("akazeSetThreshold", Napi::Function::New(env, AKAZE_SetThreshold));

            // BFMatcher 函数
            exports.Set("bfMatcherCreate", Napi::Function::New(env, BFMatcher_Create));
            exports.Set("bfMatcherIsCrossCheck", Napi::Function::New(env, BFMatcher_IsCrossCheck));
            exports.Set("bfMatcherKnnMatch", Napi::Function::New(env, BFMatcher_KnnMatch));
            exports.Set("bfMatcherMatch", Napi::Function::New(env, BFMatcher_Match));
            exports.Set("bfMatcherRadiusMatch", Napi::Function::New(env, BFMatcher_RadiusMatch));

            // BRISK 函数
            exports.Set("briskCreate", Napi::Function::New(env, BRISK_Create));
            exports.Set("briskCreateWithPattern", Napi::Function::New(env, BRISK_CreateWithPattern));

            // 基础函数
            exports.Set("computeCorrespondEpilines", Napi::Function::New(env, ComputeCorrespondEpilines));
            exports.Set("computeRecallPrecisionCurve", Napi::Function::New(env, ComputeRecallPrecisionCurve));
            exports.Set("drawKeypoints", Napi::Function::New(env, DrawKeypoints));
            exports.Set("drawMatches", Napi::Function::New(env, DrawMatches));
            exports.Set("drawMatchesKnn", Napi::Function::New(env, DrawMatchesKnn));
            exports.Set("evaluateFeatureDetector", Napi::Function::New(env, EvaluateFeatureDetector));
            exports.Set("getRecall", Napi::Function::New(env, GetRecall));
            exports.Set("keyPointConvert", Napi::Function::New(env, KeyPoint_Convert));
            exports.Set("keyPointOverlap", Napi::Function::New(env, KeyPoint_Overlap));

            // FastFeatureDetector 函数
            exports.Set("fastFeatureDetectorCreate", Napi::Function::New(env, FastFeatureDetector_Create));
            exports.Set("fastFeatureDetectorSetNonmaxSuppression", Napi::Function::New(env, FastFeatureDetector_SetNonmaxSuppression));
            exports.Set("fastFeatureDetectorSetThreshold", Napi::Function::New(env, FastFeatureDetector_SetThreshold));
            exports.Set("fastFeatureDetectorSetType", Napi::Function::New(env, FastFeatureDetector_SetType));

            // Feature2D 函数
            exports.Set("feature2DCompute", Napi::Function::New(env, Feature2D_Compute));
            exports.Set("feature2DDetect", Napi::Function::New(env, Feature2D_Detect));
            exports.Set("feature2DDetectAndCompute", Napi::Function::New(env, Feature2D_DetectAndCompute));
            exports.Set("feature2DGetDefaultName", Napi::Function::New(env, Feature2D_GetDefaultName));

            // 基础矩阵函数
            exports.Set("findFundamentalMat", Napi::Function::New(env, FindFundamentalMat));
            exports.Set("findHomography", Napi::Function::New(env, FindHomography));

            // FlannBasedMatcher 函数
            exports.Set("flannBasedMatcherCreate", Napi::Function::New(env, FlannBasedMatcher_Create));
            exports.Set("flannBasedMatcherKnnMatch", Napi::Function::New(env, FlannBasedMatcher_KnnMatch));
            exports.Set("flannBasedMatcherMatch", Napi::Function::New(env, FlannBasedMatcher_Match));
            exports.Set("flannBasedMatcherRadiusMatch", Napi::Function::New(env, FlannBasedMatcher_RadiusMatch));

            // MSER 函数
            exports.Set("mserCreate", Napi::Function::New(env, MSER_Create));
            exports.Set("mserDetectRegions", Napi::Function::New(env, MSER_DetectRegions));
            exports.Set("mserSetDelta", Napi::Function::New(env, MSER_SetDelta));
            exports.Set("mserSetMaxArea", Napi::Function::New(env, MSER_SetMaxArea));
            exports.Set("mserSetMaxVariation", Napi::Function::New(env, MSER_SetMaxVariation));
            exports.Set("mserSetMinArea", Napi::Function::New(env, MSER_SetMinArea));
            exports.Set("mserSetMinDiversity", Napi::Function::New(env, MSER_SetMinDiversity));

            // ORB 函数
            exports.Set("orbCreate", Napi::Function::New(env, ORB_Create));
            exports.Set("orbSetEdgeThreshold", Napi::Function::New(env, ORB_SetEdgeThreshold));
            exports.Set("orbSetFastThreshold", Napi::Function::New(env, ORB_SetFastThreshold));
            exports.Set("orbSetFirstLevel", Napi::Function::New(env, ORB_SetFirstLevel));
            exports.Set("orbSetMaxFeatures", Napi::Function::New(env, ORB_SetMaxFeatures));
            exports.Set("orbSetNLevels", Napi::Function::New(env, ORB_SetNLevels));
            exports.Set("orbSetPatchSize", Napi::Function::New(env, ORB_SetPatchSize));
            exports.Set("orbSetScaleFactor", Napi::Function::New(env, ORB_SetScaleFactor));
            exports.Set("orbSetScoreType", Napi::Function::New(env, ORB_SetScoreType));
            exports.Set("orbSetWTA_K", Napi::Function::New(env, ORB_SetWTA_K));

            // SIFT 函数
            exports.Set("siftCreate", Napi::Function::New(env, SIFT_Create));
            exports.Set("siftSetContrastThreshold", Napi::Function::New(env, SIFT_SetContrastThreshold));
            exports.Set("siftSetEdgeThreshold", Napi::Function::New(env, SIFT_SetEdgeThreshold));
            exports.Set("siftSetNFeatures", Napi::Function::New(env, SIFT_SetNFeatures));
            exports.Set("siftSetNOctaveLayers", Napi::Function::New(env, SIFT_SetNOctaveLayers));
            exports.Set("siftSetSigma", Napi::Function::New(env, SIFT_SetSigma));

            // SimpleBlobDetector 函数
            exports.Set("simpleBlobDetectorCreate", Napi::Function::New(env, SimpleBlobDetector_Create));
            exports.Set("simpleBlobDetectorSetParams", Napi::Function::New(env, SimpleBlobDetector_SetParams));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name)                                                            \
    Napi::Value func_name(const Napi::CallbackInfo &info)                                      \
    {                                                                                          \
        Napi::Error::New(info.Env(), #func_name " 函数尚未实现").ThrowAsJavaScriptException(); \
        return info.Env().Undefined();                                                         \
    }

        PLACEHOLDER_IMPL(AKAZE_Create)
        PLACEHOLDER_IMPL(AKAZE_SetDescriptorChannels)
        PLACEHOLDER_IMPL(AKAZE_SetDescriptorSize)
        PLACEHOLDER_IMPL(AKAZE_SetDescriptorType)
        PLACEHOLDER_IMPL(AKAZE_SetDiffusivity)
        PLACEHOLDER_IMPL(AKAZE_SetNOctaveLayers)
        PLACEHOLDER_IMPL(AKAZE_SetNOctaves)
        PLACEHOLDER_IMPL(AKAZE_SetThreshold)
        PLACEHOLDER_IMPL(BFMatcher_Create)
        PLACEHOLDER_IMPL(BFMatcher_IsCrossCheck)
        PLACEHOLDER_IMPL(BFMatcher_KnnMatch)
        PLACEHOLDER_IMPL(BFMatcher_Match)
        PLACEHOLDER_IMPL(BFMatcher_RadiusMatch)
        PLACEHOLDER_IMPL(BRISK_Create)
        PLACEHOLDER_IMPL(BRISK_CreateWithPattern)
        PLACEHOLDER_IMPL(ComputeCorrespondEpilines)
        PLACEHOLDER_IMPL(ComputeRecallPrecisionCurve)
        PLACEHOLDER_IMPL(DrawKeypoints)
        PLACEHOLDER_IMPL(DrawMatches)
        PLACEHOLDER_IMPL(DrawMatchesKnn)
        PLACEHOLDER_IMPL(EvaluateFeatureDetector)
        PLACEHOLDER_IMPL(FastFeatureDetector_Create)
        PLACEHOLDER_IMPL(FastFeatureDetector_SetNonmaxSuppression)
        PLACEHOLDER_IMPL(FastFeatureDetector_SetThreshold)
        PLACEHOLDER_IMPL(FastFeatureDetector_SetType)
        PLACEHOLDER_IMPL(Feature2D_Compute)
        PLACEHOLDER_IMPL(Feature2D_Detect)
        PLACEHOLDER_IMPL(Feature2D_DetectAndCompute)
        PLACEHOLDER_IMPL(Feature2D_GetDefaultName)
        PLACEHOLDER_IMPL(FindFundamentalMat)
        PLACEHOLDER_IMPL(FindHomography)
        PLACEHOLDER_IMPL(FlannBasedMatcher_Create)
        PLACEHOLDER_IMPL(FlannBasedMatcher_KnnMatch)
        PLACEHOLDER_IMPL(FlannBasedMatcher_Match)
        PLACEHOLDER_IMPL(FlannBasedMatcher_RadiusMatch)
        PLACEHOLDER_IMPL(GetRecall)
        PLACEHOLDER_IMPL(KeyPoint_Convert)
        PLACEHOLDER_IMPL(KeyPoint_Overlap)
        PLACEHOLDER_IMPL(MSER_Create)
        PLACEHOLDER_IMPL(MSER_DetectRegions)
        PLACEHOLDER_IMPL(MSER_SetDelta)
        PLACEHOLDER_IMPL(MSER_SetMaxArea)
        PLACEHOLDER_IMPL(MSER_SetMaxVariation)
        PLACEHOLDER_IMPL(MSER_SetMinArea)
        PLACEHOLDER_IMPL(MSER_SetMinDiversity)
        PLACEHOLDER_IMPL(ORB_Create)
        PLACEHOLDER_IMPL(ORB_SetEdgeThreshold)
        PLACEHOLDER_IMPL(ORB_SetFastThreshold)
        PLACEHOLDER_IMPL(ORB_SetFirstLevel)
        PLACEHOLDER_IMPL(ORB_SetMaxFeatures)
        PLACEHOLDER_IMPL(ORB_SetNLevels)
        PLACEHOLDER_IMPL(ORB_SetPatchSize)
        PLACEHOLDER_IMPL(ORB_SetScaleFactor)
        PLACEHOLDER_IMPL(ORB_SetScoreType)
        PLACEHOLDER_IMPL(ORB_SetWTA_K)
        PLACEHOLDER_IMPL(SIFT_Create)
        PLACEHOLDER_IMPL(SIFT_SetContrastThreshold)
        PLACEHOLDER_IMPL(SIFT_SetEdgeThreshold)
        PLACEHOLDER_IMPL(SIFT_SetNFeatures)
        PLACEHOLDER_IMPL(SIFT_SetNOctaveLayers)
        PLACEHOLDER_IMPL(SIFT_SetSigma)
        PLACEHOLDER_IMPL(SimpleBlobDetector_Create)
        PLACEHOLDER_IMPL(SimpleBlobDetector_SetParams)

    } // namespace Features2d
} // namespace NapiOpenCV
