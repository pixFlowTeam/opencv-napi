#ifndef NAPI_OPENCV_CORE_H
#define NAPI_OPENCV_CORE_H

#include <napi.h>

namespace NapiOpenCV {
namespace Core {

    // 注册所有Core模块函数
    void RegisterFunctions(Napi::Env env, Napi::Object exports);

    // ==================== 系统信息函数 ====================
    Napi::Value GetBuildInformation(const Napi::CallbackInfo &info);
    Napi::Value GetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value SetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value GetTickCount(const Napi::CallbackInfo &info);
    Napi::Value GetTickFrequency(const Napi::CallbackInfo &info);
    Napi::Value GetVersionMajor(const Napi::CallbackInfo &info);
    Napi::Value GetVersionMinor(const Napi::CallbackInfo &info);
    Napi::Value GetVersionRevision(const Napi::CallbackInfo &info);

    // ==================== 基础数学运算函数 ====================
    Napi::Value Add(const Napi::CallbackInfo &info);
    Napi::Value Subtract(const Napi::CallbackInfo &info);
    Napi::Value Multiply(const Napi::CallbackInfo &info);
    Napi::Value Divide(const Napi::CallbackInfo &info);
    Napi::Value AbsDiff(const Napi::CallbackInfo &info);
    Napi::Value Pow(const Napi::CallbackInfo &info);
    Napi::Value Sqrt(const Napi::CallbackInfo &info);
    Napi::Value Exp(const Napi::CallbackInfo &info);
    Napi::Value Log(const Napi::CallbackInfo &info);
    Napi::Value Phase(const Napi::CallbackInfo &info);

    // ==================== 位运算函数 ====================
    Napi::Value BitwiseAnd(const Napi::CallbackInfo &info);
    Napi::Value BitwiseOr(const Napi::CallbackInfo &info);
    Napi::Value BitwiseXor(const Napi::CallbackInfo &info);
    Napi::Value BitwiseNot(const Napi::CallbackInfo &info);

    // ==================== 数组操作函数 ====================
    Napi::Value AddWeighted(const Napi::CallbackInfo &info);
    Napi::Value MinMaxLoc(const Napi::CallbackInfo &info);
    Napi::Value MinMaxIdx(const Napi::CallbackInfo &info);
    Napi::Value FindNonZero(const Napi::CallbackInfo &info);
    Napi::Value CountNonZero(const Napi::CallbackInfo &info);
    Napi::Value Sum(const Napi::CallbackInfo &info);
    Napi::Value Mean(const Napi::CallbackInfo &info);
    Napi::Value MeanStdDev(const Napi::CallbackInfo &info);
    Napi::Value Normalize(const Napi::CallbackInfo &info);
    Napi::Value Split(const Napi::CallbackInfo &info);
    Napi::Value Merge(const Napi::CallbackInfo &info);
    Napi::Value ConvertScaleAbs(const Napi::CallbackInfo &info);
    Napi::Value Transform(const Napi::CallbackInfo &info);
    Napi::Value PerspectiveTransform(const Napi::CallbackInfo &info);
    Napi::Value Compare(const Napi::CallbackInfo &info);
    Napi::Value InRange(const Napi::CallbackInfo &info);
    Napi::Value Norm(const Napi::CallbackInfo &info);
    Napi::Value CalcCovarMatrix(const Napi::CallbackInfo &info);
    Napi::Value SetIdentity(const Napi::CallbackInfo &info);
    Napi::Value CheckRange(const Napi::CallbackInfo &info);
    Napi::Value PatchNaNs(const Napi::CallbackInfo &info);
    Napi::Value SetRNGSeed(const Napi::CallbackInfo &info);
    Napi::Value TheRNG(const Napi::CallbackInfo &info);
    Napi::Value RNG_Uniform(const Napi::CallbackInfo &info);
    Napi::Value RNG_Gaussian(const Napi::CallbackInfo &info);

