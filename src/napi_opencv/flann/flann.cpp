#include "flann.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Flann
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("index_create", Napi::Function::New(env, Index_Create));
            exports.Set("index_build", Napi::Function::New(env, Index_Build));
            exports.Set("index_knnsearch", Napi::Function::New(env, Index_KnnSearch));
            exports.Set("index_radiussearch", Napi::Function::New(env, Index_RadiusSearch));
            exports.Set("index_save", Napi::Function::New(env, Index_Save));
            exports.Set("index_load", Napi::Function::New(env, Index_Load));
            exports.Set("index_release", Napi::Function::New(env, Index_Release));
            exports.Set("index_getdistance", Napi::Function::New(env, Index_GetDistance));
            exports.Set("index_getalgorithm", Napi::Function::New(env, Index_GetAlgorithm));
            exports.Set("searchparams_create", Napi::Function::New(env, SearchParams_Create));
            exports.Set("searchparams_setchecks", Napi::Function::New(env, SearchParams_SetChecks));
            exports.Set("searchparams_seteps", Napi::Function::New(env, SearchParams_SetEps));
            exports.Set("searchparams_setsorted", Napi::Function::New(env, SearchParams_SetSorted));
            exports.Set("linearindexparams_create", Napi::Function::New(env, LinearIndexParams_Create));
            exports.Set("kdtreeindexparams_create", Napi::Function::New(env, KDTreeIndexParams_Create));
            exports.Set("kmeansindexparams_create", Napi::Function::New(env, KMeansIndexParams_Create));
            exports.Set("compositeindexparams_create", Napi::Function::New(env, CompositeIndexParams_Create));
            exports.Set("autotunedindexparams_create", Napi::Function::New(env, AutotunedIndexParams_Create));
            exports.Set("savedindexparams_create", Napi::Function::New(env, SavedIndexParams_Create));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name) \
        Napi::Value func_name(const Napi::CallbackInfo &info) \
        { \
            throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
        }

        PLACEHOLDER_IMPL(Index_Create)
        PLACEHOLDER_IMPL(Index_Build)
        PLACEHOLDER_IMPL(Index_KnnSearch)
        PLACEHOLDER_IMPL(Index_RadiusSearch)
        PLACEHOLDER_IMPL(Index_Save)
        PLACEHOLDER_IMPL(Index_Load)
        PLACEHOLDER_IMPL(Index_Release)
        PLACEHOLDER_IMPL(Index_GetDistance)
        PLACEHOLDER_IMPL(Index_GetAlgorithm)
        PLACEHOLDER_IMPL(SearchParams_Create)
        PLACEHOLDER_IMPL(SearchParams_SetChecks)
        PLACEHOLDER_IMPL(SearchParams_SetEps)
        PLACEHOLDER_IMPL(SearchParams_SetSorted)
        PLACEHOLDER_IMPL(LinearIndexParams_Create)
        PLACEHOLDER_IMPL(KDTreeIndexParams_Create)
        PLACEHOLDER_IMPL(KMeansIndexParams_Create)
        PLACEHOLDER_IMPL(CompositeIndexParams_Create)
        PLACEHOLDER_IMPL(AutotunedIndexParams_Create)
        PLACEHOLDER_IMPL(SavedIndexParams_Create)

    } // namespace Flann
} // namespace NapiOpenCV
