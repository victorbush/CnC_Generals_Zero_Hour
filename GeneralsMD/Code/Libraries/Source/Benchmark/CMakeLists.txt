add_library(Benchmark STATIC
    nbench/emfloat.c
    nbench/misc.c
    nbench/nbench0.c
    nbench/nbench1.c
    nbench/sysspec.c
)

target_link_libraries(Benchmark INTERFACE Compiler)
