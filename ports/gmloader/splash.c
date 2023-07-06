#define STBI_MALLOC malloc
#define STBI_REALLOC realloc
#define STBI_FREE free
#define STB_IMAGE_IMPLEMENTATION
#define STB_ONLY_PNG
#include "stb_image.h"
#include "gles2.h"
#include "so_util.h"
#include "libyoyo.h"
#include "zip_util.h"
#include "io_util.h"

static char* blit_vert_fmt =
"#version 100\n"
"varying vec2 vTexCoord;\n"
"attribute vec2 aVertCoord;\n"
"attribute vec2 aTexCoord;\n"
"void main() {\n"
"   vTexCoord = aTexCoord;\n"
"   gl_Position = vec4(aVertCoord, 0.0, 1.0);\n"
"}";

static char* blit_frag_standard =
"#version 100\n"
"precision mediump float;\n"
"varying vec2 vTexCoord;\n"
"uniform sampler2D uFBOTex;\n"
"uniform vec2 uTexSize;\n"
"void main() {\n"
"   gl_FragColor = texture2D(uFBOTex, vTexCoord);\n"
"}\n";

typedef struct mat4 {
    GLfloat v[16];
} mat4;

void create_splash_texture(zip_t *apk, GLuint *tex, int *w_tex, int *h_tex, int *w, int *h)
{
    char path_splash[PATH_MAX];
    void *inflated_ptr = NULL;
    size_t inflated_bytes = 0;
    uint32_t *pixels = NULL;

    int _;    
    snprintf(path_splash, sizeof(path_splash), "%s/%s", get_platform_savedir(), "splash.png");
    io_buffer_from_file(path_splash, &_, &inflated_ptr, &inflated_bytes, 0);
    if (!inflated_ptr) {
        zip_inflate_buf(apk, "assets/splash.png", &inflated_bytes, &inflated_ptr);
    }

    if (inflated_ptr) {
        pixels = (uint8_t*)stbi_load_from_memory(inflated_ptr, inflated_bytes, w, h, &_, 4);
        free(inflated_ptr);
    } else {
        *w = 320;
        *h = 240;
        warning("Warning, no splash image available, creating xor pattern...\n");
        pixels = malloc(320 * 240 * sizeof(uint32_t));

        for (int i = 0; i < 240; i++) {
            for (int j = 0; j < 320; j++) {
                pixels[i * 320 + j] = ((~i ^ j) << 16) | ((i ^ ~j) << 8) | (i ^ j);
            }
        }
    }

    // Get pot-2 sizes
    *w_tex = 1; while(*w_tex < *w) *w_tex *= 2;
    *h_tex = 1; while(*h_tex < *h) *h_tex *= 2;

    glGenTextures(1, tex);
    glBindTexture(GL_TEXTURE_2D, *tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *w_tex, *h_tex, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, *w, *h, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glFlush();

    free(pixels);
}

static void get_aspect_correct_coords(int viewport[2], int plane[2], float uv[2], GLfloat vert[4][4])
{
    float aspect_plane, aspect_viewport;
    float ratio_x, ratio_y, shift_x, shift_y;

    // Choose which edge to touch
    aspect_plane = (float)plane[0] / plane[1];
    aspect_viewport = (float)viewport[0] / viewport[1];

    if (aspect_viewport > aspect_plane) {
        // viewport wider than plane
        ratio_x = aspect_plane / aspect_viewport;
        ratio_y = 1.0f;
    } else {
        // plane wider than viewport
        ratio_x = 1.0f;
        ratio_y = aspect_viewport / aspect_plane;
    }

    shift_x = (1.0f - 1.0f * ratio_x) / 2.0f;
    shift_y = (1.0f - 1.0f * ratio_y) / 2.0f;

    // Get aspect corrected sizes within pixel boundaries
    vert[0][0] = -1.0f + shift_x; vert[0][1] = -1.0f + shift_y;
    vert[1][0] = -1.0f + shift_x; vert[1][1] =  1.0f - shift_y;
    vert[2][0] =  1.0f - shift_x; vert[2][1] = -1.0f + shift_y;
    vert[3][0] =  1.0f - shift_x; vert[3][1] =  1.0f - shift_y;

    // Texture UVs
    vert[0][2] = 0.0f; vert[0][3] = uv[1];
    vert[1][2] = 0.0f; vert[1][3] = 0.0f;
    vert[2][2] = uv[0]; vert[2][3] = uv[1];
    vert[3][2] = uv[0]; vert[3][3] = 0.0f;
}

void render_splash_image(GLuint tex, int w, int h, int img_w, int img_h, int tex_w, int tex_h)
{
    GLchar msg[2048] = {};
    GLchar msg_frag[2048] = {};
    GLchar msg_vert[2048] = {};

    /* Compile the vertex shader */
    char *sources[] = {blit_vert_fmt, blit_frag_standard};
    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &sources[0], NULL);
    glCompileShader(vert);
    glGetShaderInfoLog(vert, sizeof(msg_vert), NULL, msg_vert);
    warning("render_splash_image vert status: %s\n", msg_vert);
    
    /* Compile the fragment shader */
    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &sources[1], NULL);
    glCompileShader(frag);
    glGetShaderInfoLog(frag, sizeof(msg_frag), NULL, msg_frag);
    warning("render_splash_image frag status: %s\n", msg_frag);

    GLuint prog = glCreateProgram();
    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glLinkProgram(prog);

    GLuint loc_aVertCoord = glGetAttribLocation(prog, "aVertCoord");
    GLuint loc_aTexCoord = glGetAttribLocation(prog, "aTexCoord");
    GLuint loc_uFBOtex = glGetUniformLocation(prog, "uFBOTex");
    GLuint loc_uProj = glGetUniformLocation(prog, "uProj");
    GLuint loc_uTexSize = glGetUniformLocation(prog, "uTexSize");

    glGetProgramInfoLog(prog, sizeof(msg), NULL, msg);
    warning("Blitter Program Info: %s\n", msg);

    warning("loc_aVertCoord %d\n", loc_aVertCoord);
    warning("loc_aTexCoord %d\n", loc_aTexCoord);
    warning("loc_uFBOtex %d\n", loc_uFBOtex);
    
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(prog);
    glUniform1i(loc_uFBOtex, 0);

    mat4 mat_proj = {};
    mat4 vert_buffer = {};
    float u, v;
    u = img_w / (float)tex_w;
    v = img_h / (float)tex_h;
    get_aspect_correct_coords(
        (int [2]){w, h},
        (int [2]){img_w, img_h},
        (float [2]){u, v},
        &vert_buffer
    );

    glViewport(0, 0, w, h);
    glUniformMatrix4fv(loc_uProj, 1, 0, &mat_proj);
    glUniform2f(loc_uTexSize, tex_w, tex_h);

    /* Generate buffers */
    GLuint vbo, vao;
    glGenBuffers(1, &vbo);
    glGenVertexArraysOES(1, &vao);

    /* Populate buffers */
    glBindVertexArrayOES(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(loc_aVertCoord);
    glEnableVertexAttribArray(loc_aTexCoord);
    glVertexAttribPointer(loc_aVertCoord, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0 * sizeof(float)));
    glVertexAttribPointer(loc_aTexCoord, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert_buffer), &vert_buffer, GL_STATIC_DRAW);

    /* perform draws */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glFinish();

    /* clean-up */
    glUseProgram(0);
    glDisableVertexAttribArray(loc_aVertCoord);
    glDisableVertexAttribArray(loc_aTexCoord);
    glBindVertexArrayOES(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(prog);
    glDeleteShader(vert);
    glDeleteShader(frag);
}

void free_splash_image(GLuint tex)
{
    // Free splash screen background texture
    glDeleteTextures(1, &tex);
}