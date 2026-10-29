/* Renderer core: render state, palette atlas, texture handle tables,
 * batching, 2D primitives, canvas + present, overlay. */
#include "r_internal.h"
#include "decode.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEX 4096
#define MAX_PAL 4096
#define MAX_VERTS 65536

typedef struct TexRec { GLuint gl; int w, h, fmt, used; int linear, clamp; } TexRec;
typedef struct PalRec { int row, ncolors, used; } PalRec;

static struct {
    GLuint prog, vao, vbo;
    GLint u_view, u_mode, u_linear, u_clamp, u_tex, u_pal;
    GLuint pal_tex;
    int pal_next_row;
    GLuint canvas_fbo, canvas_tex, canvas_depth;
    GLuint sharp_fbo, sharp_tex; int sharp_w, sharp_h;
    GLuint white_tex;
    TexRec tex[MAX_TEX];
    PalRec pal[MAX_PAL];
    RVtx verts[MAX_VERTS];
    int nverts;
    /* batch key */
    GLuint cur_tex; int cur_mode;
    /* applied GL state */
    int view_w, view_h;
    /* fl state (func_003DF850) */
    uint32_t state_ad0;    /* D_004C2AD0: blend low byte, 0xC00 modifier, 0x10000 nearest, 0x20000 clamp */
    uint32_t state_ad4;    /* D_004C2AD4 mode flags */
    uint32_t cur_texture;  /* D_004C2AEC */
    uint32_t tex_slots[4]; /* D_004C2A98 */
    uint32_t material_color, fog_color, global_mod, clear_color, state_5f;
    float fog_a, fog_b;
    float matrices[0x60][16];
    uint32_t matrix_dirty;
    uint8_t materials[32][76]; /* 0x39..0x58: D_0061B420 + 76 * n (func_003F1C10 layout) */
    uint8_t lights[3][100];    /* 0x59..0x5B: 0x0061B2F0 + 100 * n, direction at +0x34 normalised */
    int vp_i[4];               /* 0x18: func_003DD5D0 {x, y, w, h} */
    float vp_f[2];             /*        {fa, fb} */
    int ztest;             /* D_004C2A7C */
    int zwrite;
    int blend_ok; GLenum bl_eq, bl_src, bl_dst;
    int scissor[4];
    int origin_x, origin_y;
    int in_overlay;
    int draws, last_draws, last_verts, frame_verts;
} R;

/* ---------------- shaders ---------------- */
static const char *k_vs =
    "in vec4 a_pos;\n"
    "in vec2 a_uv;\n"
    "in vec4 a_col;\n"
    "in float a_pal;\n"
    "uniform vec2 u_view;\n"
    "out vec2 v_uv;\n"
    "out vec4 v_col;\n"
    "flat out float v_pal;\n"
    "void main() {\n"
    "  vec2 n = vec2(a_pos.x / u_view.x * 2.0 - 1.0, 1.0 - a_pos.y / u_view.y * 2.0);\n"
    "  gl_Position = vec4(n * a_pos.w, a_pos.z * a_pos.w, a_pos.w);\n"
    "  v_uv = a_uv; v_col = a_col; v_pal = a_pal;\n"
    "}\n";

static const char *k_fs =
    "uniform int u_mode;   /* 0 flat, 1 rgba texture, 2 index texture + palette atlas */\n"
    "uniform int u_linear; /* state 0x62: bilinear (done by hand for index textures) */\n"
    "uniform int u_clamp;  /* state 0x63: REGION_CLAMP vs repeat */\n"
    "uniform sampler2D u_tex;\n"
    "uniform sampler2D u_pal;\n"
    "in vec2 v_uv;\n"
    "in vec4 v_col;\n"
    "flat in float v_pal;\n"
    "out vec4 o_col;\n"
    "vec4 lut(ivec2 t, ivec2 sz) {\n"
    "  if (u_clamp == 1) t = clamp(t, ivec2(0), sz - 1);\n"
    "  else t = ((t % sz) + sz) % sz;\n"
    "  int i = int(texelFetch(u_tex, t, 0).r * 255.0 + 0.5);\n"
    "  return texelFetch(u_pal, ivec2(i, int(v_pal)), 0);\n"
    "}\n"
    "void main() {\n"
    "  vec4 t = vec4(1.0);\n"
    "  if (u_mode == 1) {\n"
    "    t = texture(u_tex, v_uv);\n"
    "  } else if (u_mode == 2) {\n"
    "    ivec2 sz = textureSize(u_tex, 0);\n"
    "    vec2 p = v_uv * vec2(sz);\n"
    "    if (u_linear == 0) {\n"
    "      t = lut(ivec2(floor(p)), sz);\n"
    "    } else {\n"
    "      p -= 0.5; ivec2 i0 = ivec2(floor(p)); vec2 f = fract(p);\n"
    "      t = mix(mix(lut(i0, sz), lut(i0 + ivec2(1, 0), sz), f.x),\n"
    "              mix(lut(i0 + ivec2(0, 1), sz), lut(i0 + ivec2(1, 1), sz), f.x), f.y);\n"
    "    }\n"
    "  }\n"
    "  vec4 c = t * v_col;   /* GS MODULATE: tex * vertex * 2 with 0x80 = 1.0 */\n"
    "  if (c.a < 0.5 / 255.0) discard; /* GS TEST: alpha != 0 */\n"
    "  o_col = c;\n"
    "}\n";

static GLuint compile(GLenum type, const char *body)
{
    const char *src[2] = { gl_shader_header(), body };
    GLuint s = glCreateShader(type);
    glShaderSource(s, 2, src, NULL);
    glCompileShader(s);
    GLint ok = 0;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[2048];
        glGetShaderInfoLog(s, sizeof log, NULL, log);
        fprintf(stderr, "shader compile failed:\n%s\n", log);
        return 0;
    }
    return s;
}

