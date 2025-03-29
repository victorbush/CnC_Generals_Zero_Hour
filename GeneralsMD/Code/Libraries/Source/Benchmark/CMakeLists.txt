add_library(Benchmark STATIC
        nbench/emfloat.c
        nbench/misc.c
        nbench/nbench0.c
        nbench/nbench1.c
        nbench/sysspec.c
)

target_compile_definitions(Benchmark PRIVATE
        $<$<CONFIG:Release>:WIN32 NDEBUG _LIB>
        $<$<CONFIG:Debug>:WIN32 _DEBUG _LIB>
        $<$<CONFIG:Internal>:WIN32 _INTERNAL _LIB>
        $<$<CONFIG:Profile>:WIN32 _PROFILE _LIB>
)
