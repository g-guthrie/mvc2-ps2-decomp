/* GL entry points for the port.
 *
 * One code path for three targets:
 *   - Emscripten: WebGL2 through <GLES3/gl3.h> (linked directly).
 *   - native GL ES 3.0 context (preferred) or desktop GL 3.3 core (fallback):
 *     every function is loaded at runtime with SDL_GL_GetProcAddress into the
 *     p_gl* pointers below, so no GL import library is linked and the same
 *     binary works with either context type.
 * Shaders are written once in GLSL ES 3.00; gl_shader_header() returns the
 * matching #version line ("#version 300 es" or "#version 330 core").
 */
#ifndef PORT_GL_H
#define PORT_GL_H

#ifdef __EMSCRIPTEN__
#include <GLES3/gl3.h>
#define GL_DIRECT 1
#else
#define GL_GLES_PROTOTYPES 0
#include <GLES3/gl3.h>
#endif

/* X(PFN type, name) for every GL function the port uses. */
#define PORT_GL_FUNCS(X) \
    X(PFNGLGETSTRINGPROC, glGetString) \
    X(PFNGLGETINTEGERVPROC, glGetIntegerv) \
    X(PFNGLGETERRORPROC, glGetError) \
    X(PFNGLVIEWPORTPROC, glViewport) \
    X(PFNGLCLEARPROC, glClear) \
    X(PFNGLCLEARCOLORPROC, glClearColor) \
    X(PFNGLENABLEPROC, glEnable) \
    X(PFNGLDISABLEPROC, glDisable) \
    X(PFNGLBLENDFUNCPROC, glBlendFunc) \
    X(PFNGLBLENDEQUATIONPROC, glBlendEquation) \
    X(PFNGLDEPTHFUNCPROC, glDepthFunc) \
    X(PFNGLDEPTHMASKPROC, glDepthMask) \
    X(PFNGLCOLORMASKPROC, glColorMask) \
    X(PFNGLSCISSORPROC, glScissor) \
    X(PFNGLGENTEXTURESPROC, glGenTextures) \
    X(PFNGLDELETETEXTURESPROC, glDeleteTextures) \
    X(PFNGLBINDTEXTUREPROC, glBindTexture) \
    X(PFNGLACTIVETEXTUREPROC, glActiveTexture) \
    X(PFNGLTEXIMAGE2DPROC, glTexImage2D) \
    X(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D) \
    X(PFNGLTEXPARAMETERIPROC, glTexParameteri) \
    X(PFNGLPIXELSTOREIPROC, glPixelStorei) \
    X(PFNGLCREATESHADERPROC, glCreateShader) \
    X(PFNGLDELETESHADERPROC, glDeleteShader) \
    X(PFNGLSHADERSOURCEPROC, glShaderSource) \
    X(PFNGLCOMPILESHADERPROC, glCompileShader) \
    X(PFNGLGETSHADERIVPROC, glGetShaderiv) \
    X(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog) \
    X(PFNGLCREATEPROGRAMPROC, glCreateProgram) \
    X(PFNGLATTACHSHADERPROC, glAttachShader) \
    X(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation) \
    X(PFNGLLINKPROGRAMPROC, glLinkProgram) \
    X(PFNGLGETPROGRAMIVPROC, glGetProgramiv) \
    X(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog) \
    X(PFNGLUSEPROGRAMPROC, glUseProgram) \
    X(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation) \
    X(PFNGLUNIFORM1IPROC, glUniform1i) \
    X(PFNGLUNIFORM2FPROC, glUniform2f) \
    X(PFNGLGENBUFFERSPROC, glGenBuffers) \
    X(PFNGLBINDBUFFERPROC, glBindBuffer) \
    X(PFNGLBUFFERDATAPROC, glBufferData) \
    X(PFNGLBUFFERSUBDATAPROC, glBufferSubData) \
    X(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays) \
    X(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray) \
    X(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer) \
    X(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray) \
    X(PFNGLDRAWARRAYSPROC, glDrawArrays) \
    X(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers) \
    X(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer) \
    X(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D) \
    X(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers) \
    X(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer) \
    X(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage) \
    X(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer) \
    X(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus) \
    X(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer) \
    X(PFNGLREADPIXELSPROC, glReadPixels) \
    X(PFNGLREADBUFFERPROC, glReadBuffer) \
    X(PFNGLFINISHPROC, glFinish) \
    X(PFNGLUNIFORM1FPROC, glUniform1f) \
    X(PFNGLUNIFORM2FVPROC, glUniform2fv) \
    X(PFNGLUNIFORM3FVPROC, glUniform3fv) \
    X(PFNGLUNIFORM4FVPROC, glUniform4fv) \
    X(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv) \
    X(PFNGLDRAWELEMENTSPROC, glDrawElements) \
    X(PFNGLDELETEBUFFERSPROC, glDeleteBuffers) \
    X(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays) \
    X(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray) \
    X(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f) \
    X(PFNGLDELETEPROGRAMPROC, glDeleteProgram)

#ifndef GL_DIRECT
#define PORT_GL_DECL(type, name) extern type p_##name;
PORT_GL_FUNCS(PORT_GL_DECL)
#undef PORT_GL_DECL
#define PORT_GL_ALIAS
#include "gl_alias.h"
#endif

/* Clear depth: GLES/WebGL have glClearDepthf; desktop 3.3 core only has
 * glClearDepth(double). Both are wrapped here. */
void gl_clear_depth(float d);

/* Load entry points for the current context (no-op on Emscripten).
 * Returns 0 on success. is_es selects the shader header. */
int gl_load(int is_es);
int gl_is_es(void);
const char *gl_shader_header(void); /* "#version ...\nprecision ...\n" */

#endif
