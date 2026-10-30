/* 3D mesh path: the VU1 microcode path of the render library, replaced by
 * GL buffers built at load time and one uber-shader.
 *
 *   func_00415320 + func_00415590  -> fl_model_load   (POL pack: materials, meshes, node trees)
 *   func_003EE6F0 / func_003E0F60  -> build_mesh      (format word + VU1 descriptor selection)
 *   func_003F0500 + setup callback -> fl_mesh_draw    (uniforms = the VU1 constant block)
 *   func_00152180 / func_001538B0 /
 *   func_001537D0                  -> fl_model_draw   (node walk, per-mesh blend and UV scroll)
 *   func_00413F50 / func_003DD2E0 /
 *   func_003DD5D0 / func_003DDF20  -> fl_camera_apply (battle camera)
 *
 * The POL format and the derivation of every step are in
 * port/docs/ASSET_FORMATS.md section 6 and port/docs/MESH_NOTES.md; the Python
 * reference decoder/rasteriser is port/tools/convert/mesh.py.
 *
 * Colour maths (GS units, 0x80 = 1.0), as the microcode computes it:
 *   vertex colour programs (format bit 1 clear, unlit):
 *       c = ftoi0(byte * 0.5 * mod)           (descs 11, 15, 35, 43, 45 ...)
 *   material colour programs (format bit 1 set, unlit):
 *       c.rgb = ftoi0(min(diffuse * 128, 128) * mod), c.a = ftoi0(diffuse.a * 128 * mod.a)
 *   lit programs (format 0x100, desc 0 family):
 *       c.rgb = min(128, sum_i min(128, 128 * diffuse * light_i) * max(0, n . l_i)
 *                        + min(128, (128 * ambient + stateE) * c0)), c.a = ftoi0(128 * diffuse.a)
 *   then GS MODULATE: out = tex * c / 128 (untextured: c.rgb / 255, c.a / 128),
 *   FOG: out = mix(fogcol, out, F / 255), F = clamp((far - w) / (far - near) * 255),
 *   ALPHA from state 0x5D, TEST alpha != 0, Z GEQUAL/GREATER (larger = nearer).
 * mod = state 0x66 / 255 when the format has 0x20000, else 1.
 */
#include "r_internal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------- VU0 matrix maths (row-major, v' = v * M) ---------------- */
void fl_mat_identity(float m[16])
{
    for (int i = 0; i < 16; i++) m[i] = (i % 5) == 0 ? 1.f : 0.f;
}

void fl_mat_mul(float out[16], const float a[16], const float b[16])
{
    float r[16];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i * 4 + j] = a[i * 4 + 0] * b[0 * 4 + j] + a[i * 4 + 1] * b[1 * 4 + j] +
                           a[i * 4 + 2] * b[2 * 4 + j] + a[i * 4 + 3] * b[3 * 4 + j];
    memcpy(out, r, sizeof r);
}

static void v3norm(float v[3])
{
    float n = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (n > 0.f) { v[0] /= n; v[1] /= n; v[2] /= n; }
}

void fl_mat_look_at(float d[16], const float e[3], const float at[3], const float up[3])
{
    /* func_003DDF20: C = -(at - eye), X = up x C, Y = C x X */
    float C[3] = { -(at[0] - e[0]), -(at[1] - e[1]), -(at[2] - e[2]) }, B[3] = { up[0], up[1], up[2] };
    v3norm(C);
    v3norm(B);
    float X[3] = { B[1] * C[2] - B[2] * C[1], B[2] * C[0] - B[0] * C[2], B[0] * C[1] - B[1] * C[0] };
    v3norm(X);
    float Y[3] = { C[1] * X[2] - C[2] * X[1], C[2] * X[0] - C[0] * X[2], C[0] * X[1] - C[1] * X[0] };
    d[0] = X[0]; d[4] = X[1]; d[8] = X[2];
    d[1] = Y[0]; d[5] = Y[1]; d[9] = Y[2];
    d[2] = C[0]; d[6] = C[1]; d[10] = C[2];
    d[3] = d[7] = d[11] = 0.f;
    d[15] = 1.f;
    d[12] = -(e[0] * X[0] + e[1] * X[1] + e[2] * X[2]);
    d[13] = -(e[0] * Y[0] + e[1] * Y[1] + e[2] * Y[2]);
    d[14] = -(e[0] * C[0] + e[1] * C[1] + e[2] * C[2]);
}

void fl_mat_perspective(float m[16], float far_plane, float near_plane, float fov, float aspect)
{
    /* func_003DD360 */
    fov *= 0.5f;
    float cot = cosf(fov) / sinf(fov);
    fl_mat_identity(m);
    m[0] = cot / aspect;
    m[5] = cot;
    m[10] = -(far_plane + near_plane) / (far_plane - near_plane);
    m[11] = -1.f;
    m[14] = -(2.f * far_plane * near_plane) / (far_plane - near_plane);
    m[15] = 0.f;
}

/* func_00122DA0: initial battle camera */
void fl_camera_battle_default(FlCamera *c)
{
    memset(c, 0, sizeof *c);
    c->eye[1] = 95.f;
    c->eye[2] = 320.f / tanf(0xF4A * 6.283185307f / 65536.f); /* func_004175C0(0xF4A): tan(21.5 deg) */
    c->at[1] = 95.f;
    c->fov_deg = 43.f;
    c->target_dy = -0.41f;
}

/* func_00413F50(cam, far, n) with the viewport template D_004F8020 = {vx, vy, 640, 480, 0, 1} */
void fl_camera_apply(const FlCamera *c, float far_plane, int n, int vx, int vy)
{
    float a[3] = { c->eye[0], c->eye[1], c->eye[2] };
    float b[3] = { c->at[0], c->at[1] - 240.f * ((float)n * c->target_dy), c->at[2] };
    /* the roll term as the decomp computes it; roll 0 gives up = (0, 1, 0) */
    double ang = 6.283185307179586 * (double)(int)((unsigned)(c->roll / 2) & 0xFFFF) / 65536.0;
    float C = cosf((float)ang), S = sinf((float)ang), ky = 1.f, kz = 1.f, w = 1.f;
    float X1 = w * C - ky * kz - kz * ky - ky * S;
    float Y = (ky * S + (X1 * ky + kz * ky)) - ky * kz;
    float Z = (ky * kz + (ky * X1 + Y * ky)) - Y * S;
    float up[3] = { 0.f, 1.f, (Y * ky + (X1 * S + Y * S)) - Z * ky };
    struct { int32_t x, y, w, h; float fa, fb; } vp = { vx, vy - 16, 640, 0x1E0, 0.f, 1.f };
    float t = tanf((float)(3.141592653589793 * ((double)(c->fov_deg / 2.f) / 180.0)));
    t = atanf(240.f / (320.f / t));
    t = 2.f * t;
    float proj[16], view[16];
    fl_mat_perspective(proj, far_plane, 1.f, t, 1.f); /* func_003DD2E0(0x20, far, 1, t, 1) */
    fl_set_render_state(0x17, (uintptr_t)proj);
    fl_set_render_state(0x18, (uintptr_t)&vp);
    fl_mat_look_at(view, a, b, up);
    fl_set_render_state(0x16, (uintptr_t)view);
}

