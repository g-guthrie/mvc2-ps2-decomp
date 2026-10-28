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
/* GS colour conversions (func_003E0CB0): textured = all channels halved,
 * untextured = alpha only; output in the 255 = 1.0 convention. */
void r_color_tex(uint32_t argb, uint8_t out[4]);
void r_color_flat(uint32_t argb, uint8_t out[4]);
/* Palette atlas row allocation. */
int r_pal_alloc_rows(int nrows);
void r_pal_write(int row, int first, int n, const uint8_t *rgba);
GLuint r_tex_gl(uint32_t handle, int *mode, int *pal_row);
int r_texture_filter_linear(void);
float r_depth_of(float z);           /* game z in [-1, 1] -> NDC depth */
float r_snap_x(float x);              /* origin + integer truncation, as fptosi does */
float r_snap_y(float y);

#define R_PAL_ROWS 1024
#endif
