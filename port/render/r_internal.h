/* Shared between the renderer translation units. */
#ifndef PORT_R_INTERNAL_H
#define PORT_R_INTERNAL_H
#include "../platform/gl.h"
#include "render.h"

typedef struct RVtx {
    float x, y, z, w;   /* x,y in view pixels; z = NDC depth; w = 1/q (perspective ST) */
    float u, v;
    uint8_t c[4];       /* RGBA modulate, 255 = GS 0x80 (identity) */
    float pal;          /* palette atlas row for indexed textures */
} RVtx;

enum { RM_FLAT = 0, RM_RGBA = 1, RM_INDEX = 2 };

/* Select texture/mode for the next vertices (flushes on change). */
void r_use(GLuint tex, int mode);
/* Reserve n vertices in the current batch. */
RVtx *r_verts(int n);
void r_flush(void);
void r_canvas_bind(void);            /* canvas FBO + viewport + pending flip clear; marks it drawn */
/* GS colour conversions (func_003E0CB0): textured = all channels halved,
 * untextured = alpha only; output in the 255 = 1.0 convention. */
void r_color_tex(uint32_t argb, uint8_t out[4]);
void r_color_flat(uint32_t argb, uint8_t out[4]);
/* Palette atlas row allocation. */
int r_pal_alloc_rows(int nrows);
void r_pal_write(int row, int first, int n, const uint8_t *rgba);
GLuint r_tex_gl(uint32_t handle, int *mode, int *pal_row);
int r_texture_filter_linear(void);
int r_discarding(void);              /* r_set_discard: drop draws this step */
float r_depth_of(float z);           /* game z in [-1, 1] -> NDC depth */
float r_snap_x(float x);              /* origin + integer truncation, as fptosi does */
float r_snap_y(float y);

#define R_PAL_ROWS 1024

/* ---- state the mesh path (r_mesh.c) reads from r_gl.c ---- */
const float *r_matrix(int id);          /* 0x16 view, 0x17 projection, 0x19.. slots (row-major, v' = v * M) */
uint32_t r_state_ad0(void);             /* D_004C2AD0 */
uint32_t r_state_ad4(void);             /* D_004C2AD4 */
uint32_t r_global_mod(void);            /* 0x66, D_004C2ABC */
uint32_t r_material_color(void);        /* 0xE, D_004C2AC0 */
uint32_t r_fog_color(void);             /* 0xF */
void r_fog_params(float *near_10, float *far_11); /* 0x10 / 0x11 */
void r_viewport(int vi[4], float vf[2]);/* 0x18 */
const uint8_t *r_material_slot(int i);  /* 0x39 + i, 76 bytes */
const uint8_t *r_light(int i);          /* 0x59 + i, 100 bytes */
GLuint r_pal_texture(void);
GLuint r_white_texture(void);
void r_count_draw(int verts);
void r_apply_state(void);               /* blend + depth from the fl state */
int r_mesh_init(void);
void r_mesh_shutdown(void);
#endif
