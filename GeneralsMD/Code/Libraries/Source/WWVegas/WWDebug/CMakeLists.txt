add_library(WWDebug STATIC
    wwdebug.cpp
    wwmemlog.cpp
    wwprofile.cpp
)

target_link_libraries(WWDebug INTERFACE Compiler)

target_include_directories(WWDebug PRIVATE
    ../WWLib
)