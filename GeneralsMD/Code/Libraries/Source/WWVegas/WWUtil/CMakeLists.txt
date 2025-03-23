add_library(WWUtil STATIC
        mathutil.cpp
        miscutil.cpp
)

target_link_libraries(WWUtil INTERFACE Compiler)

target_include_directories(WWUtil PRIVATE
    ../WWDebug
    ../WWLib
    ../WWMath
)
