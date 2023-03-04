cmake_minimum_required(VERSION 3.15)
project(VideoManPlat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


#cmake在编译过程中打印编印信息
set(CMAKE_VERBOSE_MAKEFILEON ON)
#set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
#set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
#set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -fPIC -ggdb -std=c++11 -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
set(CMAKE_EXE_LINKER_FLAGS -static)
set(CMAKE_EXE_LINKER_FLAGS -static-libgcc)
#set(CMAKE_EXE_LINKER_FLAGS -static-libg++)

# 设置输出bin文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -G Unix Makefiles")
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
include(${CMAKE_SOURCE_DIR}/cmake/3drparty.cmake)

# 导入QT中的资源文件
set(QRC_SOURCE_FILES src/resource.qrc src/qss.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
set(EXTRA_LIBS ${EXTRA_LIBS} utils IconHelper VideoPanel PlayFFmpeg addVideo)
set(3rdParty_LIBS ${3rdParty_LIBS})

add_executable(${PROJECT_NAME} main.cpp ${QRC_FILES} )

target_link_libraries(${PROJECT_NAME} vidManPlatUi
        ${Qt5_Libs}
        ${EXTRA_LIBS}
        ${3rdParty_LIBS}
        )