/* ---------------- model data ---------------- */
typedef struct MVtx { float pos[3], nrm[3]; uint8_t col[4]; float uv[2]; } MVtx; /* 36 bytes */

typedef struct MRange {
    int first, count;       /* in indices */
    uint32_t tex;           /* material texture handle (mat + 0x44) */
    float diffuse[4], c0[4];/* mat + 0x04, mat + 0x24 */
} MRange;

typedef struct MMesh {
    uint32_t flags;         /* POL off[2][i] */
    uint32_t fmt, key;      /* D_004C2AD4 at build, w4 | w8 */
    int desc;               /* VU1 descriptor table index (D_004779F0), -1 = not drawable */
    int textured;
    GLuint vao, vbo, ibo;
    int nverts, nidx;
    float bmin[3], bmax[3]; /* vertex bounds (tools) */
    MRange *range;
    int nrange;
} MMesh;

typedef struct MNode { int child, sibling, mesh; float local[16]; } MNode;

struct FlModel {
    MMesh *mesh; int nmesh;
    MNode *node; int nnode;
    int *root; int nroot;
};

static struct {
    GLuint prog;
    GLint u_mvp, u_vp, u_vpz, u_flags, u_cscale, u_mod, u_matcol, u_uv0, u_uv1, u_uv3, u_fog,
        u_fogcol, u_ldir, u_lcol, u_lamb, u_mode, u_linear, u_clamp, u_tex, u_pal, u_palrow;
    int ok;
} M;

enum { MF_VCOL = 1, MF_MATCOL = 2, MF_LIT = 4, MF_UVX = 8, MF_FOG = 16, MF_TEX = 32 };

static const char *k_mvs =
    "in vec3 a_pos;\n"
    "in vec3 a_nrm;\n"
    "in vec4 a_col;   /* raw colour bytes 0..255 */\n"
    "in vec2 a_uv;\n"
    "uniform mat4 u_mvp;      /* world * view * projection (VU1 vf1..vf4 without the viewport) */\n"
    "uniform vec4 u_vp;       /* viewport to canvas NDC: x*ax + w*bx, y*ay + w*by */\n"
    "uniform float u_vpz;     /* -(fb - fa) */\n"
    "uniform int u_flags;\n"
    "uniform vec4 u_cscale;   /* vertex colour byte -> GS units (0.5 textured) */\n"
    "uniform vec4 u_mod;      /* 0x66 / 255, or 1 */\n"
    "uniform vec4 u_matcol;   /* material colour, GS units, final */\n"
    "uniform vec4 u_uv0, u_uv1, u_uv3; /* matrix slot 0x1A rows 0, 1, 3 */\n"
    "uniform vec2 u_fog;      /* far (0x11), 1 / (far - near) */\n"
    "uniform vec3 u_ldir[3];  /* model-space directions to the lights */\n"
    "uniform vec4 u_lcol[3];  /* min(128, 128 * diffuse * light colour) */\n"
    "uniform vec4 u_lamb;     /* min(128, (ambient + 0xE) * c0); w = alpha */\n"
    "out vec2 v_uv;\n"
    "out vec4 v_colw;   /* colour * w and fog * w: the GS interpolates RGBA and F linearly in */\n"
    "out float v_fogw;  /* screen space (only STQ is perspective-correct); GLSL ES 3.00 has */\n"
    "out float v_w;     /* no noperspective, so divide by the perspective-interpolated w */\n"
    "void main() {\n"
    "  vec4 c = u_mvp * vec4(a_pos, 1.0);\n"
    "  gl_Position = vec4(c.x * u_vp.x + c.w * u_vp.y, c.y * u_vp.z + c.w * u_vp.w, c.z * u_vpz, c.w);\n"
    "  vec4 col;\n"
    "  if ((u_flags & 4) != 0) {\n"
    "    vec3 d = max(vec3(dot(a_nrm, u_ldir[0]), dot(a_nrm, u_ldir[1]), dot(a_nrm, u_ldir[2])), 0.0);\n"
    "    col.rgb = min(u_lcol[0].rgb * d.x + u_lcol[1].rgb * d.y + u_lcol[2].rgb * d.z + u_lamb.rgb, 128.0);\n"
    "    col = floor(vec4(col.rgb, u_lamb.a) * u_mod);\n"
    "  } else if ((u_flags & 2) != 0) {\n"
    "    col = u_matcol;\n"
    "  } else {\n"
    "    col = floor(a_col * u_cscale * u_mod);\n"
    "  }\n"
    "  v_colw = col * c.w;\n"
    "  v_w = c.w;\n"
    "  v_uv = ((u_flags & 8) != 0) ? (u_uv0.xy * a_uv.x + u_uv1.xy * a_uv.y + u_uv3.xy) : a_uv;\n"
    "  v_fogw = (((u_flags & 16) != 0) ? clamp((u_fog.x - c.w) * u_fog.y * 255.0, 0.0, 255.0) : 255.0) * c.w;\n"
    "}\n";

