#ifndef NAPI_OPENCV_VIDEOIO_H
#define NAPI_OPENCV_VIDEOIO_H

#include <napi.h>

namespace NapiOpenCV
{
    namespace Videoio
    {

        // 注册所有VIDEOIO模块函数
        void RegisterFunctions(Napi::Env env, Napi::Object exports);

        // ==================== VideoCapture类函数 ====================
        Napi::Value VideoCapture_Create(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Open(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_OpenWithBackend(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_IsOpened(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Release(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Grab(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Retrieve(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Read(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Set(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_Get(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_GetBackendName(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_SetExceptionMode(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_GetExceptionMode(const Napi::CallbackInfo &info);

        // ==================== VideoWriter类函数 ====================
        Napi::Value VideoWriter_Create(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_Open(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_IsOpened(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_Release(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_Write(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_Set(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_Get(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_FourCC(const Napi::CallbackInfo &info);
        Napi::Value VideoWriter_GetBackendName(const Napi::CallbackInfo &info);

        // ==================== 摄像头控制函数 ====================
        Napi::Value VideoCapture_GetBackends(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_GetCameraBackends(const Napi::CallbackInfo &info);
        Napi::Value VideoCapture_GetStreamBackends(const Napi::CallbackInfo &info);

        // ==================== 编解码器支持函数 ====================
        Napi::Value GetWriterBackends(const Napi::CallbackInfo &info);
        Napi::Value GetCaptureBackends(const Napi::CallbackInfo &info);

        // ==================== 设备枚举函数 ====================
        Napi::Value GetCameraList(const Napi::CallbackInfo &info);
        Napi::Value GetCameraCount(const Napi::CallbackInfo &info);

    } // namespace Videoio
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_VIDEOIO_H
