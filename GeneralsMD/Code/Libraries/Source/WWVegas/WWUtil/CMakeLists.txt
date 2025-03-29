add_library(WWUtil STATIC
        mathutil.cpp
        miscutil.cpp
)

target_compile_definitions(WWUtil PRIVATE
        $<$<CONFIG:Release>:_LIB _WINDOWS WIN32_LEAN_AND_MEAN NDEBUG WIN32 IG_DEBUG_STACKTRACE>
        $<$<CONFIG:Debug>:_DEBUG _LIB WIN32 _WINDOWS WIN32_LEAN_AND_MEAN>
        $<$<CONFIG:Internal>:NDEBUG _LIB WIN32 _WINDOWS WIN32_LEAN_AND_MEAN _INTERNAL>
        $<$<CONFIG:Profile>:NDEBUG WWDEBUG _LIB WIN32 _WINDOWS WIN32_LEAN_AND_MEAN _PROFILE>
)

target_include_directories(WWUtil PRIVATE
    ../WWDebug
    ../WWLib
    ../WWMath
)
