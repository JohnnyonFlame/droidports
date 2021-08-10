# ImGui
set(IMGUI_LIB_NAME "ImGui")

set(IMGUI_SOURCES
    "${IMGUI_LIB_NAME}/imgui.cpp"
    "${IMGUI_LIB_NAME}/imgui_draw.cpp"
    "${IMGUI_LIB_NAME}/imgui_tables.cpp"
    "${IMGUI_LIB_NAME}/imgui_widgets.cpp"
    "${IMGUI_LIB_NAME}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_LIB_NAME}/backends/imgui_impl_sdl.cpp"
)

set(IMGUI_HEADERS
    "${IMGUI_LIB_NAME}/imconfig.h"
    "${IMGUI_LIB_NAME}/imgui.h"
    "${IMGUI_LIB_NAME}/imgui_internal.h"
    "${IMGUI_LIB_NAME}/imstb_rectpack.h"
    "${IMGUI_LIB_NAME}/imstb_textedit.h"
    "${IMGUI_LIB_NAME}/imstb_truetype.h"
    "${IMGUI_LIB_NAME}/backends/imgui_impl_opengl3.h"
    "${IMGUI_LIB_NAME}/backends/imgui_impl_sdl.h"
)

set(IMGUI_INC_PATH "${IMGUI_LIB_NAME}/")

# Import external SDL2 libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(${IMGUI_LIB_NAME} STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
target_link_libraries(${IMGUI_LIB_NAME} ${GLAD_LIB_NAME})

target_compile_definitions(${IMGUI_LIB_NAME}
    PRIVATE
        IMGUI_IMPL_OPENGL_LOADER_CUSTOM="${PROJECT_SOURCE_DIR}/platform/common/gles2.h"
)

target_include_directories(${IMGUI_LIB_NAME} PUBLIC ${IMGUI_INC_PATH} ${GLAD_INC_PATH})