/* ---------------- canvas ---------------- */
static int make_canvas(void)
{
    glGenTextures(1, &R.canvas_tex);
    glBindTexture(GL_TEXTURE_2D, R.canvas_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FL_SCREEN_W, FL_SCREEN_H, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glGenRenderbuffers(1, &R.canvas_depth);
    glBindRenderbuffer(GL_RENDERBUFFER, R.canvas_depth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, FL_SCREEN_W, FL_SCREEN_H);
    glGenFramebuffers(1, &R.canvas_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, R.canvas_fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, R.canvas_tex, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, R.canvas_depth);
    GLenum st = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    if (st != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "canvas FBO incomplete 0x%x\n", st);
        return -1;
    }
    return 0;
}

int r_init(void)
{
    memset(&R, 0, sizeof R);
    GLuint vs = compile(GL_VERTEX_SHADER, k_vs), fs = compile(GL_FRAGMENT_SHADER, k_fs);
    if (!vs || !fs) return -1;
    R.prog = glCreateProgram();
    glAttachShader(R.prog, vs);
    glAttachShader(R.prog, fs);
    glBindAttribLocation(R.prog, 0, "a_pos");
    glBindAttribLocation(R.prog, 1, "a_uv");
    glBindAttribLocation(R.prog, 2, "a_col");
    glBindAttribLocation(R.prog, 3, "a_pal");
    glLinkProgram(R.prog);
    GLint ok = 0;
    glGetProgramiv(R.prog, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[2048];
        glGetProgramInfoLog(R.prog, sizeof log, NULL, log);
        fprintf(stderr, "link failed:\n%s\n", log);
        return -1;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    R.u_view = glGetUniformLocation(R.prog, "u_view");
    R.u_mode = glGetUniformLocation(R.prog, "u_mode");
    R.u_linear = glGetUniformLocation(R.prog, "u_linear");
    R.u_clamp = glGetUniformLocation(R.prog, "u_clamp");
    R.u_tex = glGetUniformLocation(R.prog, "u_tex");
    R.u_pal = glGetUniformLocation(R.prog, "u_pal");
    glUseProgram(R.prog);
    glUniform1i(R.u_tex, 0);
    glUniform1i(R.u_pal, 1);

    glGenVertexArrays(1, &R.vao);
    glBindVertexArray(R.vao);
    glGenBuffers(1, &R.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, R.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof R.verts, NULL, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(RVtx), (void *)offsetof(RVtx, x));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(RVtx), (void *)offsetof(RVtx, u));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(RVtx), (void *)offsetof(RVtx, c));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(RVtx), (void *)offsetof(RVtx, pal));

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    /* palette atlas: 256 colours x R_PAL_ROWS rows, RGBA8, fetched with texelFetch */
    glGenTextures(1, &R.pal_tex);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, R.pal_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 256, R_PAL_ROWS, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glActiveTexture(GL_TEXTURE0);
    R.pal_next_row = 1; /* row 0 stays black/transparent */
    {
        static const uint8_t white[4] = { 255, 255, 255, 255 };
        glGenTextures(1, &R.white_tex);
        glBindTexture(GL_TEXTURE_2D, R.white_tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, white);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    if (make_canvas()) return -1;
    R.cur_tex = R.white_tex;
    /* viewport default {0, 0, 640, 480, 0.0, 1.0} (D_004F8040, func_00413000 role) */
    R.vp_i[2] = FL_SCREEN_W; R.vp_i[3] = FL_SCREEN_H; R.vp_f[1] = 1.f;
    for (int i = 0x16; i < 0x39; i++)
        for (int k = 0; k < 16; k++) R.matrices[i][k] = (k % 5) == 0 ? 1.f : 0.f;
    R.global_mod = 0xFFFFFFFFu;
    { float big = 10000000.f; R.fog_a = big; R.fog_b = big; } /* func_0016D460: fog off */
    fl_default_state();
    if (r_mesh_init()) return -1;
    return 0;
}

void r_shutdown(void)
{
    r_mesh_shutdown();
    for (int i = 0; i < MAX_TEX; i++)
        if (R.tex[i].used) glDeleteTextures(1, &R.tex[i].gl);
}

/* ---------------- GL state application ---------------- */
static void apply_blend_depth(void)
{
    if (R.in_overlay) {
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_DEPTH_TEST);
        return;
    }
    if (R.blend_ok) {
        glEnable(GL_BLEND);
        glBlendEquation(R.bl_eq);
        glBlendFunc(R.bl_src, R.bl_dst);
    } else {
        glDisable(GL_BLEND);
    }
    /* GS ZTE is always on; ZTST NEVER/GEQUAL/GREATER/ALWAYS with larger Z = nearer */
    glEnable(GL_DEPTH_TEST);
    switch (R.ztest) {
    case 0: glDepthFunc(GL_NEVER); break;
    case 3: glDepthFunc(GL_GREATER); break;
    case 7: glDepthFunc(GL_ALWAYS); break;
    default: glDepthFunc(GL_GEQUAL); break;
    }
    glDepthMask(R.zwrite ? GL_TRUE : GL_FALSE);
}

