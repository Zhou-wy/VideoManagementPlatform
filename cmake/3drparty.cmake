
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_PREFIX_PATH "/home/zwy/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5")
    set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/0build-linux)

elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(CMAKE_PREFIX_PATH "D:/Qt5.12.5/5.12.5/msvc2017_64")
    set(FFMPEG_DIR ${PROJECT_SOURCE_DIR}/3rdparty/ffmpeg4)
    set(QUCSDK_DIR ${PROJECT_SOURCE_DIR}/3rdparty/qucsdk)
    set(SPDLOG_DIR ${PROJECT_SOURCE_DIR}/3rdparty/spdlog)


elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")
    set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/0build-mac)

else ()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif ()
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
set(Qt5_Libs Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

include_directories(${FFMPEG_DIR}/include) # FFMPEG头文件搜索路径
include_directories(${SPDLOG_DIR}/include) # gLog头文件搜索路径
include_directories(${QUCSDK_DIR}/include) # qucsdk头文件搜索路径


link_directories(${FFMPEG_DIR}/lib) # FFMPEG动态链接库或静态链接库的搜索路径
link_directories(${SPDLOG_DIR}/lib) # gLog动态链接库或静态链接库的搜索路径
link_directories(${QUCSDK_DIR}/lib) # qucsdk动态链接库或静态链接库的搜索路径