    // ==================== 随机数生成函数 ====================
    Napi::Value Randu(const Napi::CallbackInfo &info);
    Napi::Value Randn(const Napi::CallbackInfo &info);
    Napi::Value Shuffle(const Napi::CallbackInfo &info);

    // ==================== 矩阵操作函数 ====================
    Napi::Value Transpose(const Napi::CallbackInfo &info);
    Napi::Value Determinant(const Napi::CallbackInfo &info);
    Napi::Value Trace(const Napi::CallbackInfo &info);
    Napi::Value Invert(const Napi::CallbackInfo &info);
    Napi::Value Gemm(const Napi::CallbackInfo &info);
    Napi::Value MulTransposed(const Napi::CallbackInfo &info);
    Napi::Value Repeat(const Napi::CallbackInfo &info);
    Napi::Value CompleteSymm(const Napi::CallbackInfo &info);

    // ==================== 几何变换函数 ====================
    Napi::Value CartToPolar(const Napi::CallbackInfo &info);
    Napi::Value PolarToCart(const Napi::CallbackInfo &info);
    Napi::Value Magnitude(const Napi::CallbackInfo &info);

    // ==================== 线性代数函数 ====================
    Napi::Value Solve(const Napi::CallbackInfo &info);
    Napi::Value Eigen(const Napi::CallbackInfo &info);
    Napi::Value Min(const Napi::CallbackInfo &info);
    Napi::Value Max(const Napi::CallbackInfo &info);
    Napi::Value Reduce(const Napi::CallbackInfo &info);

    // ==================== 图像变换函数 ====================
    Napi::Value Flip(const Napi::CallbackInfo &info);
    Napi::Value CopyMakeBorder(const Napi::CallbackInfo &info);

    // ==================== 频域变换函数 ====================
    Napi::Value Dct(const Napi::CallbackInfo &info);
    Napi::Value Idct(const Napi::CallbackInfo &info);
    Napi::Value Dft(const Napi::CallbackInfo &info);
    Napi::Value Idft(const Napi::CallbackInfo &info);
    Napi::Value MulSpectrums(const Napi::CallbackInfo &info);
    Napi::Value GetOptimalDFTSize(const Napi::CallbackInfo &info);

    // ==================== 聚类和分割函数 ====================
    Napi::Value Partition(const Napi::CallbackInfo &info);
    Napi::Value Kmeans(const Napi::CallbackInfo &info);

    // ==================== SVD分解函数 ====================
    Napi::Value SVD_Compute(const Napi::CallbackInfo &info);
    Napi::Value SVD_BackSubst(const Napi::CallbackInfo &info);
    Napi::Value SVD_SolveZ(const Napi::CallbackInfo &info);

    // ==================== 文件存储函数 ====================
    Napi::Value FileStorage_Open(const Napi::CallbackInfo &info);
    Napi::Value FileStorage_Write(const Napi::CallbackInfo &info);
    Napi::Value FileStorage_Read(const Napi::CallbackInfo &info);
    Napi::Value FileStorage_Release(const Napi::CallbackInfo &info);

    // ==================== 内存管理函数 ====================
    Napi::Value FastMalloc(const Napi::CallbackInfo &info);
    Napi::Value FastFree(const Napi::CallbackInfo &info);
    Napi::Value SetUseOptimized(const Napi::CallbackInfo &info);
    Napi::Value UseOptimized(const Napi::CallbackInfo &info);

    // ==================== 并行处理函数 ====================
    Napi::Value SetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value GetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value GetThreadNum(const Napi::CallbackInfo &info);

    // ==================== 错误处理函数 ====================
    Napi::Value SetBreakOnError(const Napi::CallbackInfo &info);
    Napi::Value RedirectError(const Napi::CallbackInfo &info);

} // namespace Core
} // namespace NapiOpenCV

#endif // NAPI_OPENCV_CORE_H