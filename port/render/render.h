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