void r_flush(void)
{
    if (!R.nverts) return;
    glUseProgram(R.prog);
    glBindVertexArray(R.vao);
    glUniform2f(R.u_view, (float)R.view_w, (float)R.view_h);
    glUniform1i(R.u_mode, R.cur_mode);
    int linear = r_texture_filter_linear();
    int clamp = (R.state_ad0 & 0x20000) ? 1 : 0;
    glUniform1i(R.u_linear, linear);
    glUniform1i(R.u_clamp, clamp);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, R.pal_tex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, R.cur_tex);
    if (R.cur_mode == RM_RGBA) {
        GLint f = linear ? GL_LINEAR : GL_NEAREST, wr = clamp ? GL_CLAMP_TO_EDGE : GL_REPEAT;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, f);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, f);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wr);
    }
    apply_blend_depth();
    glBindBuffer(GL_ARRAY_BUFFER, R.vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, (GLsizeiptr)(sizeof(RVtx) * R.nverts), R.verts);
    glDrawArrays(GL_TRIANGLES, 0, R.nverts);
    R.draws++;
    R.frame_verts += R.nverts;
    R.nverts = 0;
}

void r_use(GLuint tex, int mode)
{
    if (!tex) tex = R.white_tex;
    if (tex != R.cur_tex || mode != R.cur_mode) {
        r_flush();
        R.cur_tex = tex;
        R.cur_mode = mode;
    }
}

RVtx *r_verts(int n)
{
    if (R.nverts + n > MAX_VERTS) r_flush();
    RVtx *v = &R.verts[R.nverts];
    R.nverts += n;
    memset(v, 0, sizeof(RVtx) * n);
    return v;
}

int r_texture_filter_linear(void) { return (R.state_ad0 & 0x10000) ? 0 : 1; }

static uint8_t gs_to_unorm(unsigned g) { unsigned v = (g * 255 + 64) / 128; return (uint8_t)(v > 255 ? 255 : v); }
static unsigned halve(unsigned t) { return t == 0xFF ? 0x80 : t ? ((t >> 1) ? (t >> 1) : 1) : 0; }

void r_color_tex(uint32_t c, uint8_t o[4])
{
    o[0] = gs_to_unorm(halve((c >> 16) & 0xFF));
    o[1] = gs_to_unorm(halve((c >> 8) & 0xFF));
    o[2] = gs_to_unorm(halve(c & 0xFF));
    o[3] = gs_to_unorm(halve(c >> 24));
}

void r_color_flat(uint32_t c, uint8_t o[4])
{
    o[0] = (uint8_t)(c >> 16);
    o[1] = (uint8_t)(c >> 8);
    o[2] = (uint8_t)c;
    o[3] = gs_to_unorm(halve(c >> 24));
}

/* GS Z = -(z - 1) * 0.5 * scale: z = -1 is nearest. NDC depth = -z gives
 * window depth (1 - z) / 2, compared with GEQUAL like the GS. */
float r_depth_of(float z)
{
    float d = -z;
    return d < -1.f ? -1.f : d > 1.f ? 1.f : d;
}
float r_snap_x(float x) { return floorf(x - (float)R.origin_x); }
float r_snap_y(float y) { return floorf(y - (float)R.origin_y); }

/* ---------------- blend: func_003E06D0 ----------------
 * Decodes exactly the src|dst combinations the GS packet builder accepts;
 * others leave the previous ALPHA register (here: GL blend) untouched. */
static void set_blend_from_state(void)
{
    uint32_t f = R.state_ad0;
    int src = f & 0xF, dst = (f >> 4) & 0xF;
    GLenum eq = GL_FUNC_ADD, sf = 0, df = 0;
    int ok = 1;
#define B(e, s, d) do { eq = (e); sf = (s); df = (d); } while (0)
    switch (src) {
    case 1: /* ONE */
        switch (dst) {
        case 1:
            if ((f & 0xC00) == 0x400) B(GL_FUNC_SUBTRACT, GL_ONE, GL_ONE);      /* Cs - Cd */
            else B(GL_FUNC_ADD, GL_ONE, GL_ONE);                                 /* Cs + Cd (0x800: undefined on PS2) */
            break;
        case 0: B(GL_FUNC_ADD, GL_ONE, GL_ZERO); break;                          /* 0xA8: Cs */
        case 2: B(GL_FUNC_ADD, GL_ONE, GL_SRC_ALPHA); break;                     /* 0x09: Cd*As + Cs */
        case 3: B(GL_FUNC_SUBTRACT, GL_ONE, GL_SRC_ALPHA); break;                /* 0x06: Cs - Cd*As (GS) */
        case 4: B(GL_FUNC_ADD, GL_ONE, GL_DST_ALPHA); break;                     /* 0x19: Cd*Ad + Cs */
        case 5: B(GL_FUNC_SUBTRACT, GL_ONE, GL_DST_ALPHA); break;                /* 0x16: Cs - Cd*Ad (GS) */
        default: ok = 0;
        }
        break;
    case 0: /* ZERO */
        switch (dst) {
        case 1: B(GL_FUNC_ADD, GL_ZERO, GL_ONE); break;
        case 0: B(GL_FUNC_ADD, GL_ZERO, GL_ZERO); break;
        case 2: B(GL_FUNC_ADD, GL_ZERO, GL_SRC_ALPHA); break;
        case 3: B(GL_FUNC_ADD, GL_ZERO, GL_ONE_MINUS_SRC_ALPHA); break;
        case 4: B(GL_FUNC_ADD, GL_ZERO, GL_DST_ALPHA); break;
        case 5: B(GL_FUNC_ADD, GL_ZERO, GL_ONE_MINUS_DST_ALPHA); break;
        default: ok = 0;
        }
        break;
    case 2: /* SRC_ALPHA */
        switch (dst) {
        case 1: B(GL_FUNC_ADD, GL_SRC_ALPHA, GL_ONE); break;                     /* 0x48 */
        case 0: B(GL_FUNC_ADD, GL_SRC_ALPHA, GL_ZERO); break;                    /* 0x88 */
        case 3: B(GL_FUNC_ADD, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); break;     /* 0x44 */
        default: ok = 0;
        }
        break;
    case 3: /* INV_SRC_ALPHA */
        switch (dst) {
        case 0: B(GL_FUNC_ADD, GL_ONE_MINUS_SRC_ALPHA, GL_ZERO); break;          /* 0x02 */
        case 2: B(GL_FUNC_ADD, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA); break;     /* 0x01 */
        default: ok = 0;
        }
        break;
    case 4: /* DST_ALPHA */
        switch (dst) {
        case 1: B(GL_FUNC_ADD, GL_DST_ALPHA, GL_ONE); break;                     /* 0x58 */
        case 0: B(GL_FUNC_ADD, GL_DST_ALPHA, GL_ZERO); break;                    /* 0x98 */
        case 5: B(GL_FUNC_ADD, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA); break;     /* 0x54 */
        default: ok = 0;
        }
        break;
    case 5: /* INV_DST_ALPHA */
        switch (dst) {
        case 0: B(GL_FUNC_ADD, GL_ONE_MINUS_DST_ALPHA, GL_ZERO); break;          /* 0x12 */
        case 4: B(GL_FUNC_ADD, GL_ONE_MINUS_DST_ALPHA, GL_DST_ALPHA); break;     /* 0x11 */
        default: ok = 0;
        }
        break;
    default: ok = 0;
    }
#undef B
    if (!ok) return;
    if (R.blend_ok && eq == R.bl_eq && sf == R.bl_src && df == R.bl_dst) return;
    r_flush();
    R.blend_ok = 1;
    R.bl_eq = eq;
    R.bl_src = sf;
    R.bl_dst = df;
}

