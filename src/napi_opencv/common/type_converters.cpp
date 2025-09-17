#include "type_converters.h"
#include <opencv2/core.hpp>

namespace NapiOpenCV {
namespace Common {

    // 基础类型实现
    template <>
    Napi::Value TypeConverter<int>::ToNapi(Napi::Env env, const int &value)
    {
        return Napi::Number::New(env, value);
    }

    template <>
    int TypeConverter<int>::FromNapi(Napi::Value value)
    {
        return value.As<Napi::Number>().Int32Value();
    }

    template <>
    Napi::Value TypeConverter<double>::ToNapi(Napi::Env env, const double &value)
    {
        return Napi::Number::New(env, value);
    }

    template <>
    double TypeConverter<double>::FromNapi(Napi::Value value)
    {
        return value.As<Napi::Number>().DoubleValue();
    }

    template <>
    Napi::Value TypeConverter<std::string>::ToNapi(Napi::Env env, const std::string &value)
    {
        return Napi::String::New(env, value);
    }

    template <>
    std::string TypeConverter<std::string>::FromNapi(Napi::Value value)
    {
        return value.As<Napi::String>().Utf8Value();
    }

    // Mat 类型转换器实现
    template <>
    Napi::Value TypeConverter<cv::Mat>::ToNapi(Napi::Env env, const cv::Mat &mat)
    {
        Napi::Object matObj = Napi::Object::New(env);

        matObj.Set("rows", Napi::Number::New(env, mat.rows));
        matObj.Set("cols", Napi::Number::New(env, mat.cols));
        matObj.Set("channels", Napi::Number::New(env, mat.channels()));
        matObj.Set("type", Napi::Number::New(env, mat.type()));
        matObj.Set("depth", Napi::Number::New(env, mat.depth()));
        matObj.Set("dims", Napi::Number::New(env, mat.dims));
        matObj.Set("empty", Napi::Boolean::New(env, mat.empty()));
        matObj.Set("elemSize", Napi::Number::New(env, mat.elemSize()));
        matObj.Set("step", Napi::Number::New(env, mat.step[0]));

        if (!mat.empty())
        {
            size_t dataSize = mat.total() * mat.elemSize();
            Napi::Buffer<uint8_t> buffer = Napi::Buffer<uint8_t>::New(env, dataSize);
            memcpy(buffer.Data(), mat.data, dataSize);
            matObj.Set("data", buffer);
        }

        return matObj;
    }

    template <>
    cv::Mat TypeConverter<cv::Mat>::FromNapi(Napi::Value value)
    {
        if (!value.IsObject())
        {
            throw std::invalid_argument("期望 Mat 对象");
        }

        Napi::Object matObj = value.As<Napi::Object>();

        int rows = matObj.Get("rows").As<Napi::Number>().Int32Value();
        int cols = matObj.Get("cols").As<Napi::Number>().Int32Value();
        int type = matObj.Get("type").As<Napi::Number>().Int32Value();

        cv::Mat mat(rows, cols, type);

        if (matObj.Has("data"))
        {
            Napi::Buffer<uint8_t> buffer = matObj.Get("data").As<Napi::Buffer<uint8_t>>();
            memcpy(mat.data, buffer.Data(), buffer.Length());
        }

        return mat;
    }

    // Point2f 类型转换器实现
    template <>
    Napi::Value TypeConverter<cv::Point2f>::ToNapi(Napi::Env env, const cv::Point2f &point)
    {
        Napi::Object pointObj = Napi::Object::New(env);
        pointObj.Set("x", Napi::Number::New(env, point.x));
        pointObj.Set("y", Napi::Number::New(env, point.y));
        return pointObj;
    }

    template <>
    cv::Point2f TypeConverter<cv::Point2f>::FromNapi(Napi::Value value)
    {
        if (!value.IsObject())
        {
            throw std::invalid_argument("期望 Point 对象");
        }

        Napi::Object pointObj = value.As<Napi::Object>();
        float x = pointObj.Get("x").As<Napi::Number>().FloatValue();
        float y = pointObj.Get("y").As<Napi::Number>().FloatValue();

        return cv::Point2f(x, y);
    }

    // Rect 类型转换器实现
    template <>
    Napi::Value TypeConverter<cv::Rect>::ToNapi(Napi::Env env, const cv::Rect &rect)
    {
        Napi::Object rectObj = Napi::Object::New(env);
        rectObj.Set("x", Napi::Number::New(env, rect.x));
        rectObj.Set("y", Napi::Number::New(env, rect.y));
        rectObj.Set("width", Napi::Number::New(env, rect.width));
        rectObj.Set("height", Napi::Number::New(env, rect.height));
        return rectObj;
    }

    template <>
    cv::Rect TypeConverter<cv::Rect>::FromNapi(Napi::Value value)
    {
        if (!value.IsObject())
        {
            throw std::invalid_argument("期望 Rect 对象");
        }

        Napi::Object rectObj = value.As<Napi::Object>();
        int x = rectObj.Get("x").As<Napi::Number>().Int32Value();
        int y = rectObj.Get("y").As<Napi::Number>().Int32Value();
        int width = rectObj.Get("width").As<Napi::Number>().Int32Value();
        int height = rectObj.Get("height").As<Napi::Number>().Int32Value();

        return cv::Rect(x, y, width, height);
    }

