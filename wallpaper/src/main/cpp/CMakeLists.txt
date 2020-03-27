cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

if (NOT DEFINED LIB_WALLPAPER)
    message(FATAL_ERROR "You must set argument \"LIB_WALLPAPER\" with library name...")
endif ()

file(GLOB_RECURSE
    WALLPAPER_CPP
        wallpaper/Main/*.cpp
        wallpaper/Shaders/*.cpp
        wallpaper/Textures/*.cpp
        wallpaper/Graphic/*.cpp
)

add_library(${LIB_WALLPAPER}
    SHARED
        # Main JNI source
        wallpaper/wallpaperlib.cpp
        # Wallpaper source
        ${WALLPAPER_CPP}
)

set_target_properties(${LIB_WALLPAPER}
    PROPERTIES LIBRARY_OUTPUT_DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../lib/${ANDROID_ABI}"
)

target_link_libraries(${LIB_WALLPAPER}
    PRIVATE
        android
        log
        GLESv2
        OpenSLES
)

target_include_directories(${LIB_WALLPAPER}
    PUBLIC
        wallpaper
)