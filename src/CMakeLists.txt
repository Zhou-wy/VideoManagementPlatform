cmake_minimum_required(VERSION 3.17)
project(vidManPlatUi)

# find
include(${CMAKE_SOURCE_DIR}/cmake/3drparty.cmake)

add_subdirectory(utils)
add_subdirectory(iconHelper)
add_subdirectory(videoPanel)
add_subdirectory(playFFmpeg)
add_subdirectory(addVideoDevice)
set(CMAKE_EXE_LINKER_FLAGS "-SHARED")

set(EXTRA_LIBS ${EXTRA_LIBS} utils IconHelper VideoPanel PlayFFmpeg addVideo)

#qt_add_resources(resource.qrc)
add_library(${PROJECT_NAME} sevimanplat_1.cpp sevimanplat.h sevimanplat.ui resource.qrc sevimanplat_2.cpp sevimanplat_4.cpp)

target_link_libraries(${PROJECT_NAME}
        ${Qt5_Libs}
        spdlog
        ${EXTRA_LIBS}
        )