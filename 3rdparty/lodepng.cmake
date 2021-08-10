# lodepng
set(LODEPNG_LIB_NAME "lodepng")

# We compile the wrapper .c file to avoid .cpp name mangling nonsense
set(LODEPNG_SOURCES
    "lodepng.c"
)

set(LODEPNG_HEADERS
    "${LODEPNG_LIB_NAME}/lodepng.h"
)

set(LODEPNG_INC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${LODEPNG_LIB_NAME}/" PARENT_SCOPE)

add_library(${LODEPNG_LIB_NAME} STATIC ${LODEPNG_SOURCES} ${LODEPNG_HEADERS})

target_include_directories(${LODEPNG_LIB_NAME} PUBLIC ${LODEPNG_INC_PATH})

target_compile_definitions(${LODEPNG_LIB_NAME}
    PRIVATE
        LODEPNG_NO_COMPILE_CPP=1
        LODEPNG_NO_COMPILE_DISK=1
)