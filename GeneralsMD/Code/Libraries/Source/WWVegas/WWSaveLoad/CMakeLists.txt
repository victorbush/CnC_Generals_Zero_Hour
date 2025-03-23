add_library(WWSaveLoad STATIC
        definition.cpp
        definitionfactory.cpp
        definitionfactorymgr.cpp
        definitionmgr.cpp
        parameter.cpp
        persistfactory.cpp
        pointerremap.cpp
        saveload.cpp
        saveloadstatus.cpp
        saveloadsubsystem.cpp
        twiddler.cpp
        wwsaveload.cpp
)

target_link_libraries(WWSaveLoad INTERFACE Compiler)

target_include_directories(WWSaveLoad PRIVATE
    ../WWLib
    ../WWDebug
    ../WWMath
)
