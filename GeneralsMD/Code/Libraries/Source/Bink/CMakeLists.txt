add_library(Bink STATIC
        bink.c
)

target_compile_definitions(Bink PRIVATE
        $<$<CONFIG:Release>:WIN32 NDEBUG _LIB>
        $<$<CONFIG:Debug>:WIN32 _DEBUG _LIB>
        $<$<CONFIG:Internal>:WIN32 _INTERNAL _LIB>
        $<$<CONFIG:Profile>:WIN32 _PROFILE _LIB>
)
