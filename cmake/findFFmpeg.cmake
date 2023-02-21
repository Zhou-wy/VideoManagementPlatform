if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux ")

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")

elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(FFMPEG_DIR ${CMAKE_SOURCE_DIR}/3rdparty/ffmpeg4.4.3/macos) # FFmpeg的安装目录，可以通过命令"brew info ffmpeg"获取
    include_directories(${FFMPEG_DIR}/include) # 头文件搜索路径
    link_directories(${FFMPEG_DIR}/lib) # 动态链接库或静态链接库的搜索路径
else()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif()