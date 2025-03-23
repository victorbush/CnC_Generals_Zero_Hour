cmake_minimum_required(VERSION 3.30)
project(GeneralsMD)

add_subdirectory(Code)

add_library(Compiler INTERFACE)
target_compile_definitions(Compiler INTERFACE
    $<$<CONFIG:Release>:_RELEASE>
    $<$<CONFIG:Debug>:_DEBUG WWDEBUG DEBUG>
)

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