/* ---------------- func_003DF850 ---------------- */
int fl_set_render_state(int id, uintptr_t val)
{
    uint32_t v = (uint32_t)val;
    if (id >= 0x19 && id < 0x39) {
        if (val) {
            memcpy(R.matrices[id], (const void *)val, 64);
            R.matrix_dirty |= 1u << (id - 0x19);
        } else {
            R.matrix_dirty &= ~(1u << (id - 0x19));
        }
        return 1;
    }
    if (id >= 0x39 && id < 0x59) { /* material slots, read by the mesh build (r_mesh.c) */
        if (val) memcpy(R.materials[id - 0x39], (const void *)val, 76);
        return 1;
    }
    if (id >= 0x59 && id < 0x5C) { /* lights; func_003DE530 normalises the direction */
        uint8_t *l = R.lights[id - 0x59];
        float d[3];
        if (val) memcpy(l, (const void *)val, 100);
        memcpy(d, l + 0x34, 12);
        float n = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        if (n > 0.f) { d[0] /= n; d[1] /= n; d[2] /= n; }
        memcpy(l + 0x34, d, 12);
        return 1;
    }
    switch (id) {
    case 0xE: R.material_color = v; break;
    case 0xF: R.fog_color = v; break;
    case 0x10: memcpy(&R.fog_a, &v, 4); break;
    case 0x11: memcpy(&R.fog_b, &v, 4); break;
    case 0x12: R.state_ad4 = (R.state_ad4 & 0xFFFE7FFF) | (v ? 0x8000 : 0); break;
    case 1:
        R.state_ad4 &= 0xFFFFFC7F;
        if (v == 1) R.state_ad4 |= 0x100;
        else if (v == 2) R.state_ad4 |= 0x80;
        break;
    case 2:
        R.state_ad4 &= 0xFFFFFFF3;
        if (v == 1) R.state_ad4 |= 4;
        else if (v == 2) R.state_ad4 |= 8;
        break;
    case 0xD:
        if ((R.state_ad0 & 0xC00) != v) {
            R.state_ad0 = (R.state_ad0 & 0xFFFFF3FF) | v;
            set_blend_from_state();
        }
        break;
    case 0x5D:
        if ((R.state_ad0 & 0xFF) != v) {
            R.state_ad0 = (R.state_ad0 & 0xFFFFFF00) | v;
            set_blend_from_state();
        }
        break;
    case 4: case 5: case 6: case 7:
        if (id == 4) R.cur_texture = v;
        R.tex_slots[id - 4] = v;
        break;
    case 0x14: fl_set_clear_color(v); break;
    case 0x16: memcpy(R.matrices[0x16], (const void *)val, 64); R.matrix_dirty = 0xFFFFFFFFu; break;
    case 0x17: memcpy(R.matrices[0x17], (const void *)val, 64); R.matrix_dirty = 0xFFFFFFFFu; break;
    case 0x18: /* func_003DD4E0(0x22, x, y, w, h, fa, fb): viewport matrix + scissor */
        if (val) {
            const int32_t *q = (const int32_t *)val;
            memcpy(R.vp_i, q, 16);
            memcpy(R.vp_f, q + 4, 8);
            fl_set_scissor(R.vp_i[0], R.vp_i[1], R.vp_i[2], R.vp_i[3]);
        }
        R.matrix_dirty = 0xFFFFFFFFu;
        break;
    case 0x15:
        R.state_ad4 &= 0xFFFFFFFC;
        if (v == 2) R.state_ad4 |= 2;
        break;
    case 0x5C: R.state_ad4 = (R.state_ad4 & 0xFFFFFF) | v; break;
    case 0x5F: R.state_5f = v; break;
    case 0x61: R.state_ad4 = (R.state_ad4 & 0xFFFFBFFF) | (v ? 0x4000 : 0); break;
    case 0x62:
        if (((R.state_ad0 & 0x10000) != 0) != (v == 0x10000)) r_flush();
        R.state_ad0 = (R.state_ad0 & 0xFFFEFFFF) | (v == 0x10000 ? 0x10000 : 0);
        break;
    case 0x63:
        if (((R.state_ad0 & 0x20000) != 0) != (v == 0x20000)) r_flush();
        R.state_ad0 = (R.state_ad0 & 0xFFF9FFFF) | (v == 0x20000 ? 0x20000 : 0);
        break;
    case 0x65: R.state_ad4 = (R.state_ad4 & 0xFFFDFFFF) | (v ? 0x20000 : 0); break;
    case 0x66: R.global_mod = v; break;
    case 0xC: R.state_ad4 = (R.state_ad4 & 0xFFFFFFBF) | (v == 1 ? 0x40 : 0); break;
    case 0x6C:
        if ((v == 0 || v == 1 || v == 3 || v == 7) && R.ztest != (int)v) {
            r_flush();
            R.ztest = (int)v;
        }
        /* FALLTHROUGH: the original switch has no break here, so 0x6C also
         * runs the Z-write case with the same value */
        /* fall through */
    case 0x6B:
        if (R.zwrite != (v != 0)) r_flush();
        R.zwrite = v != 0;
        break;
    default: break;
    }
    return 1;
}