    // Size 类型转换器实现
    template <>
    Napi::Value TypeConverter<cv::Size>::ToNapi(Napi::Env env, const cv::Size &size)
    {
        Napi::Object sizeObj = Napi::Object::New(env);
        sizeObj.Set("width", Napi::Number::New(env, size.width));
        sizeObj.Set("height", Napi::Number::New(env, size.height));
        return sizeObj;
    }

    template <>
    cv::Size TypeConverter<cv::Size>::FromNapi(Napi::Value value)
    {
        if (!value.IsObject())
        {
            throw std::invalid_argument("期望 Size 对象");
        }

        Napi::Object sizeObj = value.As<Napi::Object>();
        int width = sizeObj.Get("width").As<Napi::Number>().Int32Value();
        int height = sizeObj.Get("height").As<Napi::Number>().Int32Value();

        return cv::Size(width, height);
    }

    // Scalar 类型转换器实现
    template <>
    Napi::Value TypeConverter<cv::Scalar>::ToNapi(Napi::Env env, const cv::Scalar &scalar)
    {
        Napi::Array scalarArray = Napi::Array::New(env, 4);
        scalarArray.Set(0u, Napi::Number::New(env, scalar[0]));
        scalarArray.Set(1u, Napi::Number::New(env, scalar[1]));
        scalarArray.Set(2u, Napi::Number::New(env, scalar[2]));
        scalarArray.Set(3u, Napi::Number::New(env, scalar[3]));
        return scalarArray;
    }

    template <>
    cv::Scalar TypeConverter<cv::Scalar>::FromNapi(Napi::Value value)
    {
        if (value.IsArray())
        {
            Napi::Array array = value.As<Napi::Array>();
            uint32_t length = array.Length();
            if (length >= 1) {
                double v0 = array.Get(0u).As<Napi::Number>().DoubleValue();
                double v1 = length > 1 ? array.Get(1u).As<Napi::Number>().DoubleValue() : 0;
                double v2 = length > 2 ? array.Get(2u).As<Napi::Number>().DoubleValue() : 0;
                double v3 = length > 3 ? array.Get(3u).As<Napi::Number>().DoubleValue() : 0;
                return cv::Scalar(v0, v1, v2, v3);
            }
        }
        else if (value.IsNumber())
        {
            double v = value.As<Napi::Number>().DoubleValue();
            return cv::Scalar(v);
        }
        
        throw std::invalid_argument("期望 Scalar 数组或数字");
    }

    // vector<Point2f> 类型转换器实现
    template <>
    Napi::Value TypeConverter<std::vector<cv::Point2f>>::ToNapi(Napi::Env env, const std::vector<cv::Point2f> &points)
    {
        Napi::Array pointsArray = Napi::Array::New(env, points.size());
        for (size_t i = 0; i < points.size(); i++)
        {
            pointsArray.Set(i, TypeConverter<cv::Point2f>::ToNapi(env, points[i]));
        }
        return pointsArray;
    }

    template <>
    std::vector<cv::Point2f> TypeConverter<std::vector<cv::Point2f>>::FromNapi(Napi::Value value)
    {
        if (!value.IsArray())
        {
            throw std::invalid_argument("期望 Point2f 数组");
        }

        Napi::Array array = value.As<Napi::Array>();
        std::vector<cv::Point2f> points;
        points.reserve(array.Length());

        for (uint32_t i = 0; i < array.Length(); i++)
        {
            points.push_back(TypeConverter<cv::Point2f>::FromNapi(array.Get(i)));
        }

        return points;
    }

    // vector<Rect> 类型转换器实现
    template <>
    Napi::Value TypeConverter<std::vector<cv::Rect>>::ToNapi(Napi::Env env, const std::vector<cv::Rect> &rects)
    {
        Napi::Array rectsArray = Napi::Array::New(env, rects.size());
        for (size_t i = 0; i < rects.size(); i++)
        {
            rectsArray.Set(i, TypeConverter<cv::Rect>::ToNapi(env, rects[i]));
        }
        return rectsArray;
    }

    template <>
    std::vector<cv::Rect> TypeConverter<std::vector<cv::Rect>>::FromNapi(Napi::Value value)
    {
        if (!value.IsArray())
        {
            throw std::invalid_argument("期望 Rect 数组");
        }

        Napi::Array array = value.As<Napi::Array>();
        std::vector<cv::Rect> rects;
        rects.reserve(array.Length());

        for (uint32_t i = 0; i < array.Length(); i++)
        {
            rects.push_back(TypeConverter<cv::Rect>::FromNapi(array.Get(i)));
        }

        return rects;
    }

    // int64_t 类型转换器实现
    template <>
    Napi::Value TypeConverter<int64_t>::ToNapi(Napi::Env env, const int64_t &value)
    {
        return Napi::Number::New(env, static_cast<double>(value));
    }

    template <>
    int64_t TypeConverter<int64_t>::FromNapi(Napi::Value value)
    {
        return static_cast<int64_t>(value.As<Napi::Number>().Int64Value());
    }

} // namespace Common
} // namespace NapiOpenCV