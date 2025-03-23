add_library(WWShade STATIC
        shd6bumpdiff.cpp
        shd6bumpspec.cpp
        shd7bumpdiff.cpp
        shd7bumpspec.cpp
        shd8bumpdiff.cpp
        shd8bumpspec.cpp
        shdbumpdiff.cpp
        shdbumpspec.cpp
        shdcubemap.cpp
        shddef.cpp
        shddeffactory.cpp
        shddefmanager.cpp
        shdforcelinks.cpp
        shdglossmask.cpp
        shdhwshader.cpp
        shdinterface.cpp
        shdlegacyw3d.cpp
        shdlib.cpp
        shdloader.cpp
        shdmesh.cpp
        shdrenderer.cpp
        shdsimple.cpp
        shdsubmesh.cpp
)

target_link_libraries(WWShade INTERFACE Compiler)

target_include_directories(WWShade PRIVATE
    ../WW3D2
    ../WWDebug
    ../WWLib
    ../WWMath
    ../WWSaveLoad
    ../../dx8
)

target_compile_options(WWShade PRIVATE
        # for loop variable scope (ForceConformanceInForLoopScope)
        "/Zc:forScope-"
)
