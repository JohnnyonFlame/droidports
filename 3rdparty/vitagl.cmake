# ImGui
set(VITAGL_LIB_NAME "vitaGL")

set(VITAGL_SOURCES
    "${VITAGL_LIB_NAME}/imgui.cpp"
    "${VITAGL_LIB_NAME}/VITAGL_draw.cpp"
    "${VITAGL_LIB_NAME}/VITAGL_tables.cpp"
    "${VITAGL_LIB_NAME}/VITAGL_widgets.cpp"
    "${VITAGL_LIB_NAME}/backends/VITAGL_impl_opengl3.cpp"
    "${VITAGL_LIB_NAME}/backends/VITAGL_impl_sdl.cpp"
)

set(VITAGL_HEADERS
    "${VITAGL_LIB_NAME}/imconfig.h"
    "${VITAGL_LIB_NAME}/imgui.h"
    "${VITAGL_LIB_NAME}/VITAGL_internal.h"
    "${VITAGL_LIB_NAME}/imstb_rectpack.h"
    "${VITAGL_LIB_NAME}/imstb_textedit.h"
    "${VITAGL_LIB_NAME}/imstb_truetype.h"
    "${VITAGL_LIB_NAME}/backends/VITAGL_impl_opengl3.h"
    "${VITAGL_LIB_NAME}/backends/VITAGL_impl_sdl.h"
)

set(VITAGL_INC_PATH "${VITAGL_LIB_NAME}/")

# Import external SDL2 libraries
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(${VITAGL_LIB_NAME} STATIC ${VITAGL_SOURCES} ${VITAGL_HEADERS})
target_link_libraries(${VITAGL_LIB_NAME} ${GLAD_LIB_NAME})

target_compile_definitions(${VITAGL_LIB_NAME}
    PRIVATE
        VITAGL_IMPL_OPENGL_LOADER_CUSTOM="${PROJECT_SOURCE_DIR}/platform/common/gles2.h"
)

target_include_directories(${VITAGL_LIB_NAME} PUBLIC ${VITAGL_INC_PATH} ${GLAD_INC_PATH})