static const char *k_mfs =
    "uniform int u_flags;\n"
    "uniform int u_mode;      /* 1 rgba texture, 2 index texture + palette atlas */\n"
    "uniform int u_linear;\n"
    "uniform int u_clamp;\n"
    "uniform float u_palrow;\n"
    "uniform vec3 u_fogcol;\n"
    "uniform sampler2D u_tex;\n"
    "uniform sampler2D u_pal;\n"
    "in vec2 v_uv;\n"
    "in vec4 v_colw;\n"
    "in float v_fogw;\n"
    "in float v_w;\n"
    "out vec4 o_col;\n"
    "vec4 lut(ivec2 t, ivec2 sz) {\n"
    "  if (u_clamp == 1) t = clamp(t, ivec2(0), sz - 1);\n"
    "  else t = ((t % sz) + sz) % sz;\n"
    "  int i = int(texelFetch(u_tex, t, 0).r * 255.0 + 0.5);\n"
    "  return texelFetch(u_pal, ivec2(i, int(u_palrow)), 0);\n"
    "}\n"
    "void main() {\n"
    "  vec4 v_col = v_colw / v_w;\n"
    "  float v_fog = v_fogw / v_w;\n"
    "  vec4 c;\n"
    "  if ((u_flags & 32) != 0) {\n"
    "    vec4 t;\n"
    "    if (u_mode == 2) {\n"
    "      ivec2 sz = textureSize(u_tex, 0);\n"
    "      vec2 p = v_uv * vec2(sz);\n"
    "      if (u_linear == 0) t = lut(ivec2(floor(p)), sz);\n"
    "      else {\n"
    "        p -= 0.5; ivec2 i0 = ivec2(floor(p)); vec2 f = fract(p);\n"
    "        t = mix(mix(lut(i0, sz), lut(i0 + ivec2(1, 0), sz), f.x),\n"
    "                mix(lut(i0 + ivec2(0, 1), sz), lut(i0 + ivec2(1, 1), sz), f.x), f.y);\n"
    "      }\n"
    "    } else {\n"
    "      t = texture(u_tex, v_uv);\n"
    "    }\n"
    "    c = t * v_col / 128.0;      /* GS MODULATE; texture alpha 1.0 = GS 0x80 */\n"
    "  } else {\n"
    "    c = vec4(v_col.rgb / 255.0, v_col.a / 128.0);\n"
    "  }\n"
    "  c = min(c, vec4(1.0, 1.0, 1.0, 255.0 / 128.0));\n"
    "  if (c.a * 128.0 < 1.0) discard;  /* GS TEST alpha != 0 */\n"
    "  float f = v_fog / 255.0;\n"
    "  c.rgb = mix(u_fogcol, c.rgb, f);\n"
    "  o_col = c;\n"
    "}\n";

static GLuint mcompile(GLenum type, const char *body)
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
        fprintf(stderr, "mesh shader compile failed:\n%s\n", log);
        return 0;
    }
    return s;
}

int r_mesh_init(void)
{
    memset(&M, 0, sizeof M);
    GLuint vs = mcompile(GL_VERTEX_SHADER, k_mvs), fs = mcompile(GL_FRAGMENT_SHADER, k_mfs);
    if (!vs || !fs) return -1;
    M.prog = glCreateProgram();
    glAttachShader(M.prog, vs);
    glAttachShader(M.prog, fs);
    glBindAttribLocation(M.prog, 0, "a_pos");
    glBindAttribLocation(M.prog, 1, "a_nrm");
    glBindAttribLocation(M.prog, 2, "a_col");
    glBindAttribLocation(M.prog, 3, "a_uv");
    glLinkProgram(M.prog);
    GLint ok = 0;
    glGetProgramiv(M.prog, GL_LINK_STATUS, &ok);
    glDeleteShader(vs);
    glDeleteShader(fs);
    if (!ok) {
        char log[2048];
        glGetProgramInfoLog(M.prog, sizeof log, NULL, log);
        fprintf(stderr, "mesh link failed:\n%s\n", log);
        return -1;
    }
#define U(n) M.n = glGetUniformLocation(M.prog, #n)
    U(u_mvp); U(u_vp); U(u_vpz); U(u_flags); U(u_cscale); U(u_mod); U(u_matcol); U(u_uv0); U(u_uv1);
    U(u_uv3); U(u_fog); U(u_fogcol); U(u_ldir); U(u_lcol); U(u_lamb); U(u_mode); U(u_linear);
    U(u_clamp); U(u_tex); U(u_pal); U(u_palrow);
#undef U
    glUseProgram(M.prog);
    glUniform1i(M.u_tex, 0);
    glUniform1i(M.u_pal, 1);
    M.ok = 1;
    return 0;
}

void r_mesh_shutdown(void)
{
    if (M.prog) glDeleteProgram(M.prog);
    M.ok = 0;
}

/* ---------------- func_003E0F60: format word + vertex key -> descriptor table index ---------------- */
static int desc_select(uint32_t w, uint32_t key)
{
    uint32_t top = w & 0xFF000000u, low = w & 0xFFFFFFu;
    int tex = key == 0x21035 || key == 0x421035, untex = key == 0x21025 || key == 0x421025,
        ext = key == 0x521235 || key == 0x121235;
    if (top == 0x01000000u) return key == 0x21025 ? 47 : -1;
    if (top == 0x06000000u) return ext ? 48 : -1;
    if (top != 0) return -1;
    switch (low) {
    case 0x102: return tex ? 0 : ext ? 1 : untex ? 2 : -1;
    case 0x20102: return tex ? 3 : untex ? 4 : -1;
    case 0x106: return tex ? 5 : ext ? 6 : -1;
    case 0x100: return tex ? 7 : untex ? 8 : -1;
    case 0x20100: return tex ? 9 : untex ? 10 : -1;
    case 0x0: return tex ? 11 : untex ? 12 : -1;
    case 0x2: return tex ? 13 : untex ? 14 : -1;
    case 0x20000: return tex ? 15 : untex ? 16 : -1;
    case 0x20002: return tex ? 17 : untex ? 18 : -1;
    }
    if (!tex) return -1;
    switch (low) {
    case 0x142: return 19;
    case 0x8102: return 20;
    case 0x28102: return 21;
    case 0x8100: return 22;
    case 0x8000: return 23;
    case 0x8002: return 24;
    case 0x28100: return 25;
    case 0x28000: return 26;
    case 0x28002: return 27;
    case 0x4102: return 28;
    case 0x24102: return 29;
    case 0x4100: return 30;
    case 0x24100: return 31;
    case 0x4002: return 32;
    case 0x24002: return 33;
    case 0x4000: return 34;
    case 0x24000: return 35;
    case 0xC102: return 36;
    case 0x2C102: return 37;
    case 0xC100: return 38;
    case 0x2C100: return 39;
    case 0xC002: return 40;
    case 0x2C002: return 41;
    case 0xC000: return 42;
    case 0x2C000: return 43; /* SET(44, 43) */
    case 0x28040: return 44;
    case 0x2C040: return 45;
    case 0x2C140: return 46;
    }
    return -1;
}

/* ---------------- POL parsing (see mesh.py for the same in Python) ---------------- */
typedef struct Pol { const uint8_t *d; size_t n; } Pol;

