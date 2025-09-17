#ifndef NAPI_OPENCV_CALIB3D_H
#define NAPI_OPENCV_CALIB3D_H

#include <napi.h>

namespace NapiOpenCV
{
    namespace Calib3d
    {

        // 注册所有CALIB3D模块函数
        void RegisterFunctions(Napi::Env env, Napi::Object exports);

        // ==================== 相机标定函数 ====================
        Napi::Value CalibrateCamera(const Napi::CallbackInfo &info);
        Napi::Value CalibrateCameraExtended(const Napi::CallbackInfo &info);
        Napi::Value CalibrateHandEye(const Napi::CallbackInfo &info);
        Napi::Value CalibrateRobotWorldHandEye(const Napi::CallbackInfo &info);
        Napi::Value FindChessboardCorners(const Napi::CallbackInfo &info);
        Napi::Value FindChessboardCornersSB(const Napi::CallbackInfo &info);
        Napi::Value DrawChessboardCorners(const Napi::CallbackInfo &info);
        Napi::Value Find4QuadCornerSubpix(const Napi::CallbackInfo &info);
        Napi::Value CornerSubPix(const Napi::CallbackInfo &info);

        // ==================== 立体视觉函数 ====================
        Napi::Value StereoCalibrate(const Napi::CallbackInfo &info);
        Napi::Value StereoRectify(const Napi::CallbackInfo &info);
        Napi::Value StereoRectifyUncalibrated(const Napi::CallbackInfo &info);
        Napi::Value InitCameraMatrix2D(const Napi::CallbackInfo &info);
        Napi::Value GetOptimalNewCameraMatrix(const Napi::CallbackInfo &info);
        Napi::Value InitUndistortRectifyMap(const Napi::CallbackInfo &info);
        Napi::Value Undistort(const Napi::CallbackInfo &info);
        Napi::Value UndistortPoints(const Napi::CallbackInfo &info);

        // ==================== 立体匹配函数 ====================
        Napi::Value StereoBM_Create(const Napi::CallbackInfo &info);
        Napi::Value StereoSGBM_Create(const Napi::CallbackInfo &info);
        Napi::Value StereoMatcher_Compute(const Napi::CallbackInfo &info);
        Napi::Value ValidateDisparity(const Napi::CallbackInfo &info);
        Napi::Value ReprojectImageTo3D(const Napi::CallbackInfo &info);

        // ==================== 三角测量函数 ====================
        Napi::Value TriangulatePoints(const Napi::CallbackInfo &info);
        Napi::Value ConvertPointsFromHomogeneous(const Napi::CallbackInfo &info);
        Napi::Value ConvertPointsToHomogeneous(const Napi::CallbackInfo &info);

        // ==================== 姿态估计函数 ====================
        Napi::Value SolvePnP(const Napi::CallbackInfo &info);
        Napi::Value SolvePnPRansac(const Napi::CallbackInfo &info);
        Napi::Value SolvePnPRefineLM(const Napi::CallbackInfo &info);
        Napi::Value SolvePnPRefineVVS(const Napi::CallbackInfo &info);
        Napi::Value SolvePnPGeneric(const Napi::CallbackInfo &info);
        Napi::Value SolveP3P(const Napi::CallbackInfo &info);
        Napi::Value EstimateAffine2D(const Napi::CallbackInfo &info);
        Napi::Value EstimateAffine3D(const Napi::CallbackInfo &info);
        Napi::Value EstimateAffinePartial2D(const Napi::CallbackInfo &info);

        // ==================== 投影变换函数 ====================
        Napi::Value ProjectPoints(const Napi::CallbackInfo &info);
        Napi::Value Rodrigues(const Napi::CallbackInfo &info);
        Napi::Value ComposeRT(const Napi::CallbackInfo &info);
        Napi::Value DecomposeProjectionMatrix(const Napi::CallbackInfo &info);
        Napi::Value MatMulDeriv(const Napi::CallbackInfo &info);

        // ==================== 极线几何函数 ====================
        Napi::Value FindEssentialMat(const Napi::CallbackInfo &info);
        Napi::Value RecoverPose(const Napi::CallbackInfo &info);
        Napi::Value FindFundamentalMat(const Napi::CallbackInfo &info);
        Napi::Value ComputeCorrespondEpilines(const Napi::CallbackInfo &info);

        // ==================== 相机参数验证 ====================
        Napi::Value CheckChessboard(const Napi::CallbackInfo &info);
        Napi::Value CalibrationMatrixValues(const Napi::CallbackInfo &info);

        // ==================== 鱼眼相机函数 ====================
        Napi::Value Fisheye_ProjectPoints(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_DistortPoints(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_UndistortPoints(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_InitUndistortRectifyMap(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_UndistortImage(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_EstimateNewCameraMatrixForUndistortRectify(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_Calibrate(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_StereoCalibrate(const Napi::CallbackInfo &info);
        Napi::Value Fisheye_StereoRectify(const Napi::CallbackInfo &info);

    } // namespace Calib3d
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_CALIB3D_H
