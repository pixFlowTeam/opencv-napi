#include "imgcodecs.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"
#include <opencv2/imgcodecs.hpp>

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace ImgCodecs
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("imread", Napi::Function::New(env, Imread));
            exports.Set("imwrite", Napi::Function::New(env, Imwrite));
            exports.Set("imdecode", Napi::Function::New(env, Imdecode));
            exports.Set("imencode", Napi::Function::New(env, Imencode));
            exports.Set("haveImageReader", Napi::Function::New(env, HaveImageReader));
            exports.Set("haveImageWriter", Napi::Function::New(env, HaveImageWriter));

            exports.Set("imcountPages", Napi::Function::New(env, ImcountPages));
            exports.Set("imreadMulti", Napi::Function::New(env, ImreadMulti));
            exports.Set("imwriteMulti", Napi::Function::New(env, ImwriteMulti));
        }

        // 读取图像
        Napi::Value Imread(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]() -> Napi::Value
                            {
            if (info.Length() < 1 || !info[0].IsString()) {
                throw Napi::TypeError::New(info.Env(), "期望字符串参数");
            }
            
            std::string filename = info[0].As<Napi::String>().Utf8Value();
            int flags = cv::IMREAD_COLOR; // 默认彩色模式
            
            if (info.Length() > 1 && info[1].IsNumber()) {
                flags = info[1].As<Napi::Number>().Int32Value();
            }
            
            cv::Mat image = cv::imread(filename, flags);
            if (image.empty()) {
                throw Napi::Error::New(info.Env(), "无法读取图像: " + filename);
            }
            
            return TypeConverter<cv::Mat>::ToNapi(info.Env(), image); });
        }

        // 写入图像
        Napi::Value Imwrite(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]() -> Napi::Value
                            {
            if (info.Length() < 2 || !info[0].IsString() || !info[1].IsObject()) {
                throw Napi::TypeError::New(info.Env(), "期望字符串和 Mat 对象参数");
            }
            
            std::string filename = info[0].As<Napi::String>().Utf8Value();
            cv::Mat image = TypeConverter<cv::Mat>::FromNapi(info[1]);
            
            bool success = cv::imwrite(filename, image);
            return Napi::Boolean::New(info.Env(), success); });
        }

#define PLACEHOLDER_IMPL(func_name)                                     \
    Napi::Value func_name(const Napi::CallbackInfo &info)               \
    {                                                                   \
        throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
    }

        PLACEHOLDER_IMPL(Imdecode)
        PLACEHOLDER_IMPL(Imencode)
        PLACEHOLDER_IMPL(HaveImageReader)
        PLACEHOLDER_IMPL(HaveImageWriter)

        PLACEHOLDER_IMPL(ImcountPages)
        PLACEHOLDER_IMPL(ImreadMulti)
        PLACEHOLDER_IMPL(ImwriteMulti)

    } // namespace ImgCodecs
} // namespace NapiOpenCV