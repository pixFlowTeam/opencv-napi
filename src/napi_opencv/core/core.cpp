#include "core.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"
#include <opencv2/core.hpp>

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Core
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            // 系统信息函数
            exports.Set("getBuildInformation", Napi::Function::New(env, GetBuildInformation));
            exports.Set("getNumThreads", Napi::Function::New(env, GetNumThreads));
            exports.Set("setNumThreads", Napi::Function::New(env, SetNumThreads));
            exports.Set("getTickCount", Napi::Function::New(env, GetTickCount));
            exports.Set("getTickFrequency", Napi::Function::New(env, GetTickFrequency));
            exports.Set("getVersionMajor", Napi::Function::New(env, GetVersionMajor));
            exports.Set("getVersionMinor", Napi::Function::New(env, GetVersionMinor));
            exports.Set("getVersionRevision", Napi::Function::New(env, GetVersionRevision));

            // 基础数学运算函数
            exports.Set("add", Napi::Function::New(env, Add));
            exports.Set("subtract", Napi::Function::New(env, Subtract));
            exports.Set("multiply", Napi::Function::New(env, Multiply));
            exports.Set("divide", Napi::Function::New(env, Divide));
            exports.Set("absdiff", Napi::Function::New(env, AbsDiff));
            exports.Set("pow", Napi::Function::New(env, Pow));
            exports.Set("sqrt", Napi::Function::New(env, Sqrt));
            exports.Set("exp", Napi::Function::New(env, Exp));
            exports.Set("log", Napi::Function::New(env, Log));

            // 位运算函数
            exports.Set("bitwiseAnd", Napi::Function::New(env, BitwiseAnd));
            exports.Set("bitwiseOr", Napi::Function::New(env, BitwiseOr));
            exports.Set("bitwiseXor", Napi::Function::New(env, BitwiseXor));
            exports.Set("bitwiseNot", Napi::Function::New(env, BitwiseNot));

            // 数组操作函数
            exports.Set("addWeighted", Napi::Function::New(env, AddWeighted));
            exports.Set("minMaxLoc", Napi::Function::New(env, MinMaxLoc));
            exports.Set("minMaxIdx", Napi::Function::New(env, MinMaxIdx));
            exports.Set("findNonZero", Napi::Function::New(env, FindNonZero));
            exports.Set("countNonZero", Napi::Function::New(env, CountNonZero));
            exports.Set("sum", Napi::Function::New(env, Sum));
            exports.Set("mean", Napi::Function::New(env, Mean));
            exports.Set("meanStdDev", Napi::Function::New(env, MeanStdDev));
            exports.Set("normalize", Napi::Function::New(env, Normalize));
            exports.Set("split", Napi::Function::New(env, Split));
            exports.Set("merge", Napi::Function::New(env, Merge));
            exports.Set("convertScaleAbs", Napi::Function::New(env, ConvertScaleAbs));
            exports.Set("transform", Napi::Function::New(env, Transform));
            exports.Set("perspectiveTransform", Napi::Function::New(env, PerspectiveTransform));
            exports.Set("compare", Napi::Function::New(env, Compare));
            exports.Set("inRange", Napi::Function::New(env, InRange));
            exports.Set("norm", Napi::Function::New(env, Norm));
            exports.Set("calcCovarMatrix", Napi::Function::New(env, CalcCovarMatrix));

            // 随机数生成函数
            exports.Set("randu", Napi::Function::New(env, Randu));
            exports.Set("randn", Napi::Function::New(env, Randn));
            exports.Set("shuffle", Napi::Function::New(env, Shuffle));

            // 矩阵操作函数
            exports.Set("transpose", Napi::Function::New(env, Transpose));
            exports.Set("determinant", Napi::Function::New(env, Determinant));
            exports.Set("trace", Napi::Function::New(env, Trace));
            exports.Set("invert", Napi::Function::New(env, Invert));
            exports.Set("gemm", Napi::Function::New(env, Gemm));

            // 几何变换函数
            exports.Set("cartToPolar", Napi::Function::New(env, CartToPolar));
            exports.Set("polarToCart", Napi::Function::New(env, PolarToCart));
            exports.Set("magnitude", Napi::Function::New(env, Magnitude));

            // 线性代数函数
            exports.Set("solve", Napi::Function::New(env, Solve));
            exports.Set("eigen", Napi::Function::New(env, Eigen));
            exports.Set("min", Napi::Function::New(env, Min));
            exports.Set("max", Napi::Function::New(env, Max));
            exports.Set("reduce", Napi::Function::New(env, Reduce));

            // 图像变换函数
            exports.Set("flip", Napi::Function::New(env, Flip));
            exports.Set("copyMakeBorder", Napi::Function::New(env, CopyMakeBorder));

            // 频域变换函数
            exports.Set("dct", Napi::Function::New(env, Dct));
            exports.Set("idct", Napi::Function::New(env, Idct));
            exports.Set("dft", Napi::Function::New(env, Dft));
            exports.Set("idft", Napi::Function::New(env, Idft));
            exports.Set("mulSpectrums", Napi::Function::New(env, MulSpectrums));

            // 聚类和分割函数
            exports.Set("partition", Napi::Function::New(env, Partition));
            exports.Set("kmeans", Napi::Function::New(env, Kmeans));

            exports.Set("checkRange", Napi::Function::New(env, CheckRange));
            exports.Set("completeSymm", Napi::Function::New(env, CompleteSymm));
            exports.Set("fastFree", Napi::Function::New(env, FastFree));
            exports.Set("fastMalloc", Napi::Function::New(env, FastMalloc));
            exports.Set("fileStorageOpen", Napi::Function::New(env, FileStorage_Open));
            exports.Set("fileStorageRead", Napi::Function::New(env, FileStorage_Read));
            exports.Set("fileStorageRelease", Napi::Function::New(env, FileStorage_Release));
            exports.Set("fileStorageWrite", Napi::Function::New(env, FileStorage_Write));
            exports.Set("getOptimalDFTSize", Napi::Function::New(env, GetOptimalDFTSize));
            exports.Set("getThreadNum", Napi::Function::New(env, GetThreadNum));
            exports.Set("mulTransposed", Napi::Function::New(env, MulTransposed));
            exports.Set("patchNaNs", Napi::Function::New(env, PatchNaNs));
            exports.Set("phase", Napi::Function::New(env, Phase));
            exports.Set("rngGaussian", Napi::Function::New(env, RNG_Gaussian));
            exports.Set("rngUniform", Napi::Function::New(env, RNG_Uniform));
            exports.Set("redirectError", Napi::Function::New(env, RedirectError));
            exports.Set("repeat", Napi::Function::New(env, Repeat));
            exports.Set("svdBackSubst", Napi::Function::New(env, SVD_BackSubst));
            exports.Set("svdCompute", Napi::Function::New(env, SVD_Compute));
            exports.Set("svdSolveZ", Napi::Function::New(env, SVD_SolveZ));
            exports.Set("setBreakOnError", Napi::Function::New(env, SetBreakOnError));
            exports.Set("setIdentity", Napi::Function::New(env, SetIdentity));
            exports.Set("setRNGSeed", Napi::Function::New(env, SetRNGSeed));
            exports.Set("setUseOptimized", Napi::Function::New(env, SetUseOptimized));
            exports.Set("theRNG", Napi::Function::New(env, TheRNG));
            exports.Set("useOptimized", Napi::Function::New(env, UseOptimized));
        }

        // ==================== 系统信息函数实现 ====================

        Napi::Value GetBuildInformation(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<std::string>::ToNapi(info.Env(), cv::getBuildInformation()); });
        }

        Napi::Value GetNumThreads(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<int>::ToNapi(info.Env(), cv::getNumThreads()); });
        }

        Napi::Value SetNumThreads(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            {
            if (info.Length() < 1 || !info[0].IsNumber()) {
                throw Napi::TypeError::New(info.Env(), "期望数字参数");
            }
            
            int nthreads = info[0].As<Napi::Number>().Int32Value();
            cv::setNumThreads(nthreads);
            return info.Env().Undefined(); });
        }

        Napi::Value GetTickCount(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<int64_t>::ToNapi(info.Env(), cv::getTickCount()); });
        }

        Napi::Value GetTickFrequency(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<double>::ToNapi(info.Env(), cv::getTickFrequency()); });
        }

        Napi::Value GetVersionMajor(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<int>::ToNapi(info.Env(), CV_VERSION_MAJOR); });
        }

        Napi::Value GetVersionMinor(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<int>::ToNapi(info.Env(), CV_VERSION_MINOR); });
        }

        Napi::Value GetVersionRevision(const Napi::CallbackInfo &info)
        {
            return SafeCall(info.Env(), [&]()
                            { return TypeConverter<int>::ToNapi(info.Env(), CV_VERSION_REVISION); });
        }

        // ==================== 占位符实现 ====================
        // 这些函数暂时只抛出"未实现"错误，后续可以逐步实现

        Napi::Value Add(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Add 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Subtract(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Subtract 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Multiply(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Multiply 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Divide(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Divide 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value AbsDiff(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "AbsDiff 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Pow(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Pow 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Sqrt(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Sqrt 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Exp(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Exp 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value Log(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "Log 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value BitwiseAnd(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "BitwiseAnd 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value BitwiseOr(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "BitwiseOr 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value BitwiseXor(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "BitwiseXor 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        Napi::Value BitwiseNot(const Napi::CallbackInfo &info)
        {
            Napi::Error::New(info.Env(), "BitwiseNot 函数尚未实现").ThrowAsJavaScriptException();
            return info.Env().Undefined();
        }

        // 继续其他函数的占位符实现...
        // 为了简洁，我只实现几个关键函数，其他的都返回"尚未实现"

#define PLACEHOLDER_IMPL(func_name)                                                            \
    Napi::Value func_name(const Napi::CallbackInfo &info)                                      \
    {                                                                                          \
        Napi::Error::New(info.Env(), #func_name " 函数尚未实现").ThrowAsJavaScriptException(); \
        return info.Env().Undefined();                                                         \
    }

        PLACEHOLDER_IMPL(AddWeighted)
        PLACEHOLDER_IMPL(MinMaxLoc)
        PLACEHOLDER_IMPL(MinMaxIdx)
        PLACEHOLDER_IMPL(FindNonZero)
        PLACEHOLDER_IMPL(CountNonZero)
        PLACEHOLDER_IMPL(Sum)
        PLACEHOLDER_IMPL(Mean)
        PLACEHOLDER_IMPL(MeanStdDev)
        PLACEHOLDER_IMPL(Normalize)
        PLACEHOLDER_IMPL(Split)
        PLACEHOLDER_IMPL(Merge)
        PLACEHOLDER_IMPL(ConvertScaleAbs)
        PLACEHOLDER_IMPL(Transform)
        PLACEHOLDER_IMPL(PerspectiveTransform)
        PLACEHOLDER_IMPL(Compare)
        PLACEHOLDER_IMPL(InRange)
        PLACEHOLDER_IMPL(Norm)
        PLACEHOLDER_IMPL(CalcCovarMatrix)
        PLACEHOLDER_IMPL(Randu)
        PLACEHOLDER_IMPL(Randn)
        PLACEHOLDER_IMPL(Shuffle)
        PLACEHOLDER_IMPL(Transpose)
        PLACEHOLDER_IMPL(Determinant)
        PLACEHOLDER_IMPL(Trace)
        PLACEHOLDER_IMPL(Invert)
        PLACEHOLDER_IMPL(Gemm)
        PLACEHOLDER_IMPL(CartToPolar)
        PLACEHOLDER_IMPL(PolarToCart)
        PLACEHOLDER_IMPL(Magnitude)
        PLACEHOLDER_IMPL(Solve)
        PLACEHOLDER_IMPL(Eigen)
        PLACEHOLDER_IMPL(Min)
        PLACEHOLDER_IMPL(Max)
        PLACEHOLDER_IMPL(Reduce)
        PLACEHOLDER_IMPL(Flip)
        PLACEHOLDER_IMPL(CopyMakeBorder)
        PLACEHOLDER_IMPL(Dct)
        PLACEHOLDER_IMPL(Idct)
        PLACEHOLDER_IMPL(Dft)
        PLACEHOLDER_IMPL(Idft)
        PLACEHOLDER_IMPL(MulSpectrums)
        PLACEHOLDER_IMPL(Partition)
        PLACEHOLDER_IMPL(Kmeans)

        PLACEHOLDER_IMPL(CheckRange)
        PLACEHOLDER_IMPL(CompleteSymm)
        PLACEHOLDER_IMPL(FastFree)
        PLACEHOLDER_IMPL(FastMalloc)
        PLACEHOLDER_IMPL(FileStorage_Open)
        PLACEHOLDER_IMPL(FileStorage_Read)
        PLACEHOLDER_IMPL(FileStorage_Release)
        PLACEHOLDER_IMPL(FileStorage_Write)
        PLACEHOLDER_IMPL(GetOptimalDFTSize)
        PLACEHOLDER_IMPL(GetThreadNum)
        PLACEHOLDER_IMPL(MulTransposed)
        PLACEHOLDER_IMPL(PatchNaNs)
        PLACEHOLDER_IMPL(Phase)
        PLACEHOLDER_IMPL(RNG_Gaussian)
        PLACEHOLDER_IMPL(RNG_Uniform)
        PLACEHOLDER_IMPL(RedirectError)
        PLACEHOLDER_IMPL(Repeat)
        PLACEHOLDER_IMPL(SVD_BackSubst)
        PLACEHOLDER_IMPL(SVD_Compute)
        PLACEHOLDER_IMPL(SVD_SolveZ)
        PLACEHOLDER_IMPL(SetBreakOnError)
        PLACEHOLDER_IMPL(SetIdentity)
        PLACEHOLDER_IMPL(SetRNGSeed)
        PLACEHOLDER_IMPL(SetUseOptimized)
        PLACEHOLDER_IMPL(TheRNG)
        PLACEHOLDER_IMPL(UseOptimized)

    } // namespace Core
} // namespace NapiOpenCV