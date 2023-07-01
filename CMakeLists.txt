cmake_minimum_required(VERSION 3.10)

# Variable preamble
set(PLATFORM "linux" CACHE STRING "Target platform")
set(PORT "gmloader" CACHE STRING "Port project being built")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(USE_BUILTIN_FREETYPE OFF CACHE STRING "Use built-in freetype")

project(droidports)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE=1" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE=1" CACHE STRING "" FORCE)

# Define platform specific settings for Linux
if(PLATFORM STREQUAL "linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wfloat-conversion")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wfloat-conversion")
    
    # Needed packages
    find_package(SDL2 REQUIRED)
    find_package(OpenAL REQUIRED)
    find_package(ZLIB REQUIRED)
    find_package(BZip2 REQUIRED)
    find_package(LibZip REQUIRED)
    if(NOT USE_BUILTIN_FREETYPE)
        find_package(Freetype REQUIRED)
    endif()
else()
    # Failure to setup platform specific settings.
    message(FATAL_ERROR "Unknown platform ${PLATFORM}!")
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -g -DDEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Og -g -DDEBUG")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Os")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -mcpu=cortex-a9 -mfpu=vfpv3-d16")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -mthumb -mcpu=cortex-a9 -mfpu=vfpv3-d16")

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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")

target_link_libraries(${PORT}
    stdc++
    m
    ${SDL2_LIBRARY}
    ${ZLIB_LIBRARY}
    ${LIBZIP_LIBRARY}
    ${FREETYPE_LIBRARY}
    ${PNG_LIBRARY}
    ${BZIP2_LIBRARY}
    ${OPENAL_LIBRARY}
    pthread
)
