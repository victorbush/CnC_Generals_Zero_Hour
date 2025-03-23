add_library(Compression STATIC
    CompressionManager.cpp
    EAC/btreeabout.cpp
    EAC/btreedecode.cpp
    EAC/btreeencode.cpp
    EAC/huffabout.cpp
    EAC/huffdecode.cpp
    EAC/huffencode.cpp
    EAC/refabout.cpp
    EAC/refdecode.cpp
    EAC/refencode.cpp
    LZHCompress/CompLibSource/Huff.cpp
    LZHCompress/CompLibSource/Lz.cpp
    LZHCompress/CompLibSource/Lzhl.cpp
    LZHCompress/CompLibSource/Lzhl_tcp.cpp
    LZHCompress/NoxCompress.cpp
    ZLib/adler32.c
    ZLib/compress.c
    ZLib/crc32.c
    ZLib/deflate.c
    ZLib/gzio.c
    ZLib/infblock.c
    ZLib/infcodes.c
    ZLib/inffast.c
    ZLib/inflate.c
    ZLib/inftrees.c
    ZLib/infutil.c
    ZLib/maketree.c
    ZLib/trees.c
    ZLib/uncompr.c
    ZLib/zutil.c
)

target_link_libraries(Compression INTERFACE Compiler)

target_compile_definitions(Compression PRIVATE Z_PREFIX)

target_include_directories(Compression

    PUBLIC
        Include

    PRIVATE
    ../../Include
)