/* func_003DFF80 (the getter), for the ids the mesh path and its callers use */
uintptr_t fl_get_render_state(int id)
{
    switch (id) {
    case 1:
        switch (R.state_ad4 & 0x380) { case 0x100: return 1; case 0x80: return 2; default: return 0; }
    case 0x15:
        switch (R.state_ad4 & 3) { case 0: return 1; case 2: return 2; default: return 0; }
    case 4: case 5: case 6: case 7: return R.tex_slots[id - 4];
    case 0x14: return R.clear_color;
    default:
        if (id >= 0x16 && id < 0x39) return (uintptr_t)R.matrices[id];
        if (id >= 0x39 && id < 0x59) return (uintptr_t)R.materials[id - 0x39];
        return 0;
    }
}

/* ---- accessors for r_mesh.c ---- */
const float *r_matrix(int id) { return R.matrices[id]; }
uint32_t r_state_ad0(void) { return R.state_ad0; }
uint32_t r_state_ad4(void) { return R.state_ad4; }
uint32_t r_global_mod(void) { return R.global_mod; }
uint32_t r_material_color(void) { return R.material_color; }
uint32_t r_fog_color(void) { return R.fog_color; }
void r_fog_params(float *near_10, float *far_11) { *near_10 = R.fog_a; *far_11 = R.fog_b; }
void r_viewport(int vi[4], float vf[2]) { memcpy(vi, R.vp_i, 16); memcpy(vf, R.vp_f, 8); }
const uint8_t *r_material_slot(int i) { return R.materials[i]; }
const uint8_t *r_light(int i) { return R.lights[i]; }
GLuint r_pal_texture(void) { return R.pal_tex; }
GLuint r_white_texture(void) { return R.white_tex; }
void r_count_draw(int verts) { R.draws++; R.frame_verts += verts; }
void r_apply_state(void) { apply_blend_depth(); }

void fl_default_state(void)
{
    r_flush();
    R.state_ad4 = 0x102;
    R.state_ad0 = 0x38B032;
    R.blend_ok = 0;
    set_blend_from_state();
    R.ztest = -1;
    fl_set_render_state(0x6C, 1);
    fl_set_render_state(0x62, 0);
    fl_set_scissor(0, 0, FL_SCREEN_W, FL_SCREEN_H);
}

void fl_set_scissor(int x, int y, int w, int h)
{
    if (x < 0) x = 0;
    if (x + w > FL_SCREEN_W) w = FL_SCREEN_W - x;
    if (y < 0) y = 0;
    if (y + h > FL_SCREEN_H) h = FL_SCREEN_H - y;
    if (w < 0) w = 0;
    if (h < 0) h = 0;
    r_flush();
    R.scissor[0] = x; R.scissor[1] = y; R.scissor[2] = w; R.scissor[3] = h;
    if (!R.in_overlay) glScissor(x, FL_SCREEN_H - (y + h), w, h);
}

void fl_set_clear_color(uint32_t argb) { R.clear_color = argb; }
void fl_set_origin(int x, int y) { R.origin_x = x; R.origin_y = y; }

/* ---------------- frame ---------------- */
void fl_frame_begin(void)
{
    R.last_draws = R.draws;
    R.last_verts = R.frame_verts;
    R.draws = 0;
    R.frame_verts = 0;
    glBindFramebuffer(GL_FRAMEBUFFER, R.canvas_fbo);
    glViewport(0, 0, FL_SCREEN_W, FL_SCREEN_H);
    R.view_w = FL_SCREEN_W;
    R.view_h = FL_SCREEN_H;
    glEnable(GL_SCISSOR_TEST);
    glScissor(0, 0, FL_SCREEN_W, FL_SCREEN_H);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);
    uint32_t c = R.clear_color;
    glClearColor(((c >> 16) & 0xFF) / 255.f, ((c >> 8) & 0xFF) / 255.f, (c & 0xFF) / 255.f, 1.f);
    gl_clear_depth(0.f); /* GS Z 0 = farthest */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /* func_00170D30: per-frame blend 0x32, nearest filtering */
    fl_set_render_state(0x5D, 0x32);
    fl_set_render_state(0x62, 0x10000);
    fl_set_scissor(R.scissor[0], R.scissor[1], R.scissor[2], R.scissor[3]);
}

void fl_frame_end(void) { r_flush(); }

void r_stats(int *d, int *v) { if (d) *d = R.last_draws; if (v) *v = R.last_verts; }

