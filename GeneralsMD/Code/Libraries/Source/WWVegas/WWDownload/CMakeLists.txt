add_library(WWDownload STATIC
    Download.cpp
    Ftp.cpp
    registry.cpp
    urlBuilder.cpp
)

target_link_libraries(WWDownload INTERFACE Compiler)

target_include_directories(WWDownload PRIVATE ../)
