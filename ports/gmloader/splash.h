#ifndef __SPLASH_H__
#define __SPLASH_H__

#include "zip_util.h"
#include "gles2_platform.h"

extern void create_splash_texture(zip_t *apk, GLuint *tex, int *w_tex, int *h_tex, int *w, int *h);
extern void render_splash_image(GLuint tex, int w, int h, int img_w, int img_h, int tex_w, int tex_h);
extern void free_splash_image(GLuint tex);

#endif __SPLASH_H__