void r_canvas_rect(int W, int H, int mode, int *x, int *y, int *w, int *h)
{
    int k = W / FL_SCREEN_W < H / FL_SCREEN_H ? W / FL_SCREEN_W : H / FL_SCREEN_H;
    int cw, ch;
    if (mode == R_PRESENT_INTEGER && k >= 1) {
        cw = FL_SCREEN_W * k;
        ch = FL_SCREEN_H * k;
    } else {
        /* fit keeping 4:3 */
        if ((long)W * FL_SCREEN_H < (long)H * FL_SCREEN_W) { cw = W; ch = W * FL_SCREEN_H / FL_SCREEN_W; }
        else { ch = H; cw = H * FL_SCREEN_W / FL_SCREEN_H; }
    }
    *x = (W - cw) / 2;
    *y = (H - ch) / 2;
    *w = cw;
    *h = ch;
}

void r_present(int W, int H, int mode)
{
    r_flush();
    int x, y, w, h;
    r_canvas_rect(W, H, mode, &x, &y, &w, &h);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, W, H);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    int gy = H - (y + h); /* GL origin is bottom-left */
    int exact = (w % FL_SCREEN_W) == 0 && (h % FL_SCREEN_H) == 0 && w / FL_SCREEN_W == h / FL_SCREEN_H;
    glBindFramebuffer(GL_READ_FRAMEBUFFER, R.canvas_fbo);
    if (exact || mode == R_PRESENT_INTEGER) {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        glBlitFramebuffer(0, 0, FL_SCREEN_W, FL_SCREEN_H, x, gy, x + w, gy + h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    } else {
        /* sharp fit: nearest to the next integer multiple, then linear down */
        int k = (w + FL_SCREEN_W - 1) / FL_SCREEN_W;
        int kh = (h + FL_SCREEN_H - 1) / FL_SCREEN_H;
        if (kh > k) k = kh;
        if (k < 1) k = 1;
        if (!R.sharp_fbo || R.sharp_w != FL_SCREEN_W * k) {
            if (!R.sharp_fbo) { glGenFramebuffers(1, &R.sharp_fbo); glGenTextures(1, &R.sharp_tex); }
            R.sharp_w = FL_SCREEN_W * k;
            R.sharp_h = FL_SCREEN_H * k;
            glBindTexture(GL_TEXTURE_2D, R.sharp_tex);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, R.sharp_w, R.sharp_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glBindFramebuffer(GL_DRAW_FRAMEBUFFER, R.sharp_fbo);
            glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, R.sharp_tex, 0);
        }
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, R.sharp_fbo);
        glBlitFramebuffer(0, 0, FL_SCREEN_W, FL_SCREEN_H, 0, 0, R.sharp_w, R.sharp_h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
        glBindFramebuffer(GL_READ_FRAMEBUFFER, R.sharp_fbo);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        glBlitFramebuffer(0, 0, R.sharp_w, R.sharp_h, x, gy, x + w, gy + h, GL_COLOR_BUFFER_BIT, GL_LINEAR);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

int r_read_canvas(uint8_t *rgba)
{
    r_flush();
    glBindFramebuffer(GL_FRAMEBUFFER, R.canvas_fbo);
    uint8_t *tmp = (uint8_t *)malloc(FL_SCREEN_W * FL_SCREEN_H * 4);
    glReadPixels(0, 0, FL_SCREEN_W, FL_SCREEN_H, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
    for (int y = 0; y < FL_SCREEN_H; y++)
        memcpy(rgba + (size_t)y * FL_SCREEN_W * 4, tmp + (size_t)(FL_SCREEN_H - 1 - y) * FL_SCREEN_W * 4, FL_SCREEN_W * 4);
    free(tmp);
    return glGetError() == GL_NO_ERROR ? 0 : -1;
}

/* ---------------- palettes ---------------- */
int r_pal_alloc_rows(int n)
{
    if (R.pal_next_row + n > R_PAL_ROWS) return -1;
    int r = R.pal_next_row;
    R.pal_next_row += n;
    return r;
}

void r_pal_write(int row, int first, int n, const uint8_t *rgba)
{
    r_flush();
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, R.pal_tex);
    glTexSubImage2D(GL_TEXTURE_2D, 0, first, row, n, 1, GL_RGBA, GL_UNSIGNED_BYTE, rgba);
    glActiveTexture(GL_TEXTURE0);
}

uint32_t fl_pal_create(int ncolors, const uint8_t *rgba)
{
    for (int i = 0; i < MAX_PAL; i++) {
        if (R.pal[i].used) continue;
        int row = r_pal_alloc_rows(1);
        if (row < 0) return 0;
        R.pal[i].used = 1;
        R.pal[i].row = row;
        R.pal[i].ncolors = ncolors;
        if (rgba) r_pal_write(row, 0, ncolors, rgba);
        return (uint32_t)(i + 1) << 16;
    }
    return 0;
}

void fl_pal_update(uint32_t handle, int first, int n, const uint8_t *rgba)
{
    int i = (int)(handle >> 16) - 1;
    if (i < 0 || i >= MAX_PAL || !R.pal[i].used) return;
    r_pal_write(R.pal[i].row, first, n, rgba);
}

/* ---------------- textures ---------------- */
uint32_t fl_tex_create(int w, int h, int fmt, const void *pixels)
{
    for (int i = 0; i < MAX_TEX; i++) {
        if (R.tex[i].used) continue;
        TexRec *t = &R.tex[i];
        memset(t, 0, sizeof *t);
        t->used = 1;
        t->w = w;
        t->h = h;
        t->fmt = fmt;
        r_flush();
        glGenTextures(1, &t->gl);
        glBindTexture(GL_TEXTURE_2D, t->gl);
        if (fmt == FL_TEX_IDX4 || fmt == FL_TEX_IDX8)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, w, h, 0, GL_RED, GL_UNSIGNED_BYTE, pixels);
        else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBindTexture(GL_TEXTURE_2D, R.cur_tex);
        return (uint32_t)(i + 1);
    }
    return 0;
}

