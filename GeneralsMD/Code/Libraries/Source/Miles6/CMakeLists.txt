add_library(Miles6 STATIC
    cleanup.c
    miles.c
)

target_link_libraries(Miles6 INTERFACE Compiler)

target_include_directories(Miles6 PUBLIC include)

target_compile_definitions(Miles6 PRIVATE BUILD_STUBS)