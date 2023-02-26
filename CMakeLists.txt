cmake_minimum_required(VERSION 3.15)
project(VideoManPlat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#cmake在编译过程中打印编印信息
set(CMAKE_VERBOSE_MAKEFILEON ON)
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
#set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -fPIC -ggdb -std=c++11 -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

# 设置输出bin文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 判断操作系统
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux ")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "current platform: MacOS")
else()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif()

# 导入第三方库
include(cmake/findQt5.cmake) # Qt5
include(cmake/findFFmpeg.cmake) # FFmpeg
include(cmake/findBoost.cmake)
include(cmake/findYaml.cmake)

# 导入QT中的资源文件
set(QRC_SOURCE_FILES src/resource.qrc src/qss.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp ${QRC_FILES} )

target_link_libraries(${PROJECT_NAME} vidManPlatUi
        ${Qt5_Libs} # 定义在 findQt5.cmake 中
        )

# 单元测试
#add_subdirectory(test)
#enable_testing()
#add_test(NAME test_ffmpeg COMMAND ${CMAKE_SOURCE_DIR}/bin/test_ffmpeg)