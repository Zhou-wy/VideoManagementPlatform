cmake_minimum_required(VERSION 3.20)
project(VideoManPlat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#cmake在编译过程中打印编印信息
set(CMAKE_VERBOSE_MAKEFILEON ON)
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

# 设置输出bin文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(QRC_SOURCE_FILES src/resource.qrc src/qss.qrc)
# find QT5
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.8_1/lib/cmake/Qt5")
# Qt5
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

# find ffmpeg
set(FFMPEG_DIR ${CMAKE_SOURCE_DIR}/3rdparty/ffmpeg4.4.3/macos) # FFmpeg的安装目录，可以通过命令"brew info ffmpeg"获取

include_directories(${FFMPEG_DIR}/include) # 头文件搜索路径
link_directories(${FFMPEG_DIR}/lib) # 动态链接库或静态链接库的搜索路径


add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp ${QRC_FILES} )

target_link_libraries(${PROJECT_NAME} vidManPlatUi
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        avcodec)

# 单元测试
add_subdirectory(test)
enable_testing()
#add_executable(test_ffmpeg test/testFFmpeg.cpp)
add_test(NAME test_ffmpeg
        COMMAND ${CMAKE_SOURCE_DIR}/bin/test_ffmpeg)