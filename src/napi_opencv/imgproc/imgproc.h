#ifndef NAPI_OPENCV_IMGPROC_H
#define NAPI_OPENCV_IMGPROC_H

#include <napi.h>

namespace NapiOpenCV {
namespace ImgProc {

    // 注册所有IMGPROC模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== 滤波函数 ====================
    Napi::Value Blur(const Napi::CallbackInfo &info);
    Napi::Value GaussianBlur(const Napi::CallbackInfo &info);
    Napi::Value MedianBlur(const Napi::CallbackInfo &info);
    Napi::Value BilateralFilter(const Napi::CallbackInfo &info);
    Napi::Value Filter2D(const Napi::CallbackInfo &info);
    Napi::Value BoxFilter(const Napi::CallbackInfo &info);
    Napi::Value SqrBoxFilter(const Napi::CallbackInfo &info);
    Napi::Value SepFilter2D(const Napi::CallbackInfo &info);
    Napi::Value MorphologyEx(const Napi::CallbackInfo &info);
    Napi::Value GetDerivKernels(const Napi::CallbackInfo &info);

    // ==================== 几何变换函数 ====================
    Napi::Value Resize(const Napi::CallbackInfo &info);
    Napi::Value WarpAffine(const Napi::CallbackInfo &info);
    Napi::Value WarpPerspective(const Napi::CallbackInfo &info);
    Napi::Value GetRotationMatrix2D(const Napi::CallbackInfo &info);
    Napi::Value GetAffineTransform(const Napi::CallbackInfo &info);
    Napi::Value GetPerspectiveTransform(const Napi::CallbackInfo &info);
    Napi::Value InvertAffineTransform(const Napi::CallbackInfo &info);
    Napi::Value Remap(const Napi::CallbackInfo &info);
    Napi::Value ConvertMaps(const Napi::CallbackInfo &info);
    Napi::Value GetRectSubPix(const Napi::CallbackInfo &info);
    Napi::Value LogPolar(const Napi::CallbackInfo &info);
    Napi::Value LinearPolar(const Napi::CallbackInfo &info);

    // ==================== 形态学操作 ====================
    Napi::Value Erode(const Napi::CallbackInfo &info);
    Napi::Value Dilate(const Napi::CallbackInfo &info);
    Napi::Value MorphologyEx(const Napi::CallbackInfo &info);
    Napi::Value GetStructuringElement(const Napi::CallbackInfo &info);
    Napi::Value MorphGradient(const Napi::CallbackInfo &info);

    // ==================== 图像金字塔 ====================
    Napi::Value PyrDown(const Napi::CallbackInfo &info);
    Napi::Value PyrUp(const Napi::CallbackInfo &info);
    Napi::Value BuildPyramid(const Napi::CallbackInfo &info);

    // ==================== 轮廓分析函数 ====================
    Napi::Value FindContours(const Napi::CallbackInfo &info);
    Napi::Value DrawContours(const Napi::CallbackInfo &info);
    Napi::Value ContourArea(const Napi::CallbackInfo &info);
    Napi::Value ArcLength(const Napi::CallbackInfo &info);
    Napi::Value ConvexHull(const Napi::CallbackInfo &info);
    Napi::Value ConvexityDefects(const Napi::CallbackInfo &info);
    Napi::Value MinAreaRect(const Napi::CallbackInfo &info);
    Napi::Value MinEnclosingCircle(const Napi::CallbackInfo &info);
    Napi::Value MinEnclosingTriangle(const Napi::CallbackInfo &info);
    Napi::Value FitEllipse(const Napi::CallbackInfo &info);
    Napi::Value FitLine(const Napi::CallbackInfo &info);
    Napi::Value BoundingRect(const Napi::CallbackInfo &info);
    Napi::Value ApproxPolyDP(const Napi::CallbackInfo &info);
    Napi::Value IsContourConvex(const Napi::CallbackInfo &info);
    Napi::Value PointPolygonTest(const Napi::CallbackInfo &info);
    Napi::Value MatchShapes(const Napi::CallbackInfo &info);
    Napi::Value ConnectedComponents(const Napi::CallbackInfo &info);
    Napi::Value ConnectedComponentsWithStats(const Napi::CallbackInfo &info);
    Napi::Value Moments(const Napi::CallbackInfo &info);
    Napi::Value HuMoments(const Napi::CallbackInfo &info);

