cmake_minimum_required(VERSION 3.15)
project(addVideo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
file(GLOB CURRENT_SOURCES  *.cpp *.c)

source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${CURRENT_SOURCES})

# find QT5
include(${CMAKE_SOURCE_DIR}/cmake/findQt5.cmake)

#add_subdirectory(${CMAKE_SOURCE_DIR}/src/utils ${CMAKE_SOURCE_DIR}/0build-linux/src/utils)

# create static library
add_library(${PROJECT_NAME} STATIC ${CURRENT_HEADERS} ${CURRENT_SOURCES} addVideo.ui)
target_link_libraries(${PROJECT_NAME}
                         ${Qt5_Libs}
                        ${CMAKE_SOURCE_DIR}/lib/libutils.a)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
