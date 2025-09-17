#include "gapi.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Gapi
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("gcomputation_create", Napi::Function::New(env, GComputation_Create));
            exports.Set("gcomputation_apply", Napi::Function::New(env, GComputation_Apply));
            exports.Set("gcomputation_applywithargs", Napi::Function::New(env, GComputation_ApplyWithArgs));
            exports.Set("gcomputation_compile", Napi::Function::New(env, GComputation_Compile));
            exports.Set("gapiadd", Napi::Function::New(env, GApiAdd));
            exports.Set("gapisubtract", Napi::Function::New(env, GApiSubtract));
            exports.Set("gapimultiply", Napi::Function::New(env, GApiMultiply));
            exports.Set("gapidivide", Napi::Function::New(env, GApiDivide));
            exports.Set("gapiresize", Napi::Function::New(env, GApiResize));
            exports.Set("gapifilter2d", Napi::Function::New(env, GApiFilter2D));
            exports.Set("gapiblur", Napi::Function::New(env, GApiBlur));
            exports.Set("gapicvtcolor", Napi::Function::New(env, GApiCvtColor));
            exports.Set("gapicpu", Napi::Function::New(env, GApiCPU));
            exports.Set("gapiocl", Napi::Function::New(env, GApiOCL));
            exports.Set("gapiie", Napi::Function::New(env, GApiIE));
            exports.Set("gstreamingcompile", Napi::Function::New(env, GStreamingCompile));
            exports.Set("gstreamingapply", Napi::Function::New(env, GStreamingApply));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name) \
        Napi::Value func_name(const Napi::CallbackInfo &info) \
        { \
            throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
        }

        PLACEHOLDER_IMPL(GComputation_Create)
        PLACEHOLDER_IMPL(GComputation_Apply)
        PLACEHOLDER_IMPL(GComputation_ApplyWithArgs)
        PLACEHOLDER_IMPL(GComputation_Compile)
        PLACEHOLDER_IMPL(GApiAdd)
        PLACEHOLDER_IMPL(GApiSubtract)
        PLACEHOLDER_IMPL(GApiMultiply)
        PLACEHOLDER_IMPL(GApiDivide)
        PLACEHOLDER_IMPL(GApiResize)
        PLACEHOLDER_IMPL(GApiFilter2D)
        PLACEHOLDER_IMPL(GApiBlur)
        PLACEHOLDER_IMPL(GApiCvtColor)
        PLACEHOLDER_IMPL(GApiCPU)
        PLACEHOLDER_IMPL(GApiOCL)
        PLACEHOLDER_IMPL(GApiIE)
        PLACEHOLDER_IMPL(GStreamingCompile)
        PLACEHOLDER_IMPL(GStreamingApply)

    } // namespace Gapi
} // namespace NapiOpenCV
