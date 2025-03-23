add_library(Bink STATIC
    bink.c
)

target_link_libraries(Benchmark INTERFACE Compiler)
