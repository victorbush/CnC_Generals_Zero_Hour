add_library(WWMath STATIC
        aabox.cpp
        aabtreecull.cpp
        cardinalspline.cpp
        catmullromspline.cpp
        colmath.cpp
        colmathaabox.cpp
        colmathaabtri.cpp
        colmathfrustum.cpp
        colmathline.cpp
        colmathobbobb.cpp
        colmathobbox.cpp
        colmathobbtri.cpp
        colmathplane.cpp
        colmathsphere.cpp
        cullsys.cpp
        curve.cpp
        euler.cpp
        frustum.cpp
        gridcull.cpp
        hermitespline.cpp
        lineseg.cpp
        lookuptable.cpp
        matrix3.cpp
        matrix3d.cpp
        matrix4.cpp
        obbox.cpp
        ode.cpp
        pot.cpp
        quat.cpp
        tcbspline.cpp
        tri.cpp
        v3_rnd.cpp
        vehiclecurve.cpp
        vp.cpp
        wwmath.cpp
)

target_link_libraries(WWMath INTERFACE Compiler)

target_include_directories(WWMath
    PRIVATE
        ../WWLib
        ../WWDebug
        ../WWSaveLoad
        ../../dx8
)

target_compile_options(WWMath PRIVATE
        # for loop variable scope (ForceConformanceInForLoopScope)
        "/Zc:forScope-"
)
