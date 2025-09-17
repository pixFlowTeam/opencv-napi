#include <napi.h>
#include "napi_opencv/napi_opencv.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return NapiOpenCV::Init(env, exports);
}

NODE_API_MODULE(opencv_napi, InitAll)
