cmake_minimum_required(VERSION 3.30)
project(GeneralsMD)

set(CMAKE_CONFIGURATION_TYPES "Release;Profile;Internal;Debug")

add_subdirectory(Code)

#add_library(Compiler INTERFACE)
#target_compile_definitions(Compiler INTERFACE
#    $<$<CONFIG:Release>:_RELEASE IG_DEBUG_STACKTRACE NDEBUG>
#    $<$<CONFIG:Debug>:_DEBUG WWDEBUG DEBUG>
#    $<$<CONFIG:Internal>:_INTERNAL NDEBUG>
#)

message(Compiler=${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION})

if(MSVC)
#    target_compile_options(Compiler INTERFACE
#        # for loop variable scope (ForceConformanceInForLoopScope)
#        "/Zc:forScope-"
#    )

    # Disable "treat warnings as error" (TreatWarningAsError)
#    string(REPLACE " /WX" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
#    add_compile_options(-fpermissive)
endif()
