add_executable(RTS WIN32
    WinMain.cpp
        RTS.RC
)

target_compile_features(RTS PRIVATE cxx_std_17)

target_compile_definitions(RTS PRIVATE _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)

target_link_libraries(RTS INTERFACE Compiler)

target_include_directories(RTS PRIVATE
    ../GameEngine/Include
    ../GameEngineDevice/Include
    ../Libraries/Include
    ../Libraries/Source/WWVegas
    ../Libraries/Source/WWVegas/WWLib
    ../Libraries/Source/WWVegas/WWMath
    ../Libraries/Source/WWVegas/WWDebug
    ../Libraries/Source/WWVegas/WWSaveLoad
    ../Libraries/Source/WWVegas/WW3D2
    ../Libraries/Source/Miles6/include
    ../Libraries/Source/dx8
    ../Libraries/Source/Bink
)

target_link_libraries(RTS PRIVATE
#    Benchmark
    WW3D2
    WWDebug
    WWLib
    WWUtil
    WWMath
    WWDownload
    GameEngine
    GameEngineDevice
    GameSpy
    Bink
    Miles6
        EABrowserDispatch
    d3d8lib
      odbc32.lib
        odbccp32.lib
        winmm.lib
    vfw32.lib
        dsound.lib
        wsock32.lib
        imm32.lib
        wininet.lib
)

#set_target_properties(RTS PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Run/System")
set_target_properties(RTS PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Run/System")
set_target_properties(RTS PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/Run/SystemDebug")
set_target_properties(RTS PROPERTIES RUNTIME_OUTPUT_DIRECTORY_PROFILE "${CMAKE_SOURCE_DIR}/Run/SystemProfile")
set_target_properties(RTS PROPERTIES RUNTIME_OUTPUT_DIRECTORY_INTERNAL "${CMAKE_SOURCE_DIR}/Run/SystemInternal")

target_compile_definitions(RTS PRIVATE
        $<$<CONFIG:Release>:IG_DEBUG_STACKTRACE NDEBUG _RELEASE WIN32 _WINDOWS>
        $<$<CONFIG:Debug>:_DEBUG WIN32 _WINDOWS BROWSER_DEBUG>
        $<$<CONFIG:Internal>:NDEBUG _INTERNAL WIN32 _WINDOWS>
        $<$<CONFIG:Profile>:IG_DEBUG_STACKTRACE NDEBUG _RELEASE WIN32 _WINDOWS _PROFILE>
)
