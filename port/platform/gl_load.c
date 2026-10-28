#include "gl.h"
#include <SDL.h>
#include <stdio.h>

static int s_is_es = 1;

#ifndef GL_DIRECT
#define PORT_GL_DEF(type, name) type p_##name;
PORT_GL_FUNCS(PORT_GL_DEF)
#undef PORT_GL_DEF
typedef PFNGLCLEARDEPTHFPROC PFN_CLEARDEPTHF;
typedef void (GL_APIENTRYP PFN_CLEARDEPTH)(double);
static PFN_CLEARDEPTHF s_clear_depthf;
static PFN_CLEARDEPTH s_clear_depth;
#endif

int gl_load(int is_es)
{
    s_is_es = is_es;
#ifndef GL_DIRECT
    int missing = 0;
#define PORT_GL_LOAD(type, name) \
    p_##name = (type)SDL_GL_GetProcAddress(#name); \
    if (!p_##name) { fprintf(stderr, "gl: missing %s\n", #name); missing++; }
    PORT_GL_FUNCS(PORT_GL_LOAD)
#undef PORT_GL_LOAD
    s_clear_depthf = (PFN_CLEARDEPTHF)SDL_GL_GetProcAddress("glClearDepthf");
    if (!is_es || !s_clear_depthf)
        s_clear_depth = (PFN_CLEARDEPTH)SDL_GL_GetProcAddress("glClearDepth");
    return missing ? -1 : 0;
#else
    return 0;
#endif
}

void gl_clear_depth(float d)
{
#ifdef GL_DIRECT
    glClearDepthf(d);
#else
    if (s_clear_depth) s_clear_depth(d);
    else if (s_clear_depthf) s_clear_depthf(d);
#endif
}

int gl_is_es(void) { return s_is_es; }

const char *gl_shader_header(void)
{
    return s_is_es ? "#version 300 es\nprecision highp float;\nprecision highp int;\n"
                   : "#version 330 core\n";
}
