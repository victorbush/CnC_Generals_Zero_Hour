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

target_compile_definitions(WWShade PRIVATE
        $<$<CONFIG:Release>:WIN32 NDEBUG _LIB>
        $<$<CONFIG:Debug>:_LIB WWDEBUG _DEBUG WIN32>
        $<$<CONFIG:Internal>:WINVER=0x400 WWDEBUG NDEBUG WIN32 _WINDOWS _INTERNAL>
        $<$<CONFIG:Profile>:WIN32 NDEBUG _LIB _PROFILE>
)

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
