/* Character sprite path: func_00411C10 (slot setup) and func_00412260 (draw),
 * re-implemented on an index-texture atlas + the palette atlas.
 * Bank layout and placement: port/docs/ASSET_FORMATS.md section 2, chars.py. */
#include "r_internal.h"
#include "decode.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PAGE 1024
#define MAX_PAGES 16

typedef struct CharTile {
    int16_t page;       /* -1 = not decoded yet */
    uint16_t x, y;
    uint8_t fw8, fh8, w8, h8;
} CharTile;

struct FlCharBank {
    const uint8_t *d;
    size_t n;
    uint32_t tile_tab, frame_tab, pal_off;
    int n_tiles, n_frames, n_pals;
    CharTile *tiles;
    uint32_t pages[MAX_PAGES]; /* fl texture handles, FL_TEX_IDX4 */
    int n_pages;
    int shelf_x, shelf_y, shelf_h; /* packer state of the last page */
    int pal_row;                  /* 16 consecutive palette atlas rows = slot.d[0..15] */
    uint8_t *scratch;
};

static uint32_t rd32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }
static int16_t rd16s(const uint8_t *p) { return (int16_t)(p[0] | p[1] << 8); }

FlCharBank *fl_char_bank_create(const uint8_t *d, size_t n)
{
    if (n < 0x20) return NULL;
    FlCharBank *b = (FlCharBank *)calloc(1, sizeof *b);
    b->d = d;
    b->n = n;
    b->tile_tab = rd32(d + 0x04);
    b->frame_tab = rd32(d + 0x0C);
    b->pal_off = rd32(d + 0x14);
    if (b->tile_tab + 4 > n || b->frame_tab + 4 > n || b->pal_off + 32 * 16 > n) { free(b); return NULL; }
    b->n_tiles = (int)(rd32(d + b->tile_tab) / 4);
    b->n_frames = (int)(rd32(d + b->frame_tab) / 4);
    b->n_pals = (int)((n - b->pal_off) / 32);
    if (b->n_pals > 48) b->n_pals = 48;
    b->tiles = (CharTile *)calloc((size_t)b->n_tiles, sizeof(CharTile));
    for (int i = 0; i < b->n_tiles; i++) {
        uint32_t o = b->tile_tab + rd32(d + b->tile_tab + 4 * i);
        b->tiles[i].page = -1;
        if (o + 4 <= n) {
            b->tiles[i].fw8 = d[o]; b->tiles[i].fh8 = d[o + 1];
            b->tiles[i].w8 = d[o + 2]; b->tiles[i].h8 = d[o + 3];
        }
    }
    b->scratch = (uint8_t *)malloc(64 * 64 + 64);
    /* func_00411C10: 16 CLUTs converted from the bank's ARGB1555 palettes */
    b->pal_row = r_pal_alloc_rows(16);
    if (b->pal_row < 0) { fl_char_bank_destroy(b); return NULL; }
    for (int p = 0; p < 16; p++) fl_char_load_palette(b, p, p);
    return b;
}

void fl_char_bank_destroy(FlCharBank *b)
{
    if (!b) return;
    for (int i = 0; i < b->n_pages; i++) fl_tex_release(b->pages[i]);
    free(b->tiles);
    free(b->scratch);
    free(b);
}

int fl_char_frame_count(const FlCharBank *b) { return b->n_frames; }
int fl_char_tile_count(const FlCharBank *b) { return b->n_tiles; }

void fl_char_set_palette_1555(FlCharBank *b, int dst, const uint16_t *c)
{
    uint8_t rgba[16 * 4];
    for (int k = 0; k < 16; k++) argb1555_to_rgba8(c[k], rgba + 4 * k);
    r_pal_write(b->pal_row + (dst & 15), 0, 16, rgba);
}

void fl_char_load_palette(FlCharBank *b, int dst, int src)
{
    if (src < 0 || src >= b->n_pals) return;
    uint16_t c[16];
    const uint8_t *p = b->d + b->pal_off + 32 * src;
    for (int k = 0; k < 16; k++) c[k] = (uint16_t)(p[2 * k] | p[2 * k + 1] << 8);
    fl_char_set_palette_1555(b, dst, c);
}

