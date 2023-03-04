cmake_minimum_required(VERSION 3.15)

project(utils)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
file(GLOB CURRENT_SOURCES  *.c *.cpp)

source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${CURRENT_SOURCES})

include(${CMAKE_SOURCE_DIR}/cmake/3drparty.cmake)

set(CMAKE_EXE_LINKER_FLAGS "-SHARED")
# create static library
add_library(${PROJECT_NAME} STATIC ${CURRENT_HEADERS} ${CURRENT_SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${Qt5_Libs}
        pthread
        spdlog)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)