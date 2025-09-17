#ifndef NAPI_OPENCV_TYPE_CONVERTERS_H
#define NAPI_OPENCV_TYPE_CONVERTERS_H

#include <napi.h>
#include <opencv2/core.hpp>
#include <memory>
#include <string>
#include <vector>

namespace NapiOpenCV {
namespace Common {

    // 基础类型转换器模板类
    template <typename T>
    class TypeConverter
    {
    public:
        static Napi::Value ToNapi(Napi::Env env, const T &value);
        static T FromNapi(Napi::Value value);
    };

    // 基础类型特化声明
    template <>
    Napi::Value TypeConverter<int>::ToNapi(Napi::Env env, const int &value);
    
    template <>
    int TypeConverter<int>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<double>::ToNapi(Napi::Env env, const double &value);
    
    template <>
    double TypeConverter<double>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<std::string>::ToNapi(Napi::Env env, const std::string &value);
    
    template <>
    std::string TypeConverter<std::string>::FromNapi(Napi::Value value);

    // OpenCV 类型特化声明
    template <>
    Napi::Value TypeConverter<cv::Mat>::ToNapi(Napi::Env env, const cv::Mat &mat);

    template <>
    cv::Mat TypeConverter<cv::Mat>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<cv::Point2f>::ToNapi(Napi::Env env, const cv::Point2f &point);

    template <>
    cv::Point2f TypeConverter<cv::Point2f>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<cv::Rect>::ToNapi(Napi::Env env, const cv::Rect &rect);

    template <>
    cv::Rect TypeConverter<cv::Rect>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<cv::Size>::ToNapi(Napi::Env env, const cv::Size &size);

    template <>
    cv::Size TypeConverter<cv::Size>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<cv::Scalar>::ToNapi(Napi::Env env, const cv::Scalar &scalar);

    template <>
    cv::Scalar TypeConverter<cv::Scalar>::FromNapi(Napi::Value value);

    // 容器类型特化声明
    template <>
    Napi::Value TypeConverter<std::vector<cv::Point2f>>::ToNapi(Napi::Env env, const std::vector<cv::Point2f> &points);

    template <>
    std::vector<cv::Point2f> TypeConverter<std::vector<cv::Point2f>>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<std::vector<cv::Rect>>::ToNapi(Napi::Env env, const std::vector<cv::Rect> &rects);

    template <>
    std::vector<cv::Rect> TypeConverter<std::vector<cv::Rect>>::FromNapi(Napi::Value value);

    template <>
    Napi::Value TypeConverter<int64_t>::ToNapi(Napi::Env env, const int64_t &value);

    template <>
    int64_t TypeConverter<int64_t>::FromNapi(Napi::Value value);

} // namespace Common
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_TYPE_CONVERTERS_H