/* Decode tile `ti` (func_00413A80 + square sub-block layout) and pack it
 * into an atlas page. Replaces the 26-page PSMT4 LRU cache. */
static int ensure_tile(FlCharBank *b, int ti)
{
    CharTile *t = &b->tiles[ti];
    if (t->page >= 0) return 0;
    int w = t->w8 * 8, h = t->h8 * 8;
    if (w <= 0 || h <= 0 || w > 64 || h > 64) return -1;
    uint32_t o = b->tile_tab + rd32(b->d + b->tile_tab + 4 * ti);
    uint8_t raw[64 * 64 / 2 + 32];
    lz8_decode(b->d + o + 4, b->n - o - 4, raw, (size_t)(w * h / 2));
    int s = w < h ? w : h, nsub = (w > h ? w : h) / s;
    uint8_t *pix = b->scratch;
    size_t p = 0;
    for (int k = 0; k < nsub; k++) {
        int ox = w >= h ? k * s : 0, oy = w >= h ? 0 : k * s;
        for (int y = 0; y < s; y++)
            for (int x = 0; x < s; x += 2) {
                uint8_t v = raw[p++];
                pix[(oy + y) * w + ox + x] = v & 15; /* PSMT4: low nibble = left */
                pix[(oy + y) * w + ox + x + 1] = v >> 4;
            }
    }
    /* shelf packer, 1 px gutter */
    if (b->n_pages == 0 || b->shelf_x + w + 1 > PAGE) {
        b->shelf_x = 0;
        b->shelf_y += b->shelf_h + 1;
        b->shelf_h = 0;
    }
    if (b->n_pages == 0 || b->shelf_y + h > PAGE) {
        if (b->n_pages == MAX_PAGES) return -1;
        uint8_t *zero = (uint8_t *)calloc(PAGE, PAGE); /* index 0 = transparent */
        b->pages[b->n_pages++] = fl_tex_create(PAGE, PAGE, FL_TEX_IDX4, zero);
        free(zero);
        b->shelf_x = b->shelf_y = b->shelf_h = 0;
    }
    t->page = (int16_t)(b->n_pages - 1);
    t->x = (uint16_t)b->shelf_x;
    t->y = (uint16_t)b->shelf_y;
    b->shelf_x += w + 1;
    if (h > b->shelf_h) b->shelf_h = h;
    fl_tex_update(b->pages[t->page], t->x, t->y, w, h, pix);
    return 0;
}

static const uint8_t *frame_rec(const FlCharBank *b, int f, int *nparts)
{
    if (f < 0 || f >= b->n_frames) return NULL;
    uint32_t o = b->frame_tab + rd32(b->d + b->frame_tab + 4 * f);
    if (o + 2 > b->n) return NULL;
    int n = rd16s(b->d + o);
    if (n < 0 || o + 2 + 8 * (size_t)n > b->n) return NULL;
    *nparts = n;
    return b->d + o + 2;
}

/* Part placement (func_00412260 + func_00413600): positions are cumulative
 * (pos -= (dx, dy)); a flipped part anchors at pos + flipExtent*8 - size. */
typedef struct PartRect { float x0, y0, x1, y1; int ti; uint16_t flags; } PartRect;

static int part_rect(const FlCharBank *b, const uint8_t *rec, int k, float *px, float *py, PartRect *r)
{
    int16_t dx = rd16s(rec + 8 * k), dy = rd16s(rec + 8 * k + 2);
    uint16_t flags = (uint16_t)rd16s(rec + 8 * k + 4);
    int ti = rd16s(rec + 8 * k + 6);
    *px -= dx;
    *py -= dy;
    if (ti < 0 || ti >= b->n_tiles) return -1;
    const CharTile *t = &b->tiles[ti];
    int w = t->w8 * 8, h = t->h8 * 8;
    r->x0 = (flags & 0x8000) ? *px + t->fw8 * 8 - w : *px;
    r->y0 = (flags & 0x4000) ? *py + t->fh8 * 8 - h : *py;
    r->x1 = r->x0 + w;
    r->y1 = r->y0 + h;
    r->ti = ti;
    r->flags = flags;
    return 0;
}

