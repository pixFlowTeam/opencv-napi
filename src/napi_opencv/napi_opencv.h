#ifndef NAPI_OPENCV_MAIN_H
#define NAPI_OPENCV_MAIN_H

#include <napi.h>
#include "common/type_converters.h"
#include "common/safe_call.h"

// 模块头文件
#include "core/core.h"
#include "imgproc/imgproc.h"
#include "imgcodecs/imgcodecs.h"
#include "objdetect/objdetect.h"
#include "features2d/features2d.h"
#include "photo/photo.h"
#include "calib3d/calib3d.h"
#include "flann/flann.h"
#include "videoio/videoio.h"
#include "gapi/gapi.h"

namespace NapiOpenCV
{

    // 主初始化函数
    Napi::Object Init(Napi::Env env, Napi::Object exports);

} // namespace NapiOpenCV

#endif // NAPI_OPENCV_MAIN_H