static uint32_t rd(const Pol *p, size_t o) { return o + 4 <= p->n ? (uint32_t)p->d[o] | p->d[o + 1] << 8 | p->d[o + 2] << 16 | (uint32_t)p->d[o + 3] << 24 : 0; }
static float rdf(const Pol *p, size_t o) { uint32_t u = rd(p, o); float f; memcpy(&f, &u, 4); return f; }

/* func_003F1F10 / func_003F1F90: first child chunk whose type matches (mask test or equality) */
static size_t chunk_nth(const Pol *p, size_t base, int n)
{
    size_t o = base + 12;
    uint32_t cnt = rd(p, base + 4);
    for (uint32_t i = 0; i < cnt; i++) {
        if ((int)i == n) return o;
        uint32_t sz = rd(p, o + 8);
        if (sz < 12 || o + sz > p->n) return 0;
        o += sz;
    }
    return 0;
}
static size_t chunk_find(const Pol *p, size_t base, uint32_t type, int by_mask)
{
    size_t o = base + 12;
    uint32_t cnt = rd(p, base + 4);
    for (uint32_t i = 0; i < cnt && o + 12 <= p->n; i++) {
        uint32_t t = rd(p, o);
        if (by_mask ? (t & type) != 0 : t == type) return o;
        uint32_t sz = rd(p, o + 8);
        if (sz < 12) return 0;
        o += sz;
    }
    return 0;
}

/* func_00119098: float -> unsigned with truncation (negative -> 0, >= 2^32 -> ~0) */
static uint32_t f2u(float f)
{
    if (!(f >= 1.f)) return 0;
    if (f >= 4294967296.f) return 0xFFFFFFFFu;
    return (uint32_t)f;
}

/* func_003DEAF0: node local matrix = scale, rotate X, Y, Z (func_003F3BE0), translate */
static void node_local(float m[16], const float sc[3], const float rot[3], const float tr[3])
{
    fl_mat_identity(m);
    m[0] = sc[0]; m[5] = sc[1]; m[10] = sc[2];
    for (int axis = 0; axis < 3; axis++) {
        float a = rot[axis];
        if (a == 0.f) continue;
        float c = cosf(a), s = sinf(a), r[16];
        fl_mat_identity(r);
        if (a == 3.1415927410125732f) { c = -1.f; s = 0.f; }
        if (axis == 0) { r[5] = c; r[6] = s; r[9] = -s; r[10] = c; }
        else if (axis == 1) { r[0] = c; r[2] = -s; r[8] = s; r[10] = c; }
        else { r[0] = c; r[1] = s; r[4] = -s; r[5] = c; }
        fl_mat_mul(m, m, r);
    }
    m[12] = tr[0]; m[13] = tr[1]; m[14] = tr[2];
}

/* func_003F1C10 + func_00415320: one 76-byte material slot */
static void make_material(const Pol *p, size_t rec, const FlModelLoad *ld, size_t tex_container, uint8_t out[76])
{
    size_t s = rec + 12;
    float f[13];
    for (int i = 0; i < 13; i++) f[i] = rdf(p, s + 4 * i);
    memset(out, 0, 76);
    memcpy(out + 0x04, &f[4], 16);   /* o->f4..f10  = s->f10..f1C (diffuse) */
    memcpy(out + 0x14, &f[8], 16);   /* o->f14..f20 = s->f20..f2C */
    memcpy(out + 0x24, &f[0], 16);   /* o->f24..f30 = s->f0..fC */
    uint32_t power = f2u(f[12]);
    memcpy(out + 0x48, &power, 4);
    uint32_t handle = 0;
    if (rd(p, s + 0x34) && tex_container) {
        size_t t = chunk_nth(p, tex_container, (int)rd(p, s + 0x100));
        if (t) {
            uint32_t id = rd(p, t + 12); /* func_003F1D10 -> u32 texture id = TEX record index */
            if ((int)id < ld->ntex) handle = ld->tex[id];
        }
    }
    memcpy(out + 0x44, &handle, 4);
}

