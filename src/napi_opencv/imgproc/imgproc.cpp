#include "imgproc.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"
#include <opencv2/imgproc.hpp>

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace ImgProc
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            // 滤波函数
            exports.Set("blur", Napi::Function::New(env, Blur));
            exports.Set("gaussianBlur", Napi::Function::New(env, GaussianBlur));
            exports.Set("medianBlur", Napi::Function::New(env, MedianBlur));
            exports.Set("bilateralFilter", Napi::Function::New(env, BilateralFilter));
            exports.Set("filter2D", Napi::Function::New(env, Filter2D));
            exports.Set("boxFilter", Napi::Function::New(env, BoxFilter));
            exports.Set("sqrBoxFilter", Napi::Function::New(env, SqrBoxFilter));
            exports.Set("sepFilter2D", Napi::Function::New(env, SepFilter2D));

            // 几何变换函数
            exports.Set("resize", Napi::Function::New(env, Resize));
            exports.Set("warpAffine", Napi::Function::New(env, WarpAffine));
            exports.Set("warpPerspective", Napi::Function::New(env, WarpPerspective));
            exports.Set("getRotationMatrix2D", Napi::Function::New(env, GetRotationMatrix2D));
            exports.Set("getAffineTransform", Napi::Function::New(env, GetAffineTransform));
            exports.Set("getPerspectiveTransform", Napi::Function::New(env, GetPerspectiveTransform));
            exports.Set("invertAffineTransform", Napi::Function::New(env, InvertAffineTransform));
            exports.Set("remap", Napi::Function::New(env, Remap));

            // 形态学操作
            exports.Set("erode", Napi::Function::New(env, Erode));
            exports.Set("dilate", Napi::Function::New(env, Dilate));
            exports.Set("morphologyEx", Napi::Function::New(env, MorphologyEx));
            exports.Set("getStructuringElement", Napi::Function::New(env, GetStructuringElement));

            // 图像金字塔
            exports.Set("pyrDown", Napi::Function::New(env, PyrDown));
            exports.Set("pyrUp", Napi::Function::New(env, PyrUp));
            exports.Set("buildPyramid", Napi::Function::New(env, BuildPyramid));

            // 轮廓分析函数
            exports.Set("findContours", Napi::Function::New(env, FindContours));
            exports.Set("drawContours", Napi::Function::New(env, DrawContours));
            exports.Set("contourArea", Napi::Function::New(env, ContourArea));
            exports.Set("arcLength", Napi::Function::New(env, ArcLength));
            exports.Set("convexHull", Napi::Function::New(env, ConvexHull));
            exports.Set("convexityDefects", Napi::Function::New(env, ConvexityDefects));
            exports.Set("minAreaRect", Napi::Function::New(env, MinAreaRect));
            exports.Set("minEnclosingCircle", Napi::Function::New(env, MinEnclosingCircle));
            exports.Set("minEnclosingTriangle", Napi::Function::New(env, MinEnclosingTriangle));
            exports.Set("fitEllipse", Napi::Function::New(env, FitEllipse));
            exports.Set("fitLine", Napi::Function::New(env, FitLine));
            exports.Set("boundingRect", Napi::Function::New(env, BoundingRect));
            exports.Set("approxPolyDP", Napi::Function::New(env, ApproxPolyDP));
            exports.Set("isContourConvex", Napi::Function::New(env, IsContourConvex));

            // 色彩空间转换
            exports.Set("cvtColor", Napi::Function::New(env, CvtColor));

            // 直方图函数
            exports.Set("calcHist", Napi::Function::New(env, CalcHist));
            exports.Set("calcBackProject", Napi::Function::New(env, CalcBackProject));
            exports.Set("compareHist", Napi::Function::New(env, CompareHist));
            exports.Set("equalizeHist", Napi::Function::New(env, EqualizeHist));
            exports.Set("claheCreate", Napi::Function::New(env, CLAHE_Create));

            // 模板匹配
            exports.Set("matchTemplate", Napi::Function::New(env, MatchTemplate));

            // 霍夫变换
            exports.Set("houghLines", Napi::Function::New(env, HoughLines));
            exports.Set("houghLinesP", Napi::Function::New(env, HoughLinesP));
            exports.Set("houghCircles", Napi::Function::New(env, HoughCircles));

            // 距离变换
            exports.Set("distanceTransform", Napi::Function::New(env, DistanceTransform));
            exports.Set("distanceTransformWithLabels", Napi::Function::New(env, DistanceTransformWithLabels));

            // 图像分割
            exports.Set("watershed", Napi::Function::New(env, Watershed));
            exports.Set("grabCut", Napi::Function::New(env, GrabCut));
            exports.Set("floodFill", Napi::Function::New(env, FloodFill));

            // 绘制函数
            exports.Set("line", Napi::Function::New(env, Line));
            exports.Set("rectangle", Napi::Function::New(env, Rectangle));
            exports.Set("circle", Napi::Function::New(env, Circle));
            exports.Set("ellipse", Napi::Function::New(env, Ellipse));
            exports.Set("polylines", Napi::Function::New(env, Polylines));
            exports.Set("fillPoly", Napi::Function::New(env, FillPoly));
            exports.Set("putText", Napi::Function::New(env, PutText));

            // 边缘检测
            exports.Set("canny", Napi::Function::New(env, Canny));
            exports.Set("sobel", Napi::Function::New(env, Sobel));
            exports.Set("scharr", Napi::Function::New(env, Scharr));
            exports.Set("laplacian", Napi::Function::New(env, Laplacian));

            exports.Set("accumulateWeighted", Napi::Function::New(env, AccumulateWeighted));
            exports.Set("applyColorMap", Napi::Function::New(env, ApplyColorMap));
            exports.Set("arrowedLine", Napi::Function::New(env, ArrowedLine));
            exports.Set("connectedComponents", Napi::Function::New(env, ConnectedComponents));
            exports.Set("connectedComponentsWithStats", Napi::Function::New(env, ConnectedComponentsWithStats));
            exports.Set("convertMaps", Napi::Function::New(env, ConvertMaps));
            exports.Set("cornerEigenValsAndVecs", Napi::Function::New(env, CornerEigenValsAndVecs));
            exports.Set("cornerHarris", Napi::Function::New(env, CornerHarris));
            exports.Set("cornerMinEigenVal", Napi::Function::New(env, CornerMinEigenVal));
            exports.Set("createBackgroundSubtractorKNN", Napi::Function::New(env, CreateBackgroundSubtractorKNN));
            exports.Set("createBackgroundSubtractorMOG2", Napi::Function::New(env, CreateBackgroundSubtractorMOG2));
            exports.Set("emd", Napi::Function::New(env, EMD));
            exports.Set("getDerivKernels", Napi::Function::New(env, GetDerivKernels));
            exports.Set("getRectSubPix", Napi::Function::New(env, GetRectSubPix));
            exports.Set("goodFeaturesToTrack", Napi::Function::New(env, GoodFeaturesToTrack));
            exports.Set("huMoments", Napi::Function::New(env, HuMoments));
            exports.Set("integralImage", Napi::Function::New(env, IntegralImage));
            exports.Set("linearPolar", Napi::Function::New(env, LinearPolar));
            exports.Set("logPolar", Napi::Function::New(env, LogPolar));
            exports.Set("matchShapes", Napi::Function::New(env, MatchShapes));
            exports.Set("moments", Napi::Function::New(env, Moments));
            exports.Set("morphGradient", Napi::Function::New(env, MorphGradient));
            exports.Set("pointPolygonTest", Napi::Function::New(env, PointPolygonTest));
            exports.Set("preCornerDetect", Napi::Function::New(env, PreCornerDetect));
            exports.Set("spatialGradient", Napi::Function::New(env, SpatialGradient));
            exports.Set("subdiv2DCreate", Napi::Function::New(env, Subdiv2D_Create));
            exports.Set("subdiv2DGetTriangleList", Napi::Function::New(env, Subdiv2D_GetTriangleList));
            exports.Set("subdiv2DGetVoronoiFacetList", Napi::Function::New(env, Subdiv2D_GetVoronoiFacetList));
            exports.Set("subdiv2DInsert", Napi::Function::New(env, Subdiv2D_Insert));
        }

        // ==================== 已实现的函数 ====================

        // 图像缩放
        Napi::Value Resize(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]() -> Napi::Value
                            {
            if (info.Length() < 2 || !info[0].IsObject() || !info[1].IsObject()) {
                throw Napi::TypeError::New(info.Env(), "期望 Mat 对象和 Size 对象参数");
            }
            
            cv::Mat src = TypeConverter<cv::Mat>::FromNapi(info[0]);
            cv::Size dsize = TypeConverter<cv::Size>::FromNapi(info[1]);
            
            int interpolation = cv::INTER_LINEAR; // 默认线性插值
            if (info.Length() > 2 && info[2].IsNumber()) {
                interpolation = info[2].As<Napi::Number>().Int32Value();
            }
            
            cv::Mat dst;
            cv::resize(src, dst, dsize, 0, 0, interpolation);
            
            return TypeConverter<cv::Mat>::ToNapi(info.Env(), dst); });
        }

        // 高斯滤波
        Napi::Value GaussianBlur(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]() -> Napi::Value
                            {
            if (info.Length() < 3 || !info[0].IsObject() || !info[1].IsObject() || !info[2].IsNumber()) {
                throw Napi::TypeError::New(info.Env(), "期望 Mat 对象、Size 对象和数字参数");
            }
            
            cv::Mat src = TypeConverter<cv::Mat>::FromNapi(info[0]);
            cv::Size ksize = TypeConverter<cv::Size>::FromNapi(info[1]);
            double sigmaX = info[2].As<Napi::Number>().DoubleValue();
            
            double sigmaY = 0; // 默认与 sigmaX 相同
            if (info.Length() > 3 && info[3].IsNumber()) {
                sigmaY = info[3].As<Napi::Number>().DoubleValue();
            }
            
            cv::Mat dst;
            cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY);
            
            return TypeConverter<cv::Mat>::ToNapi(info.Env(), dst); });
        }

        // 色彩空间转换
        Napi::Value CvtColor(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]() -> Napi::Value
                            {
            if (info.Length() < 2 || !info[0].IsObject() || !info[1].IsNumber()) {
                throw Napi::TypeError::New(info.Env(), "期望 Mat 对象和数字参数");
            }
            
            cv::Mat src = TypeConverter<cv::Mat>::FromNapi(info[0]);
            int code = info[1].As<Napi::Number>().Int32Value();
            
            cv::Mat dst;
            cv::cvtColor(src, dst, code);
            
            return TypeConverter<cv::Mat>::ToNapi(info.Env(), dst); });
        }

        // ==================== 占位符实现 ====================

