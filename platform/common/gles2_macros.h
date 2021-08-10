#ifndef __GLES2_MACROS_H__
#define __GLES2_MACROS_H__

#define GLES2_FUNCS \
    GB_DECL_FWD     (glActiveTexture,                                  void,           (texture),                                                                    (GLenum texture)) \
    GB_DECL_FWD     (glAttachShader,                                   void,           (program, shader),                                                            (GLuint program, GLuint shader)) \
    GB_DECL_FWD     (glBindAttribLocation,                             void,           (program, index, name),                                                       (GLuint program, GLuint index, const GLchar *name)) \
    GB_DECL_FWD     (glBindBuffer,                                     void,           (target, buffer),                                                             (GLenum target, GLuint buffer)) \
    GB_DECL_FWD     (glBindFramebuffer,                                void,           (target, framebuffer),                                                        (GLenum target, GLuint framebuffer)) \
    GB_DECL_FWD     (glBindRenderbuffer,                               void,           (target, renderbuffer),                                                       (GLenum target, GLuint renderbuffer)) \
    GB_DECL_FWD     (glBindTexture,                                    void,           (target, texture),                                                            (GLenum target, GLuint texture)) \
    GB_DECL_FWD     (glBlendColor,                                     void,           (red, green, blue, alpha),                                                    (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    GB_DECL_FWD     (glBlendEquation,                                  void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD     (glBlendEquationSeparate,                          void,           (modeRGB, modeAlpha),                                                         (GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD     (glBlendFunc,                                      void,           (sfactor, dfactor),                                                           (GLenum sfactor, GLenum dfactor)) \
    GB_DECL_FWD     (glBlendFuncSeparate,                              void,           (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha),                         (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)) \
    GB_DECL_FWD     (glBufferData,                                     void,           (target, size, data, usage),                                                  (GLenum target, GLsizeiptr size, const void *data, GLenum usage)) \
    GB_DECL_FWD     (glBufferSubData,                                  void,           (target, offset, size, data),                                                 (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)) \
    GB_DECL_FWD     (glCheckFramebufferStatus,                         GLenum,         (target),                                                                     (GLenum target)) \
    GB_DECL_FWD     (glClear,                                          void,           (mask),                                                                       (GLbitfield mask)) \
    GB_DECL_FWD     (glClearColor,                                     void,           (red, green, blue, alpha),                                                    (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    GB_DECL_FWD     (glClearDepthf,                                    void,           (d),                                                                          (GLfloat d)) \
    GB_DECL_FWD     (glClearStencil,                                   void,           (s),                                                                          (GLint s)) \
    GB_DECL_FWD     (glColorMask,                                      void,           (red, green, blue, alpha),                                                    (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)) \
    GB_DECL_FWD     (glCompileShader,                                  void,           (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD     (glCompressedTexImage2D,                           void,           (target, level, internalformat, width, height, border, imageSize, data),      (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD     (glCompressedTexSubImage2D,                        void,           (target, level, xoffset, yoffset, width, height, format, imageSize, data),    (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD     (glCopyTexImage2D,                                 void,           (target, level, internalformat, x, y, width, height, border),                 (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)) \
    GB_DECL_FWD     (glCopyTexSubImage2D,                              void,           (target, level, xoffset, yoffset, x, y, width, height),                       (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glCreateProgram,                                  GLuint,         (),                                                                           ()) \
    GB_DECL_FWD     (glCreateShader,                                   GLuint,         (type),                                                                       (GLenum type)) \
    GB_DECL_FWD     (glCullFace,                                       void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD     (glDeleteBuffers,                                  void,           (n, buffers),                                                                 (GLsizei n, const GLuint *buffers)) \
    GB_DECL_FWD     (glDeleteFramebuffers,                             void,           (n, framebuffers),                                                            (GLsizei n, const GLuint *framebuffers)) \
    GB_DECL_FWD     (glDeleteProgram,                                  void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glDeleteRenderbuffers,                            void,           (n, renderbuffers),                                                           (GLsizei n, const GLuint *renderbuffers)) \
    GB_DECL_FWD     (glDeleteShader,                                   void,           (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD     (glDeleteTextures,                                 void,           (n, textures),                                                                (GLsizei n, const GLuint *textures)) \
    GB_DECL_FWD     (glDepthFunc,                                      void,           (func),                                                                       (GLenum func)) \
    GB_DECL_FWD     (glDepthMask,                                      void,           (flag),                                                                       (GLboolean flag)) \
    GB_DECL_FWD     (glDepthRangef,                                    void,           (n, f),                                                                       (GLfloat n, GLfloat f)) \
    GB_DECL_FWD     (glDetachShader,                                   void,           (program, shader),                                                            (GLuint program, GLuint shader)) \
    GB_DECL_FWD     (glDisable,                                        void,           (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD     (glDisableVertexAttribArray,                       void,           (index),                                                                      (GLuint index)) \
    GB_DECL_FWD     (glDrawArrays,                                     void,           (mode, first, count),                                                         (GLenum mode, GLint first, GLsizei count)) \
    GB_DECL_FWD     (glDrawElements,                                   void,           (mode, count, type, indices),                                                 (GLenum mode, GLsizei count, GLenum type, const void *indices)) \
    GB_DECL_FWD     (glEnable,                                         void,           (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD     (glEnableVertexAttribArray,                        void,           (index),                                                                      (GLuint index)) \
    GB_DECL_FWD     (glFinish,                                         void,           (),                                                                           ()) \
    GB_DECL_FWD     (glFlush,                                          void,           (),                                                                           ()) \
    GB_DECL_FWD     (glFramebufferRenderbuffer,                        void,           (target, attachment, renderbuffertarget, renderbuffer),                       (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)) \
    GB_DECL_FWD     (glFramebufferTexture2D,                           void,           (target, attachment, textarget, texture, level),                              (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)) \
    GB_DECL_FWD     (glFrontFace,                                      void,           (mode),                                                                       (GLenum mode)) \
    GB_DECL_FWD     (glGenBuffers,                                     void,           (n, buffers),                                                                 (GLsizei n, GLuint *buffers)) \
    GB_DECL_FWD     (glGenerateMipmap,                                 void,           (target),                                                                     (GLenum target)) \
    GB_DECL_FWD     (glGenFramebuffers,                                void,           (n, framebuffers),                                                            (GLsizei n, GLuint *framebuffers)) \
    GB_DECL_FWD     (glGenRenderbuffers,                               void,           (n, renderbuffers),                                                           (GLsizei n, GLuint *renderbuffers)) \
    GB_DECL_FWD     (glGenTextures,                                    void,           (n, textures),                                                                (GLsizei n, GLuint *textures)) \
    GB_DECL_FWD     (glGetActiveAttrib,                                void,           (program, index, bufSize, length, size, type, name),                          (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    GB_DECL_FWD     (glGetActiveUniform,                               void,           (program, index, bufSize, length, size, type, name),                          (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    GB_DECL_FWD     (glGetAttachedShaders,                             void,           (program, maxCount, count, shaders),                                          (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)) \
    GB_DECL_FWD     (glGetAttribLocation,                              GLint,          (program, name),                                                              (GLuint program, const GLchar *name)) \
    GB_DECL_FWD     (glGetBooleanv,                                    void,           (pname, data),                                                                (GLenum pname, GLboolean *data)) \
    GB_DECL_FWD     (glGetBufferParameteriv,                           void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetError,                                       GLenum,         (),                                                                           ()) \
    GB_DECL_FWD     (glGetFloatv,                                      void,           (pname, data),                                                                (GLenum pname, GLfloat *data)) \
    GB_DECL_FWD     (glGetFramebufferAttachmentParameteriv,            void,           (target, attachment, pname, params),                                          (GLenum target, GLenum attachment, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetIntegerv,                                    void,           (pname, data),                                                                (GLenum pname, GLint *data)) \
    GB_DECL_FWD     (glGetProgramiv,                                   void,           (program, pname, params),                                                     (GLuint program, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetProgramInfoLog,                              void,           (program, bufSize, length, infoLog),                                          (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD     (glGetRenderbufferParameteriv,                     void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetShaderiv,                                    void,           (shader, pname, params),                                                      (GLuint shader, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetShaderInfoLog,                               void,           (shader, bufSize, length, infoLog),                                           (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD     (glGetShaderPrecisionFormat,                       void,           (shadertype, precisiontype, range, precision),                                (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)) \
    GB_DECL_FWD     (glGetShaderSource,                                void,           (shader, bufSize, length, source),                                            (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)) \
    GB_DECL_FWD     (glGetString,                                      const GLubyte*, (name),                                                                       (GLenum name)) \
    GB_DECL_FWD     (glGetTexParameterfv,                              void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLfloat *params)) \
    GB_DECL_FWD     (glGetTexParameteriv,                              void,           (target, pname, params),                                                      (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetUniformfv,                                   void,           (program, location, params),                                                  (GLuint program, GLint location, GLfloat *params)) \
    GB_DECL_FWD     (glGetUniformiv,                                   void,           (program, location, params),                                                  (GLuint program, GLint location, GLint *params)) \
    GB_DECL_FWD     (glGetUniformLocation,                             GLint,          (program, name),                                                              (GLuint program, const GLchar *name)) \
    GB_DECL_FWD     (glGetVertexAttribfv,                              void,           (index, pname, params),                                                       (GLuint index, GLenum pname, GLfloat *params)) \
    GB_DECL_FWD     (glGetVertexAttribiv,                              void,           (index, pname, params),                                                       (GLuint index, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetVertexAttribPointerv,                        void,           (index, pname, pointer),                                                      (GLuint index, GLenum pname, void **pointer)) \
    GB_DECL_FWD     (glHint,                                           void,           (target, mode),                                                               (GLenum target, GLenum mode)) \
    GB_DECL_FWD     (glIsBuffer,                                       GLboolean,      (buffer),                                                                     (GLuint buffer)) \
    GB_DECL_FWD     (glIsEnabled,                                      GLboolean,      (cap),                                                                        (GLenum cap)) \
    GB_DECL_FWD     (glIsFramebuffer,                                  GLboolean,      (framebuffer),                                                                (GLuint framebuffer)) \
    GB_DECL_FWD     (glIsProgram,                                      GLboolean,      (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glIsRenderbuffer,                                 GLboolean,      (renderbuffer),                                                               (GLuint renderbuffer)) \
    GB_DECL_FWD     (glIsShader,                                       GLboolean,      (shader),                                                                     (GLuint shader)) \
    GB_DECL_FWD     (glIsTexture,                                      GLboolean,      (texture),                                                                    (GLuint texture)) \
    GB_DECL_FWD     (glLineWidth,                                      void,           (width),                                                                      (GLfloat width)) \
    GB_DECL_FWD     (glLinkProgram,                                    void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glPixelStorei,                                    void,           (pname, param),                                                               (GLenum pname, GLint param)) \
    GB_DECL_FWD     (glPolygonOffset,                                  void,           (factor, units),                                                              (GLfloat factor, GLfloat units)) \
    GB_DECL_FWD     (glReadPixels,                                     void,           (x, y, width, height, format, type, pixels),                                  (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)) \
    GB_DECL_FWD     (glReleaseShaderCompiler,                          void,           (),                                                                           ()) \
    GB_DECL_FWD     (glRenderbufferStorage,                            void,           (target, internalformat, width, height),                                      (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glSampleCoverage,                                 void,           (value, invert),                                                              (GLfloat value, GLboolean invert)) \
    GB_DECL_FWD     (glScissor,                                        void,           (x, y, width, height),                                                        (GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glShaderBinary,                                   void,           (count, shaders, binaryformat, binary, length),                               (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)) \
    GB_DECL_FWD     (glShaderSource,                                   void,           (shader, count, string, length),                                              (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)) \
    GB_DECL_FWD     (glStencilFunc,                                    void,           (func, ref, mask),                                                            (GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD     (glStencilFuncSeparate,                            void,           (face, func, ref, mask),                                                      (GLenum face, GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD     (glStencilMask,                                    void,           (mask),                                                                       (GLuint mask)) \
    GB_DECL_FWD     (glStencilMaskSeparate,                            void,           (face, mask),                                                                 (GLenum face, GLuint mask)) \
    GB_DECL_FWD     (glStencilOp,                                      void,           (fail, zfail, zpass),                                                         (GLenum fail, GLenum zfail, GLenum zpass)) \
    GB_DECL_FWD     (glStencilOpSeparate,                              void,           (face, sfail, dpfail, dppass),                                                (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)) \
    GB_DECL_FWD     (glTexImage2D,                                     void,           (target, level, internalformat, width, height, border, format, type, pixels), (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD     (glTexParameterf,                                  void,           (target, pname, param),                                                       (GLenum target, GLenum pname, GLfloat param)) \
    GB_DECL_FWD     (glTexParameterfv,                                 void,           (target, pname, params),                                                      (GLenum target, GLenum pname, const GLfloat *params)) \
    GB_DECL_FWD     (glTexParameteri,                                  void,           (target, pname, param),                                                       (GLenum target, GLenum pname, GLint param)) \
    GB_DECL_FWD     (glTexParameteriv,                                 void,           (target, pname, params),                                                      (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD     (glTexSubImage2D,                                  void,           (target, level, xoffset, yoffset, width, height, format, type, pixels),       (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD     (glUniform1f,                                      void,           (location, v0),                                                               (GLint location, GLfloat v0)) \
    GB_DECL_FWD     (glUniform1fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glUniform1i,                                      void,           (location, v0),                                                               (GLint location, GLint v0)) \
    GB_DECL_FWD     (glUniform1iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glUniform2f,                                      void,           (location, v0, v1),                                                           (GLint location, GLfloat v0, GLfloat v1)) \
    GB_DECL_FWD     (glUniform2fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glUniform2i,                                      void,           (location, v0, v1),                                                           (GLint location, GLint v0, GLint v1)) \
    GB_DECL_FWD     (glUniform2iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glUniform3f,                                      void,           (location, v0, v1, v2),                                                       (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    GB_DECL_FWD     (glUniform3fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glUniform3i,                                      void,           (location, v0, v1, v2),                                                       (GLint location, GLint v0, GLint v1, GLint v2)) \
    GB_DECL_FWD     (glUniform3iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glUniform4f,                                      void,           (location, v0, v1, v2, v3),                                                   (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    GB_DECL_FWD     (glUniform4fv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glUniform4i,                                      void,           (location, v0, v1, v2, v3),                                                   (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    GB_DECL_FWD     (glUniform4iv,                                     void,           (location, count, value),                                                     (GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glUniformMatrix2fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix3fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix4fv,                               void,           (location, count, transpose, value),                                          (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUseProgram,                                     void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glValidateProgram,                                void,           (program),                                                                    (GLuint program)) \
    GB_DECL_FWD     (glVertexAttrib1f,                                 void,           (index, x),                                                                   (GLuint index, GLfloat x)) \
    GB_DECL_FWD     (glVertexAttrib1fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glVertexAttrib2f,                                 void,           (index, x, y),                                                                (GLuint index, GLfloat x, GLfloat y)) \
    GB_DECL_FWD     (glVertexAttrib2fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glVertexAttrib3f,                                 void,           (index, x, y, z),                                                             (GLuint index, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD     (glVertexAttrib3fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glVertexAttrib4f,                                 void,           (index, x, y, z, w),                                                          (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)) \
    GB_DECL_FWD     (glVertexAttrib4fv,                                void,           (index, v),                                                                   (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glVertexAttribPointer,                            void,           (index, size, type, normalized, stride, pointer),                             (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)) \
    GB_DECL_FWD     (glViewport,                                       void,           (x, y, width, height),                                                        (GLint x, GLint y, GLsizei width, GLsizei height))

#define GLES2_EXT_FUNCS \
    GB_DECL_FWD     (glBlendBarrierKHR,                                void,           (), (void)) \
    GB_DECL_FWD     (glDebugMessageControlKHR,                         void,           (source, type, severity, count, ids, enabled), (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)) \
    GB_DECL_FWD     (glDebugMessageInsertKHR,                          void,           (source, type, id, severity, length, buf), (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)) \
    GB_DECL_FWD     (glDebugMessageCallbackKHR,                        void,           (callback, userParam), (GLDEBUGPROCKHR callback, const void *userParam)) \
    GB_DECL_FWD     (glGetDebugMessageLogKHR,                          GLuint,         (count, bufSize, sources, types, ids, severities, lengths, messageLog), (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)) \
    GB_DECL_FWD     (glPushDebugGroupKHR,                              void,           (source, id, length, message), (GLenum source, GLuint id, GLsizei length, const GLchar *message)) \
    GB_DECL_FWD     (glPopDebugGroupKHR,                               void,           (), (void)) \
    GB_DECL_FWD     (glObjectLabelKHR,                                 void,           (identifier, name, length, label), (GLenum identifier, GLuint name, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD     (glGetObjectLabelKHR,                              void,           (identifier, name, bufSize, length, label), (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD     (glObjectPtrLabelKHR,                              void,           (ptr, length, label), (const void *ptr, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD     (glGetObjectPtrLabelKHR,                           void,           (ptr, bufSize, length, label), (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD     (glGetPointervKHR,                                 void,           (pname, params), (GLenum pname, void **params)) \
    GB_DECL_FWD     (glMaxShaderCompilerThreadsKHR,                    void,           (count), (GLuint count)) \
    GB_DECL_FWD     (glGetGraphicsResetStatusKHR,                      GLenum,         (), (void)) \
    GB_DECL_FWD     (glReadnPixelsKHR,                                 void,           (x, y, width, height, format, type, bufSize, data), (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)) \
    GB_DECL_FWD     (glGetnUniformfvKHR,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)) \
    GB_DECL_FWD     (glGetnUniformivKHR,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD     (glGetnUniformuivKHR,                              void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLuint *params)) \
    GB_DECL_FWD     (glEGLImageTargetTexture2DOES,                     void,           (target, image), (GLenum target, GLeglImageOES image)) \
    GB_DECL_FWD     (glEGLImageTargetRenderbufferStorageOES,           void,           (target, image), (GLenum target, GLeglImageOES image)) \
    GB_DECL_FWD     (glCopyImageSubDataOES,                            void,           (srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth), (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)) \
    GB_DECL_FWD     (glEnableiOES,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glDisableiOES,                                    void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glBlendEquationiOES,                              void,           (buf, mode), (GLuint buf, GLenum mode)) \
    GB_DECL_FWD     (glBlendEquationSeparateiOES,                      void,           (buf, modeRGB, modeAlpha), (GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD     (glBlendFunciOES,                                  void,           (buf, src, dst), (GLuint buf, GLenum src, GLenum dst)) \
    GB_DECL_FWD     (glBlendFuncSeparateiOES,                          void,           (buf, srcRGB, dstRGB, srcAlpha, dstAlpha), (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    GB_DECL_FWD     (glColorMaskiOES,                                  void,           (index, r, g, b, a), (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)) \
    GB_DECL_FWD     (glIsEnablediOES,                                  GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glDrawElementsBaseVertexOES,                      void,           (mode, count, type, indices, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD     (glDrawRangeElementsBaseVertexOES,                 void,           (mode, start, end, count, type, indices, basevertex), (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD     (glDrawElementsInstancedBaseVertexOES,             void,           (mode, count, type, indices, instancecount, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)) \
    GB_DECL_FWD     (glMultiDrawElementsBaseVertexEXT,                 void,           (mode, count, type, indices, primcount, basevertex), (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, const GLint *basevertex)) \
    GB_DECL_FWD     (glFramebufferTextureOES,                          void,           (target, attachment, texture, level), (GLenum target, GLenum attachment, GLuint texture, GLint level)) \
    GB_DECL_FWD     (glGetProgramBinaryOES,                            void,           (program, bufSize, length, binaryFormat, binary), (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)) \
    GB_DECL_FWD     (glProgramBinaryOES,                               void,           (program, binaryFormat, binary, length), (GLuint program, GLenum binaryFormat, const void *binary, GLint length)) \
    GB_DECL_FWD     (glMapBufferOES,                                   void*,          (target, access), (GLenum target, GLenum access)) \
    GB_DECL_FWD     (glUnmapBufferOES,                                 GLboolean,      (target), (GLenum target)) \
    GB_DECL_FWD     (glGetBufferPointervOES,                           void,           (target, pname, params), (GLenum target, GLenum pname, void **params)) \
    GB_DECL_FWD     (glPrimitiveBoundingBoxOES,                        void,           (minX, minY, minZ, minW, maxX, maxY, maxZ, maxW), (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)) \
    GB_DECL_FWD     (glMinSampleShadingOES,                            void,           (value), (GLfloat value)) \
    GB_DECL_FWD     (glPatchParameteriOES,                             void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD     (glTexImage3DOES,                                  void,           (target, level, internalformat, width, height, depth, border, format, type, pixels), (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD     (glTexSubImage3DOES,                               void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)) \
    GB_DECL_FWD     (glCopyTexSubImage3DOES,                           void,           (target, level, xoffset, yoffset, zoffset, x, y, width, height), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glCompressedTexImage3DOES,                        void,           (target, level, internalformat, width, height, depth, border, imageSize, data), (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD     (glCompressedTexSubImage3DOES,                     void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)) \
    GB_DECL_FWD     (glFramebufferTexture3DOES,                        void,           (target, attachment, textarget, texture, level, zoffset), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)) \
    GB_DECL_FWD     (glTexParameterIivOES,                             void,           (target, pname, params), (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD     (glTexParameterIuivOES,                            void,           (target, pname, params), (GLenum target, GLenum pname, const GLuint *params)) \
    GB_DECL_FWD     (glGetTexParameterIivOES,                          void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetTexParameterIuivOES,                         void,           (target, pname, params), (GLenum target, GLenum pname, GLuint *params)) \
    GB_DECL_FWD     (glSamplerParameterIivOES,                         void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLint *param)) \
    GB_DECL_FWD     (glSamplerParameterIuivOES,                        void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLuint *param)) \
    GB_DECL_FWD     (glGetSamplerParameterIivOES,                      void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetSamplerParameterIuivOES,                     void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLuint *params)) \
    GB_DECL_FWD     (glTexBufferOES,                                   void,           (target, internalformat, buffer), (GLenum target, GLenum internalformat, GLuint buffer)) \
    GB_DECL_FWD     (glTexBufferRangeOES,                              void,           (target, internalformat, buffer, offset, size), (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    GB_DECL_FWD     (glTexStorage3DMultisampleOES,                     void,           (target, samples, internalformat, width, height, depth, fixedsamplelocations), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)) \
    GB_DECL_FWD     (glTextureViewOES,                                 void,           (texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers), (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)) \
    GB_DECL_FWD     (glBindVertexArrayOES,                             void,           (array), (GLuint array)) \
    GB_DECL_FWD     (glDeleteVertexArraysOES,                          void,           (n, arrays), (GLsizei n, const GLuint *arrays)) \
    GB_DECL_FWD     (glGenVertexArraysOES,                             void,           (n, arrays), (GLsizei n, GLuint *arrays)) \
    GB_DECL_FWD     (glIsVertexArrayOES,                               GLboolean,      (array), (GLuint array)) \
    GB_DECL_FWD     (glViewportArrayvOES,                              void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glViewportIndexedfOES,                            void,           (index, x, y, w, h), (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)) \
    GB_DECL_FWD     (glViewportIndexedfvOES,                           void,           (index, v), (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glScissorArrayvOES,                               void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD     (glScissorIndexedOES,                              void,           (index, left, bottom, width, height), (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glScissorIndexedvOES,                             void,           (index, v), (GLuint index, const GLint *v)) \
    GB_DECL_FWD     (glDepthRangeArrayfvOES,                           void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glDepthRangeIndexedfOES,                          void,           (index, n, f), (GLuint index, GLfloat n, GLfloat f)) \
    GB_DECL_FWD     (glGetFloati_vOES,                                 void,           (target, index, data), (GLenum target, GLuint index, GLfloat *data)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleAdvancedAMD,      void,           (target, samples, storageSamples, internalformat, width, height), (GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glNamedRenderbufferStorageMultisampleAdvancedAMD, void,           (renderbuffer, samples, storageSamples, internalformat, width, height), (GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glGetPerfMonitorGroupsAMD,                        void,           (numGroups, groupsSize, groups), (GLint *numGroups, GLsizei groupsSize, GLuint *groups)) \
    GB_DECL_FWD     (glGetPerfMonitorCountersAMD,                      void,           (group, numCounters, maxActiveCounters, counterSize, counters), (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters)) \
    GB_DECL_FWD     (glGetPerfMonitorGroupStringAMD,                   void,           (group, bufSize, length, groupString), (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString)) \
    GB_DECL_FWD     (glGetPerfMonitorCounterStringAMD,                 void,           (group, counter, bufSize, length, counterString), (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString)) \
    GB_DECL_FWD     (glGetPerfMonitorCounterInfoAMD,                   void,           (group, counter, pname, data), (GLuint group, GLuint counter, GLenum pname, void *data)) \
    GB_DECL_FWD     (glGenPerfMonitorsAMD,                             void,           (n, monitors), (GLsizei n, GLuint *monitors)) \
    GB_DECL_FWD     (glDeletePerfMonitorsAMD,                          void,           (n, monitors), (GLsizei n, GLuint *monitors)) \
    GB_DECL_FWD     (glSelectPerfMonitorCountersAMD,                   void,           (monitor, enable, group, numCounters, counterList), (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList)) \
    GB_DECL_FWD     (glBeginPerfMonitorAMD,                            void,           (monitor), (GLuint monitor)) \
    GB_DECL_FWD     (glEndPerfMonitorAMD,                              void,           (monitor), (GLuint monitor)) \
    GB_DECL_FWD     (glGetPerfMonitorCounterDataAMD,                   void,           (monitor, pname, dataSize, data, bytesWritten), (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten)) \
    GB_DECL_FWD     (glBlitFramebufferANGLE,                           void,           (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter), (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleANGLE,            void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glDrawArraysInstancedANGLE,                       void,           (mode, first, count, primcount), (GLenum mode, GLint first, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD     (glDrawElementsInstancedANGLE,                     void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD     (glVertexAttribDivisorANGLE,                       void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD     (glGetTranslatedShaderSourceANGLE,                 void,           (shader, bufsize, length, source), (GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source)) \
    GB_DECL_FWD     (glCopyTextureLevelsAPPLE,                         void,           (destinationTexture, sourceTexture, sourceBaseLevel, sourceLevelCount), (GLuint destinationTexture, GLuint sourceTexture, GLint sourceBaseLevel, GLsizei sourceLevelCount)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleAPPLE,            void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glResolveMultisampleFramebufferAPPLE,             void,           (), (void)) \
    GB_DECL_FWD     (glFenceSyncAPPLE,                                 GLsync,         (condition, flags), (GLenum condition, GLbitfield flags)) \
    GB_DECL_FWD     (glIsSyncAPPLE,                                    GLboolean,      (sync), (GLsync sync)) \
    GB_DECL_FWD     (glDeleteSyncAPPLE,                                void,           (sync), (GLsync sync)) \
    GB_DECL_FWD     (glClientWaitSyncAPPLE,                            GLenum,         (sync, flags, timeout), (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    GB_DECL_FWD     (glWaitSyncAPPLE,                                  void,           (sync, flags, timeout), (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    GB_DECL_FWD     (glGetInteger64vAPPLE,                             void,           (pname, params), (GLenum pname, GLint64 *params)) \
    GB_DECL_FWD     (glGetSyncivAPPLE,                                 void,           (sync, pname, bufSize, length, values), (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)) \
    GB_DECL_FWD     (glEGLImageTargetTexStorageEXT,                    void,           (target, image, attrib_list), (GLenum target, GLeglImageOES image, const GLint* attrib_list)) \
    GB_DECL_FWD     (glEGLImageTargetTextureStorageEXT,                void,           (texture, image, attrib_list), (GLuint texture, GLeglImageOES image, const GLint* attrib_list)) \
    GB_DECL_FWD     (glDrawArraysInstancedBaseInstanceEXT,             void,           (mode, first, count, instancecount, baseinstance), (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)) \
    GB_DECL_FWD     (glDrawElementsInstancedBaseInstanceEXT,           void,           (mode, count, type, indices, instancecount, baseinstance), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance)) \
    GB_DECL_FWD     (glDrawElementsInstancedBaseVertexBaseInstanceEXT, void,           (mode, count, type, indices, instancecount, basevertex, baseinstance), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)) \
    GB_DECL_FWD     (glBindFragDataLocationIndexedEXT,                 void,           (program, colorNumber, index, name), (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)) \
    GB_DECL_FWD     (glBindFragDataLocationEXT,                        void,           (program, color, name), (GLuint program, GLuint color, const GLchar *name)) \
    GB_DECL_FWD     (glGetProgramResourceLocationIndexEXT,             GLint,          (program, programInterface, name), (GLuint program, GLenum programInterface, const GLchar *name)) \
    GB_DECL_FWD     (glGetFragDataIndexEXT,                            GLint,          (program, name), (GLuint program, const GLchar *name)) \
    GB_DECL_FWD     (glBufferStorageEXT,                               void,           (target, size, data, flags), (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags)) \
    GB_DECL_FWD     (glClearTexImageEXT,                               void,           (texture, level, format, type, data), (GLuint texture, GLint level, GLenum format, GLenum type, const void *data)) \
    GB_DECL_FWD     (glClearTexSubImageEXT,                            void,           (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data), (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)) \
    GB_DECL_FWD     (glClipControlEXT,                                 void,           (origin, depth), (GLenum origin, GLenum depth)) \
    GB_DECL_FWD     (glCopyImageSubDataEXT,                            void,           (srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth), (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)) \
    GB_DECL_FWD     (glLabelObjectEXT,                                 void,           (type, object, length, label), (GLenum type, GLuint object, GLsizei length, const GLchar *label)) \
    GB_DECL_FWD     (glGetObjectLabelEXT,                              void,           (type, object, bufSize, length, label), (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    GB_DECL_FWD     (glInsertEventMarkerEXT,                           void,           (length, marker), (GLsizei length, const GLchar *marker)) \
    GB_DECL_FWD     (glPushGroupMarkerEXT,                             void,           (length, marker), (GLsizei length, const GLchar *marker)) \
    GB_DECL_FWD     (glPopGroupMarkerEXT,                              void,           (), (void)) \
    GB_DECL_FWD_HOOK(glDiscardFramebufferEXT,                     void,           (target, numAttachments, attachments), (GLenum target, GLsizei numAttachments, const GLenum *attachments)) \
    GB_DECL_FWD     (glGenQueriesEXT,                                  void,           (n, ids), (GLsizei n, GLuint *ids)) \
    GB_DECL_FWD     (glDeleteQueriesEXT,                               void,           (n, ids), (GLsizei n, const GLuint *ids)) \
    GB_DECL_FWD     (glIsQueryEXT,                                     GLboolean,      (id), (GLuint id)) \
    GB_DECL_FWD     (glBeginQueryEXT,                                  void,           (target, id), (GLenum target, GLuint id)) \
    GB_DECL_FWD     (glEndQueryEXT,                                    void,           (target), (GLenum target)) \
    GB_DECL_FWD     (glQueryCounterEXT,                                void,           (id, target), (GLuint id, GLenum target)) \
    GB_DECL_FWD     (glGetQueryivEXT,                                  void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetQueryObjectivEXT,                            void,           (id, pname, params), (GLuint id, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetQueryObjectuivEXT,                           void,           (id, pname, params), (GLuint id, GLenum pname, GLuint *params)) \
    GB_DECL_FWD     (glGetQueryObjecti64vEXT,                          void,           (id, pname, params), (GLuint id, GLenum pname, GLint64 *params)) \
    GB_DECL_FWD     (glGetQueryObjectui64vEXT,                         void,           (id, pname, params), (GLuint id, GLenum pname, GLuint64 *params)) \
    GB_DECL_FWD     (glDrawBuffersEXT,                                 void,           (n, bufs), (GLsizei n, const GLenum *bufs)) \
    GB_DECL_FWD     (glEnableiEXT,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glDisableiEXT,                                    void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glBlendEquationiEXT,                              void,           (buf, mode), (GLuint buf, GLenum mode)) \
    GB_DECL_FWD     (glBlendEquationSeparateiEXT,                      void,           (buf, modeRGB, modeAlpha), (GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    GB_DECL_FWD     (glBlendFunciEXT,                                  void,           (buf, src, dst), (GLuint buf, GLenum src, GLenum dst)) \
    GB_DECL_FWD     (glBlendFuncSeparateiEXT,                          void,           (buf, srcRGB, dstRGB, srcAlpha, dstAlpha), (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    GB_DECL_FWD     (glColorMaskiEXT,                                  void,           (index, r, g, b, a), (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)) \
    GB_DECL_FWD     (glIsEnablediEXT,                                  GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glDrawElementsBaseVertexEXT,                      void,           (mode, count, type, indices, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD     (glDrawRangeElementsBaseVertexEXT,                 void,           (mode, start, end, count, type, indices, basevertex), (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    GB_DECL_FWD     (glDrawElementsInstancedBaseVertexEXT,             void,           (mode, count, type, indices, instancecount, basevertex), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)) \
    GB_DECL_FWD     (glDrawArraysInstancedEXT,                         void,           (mode, start, count, primcount), (GLenum mode, GLint start, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD     (glDrawElementsInstancedEXT,                       void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD     (glDrawTransformFeedbackEXT,                       void,           (mode, id), (GLenum mode, GLuint id)) \
    GB_DECL_FWD     (glDrawTransformFeedbackInstancedEXT,              void,           (mode, id, instancecount), (GLenum mode, GLuint id, GLsizei instancecount)) \
    GB_DECL_FWD     (glBufferStorageExternalEXT,                       void,           (target, offset, size, clientBuffer, flags), (GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags)) \
    GB_DECL_FWD     (glNamedBufferStorageExternalEXT,                  void,           (buffer, offset, size, clientBuffer, flags), (GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags)) \
    GB_DECL_FWD     (glFramebufferTextureEXT,                          void,           (target, attachment, texture, level), (GLenum target, GLenum attachment, GLuint texture, GLint level)) \
    GB_DECL_FWD     (glVertexAttribDivisorEXT,                         void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD     (glMapBufferRangeEXT,                              void*,          (target, offset, length, access), (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)) \
    GB_DECL_FWD     (glFlushMappedBufferRangeEXT,                      void,           (target, offset, length), (GLenum target, GLintptr offset, GLsizeiptr length)) \
    GB_DECL_FWD     (glGetUnsignedBytevEXT,                            void,           (pname, data), (GLenum pname, GLubyte *data)) \
    GB_DECL_FWD     (glGetUnsignedBytei_vEXT,                          void,           (target, index, data), (GLenum target, GLuint index, GLubyte *data)) \
    GB_DECL_FWD     (glDeleteMemoryObjectsEXT,                         void,           (n, memoryObjects), (GLsizei n, const GLuint *memoryObjects)) \
    GB_DECL_FWD     (glIsMemoryObjectEXT,                              GLboolean,      (memoryObject), (GLuint memoryObject)) \
    GB_DECL_FWD     (glCreateMemoryObjectsEXT,                         void,           (n, memoryObjects), (GLsizei n, GLuint *memoryObjects)) \
    GB_DECL_FWD     (glMemoryObjectParameterivEXT,                     void,           (memoryObject, pname, params), (GLuint memoryObject, GLenum pname, const GLint *params)) \
    GB_DECL_FWD     (glGetMemoryObjectParameterivEXT,                  void,           (memoryObject, pname, params), (GLuint memoryObject, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glTexStorageMem2DEXT,                             void,           (target, levels, internalFormat, width, height, memory, offset), (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTexStorageMem2DMultisampleEXT,                  void,           (target, samples, internalFormat, width, height, fixedSampleLocations, memory, offset), (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTexStorageMem3DEXT,                             void,           (target, levels, internalFormat, width, height, depth, memory, offset), (GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTexStorageMem3DMultisampleEXT,                  void,           (target, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset), (GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glBufferStorageMemEXT,                            void,           (target, size, memory, offset), (GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTextureStorageMem2DEXT,                         void,           (texture, levels, internalFormat, width, height, memory, offset), (GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTextureStorageMem2DMultisampleEXT,              void,           (texture, samples, internalFormat, width, height, fixedSampleLocations, memory, offset), (GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTextureStorageMem3DEXT,                         void,           (texture, levels, internalFormat, width, height, depth, memory, offset), (GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTextureStorageMem3DMultisampleEXT,              void,           (texture, samples, internalFormat, width, height, depth, fixedSampleLocations, memory, offset), (GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glNamedBufferStorageMemEXT,                       void,           (buffer, size, memory, offset), (GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glImportMemoryFdEXT,                              void,           (memory, size, handleType, fd), (GLuint memory, GLuint64 size, GLenum handleType, GLint fd)) \
    GB_DECL_FWD     (glImportMemoryWin32HandleEXT,                     void,           (memory, size, handleType, handle), (GLuint memory, GLuint64 size, GLenum handleType, void *handle)) \
    GB_DECL_FWD     (glImportMemoryWin32NameEXT,                       void,           (memory, size, handleType, name), (GLuint memory, GLuint64 size, GLenum handleType, const void *name)) \
    GB_DECL_FWD     (glMultiDrawArraysEXT,                             void,           (mode, first, count, primcount), (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)) \
    GB_DECL_FWD     (glMultiDrawElementsEXT,                           void,           (mode, count, type, indices, primcount), (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount)) \
    GB_DECL_FWD     (glMultiDrawArraysIndirectEXT,                     void,           (mode, indirect, drawcount, stride), (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD     (glMultiDrawElementsIndirectEXT,                   void,           (mode, type, indirect, drawcount, stride), (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleEXT,              void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glFramebufferTexture2DMultisampleEXT,             void,           (target, attachment, textarget, texture, level, samples), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)) \
    GB_DECL_FWD     (glReadBufferIndexedEXT,                           void,           (src, index), (GLenum src, GLint index)) \
    GB_DECL_FWD     (glDrawBuffersIndexedEXT,                          void,           (n, location, indices), (GLint n, const GLenum *location, const GLint *indices)) \
    GB_DECL_FWD     (glGetIntegeri_vEXT,                               void,           (target, index, data), (GLenum target, GLuint index, GLint *data)) \
    GB_DECL_FWD     (glPolygonOffsetClampEXT,                          void,           (factor, units, clamp), (GLfloat factor, GLfloat units, GLfloat clamp)) \
    GB_DECL_FWD     (glPrimitiveBoundingBoxEXT,                        void,           (minX, minY, minZ, minW, maxX, maxY, maxZ, maxW), (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)) \
    GB_DECL_FWD     (glRasterSamplesEXT,                               void,           (samples, fixedsamplelocations), (GLuint samples, GLboolean fixedsamplelocations)) \
    GB_DECL_FWD     (glGetGraphicsResetStatusEXT,                      GLenum,         (), (void)) \
    GB_DECL_FWD     (glReadnPixelsEXT,                                 void,           (x, y, width, height, format, type, bufSize, data), (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)) \
    GB_DECL_FWD     (glGetnUniformfvEXT,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)) \
    GB_DECL_FWD     (glGetnUniformivEXT,                               void,           (program, location, bufSize, params), (GLuint program, GLint location, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD     (glGenSemaphoresEXT,                               void,           (n, semaphores), (GLsizei n, GLuint *semaphores)) \
    GB_DECL_FWD     (glDeleteSemaphoresEXT,                            void,           (n, semaphores), (GLsizei n, const GLuint *semaphores)) \
    GB_DECL_FWD     (glIsSemaphoreEXT,                                 GLboolean,      (semaphore), (GLuint semaphore)) \
    GB_DECL_FWD     (glSemaphoreParameterui64vEXT,                     void,           (semaphore, pname, params), (GLuint semaphore, GLenum pname, const GLuint64 *params)) \
    GB_DECL_FWD     (glGetSemaphoreParameterui64vEXT,                  void,           (semaphore, pname, params), (GLuint semaphore, GLenum pname, GLuint64 *params)) \
    GB_DECL_FWD     (glWaitSemaphoreEXT,                               void,           (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts), (GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *srcLayouts)) \
    GB_DECL_FWD     (glSignalSemaphoreEXT,                             void,           (semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts), (GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *dstLayouts)) \
    GB_DECL_FWD     (glImportSemaphoreFdEXT,                           void,           (semaphore, handleType, fd), (GLuint semaphore, GLenum handleType, GLint fd)) \
    GB_DECL_FWD     (glImportSemaphoreWin32HandleEXT,                  void,           (semaphore, handleType, handle), (GLuint semaphore, GLenum handleType, void *handle)) \
    GB_DECL_FWD     (glImportSemaphoreWin32NameEXT,                    void,           (semaphore, handleType, name), (GLuint semaphore, GLenum handleType, const void *name)) \
    GB_DECL_FWD     (glActiveShaderProgramEXT,                         void,           (pipeline, program), (GLuint pipeline, GLuint program)) \
    GB_DECL_FWD     (glBindProgramPipelineEXT,                         void,           (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD     (glCreateShaderProgramvEXT,                        GLuint,         (type, count, strings), (GLenum type, GLsizei count, const GLchar **strings)) \
    GB_DECL_FWD     (glDeleteProgramPipelinesEXT,                      void,           (n, pipelines), (GLsizei n, const GLuint *pipelines)) \
    GB_DECL_FWD     (glGenProgramPipelinesEXT,                         void,           (n, pipelines), (GLsizei n, GLuint *pipelines)) \
    GB_DECL_FWD     (glGetProgramPipelineInfoLogEXT,                   void,           (pipeline, bufSize, length, infoLog), (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    GB_DECL_FWD     (glGetProgramPipelineivEXT,                        void,           (pipeline, pname, params), (GLuint pipeline, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glIsProgramPipelineEXT,                           GLboolean,      (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD     (glProgramParameteriEXT,                           void,           (program, pname, value), (GLuint program, GLenum pname, GLint value)) \
    GB_DECL_FWD     (glProgramUniform1fEXT,                            void,           (program, location, v0), (GLuint program, GLint location, GLfloat v0)) \
    GB_DECL_FWD     (glProgramUniform1fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniform1iEXT,                            void,           (program, location, v0), (GLuint program, GLint location, GLint v0)) \
    GB_DECL_FWD     (glProgramUniform1ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glProgramUniform2fEXT,                            void,           (program, location, v0, v1), (GLuint program, GLint location, GLfloat v0, GLfloat v1)) \
    GB_DECL_FWD     (glProgramUniform2fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniform2iEXT,                            void,           (program, location, v0, v1), (GLuint program, GLint location, GLint v0, GLint v1)) \
    GB_DECL_FWD     (glProgramUniform2ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glProgramUniform3fEXT,                            void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    GB_DECL_FWD     (glProgramUniform3fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniform3iEXT,                            void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLint v0, GLint v1, GLint v2)) \
    GB_DECL_FWD     (glProgramUniform3ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glProgramUniform4fEXT,                            void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    GB_DECL_FWD     (glProgramUniform4fvEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniform4iEXT,                            void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    GB_DECL_FWD     (glProgramUniform4ivEXT,                           void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix2fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix3fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix4fvEXT,                     void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUseProgramStagesEXT,                            void,           (pipeline, stages, program), (GLuint pipeline, GLbitfield stages, GLuint program)) \
    GB_DECL_FWD     (glValidateProgramPipelineEXT,                     void,           (pipeline), (GLuint pipeline)) \
    GB_DECL_FWD     (glProgramUniform1uiEXT,                           void,           (program, location, v0), (GLuint program, GLint location, GLuint v0)) \
    GB_DECL_FWD     (glProgramUniform2uiEXT,                           void,           (program, location, v0, v1), (GLuint program, GLint location, GLuint v0, GLuint v1)) \
    GB_DECL_FWD     (glProgramUniform3uiEXT,                           void,           (program, location, v0, v1, v2), (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)) \
    GB_DECL_FWD     (glProgramUniform4uiEXT,                           void,           (program, location, v0, v1, v2, v3), (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \
    GB_DECL_FWD     (glProgramUniform1uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD     (glProgramUniform2uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD     (glProgramUniform3uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD     (glProgramUniform4uivEXT,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix2x3fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix3x2fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix2x4fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix4x2fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix3x4fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glProgramUniformMatrix4x3fvEXT,                   void,           (program, location, count, transpose, value), (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glFramebufferFetchBarrierEXT,                     void,           (), (void)) \
    GB_DECL_FWD     (glFramebufferPixelLocalStorageSizeEXT,            void,           (target, size), (GLuint target, GLsizei size)) \
    GB_DECL_FWD     (glGetFramebufferPixelLocalStorageSizeEXT,         GLsizei,        (target), (GLuint target)) \
    GB_DECL_FWD     (glClearPixelLocalStorageuiEXT,                    void,           (offset, n, values), (GLsizei offset, GLsizei n, const GLuint *values)) \
    GB_DECL_FWD     (glTexPageCommitmentEXT,                           void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, commit), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit)) \
    GB_DECL_FWD     (glPatchParameteriEXT,                             void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD     (glTexParameterIivEXT,                             void,           (target, pname, params), (GLenum target, GLenum pname, const GLint *params)) \
    GB_DECL_FWD     (glTexParameterIuivEXT,                            void,           (target, pname, params), (GLenum target, GLenum pname, const GLuint *params)) \
    GB_DECL_FWD     (glGetTexParameterIivEXT,                          void,           (target, pname, params), (GLenum target, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetTexParameterIuivEXT,                         void,           (target, pname, params), (GLenum target, GLenum pname, GLuint *params)) \
    GB_DECL_FWD     (glSamplerParameterIivEXT,                         void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLint *param)) \
    GB_DECL_FWD     (glSamplerParameterIuivEXT,                        void,           (sampler, pname, param), (GLuint sampler, GLenum pname, const GLuint *param)) \
    GB_DECL_FWD     (glGetSamplerParameterIivEXT,                      void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glGetSamplerParameterIuivEXT,                     void,           (sampler, pname, params), (GLuint sampler, GLenum pname, GLuint *params)) \
    GB_DECL_FWD     (glTexBufferEXT,                                   void,           (target, internalformat, buffer), (GLenum target, GLenum internalformat, GLuint buffer)) \
    GB_DECL_FWD     (glTexBufferRangeEXT,                              void,           (target, internalformat, buffer, offset, size), (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    GB_DECL_FWD     (glTexStorage1DEXT,                                void,           (target, levels, internalformat, width), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)) \
    GB_DECL_FWD     (glTexStorage2DEXT,                                void,           (target, levels, internalformat, width, height), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glTexStorage3DEXT,                                void,           (target, levels, internalformat, width, height, depth), (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    GB_DECL_FWD     (glTextureStorage1DEXT,                            void,           (texture, target, levels, internalformat, width), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)) \
    GB_DECL_FWD     (glTextureStorage2DEXT,                            void,           (texture, target, levels, internalformat, width, height), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glTextureStorage3DEXT,                            void,           (texture, target, levels, internalformat, width, height, depth), (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    GB_DECL_FWD     (glTextureViewEXT,                                 void,           (texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers), (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)) \
    GB_DECL_FWD     (glAcquireKeyedMutexWin32EXT,                      GLboolean,      (memory, key, timeout), (GLuint memory, GLuint64 key, GLuint timeout)) \
    GB_DECL_FWD     (glReleaseKeyedMutexWin32EXT,                      GLboolean,      (memory, key), (GLuint memory, GLuint64 key)) \
    GB_DECL_FWD     (glWindowRectanglesEXT,                            void,           (mode, count, box), (GLenum mode, GLsizei count, const GLint *box)) \
    GB_DECL_FWD     (glGetTextureHandleIMG,                            GLuint64,       (texture), (GLuint texture)) \
    GB_DECL_FWD     (glGetTextureSamplerHandleIMG,                     GLuint64,       (texture, sampler), (GLuint texture, GLuint sampler)) \
    GB_DECL_FWD     (glUniformHandleui64IMG,                           void,           (location, value), (GLint location, GLuint64 value)) \
    GB_DECL_FWD     (glUniformHandleui64vIMG,                          void,           (location, count, value), (GLint location, GLsizei count, const GLuint64 *value)) \
    GB_DECL_FWD     (glProgramUniformHandleui64IMG,                    void,           (program, location, value), (GLuint program, GLint location, GLuint64 value)) \
    GB_DECL_FWD     (glProgramUniformHandleui64vIMG,                   void,           (program, location, count, values), (GLuint program, GLint location, GLsizei count, const GLuint64 *values)) \
    GB_DECL_FWD     (glFramebufferTexture2DDownsampleIMG,              void,           (target, attachment, textarget, texture, level, xscale, yscale), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint xscale, GLint yscale)) \
    GB_DECL_FWD     (glFramebufferTextureLayerDownsampleIMG,           void,           (target, attachment, texture, level, layer, xscale, yscale), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLint xscale, GLint yscale)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleIMG,              void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glFramebufferTexture2DMultisampleIMG,             void,           (target, attachment, textarget, texture, level, samples), (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)) \
    GB_DECL_FWD     (glApplyFramebufferAttachmentCMAAINTEL,            void,           (), (void)) \
    GB_DECL_FWD     (glBeginPerfQueryINTEL,                            void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD     (glCreatePerfQueryINTEL,                           void,           (queryId, queryHandle), (GLuint queryId, GLuint *queryHandle)) \
    GB_DECL_FWD     (glDeletePerfQueryINTEL,                           void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD     (glEndPerfQueryINTEL,                              void,           (queryHandle), (GLuint queryHandle)) \
    GB_DECL_FWD     (glGetFirstPerfQueryIdINTEL,                       void,           (queryId), (GLuint *queryId)) \
    GB_DECL_FWD     (glGetNextPerfQueryIdINTEL,                        void,           (queryId, nextQueryId), (GLuint queryId, GLuint *nextQueryId)) \
    GB_DECL_FWD     (glGetPerfCounterInfoINTEL,                        void,           (queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue), (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue)) \
    GB_DECL_FWD     (glGetPerfQueryDataINTEL,                          void,           (queryHandle, flags, dataSize, data, bytesWritten), (GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten)) \
    GB_DECL_FWD     (glGetPerfQueryIdByNameINTEL,                      void,           (queryName, queryId), (GLchar *queryName, GLuint *queryId)) \
    GB_DECL_FWD     (glGetPerfQueryInfoINTEL,                          void,           (queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask), (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask)) \
    GB_DECL_FWD     (glGetTextureHandleNV,                             GLuint64,       (texture), (GLuint texture)) \
    GB_DECL_FWD     (glGetTextureSamplerHandleNV,                      GLuint64,       (texture, sampler), (GLuint texture, GLuint sampler)) \
    GB_DECL_FWD     (glMakeTextureHandleResidentNV,                    void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glMakeTextureHandleNonResidentNV,                 void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glGetImageHandleNV,                               GLuint64,       (texture, level, layered, layer, format), (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)) \
    GB_DECL_FWD     (glMakeImageHandleResidentNV,                      void,           (handle, access), (GLuint64 handle, GLenum access)) \
    GB_DECL_FWD     (glMakeImageHandleNonResidentNV,                   void,           (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glUniformHandleui64NV,                            void,           (location, value), (GLint location, GLuint64 value)) \
    GB_DECL_FWD     (glUniformHandleui64vNV,                           void,           (location, count, value), (GLint location, GLsizei count, const GLuint64 *value)) \
    GB_DECL_FWD     (glProgramUniformHandleui64NV,                     void,           (program, location, value), (GLuint program, GLint location, GLuint64 value)) \
    GB_DECL_FWD     (glProgramUniformHandleui64vNV,                    void,           (program, location, count, values), (GLuint program, GLint location, GLsizei count, const GLuint64 *values)) \
    GB_DECL_FWD     (glIsTextureHandleResidentNV,                      GLboolean,      (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glIsImageHandleResidentNV,                        GLboolean,      (handle), (GLuint64 handle)) \
    GB_DECL_FWD     (glBlendParameteriNV,                              void,           (pname, value), (GLenum pname, GLint value)) \
    GB_DECL_FWD     (glBlendBarrierNV,                                 void,           (), (void)) \
    GB_DECL_FWD     (glViewportPositionWScaleNV,                       void,           (index, xcoeff, ycoeff), (GLuint index, GLfloat xcoeff, GLfloat ycoeff)) \
    GB_DECL_FWD     (glBeginConditionalRenderNV,                       void,           (id, mode), (GLuint id, GLenum mode)) \
    GB_DECL_FWD     (glEndConditionalRenderNV,                         void,           (), (void)) \
    GB_DECL_FWD     (glSubpixelPrecisionBiasNV,                        void,           (xbits, ybits), (GLuint xbits, GLuint ybits)) \
    GB_DECL_FWD     (glConservativeRasterParameteriNV,                 void,           (pname, param), (GLenum pname, GLint param)) \
    GB_DECL_FWD     (glCopyBufferSubDataNV,                            void,           (readTarget, writeTarget, readOffset, writeOffset, size), (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)) \
    GB_DECL_FWD     (glCoverageMaskNV,                                 void,           (mask), (GLboolean mask)) \
    GB_DECL_FWD     (glCoverageOperationNV,                            void,           (operation), (GLenum operation)) \
    GB_DECL_FWD     (glDrawBuffersNV,                                  void,           (n, bufs), (GLsizei n, const GLenum *bufs)) \
    GB_DECL_FWD     (glDrawArraysInstancedNV,                          void,           (mode, first, count, primcount), (GLenum mode, GLint first, GLsizei count, GLsizei primcount)) \
    GB_DECL_FWD     (glDrawElementsInstancedNV,                        void,           (mode, count, type, indices, primcount), (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)) \
    GB_DECL_FWD     (glDrawVkImageNV,                                  void,           (vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1), (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)) \
    GB_DECL_FWD     (glGetVkProcAddrNV,                                GLVULKANPROCNV, (name), (const GLchar *name)) \
    GB_DECL_FWD     (glWaitVkSemaphoreNV,                              void,           (vkSemaphore), (GLuint64 vkSemaphore)) \
    GB_DECL_FWD     (glSignalVkSemaphoreNV,                            void,           (vkSemaphore), (GLuint64 vkSemaphore)) \
    GB_DECL_FWD     (glSignalVkFenceNV,                                void,           (vkFence), (GLuint64 vkFence)) \
    GB_DECL_FWD     (glDeleteFencesNV,                                 void,           (n, fences), (GLsizei n, const GLuint *fences)) \
    GB_DECL_FWD     (glGenFencesNV,                                    void,           (n, fences), (GLsizei n, GLuint *fences)) \
    GB_DECL_FWD     (glIsFenceNV,                                      GLboolean,      (fence), (GLuint fence)) \
    GB_DECL_FWD     (glTestFenceNV,                                    GLboolean,      (fence), (GLuint fence)) \
    GB_DECL_FWD     (glGetFenceivNV,                                   void,           (fence, pname, params), (GLuint fence, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glFinishFenceNV,                                  void,           (fence), (GLuint fence)) \
    GB_DECL_FWD     (glSetFenceNV,                                     void,           (fence, condition), (GLuint fence, GLenum condition)) \
    GB_DECL_FWD     (glFragmentCoverageColorNV,                        void,           (color), (GLuint color)) \
    GB_DECL_FWD     (glBlitFramebufferNV,                              void,           (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter), (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    GB_DECL_FWD     (glCoverageModulationTableNV,                      void,           (n, v), (GLsizei n, const GLfloat *v)) \
    GB_DECL_FWD     (glGetCoverageModulationTableNV,                   void,           (bufsize, v), (GLsizei bufsize, GLfloat *v)) \
    GB_DECL_FWD     (glCoverageModulationNV,                           void,           (components), (GLenum components)) \
    GB_DECL_FWD     (glRenderbufferStorageMultisampleNV,               void,           (target, samples, internalformat, width, height), (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glUniform1i64NV,                                  void,           (location, x), (GLint location, GLint64EXT x)) \
    GB_DECL_FWD     (glUniform2i64NV,                                  void,           (location, x, y), (GLint location, GLint64EXT x, GLint64EXT y)) \
    GB_DECL_FWD     (glUniform3i64NV,                                  void,           (location, x, y, z), (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)) \
    GB_DECL_FWD     (glUniform4i64NV,                                  void,           (location, x, y, z, w), (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)) \
    GB_DECL_FWD     (glUniform1i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glUniform2i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glUniform3i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glUniform4i64vNV,                                 void,           (location, count, value), (GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glUniform1ui64NV,                                 void,           (location, x), (GLint location, GLuint64EXT x)) \
    GB_DECL_FWD     (glUniform2ui64NV,                                 void,           (location, x, y), (GLint location, GLuint64EXT x, GLuint64EXT y)) \
    GB_DECL_FWD     (glUniform3ui64NV,                                 void,           (location, x, y, z), (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)) \
    GB_DECL_FWD     (glUniform4ui64NV,                                 void,           (location, x, y, z, w), (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)) \
    GB_DECL_FWD     (glUniform1ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glUniform2ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glUniform3ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glUniform4ui64vNV,                                void,           (location, count, value), (GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glGetUniformi64vNV,                               void,           (program, location, params), (GLuint program, GLint location, GLint64EXT *params)) \
    GB_DECL_FWD     (glProgramUniform1i64NV,                           void,           (program, location, x), (GLuint program, GLint location, GLint64EXT x)) \
    GB_DECL_FWD     (glProgramUniform2i64NV,                           void,           (program, location, x, y), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y)) \
    GB_DECL_FWD     (glProgramUniform3i64NV,                           void,           (program, location, x, y, z), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)) \
    GB_DECL_FWD     (glProgramUniform4i64NV,                           void,           (program, location, x, y, z, w), (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)) \
    GB_DECL_FWD     (glProgramUniform1i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform2i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform3i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform4i64vNV,                          void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform1ui64NV,                          void,           (program, location, x), (GLuint program, GLint location, GLuint64EXT x)) \
    GB_DECL_FWD     (glProgramUniform2ui64NV,                          void,           (program, location, x, y), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y)) \
    GB_DECL_FWD     (glProgramUniform3ui64NV,                          void,           (program, location, x, y, z), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)) \
    GB_DECL_FWD     (glProgramUniform4ui64NV,                          void,           (program, location, x, y, z, w), (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)) \
    GB_DECL_FWD     (glProgramUniform1ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform2ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform3ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glProgramUniform4ui64vNV,                         void,           (program, location, count, value), (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)) \
    GB_DECL_FWD     (glVertexAttribDivisorNV,                          void,           (index, divisor), (GLuint index, GLuint divisor)) \
    GB_DECL_FWD     (glGetInternalformatSampleivNV,                    void,           (target, internalformat, samples, pname, bufSize, params), (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params)) \
    GB_DECL_FWD     (glGetMemoryObjectDetachedResourcesuivNV,          void,           (memory, pname, first, count, params), (GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params)) \
    GB_DECL_FWD     (glResetMemoryObjectParameterNV,                   void,           (memory, pname), (GLuint memory, GLenum pname)) \
    GB_DECL_FWD     (glTexAttachMemoryNV,                              void,           (target, memory, offset), (GLenum target, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glBufferAttachMemoryNV,                           void,           (target, memory, offset), (GLenum target, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glTextureAttachMemoryNV,                          void,           (texture, memory, offset), (GLuint texture, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glNamedBufferAttachMemoryNV,                      void,           (buffer, memory, offset), (GLuint buffer, GLuint memory, GLuint64 offset)) \
    GB_DECL_FWD     (glDrawMeshTasksNV,                                void,           (first, count), (GLuint first, GLuint count)) \
    GB_DECL_FWD     (glDrawMeshTasksIndirectNV,                        void,           (indirect), (GLintptr indirect)) \
    GB_DECL_FWD     (glMultiDrawMeshTasksIndirectNV,                   void,           (indirect, drawcount, stride), (GLintptr indirect, GLsizei drawcount, GLsizei stride)) \
    GB_DECL_FWD     (glMultiDrawMeshTasksIndirectCountNV,              void,           (indirect, drawcount, maxdrawcount, stride), (GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)) \
    GB_DECL_FWD     (glUniformMatrix2x3fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix3x2fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix2x4fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix4x2fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix3x4fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glUniformMatrix4x3fvNV,                           void,           (location, count, transpose, value), (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    GB_DECL_FWD     (glGenPathsNV,                                     GLuint,         (range), (GLsizei range)) \
    GB_DECL_FWD     (glDeletePathsNV,                                  void,           (path, range), (GLuint path, GLsizei range)) \
    GB_DECL_FWD     (glIsPathNV,                                       GLboolean,      (path), (GLuint path)) \
    GB_DECL_FWD     (glPathCommandsNV,                                 void,           (path, numCommands, commands, numCoords, coordType, coords), (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD     (glPathCoordsNV,                                   void,           (path, numCoords, coordType, coords), (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD     (glPathSubCommandsNV,                              void,           (path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords), (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD     (glPathSubCoordsNV,                                void,           (path, coordStart, numCoords, coordType, coords), (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords)) \
    GB_DECL_FWD     (glPathStringNV,                                   void,           (path, format, length, pathString), (GLuint path, GLenum format, GLsizei length, const void *pathString)) \
    GB_DECL_FWD     (glPathGlyphsNV,                                   void,           (firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD     (glPathGlyphRangeNV,                               void,           (firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD     (glWeightPathsNV,                                  void,           (resultPath, numPaths, paths, weights), (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights)) \
    GB_DECL_FWD     (glCopyPathNV,                                     void,           (resultPath, srcPath), (GLuint resultPath, GLuint srcPath)) \
    GB_DECL_FWD     (glInterpolatePathsNV,                             void,           (resultPath, pathA, pathB, weight), (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)) \
    GB_DECL_FWD     (glTransformPathNV,                                void,           (resultPath, srcPath, transformType, transformValues), (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glPathParameterivNV,                              void,           (path, pname, value), (GLuint path, GLenum pname, const GLint *value)) \
    GB_DECL_FWD     (glPathParameteriNV,                               void,           (path, pname, value), (GLuint path, GLenum pname, GLint value)) \
    GB_DECL_FWD     (glPathParameterfvNV,                              void,           (path, pname, value), (GLuint path, GLenum pname, const GLfloat *value)) \
    GB_DECL_FWD     (glPathParameterfNV,                               void,           (path, pname, value), (GLuint path, GLenum pname, GLfloat value)) \
    GB_DECL_FWD     (glPathDashArrayNV,                                void,           (path, dashCount, dashArray), (GLuint path, GLsizei dashCount, const GLfloat *dashArray)) \
    GB_DECL_FWD     (glPathStencilFuncNV,                              void,           (func, ref, mask), (GLenum func, GLint ref, GLuint mask)) \
    GB_DECL_FWD     (glPathStencilDepthOffsetNV,                       void,           (factor, units), (GLfloat factor, GLfloat units)) \
    GB_DECL_FWD     (glStencilFillPathNV,                              void,           (path, fillMode, mask), (GLuint path, GLenum fillMode, GLuint mask)) \
    GB_DECL_FWD     (glStencilStrokePathNV,                            void,           (path, reference, mask), (GLuint path, GLint reference, GLuint mask)) \
    GB_DECL_FWD     (glStencilFillPathInstancedNV,                     void,           (numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glStencilStrokePathInstancedNV,                   void,           (numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glPathCoverDepthFuncNV,                           void,           (func), (GLenum func)) \
    GB_DECL_FWD     (glCoverFillPathNV,                                void,           (path, coverMode), (GLuint path, GLenum coverMode)) \
    GB_DECL_FWD     (glCoverStrokePathNV,                              void,           (path, coverMode), (GLuint path, GLenum coverMode)) \
    GB_DECL_FWD     (glCoverFillPathInstancedNV,                       void,           (numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glCoverStrokePathInstancedNV,                     void,           (numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glGetPathParameterivNV,                           void,           (path, pname, value), (GLuint path, GLenum pname, GLint *value)) \
    GB_DECL_FWD     (glGetPathParameterfvNV,                           void,           (path, pname, value), (GLuint path, GLenum pname, GLfloat *value)) \
    GB_DECL_FWD     (glGetPathCommandsNV,                              void,           (path, commands), (GLuint path, GLubyte *commands)) \
    GB_DECL_FWD     (glGetPathCoordsNV,                                void,           (path, coords), (GLuint path, GLfloat *coords)) \
    GB_DECL_FWD     (glGetPathDashArrayNV,                             void,           (path, dashArray), (GLuint path, GLfloat *dashArray)) \
    GB_DECL_FWD     (glGetPathMetricsNV,                               void,           (metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics), (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics)) \
    GB_DECL_FWD     (glGetPathMetricRangeNV,                           void,           (metricQueryMask, firstPathName, numPaths, stride, metrics), (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics)) \
    GB_DECL_FWD     (glGetPathSpacingNV,                               void,           (pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing), (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing)) \
    GB_DECL_FWD     (glIsPointInFillPathNV,                            GLboolean,      (path, mask, x, y), (GLuint path, GLuint mask, GLfloat x, GLfloat y)) \
    GB_DECL_FWD     (glIsPointInStrokePathNV,                          GLboolean,      (path, x, y), (GLuint path, GLfloat x, GLfloat y)) \
    GB_DECL_FWD     (glGetPathLengthNV,                                GLfloat,        (path, startSegment, numSegments), (GLuint path, GLsizei startSegment, GLsizei numSegments)) \
    GB_DECL_FWD     (glPointAlongPathNV,                               GLboolean,      (path, startSegment, numSegments, distance, x, y, tangentX, tangentY), (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY)) \
    GB_DECL_FWD     (glMatrixLoad3x2fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixLoad3x3fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixLoadTranspose3x3fNV,                      void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixMult3x2fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixMult3x3fNV,                               void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixMultTranspose3x3fNV,                      void,           (matrixMode, m), (GLenum matrixMode, const GLfloat *m)) \
    GB_DECL_FWD     (glStencilThenCoverFillPathNV,                     void,           (path, fillMode, mask, coverMode), (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)) \
    GB_DECL_FWD     (glStencilThenCoverStrokePathNV,                   void,           (path, reference, mask, coverMode), (GLuint path, GLint reference, GLuint mask, GLenum coverMode)) \
    GB_DECL_FWD     (glStencilThenCoverFillPathInstancedNV,            void,           (numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glStencilThenCoverStrokePathInstancedNV,          void,           (numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues), (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)) \
    GB_DECL_FWD     (glPathGlyphIndexRangeNV,                          GLenum,         (fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount), (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2])) \
    GB_DECL_FWD     (glPathGlyphIndexArrayNV,                          GLenum,         (firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD     (glPathMemoryGlyphIndexArrayNV,                    GLenum,         (firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale), (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)) \
    GB_DECL_FWD     (glProgramPathFragmentInputGenNV,                  void,           (program, location, genMode, components, coeffs), (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs)) \
    GB_DECL_FWD     (glGetProgramResourcefvNV,                         void,           (program, programInterface, index, propCount, props, bufSize, length, params), (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params)) \
    GB_DECL_FWD     (glMatrixFrustumEXT,                               void,           (mode, left, right, bottom, top, zNear, zFar), (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)) \
    GB_DECL_FWD     (glMatrixLoadIdentityEXT,                          void,           (mode), (GLenum mode)) \
    GB_DECL_FWD     (glMatrixLoadTransposefEXT,                        void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixLoadTransposedEXT,                        void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD     (glMatrixLoadfEXT,                                 void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixLoaddEXT,                                 void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD     (glMatrixMultTransposefEXT,                        void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixMultTransposedEXT,                        void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD     (glMatrixMultfEXT,                                 void,           (mode, m), (GLenum mode, const GLfloat *m)) \
    GB_DECL_FWD     (glMatrixMultdEXT,                                 void,           (mode, m), (GLenum mode, const GLdouble *m)) \
    GB_DECL_FWD     (glMatrixOrthoEXT,                                 void,           (mode, left, right, bottom, top, zNear, zFar), (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)) \
    GB_DECL_FWD     (glMatrixPopEXT,                                   void,           (mode), (GLenum mode)) \
    GB_DECL_FWD     (glMatrixPushEXT,                                  void,           (mode), (GLenum mode)) \
    GB_DECL_FWD     (glMatrixRotatefEXT,                               void,           (mode, angle, x, y, z), (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD     (glMatrixRotatedEXT,                               void,           (mode, angle, x, y, z), (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD     (glMatrixScalefEXT,                                void,           (mode, x, y, z), (GLenum mode, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD     (glMatrixScaledEXT,                                void,           (mode, x, y, z), (GLenum mode, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD     (glMatrixTranslatefEXT,                            void,           (mode, x, y, z), (GLenum mode, GLfloat x, GLfloat y, GLfloat z)) \
    GB_DECL_FWD     (glMatrixTranslatedEXT,                            void,           (mode, x, y, z), (GLenum mode, GLdouble x, GLdouble y, GLdouble z)) \
    GB_DECL_FWD     (glPolygonModeNV,                                  void,           (face, mode), (GLenum face, GLenum mode)) \
    GB_DECL_FWD     (glReadBufferNV,                                   void,           (mode), (GLenum mode)) \
    GB_DECL_FWD     (glFramebufferSampleLocationsfvNV,                 void,           (target, start, count, v), (GLenum target, GLuint start, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glNamedFramebufferSampleLocationsfvNV,            void,           (framebuffer, start, count, v), (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glResolveDepthValuesNV,                           void,           (), (void)) \
    GB_DECL_FWD     (glScissorExclusiveNV,                             void,           (x, y, width, height), (GLint x, GLint y, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glScissorExclusiveArrayvNV,                       void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD     (glBindShadingRateImageNV,                         void,           (texture), (GLuint texture)) \
    GB_DECL_FWD     (glGetShadingRateImagePaletteNV,                   void,           (viewport, entry, rate), (GLuint viewport, GLuint entry, GLenum *rate)) \
    GB_DECL_FWD     (glGetShadingRateSampleLocationivNV,               void,           (rate, samples, index, location), (GLenum rate, GLuint samples, GLuint index, GLint *location)) \
    GB_DECL_FWD     (glShadingRateImageBarrierNV,                      void,           (synchronize), (GLboolean synchronize)) \
    GB_DECL_FWD     (glShadingRateImagePaletteNV,                      void,           (viewport, first, count, rates), (GLuint viewport, GLuint first, GLsizei count, const GLenum *rates)) \
    GB_DECL_FWD     (glShadingRateSampleOrderNV,                       void,           (order), (GLenum order)) \
    GB_DECL_FWD     (glShadingRateSampleOrderCustomNV,                 void,           (rate, samples, locations), (GLenum rate, GLuint samples, const GLint *locations)) \
    GB_DECL_FWD     (glViewportArrayvNV,                               void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glViewportIndexedfNV,                             void,           (index, x, y, w, h), (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)) \
    GB_DECL_FWD     (glViewportIndexedfvNV,                            void,           (index, v), (GLuint index, const GLfloat *v)) \
    GB_DECL_FWD     (glScissorArrayvNV,                                void,           (first, count, v), (GLuint first, GLsizei count, const GLint *v)) \
    GB_DECL_FWD     (glScissorIndexedNV,                               void,           (index, left, bottom, width, height), (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)) \
    GB_DECL_FWD     (glScissorIndexedvNV,                              void,           (index, v), (GLuint index, const GLint *v)) \
    GB_DECL_FWD     (glDepthRangeArrayfvNV,                            void,           (first, count, v), (GLuint first, GLsizei count, const GLfloat *v)) \
    GB_DECL_FWD     (glDepthRangeIndexedfNV,                           void,           (index, n, f), (GLuint index, GLfloat n, GLfloat f)) \
    GB_DECL_FWD     (glGetFloati_vNV,                                  void,           (target, index, data), (GLenum target, GLuint index, GLfloat *data)) \
    GB_DECL_FWD     (glEnableiNV,                                      void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glDisableiNV,                                     void,           (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glIsEnablediNV,                                   GLboolean,      (target, index), (GLenum target, GLuint index)) \
    GB_DECL_FWD     (glViewportSwizzleNV,                              void,           (index, swizzlex, swizzley, swizzlez, swizzlew), (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew)) \
    GB_DECL_FWD     (glFramebufferTextureMultiviewOVR,                 void,           (target, attachment, texture, level, baseViewIndex, numViews), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)) \
    GB_DECL_FWD     (glFramebufferTextureMultisampleMultiviewOVR,      void,           (target, attachment, texture, level, samples, baseViewIndex, numViews), (GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei samples, GLint baseViewIndex, GLsizei numViews)) \
    GB_DECL_FWD     (glAlphaFuncQCOM,                                  void,           (func, ref), (GLenum func, GLclampf ref)) \
    GB_DECL_FWD     (glGetDriverControlsQCOM,                          void,           (num, size, driverControls), (GLint *num, GLsizei size, GLuint *driverControls)) \
    GB_DECL_FWD     (glGetDriverControlStringQCOM,                     void,           (driverControl, bufSize, length, driverControlString), (GLuint driverControl, GLsizei bufSize, GLsizei *length, GLchar *driverControlString)) \
    GB_DECL_FWD     (glEnableDriverControlQCOM,                        void,           (driverControl), (GLuint driverControl)) \
    GB_DECL_FWD     (glDisableDriverControlQCOM,                       void,           (driverControl), (GLuint driverControl)) \
    GB_DECL_FWD     (glExtGetTexturesQCOM,                             void,           (textures, maxTextures, numTextures), (GLuint *textures, GLint maxTextures, GLint *numTextures)) \
    GB_DECL_FWD     (glExtGetBuffersQCOM,                              void,           (buffers, maxBuffers, numBuffers), (GLuint *buffers, GLint maxBuffers, GLint *numBuffers)) \
    GB_DECL_FWD     (glExtGetRenderbuffersQCOM,                        void,           (renderbuffers, maxRenderbuffers, numRenderbuffers), (GLuint *renderbuffers, GLint maxRenderbuffers, GLint *numRenderbuffers)) \
    GB_DECL_FWD     (glExtGetFramebuffersQCOM,                         void,           (framebuffers, maxFramebuffers, numFramebuffers), (GLuint *framebuffers, GLint maxFramebuffers, GLint *numFramebuffers)) \
    GB_DECL_FWD     (glExtGetTexLevelParameterivQCOM,                  void,           (texture, face, level, pname, params), (GLuint texture, GLenum face, GLint level, GLenum pname, GLint *params)) \
    GB_DECL_FWD     (glExtTexObjectStateOverrideiQCOM,                 void,           (target, pname, param), (GLenum target, GLenum pname, GLint param)) \
    GB_DECL_FWD     (glExtGetTexSubImageQCOM,                          void,           (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, texels), (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, void *texels)) \
    GB_DECL_FWD     (glExtGetBufferPointervQCOM,                       void,           (target, params), (GLenum target, void **params)) \
    GB_DECL_FWD     (glExtGetShadersQCOM,                              void,           (shaders, maxShaders, numShaders), (GLuint *shaders, GLint maxShaders, GLint *numShaders)) \
    GB_DECL_FWD     (glExtGetProgramsQCOM,                             void,           (programs, maxPrograms, numPrograms), (GLuint *programs, GLint maxPrograms, GLint *numPrograms)) \
    GB_DECL_FWD     (glExtIsProgramBinaryQCOM,                         GLboolean,      (program), (GLuint program)) \
    GB_DECL_FWD     (glExtGetProgramBinarySourceQCOM,                  void,           (program, shadertype, source, length), (GLuint program, GLenum shadertype, GLchar *source, GLint *length)) \
    GB_DECL_FWD     (glFramebufferFoveationConfigQCOM,                 void,           (framebuffer, numLayers, focalPointsPerLayer, requestedFeatures, providedFeatures), (GLuint framebuffer, GLuint numLayers, GLuint focalPointsPerLayer, GLuint requestedFeatures, GLuint *providedFeatures)) \
    GB_DECL_FWD     (glFramebufferFoveationParametersQCOM,             void,           (framebuffer, layer, focalPoint, focalX, focalY, gainX, gainY, foveaArea), (GLuint framebuffer, GLuint layer, GLuint focalPoint, GLfloat focalX, GLfloat focalY, GLfloat gainX, GLfloat gainY, GLfloat foveaArea)) \
    GB_DECL_FWD     (glFramebufferFetchBarrierQCOM,                    void,           (), (void)) \
    GB_DECL_FWD     (glTextureFoveationParametersQCOM,                 void,           (texture, layer, focalPoint, focalX, focalY, gainX, gainY, foveaArea), (GLuint texture, GLuint layer, GLuint focalPoint, GLfloat focalX, GLfloat focalY, GLfloat gainX, GLfloat gainY, GLfloat foveaArea)) \
    GB_DECL_FWD     (glStartTilingQCOM,                                void,           (x, y, width, height, preserveMask), (GLuint x, GLuint y, GLuint width, GLuint height, GLbitfield preserveMask)) \
    GB_DECL_FWD     (glEndTilingQCOM,                                  void,           (preserveMask), (GLbitfield preserveMask)) \
    /* VitaGL extensions */ \
    GB_DECL_FWD     (vglColorPointer,                                  void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglColorPointerMapped,                            void,           (type, pointer),                                                                            (GLenum type, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglDrawObjects,                                   void,           (mode, count, implicit_wvp),                                                                (GLenum mode, GLsizei count, GLboolean implicit_wvp)) \
    GB_DECL_FWD     (vglIndexPointer,                                  void,           (type, stride, count, pointer),                                                             (GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglIndexPointerMapped,                            void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD     (vglTexCoordPointer,                               void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglTexCoordPointerMapped,                         void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD     (vglVertexPointer,                                 void,           (size, type, stride, count, pointer),                                                       (GLint size, GLenum type, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglVertexPointerMapped,                           void,           (pointer),                                                                                  (const GLvoid *pointer)) \
    GB_DECL_FWD     (vglBindAttribLocation,                            void,           (prog, index, name, num, type),                                                             (GLuint prog, GLuint index, const GLchar *name, const GLuint num, const GLenum type)) \
    GB_DECL_FWD     (vglBindPackedAttribLocation,                      GLint,          (prog, name, num, type, offset, stride),                                                    (GLuint prog, const GLchar *name, const GLuint num, const GLenum type, GLuint offset, GLint stride)) \
    GB_DECL_FWD     (vglVertexAttribPointer,                           void,           (index, size, type, normalized, stride, count, pointer),                                    (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint count, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglVertexAttribPointerMapped,                     void,           (index, pointer),                                                                           (GLuint index, const GLvoid *pointer)) \
    GB_DECL_FWD     (vglAlloc,                                         void*,          (size, type),                                                                               (uint32_t size, vglMemType type)) \
    GB_DECL_FWD     (vglEnableRuntimeShaderCompiler,                   void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD     (vglEnd,                                           void,           (),                                                                                         (void)) \
    GB_DECL_FWD     (vglForceAlloc,                                    void*,          (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglFree,                                          void,           (addr),                                                                                     (void *addr)) \
    GB_DECL_FWD     (vglGetGxmTexture,                                 SceGxmTexture*, (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD     (vglGetProcAddress,                                void*,          (name),                                                                                     (const char *name)) \
    GB_DECL_FWD     (vglGetTexDataPointer,                             void*,          (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD     (vglHasRuntimeShaderCompiler,                      GLboolean,      (),                                                                                         (void)) \
    GB_DECL_FWD     (vglInit,                                          void,           (legacy_pool_size),                                                                         (int legacy_pool_size)) \
    GB_DECL_FWD     (vglInitExtended,                                  void,           (legacy_pool_size, width, height, ram_threshold, msaa),                                     (int legacy_pool_size, int width, int height, int ram_threshold, SceGxmMultisampleMode msaa)) \
    GB_DECL_FWD     (vglInitWithCustomSizes,                           void,           (legacy_pool_size, width, height, ram_pool_size, cdram_pool_size, phycont_pool_size, msaa), (int legacy_pool_size, int width, int height, int ram_pool_size, int cdram_pool_size, int phycont_pool_size, SceGxmMultisampleMode msaa)) \
    GB_DECL_FWD     (vglMemFree,                                       size_t,         (type),                                                                                     (vglMemType type)) \
    GB_DECL_FWD     (vglSetFragmentBufferSize,                         void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetParamBufferSize,                            void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetUSSEBufferSize,                             void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetVDMBufferSize,                              void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetVertexBufferSize,                           void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetVertexPoolSize,                             void,           (size),                                                                                     (uint32_t size)) \
    GB_DECL_FWD     (vglSetupRuntimeShaderCompiler,                    void,           (opt_level, use_fastmath, use_fastprecision, use_fastint),                                  (shark_opt opt_level, int32_t use_fastmath, int32_t use_fastprecision, int32_t use_fastint)) \
    GB_DECL_FWD     (vglSwapBuffers,                                   void,           (has_commondialog),                                                                         (GLboolean has_commondialog)) \
    GB_DECL_FWD     (vglTexImageDepthBuffer,                           void,           (target),                                                                                   (GLenum target)) \
    GB_DECL_FWD     (vglUseTripleBuffering,                            void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD     (vglUseVram,                                       void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD     (vglUseVramForUSSE,                                void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD     (vglUseExtraMem,                                   void,           (usage),                                                                                    (GLboolean usage)) \
    GB_DECL_FWD     (vglWaitVblankStart,                               void,           (enable),                                                                                   (GLboolean enable))


#define GB_DECL_FWD(func, ret, args, vars) extern ret (*func) vars;
#define GB_DECL_FWD_HOOK GB_DECL_FWD
GLES2_FUNCS
GLES2_EXT_FUNCS
#undef GB_DECL_FWD_HOOK
#undef GB_DECL_FWD

#endif /* __GLES2_MACROS_H__ */