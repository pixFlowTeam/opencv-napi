#include "videoio.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Videoio
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("videocapture_create", Napi::Function::New(env, VideoCapture_Create));
            exports.Set("videocapture_open", Napi::Function::New(env, VideoCapture_Open));
            exports.Set("videocapture_openwithbackend", Napi::Function::New(env, VideoCapture_OpenWithBackend));
            exports.Set("videocapture_isopened", Napi::Function::New(env, VideoCapture_IsOpened));
            exports.Set("videocapture_release", Napi::Function::New(env, VideoCapture_Release));
            exports.Set("videocapture_grab", Napi::Function::New(env, VideoCapture_Grab));
            exports.Set("videocapture_retrieve", Napi::Function::New(env, VideoCapture_Retrieve));
            exports.Set("videocapture_read", Napi::Function::New(env, VideoCapture_Read));
            exports.Set("videocapture_set", Napi::Function::New(env, VideoCapture_Set));
            exports.Set("videocapture_get", Napi::Function::New(env, VideoCapture_Get));
            exports.Set("videocapture_getbackendname", Napi::Function::New(env, VideoCapture_GetBackendName));
            exports.Set("videocapture_setexceptionmode", Napi::Function::New(env, VideoCapture_SetExceptionMode));
            exports.Set("videocapture_getexceptionmode", Napi::Function::New(env, VideoCapture_GetExceptionMode));
            exports.Set("videowriter_create", Napi::Function::New(env, VideoWriter_Create));
            exports.Set("videowriter_open", Napi::Function::New(env, VideoWriter_Open));
            exports.Set("videowriter_isopened", Napi::Function::New(env, VideoWriter_IsOpened));
            exports.Set("videowriter_release", Napi::Function::New(env, VideoWriter_Release));
            exports.Set("videowriter_write", Napi::Function::New(env, VideoWriter_Write));
            exports.Set("videowriter_set", Napi::Function::New(env, VideoWriter_Set));
            exports.Set("videowriter_get", Napi::Function::New(env, VideoWriter_Get));
            exports.Set("videowriter_fourcc", Napi::Function::New(env, VideoWriter_FourCC));
            exports.Set("videowriter_getbackendname", Napi::Function::New(env, VideoWriter_GetBackendName));
            exports.Set("videocapture_getbackends", Napi::Function::New(env, VideoCapture_GetBackends));
            exports.Set("videocapture_getcamerabackends", Napi::Function::New(env, VideoCapture_GetCameraBackends));
            exports.Set("videocapture_getstreambackends", Napi::Function::New(env, VideoCapture_GetStreamBackends));
            exports.Set("getwriterbackends", Napi::Function::New(env, GetWriterBackends));
            exports.Set("getcapturebackends", Napi::Function::New(env, GetCaptureBackends));
            exports.Set("getcameralist", Napi::Function::New(env, GetCameraList));
            exports.Set("getcameracount", Napi::Function::New(env, GetCameraCount));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name) \
        Napi::Value func_name(const Napi::CallbackInfo &info) \
        { \
            throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
        }

        PLACEHOLDER_IMPL(VideoCapture_Create)
        PLACEHOLDER_IMPL(VideoCapture_Open)
        PLACEHOLDER_IMPL(VideoCapture_OpenWithBackend)
        PLACEHOLDER_IMPL(VideoCapture_IsOpened)
        PLACEHOLDER_IMPL(VideoCapture_Release)
        PLACEHOLDER_IMPL(VideoCapture_Grab)
        PLACEHOLDER_IMPL(VideoCapture_Retrieve)
        PLACEHOLDER_IMPL(VideoCapture_Read)
        PLACEHOLDER_IMPL(VideoCapture_Set)
        PLACEHOLDER_IMPL(VideoCapture_Get)
        PLACEHOLDER_IMPL(VideoCapture_GetBackendName)
        PLACEHOLDER_IMPL(VideoCapture_SetExceptionMode)
        PLACEHOLDER_IMPL(VideoCapture_GetExceptionMode)
        PLACEHOLDER_IMPL(VideoWriter_Create)
        PLACEHOLDER_IMPL(VideoWriter_Open)
        PLACEHOLDER_IMPL(VideoWriter_IsOpened)
        PLACEHOLDER_IMPL(VideoWriter_Release)
        PLACEHOLDER_IMPL(VideoWriter_Write)
        PLACEHOLDER_IMPL(VideoWriter_Set)
        PLACEHOLDER_IMPL(VideoWriter_Get)
        PLACEHOLDER_IMPL(VideoWriter_FourCC)
        PLACEHOLDER_IMPL(VideoWriter_GetBackendName)
        PLACEHOLDER_IMPL(VideoCapture_GetBackends)
        PLACEHOLDER_IMPL(VideoCapture_GetCameraBackends)
        PLACEHOLDER_IMPL(VideoCapture_GetStreamBackends)
        PLACEHOLDER_IMPL(GetWriterBackends)
        PLACEHOLDER_IMPL(GetCaptureBackends)
        PLACEHOLDER_IMPL(GetCameraList)
        PLACEHOLDER_IMPL(GetCameraCount)

    } // namespace Videoio
} // namespace NapiOpenCV