static void build_mesh(FlModel *mdl, int mi, const Pol *p, size_t mo)
{
    MMesh *me = &mdl->mesh[mi];
    uint32_t type = rd(p, mo);
    uint32_t attr = type & 0xFFC3FF00u;
    me->desc = -1;
    if ((type & 0xFF) != 2 || (attr != 0xDF00 && attr != 0x9F00)) return; /* func_003F2B70 cases */
    size_t ss = chunk_find(p, mo, 0x100, 0), sm = chunk_find(p, mo, 0x400, 0), sp = chunk_find(p, mo, 0x800, 0),
           sn = chunk_find(p, mo, 0x1000, 0), su = chunk_find(p, mo, 0x4000, 0), sc = chunk_find(p, mo, 0x8000, 0);
    if (!ss || !sp) return;
    int nstrip = (int)rd(p, ss + 4), nv = (int)rd(p, sp + 4);
    if (nstrip <= 0 || nstrip > (1 << 20) || nv <= 0 || nv > (1 << 20)) return;
    int kind = attr == 0xDF00 ? 0x35 : 0x25;
    /* func_003F3700: per-strip materials only when they differ */
    int multi = 0;
    if (sm) {
        uint32_t first = rd(p, sm + 12);
        for (int i = 1; i < nstrip; i++) if (rd(p, sm + 12 + 4 * i) != first) multi = 1;
    }
    me->key = 0x21000u | (multi ? 0x400000u : 0) | (uint32_t)kind;
    me->fmt = r_state_ad4();
    me->desc = desc_select(me->fmt, me->key);
    me->textured = kind == 0x35;
    if (me->desc < 0) {
        fprintf(stderr, "mesh %d: format %#x key %#x has no VU1 descriptor (not drawn, as on the PS2)\n", mi, me->fmt, me->key);
        return;
    }
    /* vertices */
    MVtx *v = (MVtx *)calloc((size_t)nv, sizeof *v);
    for (int i = 0; i < nv; i++) {
        for (int k = 0; k < 3; k++) v[i].pos[k] = rdf(p, sp + 12 + 12 * i + 4 * k);
        if (sn && i < (int)rd(p, sn + 4)) for (int k = 0; k < 3; k++) v[i].nrm[k] = rdf(p, sn + 12 + 12 * i + 4 * k);
        if (su && i < (int)rd(p, su + 4)) for (int k = 0; k < 2; k++) v[i].uv[k] = rdf(p, su + 12 + 8 * i + 4 * k);
        if (sc && i < (int)rd(p, sc + 4)) {
            /* func_003F2EB0 packs (A<<24)|(R<<16)|(G<<8)|B without masking, func_003EEC30 unpacks bytes */
            uint32_t r = f2u(rdf(p, sc + 12 + 16 * i)), g = f2u(rdf(p, sc + 16 + 16 * i)),
                     b = f2u(rdf(p, sc + 20 + 16 * i)), a = f2u(rdf(p, sc + 24 + 16 * i));
            uint32_t argb = (a << 24) | (r << 16) | (g << 8) | b;
            v[i].col[0] = (uint8_t)(argb >> 16); v[i].col[1] = (uint8_t)(argb >> 8);
            v[i].col[2] = (uint8_t)argb; v[i].col[3] = (uint8_t)(argb >> 24);
        }
    }
    /* strips -> triangle list, ranges of consecutive strips with the same material slot */
    size_t cap = 0, nidx = 0;
    for (int s = 0, o = (int)ss + 12; s < nstrip; s++) {
        uint32_t n = rd(p, (size_t)o) & 0x7FFFFFFFu;
        if ((size_t)o + 4 + 4 * (size_t)n > p->n) { nstrip = s; break; }
        if (n >= 3) cap += 3 * (n - 2);
        o += 4 + 4 * (int)n;
    }
    uint32_t *idx = (uint32_t *)malloc((cap ? cap : 1) * sizeof *idx);
    me->range = (MRange *)calloc((size_t)nstrip + 1, sizeof *me->range);
    int cur = -1;
    size_t o = ss + 12;
    for (int s = 0; s < nstrip; s++) {
        uint32_t n = rd(p, o) & 0x7FFFFFFFu;
        int slot = multi ? (int)rd(p, sm + 12 + 4 * s) : 0;
        if (slot != cur) {
            MRange *r = &me->range[me->nrange++];
            r->first = (int)nidx;
            /* func_003EFA40: the material packet is built from the slot contents at build time */
            const uint8_t *mat = r_material_slot(slot & 31);
            memcpy(r->diffuse, mat + 0x04, 16);
            memcpy(r->c0, mat + 0x24, 16);
            memcpy(&r->tex, mat + 0x44, 4);
            cur = slot;
        }
        for (uint32_t j = 0; j + 2 < n; j++) {
            uint32_t a = rd(p, o + 4 + 4 * j), b = rd(p, o + 8 + 4 * j), c = rd(p, o + 12 + 4 * j);
            if (a == b || b == c || a == c) continue;           /* zero area: the GS draws nothing */
            if ((int)a >= nv || (int)b >= nv || (int)c >= nv) continue;
            idx[nidx++] = a; idx[nidx++] = b; idx[nidx++] = c;    /* no culling on the GS: winding is irrelevant */
        }
        me->range[me->nrange - 1].count = (int)nidx - me->range[me->nrange - 1].first;
        o += 4 + 4 * n;
    }
    me->nverts = nv;
    me->nidx = (int)nidx;
    for (int k = 0; k < 3; k++) { me->bmin[k] = 1e30f; me->bmax[k] = -1e30f; }
    for (int i = 0; i < nv; i++)
        for (int k = 0; k < 3; k++) {
            if (v[i].pos[k] < me->bmin[k]) me->bmin[k] = v[i].pos[k];
            if (v[i].pos[k] > me->bmax[k]) me->bmax[k] = v[i].pos[k];
        }
    glGenVertexArrays(1, &me->vao);
    glBindVertexArray(me->vao);
    glGenBuffers(1, &me->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, me->vbo);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(sizeof(MVtx) * (size_t)nv), v, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MVtx), (void *)offsetof(MVtx, pos));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MVtx), (void *)offsetof(MVtx, nrm));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(MVtx), (void *)offsetof(MVtx, col));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(MVtx), (void *)offsetof(MVtx, uv));
    glGenBuffers(1, &me->ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, me->ibo);
    if (nv <= 65536) {
        uint16_t *i16 = (uint16_t *)malloc((nidx ? nidx : 1) * sizeof *i16);
        for (size_t k = 0; k < nidx; k++) i16[k] = (uint16_t)idx[k];
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(nidx * sizeof *i16), i16, GL_STATIC_DRAW);
        free(i16);
    } else {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(nidx * sizeof *idx), idx, GL_STATIC_DRAW);
        me->nverts = -nv; /* marks 32-bit indices */
    }
    glBindVertexArray(0);
    free(idx);
    free(v);
}

