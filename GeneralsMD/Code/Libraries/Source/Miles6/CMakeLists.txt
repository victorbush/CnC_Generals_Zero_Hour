cmake_minimum_required(VERSION 3.5.0)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "No build type selected, default to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

project(Miles6 VERSION 1.0.0 LANGUAGES C)

add_library(milescleanup STATIC cleanup.c)
add_library(Miles6 SHARED miles.c miles.def)
set_target_properties(Miles6 PROPERTIES OUTPUT_NAME mss32)
set_target_properties(Miles6 PROPERTIES SOVERSION 1.0 VERSION 1.0.0)
target_include_directories(Miles6 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>      #include <mss/mss.h>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/mss>  #include <mss.h>
)
target_compile_definitions(Miles6 PRIVATE BUILD_STUBS)
target_link_libraries(Miles6 INTERFACE milescleanup)
