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

target_compile_definitions(WWSaveLoad PRIVATE
        $<$<CONFIG:Release>:WINVER=0x400 _WINDOWS NDEBUG WIN32 IG_DEBUG_STACKTRACE>
        $<$<CONFIG:Debug>:_DEBUG WINVER=0x400 _WINDOWS WIN32 WWDEBUG>
        $<$<CONFIG:Internal>:NDEBUG WINVER=0x400 _WINDOWS WIN32 _INTERNAL WWDEBUG>
        $<$<CONFIG:Profile>:NDEBUG WWDEBUG WINVER=0x400 _WINDOWS WIN32 _PROFILE>
)

target_include_directories(WWSaveLoad PRIVATE
    ../WWLib
    ../WWDebug
    ../WWMath
)
