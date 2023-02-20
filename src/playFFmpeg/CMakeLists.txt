cmake_minimum_required(VERSION 3.15)
project(PlayFFmpeg)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
file(GLOB CURRENT_SOURCES  *.cpp *.c)

source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${CURRENT_SOURCES})

# find QT5
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

##################### find ffmpeg start #################################
set(FFMPEG_DIR ${CMAKE_SOURCE_DIR}/3rdparty/ffmpeg4.4.3/macos) # FFmpeg的安装目录，可以通过命令"brew info ffmpeg"获取

include_directories(${FFMPEG_DIR}/include) # 头文件搜索路径
link_directories(${FFMPEG_DIR}/lib) # 动态链接库或静态链接库的搜索路径
##################### find ffmpeg finish #################################

# create static library
add_library(${PROJECT_NAME} STATIC ${CURRENT_HEADERS} ${CURRENT_SOURCES})
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        avcodec avformat avutil avfilter swscale)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
