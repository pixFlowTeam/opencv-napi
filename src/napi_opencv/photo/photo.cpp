#include "photo.h"
#include "../common/safe_call.h"
#include "../common/type_converters.h"

using namespace NapiOpenCV::Common;

namespace NapiOpenCV
{
    namespace Photo
    {

        void RegisterFunctions(Napi::Env env, Napi::Object exports)
        {
            exports.Set("fastnlmeansdenoising", Napi::Function::New(env, FastNlMeansDenoising));
            exports.Set("fastnlmeansdenoisingcolored", Napi::Function::New(env, FastNlMeansDenoisingColored));
            exports.Set("fastnlmeansdenoisingmulti", Napi::Function::New(env, FastNlMeansDenoisingMulti));
            exports.Set("fastnlmeansdenoisingcoloredmulti", Napi::Function::New(env, FastNlMeansDenoisingColoredMulti));
            exports.Set("edgepreservingfilter", Napi::Function::New(env, EdgePreservingFilter));
            exports.Set("detailenhance", Napi::Function::New(env, DetailEnhance));
            exports.Set("stylizationfilter", Napi::Function::New(env, StylizationFilter));
            exports.Set("pencilsketch", Napi::Function::New(env, PencilSketch));
            exports.Set("inpaint", Napi::Function::New(env, Inpaint));
            exports.Set("fastinpaint", Napi::Function::New(env, FastInpaint));
            exports.Set("createcalibratedebevec", Napi::Function::New(env, CreateCalibrateDebevec));
            exports.Set("createcalibraterobertson", Napi::Function::New(env, CreateCalibrateRobertson));
            exports.Set("createmergedebevec", Napi::Function::New(env, CreateMergeDebevec));
            exports.Set("createmergemertens", Napi::Function::New(env, CreateMergeMertens));
            exports.Set("createmergerobertson", Napi::Function::New(env, CreateMergeRobertson));
            exports.Set("createtonemapdrago", Napi::Function::New(env, CreateTonemapDrago));
            exports.Set("createtonemapdurand", Napi::Function::New(env, CreateTonemapDurand));
            exports.Set("createtonemapreinhard", Napi::Function::New(env, CreateTonemapReinhard));
            exports.Set("createtonemapmantiuk", Napi::Function::New(env, CreateTonemapMantiuk));
            exports.Set("seamlessclone", Napi::Function::New(env, SeamlessClone));
            exports.Set("colorchange", Napi::Function::New(env, ColorChange));
            exports.Set("illuminationchange", Napi::Function::New(env, IlluminationChange));
            exports.Set("textureflattening", Napi::Function::New(env, TextureFlattening));
            exports.Set("createalignmtb", Napi::Function::New(env, CreateAlignMTB));
            exports.Set("createsimplewb", Napi::Function::New(env, CreateSimpleWB));
            exports.Set("creategrayworldwb", Napi::Function::New(env, CreateGrayworldWB));
            exports.Set("createlearningbasedwb", Napi::Function::New(env, CreateLearningBasedWB));
            exports.Set("createbrief", Napi::Function::New(env, CreateBRIEF));
            exports.Set("clahe_apply", Napi::Function::New(env, CLAHE_Apply));
            exports.Set("denoisetv2", Napi::Function::New(env, DenoiseTV2));
            exports.Set("denoisebayesian", Napi::Function::New(env, DenoiseBayesian));
        }

        // 占位符实现
#define PLACEHOLDER_IMPL(func_name) \
        Napi::Value func_name(const Napi::CallbackInfo &info) \
        { \
            throw Napi::Error::New(info.Env(), #func_name " 函数尚未实现"); \
        }

        PLACEHOLDER_IMPL(FastNlMeansDenoising)
        PLACEHOLDER_IMPL(FastNlMeansDenoisingColored)
        PLACEHOLDER_IMPL(FastNlMeansDenoisingMulti)
        PLACEHOLDER_IMPL(FastNlMeansDenoisingColoredMulti)
        PLACEHOLDER_IMPL(EdgePreservingFilter)
        PLACEHOLDER_IMPL(DetailEnhance)
        PLACEHOLDER_IMPL(StylizationFilter)
        PLACEHOLDER_IMPL(PencilSketch)
        PLACEHOLDER_IMPL(Inpaint)
        PLACEHOLDER_IMPL(FastInpaint)
        PLACEHOLDER_IMPL(CreateCalibrateDebevec)
        PLACEHOLDER_IMPL(CreateCalibrateRobertson)
        PLACEHOLDER_IMPL(CreateMergeDebevec)
        PLACEHOLDER_IMPL(CreateMergeMertens)
        PLACEHOLDER_IMPL(CreateMergeRobertson)
        PLACEHOLDER_IMPL(CreateTonemapDrago)
        PLACEHOLDER_IMPL(CreateTonemapDurand)
        PLACEHOLDER_IMPL(CreateTonemapReinhard)
        PLACEHOLDER_IMPL(CreateTonemapMantiuk)
        PLACEHOLDER_IMPL(SeamlessClone)
        PLACEHOLDER_IMPL(ColorChange)
        PLACEHOLDER_IMPL(IlluminationChange)
        PLACEHOLDER_IMPL(TextureFlattening)
        PLACEHOLDER_IMPL(CreateAlignMTB)
        PLACEHOLDER_IMPL(CreateSimpleWB)
        PLACEHOLDER_IMPL(CreateGrayworldWB)
        PLACEHOLDER_IMPL(CreateLearningBasedWB)
        PLACEHOLDER_IMPL(CreateBRIEF)
        PLACEHOLDER_IMPL(CLAHE_Apply)
        PLACEHOLDER_IMPL(DenoiseTV2)
        PLACEHOLDER_IMPL(DenoiseBayesian)

    } // namespace Photo
} // namespace NapiOpenCV
