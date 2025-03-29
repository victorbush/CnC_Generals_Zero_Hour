add_library(Miles6 STATIC
    cleanup.c
    miles.c
)

target_include_directories(Miles6 PUBLIC include)

target_compile_definitions(Miles6 PRIVATE
        BUILD_STUBS
        $<$<CONFIG:Release>:NDEBUG _RELEASE WIN32 _LIB>
        $<$<CONFIG:Debug>:_DEBUG WIN32 _LIB>
        $<$<CONFIG:Internal>:NDEBUG _INTERNAL WIN32 _LIB>
        $<$<CONFIG:Profile>:NDEBUG _RELEASE WIN32 _LIB _PROFILE>
)
