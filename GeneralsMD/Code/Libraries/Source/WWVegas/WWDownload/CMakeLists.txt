add_library(WWDownload STATIC
    Download.cpp
    Ftp.cpp
    registry.cpp
    urlBuilder.cpp
)

target_compile_definitions(WWDownload PRIVATE
        $<$<CONFIG:Release>:WIN32 NDEBUG _LIB>
        $<$<CONFIG:Debug>:WIN32 _DEBUG _LIB>
        $<$<CONFIG:Internal>:WIN32 DEBUG _LIB>
        $<$<CONFIG:Profile>:WIN32 NDEBUG _LIB>
)

target_include_directories(WWDownload PRIVATE ../)
