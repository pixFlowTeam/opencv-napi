#include "napi_opencv.h"
#include "common/type_converters.h"
#include <opencv2/core.hpp>

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{

    Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        // 添加版本信息
        Napi::Object version = Napi::Object::New(env);
        version.Set("major", Napi::Number::New(env, CV_VERSION_MAJOR));
        version.Set("minor", Napi::Number::New(env, CV_VERSION_MINOR));
        version.Set("revision", Napi::Number::New(env, CV_VERSION_REVISION));
        exports.Set("version", version);

        // Mat 类暂时移除

        // 添加模块信息
        Napi::Object modules = Napi::Object::New(env);
        modules.Set("core", Napi::Boolean::New(env, true));
        modules.Set("imgproc", Napi::Boolean::New(env, true));
        modules.Set("imgcodecs", Napi::Boolean::New(env, true));
        modules.Set("objdetect", Napi::Boolean::New(env, true));
        modules.Set("features2d", Napi::Boolean::New(env, true));
        modules.Set("flann", Napi::Boolean::New(env, true));
        modules.Set("photo", Napi::Boolean::New(env, true));
        modules.Set("calib3d", Napi::Boolean::New(env, true));
        modules.Set("gapi", Napi::Boolean::New(env, true));
        modules.Set("videoio", Napi::Boolean::New(env, true));
        modules.Set("ts", Napi::Boolean::New(env, true));
        modules.Set("world", Napi::Boolean::New(env, true));
        exports.Set("modules", modules);

        // 注册各模块函数 - 逐步开启模块
        Core::RegisterFunctions(env, exports);
        ImgProc::RegisterFunctions(env, exports);
        ImgCodecs::RegisterFunctions(env, exports);
        Objdetect::RegisterFunctions(env, exports);
        Features2d::RegisterFunctions(env, exports);
        Photo::RegisterFunctions(env, exports);
        Calib3d::RegisterFunctions(env, exports);
        Flann::RegisterFunctions(env, exports);
        Videoio::RegisterFunctions(env, exports);
        Gapi::RegisterFunctions(env, exports);

        return exports;
    }

} // namespace NapiOpenCV