#ifndef NAPI_OPENCV_SAFE_CALL_H
#define NAPI_OPENCV_SAFE_CALL_H

#include <napi.h>
#include <opencv2/core.hpp>
#include <string>

namespace NapiOpenCV {
namespace Common {

    // OpenCV 错误处理类
    class OpenCVError : public std::exception
    {
    public:
        OpenCVError(const std::string &message) : message_(message) {}
        const char *what() const noexcept override { return message_.c_str(); }

    private:
        std::string message_;
    };

    // 异常安全包装器
    template <typename Func>
    auto SafeCall(Napi::Env env, Func &&func) -> decltype(func())
    {
        try
        {
            return func();
        }
        catch (const cv::Exception &e)
        {
            throw Napi::Error::New(env, "OpenCV 错误: " + std::string(e.what()));
        }
        catch (const std::exception &e)
        {
            throw Napi::Error::New(env, "错误: " + std::string(e.what()));
        }
        catch (...)
        {
            throw Napi::Error::New(env, "发生未知错误");
        }
    }

} // namespace Common
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_SAFE_CALL_H