/* GL ES 3 / WebGL2 implementation of the MvC2 in-house render library ("fl"),
 * at its API level (see port/docs/RENDER_PATH.md and port/docs/RENDERER.md).
 *
 * Coordinates: the game's 640x480 virtual space (the PS2 Y halving is dropped,
 * the picture is rendered at full height into a 640x480 canvas FBO and scaled
 * to the window at present time).
 *
 * Handles: textures are 1-based in the low 16 bits, palettes 1-based in the
 * high 16 bits, exactly as the game passes them to render state 4.
 */
#ifndef PORT_RENDER_H
#define PORT_RENDER_H
#include <stddef.h>
#include <stdint.h>

#define FL_SCREEN_W 640
#define FL_SCREEN_H 480

/* ---- 2D vertex inputs, byte-compatible with the game's structs ---- */
typedef struct FlVec4 { float x, y, z, w; } FlVec4;
/* func_003DF0C0 / func_003DEE00: 3 x (x,y,z,w) @0x00, ARGB x3 @0x30, (u,v) x3 @0x3C. */
typedef struct FlTri { FlVec4 v[3]; uint32_t argb[3]; float uv[3][2]; } FlTri;
/* func_003DF490: 2 x (x,y,z,w) @0x00, ARGB @0x20, (u,v) x2 @0x24. */
typedef struct FlSprite { FlVec4 v[2]; uint32_t argb; float uv[2][2]; } FlSprite;
/* func_00420BF0: two FlTri back to back; the strip is t[0].v0..v2 + t[1].v[2]. */
typedef struct FlQuad { FlTri t[2]; } FlQuad;

/* ---- lifetime / frame ---- */
int r_init(void);                 /* after the GL context exists */
void r_shutdown(void);
void fl_frame_begin(void);        /* func_00170D30 role: bind canvas, clear, blend 0x32 + nearest */
void fl_frame_end(void);          /* flush pending batches (func_00170D70 role) */
enum { R_PRESENT_INTEGER = 0, R_PRESENT_SHARP_FIT = 1 };
void r_present(int win_w, int win_h, int mode); /* func_003ECD00 role: canvas -> window */
void r_canvas_rect(int win_w, int win_h, int mode, int *x, int *y, int *w, int *h);
/* Read the 640x480 canvas as top-down RGBA8. */
int r_read_canvas(uint8_t *rgba);
void r_stats(int *draw_calls, int *verts); /* last frame */

/* ---- render state: func_003DF850(id, value) ---- */
int fl_set_render_state(int id, uintptr_t value);
void fl_default_state(void);                    /* func_003DF7D0 */
void fl_set_scissor(int x, int y, int w, int h);/* func_003E00D0 (640x480 space) */
void fl_set_clear_color(uint32_t argb);         /* func_003E00B0 / state 0x14 */
void fl_set_origin(int x, int y);               /* scroll origin D_0062BF8C / D_0062BF90 */

/* ---- 2D primitives (return 1 when drawn, 0 when rejected like the original) ---- */
int fl_tri_tex(const FlTri *t);       /* func_003DF0C0 textured gouraud triangle */
int fl_tri(const FlTri *t);           /* func_003DEE00 untextured gouraud triangle */
int fl_sprite_tex(const FlSprite *s); /* func_003DF490 textured sprite */
int fl_fill_screen(int mode, uint32_t argb); /* func_003ED1C0: 0 = Z only, 1 = colour + Z */
int fl_quad_tex(const FlQuad *q);     /* func_00420BF0 textured quad (batch writer) */

/* ---- textures / palettes ---- */
enum { FL_TEX_IDX4 = 0, FL_TEX_IDX8 = 1, FL_TEX_RGBA16 = 2, FL_TEX_RGBA24 = 3, FL_TEX_RGBA32 = 4 };
/* pixels: IDX4/IDX8 = one index byte per pixel; RGBA* = RGBA8 (already converted). */
uint32_t fl_tex_create(int w, int h, int fmt, const void *pixels);
void fl_tex_update(uint32_t handle, int x, int y, int w, int h, const void *pixels);
/* rgba: n colours as R,G,B,A bytes (A 0..255, 255 = opaque). Returns handle<<16. */
uint32_t fl_pal_create(int ncolors, const uint8_t *rgba);
void fl_pal_update(uint32_t handle, int first, int n, const uint8_t *rgba);
void fl_tex_release(uint32_t handle);   /* releases both halves present */
int fl_tex_info(uint32_t handle, int *w, int *h, int *fmt);
/* func_00418200: TIM2 picture `pic` -> (palette<<16)|texture, 0 on error. */
uint32_t fl_tex_load_tim2(const uint8_t *data, size_t size, int pic);

/* ---- character sprites: func_00411C10 / func_00412260 ---- */
typedef struct FlCharBank FlCharBank;
/* bank = section 0 of PLxxPAK.BIN (must stay valid while the bank lives). */
FlCharBank *fl_char_bank_create(const uint8_t *bank, size_t size);
void fl_char_bank_destroy(FlCharBank *b);
int fl_char_frame_count(const FlCharBank *b);
int fl_char_tile_count(const FlCharBank *b);
/* Copy bank palette src (0..47) into slot palette dst (0..15), as colour select does. */
void fl_char_load_palette(FlCharBank *b, int dst, int src);
/* Overwrite slot palette dst with 16 ARGB1555 colours (palette animation). */
void fl_char_set_palette_1555(FlCharBank *b, int dst, const uint16_t *argb1555);
/* Draw frame: m = row-major 4x4 (VU0 layout, translation m[12..14]) mapping
 * bank pixels (origin = feet, y down) to 640x480 space; argb 0xFFFFFFFF = identity. */