void fl_tex_update(uint32_t handle, int x, int y, int w, int h, const void *pixels)
{
    int i = (int)(handle & 0xFFFF) - 1;
    if (i < 0 || i >= MAX_TEX || !R.tex[i].used) return;
    TexRec *t = &R.tex[i];
    r_flush();
    glBindTexture(GL_TEXTURE_2D, t->gl);
    if (t->fmt == FL_TEX_IDX4 || t->fmt == FL_TEX_IDX8)
        glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, w, h, GL_RED, GL_UNSIGNED_BYTE, pixels);
    else
        glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glBindTexture(GL_TEXTURE_2D, R.cur_tex);
}

void fl_tex_release(uint32_t handle)
{
    int i = (int)(handle & 0xFFFF) - 1, p = (int)(handle >> 16) - 1;
    r_flush();
    if (i >= 0 && i < MAX_TEX && R.tex[i].used) {
        if (R.cur_tex == R.tex[i].gl) R.cur_tex = R.white_tex;
        glDeleteTextures(1, &R.tex[i].gl);
        R.tex[i].used = 0;
    }
    if (p >= 0 && p < MAX_PAL) R.pal[p].used = 0; /* atlas row is not reclaimed (TODO) */
}

int fl_tex_info(uint32_t handle, int *w, int *h, int *fmt)
{
    int i = (int)(handle & 0xFFFF) - 1;
    if (i < 0 || i >= MAX_TEX || !R.tex[i].used) return -1;
    if (w) *w = R.tex[i].w;
    if (h) *h = R.tex[i].h;
    if (fmt) *fmt = R.tex[i].fmt;
    return 0;
}

GLuint r_tex_gl(uint32_t handle, int *mode, int *pal_row)
{
    int i = (int)(handle & 0xFFFF) - 1, p = (int)(handle >> 16) - 1;
    if (i < 0 || i >= MAX_TEX || !R.tex[i].used) return 0;
    TexRec *t = &R.tex[i];
    int indexed = t->fmt == FL_TEX_IDX4 || t->fmt == FL_TEX_IDX8;
    *mode = indexed ? RM_INDEX : RM_RGBA;
    *pal_row = (p >= 0 && p < MAX_PAL && R.pal[p].used) ? R.pal[p].row : 0;
    return t->gl;
}

uint32_t fl_tex_load_tim2(const uint8_t *data, size_t size, int pic)
{
    Tim2Pic tp;
    if (tim2_decode(data, size, pic, &tp)) { tim2_free(&tp); return 0; }
    uint32_t h = 0;
    if (tp.index) {
        h = fl_tex_create(tp.w, tp.h, tp.image_type == 4 ? FL_TEX_IDX4 : FL_TEX_IDX8, tp.index);
        if (h) h |= fl_pal_create(tp.clut_colors ? tp.clut_colors : 16, tp.clut);
    } else {
        h = fl_tex_create(tp.w, tp.h, tp.image_type == 1 ? FL_TEX_RGBA16 : tp.image_type == 2 ? FL_TEX_RGBA24 : FL_TEX_RGBA32, tp.rgba);
    }
    tim2_free(&tp);
    return h;
}

/* ---------------- 2D primitives ---------------- */
/* The textured prims bind state 4 (D_004C2AEC); func_003DF0C0 rejects
 * handles without a VRAM record, which here means an unknown handle. */
static int bind_current(int *pal_row)
{
    int mode;
    GLuint gl = r_tex_gl(R.cur_texture, &mode, pal_row);
    if (!gl) return 0;
    r_use(gl, mode);
    return 1;
}

static void put(RVtx *o, const FlVec4 *v, const float *uv, const uint8_t c[4], int pal)
{
    o->x = r_snap_x(v->x);
    o->y = r_snap_y(v->y);
    o->z = r_depth_of(v->z);
    o->w = (v->w > 0.f) ? 1.f / v->w : 1.f; /* ST = uv * q, Q = q: perspective-correct when w = 1/q */
    if (uv) { o->u = uv[0]; o->v = uv[1]; }
    memcpy(o->c, c, 4);
    o->pal = (float)pal;
}

int fl_tri_tex(const FlTri *t)
{
    int pal;
    if (!bind_current(&pal)) return 0;
    RVtx *o = r_verts(3);
    for (int k = 0; k < 3; k++) {
        uint8_t c[4];
        r_color_tex(t->argb[k], c);
        put(&o[k], &t->v[k], t->uv[k], c, pal);
    }
    return 1;
}

int fl_tri(const FlTri *t)
{
    r_use(0, RM_FLAT);
    RVtx *o = r_verts(3);
    for (int k = 0; k < 3; k++) {
        uint8_t c[4];
        r_color_flat(t->argb[k], c);
        FlVec4 v = t->v[k];
        v.w = 1.f; /* untextured: Q is irrelevant */
        put(&o[k], &v, NULL, c, 0);
    }
    return 1;
}

