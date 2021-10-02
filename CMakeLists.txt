cmake_minimum_required(VERSION 3.10)

# Variable preamble
set(PLATFORM "linux" CACHE STRING "Target platform")
set(PORT "gmloader" CACHE STRING "Port project being built")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(USE_BUILTIN_FREETYPE OFF CACHE STRING "Use built-in freetype")

project(droidports)

find_package(OpenAL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(BZip2 REQUIRED)
find_package(PNG REQUIRED)
find_package(LibZip REQUIRED)
if(NOT USE_BUILTIN_FREETYPE)
    find_package(Freetype REQUIRED)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE=1" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE=1" CACHE STRING "" FORCE)

# Define platform specific settings for Linux
if(PLATFORM STREQUAL "linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wfloat-conversion")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wfloat-conversion")
    find_package(SDL2 REQUIRED)
# Define platform specific settings for PSVita
elseif(PLATFORM STREQUAL "vita")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wfloat-conversion")
    message(STATUS "Using platform ps-vita.")
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        if(DEFINED ENV{VITASDK})
            set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
        else()
            message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
        endif()
    endif()

    include("${VITASDK}/share/vita.cmake" REQUIRED)
# Failure to setup platform specific settings.
else()
    message(FATAL_ERROR "Unknown platform ${PLATFORM}!")
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -g -DDEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Og -g -DDEBUG")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2")
endif()

# Add the 3rd-party packages
add_subdirectory(3rdparty)

# Add the port-specific settings
include("ports/${PORT}/port.cmake")

include_directories(
    ${FREETYPE_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIR}
    ${OPENAL_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
    ${VORBIS_INCLUDE_DIRS}
    ${LODEPNG_INC_PATH}
    "platform/${PLATFORM}"   
    "platform/common"   
    "bridges"
    "jni"
)

# Source globs
file(GLOB_RECURSE PORT_SOURCES
    ${PORT_BRIDGE_SOURCES}
    "ports/${PORT}/*.c"
)

file(GLOB_RECURSE COMMON_SOURCES
    "platform/common/*.c"
    "bridges/math_bridge.c"
    "bridges/ctype_bridge.c"
    "bridges/misc_bridges.c"
    "bridges/pthread_bridge.c"
    "bridges/stdio_bridge.c"
    "bridges/gles2_bridge.c"
    "jni/*.c"
)
    
file(GLOB_RECURSE PLATFORM_SOURCES
    "platform/${PLATFORM}/*.c"
)

## Build and link
# Add all the files needed to compile here
add_executable(${PORT}
  ${PORT_SOURCES}     # Port specific files
  ${COMMON_SOURCES}   # Common files
  ${PLATFORM_SOURCES} # Platform specific files
)

target_link_libraries(${PORT}
    stdc++
    m
    "lodepng"
    ${SDL2_LIBRARY}
    ${ZLIB_LIBRARY}
    ${LIBZIP_LIBRARY}
    ${FREETYPE_LIBRARY}
    ${PNG_LIBRARY}
    ${BZIP2_LIBRARY}
    ${OPENAL_LIBRARY}
    pthread
)

if(PLATFORM STREQUAL "vita")
    # Vita-specific flags
    target_compile_definitions(${PORT} PUBLIC
        -DUSE_VITAGL=1
        -DPLATFORM_VITA=1
    )

    # Link the vita-specific libraries
    target_link_libraries(${PORT}
        mathneon
        taihen_stub
        kubridge_stub
        SceAppMgr_stub
        SceAppUtil_stub
        SceAudio_stub
        SceAudioIn_stub
        SceCtrl_stub
        SceCommonDialog_stub
        SceDisplay_stub
        SceFios2_stub
        SceGxm_stub
        SceShaccCg_stub
        SceSysmodule_stub
        ScePower_stub
        SceTouch_stub
        SceVshBridge_stub
        "${CMAKE_SOURCE_DIR}/3rdparty/vitaGL/libvitaGL.a"
        vitashark
    )

    ## Create Vita files
    vita_create_self(${PORT}.self ${PORT})

    # The FILE directive lets you add additional files to the VPK, the syntax is
    # FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
    vita_create_vpk(${PORT}.vpk ${VITA_TITLEID} ${PORT}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE "ports/${PORT}/sce_sys/icon0.png" sce_sys/icon0.png
        FILE "ports/${PORT}/sce_sys/livearea/contents/bg.png" sce_sys/livearea/contents/bg.png
        FILE "ports/${PORT}/sce_sys/livearea/contents/startup.png" sce_sys/livearea/contents/startup.png
        FILE "ports/${PORT}/sce_sys/livearea/contents/template.xml" sce_sys/livearea/contents/template.xml
    )
endif()
