add_library(WWDebug STATIC
    wwdebug.cpp
    wwmemlog.cpp
    wwprofile.cpp
)

target_compile_definitions(WWDebug PRIVATE
        $<$<CONFIG:Release>:WINVER=0x400 _WINDOWS WIN32_LEAN_AND_MEAN NDEBUG WIN32 IG_DEBUG_STACKTRACE>
        $<$<CONFIG:Debug>:_DEBUG WINVER=0x400 _WINDOWS WIN32_LEAN_AND_MEAN WIN32 WWDEBUG>
        $<$<CONFIG:Internal>:NDEBUG WINVER=0x400 _WINDOWS WIN32_LEAN_AND_MEAN WIN32 _INTERNAL WWDEBUG>
        $<$<CONFIG:Profile>:NDEBUG WWDEBUG WINVER=0x400 _WINDOWS WIN32_LEAN_AND_MEAN WIN32 _PROFILE>
)

target_include_directories(WWDebug PRIVATE
    ../WWLib
)