int fl_char_draw(FlCharBank *b, int frame, const float m[16], uint32_t argb, int palette);
/* Bounds of a frame in bank pixels (for tools). */
int fl_char_frame_bounds(FlCharBank *b, int frame, int *x0, int *y0, int *x1, int *y1);

/* ---- 3D meshes: the VU1 path (func_00415590, func_003EE6F0, func_003F0500, func_001538B0) ----
 * POL packs (STGxxPOL, DMxxPOL, EFKYPOL ...) are converted to GL vertex/index
 * buffers at load time and drawn with one uber-shader whose feature flags come
 * from the format word the game builds (D_004C2AD4 at build time). */
typedef struct FlModel FlModel;
typedef struct FlModelLoad {
    const uint32_t *tex; /* tex[i] = handle of TEX-pack record i (D_0057FB70[D_0057ED70[slot + i]]) */
    int ntex;
    int b34;             /* D_004C2B34: bit 2 lets func_00415A00 enable fog (stage loads set 4) */
    int b30;             /* D_004C2B30: lets func_00415A00 pick the clipping programs (stage loads set 1) */
    int keep_state;      /* 1: skip func_00415A00 and the state-1 dance and build every mesh with the
                          * current format word (the bare func_003EE6F0 path; e.g. 0x102 -> desc 0, lit) */
} FlModelLoad;
/* func_00415320 + func_00415590 (+ func_003EE6F0 per mesh). The buffer is read
 * only and may be freed afterwards. Uses and changes render states 1, 0xC, 0x12,
 * 0x15, 0x1A, 0x39.., 0x61, 0x65 exactly as the original does; set states 1 and 2
 * to 0 first for a stage (func_00170170). */
FlModel *fl_model_load(const uint8_t *pol, size_t size, const FlModelLoad *ld);
void fl_model_destroy(FlModel *m);
int fl_model_roots(const FlModel *m);
int fl_model_meshes(const FlModel *m);
/* flags = POL per-mesh draw flags, fmt = format word, desc = VU1 descriptor index (-1 = none) */
int fl_model_mesh_info(const FlModel *m, int mesh, uint32_t *flags, uint32_t *fmt, int *desc);
/* World bounds of a root tree under an identity object matrix; returns its drawable mesh count. */
int fl_model_root_bounds(const FlModel *m, int root, float bmin[3], float bmax[3]);
/* func_00152180 + func_001538B0: draw root tree `root` with object matrix objm,
 * object flags (o+0xD0) and UV scroll (o+0xE0/E4). Set 0x66 first (func_00152400). */
int fl_model_draw(FlModel *m, int root, const float objm[16], uint32_t obj_flags, float uv_u, float uv_v);
/* func_003F0500: one mesh with matrix slot 0x19 as its world matrix and the
 * current view (0x16), projection (0x17), viewport (0x18), 0x66, 0x1A, fog, blend. */
int fl_mesh_draw(FlModel *m, int mesh);
/* fl_get_render_state: func_003DFF80 for ids 1, 0x15, 4..7, 0x14, matrices, materials */
uintptr_t fl_get_render_state(int id);

/* VU0 matrix maths (row-major, v' = v * M, translation in m[12..14]) */
void fl_mat_identity(float m[16]);                                        /* func_003DD260 */
void fl_mat_mul(float out[16], const float a[16], const float b[16]);     /* func_003DE160: a * b */
void fl_mat_look_at(float m[16], const float eye[3], const float at[3], const float up[3]); /* func_003DDF20 */
void fl_mat_perspective(float m[16], float far_plane, float near_plane, float fov_rad, float aspect); /* func_003DD360 */
/* The camera object D_004F1F40 as func_00413F50 reads it. */
typedef struct FlCamera {
    float eye[3];   /* +0x0C */
    float at[3];    /* +0x54 */
    float target_dy;/* +0x80 (-0.41): target.y -= 240 * n * target_dy */
    int roll;       /* +0x84 */
    float fov_deg;  /* +0x6C, horizontal over 640 px */
} FlCamera;
void fl_camera_battle_default(FlCamera *c);          /* func_00122DA0 */
/* func_00413F50(cam, far, n): states 0x17 (func_003DD2E0), 0x18 (viewport, y - 16) and 0x16.
 * vx/vy = the D_004F8020 shake offset (0 normally). Battle: far 120000, n = 1. */
void fl_camera_apply(const FlCamera *c, float far_plane, int n, int vx, int vy);

/* ---- window-space overlay (touch pad, debug) ---- */
void r_overlay_begin(int win_w, int win_h);
void r_overlay_disc(float cx, float cy, float r, uint32_t argb);
void r_overlay_ring(float cx, float cy, float r, float width, uint32_t argb);
void r_overlay_rect(float x, float y, float w, float h, uint32_t argb);
void r_overlay_end(void);

/* ---- asset helpers (decoders shared with the tools) ---- */
/* LZ16 (func_00176230). Returns malloc'd buffer. */
uint8_t *lz16_decode(const uint8_t *src, size_t src_size, size_t *out_size);
/* Byte LZ for sprite tiles (func_00413A80). dst must have out_len + 18 bytes. Returns bytes consumed. */
size_t lz8_decode(const uint8_t *src, size_t src_size, uint8_t *dst, size_t out_len);
/* TEX pack: 16-byte records {s16 w, u16 h, u32 flags, u32 offset, s32 attr}. */
typedef struct FlTexRecord { int w, h; uint32_t flags, offset; int32_t attr; } FlTexRecord;
int texpack_records(const uint8_t *pack, size_t size, FlTexRecord *out, int max);
/* Raw TEX pack (LZ16 or plain) -> decoded pack (malloc'd; may be src copy). */
uint8_t *texpack_decode(const uint8_t *raw, size_t size, size_t *out_size);

#endif
