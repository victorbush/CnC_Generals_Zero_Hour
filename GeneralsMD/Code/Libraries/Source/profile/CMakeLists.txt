add_library(Profile STATIC
    profile.cpp
    profile_cmd.cpp
    profile_funclevel.cpp
    profile_highlevel.cpp
    profile_result.cpp
    _pch.cpp
)

target_compile_definitions(Profile PRIVATE
        $<$<CONFIG:Release>:WIN32 NDEBUG _LIB>
        $<$<CONFIG:Debug>:WIN32 _DEBUG _LIB>
        $<$<CONFIG:Internal>:WIN32 NDEBUG _LIB _INTERNAL>
        $<$<CONFIG:Profile>:WIN32 NDEBUG _LIB _PROFILE>
)

target_compile_options(Profile PRIVATE
        # for loop variable scope (ForceConformanceInForLoopScope)
        "/Zc:forScope-"
)
