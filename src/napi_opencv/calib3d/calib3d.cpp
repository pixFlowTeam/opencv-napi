#include "calib3d.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Calib3d
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("calibratecamera", Napi::Function::New(env, CalibrateCamera));
            exports.Set("calibratecameraextended", Napi::Function::New(env, CalibrateCameraExtended));
            exports.Set("calibratehandeye", Napi::Function::New(env, CalibrateHandEye));
            exports.Set("calibraterobotworldhandeye", Napi::Function::New(env, CalibrateRobotWorldHandEye));
            exports.Set("findchessboardcorners", Napi::Function::New(env, FindChessboardCorners));
            exports.Set("findchessboardcornerssb", Napi::Function::New(env, FindChessboardCornersSB));
            exports.Set("drawchessboardcorners", Napi::Function::New(env, DrawChessboardCorners));
            exports.Set("find4quadcornersubpix", Napi::Function::New(env, Find4QuadCornerSubpix));
            exports.Set("cornersubpix", Napi::Function::New(env, CornerSubPix));
            exports.Set("stereocalibrate", Napi::Function::New(env, StereoCalibrate));
            exports.Set("stereorectify", Napi::Function::New(env, StereoRectify));
            exports.Set("stereorectifyuncalibrated", Napi::Function::New(env, StereoRectifyUncalibrated));
            exports.Set("initcameramatrix2d", Napi::Function::New(env, InitCameraMatrix2D));
            exports.Set("getoptimalnewcameramatrix", Napi::Function::New(env, GetOptimalNewCameraMatrix));
            exports.Set("initundistortrectifymap", Napi::Function::New(env, InitUndistortRectifyMap));
            exports.Set("undistort", Napi::Function::New(env, Undistort));
            exports.Set("undistortpoints", Napi::Function::New(env, UndistortPoints));
            exports.Set("stereobm_create", Napi::Function::New(env, StereoBM_Create));
            exports.Set("stereosgbm_create", Napi::Function::New(env, StereoSGBM_Create));
            exports.Set("stereomatcher_compute", Napi::Function::New(env, StereoMatcher_Compute));
            exports.Set("validatedisparity", Napi::Function::New(env, ValidateDisparity));
            exports.Set("reprojectimageto3d", Napi::Function::New(env, ReprojectImageTo3D));
            exports.Set("triangulatepoints", Napi::Function::New(env, TriangulatePoints));
            exports.Set("convertpointsfromhomogeneous", Napi::Function::New(env, ConvertPointsFromHomogeneous));
            exports.Set("convertpointstohomogeneous", Napi::Function::New(env, ConvertPointsToHomogeneous));
            exports.Set("solvepnp", Napi::Function::New(env, SolvePnP));
            exports.Set("solvepnpransac", Napi::Function::New(env, SolvePnPRansac));
            exports.Set("solvepnprefinelm", Napi::Function::New(env, SolvePnPRefineLM));
            exports.Set("solvepnprefinevvs", Napi::Function::New(env, SolvePnPRefineVVS));
            exports.Set("solvepnpgeneric", Napi::Function::New(env, SolvePnPGeneric));
            exports.Set("solvep3p", Napi::Function::New(env, SolveP3P));
            exports.Set("estimateaffine2d", Napi::Function::New(env, EstimateAffine2D));
            exports.Set("estimateaffine3d", Napi::Function::New(env, EstimateAffine3D));
            exports.Set("estimateaffinepartial2d", Napi::Function::New(env, EstimateAffinePartial2D));
            exports.Set("projectpoints", Napi::Function::New(env, ProjectPoints));
            exports.Set("rodrigues", Napi::Function::New(env, Rodrigues));
            exports.Set("composert", Napi::Function::New(env, ComposeRT));
            exports.Set("decomposeprojectionmatrix", Napi::Function::New(env, DecomposeProjectionMatrix));
            exports.Set("matmulderiv", Napi::Function::New(env, MatMulDeriv));
            exports.Set("findessentialmat", Napi::Function::New(env, FindEssentialMat));
            exports.Set("recoverpose", Napi::Function::New(env, RecoverPose));
            exports.Set("findfundamentalmat", Napi::Function::New(env, FindFundamentalMat));
            exports.Set("computecorrespondepilines", Napi::Function::New(env, ComputeCorrespondEpilines));
            exports.Set("checkchessboard", Napi::Function::New(env, CheckChessboard));
            exports.Set("calibrationmatrixvalues", Napi::Function::New(env, CalibrationMatrixValues));
            exports.Set("fisheye_projectpoints", Napi::Function::New(env, Fisheye_ProjectPoints));
            exports.Set("fisheye_distortpoints", Napi::Function::New(env, Fisheye_DistortPoints));
            exports.Set("fisheye_undistortpoints", Napi::Function::New(env, Fisheye_UndistortPoints));
            exports.Set("fisheye_initundistortrectifymap", Napi::Function::New(env, Fisheye_InitUndistortRectifyMap));
            exports.Set("fisheye_undistortimage", Napi::Function::New(env, Fisheye_UndistortImage));
            exports.Set("fisheye_estimatenewcameramatrixforundistortrectify", Napi::Function::New(env, Fisheye_EstimateNewCameraMatrixForUndistortRectify));
            exports.Set("fisheye_calibrate", Napi::Function::New(env, Fisheye_Calibrate));
            exports.Set("fisheye_stereocalibrate", Napi::Function::New(env, Fisheye_StereoCalibrate));
            exports.Set("fisheye_stereorectify", Napi::Function::New(env, Fisheye_StereoRectify));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name) \
        Napi::Value func_name(const Napi::CallbackInfo &info) \
        { \
            throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
        }

        PLACEHOLDER_IMPL(CalibrateCamera)
        PLACEHOLDER_IMPL(CalibrateCameraExtended)
        PLACEHOLDER_IMPL(CalibrateHandEye)
        PLACEHOLDER_IMPL(CalibrateRobotWorldHandEye)
        PLACEHOLDER_IMPL(FindChessboardCorners)
        PLACEHOLDER_IMPL(FindChessboardCornersSB)
        PLACEHOLDER_IMPL(DrawChessboardCorners)
        PLACEHOLDER_IMPL(Find4QuadCornerSubpix)
        PLACEHOLDER_IMPL(CornerSubPix)
        PLACEHOLDER_IMPL(StereoCalibrate)
        PLACEHOLDER_IMPL(StereoRectify)
        PLACEHOLDER_IMPL(StereoRectifyUncalibrated)
        PLACEHOLDER_IMPL(InitCameraMatrix2D)
        PLACEHOLDER_IMPL(GetOptimalNewCameraMatrix)
        PLACEHOLDER_IMPL(InitUndistortRectifyMap)
        PLACEHOLDER_IMPL(Undistort)
        PLACEHOLDER_IMPL(UndistortPoints)
        PLACEHOLDER_IMPL(StereoBM_Create)
        PLACEHOLDER_IMPL(StereoSGBM_Create)
        PLACEHOLDER_IMPL(StereoMatcher_Compute)
        PLACEHOLDER_IMPL(ValidateDisparity)
        PLACEHOLDER_IMPL(ReprojectImageTo3D)
        PLACEHOLDER_IMPL(TriangulatePoints)
        PLACEHOLDER_IMPL(ConvertPointsFromHomogeneous)
        PLACEHOLDER_IMPL(ConvertPointsToHomogeneous)
        PLACEHOLDER_IMPL(SolvePnP)
        PLACEHOLDER_IMPL(SolvePnPRansac)
        PLACEHOLDER_IMPL(SolvePnPRefineLM)
        PLACEHOLDER_IMPL(SolvePnPRefineVVS)
        PLACEHOLDER_IMPL(SolvePnPGeneric)
        PLACEHOLDER_IMPL(SolveP3P)
        PLACEHOLDER_IMPL(EstimateAffine2D)
        PLACEHOLDER_IMPL(EstimateAffine3D)
        PLACEHOLDER_IMPL(EstimateAffinePartial2D)
        PLACEHOLDER_IMPL(ProjectPoints)
        PLACEHOLDER_IMPL(Rodrigues)
        PLACEHOLDER_IMPL(ComposeRT)
        PLACEHOLDER_IMPL(DecomposeProjectionMatrix)
        PLACEHOLDER_IMPL(MatMulDeriv)
        PLACEHOLDER_IMPL(FindEssentialMat)
        PLACEHOLDER_IMPL(RecoverPose)
        PLACEHOLDER_IMPL(FindFundamentalMat)
        PLACEHOLDER_IMPL(ComputeCorrespondEpilines)
        PLACEHOLDER_IMPL(CheckChessboard)
        PLACEHOLDER_IMPL(CalibrationMatrixValues)
        PLACEHOLDER_IMPL(Fisheye_ProjectPoints)
        PLACEHOLDER_IMPL(Fisheye_DistortPoints)
        PLACEHOLDER_IMPL(Fisheye_UndistortPoints)
        PLACEHOLDER_IMPL(Fisheye_InitUndistortRectifyMap)
        PLACEHOLDER_IMPL(Fisheye_UndistortImage)
        PLACEHOLDER_IMPL(Fisheye_EstimateNewCameraMatrixForUndistortRectify)
        PLACEHOLDER_IMPL(Fisheye_Calibrate)
        PLACEHOLDER_IMPL(Fisheye_StereoCalibrate)
        PLACEHOLDER_IMPL(Fisheye_StereoRectify)

    } // namespace Calib3d
} // namespace NapiOpenCV
