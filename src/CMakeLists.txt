cmake_minimum_required(VERSION 3.17)
project(vidManPlatUi)

# find QT5
include(${CMAKE_SOURCE_DIR}/cmake/findQt5.cmake)

add_subdirectory(cpuMonitor)
add_subdirectory(iconHelper)
add_subdirectory(videoPanel)
add_subdirectory(playFFmpeg)
add_subdirectory(addVideoDevice)

set(EXTRA_LIBS ${EXTRA_LIBS} CpuMonitor IconHelper VideoPanel PlayFFmpeg addVideo)

#qt_add_resources(resource.qrc)
add_library(${PROJECT_NAME} sevimanplat.cpp sevimanplat.h sevimanplat.ui resource.qrc)

target_link_libraries(${PROJECT_NAME}
        ${Qt5_Libs}
        ${EXTRA_LIBS}
        )