int fl_char_frame_bounds(FlCharBank *b, int f, int *x0, int *y0, int *x1, int *y1)
{
    int n;
    const uint8_t *rec = frame_rec(b, f, &n);
    if (!rec || !n) return -1;
    float px = 0, py = 0, a = 1e9f, c = 1e9f, e = -1e9f, g = -1e9f;
    for (int k = 0; k < n; k++) {
        PartRect r;
        if (part_rect(b, rec, k, &px, &py, &r)) continue;
        if (r.x0 < a) a = r.x0;
        if (r.y0 < c) c = r.y0;
        if (r.x1 > e) e = r.x1;
        if (r.y1 > g) g = r.y1;
    }
    *x0 = (int)a; *y0 = (int)c; *x1 = (int)e; *y1 = (int)g;
    return 0;
}

int fl_char_draw(FlCharBank *b, int f, const float m[16], uint32_t argb, int palette)
{
    int n;
    const uint8_t *rec = frame_rec(b, f, &n);
    if (!rec) return 0;
    /* RGBA = (c + 1) >> 1 per channel (GS 0x80 = 1.0) */
    uint8_t col[4];
    {
        unsigned ch[4] = { (argb >> 16) & 0xFF, (argb >> 8) & 0xFF, argb & 0xFF, argb >> 24 };
        for (int i = 0; i < 4; i++) {
            unsigned g = (ch[i] + 1) >> 1, v = (g * 255 + 64) / 128;
            col[i] = (uint8_t)(v > 255 ? 255 : v);
        }
    }
    int axis = m[1] == 0.f && m[4] == 0.f;
    float z = r_depth_of(m[14]);
    float px = 0, py = 0;
    int drawn = 0;
    /* parts later in the list are drawn later (on top), as in the original loop */
    for (int k = 0; k < n; k++) {
        PartRect r;
        if (part_rect(b, rec, k, &px, &py, &r)) continue;
        if (ensure_tile(b, r.ti)) continue;
        const CharTile *t = &b->tiles[r.ti];
        int mode, pal_unused;
        GLuint gl = r_tex_gl(b->pages[t->page], &mode, &pal_unused);
        r_use(gl, RM_INDEX);
        float u0 = (float)t->x / PAGE, v0 = (float)t->y / PAGE;
        float u1 = (float)(t->x + t->w8 * 8) / PAGE, v1 = (float)(t->y + t->h8 * 8) / PAGE;
        if (r.flags & 0x8000) { float s = u0; u0 = u1; u1 = s; }
        if (r.flags & 0x4000) { float s = v0; v0 = v1; v1 = s; }
        float cx[4] = { r.x0, r.x1, r.x1, r.x0 }, cy[4] = { r.y0, r.y0, r.y1, r.y1 };
        float cu[4] = { u0, u1, u1, u0 }, cv[4] = { v0, v0, v1, v1 };
        float pal = (float)(b->pal_row + (((r.flags >> 4) + palette) & 15));
        RVtx q[4];
        for (int i = 0; i < 4; i++) {
            float X = m[0] * cx[i] + m[4] * cy[i] + m[12];
            float Y = m[1] * cx[i] + m[5] * cy[i] + m[13];
            q[i].x = axis ? r_snap_x(X) : X;
            q[i].y = axis ? r_snap_y(Y) : Y;
            q[i].z = z;
            q[i].w = 1.f;
            q[i].u = cu[i];
            q[i].v = cv[i];
            memcpy(q[i].c, col, 4);
            q[i].pal = pal;
        }
        RVtx *o = r_verts(6);
        o[0] = q[0]; o[1] = q[1]; o[2] = q[2];
        o[3] = q[0]; o[4] = q[2]; o[5] = q[3];
        drawn++;
    }
    return drawn;
}