FlModel *fl_model_load(const uint8_t *data, size_t size, const FlModelLoad *ld)
{
    Pol P = { data, size }, *p = &P;
    static const FlModelLoad none = { 0 };
    if (!ld) ld = &none;
    if (size < 12 || !M.ok) return NULL;
    size_t off0 = rd(p, 0), off1 = rd(p, 4), off2 = rd(p, 8);
    if (off0 + 12 > size || off1 + 12 > size || off2 > size) return NULL;
    size_t cm = chunk_find(p, off0, 1, 1), cmat = chunk_find(p, off0, 2, 1), ctex = chunk_find(p, off0, 4, 1);
    if (!cm) return NULL;
    FlModel *mdl = (FlModel *)calloc(1, sizeof *mdl);
    mdl->nmesh = (int)rd(p, cm + 4);
    mdl->mesh = (MMesh *)calloc((size_t)(mdl->nmesh ? mdl->nmesh : 1), sizeof *mdl->mesh);
    int nmat = cmat ? (int)rd(p, cmat + 4) : 0;
    uint8_t(*mats)[76] = (uint8_t(*)[76])calloc((size_t)(nmat ? nmat : 1), 76);
    for (int i = 0; i < nmat; i++) {
        size_t r = chunk_nth(p, cmat, i);
        if (r) make_material(p, r, ld, ctex, mats[i]);
    }
    r_flush();
    /* func_00415590: per mesh, func_00415A00(flags), material slots 0x39 + j, and the
     * state 1 dance (vertex-colour meshes are built unlit), then func_003EE6F0 */
    for (int i = 0; i < mdl->nmesh; i++) {
        MMesh *me = &mdl->mesh[i];
        size_t mo = chunk_nth(p, cm, i);
        me->flags = off2 + 4 * (size_t)i + 4 <= size ? rd(p, off2 + 4 * (size_t)i) : 0;
        me->desc = -1;
        if (!mo) continue;
        uint32_t fl = me->flags;
        if (!ld->keep_state) {
            int a = (fl & 1) ? 1 : 2, b = (fl & 2) ? 1 : 0, v = 0, r = 0;
            float ident[16];
            fl_mat_identity(ident);
            fl_set_render_state(0x65, 1);
            fl_set_render_state(0x15, (uintptr_t)a);
            fl_set_render_state(0x61, (uintptr_t)b);
            fl_set_render_state(0x1A, (uintptr_t)ident);
            if (ld->b34 & 4) {
                if (fl & 4) v = 0x8000;
                if (b == 0) v = 0;
            }
            fl_set_render_state(0x12, (uintptr_t)v);
            if (ld->b30 && a == 1 && b == 1) {
                r = 1;
                fl_set_render_state(0x12, 0x8000);
            }
            fl_set_render_state(0xC, (uintptr_t)r);
        }
        size_t ml = chunk_find(p, mo, 0x200, 0);
        int nml = ml && (rd(p, mo) & 0xFF) == 2 ? (int)rd(p, ml + 4) : 0;
        for (int j = 0; j < nml && j < 32; j++) {
            uint32_t mi = rd(p, ml + 12 + 4 * (size_t)j);
            if ((int)mi < nmat) fl_set_render_state(0x39 + j, (uintptr_t)mats[mi]);
        }
        uintptr_t s0 = ld->keep_state ? 0 : fl_get_render_state(1);
        if (s0 && fl_get_render_state(0x15) == 1) fl_set_render_state(1, 0);
        build_mesh(mdl, i, p, mo);
        if (s0) fl_set_render_state(1, s0);
    }
    free(mats);
    /* node trees (func_003F1730 / func_003DE890): type-0 chunk = root list */
    size_t n1 = off1;
    uint32_t nch = rd(p, n1 + 4);
    mdl->node = (MNode *)calloc(nch ? nch : 1, sizeof *mdl->node);
    size_t o = n1 + 12;
    for (uint32_t i = 0; i < nch && o + 12 <= size; i++) {
        uint32_t t = rd(p, o), cnt = rd(p, o + 4), sz = rd(p, o + 8);
        if (t == 0) {
            mdl->root = (int *)calloc(cnt ? cnt : 1, sizeof(int));
            for (uint32_t k = 0; k < cnt; k++) mdl->root[k] = (int)rd(p, o + 12 + 4 * k);
            mdl->nroot = (int)cnt;
        } else {
            MNode *nd = &mdl->node[mdl->nnode++];
            size_t b = o + 12;
            float sc[3], rot[3], tr[3];
            for (int k = 0; k < 3; k++) { sc[k] = rdf(p, b + 0x10 + 4 * k); rot[k] = rdf(p, b + 0x20 + 4 * k); tr[k] = rdf(p, b + 0x30 + 4 * k); }
            node_local(nd->local, sc, rot, tr);
            nd->child = (int32_t)rd(p, b + 8);
            nd->sibling = (int32_t)rd(p, b + 0xC);
            uint32_t mesh = rd(p, b + 0x40) & 0xFFFF;
            nd->mesh = mesh == 0xFFFF ? -1 : (int)mesh;
        }
        if (sz < 12) break;
        o += sz;
    }
    return mdl;
}

/* ---------------- Port J: meshes built per game "clay" handle ----------------
 * The game builds its meshes itself (func_00415590 -> func_003F2A50 ->
 * func_003F2B70 -> func_003EE6F0, one clay handle per POL mesh chunk) and
 * draws them one by one (func_003F0500).  These keep one GL mesh per clay
 * handle, built from the same POL mesh chunk with the format word current
 * at build time, and draw it with the current render state. */
#define MAX_CLAY 0x402
static FlModel CLAY;

static void clay_free(int h)
{
    MMesh *me = &CLAY.mesh[h];
    if (me->vao) glDeleteVertexArrays(1, &me->vao);
    if (me->vbo) glDeleteBuffers(1, &me->vbo);
    if (me->ibo) glDeleteBuffers(1, &me->ibo);
    free(me->range);
    memset(me, 0, sizeof *me);
    me->desc = -1;
}

int fl_clay_build(int h, const uint8_t *chunk, size_t avail, uint32_t draw_flags)
{
    Pol P = { chunk, avail };
    if (!M.ok || h <= 0 || h >= MAX_CLAY || !chunk) return 0;
    if (!CLAY.mesh) {
        CLAY.mesh = (MMesh *)calloc(MAX_CLAY, sizeof *CLAY.mesh);
        CLAY.nmesh = MAX_CLAY;
    }
    r_flush();
    clay_free(h);
    CLAY.mesh[h].flags = draw_flags;
    build_mesh(&CLAY, h, &P, 0);
    return CLAY.mesh[h].desc >= 0;
}

/* the material texture handles a clay's ranges draw with (to sync them) */
int fl_clay_textures(int h, uint32_t *out, int max)
{
    int n = 0;
    if (!CLAY.mesh || h <= 0 || h >= MAX_CLAY || CLAY.mesh[h].desc < 0) return 0;
    for (int r = 0; r < CLAY.mesh[h].nrange && n < max; r++)
        if (CLAY.mesh[h].range[r].tex) out[n++] = CLAY.mesh[h].range[r].tex;
    return n;
}

uint32_t fl_clay_fmt(int h)
{
    return (CLAY.mesh && h > 0 && h < MAX_CLAY) ? CLAY.mesh[h].fmt : 0;
}

int fl_clay_draw(int h)
{
    if (!CLAY.mesh || h <= 0 || h >= MAX_CLAY || CLAY.mesh[h].desc < 0) return 0;
    return fl_mesh_draw(&CLAY, h);
}

void fl_clay_release(int h)
{
    if (CLAY.mesh && h > 0 && h < MAX_CLAY) {
        r_flush();
        clay_free(h);
    }
}

void fl_model_destroy(FlModel *m)
{
    if (!m) return;
    r_flush();
    for (int i = 0; i < m->nmesh; i++) {
        MMesh *me = &m->mesh[i];
        if (me->vao) glDeleteVertexArrays(1, &me->vao);
        if (me->vbo) glDeleteBuffers(1, &me->vbo);
        if (me->ibo) glDeleteBuffers(1, &me->ibo);
        free(me->range);
    }
    free(m->mesh);
    free(m->node);
    free(m->root);
    free(m);
}

int fl_model_roots(const FlModel *m) { return m ? m->nroot : 0; }
int fl_model_meshes(const FlModel *m) { return m ? m->nmesh : 0; }

int fl_model_mesh_info(const FlModel *m, int i, uint32_t *flags, uint32_t *fmt, int *desc)
{
    if (!m || i < 0 || i >= m->nmesh) return -1;
    if (flags) *flags = m->mesh[i].flags;
    if (fmt) *fmt = m->mesh[i].fmt;
    if (desc) *desc = m->mesh[i].desc;
    return 0;
}