int fl_sprite_tex(const FlSprite *s)
{
    int pal;
    if (!bind_current(&pal)) return 0;
    uint8_t c[4];
    r_color_tex(s->argb, c);
    /* GS SPRITE: corners (x0,y0)-(x1,y1), Z from the second vertex */
    FlVec4 a = s->v[0], b = s->v[1];
    a.z = b.z;
    /* RGBAQ is written once, so both corners share Q = v0.w while the second
     * ST is uv1 * v1.w: the effective second UV is uv1 * w1 / w0. */
    float k = (a.w != 0.f) ? b.w / a.w : 1.f;
    float uv0[2] = { s->uv[0][0], s->uv[0][1] }, uv1[2] = { s->uv[1][0] * k, s->uv[1][1] * k };
    FlVec4 tr = { b.x, a.y, b.z, 1.f }, bl = { a.x, b.y, b.z, 1.f };
    float uv_tr[2] = { uv1[0], uv0[1] }, uv_bl[2] = { uv0[0], uv1[1] };
    RVtx *o = r_verts(6);
    put(&o[0], &a, uv0, c, pal);
    put(&o[1], &tr, uv_tr, c, pal);
    put(&o[2], &b, uv1, c, pal);
    put(&o[3], &a, uv0, c, pal);
    put(&o[4], &b, uv1, c, pal);
    put(&o[5], &bl, uv_bl, c, pal);
    for (int k = 0; k < 6; k++) o[k].w = 1.f; /* sprites are affine on the GS */
    return 1;
}

int fl_quad_tex(const FlQuad *q)
{
    int pal;
    if (!bind_current(&pal)) return 0;
    const FlVec4 *v[4] = { &q->t[0].v[0], &q->t[0].v[1], &q->t[0].v[2], &q->t[1].v[2] };
    const float *uv[4] = { q->t[0].uv[0], q->t[0].uv[1], q->t[0].uv[2], q->t[1].uv[2] };
    uint32_t col[4] = { q->t[0].argb[0], q->t[0].argb[1], q->t[0].argb[2], q->t[1].argb[2] };
    static const int strip[6] = { 0, 1, 2, 1, 3, 2 }; /* XYZ2,XYZ2,XYZ3,XYZ3 kicks = strip */
    RVtx *o = r_verts(6);
    for (int k = 0; k < 6; k++) {
        uint8_t c[4];
        r_color_tex(col[strip[k]], c);
        put(&o[k], v[strip[k]], uv[strip[k]], c, pal);
    }
    return 1;
}

int fl_fill_screen(int mode, uint32_t c)
{
    /* func_003ED1C0: SPRITE over the whole screen at Z = 0 (farthest), ZTST ALWAYS.
     * mode 0: ATST NOTEQUAL with A = 0 and AFAIL = ZB_ONLY -> only Z is written.
     * mode 1: ATST ALWAYS -> colour (A = 0) and Z. Scissor still applies. */
    if (mode != 0 && mode != 1) return 0;
    r_flush();
    glDepthMask(GL_TRUE);
    gl_clear_depth(0.f);
    if (mode == 1) {
        glClearColor(((c >> 16) & 0xFF) / 255.f, ((c >> 8) & 0xFF) / 255.f, (c & 0xFF) / 255.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    } else {
        glClear(GL_DEPTH_BUFFER_BIT);
    }
    return 0; /* the original returns 0 */
}

/* ---------------- overlay (window pixels, default framebuffer) ---------------- */
void r_overlay_begin(int w, int h)
{
    r_flush();
    R.in_overlay = 1;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, w, h);
    glDisable(GL_SCISSOR_TEST);
    R.view_w = w;
    R.view_h = h;
    r_use(0, RM_FLAT);
}

static void ov_tri(float x0, float y0, float x1, float y1, float x2, float y2, uint32_t argb)
{
    RVtx *o = r_verts(3);
    float xs[3] = { x0, x1, x2 }, ys[3] = { y0, y1, y2 };
    for (int k = 0; k < 3; k++) {
        o[k].x = xs[k]; o[k].y = ys[k]; o[k].z = 0; o[k].w = 1;
        o[k].c[0] = (uint8_t)(argb >> 16); o[k].c[1] = (uint8_t)(argb >> 8);
        o[k].c[2] = (uint8_t)argb; o[k].c[3] = (uint8_t)(argb >> 24);
    }
}

void r_overlay_disc(float cx, float cy, float r, uint32_t argb)
{
    r_use(0, RM_FLAT);
    const int n = 32;
    for (int i = 0; i < n; i++) {
        float a0 = 6.2831853f * i / n, a1 = 6.2831853f * (i + 1) / n;
        ov_tri(cx, cy, cx + r * cosf(a0), cy + r * sinf(a0), cx + r * cosf(a1), cy + r * sinf(a1), argb);
    }
}

void r_overlay_ring(float cx, float cy, float r, float wd, uint32_t argb)
{
    r_use(0, RM_FLAT);
    const int n = 40;
    float ri = r - wd;
    for (int i = 0; i < n; i++) {
        float a0 = 6.2831853f * i / n, a1 = 6.2831853f * (i + 1) / n;
        float c0 = cosf(a0), s0 = sinf(a0), c1 = cosf(a1), s1 = sinf(a1);
        ov_tri(cx + r * c0, cy + r * s0, cx + r * c1, cy + r * s1, cx + ri * c0, cy + ri * s0, argb);
        ov_tri(cx + ri * c0, cy + ri * s0, cx + r * c1, cy + r * s1, cx + ri * c1, cy + ri * s1, argb);
    }
}

void r_overlay_rect(float x, float y, float w, float h, uint32_t argb)
{
    r_use(0, RM_FLAT);
    ov_tri(x, y, x + w, y, x + w, y + h, argb);
    ov_tri(x, y, x + w, y + h, x, y + h, argb);
}

void r_overlay_end(void)
{
    r_flush();
    R.in_overlay = 0;
}
