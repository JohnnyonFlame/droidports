#ifndef __GLES2_MACROS_H__
#define __GLES2_MACROS_H__

#define GLES2_FUNCS \
    GB_DECL_FWD_NR  (glActiveTexture,                                  void,           (texture),                                                                    (GLenum texture)) \
    GB_DECL_FWD_NR  (glAttachShader,                                   void,           (program, shader),                                                            (GLuint program, GLuint shader)) \
    GB_DECL_FWD_NR  (glBindAttribLocation,                             void,           (program, index, name),                                                       (GLuint program, GLuint index, const GLchar *name)) \
    GB_DECL_FWD_NR  (glBindBuffer,                                     void,           (target, buffer),                                                             (GLenum target, GLuint buffer)) \
    GB_DECL_FWD_NR  (glBindFramebuffer,                                void,           (target, framebuffer),                                                        (GLenum target, GLuint framebuffer)) \
    GB_DECL_FWD_NR  (glBindRenderbuffer,                               void,           (target, renderbuffer),                                                       (GLenum target, GLuint renderbuffer)) \
    GB_DECL_FWD_NR  (glBindTexture,                                    void,           (target, texture),                                                            (GLenum target, GLuint texture)) \
    GB_DECL_FWD_NR  (glBlendColor,                                     void,           (red, green, blue, alpha),                                                    (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    GB_DECL_FWD_NR  (glBlendEquation,                                  void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD_NR  (glBlendEquationSeparate,                          void,           (modeRGB, modeAlpha),                                                         (GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD_NR  (glBlendFunc,                                      void,           (sfactor, dfactor),                                                           (GLenum sfactor, GLenum dfactor)) \
    GB_DECL_FWD_NR  (glBlendFuncSeparate,                              void,           (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha),                         (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)) \
    GB_DECL_FWD_NR  (glBufferData,                                     void,           (target, size, data, usage),                                                  (GLenum target, GLsizeiptr size, const void *data, GLenum usage)) \
    GB_DECL_FWD_NR  (glBufferSubData,                                  void,           (target, offset, size, data),                                                 (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)) \
    GB_DECL_FWD     (glCheckFramebufferStatus,                         GLenum,         (target),                                                                     (GLenum target)) \
    GB_DECL_FWD_NR  (glClear,                                          void,           (mask),                                                                       (GLbitfield mask)) \
    GB_DECL_FWD_NR  (glClearColor,                                     void,           (red, green, blue, alpha),                                                    (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    GB_DECL_FWD_NR  (glClearDepthf,                                    void,           (d),                                                                          (GLfloat d)) \
    GB_DECL_FWD_NR  (glClearStencil,                                   void,           (s),                                                                          (GLint s)) \
    GB_DECL_FWD_NR  (glColorMask,                                      void,           (red, green, blue, alpha),                                                    (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)) \
    GB_DECL_FWD_NR  (glCompileShader,                                  void,           (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD_NR  (glCompressedTexImage2D,                           void,           (target, level, internalformat, width, height, border, imageSize, data),      (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD_NR  (glCompressedTexSubImage2D,                        void,           (target, level, xoffset, yoffset, width, height, format, imageSize, data),    (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD_NR  (glCopyTexImage2D,                                 void,           (target, level, internalformat, x, y, width, height, border),                 (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)) \
    GB_DECL_FWD_NR  (glCopyTexSubImage2D,                              void,           (target, level, xoffset, yoffset, x, y, width, height),                       (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glCreateProgram,                                  GLuint,         (),                                                                           ()) \
    GB_DECL_FWD     (glCreateShader,                                   GLuint,         (type),                                                                       (GLenum type)) \
    GB_DECL_FWD_NR  (glCullFace,                                       void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD_NR  (glDeleteBuffers,                                  void,           (n, buffers),                                                                 (GLsizei n, const GLuint *buffers)) \
    GB_DECL_FWD_NR  (glDeleteFramebuffers,                             void,           (n, framebuffers),                                                            (GLsizei n, const GLuint *framebuffers)) \
    GB_DECL_FWD_NR  (glDeleteProgram,                                  void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD_NR  (glDeleteRenderbuffers,                            void,           (n, renderbuffers),                                                           (GLsizei n, const GLuint *renderbuffers)) \
    GB_DECL_FWD_NR  (glDeleteShader,                                   void,           (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD_NR  (glDeleteTextures,                                 void,           (n, textures),                                                                (GLsizei n, const GLuint *textures)) \
    GB_DECL_FWD_NR  (glDepthFunc,                                      void,           (func),                                                                       (GLenum func)) \
    GB_DECL_FWD_NR  (glDepthMask,                                      void,           (flag),                                                                       (GLboolean flag)) \
    GB_DECL_FWD_NR  (glDepthRangef,                                    void,           (n, f),                                                                       (GLfloat n, GLfloat f)) \
    GB_DECL_FWD_NR  (glDetachShader,                                   void,           (program, shader),                                                            (GLuint program, GLuint shader)) \
    GB_DECL_FWD_NR  (glDisable,                                        void,           (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD_NR  (glDisableVertexAttribArray,                       void,           (index),                                                                      (GLuint index)) \
    GB_DECL_FWD_NR  (glDrawArrays,                                     void,           (mode, first, count),                                                         (GLenum mode, GLint first, GLsizei count)) \
    GB_DECL_FWD_NR  (glDrawElements,                                   void,           (mode, count, type, indices),                                                 (GLenum mode, GLsizei count, GLenum type, const void *indices)) \
    GB_DECL_FWD_NR  (glEnable,                                         void,           (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD_NR  (glEnableVertexAttribArray,                        void,           (index),                                                                      (GLuint index)) \
    GB_DECL_FWD_NR  (glFinish,                                         void,           (),                                                                           ()) \
    GB_DECL_FWD_NR  (glFlush,                                          void,           (),                                                                           ()) \
    GB_DECL_FWD_NR  (glFramebufferRenderbuffer,                        void,           (target, attachment, renderbuffertarget, renderbuffer),                       (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)) \
    GB_DECL_FWD_NR  (glFramebufferTexture2D,                           void,           (target, attachment, textarget, texture, level),                              (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)) \
    GB_DECL_FWD_NR  (glFrontFace,                                      void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD_NR  (glGenBuffers,                                     void,           (n, buffers),                                                                 (GLsizei n, GLuint *buffers)) \
    GB_DECL_FWD_NR  (glGenerateMipmap,                                 void,           (target),                                                                     (GLenum target)) \
    GB_DECL_FWD_NR  (glGenFramebuffers,                                void,           (n, framebuffers),                                                            (GLsizei n, GLuint *framebuffers)) \
    GB_DECL_FWD_NR  (glGenRenderbuffers,                               void,           (n, renderbuffers),                                                           (GLsizei n, GLuint *renderbuffers)) \
    GB_DECL_FWD_NR  (glGenTextures,                                    void,           (n, textures),                                                                (GLsizei n, GLuint *textures)) \
    GB_DECL_FWD_NR  (glGetActiveAttrib,                                void,           (program, index, bufSize, length, size, type, name),                          (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    GB_DECL_FWD_NR  (glGetActiveUniform,                               void,           (program, index, bufSize, length, size, type, name),                          (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    GB_DECL_FWD_NR  (glGetAttachedShaders,                             void,           (program, maxCount, count, shaders),                                          (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)) \
    GB_DECL_FWD     (glGetAttribLocation,                              GLint,          (program, name),                                                              (GLuint program, const GLchar *name)) \
    GB_DECL_FWD_NR  (glGetBooleanv,                                    void,           (pname, data),                                                                (GLenum pname, GLboolean *data)) \
    GB_DECL_FWD_NR  (glGetBufferParameteriv,                           void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetError,                                       GLenum,         (),                                                                           ()) \
    GB_DECL_FWD_NR  (glGetFloatv,                                      void,           (pname, data),                                                                (GLenum pname, GLfloat *data)) \
    GB_DECL_FWD_NR  (glGetFramebufferAttachmentParameteriv,            void,           (target, attachment, pname, params),                                          (GLenum target, GLenum attachment, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetIntegerv,                                    void,           (pname, data),                                                                (GLenum pname, GLint *data)) \
    GB_DECL_FWD_NR  (glGetProgramiv,                                   void,           (program, pname, params),                                                     (GLuint program, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetProgramInfoLog,                              void,           (program, bufSize, length, infoLog),                                          (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD_NR  (glGetRenderbufferParameteriv,                     void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetShaderiv,                                    void,           (shader, pname, params),                                                      (GLuint shader, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetShaderInfoLog,                               void,           (shader, bufSize, length, infoLog),                                           (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD_NR  (glGetShaderPrecisionFormat,                       void,           (shadertype, precisiontype, range, precision),                                (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)) \
    GB_DECL_FWD_NR  (glGetShaderSource,                                void,           (shader, bufSize, length, source),                                            (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)) \
    GB_DECL_FWD     (glGetString,                                      const GLubyte*, (name),                                                                       (GLenum name)) \
    GB_DECL_FWD_NR  (glGetTexParameterfv,                              void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLfloat *params)) \
    GB_DECL_FWD_NR  (glGetTexParameteriv,                              void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetUniformfv,                                   void,           (program, location, params),                                                  (GLuint program, GLint location, GLfloat *params)) \
    GB_DECL_FWD_NR  (glGetUniformiv,                                   void,           (program, location, params),                                                  (GLuint program, GLint location, GLint *params)) \
    GB_DECL_FWD     (glGetUniformLocation,                             GLint,          (program, name),                                                              (GLuint program, const GLchar *name)) \
    GB_DECL_FWD_NR  (glGetVertexAttribfv,                              void,           (index, pname, params),                                                       (GLuint index, GLenum pname, GLfloat *params)) \
    GB_DECL_FWD_NR  (glGetVertexAttribiv,                              void,           (index, pname, params),                                                       (GLuint index, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetVertexAttribPointerv,                        void,           (index, pname, pointer),                                                      (GLuint index, GLenum pname, void **pointer)) \
    GB_DECL_FWD_NR  (glHint,                                           void,           (target, mode),                                                               (GLenum target, GLenum mode)) \
    GB_DECL_FWD     (glIsBuffer,                                       GLboolean,      (buffer),                                                                     (GLuint buffer)) \
    GB_DECL_FWD     (glIsEnabled,                                      GLboolean,      (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD     (glIsFramebuffer,                                  GLboolean,      (framebuffer),                                                                (GLuint framebuffer)) \
    GB_DECL_FWD     (glIsProgram,                                      GLboolean,      (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glIsRenderbuffer,                                 GLboolean,      (renderbuffer),                                                               (GLuint renderbuffer)) \
    GB_DECL_FWD     (glIsShader,                                       GLboolean,      (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD     (glIsTexture,                                      GLboolean,      (texture),                                                                    (GLuint texture)) \
    GB_DECL_FWD_NR  (glLineWidth,                                      void,           (width),                                                                      (GLfloat width)) \
    GB_DECL_FWD_NR  (glLinkProgram,                                    void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD_NR  (glPixelStorei,                                    void,           (pname, param),                                                               (GLenum pname, GLint param)) \
    GB_DECL_FWD_NR  (glPolygonOffset,                                  void,           (factor, units),                                                              (GLfloat factor, GLfloat units)) \
    GB_DECL_FWD_NR  (glReadPixels,                                     void,           (x, y, width, height, format, type, pixels),                                  (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)) \
    GB_DECL_FWD_NR  (glReleaseShaderCompiler,                          void,           (),                                                                           ()) \
    GB_DECL_FWD_NR  (glRenderbufferStorage,                            void,           (target, internalformat, width, height),                                      (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glSampleCoverage,                                 void,           (value, invert),                                                              (GLfloat value, GLboolean invert)) \
    GB_DECL_FWD_NR  (glScissor,                                        void,           (x, y, width, height),                                                        (GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glShaderBinary,                                   void,           (count, shaders, binaryformat, binary, length),                               (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)) \
    GB_DECL_FWD_NR  (glShaderSource,                                   void,           (shader, count, string, length),                                              (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)) \
    GB_DECL_FWD_NR  (glStencilFunc,                                    void,           (func, ref, mask),                                                            (GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilFuncSeparate,                            void,           (face, func, ref, mask),                                                      (GLenum face, GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilMask,                                    void,           (mask),                                                                       (GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilMaskSeparate,                            void,           (face, mask),                                                                 (GLenum face, GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilOp,                                      void,           (fail, zfail, zpass),                                                         (GLenum fail, GLenum zfail, GLenum zpass)) \
    GB_DECL_FWD_NR  (glStencilOpSeparate,                              void,           (face, sfail, dpfail, dppass),                                                (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)) \
    GB_DECL_FWD_NR  (glTexImage2D,                                     void,           (target, level, internalformat, width, height, border, format, type, pixels), (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD_NR  (glTexParameterf,                                  void,           (target, pname, param),                                                       (GLenum target, GLenum pname, GLfloat param)) \
    GB_DECL_FWD_NR  (glTexParameterfv,                                 void,           (target, pname, params),                                                      (GLenum target, GLenum pname, const GLfloat *params)) \
    GB_DECL_FWD_NR  (glTexParameteri,                                  void,           (target, pname, param),                                                       (GLenum target, GLenum pname, GLint param)) \
    GB_DECL_FWD_NR  (glTexParameteriv,                                 void,           (target, pname, params),                                                      (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD_NR  (glTexSubImage2D,                                  void,           (target, level, xoffset, yoffset, width, height, format, type, pixels),       (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD_NR  (glUniform1f,                                      void,           (location, v0),                                                               (GLint location, GLfloat v0)) \
    GB_DECL_FWD_NR  (glUniform1fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniform1i,                                      void,           (location, v0),                                                               (GLint location, GLint v0)) \
    GB_DECL_FWD_NR  (glUniform1iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glUniform2f,                                      void,           (location, v0, v1),                                                           (GLint location, GLfloat v0, GLfloat v1)) \
    GB_DECL_FWD_NR  (glUniform2fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniform2i,                                      void,           (location, v0, v1),                                                           (GLint location, GLint v0, GLint v1)) \
    GB_DECL_FWD_NR  (glUniform2iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glUniform3f,                                      void,           (location, v0, v1, v2),                                                       (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    GB_DECL_FWD_NR  (glUniform3fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniform3i,                                      void,           (location, v0, v1, v2),                                                       (GLint location, GLint v0, GLint v1, GLint v2)) \
    GB_DECL_FWD_NR  (glUniform3iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glUniform4f,                                      void,           (location, v0, v1, v2, v3),                                                   (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    GB_DECL_FWD_NR  (glUniform4fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniform4i,                                      void,           (location, v0, v1, v2, v3),                                                   (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    GB_DECL_FWD_NR  (glUniform4iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix2fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix3fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix4fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUseProgram,                                     void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD_NR  (glValidateProgram,                                void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD_NR  (glVertexAttrib1f,                                 void,           (index, x),                                                                   (GLuint index, GLfloat x)) \
    GB_DECL_FWD_NR  (glVertexAttrib1fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glVertexAttrib2f,                                 void,           (index, x, y),                                                                (GLuint index, GLfloat x, GLfloat y)) \
    GB_DECL_FWD_NR  (glVertexAttrib2fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glVertexAttrib3f,                                 void,           (index, x, y, z),                                                             (GLuint index, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD_NR  (glVertexAttrib3fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glVertexAttrib4f,                                 void,           (index, x, y, z, w),                                                          (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)) \
    GB_DECL_FWD_NR  (glVertexAttrib4fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glVertexAttribPointer,                            void,           (index, size, type, normalized, stride, pointer),                             (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)) \
    GB_DECL_FWD_NR  (glViewport,                                       void,           (x, y, width, height),                                                        (GLint x, GLint y, GLsizei width, GLsizei height))

#define GLES2_EXT_FUNCS \
    GB_DECL_FWD_NR  (glBlendBarrierKHR,                                void,           (), (void)) \
    GB_DECL_FWD_NR  (glDebugMessageControlKHR,                         void,           (source, type, severity, count, ids, enabled), (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)) \
    GB_DECL_FWD_NR  (glDebugMessageInsertKHR,                          void,           (source, type, id, severity, length, buf), (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)) \
    GB_DECL_FWD_NR  (glDebugMessageCallbackKHR,                        void,           (callback, userParam), (GLDEBUGPROCKHR callback, const void *userParam)) \
    GB_DECL_FWD     (glGetDebugMessageLogKHR,                          GLuint,         (count, bufSize, sources, types, ids, severities, lengths, messageLog), (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)) \
    GB_DECL_FWD_NR  (glPushDebugGroupKHR,                              void,           (source, id, length, message), (GLenum source, GLuint id, GLsizei length, const GLchar *message)) \
    GB_DECL_FWD_NR  (glPopDebugGroupKHR,                               void,           (), (void)) \
    GB_DECL_FWD_NR  (glObjectLabelKHR,                                 void,           (identifier, name, length, label), (GLenum identifier, GLuint name, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD_NR  (glGetObjectLabelKHR,                              void,           (identifier, name, bufSize, length, label), (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD_NR  (glObjectPtrLabelKHR,                              void,           (ptr, length, label), (const void *ptr, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD_NR  (glGetObjectPtrLabelKHR,                           void,           (ptr, bufSize, length, label), (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD_NR  (glGetPointervKHR,                                 void,           (pname, params), (GLenum pname, void **params)) \
    GB_DECL_FWD_NR  (glMaxShaderCompilerThreadsKHR,                    void,           (count), (GLuint count)) \
    GB_DECL_FWD     (glGetGraphicsResetStatusKHR,                      GLenum,         (), (void)) \
    GB_DECL_FWD_NR  (glReadnPixelsKHR,                                 void,           (x, y, width, height, format, type, bufSize, data), (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)) \
    GB_DECL_FWD_NR  (glGetnUniformfvKHR,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)) \
    GB_DECL_FWD_NR  (glGetnUniformivKHR,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD_NR  (glGetnUniformuivKHR,                              void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLuint *params)) \
    GB_DECL_FWD_NR  (glEGLImageTargetTexture2DOES,                     void,           (target, image), (GLenum target, GLeglImageOES image)) \
    GB_DECL_FWD_NR  (glEGLImageTargetRenderbufferStorageOES,           void,           (target, image), (GLenum target, GLeglImageOES image)) \
    GB_DECL_FWD_NR  (glCopyImageSubDataOES,                            void,           (srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth), (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)) \
    GB_DECL_FWD_NR  (glEnableiOES,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glDisableiOES,                                    void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glBlendEquationiOES,                              void,           (buf, mode), (GLuint buf, GLenum mode)) \
    GB_DECL_FWD_NR  (glBlendEquationSeparateiOES,                      void,           (buf, modeRGB, modeAlpha), (GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD_NR  (glBlendFunciOES,                                  void,           (buf, src, dst), (GLuint buf, GLenum src, GLenum dst)) \
    GB_DECL_FWD_NR  (glBlendFuncSeparateiOES,                          void,           (buf, srcRGB, dstRGB, srcAlpha, dstAlpha), (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    GB_DECL_FWD_NR  (glColorMaskiOES,                                  void,           (index, r, g, b, a), (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)) \
    GB_DECL_FWD     (glIsEnablediOES,                                  GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glDrawElementsBaseVertexOES,                      void,           (mode, count, type, indices, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD_NR  (glDrawRangeElementsBaseVertexOES,                 void,           (mode, start, end, count, type, indices, basevertex), (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedBaseVertexOES,             void,           (mode, count, type, indices, instancecount, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)) \
    GB_DECL_FWD_NR  (glMultiDrawElementsBaseVertexEXT,                 void,           (mode, count, type, indices, primcount, basevertex), (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, const GLint *basevertex)) \
    GB_DECL_FWD_NR  (glFramebufferTextureOES,                          void,           (target, attachment, texture, level), (GLenum target, GLenum attachment, GLuint texture, GLint level)) \
    GB_DECL_FWD_NR  (glGetProgramBinaryOES,                            void,           (program, bufSize, length, binaryFormat, binary), (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)) \
    GB_DECL_FWD_NR  (glProgramBinaryOES,                               void,           (program, binaryFormat, binary, length), (GLuint program, GLenum binaryFormat, const void *binary, GLint length)) \
    GB_DECL_FWD     (glMapBufferOES,                                   void*,          (target, access), (GLenum target, GLenum access)) \
    GB_DECL_FWD     (glUnmapBufferOES,                                 GLboolean,      (target), (GLenum target)) \
    GB_DECL_FWD_NR  (glGetBufferPointervOES,                           void,           (target, pname, params), (GLenum target, GLenum pname, void **params)) \
    GB_DECL_FWD_NR  (glPrimitiveBoundingBoxOES,                        void,           (minX, minY, minZ, minW, maxX, maxY, maxZ, maxW), (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)) \
    GB_DECL_FWD_NR  (glMinSampleShadingOES,                            void,           (value), (GLfloat value)) \
    GB_DECL_FWD_NR  (glPatchParameteriOES,                             void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD_NR  (glTexImage3DOES,                                  void,           (target, level, internalformat, width, height, depth, border, format, type, pixels), (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD_NR  (glTexSubImage3DOES,                               void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD_NR  (glCopyTexSubImage3DOES,                           void,           (target, level, xoffset, yoffset, zoffset, x, y, width, height), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glCompressedTexImage3DOES,                        void,           (target, level, internalformat, width, height, depth, border, imageSize, data), (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD_NR  (glCompressedTexSubImage3DOES,                     void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD_NR  (glFramebufferTexture3DOES,                        void,           (target, attachment, textarget, texture, level, zoffset), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)) \
    GB_DECL_FWD_NR  (glTexParameterIivOES,                             void,           (target, pname, params), (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD_NR  (glTexParameterIuivOES,                            void,           (target, pname, params), (GLenum target, GLenum pname, const GLuint *params)) \
    GB_DECL_FWD_NR  (glGetTexParameterIivOES,                          void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetTexParameterIuivOES,                         void,           (target, pname, params), (GLenum target, GLenum pname, GLuint *params)) \
    GB_DECL_FWD_NR  (glSamplerParameterIivOES,                         void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLint *param)) \
    GB_DECL_FWD_NR  (glSamplerParameterIuivOES,                        void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLuint *param)) \
    GB_DECL_FWD_NR  (glGetSamplerParameterIivOES,                      void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetSamplerParameterIuivOES,                     void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLuint *params)) \
    GB_DECL_FWD_NR  (glTexBufferOES,                                   void,           (target, internalformat, buffer), (GLenum target, GLenum internalformat, GLuint buffer)) \
    GB_DECL_FWD_NR  (glTexBufferRangeOES,                              void,           (target, internalformat, buffer, offset, size), (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    GB_DECL_FWD_NR  (glTexStorage3DMultisampleOES,                     void,           (target, samples, internalformat, width, height, depth, fixedsamplelocations), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)) \
    GB_DECL_FWD_NR  (glTextureViewOES,                                 void,           (texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers), (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)) \
    GB_DECL_FWD_NR  (glBindVertexArrayOES,                             void,           (array), (GLuint array)) \
    GB_DECL_FWD_NR  (glDeleteVertexArraysOES,                          void,           (n, arrays), (GLsizei n, const GLuint *arrays)) \
    GB_DECL_FWD_NR  (glGenVertexArraysOES,                             void,           (n, arrays), (GLsizei n, GLuint *arrays)) \
    GB_DECL_FWD     (glIsVertexArrayOES,                               GLboolean,      (array), (GLuint array)) \
    GB_DECL_FWD_NR  (glViewportArrayvOES,                              void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glViewportIndexedfOES,                            void,           (index, x, y, w, h), (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)) \
    GB_DECL_FWD_NR  (glViewportIndexedfvOES,                           void,           (index, v), (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glScissorArrayvOES,                               void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD_NR  (glScissorIndexedOES,                              void,           (index, left, bottom, width, height), (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glScissorIndexedvOES,                             void,           (index, v), (GLuint index, const GLint *v)) \
    GB_DECL_FWD_NR  (glDepthRangeArrayfvOES,                           void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glDepthRangeIndexedfOES,                          void,           (index, n, f), (GLuint index, GLfloat n, GLfloat f)) \
    GB_DECL_FWD_NR  (glGetFloati_vOES,                                 void,           (target, index, data), (GLenum target, GLuint index, GLfloat *data)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleAdvancedAMD,      void,           (target, samples, storageSamples, internalformat, width, height), (GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glNamedRenderbufferStorageMultisampleAdvancedAMD, void,           (renderbuffer, samples, storageSamples, internalformat, width, height), (GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorGroupsAMD,                        void,           (numGroups, groupsSize, groups), (GLint *numGroups, GLsizei groupsSize, GLuint *groups)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorCountersAMD,                      void,           (group, numCounters, maxActiveCounters, counterSize, counters), (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorGroupStringAMD,                   void,           (group, bufSize, length, groupString), (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorCounterStringAMD,                 void,           (group, counter, bufSize, length, counterString), (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorCounterInfoAMD,                   void,           (group, counter, pname, data), (GLuint group, GLuint counter, GLenum pname, void *data)) \
    GB_DECL_FWD_NR  (glGenPerfMonitorsAMD,                             void,           (n, monitors), (GLsizei n, GLuint *monitors)) \
    GB_DECL_FWD_NR  (glDeletePerfMonitorsAMD,                          void,           (n, monitors), (GLsizei n, GLuint *monitors)) \
    GB_DECL_FWD_NR  (glSelectPerfMonitorCountersAMD,                   void,           (monitor, enable, group, numCounters, counterList), (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList)) \
    GB_DECL_FWD_NR  (glBeginPerfMonitorAMD,                            void,           (monitor), (GLuint monitor)) \
    GB_DECL_FWD_NR  (glEndPerfMonitorAMD,                              void,           (monitor), (GLuint monitor)) \
    GB_DECL_FWD_NR  (glGetPerfMonitorCounterDataAMD,                   void,           (monitor, pname, dataSize, data, bytesWritten), (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten)) \
    GB_DECL_FWD_NR  (glBlitFramebufferANGLE,                           void,           (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter), (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleANGLE,            void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glDrawArraysInstancedANGLE,                       void,           (mode, first, count, primcount), (GLenum mode, GLint first, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedANGLE,                     void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glVertexAttribDivisorANGLE,                       void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD_NR  (glGetTranslatedShaderSourceANGLE,                 void,           (shader, bufsize, length, source), (GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source)) \
    GB_DECL_FWD_NR  (glCopyTextureLevelsAPPLE,                         void,           (destinationTexture, sourceTexture, sourceBaseLevel, sourceLevelCount), (GLuint destinationTexture, GLuint sourceTexture, GLint sourceBaseLevel, GLsizei sourceLevelCount)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleAPPLE,            void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glResolveMultisampleFramebufferAPPLE,             void,           (), (void)) \
    GB_DECL_FWD     (glFenceSyncAPPLE,                                 GLsync,         (condition, flags), (GLenum condition, GLbitfield flags)) \
    GB_DECL_FWD     (glIsSyncAPPLE,                                    GLboolean,      (sync), (GLsync sync)) \
    GB_DECL_FWD_NR  (glDeleteSyncAPPLE,                                void,           (sync), (GLsync sync)) \
    GB_DECL_FWD     (glClientWaitSyncAPPLE,                            GLenum,         (sync, flags, timeout), (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    GB_DECL_FWD_NR  (glWaitSyncAPPLE,                                  void,           (sync, flags, timeout), (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    GB_DECL_FWD_NR  (glGetInteger64vAPPLE,                             void,           (pname, params), (GLenum pname, GLint64 *params)) \
    GB_DECL_FWD_NR  (glGetSyncivAPPLE,                                 void,           (sync, pname, bufSize, length, values), (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)) \
    GB_DECL_FWD_NR  (glEGLImageTargetTexStorageEXT,                    void,           (target, image, attrib_list), (GLenum target, GLeglImageOES image, const GLint* attrib_list)) \
    GB_DECL_FWD_NR  (glEGLImageTargetTextureStorageEXT,                void,           (texture, image, attrib_list), (GLuint texture, GLeglImageOES image, const GLint* attrib_list)) \
    GB_DECL_FWD_NR  (glDrawArraysInstancedBaseInstanceEXT,             void,           (mode, first, count, instancecount, baseinstance), (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedBaseInstanceEXT,           void,           (mode, count, type, indices, instancecount, baseinstance), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedBaseVertexBaseInstanceEXT, void,           (mode, count, type, indices, instancecount, basevertex, baseinstance), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)) \
    GB_DECL_FWD_NR  (glBindFragDataLocationIndexedEXT,                 void,           (program, colorNumber, index, name), (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)) \
    GB_DECL_FWD_NR  (glBindFragDataLocationEXT,                        void,           (program, color, name), (GLuint program, GLuint color, const GLchar *name)) \
    GB_DECL_FWD     (glGetProgramResourceLocationIndexEXT,             GLint,          (program, programInterface, name), (GLuint program, GLenum programInterface, const GLchar *name)) \
    GB_DECL_FWD     (glGetFragDataIndexEXT,                            GLint,          (program, name), (GLuint program, const GLchar *name)) \
    GB_DECL_FWD_NR  (glBufferStorageEXT,                               void,           (target, size, data, flags), (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags)) \
    GB_DECL_FWD_NR  (glClearTexImageEXT,                               void,           (texture, level, format, type, data), (GLuint texture, GLint level, GLenum format, GLenum type, const void *data)) \
    GB_DECL_FWD_NR  (glClearTexSubImageEXT,                            void,           (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data), (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)) \
    GB_DECL_FWD_NR  (glClipControlEXT,                                 void,           (origin, depth), (GLenum origin, GLenum depth)) \
    GB_DECL_FWD_NR  (glCopyImageSubDataEXT,                            void,           (srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth), (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)) \
    GB_DECL_FWD_NR  (glLabelObjectEXT,                                 void,           (type, object, length, label), (GLenum type, GLuint object, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD_NR  (glGetObjectLabelEXT,                              void,           (type, object, bufSize, length, label), (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD_NR  (glInsertEventMarkerEXT,                           void,           (length, marker), (GLsizei length, const GLchar *marker)) \
    GB_DECL_FWD_NR  (glPushGroupMarkerEXT,                             void,           (length, marker), (GLsizei length, const GLchar *marker)) \
    GB_DECL_FWD_NR  (glPopGroupMarkerEXT,                              void,           (), (void)) \
    GB_DECL_FWD_HOOK(glDiscardFramebufferEXT,                     void,           (target, numAttachments, attachments), (GLenum target, GLsizei numAttachments, const GLenum *attachments)) \
    GB_DECL_FWD_NR  (glGenQueriesEXT,                                  void,           (n, ids), (GLsizei n, GLuint *ids)) \
    GB_DECL_FWD_NR  (glDeleteQueriesEXT,                               void,           (n, ids), (GLsizei n, const GLuint *ids)) \
    GB_DECL_FWD     (glIsQueryEXT,                                     GLboolean,      (id), (GLuint id)) \
    GB_DECL_FWD_NR  (glBeginQueryEXT,                                  void,           (target, id), (GLenum target, GLuint id)) \
    GB_DECL_FWD_NR  (glEndQueryEXT,                                    void,           (target), (GLenum target)) \
    GB_DECL_FWD_NR  (glQueryCounterEXT,                                void,           (id, target), (GLuint id, GLenum target)) \
    GB_DECL_FWD_NR  (glGetQueryivEXT,                                  void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetQueryObjectivEXT,                            void,           (id, pname, params), (GLuint id, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetQueryObjectuivEXT,                           void,           (id, pname, params), (GLuint id, GLenum pname, GLuint *params)) \
    GB_DECL_FWD_NR  (glGetQueryObjecti64vEXT,                          void,           (id, pname, params), (GLuint id, GLenum pname, GLint64 *params)) \
    GB_DECL_FWD_NR  (glGetQueryObjectui64vEXT,                         void,           (id, pname, params), (GLuint id, GLenum pname, GLuint64 *params)) \
    GB_DECL_FWD_NR  (glDrawBuffersEXT,                                 void,           (n, bufs), (GLsizei n, const GLenum *bufs)) \
    GB_DECL_FWD_NR  (glEnableiEXT,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glDisableiEXT,                                    void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glBlendEquationiEXT,                              void,           (buf, mode), (GLuint buf, GLenum mode)) \
    GB_DECL_FWD_NR  (glBlendEquationSeparateiEXT,                      void,           (buf, modeRGB, modeAlpha), (GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD_NR  (glBlendFunciEXT,                                  void,           (buf, src, dst), (GLuint buf, GLenum src, GLenum dst)) \
    GB_DECL_FWD_NR  (glBlendFuncSeparateiEXT,                          void,           (buf, srcRGB, dstRGB, srcAlpha, dstAlpha), (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    GB_DECL_FWD_NR  (glColorMaskiEXT,                                  void,           (index, r, g, b, a), (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)) \
    GB_DECL_FWD     (glIsEnablediEXT,                                  GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glDrawElementsBaseVertexEXT,                      void,           (mode, count, type, indices, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD_NR  (glDrawRangeElementsBaseVertexEXT,                 void,           (mode, start, end, count, type, indices, basevertex), (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedBaseVertexEXT,             void,           (mode, count, type, indices, instancecount, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)) \
    GB_DECL_FWD_NR  (glDrawArraysInstancedEXT,                         void,           (mode, start, count, primcount), (GLenum mode, GLint start, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedEXT,                       void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glDrawTransformFeedbackEXT,                       void,           (mode, id), (GLenum mode, GLuint id)) \
    GB_DECL_FWD_NR  (glDrawTransformFeedbackInstancedEXT,              void,           (mode, id, instancecount), (GLenum mode, GLuint id, GLsizei instancecount)) \
    GB_DECL_FWD_NR  (glBufferStorageExternalEXT,                       void,           (target, offset, size, clientBuffer, flags), (GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags)) \
    GB_DECL_FWD_NR  (glNamedBufferStorageExternalEXT,                  void,           (buffer, offset, size, clientBuffer, flags), (GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags)) \
    GB_DECL_FWD_NR  (glFramebufferTextureEXT,                          void,           (target, attachment, texture, level), (GLenum target, GLenum attachment, GLuint texture, GLint level)) \
    GB_DECL_FWD_NR  (glVertexAttribDivisorEXT,                         void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD     (glMapBufferRangeEXT,                              void*,          (target, offset, length, access), (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)) \
    GB_DECL_FWD_NR  (glFlushMappedBufferRangeEXT,                      void,           (target, offset, length), (GLenum target, GLintptr offset, GLsizeiptr length)) \
    GB_DECL_FWD_NR  (glGetUnsignedBytevEXT,                            void,           (pname, data), (GLenum pname, GLubyte *data)) \
    GB_DECL_FWD_NR  (glGetUnsignedBytei_vEXT,                          void,           (target, index, data), (GLenum target, GLuint index, GLubyte *data)) \
    GB_DECL_FWD_NR  (glDeleteMemoryObjectsEXT,                         void,           (n, memoryObjects), (GLsizei n, const GLuint *memoryObjects)) \
    GB_DECL_FWD     (glIsMemoryObjectEXT,                              GLboolean,      (memoryObject), (GLuint memoryObject)) \
    GB_DECL_FWD_NR  (glCreateMemoryObjectsEXT,                         void,           (n, memoryObjects), (GLsizei n, GLuint *memoryObjects)) \
    GB_DECL_FWD_NR  (glMemoryObjectParameterivEXT,                     void,           (memoryObject, pname, params), (GLuint memoryObject, GLenum pname, const GLint *params)) \
    GB_DECL_FWD_NR  (glGetMemoryObjectParameterivEXT,                  void,           (memoryObject, pname, params), (GLuint memoryObject, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glTexStorageMem2DEXT,                             void,           (target, levels, internalFormat, width, height, memory, offset), (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTexStorageMem2DMultisampleEXT,                  void,           (target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset), (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTexStorageMem3DEXT,                             void,           (target, levels, internalFormat, width, height, depth, memory, offset), (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTexStorageMem3DMultisampleEXT,                  void,           (target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset), (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glBufferStorageMemEXT,                            void,           (target, size, memory, offset), (GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTextureStorageMem2DEXT,                         void,           (texture, levels, internalFormat, width, height, memory, offset), (GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTextureStorageMem2DMultisampleEXT,              void,           (texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset), (GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTextureStorageMem3DEXT,                         void,           (texture, levels, internalFormat, width, height, depth, memory, offset), (GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTextureStorageMem3DMultisampleEXT,              void,           (texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset), (GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glNamedBufferStorageMemEXT,                       void,           (buffer, size, memory, offset), (GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glImportMemoryFdEXT,                              void,           (memory, size, handleType, fd), (GLuint memory, GLuint64 size, GLenum handleType, GLint fd)) \
    GB_DECL_FWD_NR  (glImportMemoryWin32HandleEXT,                     void,           (memory, size, handleType, handle), (GLuint memory, GLuint64 size, GLenum handleType, void *handle)) \
    GB_DECL_FWD_NR  (glImportMemoryWin32NameEXT,                       void,           (memory, size, handleType, name), (GLuint memory, GLuint64 size, GLenum handleType, const void *name)) \
    GB_DECL_FWD_NR  (glMultiDrawArraysEXT,                             void,           (mode, first, count, primcount), (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glMultiDrawElementsEXT,                           void,           (mode, count, type, indices, primcount), (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glMultiDrawArraysIndirectEXT,                     void,           (mode, indirect, drawcount, stride), (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD_NR  (glMultiDrawElementsIndirectEXT,                   void,           (mode, type, indirect, drawcount, stride), (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleEXT,              void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glFramebufferTexture2DMultisampleEXT,             void,           (target, attachment, textarget, texture, level, samples), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)) \
    GB_DECL_FWD_NR  (glReadBufferIndexedEXT,                           void,           (src, index), (GLenum src, GLint index)) \
    GB_DECL_FWD_NR  (glDrawBuffersIndexedEXT,                          void,           (n, location, indices), (GLint n, const GLenum *location, const GLint *indices)) \
    GB_DECL_FWD_NR  (glGetIntegeri_vEXT,                               void,           (target, index, data), (GLenum target, GLuint index, GLint *data)) \
    GB_DECL_FWD_NR  (glPolygonOffsetClampEXT,                          void,           (factor, units, clamp), (GLfloat factor, GLfloat units, GLfloat clamp)) \
    GB_DECL_FWD_NR  (glPrimitiveBoundingBoxEXT,                        void,           (minX, minY, minZ, minW, maxX, maxY, maxZ, maxW), (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)) \
    GB_DECL_FWD_NR  (glRasterSamplesEXT,                               void,           (samples, fixedsamplelocations), (GLuint samples, GLboolean fixedsamplelocations)) \
    GB_DECL_FWD     (glGetGraphicsResetStatusEXT,                      GLenum,         (), (void)) \
    GB_DECL_FWD_NR  (glReadnPixelsEXT,                                 void,           (x, y, width, height, format, type, bufSize, data), (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)) \
    GB_DECL_FWD_NR  (glGetnUniformfvEXT,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)) \
    GB_DECL_FWD_NR  (glGetnUniformivEXT,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD_NR  (glGenSemaphoresEXT,                               void,           (n, semaphores), (GLsizei n, GLuint *semaphores)) \
    GB_DECL_FWD_NR  (glDeleteSemaphoresEXT,                            void,           (n, semaphores), (GLsizei n, const GLuint *semaphores)) \
    GB_DECL_FWD     (glIsSemaphoreEXT,                                 GLboolean,      (semaphore), (GLuint semaphore)) \
    GB_DECL_FWD_NR  (glSemaphoreParameterui64vEXT,                     void,           (semaphore, pname, params), (GLuint semaphore, GLenum pname, const GLuint64 *params)) \
    GB_DECL_FWD_NR  (glGetSemaphoreParameterui64vEXT,                  void,           (semaphore, pname, params), (GLuint semaphore, GLenum pname, GLuint64 *params)) \
    GB_DECL_FWD_NR  (glWaitSemaphoreEXT,                               void,           (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts), (GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *srcLayouts)) \
    GB_DECL_FWD_NR  (glSignalSemaphoreEXT,                             void,           (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts), (GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *dstLayouts)) \
    GB_DECL_FWD_NR  (glImportSemaphoreFdEXT,                           void,           (semaphore, handleType, fd), (GLuint semaphore, GLenum handleType, GLint fd)) \
    GB_DECL_FWD_NR  (glImportSemaphoreWin32HandleEXT,                  void,           (semaphore, handleType, handle), (GLuint semaphore, GLenum handleType, void *handle)) \
    GB_DECL_FWD_NR  (glImportSemaphoreWin32NameEXT,                    void,           (semaphore, handleType, name), (GLuint semaphore, GLenum handleType, const void *name)) \
    GB_DECL_FWD_NR  (glActiveShaderProgramEXT,                         void,           (pipeline, program), (GLuint pipeline, GLuint program)) \
    GB_DECL_FWD_NR  (glBindProgramPipelineEXT,                         void,           (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD     (glCreateShaderProgramvEXT,                        GLuint,         (type, count, strings), (GLenum type, GLsizei count, const GLchar **strings)) \
    GB_DECL_FWD_NR  (glDeleteProgramPipelinesEXT,                      void,           (n, pipelines), (GLsizei n, const GLuint *pipelines)) \
    GB_DECL_FWD_NR  (glGenProgramPipelinesEXT,                         void,           (n, pipelines), (GLsizei n, GLuint *pipelines)) \
    GB_DECL_FWD_NR  (glGetProgramPipelineInfoLogEXT,                   void,           (pipeline, bufSize, length, infoLog), (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD_NR  (glGetProgramPipelineivEXT,                        void,           (pipeline, pname, params), (GLuint pipeline, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glIsProgramPipelineEXT,                           GLboolean,      (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD_NR  (glProgramParameteriEXT,                           void,           (program, pname, value), (GLuint program, GLenum pname, GLint value)) \
    GB_DECL_FWD_NR  (glProgramUniform1fEXT,                            void,           (program, location, v0), (GLuint program, GLint location, GLfloat v0)) \
    GB_DECL_FWD_NR  (glProgramUniform1fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniform1iEXT,                            void,           (program, location, v0), (GLuint program, GLint location, GLint v0)) \
    GB_DECL_FWD_NR  (glProgramUniform1ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform2fEXT,                            void,           (program, location, v0, v1), (GLuint program, GLint location, GLfloat v0, GLfloat v1)) \
    GB_DECL_FWD_NR  (glProgramUniform2fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniform2iEXT,                            void,           (program, location, v0, v1), (GLuint program, GLint location, GLint v0, GLint v1)) \
    GB_DECL_FWD_NR  (glProgramUniform2ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform3fEXT,                            void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    GB_DECL_FWD_NR  (glProgramUniform3fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniform3iEXT,                            void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLint v0, GLint v1, GLint v2)) \
    GB_DECL_FWD_NR  (glProgramUniform3ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform4fEXT,                            void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    GB_DECL_FWD_NR  (glProgramUniform4fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniform4iEXT,                            void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    GB_DECL_FWD_NR  (glProgramUniform4ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix2fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix3fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix4fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUseProgramStagesEXT,                            void,           (pipeline, stages, program), (GLuint pipeline, GLbitfield stages, GLuint program)) \
    GB_DECL_FWD_NR  (glValidateProgramPipelineEXT,                     void,           (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD_NR  (glProgramUniform1uiEXT,                           void,           (program, location, v0), (GLuint program, GLint location, GLuint v0)) \
    GB_DECL_FWD_NR  (glProgramUniform2uiEXT,                           void,           (program, location, v0, v1), (GLuint program, GLint location, GLuint v0, GLuint v1)) \
    GB_DECL_FWD_NR  (glProgramUniform3uiEXT,                           void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)) \
    GB_DECL_FWD_NR  (glProgramUniform4uiEXT,                           void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \
    GB_DECL_FWD_NR  (glProgramUniform1uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform2uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform3uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD_NR  (glProgramUniform4uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix2x3fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix3x2fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix2x4fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix4x2fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix3x4fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glProgramUniformMatrix4x3fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glFramebufferFetchBarrierEXT,                     void,           (), (void)) \
    GB_DECL_FWD_NR  (glFramebufferPixelLocalStorageSizeEXT,            void,           (target, size), (GLuint target, GLsizei size)) \
    GB_DECL_FWD     (glGetFramebufferPixelLocalStorageSizeEXT,         GLsizei,        (target), (GLuint target)) \
    GB_DECL_FWD_NR  (glClearPixelLocalStorageuiEXT,                    void,           (offset, n, values), (GLsizei offset, GLsizei n, const GLuint *values)) \
    GB_DECL_FWD_NR  (glTexPageCommitmentEXT,                           void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, commit), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit)) \
    GB_DECL_FWD_NR  (glPatchParameteriEXT,                             void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD_NR  (glTexParameterIivEXT,                             void,           (target, pname, params), (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD_NR  (glTexParameterIuivEXT,                            void,           (target, pname, params), (GLenum target, GLenum pname, const GLuint *params)) \
    GB_DECL_FWD_NR  (glGetTexParameterIivEXT,                          void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetTexParameterIuivEXT,                         void,           (target, pname, params), (GLenum target, GLenum pname, GLuint *params)) \
    GB_DECL_FWD_NR  (glSamplerParameterIivEXT,                         void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLint *param)) \
    GB_DECL_FWD_NR  (glSamplerParameterIuivEXT,                        void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLuint *param)) \
    GB_DECL_FWD_NR  (glGetSamplerParameterIivEXT,                      void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glGetSamplerParameterIuivEXT,                     void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLuint *params)) \
    GB_DECL_FWD_NR  (glTexBufferEXT,                                   void,           (target, internalformat, buffer), (GLenum target, GLenum internalformat, GLuint buffer)) \
    GB_DECL_FWD_NR  (glTexBufferRangeEXT,                              void,           (target, internalformat, buffer, offset, size), (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    GB_DECL_FWD_NR  (glTexStorage1DEXT,                                void,           (target, levels, internalformat, width), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)) \
    GB_DECL_FWD_NR  (glTexStorage2DEXT,                                void,           (target, levels, internalformat, width, height), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glTexStorage3DEXT,                                void,           (target, levels, internalformat, width, height, depth), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    GB_DECL_FWD_NR  (glTextureStorage1DEXT,                            void,           (texture, target, levels, internalformat, width), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)) \
    GB_DECL_FWD_NR  (glTextureStorage2DEXT,                            void,           (texture, target, levels, internalformat, width, height), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glTextureStorage3DEXT,                            void,           (texture, target, levels, internalformat, width, height, depth), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    GB_DECL_FWD_NR  (glTextureViewEXT,                                 void,           (texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers), (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)) \
    GB_DECL_FWD     (glAcquireKeyedMutexWin32EXT,                      GLboolean,      (memory, key, timeout), (GLuint memory, GLuint64 key, GLuint timeout)) \
    GB_DECL_FWD     (glReleaseKeyedMutexWin32EXT,                      GLboolean,      (memory, key), (GLuint memory, GLuint64 key)) \
    GB_DECL_FWD_NR  (glWindowRectanglesEXT,                            void,           (mode, count, box), (GLenum mode, GLsizei count, const GLint *box)) \
    GB_DECL_FWD     (glGetTextureHandleIMG,                            GLuint64,       (texture), (GLuint texture)) \
    GB_DECL_FWD     (glGetTextureSamplerHandleIMG,                     GLuint64,       (texture, sampler), (GLuint texture, GLuint sampler)) \
    GB_DECL_FWD_NR  (glUniformHandleui64IMG,                           void,           (location, value), (GLint location, GLuint64 value)) \
    GB_DECL_FWD_NR  (glUniformHandleui64vIMG,                          void,           (location, count, value), (GLint location, GLsizei count, const GLuint64 *value)) \
    GB_DECL_FWD_NR  (glProgramUniformHandleui64IMG,                    void,           (program, location, value), (GLuint program, GLint location, GLuint64 value)) \
    GB_DECL_FWD_NR  (glProgramUniformHandleui64vIMG,                   void,           (program, location, count, values), (GLuint program, GLint location, GLsizei count, const GLuint64 *values)) \
    GB_DECL_FWD_NR  (glFramebufferTexture2DDownsampleIMG,              void,           (target, attachment, textarget, texture, level, xscale, yscale), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint xscale, GLint yscale)) \
    GB_DECL_FWD_NR  (glFramebufferTextureLayerDownsampleIMG,           void,           (target, attachment, texture, level, layer, xscale, yscale), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLint xscale, GLint yscale)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleIMG,              void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glFramebufferTexture2DMultisampleIMG,             void,           (target, attachment, textarget, texture, level, samples), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)) \
    GB_DECL_FWD_NR  (glApplyFramebufferAttachmentCMAAINTEL,            void,           (), (void)) \
    GB_DECL_FWD_NR  (glBeginPerfQueryINTEL,                            void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD_NR  (glCreatePerfQueryINTEL,                           void,           (queryId, queryHandle), (GLuint queryId, GLuint *queryHandle)) \
    GB_DECL_FWD_NR  (glDeletePerfQueryINTEL,                           void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD_NR  (glEndPerfQueryINTEL,                              void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD_NR  (glGetFirstPerfQueryIdINTEL,                       void,           (queryId), (GLuint *queryId)) \
    GB_DECL_FWD_NR  (glGetNextPerfQueryIdINTEL,                        void,           (queryId, nextQueryId), (GLuint queryId, GLuint *nextQueryId)) \
    GB_DECL_FWD_NR  (glGetPerfCounterInfoINTEL,                        void,           (queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue), (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue)) \
    GB_DECL_FWD_NR  (glGetPerfQueryDataINTEL,                          void,           (queryHandle, flags, dataSize, data, bytesWritten), (GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten)) \
    GB_DECL_FWD_NR  (glGetPerfQueryIdByNameINTEL,                      void,           (queryName, queryId), (GLchar *queryName, GLuint *queryId)) \
    GB_DECL_FWD_NR  (glGetPerfQueryInfoINTEL,                          void,           (queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask), (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask)) \
    GB_DECL_FWD     (glGetTextureHandleNV,                             GLuint64,       (texture), (GLuint texture)) \
    GB_DECL_FWD     (glGetTextureSamplerHandleNV,                      GLuint64,       (texture, sampler), (GLuint texture, GLuint sampler)) \
    GB_DECL_FWD_NR  (glMakeTextureHandleResidentNV,                    void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD_NR  (glMakeTextureHandleNonResidentNV,                 void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glGetImageHandleNV,                               GLuint64,       (texture, level, layered, layer, format), (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)) \
    GB_DECL_FWD_NR  (glMakeImageHandleResidentNV,                      void,           (handle, access), (GLuint64 handle, GLenum access)) \
    GB_DECL_FWD_NR  (glMakeImageHandleNonResidentNV,                   void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD_NR  (glUniformHandleui64NV,                            void,           (location, value), (GLint location, GLuint64 value)) \
    GB_DECL_FWD_NR  (glUniformHandleui64vNV,                           void,           (location, count, value), (GLint location, GLsizei count, const GLuint64 *value)) \
    GB_DECL_FWD_NR  (glProgramUniformHandleui64NV,                     void,           (program, location, value), (GLuint program, GLint location, GLuint64 value)) \
    GB_DECL_FWD_NR  (glProgramUniformHandleui64vNV,                    void,           (program, location, count, values), (GLuint program, GLint location, GLsizei count, const GLuint64 *values)) \
    GB_DECL_FWD     (glIsTextureHandleResidentNV,                      GLboolean,      (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glIsImageHandleResidentNV,                        GLboolean,      (handle), (GLuint64 handle)) \
    GB_DECL_FWD_NR  (glBlendParameteriNV,                              void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD_NR  (glBlendBarrierNV,                                 void,           (), (void)) \
    GB_DECL_FWD_NR  (glViewportPositionWScaleNV,                       void,           (index, xcoeff, ycoeff), (GLuint index, GLfloat xcoeff, GLfloat ycoeff)) \
    GB_DECL_FWD_NR  (glBeginConditionalRenderNV,                       void,           (id, mode), (GLuint id, GLenum mode)) \
    GB_DECL_FWD_NR  (glEndConditionalRenderNV,                         void,           (), (void)) \
    GB_DECL_FWD_NR  (glSubpixelPrecisionBiasNV,                        void,           (xbits, ybits), (GLuint xbits, GLuint ybits)) \
    GB_DECL_FWD_NR  (glConservativeRasterParameteriNV,                 void,           (pname, param), (GLenum pname, GLint param)) \
    GB_DECL_FWD_NR  (glCopyBufferSubDataNV,                            void,           (readTarget, writeTarget, readOffset, writeOffset, size), (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)) \
    GB_DECL_FWD_NR  (glCoverageMaskNV,                                 void,           (mask), (GLboolean mask)) \
    GB_DECL_FWD_NR  (glCoverageOperationNV,                            void,           (operation), (GLenum operation)) \
    GB_DECL_FWD_NR  (glDrawBuffersNV,                                  void,           (n, bufs), (GLsizei n, const GLenum *bufs)) \
    GB_DECL_FWD_NR  (glDrawArraysInstancedNV,                          void,           (mode, first, count, primcount), (GLenum mode, GLint first, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glDrawElementsInstancedNV,                        void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD_NR  (glDrawVkImageNV,                                  void,           (vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1), (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)) \
    GB_DECL_FWD     (glGetVkProcAddrNV,                                GLVULKANPROCNV, (name), (const GLchar *name)) \
    GB_DECL_FWD_NR  (glWaitVkSemaphoreNV,                              void,           (vkSemaphore), (GLuint64 vkSemaphore)) \
    GB_DECL_FWD_NR  (glSignalVkSemaphoreNV,                            void,           (vkSemaphore), (GLuint64 vkSemaphore)) \
    GB_DECL_FWD_NR  (glSignalVkFenceNV,                                void,           (vkFence), (GLuint64 vkFence)) \
    GB_DECL_FWD_NR  (glDeleteFencesNV,                                 void,           (n, fences), (GLsizei n, const GLuint *fences)) \
    GB_DECL_FWD_NR  (glGenFencesNV,                                    void,           (n, fences), (GLsizei n, GLuint *fences)) \
    GB_DECL_FWD     (glIsFenceNV,                                      GLboolean,      (fence), (GLuint fence)) \
    GB_DECL_FWD     (glTestFenceNV,                                    GLboolean,      (fence), (GLuint fence)) \
    GB_DECL_FWD_NR  (glGetFenceivNV,                                   void,           (fence, pname, params), (GLuint fence, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glFinishFenceNV,                                  void,           (fence), (GLuint fence)) \
    GB_DECL_FWD_NR  (glSetFenceNV,                                     void,           (fence, condition), (GLuint fence, GLenum condition)) \
    GB_DECL_FWD_NR  (glFragmentCoverageColorNV,                        void,           (color), (GLuint color)) \
    GB_DECL_FWD_NR  (glBlitFramebufferNV,                              void,           (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter), (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    GB_DECL_FWD_NR  (glCoverageModulationTableNV,                      void,           (n, v), (GLsizei n, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glGetCoverageModulationTableNV,                   void,           (bufsize, v), (GLsizei bufsize, GLfloat *v)) \
    GB_DECL_FWD_NR  (glCoverageModulationNV,                           void,           (components), (GLenum components)) \
    GB_DECL_FWD_NR  (glRenderbufferStorageMultisampleNV,               void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glUniform1i64NV,                                  void,           (location, x), (GLint location, GLint64EXT x)) \
    GB_DECL_FWD_NR  (glUniform2i64NV,                                  void,           (location, x, y), (GLint location, GLint64EXT x, GLint64EXT y)) \
    GB_DECL_FWD_NR  (glUniform3i64NV,                                  void,           (location, x, y, z), (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)) \
    GB_DECL_FWD_NR  (glUniform4i64NV,                                  void,           (location, x, y, z, w), (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)) \
    GB_DECL_FWD_NR  (glUniform1i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform2i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform3i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform4i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform1ui64NV,                                 void,           (location, x), (GLint location, GLuint64EXT x)) \
    GB_DECL_FWD_NR  (glUniform2ui64NV,                                 void,           (location, x, y), (GLint location, GLuint64EXT x, GLuint64EXT y)) \
    GB_DECL_FWD_NR  (glUniform3ui64NV,                                 void,           (location, x, y, z), (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)) \
    GB_DECL_FWD_NR  (glUniform4ui64NV,                                 void,           (location, x, y, z, w), (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)) \
    GB_DECL_FWD_NR  (glUniform1ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform2ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform3ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glUniform4ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glGetUniformi64vNV,                               void,           (program, location, params), (GLuint program, GLint location, GLint64EXT *params)) \
    GB_DECL_FWD_NR  (glProgramUniform1i64NV,                           void,           (program, location, x), (GLuint program, GLint location, GLint64EXT x)) \
    GB_DECL_FWD_NR  (glProgramUniform2i64NV,                           void,           (program, location, x, y), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y)) \
    GB_DECL_FWD_NR  (glProgramUniform3i64NV,                           void,           (program, location, x, y, z), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)) \
    GB_DECL_FWD_NR  (glProgramUniform4i64NV,                           void,           (program, location, x, y, z, w), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)) \
    GB_DECL_FWD_NR  (glProgramUniform1i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform2i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform3i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform4i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform1ui64NV,                          void,           (program, location, x), (GLuint program, GLint location, GLuint64EXT x)) \
    GB_DECL_FWD_NR  (glProgramUniform2ui64NV,                          void,           (program, location, x, y), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y)) \
    GB_DECL_FWD_NR  (glProgramUniform3ui64NV,                          void,           (program, location, x, y, z), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)) \
    GB_DECL_FWD_NR  (glProgramUniform4ui64NV,                          void,           (program, location, x, y, z, w), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)) \
    GB_DECL_FWD_NR  (glProgramUniform1ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform2ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform3ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glProgramUniform4ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD_NR  (glVertexAttribDivisorNV,                          void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD_NR  (glGetInternalformatSampleivNV,                    void,           (target, internalformat, samples, pname, bufSize, params), (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD_NR  (glGetMemoryObjectDetachedResourcesuivNV,          void,           (memory, pname, first, count, params), (GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params)) \
    GB_DECL_FWD_NR  (glResetMemoryObjectParameterNV,                   void,           (memory, pname), (GLuint memory, GLenum pname)) \
    GB_DECL_FWD_NR  (glTexAttachMemoryNV,                              void,           (target, memory, offset), (GLenum target, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glBufferAttachMemoryNV,                           void,           (target, memory, offset), (GLenum target, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glTextureAttachMemoryNV,                          void,           (texture, memory, offset), (GLuint texture, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glNamedBufferAttachMemoryNV,                      void,           (buffer, memory, offset), (GLuint buffer, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD_NR  (glDrawMeshTasksNV,                                void,           (first, count), (GLuint first, GLuint count)) \
    GB_DECL_FWD_NR  (glDrawMeshTasksIndirectNV,                        void,           (indirect), (GLintptr indirect)) \
    GB_DECL_FWD_NR  (glMultiDrawMeshTasksIndirectNV,                   void,           (indirect, drawcount, stride), (GLintptr indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD_NR  (glMultiDrawMeshTasksIndirectCountNV,              void,           (indirect, drawcount, maxdrawcount, stride), (GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)) \
    GB_DECL_FWD_NR  (glUniformMatrix2x3fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix3x2fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix2x4fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix4x2fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix3x4fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glUniformMatrix4x3fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glGenPathsNV,                                     GLuint,         (range), (GLsizei range)) \
    GB_DECL_FWD_NR  (glDeletePathsNV,                                  void,           (path, range), (GLuint path, GLsizei range)) \
    GB_DECL_FWD     (glIsPathNV,                                       GLboolean,      (path), (GLuint path)) \
    GB_DECL_FWD_NR  (glPathCommandsNV,                                 void,           (path, numCommands, commands, numCoords, coordType, coords), (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD_NR  (glPathCoordsNV,                                   void,           (path, numCoords, coordType, coords), (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD_NR  (glPathSubCommandsNV,                              void,           (path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords), (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD_NR  (glPathSubCoordsNV,                                void,           (path, coordStart, numCoords, coordType, coords), (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD_NR  (glPathStringNV,                                   void,           (path, format, length, pathString), (GLuint path, GLenum format, GLsizei length, const void *pathString)) \
    GB_DECL_FWD_NR  (glPathGlyphsNV,                                   void,           (firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD_NR  (glPathGlyphRangeNV,                               void,           (firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD_NR  (glWeightPathsNV,                                  void,           (resultPath, numPaths, paths, weights), (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights)) \
    GB_DECL_FWD_NR  (glCopyPathNV,                                     void,           (resultPath, srcPath), (GLuint resultPath, GLuint srcPath)) \
    GB_DECL_FWD_NR  (glInterpolatePathsNV,                             void,           (resultPath, pathA, pathB, weight), (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)) \
    GB_DECL_FWD_NR  (glTransformPathNV,                                void,           (resultPath, srcPath, transformType, transformValues), (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glPathParameterivNV,                              void,           (path, pname, value), (GLuint path, GLenum pname, const GLint *value)) \
    GB_DECL_FWD_NR  (glPathParameteriNV,                               void,           (path, pname, value), (GLuint path, GLenum pname, GLint value)) \
    GB_DECL_FWD_NR  (glPathParameterfvNV,                              void,           (path, pname, value), (GLuint path, GLenum pname, const GLfloat *value)) \
    GB_DECL_FWD_NR  (glPathParameterfNV,                               void,           (path, pname, value), (GLuint path, GLenum pname, GLfloat value)) \
    GB_DECL_FWD_NR  (glPathDashArrayNV,                                void,           (path, dashCount, dashArray), (GLuint path, GLsizei dashCount, const GLfloat *dashArray)) \
    GB_DECL_FWD_NR  (glPathStencilFuncNV,                              void,           (func, ref, mask), (GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD_NR  (glPathStencilDepthOffsetNV,                       void,           (factor, units), (GLfloat factor, GLfloat units)) \
    GB_DECL_FWD_NR  (glStencilFillPathNV,                              void,           (path, fillMode, mask), (GLuint path, GLenum fillMode, GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilStrokePathNV,                            void,           (path, reference, mask), (GLuint path, GLint reference, GLuint mask)) \
    GB_DECL_FWD_NR  (glStencilFillPathInstancedNV,                     void,           (numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glStencilStrokePathInstancedNV,                   void,           (numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glPathCoverDepthFuncNV,                           void,           (func), (GLenum func)) \
    GB_DECL_FWD_NR  (glCoverFillPathNV,                                void,           (path, coverMode), (GLuint path, GLenum coverMode)) \
    GB_DECL_FWD_NR  (glCoverStrokePathNV,                              void,           (path, coverMode), (GLuint path, GLenum coverMode)) \
    GB_DECL_FWD_NR  (glCoverFillPathInstancedNV,                       void,           (numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glCoverStrokePathInstancedNV,                     void,           (numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glGetPathParameterivNV,                           void,           (path, pname, value), (GLuint path, GLenum pname, GLint *value)) \
    GB_DECL_FWD_NR  (glGetPathParameterfvNV,                           void,           (path, pname, value), (GLuint path, GLenum pname, GLfloat *value)) \
    GB_DECL_FWD_NR  (glGetPathCommandsNV,                              void,           (path, commands), (GLuint path, GLubyte *commands)) \
    GB_DECL_FWD_NR  (glGetPathCoordsNV,                                void,           (path, coords), (GLuint path, GLfloat *coords)) \
    GB_DECL_FWD_NR  (glGetPathDashArrayNV,                             void,           (path, dashArray), (GLuint path, GLfloat *dashArray)) \
    GB_DECL_FWD_NR  (glGetPathMetricsNV,                               void,           (metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics), (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics)) \
    GB_DECL_FWD_NR  (glGetPathMetricRangeNV,                           void,           (metricQueryMask, firstPathName, numPaths, stride, metrics), (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics)) \
    GB_DECL_FWD_NR  (glGetPathSpacingNV,                               void,           (pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing), (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing)) \
    GB_DECL_FWD     (glIsPointInFillPathNV,                            GLboolean,      (path, mask, x, y), (GLuint path, GLuint mask, GLfloat x, GLfloat y)) \
    GB_DECL_FWD     (glIsPointInStrokePathNV,                          GLboolean,      (path, x, y), (GLuint path, GLfloat x, GLfloat y)) \
    GB_DECL_FWD     (glGetPathLengthNV,                                GLfloat,        (path, startSegment, numSegments), (GLuint path, GLsizei startSegment, GLsizei numSegments)) \
    GB_DECL_FWD     (glPointAlongPathNV,                               GLboolean,      (path, startSegment, numSegments, distance, x, y, tangentX, tangentY), (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY)) \
    GB_DECL_FWD_NR  (glMatrixLoad3x2fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixLoad3x3fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixLoadTranspose3x3fNV,                      void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixMult3x2fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixMult3x3fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixMultTranspose3x3fNV,                      void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glStencilThenCoverFillPathNV,                     void,           (path, fillMode, mask, coverMode), (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)) \
    GB_DECL_FWD_NR  (glStencilThenCoverStrokePathNV,                   void,           (path, reference, mask, coverMode), (GLuint path, GLint reference, GLuint mask, GLenum coverMode)) \
    GB_DECL_FWD_NR  (glStencilThenCoverFillPathInstancedNV,            void,           (numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD_NR  (glStencilThenCoverStrokePathInstancedNV,          void,           (numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glPathGlyphIndexRangeNV,                          GLenum,         (fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount), (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2])) \
    GB_DECL_FWD     (glPathGlyphIndexArrayNV,                          GLenum,         (firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD     (glPathMemoryGlyphIndexArrayNV,                    GLenum,         (firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD_NR  (glProgramPathFragmentInputGenNV,                  void,           (program, location, genMode, components, coeffs), (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs)) \
    GB_DECL_FWD_NR  (glGetProgramResourcefvNV,                         void,           (program, programInterface, index, propCount, props, bufSize, length, params), (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params)) \
    GB_DECL_FWD_NR  (glMatrixFrustumEXT,                               void,           (mode, left, right, bottom, top, zNear, zFar), (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)) \
    GB_DECL_FWD_NR  (glMatrixLoadIdentityEXT,                          void,           (mode), (GLenum mode)) \
    GB_DECL_FWD_NR  (glMatrixLoadTransposefEXT,                        void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixLoadTransposedEXT,                        void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD_NR  (glMatrixLoadfEXT,                                 void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixLoaddEXT,                                 void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD_NR  (glMatrixMultTransposefEXT,                        void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixMultTransposedEXT,                        void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD_NR  (glMatrixMultfEXT,                                 void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD_NR  (glMatrixMultdEXT,                                 void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD_NR  (glMatrixOrthoEXT,                                 void,           (mode, left, right, bottom, top, zNear, zFar), (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)) \
    GB_DECL_FWD_NR  (glMatrixPopEXT,                                   void,           (mode), (GLenum mode)) \
    GB_DECL_FWD_NR  (glMatrixPushEXT,                                  void,           (mode), (GLenum mode)) \
    GB_DECL_FWD_NR  (glMatrixRotatefEXT,                               void,           (mode, angle, x, y, z), (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD_NR  (glMatrixRotatedEXT,                               void,           (mode, angle, x, y, z), (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD_NR  (glMatrixScalefEXT,                                void,           (mode, x, y, z), (GLenum mode, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD_NR  (glMatrixScaledEXT,                                void,           (mode, x, y, z), (GLenum mode, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD_NR  (glMatrixTranslatefEXT,                            void,           (mode, x, y, z), (GLenum mode, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD_NR  (glMatrixTranslatedEXT,                            void,           (mode, x, y, z), (GLenum mode, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD_NR  (glPolygonModeNV,                                  void,           (face, mode), (GLenum face, GLenum mode)) \
    GB_DECL_FWD_NR  (glReadBufferNV,                                   void,           (mode), (GLenum mode)) \
    GB_DECL_FWD_NR  (glFramebufferSampleLocationsfvNV,                 void,           (target, start, count, v), (GLenum target, GLuint start, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glNamedFramebufferSampleLocationsfvNV,            void,           (framebuffer, start, count, v), (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glResolveDepthValuesNV,                           void,           (), (void)) \
    GB_DECL_FWD_NR  (glScissorExclusiveNV,                             void,           (x, y, width, height), (GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glScissorExclusiveArrayvNV,                       void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD_NR  (glBindShadingRateImageNV,                         void,           (texture), (GLuint texture)) \
    GB_DECL_FWD_NR  (glGetShadingRateImagePaletteNV,                   void,           (viewport, entry, rate), (GLuint viewport, GLuint entry, GLenum *rate)) \
    GB_DECL_FWD_NR  (glGetShadingRateSampleLocationivNV,               void,           (rate, samples, index, location), (GLenum rate, GLuint samples, GLuint index, GLint *location)) \
    GB_DECL_FWD_NR  (glShadingRateImageBarrierNV,                      void,           (synchronize), (GLboolean synchronize)) \
    GB_DECL_FWD_NR  (glShadingRateImagePaletteNV,                      void,           (viewport, first, count, rates), (GLuint viewport, GLuint first, GLsizei count, const GLenum *rates)) \
    GB_DECL_FWD_NR  (glShadingRateSampleOrderNV,                       void,           (order), (GLenum order)) \
    GB_DECL_FWD_NR  (glShadingRateSampleOrderCustomNV,                 void,           (rate, samples, locations), (GLenum rate, GLuint samples, const GLint *locations)) \
    GB_DECL_FWD_NR  (glViewportArrayvNV,                               void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glViewportIndexedfNV,                             void,           (index, x, y, w, h), (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)) \
    GB_DECL_FWD_NR  (glViewportIndexedfvNV,                            void,           (index, v), (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glScissorArrayvNV,                                void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD_NR  (glScissorIndexedNV,                               void,           (index, left, bottom, width, height), (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)) \
    GB_DECL_FWD_NR  (glScissorIndexedvNV,                              void,           (index, v), (GLuint index, const GLint *v)) \
    GB_DECL_FWD_NR  (glDepthRangeArrayfvNV,                            void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD_NR  (glDepthRangeIndexedfNV,                           void,           (index, n, f), (GLuint index, GLfloat n, GLfloat f)) \
    GB_DECL_FWD_NR  (glGetFloati_vNV,                                  void,           (target, index, data), (GLenum target, GLuint index, GLfloat *data)) \
    GB_DECL_FWD_NR  (glEnableiNV,                                      void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glDisableiNV,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glIsEnablediNV,                                   GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD_NR  (glViewportSwizzleNV,                              void,           (index, swizzlex, swizzley, swizzlez, swizzlew), (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew)) \
    GB_DECL_FWD_NR  (glFramebufferTextureMultiviewOVR,                 void,           (target, attachment, texture, level, baseViewIndex, numViews), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)) \
    GB_DECL_FWD_NR  (glFramebufferTextureMultisampleMultiviewOVR,      void,           (target, attachment, texture, level, samples, baseViewIndex, numViews), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei samples, GLint baseViewIndex, GLsizei numViews)) \
    GB_DECL_FWD_NR  (glAlphaFuncQCOM,                                  void,           (func, ref), (GLenum func, GLclampf ref)) \
    GB_DECL_FWD_NR  (glGetDriverControlsQCOM,                          void,           (num, size, driverControls), (GLint *num, GLsizei size, GLuint *driverControls)) \
    GB_DECL_FWD_NR  (glGetDriverControlStringQCOM,                     void,           (driverControl, bufSize, length, driverControlString), (GLuint driverControl, GLsizei bufSize, GLsizei *length, GLchar *driverControlString)) \
    GB_DECL_FWD_NR  (glEnableDriverControlQCOM,                        void,           (driverControl), (GLuint driverControl)) \
    GB_DECL_FWD_NR  (glDisableDriverControlQCOM,                       void,           (driverControl), (GLuint driverControl)) \
    GB_DECL_FWD_NR  (glExtGetTexturesQCOM,                             void,           (textures, maxTextures, numTextures), (GLuint *textures, GLint maxTextures, GLint *numTextures)) \
    GB_DECL_FWD_NR  (glExtGetBuffersQCOM,                              void,           (buffers, maxBuffers, numBuffers), (GLuint *buffers, GLint maxBuffers, GLint *numBuffers)) \
    GB_DECL_FWD_NR  (glExtGetRenderbuffersQCOM,                        void,           (renderbuffers, maxRenderbuffers, numRenderbuffers), (GLuint *renderbuffers, GLint maxRenderbuffers, GLint *numRenderbuffers)) \
    GB_DECL_FWD_NR  (glExtGetFramebuffersQCOM,                         void,           (framebuffers, maxFramebuffers, numFramebuffers), (GLuint *framebuffers, GLint maxFramebuffers, GLint *numFramebuffers)) \
    GB_DECL_FWD_NR  (glExtGetTexLevelParameterivQCOM,                  void,           (texture, face, level, pname, params), (GLuint texture, GLenum face, GLint level, GLenum pname, GLint *params)) \
    GB_DECL_FWD_NR  (glExtTexObjectStateOverrideiQCOM,                 void,           (target, pname, param), (GLenum target, GLenum pname, GLint param)) \
    GB_DECL_FWD_NR  (glExtGetTexSubImageQCOM,                          void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, texels), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, void *texels)) \
    GB_DECL_FWD_NR  (glExtGetBufferPointervQCOM,                       void,           (target, params), (GLenum target, void **params)) \
    GB_DECL_FWD_NR  (glExtGetShadersQCOM,                              void,           (shaders, maxShaders, numShaders), (GLuint *shaders, GLint maxShaders, GLint *numShaders)) \
    GB_DECL_FWD_NR  (glExtGetProgramsQCOM,                             void,           (programs, maxPrograms, numPrograms), (GLuint *programs, GLint maxPrograms, GLint *numPrograms)) \
    GB_DECL_FWD     (glExtIsProgramBinaryQCOM,                         GLboolean,      (program), (GLuint program)) \
    GB_DECL_FWD_NR  (glExtGetProgramBinarySourceQCOM,                  void,           (program, shadertype, source, length), (GLuint program, GLenum shadertype, GLchar *source, GLint *length)) \
    GB_DECL_FWD_NR  (glFramebufferFoveationConfigQCOM,                 void,           (framebuffer, numLayers, focalPointsPerLayer, requestedFeatures, providedFeatures), (GLuint framebuffer, GLuint numLayers, GLuint focalPointsPerLayer, GLuint requestedFeatures, GLuint *providedFeatures)) \
    GB_DECL_FWD_NR  (glFramebufferFoveationParametersQCOM,             void,           (framebuffer, layer, focalPoint, focalX, focalY, gainX, gainY, foveaArea), (GLuint framebuffer, GLuint layer, GLuint focalPoint, GLfloat focalX, GLfloat focalY, GLfloat gainX, GLfloat gainY, GLfloat foveaArea)) \
    GB_DECL_FWD_NR  (glFramebufferFetchBarrierQCOM,                    void,           (), (void)) \
    GB_DECL_FWD_NR  (glTextureFoveationParametersQCOM,                 void,           (texture, layer, focalPoint, focalX, focalY, gainX, gainY, foveaArea), (GLuint texture, GLuint layer, GLuint focalPoint, GLfloat focalX, GLfloat focalY, GLfloat gainX, GLfloat gainY, GLfloat foveaArea)) \
    GB_DECL_FWD_NR  (glStartTilingQCOM,                                void,           (x, y, width, height, preserveMask), (GLuint x, GLuint y, GLuint width, GLuint height, GLbitfield preserveMask)) \
    GB_DECL_FWD_NR  (glEndTilingQCOM,                                  void,           (preserveMask), (GLbitfield preserveMask)) \
    /* VitaGL extensions */ \
    GB_DECL_FWD_NR  (vglColorPointer,                                  void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglColorPointerMapped,                            void,           (type, pointer),                                                                            (GLenum type, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglDrawObjects,                                   void,           (mode, count, implicit_wvp),                                                                (GLenum mode, GLsizei count, GLboolean implicit_wvp)) \
    GB_DECL_FWD_NR  (vglIndexPointer,                                  void,           (type, stride, count, pointer),                                                             (GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglIndexPointerMapped,                            void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglTexCoordPointer,                               void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglTexCoordPointerMapped,                         void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglVertexPointer,                                 void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglVertexPointerMapped,                           void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglBindAttribLocation,                            void,           (prog, index, name, num, type),                                                             (GLuint prog, GLuint index, const GLchar *name, const GLuint num, const GLenum type)) \
    GB_DECL_FWD     (vglBindPackedAttribLocation,                      GLint,          (prog, name, num, type, offset, stride),                                                    (GLuint prog, const GLchar *name, const GLuint num, const GLenum type, GLuint offset, GLint stride)) \
    GB_DECL_FWD_NR  (vglVertexAttribPointer,                           void,           (index, size, type, normalized, stride, count, pointer),                                    (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD_NR  (vglVertexAttribPointerMapped,                     void,           (index, pointer),                                                                           (GLuint index, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglAlloc,                                         void*,          (size, type),                                                                               (uint32_t size, vglMemType type)) \
    GB_DECL_FWD_NR  (vglEnableRuntimeShaderCompiler,                   void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD_NR  (vglEnd,                                           void,           (),                                                                                         (void)) \
    GB_DECL_FWD     (vglForceAlloc,                                    void*,          (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglFree,                                          void,           (addr),                                                                                     (void *addr)) \
    GB_DECL_FWD     (vglGetGxmTexture,                                 SceGxmTexture*, (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD     (vglGetProcAddress,                                void*,          (name),                                                                                     (const char *name)) \
    GB_DECL_FWD     (vglGetTexDataPointer,                             void*,          (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD     (vglHasRuntimeShaderCompiler,                      GLboolean,      (),                                                                                         (void)) \
    GB_DECL_FWD_NR  (vglInit,                                          void,           (legacy_pool_size),                                                                         (int legacy_pool_size)) \
    GB_DECL_FWD_NR  (vglInitExtended,                                  void,           (legacy_pool_size, width, height, ram_threshold, msaa),                                     (int legacy_pool_size, int width, int height, int ram_threshold, SceGxmMultisampleMode msaa)) \
    GB_DECL_FWD_NR  (vglInitWithCustomSizes,                           void,           (legacy_pool_size, width, height, ram_pool_size, cdram_pool_size, phycont_pool_size, msaa), (int legacy_pool_size, int width, int height, int ram_pool_size, int cdram_pool_size, int phycont_pool_size, SceGxmMultisampleMode msaa)) \
    GB_DECL_FWD     (vglMemFree,                                       size_t,         (type),                                                                                     (vglMemType type)) \
    GB_DECL_FWD_NR  (vglSetFragmentBufferSize,                         void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetParamBufferSize,                            void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetUSSEBufferSize,                             void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetVDMBufferSize,                              void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetVertexBufferSize,                           void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetVertexPoolSize,                             void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD_NR  (vglSetupRuntimeShaderCompiler,                    void,           (opt_level, use_fastmath, use_fastprecision, use_fastint),                                  (shark_opt opt_level, int32_t use_fastmath, int32_t use_fastprecision, int32_t use_fastint)) \
    GB_DECL_FWD_NR  (vglSwapBuffers,                                   void,           (has_commondialog),                                                                         (GLboolean has_commondialog)) \
    GB_DECL_FWD_NR  (vglTexImageDepthBuffer,                           void,           (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD_NR  (vglUseTripleBuffering,                            void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD_NR  (vglUseVram,                                       void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD_NR  (vglUseVramForUSSE,                                void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD_NR  (vglUseExtraMem,                                   void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD_NR  (vglWaitVblankStart,                               void,           (enable),                                                                                   (GLboolean enable))


#define GB_DECL_FWD(func, ret, args, vars) extern ret (*func) vars;
#define GB_DECL_FWD_HOOK GB_DECL_FWD
#define GB_DECL_FWD_NR GB_DECL_FWD
GLES2_FUNCS
GLES2_EXT_FUNCS
#undef GB_DECL_FWD_NR
#undef GB_DECL_FWD_HOOK
#undef GB_DECL_FWD

#endif /* __GLES2_MACROS_H__ */