/* World-space bounds of a root tree drawn with an identity object matrix
 * (same walk as fl_model_draw). Returns the number of drawable meshes. */
int fl_model_root_bounds(const FlModel *mdl, int root, float bmin[3], float bmax[3])
{
    for (int k = 0; k < 3; k++) { bmin[k] = 1e30f; bmax[k] = -1e30f; }
    if (!mdl || root < 0 || root >= mdl->nroot) return 0;
    float buf[16], parent[16], q[16];
    fl_mat_identity(q);
    memcpy(parent, q, sizeof parent);
    int n = mdl->root[root], first = 1, cnt = 0, guard = 0;
    while (n >= 0 && n < mdl->nnode && guard++ < 100000) {
        const MNode *nd = &mdl->node[n];
        if (first) { memcpy(buf, parent, sizeof buf); first = 0; }
        else fl_mat_mul(buf, nd->local, parent);
        if (nd->mesh >= 0 && nd->mesh < mdl->nmesh && mdl->mesh[nd->mesh].desc >= 0 && mdl->mesh[nd->mesh].nidx) {
            const MMesh *me = &mdl->mesh[nd->mesh];
            for (int c = 0; c < 8; c++) {
                float p[3] = { (c & 1) ? me->bmax[0] : me->bmin[0], (c & 2) ? me->bmax[1] : me->bmin[1], (c & 4) ? me->bmax[2] : me->bmin[2] };
                for (int k = 0; k < 3; k++) {
                    float w = p[0] * buf[k] + p[1] * buf[4 + k] + p[2] * buf[8 + k] + buf[12 + k];
                    if (w < bmin[k]) bmin[k] = w;
                    if (w > bmax[k]) bmax[k] = w;
                }
            }
            cnt++;
        }
        if (nd->child >= 0) { n = nd->child; memcpy(parent, buf, sizeof parent); }
        else { n = nd->sibling; if (n < 0) break; memcpy(parent, q, sizeof parent); }
    }
    return cnt;
}

/* ---------------- func_003F0500 ---------------- */
static float gsf(uint32_t c, int sh) { return (float)((c >> sh) & 0xFF); }

int fl_mesh_draw(FlModel *mdl, int i)
{
    if (!mdl || i < 0 || i >= mdl->nmesh || !M.ok) return 0;
    MMesh *me = &mdl->mesh[i];
    if (me->desc < 0 || !me->nidx) return 0;
    r_flush(); /* keep the order with the 2D batches */
    if (r_discarding()) return 1; /* frame skip (r_set_discard): the logic ran, nothing is drawn */
    uint32_t fmt = me->fmt;
    int lit = (fmt & 0x100) != 0, matcol = (fmt & 2) != 0, mod = (fmt & 0x20000) != 0;
    int flags = (lit ? 4 : matcol ? 2 : 1) | ((fmt & 0x4000) ? 8 : 0) |
                ((fmt & 0x18000) == 0x8000 ? 16 : 0) | (me->textured ? 32 : 0);
    /* constant block: world * view * (projection [* viewport]) */
    float wv[16], mvp[16];
    fl_mat_mul(wv, r_matrix(0x19), r_matrix(0x16));
    fl_mat_mul(mvp, wv, r_matrix(0x17));
    int vi[4];
    float vf[2];
    r_viewport(vi, vf);
    /* func_003DD5D0 in 640x480 space: x = ndc.x * (w/2) / 1.333333 + x0 + w/2, y = -ndc.y * h/2 + y0 + h/2 */
    float hw = (float)(vi[2] / 2), hh = (float)((vi[3] / 2) / 2) * 2.f;
    float ax = hw / 1.3333330154418945f / (FL_SCREEN_W / 2.f), bx = ((float)vi[0] + hw) / (FL_SCREEN_W / 2.f) - 1.f;
    float ay = hh / (FL_SCREEN_H / 2.f), by = 1.f - ((float)vi[1] + hh) / (FL_SCREEN_H / 2.f);
    glUseProgram(M.prog);
    glUniformMatrix4fv(M.u_mvp, 1, GL_FALSE, mvp);
    {
        float vp[4] = { ax, bx, ay, by };
        glUniform4fv(M.u_vp, 1, vp);
    }
    glUniform1f(M.u_vpz, -(vf[1] - vf[0]));
    uint32_t g = r_global_mod();
    float modv[4] = { 1.f, 1.f, 1.f, 1.f };
    if (mod) { modv[0] = gsf(g, 16) / 255.f; modv[1] = gsf(g, 8) / 255.f; modv[2] = gsf(g, 0) / 255.f; modv[3] = gsf(g, 24) / 255.f; }
    glUniform4fv(M.u_mod, 1, modv);
    float cs[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
    if (!me->textured) cs[0] = cs[1] = cs[2] = 1.f; /* func_003EEC30 kind 0x25: rgb not halved */
    glUniform4fv(M.u_cscale, 1, cs);
    const float *u1a = r_matrix(0x1A);
    glUniform4fv(M.u_uv0, 1, u1a + 0);
    glUniform4fv(M.u_uv1, 1, u1a + 4);
    glUniform4fv(M.u_uv3, 1, u1a + 12);
    float fn, ff;
    r_fog_params(&fn, &ff);
    float fog[2] = { ff, (ff - fn) != 0.f ? 1.f / (ff - fn) : 1e30f };
    glUniform2fv(M.u_fog, 1, fog);
    uint32_t fc = r_fog_color();
    float fogc[3] = { gsf(fc, 16) / 255.f, gsf(fc, 8) / 255.f, gsf(fc, 0) / 255.f };
    glUniform3fv(M.u_fogcol, 1, fogc);
    glUniform1i(M.u_flags, flags);
    /* lights (func_003E1B20): model-space directions to the lights */
    float ldir[9], lamb_base[3];
    if (lit) {
        float w[16];
        memcpy(w, r_matrix(0x19), sizeof w);
        for (int k = 0; k < 3; k++) {
            const uint8_t *l = r_light(k);
            float d[3], o3[3];
            memcpy(d, l + 0x34, 12);
            d[0] = -d[0]; d[1] = -d[1]; d[2] = -d[2];
            /* m2 * transpose(world rotation): o = d * W^T  ->  o_j = sum_k d_k W[j][k] */
            for (int j = 0; j < 3; j++) o3[j] = d[0] * w[j * 4 + 0] + d[1] * w[j * 4 + 1] + d[2] * w[j * 4 + 2];
            v3norm(o3);
            memcpy(ldir + 3 * k, o3, 12);
        }
        uint32_t e = r_material_color();
        const uint8_t *l0 = r_light(0), *l1 = r_light(1), *l2 = r_light(2);
        for (int k = 0; k < 3; k++) {
            float a0, a1, a2;
            memcpy(&a0, l0 + 0x24 + 4 * k, 4); memcpy(&a1, l1 + 0x24 + 4 * k, 4); memcpy(&a2, l2 + 0x24 + 4 * k, 4);
            lamb_base[k] = 128.f * (a2 + (a0 + a1)) + gsf(e, 16 - 8 * k) / 255.f * 128.f;
        }
        glUniform3fv(M.u_ldir, 3, ldir);
    }
    /* texture state at draw time (func_003EFF10 -> func_003F0070 with D_004C2AD0) */
    int linear = (r_state_ad0() & 0x10000) ? 0 : 1, clamp = (r_state_ad0() & 0x20000) ? 1 : 0;
    glUniform1i(M.u_linear, linear);
    glUniform1i(M.u_clamp, clamp);
    r_apply_state();
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, r_pal_texture());
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(me->vao);
    GLenum it = me->nverts < 0 ? GL_UNSIGNED_INT : GL_UNSIGNED_SHORT;
    size_t isz = me->nverts < 0 ? 4 : 2;
    for (int r = 0; r < me->nrange; r++) {
        MRange *rg = &me->range[r];
        if (!rg->count) continue;
        int mode = RM_RGBA, palrow = 0;
        GLuint tex = 0;
        if (me->textured && rg->tex) tex = r_tex_gl(rg->tex, &mode, &palrow);
        if (!tex) { tex = r_white_texture(); mode = RM_RGBA; }
        glBindTexture(GL_TEXTURE_2D, tex);
        if (mode == RM_RGBA) {
            GLint f = linear ? GL_LINEAR : GL_NEAREST, wr = clamp ? GL_CLAMP_TO_EDGE : GL_REPEAT;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, f);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, f);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wr);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wr);
        }
        glUniform1i(M.u_mode, mode);
        glUniform1f(M.u_palrow, (float)palrow);
        /* material colour packet (func_003EFA40 case 0 + microcode): rgb clamped to 128 */
        float mc[4];
        for (int k = 0; k < 3; k++) mc[k] = floorf(fminf(rg->diffuse[k] * 128.f, 128.f) * modv[k]);
        mc[3] = floorf(rg->diffuse[3] * 128.f * modv[3]);
        glUniform4fv(M.u_matcol, 1, mc);
        if (lit) {
            float lc[12], la[4];
            for (int k = 0; k < 3; k++) {
                const uint8_t *l = r_light(k);
                for (int c = 0; c < 3; c++) {
                    float lcol;
                    memcpy(&lcol, l + 0x04 + 4 * c, 4);
                    lc[4 * k + c] = fminf(128.f, 128.f * rg->diffuse[c] * lcol);
                }
                lc[4 * k + 3] = 0.f;
            }
            for (int c = 0; c < 3; c++) la[c] = fminf(128.f, lamb_base[c] * rg->c0[c]);
            la[3] = floorf(128.f * rg->diffuse[3]);
            glUniform4fv(M.u_lcol, 3, lc);
            glUniform4fv(M.u_lamb, 1, la);
        }
        glDrawElements(GL_TRIANGLES, rg->count, it, (void *)(uintptr_t)((size_t)rg->first * isz));
        r_count_draw(rg->count);
    }
    glBindVertexArray(0);
    return 1;
}

