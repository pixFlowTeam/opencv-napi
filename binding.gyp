{
  "targets": [
    {
      "target_name": "opencv_napi",
      "sources": [
        "src/addon.cpp",
        "src/napi_opencv/napi_opencv.cpp",
        "src/napi_opencv/common/type_converters.cpp",
        "src/napi_opencv/core/core.cpp",
        "src/napi_opencv/imgproc/imgproc.cpp",
        "src/napi_opencv/imgcodecs/imgcodecs.cpp",
        "src/napi_opencv/objdetect/objdetect.cpp",
        "src/napi_opencv/features2d/features2d.cpp",
        "src/napi_opencv/photo/photo.cpp",
        "src/napi_opencv/calib3d/calib3d.cpp",
        "src/napi_opencv/flann/flann.cpp",
        "src/napi_opencv/videoio/videoio.cpp",
        "src/napi_opencv/gapi/gapi.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "deps/OpenCV-Source/opencv-4.12.0/modules/core/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/imgproc/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/imgcodecs/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/objdetect/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/features2d/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/photo/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/calib3d/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/flann/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/videoio/include",
        "deps/OpenCV-Source/opencv-4.12.0/modules/gapi/include",
        "deps/OpenCV-Source/opencv-4.12.0/include",
        "deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/include/opencv4",
        "src"
      ],
      "libraries": [
        "-L<(module_root_dir)/deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib",
        "-lopencv_world",
        "-L<(module_root_dir)/deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib/opencv4/3rdparty",
        "-llibwebp",
        "-llibpng", 
        "-llibjpeg-turbo",
        "-llibtiff",
        "-llibopenjp2",
        "-lade",
        "-lzlib",
        "-littnotify"
      ],
      "library_dirs": [
        "<(module_root_dir)/deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib"
      ],
      "cflags": [
        "-std=c++17",
        "-Wall",
        "-Wextra"
      ],
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-rtti",
        "-fno-exceptions"
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ],
      "xcode_settings": {
        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "11.0",
        "LD_RUNPATH_SEARCH_PATHS": [
          "<(module_root_dir)/deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib"
        ],
        "OTHER_LDFLAGS": [
          "-Wl,-rpath,<(module_root_dir)/deps/OpenCV-Source/opencv-4.12.0/build/darwin-arm64/lib",
          "-Wl,-install_name,@rpath/libopencv_world.4.12.0.dylib"
        ]
      },
      "conditions": [
        ["OS==\"win\"", {
          "defines": [
            "_HAS_EXCEPTIONS=1"
          ],
          "msvs_settings": {
            "VCCLCompilerTool": {
              "ExceptionHandling": "2"
            }
          }
        }]
      ]
    }
  ]
}