#define PLACEHOLDER_IMPL(func_name)                                     \
    Napi::Value func_name(const Napi::CallbackInfo &info)               \
    {                                                                   \
        throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
    }

        PLACEHOLDER_IMPL(Blur)
        PLACEHOLDER_IMPL(MedianBlur)
        PLACEHOLDER_IMPL(BilateralFilter)
        PLACEHOLDER_IMPL(Filter2D)
        PLACEHOLDER_IMPL(BoxFilter)
        PLACEHOLDER_IMPL(SqrBoxFilter)
        PLACEHOLDER_IMPL(SepFilter2D)
        PLACEHOLDER_IMPL(WarpAffine)
        PLACEHOLDER_IMPL(WarpPerspective)
        PLACEHOLDER_IMPL(GetRotationMatrix2D)
        PLACEHOLDER_IMPL(GetAffineTransform)
        PLACEHOLDER_IMPL(GetPerspectiveTransform)
        PLACEHOLDER_IMPL(InvertAffineTransform)
        PLACEHOLDER_IMPL(Remap)
        PLACEHOLDER_IMPL(Erode)
        PLACEHOLDER_IMPL(Dilate)
        PLACEHOLDER_IMPL(MorphologyEx)
        PLACEHOLDER_IMPL(GetStructuringElement)
        PLACEHOLDER_IMPL(PyrDown)
        PLACEHOLDER_IMPL(PyrUp)
        PLACEHOLDER_IMPL(BuildPyramid)
        PLACEHOLDER_IMPL(FindContours)
        PLACEHOLDER_IMPL(DrawContours)
        PLACEHOLDER_IMPL(ContourArea)
        PLACEHOLDER_IMPL(ArcLength)
        PLACEHOLDER_IMPL(ConvexHull)
        PLACEHOLDER_IMPL(ConvexityDefects)
        PLACEHOLDER_IMPL(MinAreaRect)
        PLACEHOLDER_IMPL(MinEnclosingCircle)
        PLACEHOLDER_IMPL(MinEnclosingTriangle)
        PLACEHOLDER_IMPL(FitEllipse)
        PLACEHOLDER_IMPL(FitLine)
        PLACEHOLDER_IMPL(BoundingRect)
        PLACEHOLDER_IMPL(ApproxPolyDP)
        PLACEHOLDER_IMPL(IsContourConvex)
        PLACEHOLDER_IMPL(CalcHist)
        PLACEHOLDER_IMPL(CalcBackProject)
        PLACEHOLDER_IMPL(CompareHist)
        PLACEHOLDER_IMPL(EqualizeHist)
        PLACEHOLDER_IMPL(CLAHE_Create)
        PLACEHOLDER_IMPL(MatchTemplate)
        PLACEHOLDER_IMPL(HoughLines)
        PLACEHOLDER_IMPL(HoughLinesP)
        PLACEHOLDER_IMPL(HoughCircles)
        PLACEHOLDER_IMPL(DistanceTransform)
        PLACEHOLDER_IMPL(DistanceTransformWithLabels)
        PLACEHOLDER_IMPL(Watershed)
        PLACEHOLDER_IMPL(GrabCut)
        PLACEHOLDER_IMPL(FloodFill)
        PLACEHOLDER_IMPL(Line)
        PLACEHOLDER_IMPL(Rectangle)
        PLACEHOLDER_IMPL(Circle)
        PLACEHOLDER_IMPL(Ellipse)
        PLACEHOLDER_IMPL(Polylines)
        PLACEHOLDER_IMPL(FillPoly)
        PLACEHOLDER_IMPL(PutText)
        PLACEHOLDER_IMPL(Canny)
        PLACEHOLDER_IMPL(Sobel)
        PLACEHOLDER_IMPL(Scharr)
        PLACEHOLDER_IMPL(Laplacian)

        PLACEHOLDER_IMPL(AccumulateWeighted)
        PLACEHOLDER_IMPL(ApplyColorMap)
        PLACEHOLDER_IMPL(ArrowedLine)
        PLACEHOLDER_IMPL(ConnectedComponents)
        PLACEHOLDER_IMPL(ConnectedComponentsWithStats)
        PLACEHOLDER_IMPL(ConvertMaps)
        PLACEHOLDER_IMPL(CornerEigenValsAndVecs)
        PLACEHOLDER_IMPL(CornerHarris)
        PLACEHOLDER_IMPL(CornerMinEigenVal)
        PLACEHOLDER_IMPL(CreateBackgroundSubtractorKNN)
        PLACEHOLDER_IMPL(CreateBackgroundSubtractorMOG2)
        PLACEHOLDER_IMPL(EMD)
        PLACEHOLDER_IMPL(GetDerivKernels)
        PLACEHOLDER_IMPL(GetRectSubPix)
        PLACEHOLDER_IMPL(GoodFeaturesToTrack)
        PLACEHOLDER_IMPL(HuMoments)
        PLACEHOLDER_IMPL(IntegralImage)
        PLACEHOLDER_IMPL(LinearPolar)
        PLACEHOLDER_IMPL(LogPolar)
        PLACEHOLDER_IMPL(MatchShapes)
        PLACEHOLDER_IMPL(Moments)
        PLACEHOLDER_IMPL(MorphGradient)
        PLACEHOLDER_IMPL(PointPolygonTest)
        PLACEHOLDER_IMPL(PreCornerDetect)
        PLACEHOLDER_IMPL(SpatialGradient)
        PLACEHOLDER_IMPL(Subdiv2D_Create)
        PLACEHOLDER_IMPL(Subdiv2D_GetTriangleList)
        PLACEHOLDER_IMPL(Subdiv2D_GetVoronoiFacetList)
        PLACEHOLDER_IMPL(Subdiv2D_Insert)

    } // namespace ImgProc
} // namespace NapiOpenCV