add_library(Profile STATIC
    profile.cpp
    profile_cmd.cpp
    profile_funclevel.cpp
    profile_highlevel.cpp
    profile_result.cpp
    _pch.cpp
)

target_link_libraries(Profile INTERFACE Compiler)

target_compile_options(Profile PRIVATE
        # for loop variable scope (ForceConformanceInForLoopScope)
        "/Zc:forScope-"
)