    // ==================== 色彩空间转换 ====================
    Napi::Value CvtColor(const Napi::CallbackInfo &info);

    // ==================== 直方图函数 ====================
    Napi::Value CalcHist(const Napi::CallbackInfo &info);
    Napi::Value CalcBackProject(const Napi::CallbackInfo &info);
    Napi::Value CompareHist(const Napi::CallbackInfo &info);
    Napi::Value EqualizeHist(const Napi::CallbackInfo &info);
    Napi::Value CLAHE_Create(const Napi::CallbackInfo &info);
    Napi::Value EMD(const Napi::CallbackInfo &info);

    // ==================== 模板匹配 ====================
    Napi::Value MatchTemplate(const Napi::CallbackInfo &info);

    // ==================== 霍夫变换 ====================
    Napi::Value HoughLines(const Napi::CallbackInfo &info);
    Napi::Value HoughLinesP(const Napi::CallbackInfo &info);
    Napi::Value HoughCircles(const Napi::CallbackInfo &info);

    // ==================== 距离变换 ====================
    Napi::Value DistanceTransform(const Napi::CallbackInfo &info);
    Napi::Value DistanceTransformWithLabels(const Napi::CallbackInfo &info);

    // ==================== 图像分割 ====================
    Napi::Value Watershed(const Napi::CallbackInfo &info);
    Napi::Value GrabCut(const Napi::CallbackInfo &info);
    Napi::Value FloodFill(const Napi::CallbackInfo &info);

    // ==================== 绘制函数 ====================
    Napi::Value Line(const Napi::CallbackInfo &info);
    Napi::Value Rectangle(const Napi::CallbackInfo &info);
    Napi::Value Circle(const Napi::CallbackInfo &info);
    Napi::Value Ellipse(const Napi::CallbackInfo &info);
    Napi::Value Polylines(const Napi::CallbackInfo &info);
    Napi::Value FillPoly(const Napi::CallbackInfo &info);
    Napi::Value PutText(const Napi::CallbackInfo &info);
    Napi::Value ArrowedLine(const Napi::CallbackInfo &info);

    // ==================== 边缘检测 ====================
    Napi::Value Canny(const Napi::CallbackInfo &info);
    Napi::Value Sobel(const Napi::CallbackInfo &info);
    Napi::Value Scharr(const Napi::CallbackInfo &info);
    Napi::Value Laplacian(const Napi::CallbackInfo &info);
    Napi::Value SpatialGradient(const Napi::CallbackInfo &info);

    // ==================== 色彩映射 ====================
    Napi::Value ApplyColorMap(const Napi::CallbackInfo &info);

    // ==================== 平面细分 ====================
    Napi::Value Subdiv2D_Create(const Napi::CallbackInfo &info);
    Napi::Value Subdiv2D_Insert(const Napi::CallbackInfo &info);
    Napi::Value Subdiv2D_GetTriangleList(const Napi::CallbackInfo &info);
    Napi::Value Subdiv2D_GetVoronoiFacetList(const Napi::CallbackInfo &info);

    // ==================== 运动分析 ====================
    Napi::Value AccumulateWeighted(const Napi::CallbackInfo &info);
    Napi::Value CreateBackgroundSubtractorMOG2(const Napi::CallbackInfo &info);
    Napi::Value CreateBackgroundSubtractorKNN(const Napi::CallbackInfo &info);

    // ==================== 特征检测 ====================
    Napi::Value GoodFeaturesToTrack(const Napi::CallbackInfo &info);
    Napi::Value CornerHarris(const Napi::CallbackInfo &info);
    Napi::Value CornerEigenValsAndVecs(const Napi::CallbackInfo &info);
    Napi::Value PreCornerDetect(const Napi::CallbackInfo &info);
    Napi::Value CornerMinEigenVal(const Napi::CallbackInfo &info);

    // ==================== 其他变换 ====================
    Napi::Value IntegralImage(const Napi::CallbackInfo &info);
    Napi::Value LogPolar(const Napi::CallbackInfo &info);
    Napi::Value LinearPolar(const Napi::CallbackInfo &info);

} // namespace ImgProc
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_IMGPROC_H