/* ---------------- func_00152180 / func_001538B0 / func_001537D0 ---------------- */
static const uint32_t k_blend_src[8] = { 0, 1, 0, 0, 2, 0x30, 0x40, 0x50 };  /* D_00444880 */
static const uint32_t k_blend_dst[8] = { 0, 0x10, 0, 0, 2, 0x30, 0x40, 0x50 }; /* D_004448A0 */

static void blend_select(int a, int b)
{
    /* func_00153A40 */
    fl_set_render_state(0xD, 0);
    fl_set_render_state(0x5D, k_blend_src[a & 7] | k_blend_dst[b & 7]);
}

int fl_model_draw(FlModel *mdl, int root, const float objm[16], uint32_t obj_flags, float uv_u, float uv_v)
{
    if (!mdl || root < 0 || root >= mdl->nroot) return 0;
    if (obj_flags & 0x2000) return 0;
    if (obj_flags & 0x200000) fl_set_render_state(0x6C, 7);
    if (obj_flags & 0x800000) fl_set_render_state(0x6B, 0);
    if (obj_flags & 0x400000) fl_set_render_state(0x63, 0x20000);
    float buf[16], parent[16], q[16];
    memcpy(q, objm, sizeof q);
    memcpy(parent, objm, sizeof parent);
    int n = mdl->root[root], first = 1, drawn = 0, guard = 0;
    while (n >= 0 && n < mdl->nnode && guard++ < 100000) {
        MNode *nd = &mdl->node[n];
        if (first) { memcpy(buf, parent, sizeof buf); first = 0; }
        else fl_mat_mul(buf, nd->local, parent);
        fl_set_render_state(0x19, (uintptr_t)buf);
        int k = nd->mesh;
        if (k >= 0 && k < mdl->nmesh && mdl->mesh[k].desc >= 0) {
            uint32_t mf = mdl->mesh[k].flags, c = r_global_mod();
            if (mf & 0x200) fl_set_render_state(0x66, ((((c >> 24) & 0xFF) >> 1) << 24) | (c & 0xFFFFFF));
            /* func_001537D0 */
            if (mf & 0x100) blend_select((int)((mf >> 16) & 7), (int)((mf >> 19) & 7));
            else blend_select(1, 0);
            if (mf & 2) {
                float m[16];
                fl_mat_identity(m);
                if (obj_flags & 0x20000) { m[12] = uv_u; m[13] = uv_v; }
                fl_set_render_state(0x1A, (uintptr_t)m);
            }
            drawn += fl_mesh_draw(mdl, k);
            if (mf & 0x200) fl_set_render_state(0x66, c);
        }
        if (nd->child >= 0) {
            n = nd->child;
            memcpy(parent, buf, sizeof parent);
        } else {
            n = nd->sibling;
            if (n < 0) break;
            memcpy(parent, q, sizeof parent);
        }
    }
    if (obj_flags & 0x200000) fl_set_render_state(0x6C, 1);
    if (obj_flags & 0x800000) fl_set_render_state(0x6B, 1);
    if (obj_flags & 0x400000) fl_set_render_state(0x63, 0);
    return drawn;
}
