project(test_ffmpeg)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)

##################### find ffmpeg start #################################
set(FFMPEG_DIR ${CMAKE_SOURCE_DIR}/3rdparty/ffmpeg4.4.3/macos) # FFmpeg的安装目录，可以通过命令"brew info ffmpeg"获取

include_directories(${FFMPEG_DIR}/include) # 头文件搜索路径
link_directories(${FFMPEG_DIR}/lib) # 动态链接库或静态链接库的搜索路径
##################### find ffmpeg finish #################################

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} testFFmpeg.cpp)

target_link_libraries(${PROJECT_NAME}
                        avcodec avformat avutil avfilter)

add_test(NAME test_ffmpeg
        COMMAND ${CMAKE_SOURCE_DIR}/bin/test_ffmpeg)