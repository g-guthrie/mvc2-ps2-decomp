#include "decode.h"
#include "render.h"
#include <stdlib.h>
#include <string.h>

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }
static uint32_t rd32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

/* func_00176230: u16 stream, MSB-first flag word; 1 = token v: cnt = v>>11
 * (0 -> next word), off = v & 0x7FF words back, off 0 = zero fill, both 0 = end. */
uint8_t *lz16_decode(const uint8_t *src, size_t src_size, size_t *out_size)
{
    size_t nw = src_size / 2, i = 0, n = 0, cap = src_size * 4 + 64;
    uint16_t *out = (uint16_t *)malloc(cap * 2);
    uint32_t mask = 0, bits = 0;
    if (!out) return NULL;
#define NEED(k) do { if (n + (k) > cap) { while (n + (k) > cap) cap *= 2; \
    uint16_t *t_ = (uint16_t *)realloc(out, cap * 2); if (!t_) { free(out); return NULL; } out = t_; } } while (0)
    for (;;) {
        if (mask == 0) {
            if (i >= nw) break;
            bits = rd16(src + 2 * i++);
            mask = 0x8000;
        }
        if (i >= nw) break;
        if (bits & mask) {
            uint32_t v = rd16(src + 2 * i++), cnt = v >> 11;
            if (cnt) v &= 0x7FF;
            else { if (i >= nw) break; cnt = rd16(src + 2 * i++); }
            if (v == 0) {
                if (cnt == 0) break;
                NEED(cnt);
                memset(out + n, 0, cnt * 2);
                n += cnt;
            } else {
                if (v > n) break; /* corrupt */
                NEED(cnt);
                for (uint32_t k = 0; k < cnt; k++, n++) out[n] = out[n - v];
            }
        } else {
            NEED(1);
            out[n++] = rd16(src + 2 * i++);
        }
        mask >>= 1;
    }
#undef NEED
    /* the stream is u16 little-endian; convert in place on big-endian hosts */
    uint8_t *b = (uint8_t *)out;
    for (size_t k = 0; k < n; k++) {
        uint16_t w = out[k];
        b[2 * k] = (uint8_t)w;
        b[2 * k + 1] = (uint8_t)(w >> 8);
    }
    if (out_size) *out_size = n * 2;
    return b;
}

/* func_00413A80: flag byte MSB-first; 1 = byte b: copy (b & 15) + 2 bytes from
 * dst - ((b >> 4) + 1); 0 = literal. Runs until dst >= end (may overrun by 16). */
size_t lz8_decode(const uint8_t *src, size_t src_size, uint8_t *dst, size_t out_len)
{
    size_t p = 0, n = 0;
    unsigned mask = 0, flags = 0;
    while (n < out_len && p < src_size) {
        if (mask == 0) { flags = src[p++]; mask = 0x80; if (p >= src_size) break; }
        if (flags & mask) {
            unsigned b = src[p++];
            size_t back = (b >> 4) + 1, cnt = (b & 15) + 2;
            if (back > n) back = n ? n : 1;
            for (size_t k = 0; k < cnt; k++, n++) dst[n] = n >= back ? dst[n - back] : 0;
        } else {
            dst[n++] = src[p++];
        }
        mask >>= 1;
    }
    return p;
}

void argb1555_to_rgba8(uint16_t c, uint8_t out[4])
{
    out[0] = (uint8_t)(((c >> 10) & 31) << 3);
    out[1] = (uint8_t)(((c >> 5) & 31) << 3);
    out[2] = (uint8_t)((c & 31) << 3);
    out[3] = (c & 0x8000) ? 255 : 0;
}

/* ---- TEX pack ---- */
int texpack_records(const uint8_t *d, size_t size, FlTexRecord *out, int max)
{
    int n = 0;
    for (size_t q = 0; q + 16 <= size; q += 16) {
        int16_t w = (int16_t)rd16(d + q);
        if (w <= 0) break;
        if (out && n < max) {
            out[n].w = w;
            out[n].h = rd16(d + q + 2);
            out[n].flags = rd32(d + q + 4);
            out[n].offset = rd32(d + q + 8);
            out[n].attr = (int32_t)rd32(d + q + 12);
        }
        n++;
    }
    return n;
}

static int looks_like_pack(const uint8_t *d, size_t size)
{
    FlTexRecord r[256];
    int n = texpack_records(d, size < 4096 ? size : 4096, r, 256), tim = 0;
    if (n <= 0) return 0;
    for (int i = 0; i < n && i < 256; i++) {
        if ((r[i].flags >> 16) > 3 || r[i].offset >= size) return 0;
        if ((r[i].flags >> 16) == 1 && r[i].offset + 4 <= size && !memcmp(d + r[i].offset, "TIM2", 4)) tim = 1;
    }
    return tim;
}

uint8_t *texpack_decode(const uint8_t *raw, size_t size, size_t *out_size)
{
    if (looks_like_pack(raw, size)) {
        uint8_t *c = (uint8_t *)malloc(size);
        memcpy(c, raw, size);
        *out_size = size;
        return c;
    }
    return lz16_decode(raw, size, out_size);
}

/* ---- TIM2 (see tim2.py; game parser func_003F4C10 / func_003F4E70) ---- */
int tim2_count(const uint8_t *d, size_t n)
{
    if (n < 16 || memcmp(d, "TIM2", 4)) return 0;
    return rd16(d + 6);
}

static void color_at(int fmt, const uint8_t *b, uint8_t o[4])
{
    if (fmt == 1) {
        uint16_t c = rd16(b);
        o[0] = (uint8_t)((c & 31) << 3);
        o[1] = (uint8_t)(((c >> 5) & 31) << 3);
        o[2] = (uint8_t)(((c >> 10) & 31) << 3);
        o[3] = (c & 0x8000) ? 255 : 0;
    } else if (fmt == 2) {
        o[0] = b[0]; o[1] = b[1]; o[2] = b[2]; o[3] = 255;
    } else {
        int a = b[3] * 2; /* PS2 alpha 0x80 = opaque */
        o[0] = b[0]; o[1] = b[1]; o[2] = b[2]; o[3] = (uint8_t)(a > 255 ? 255 : a);
    }
}

int tim2_decode(const uint8_t *d, size_t n, int pic, Tim2Pic *out)
{
    memset(out, 0, sizeof *out);
    int count = tim2_count(d, n);
    if (pic < 0 || pic >= count) return -1;
    size_t p = d[5] == 1 ? 128 : 16;
    for (int k = 0; k < pic; k++) {
        if (p + 4 > n) return -1;
        p += rd32(d + p);
    }
    if (p + 0x30 > n) return -1;
    uint32_t clut_size = rd32(d + p + 4), img_size = rd32(d + p + 8);
    uint16_t hdr_size = rd16(d + p + 12), clut_colors = rd16(d + p + 14);
    out->mipmaps = d[p + 17];
    out->clut_type = d[p + 18];
    out->image_type = d[p + 19];
    out->w = rd16(d + p + 20);
    out->h = rd16(d + p + 22);
    out->clut_colors = clut_colors;
    size_t img = p + hdr_size, clut = img + img_size;
    size_t npx = (size_t)out->w * out->h;
    if (img + img_size > n || clut + clut_size > n || clut_colors > 256) return -1;
    int ef = out->clut_type & 0x3F, es = ef == 1 ? 2 : ef == 2 ? 3 : 4;
    for (int k = 0; k < clut_colors; k++) {
        int src = k;
        /* 256-colour CSM1 CLUT: swap index bits 3 and 4 */
        if (clut_colors == 256 && !(out->clut_type & 0x80))
            src = (k & 0xE7) | ((k & 0x08) << 1) | ((k & 0x10) >> 1);
        color_at(ef, d + clut + (size_t)es * src, out->clut + 4 * k);
    }
    if (out->image_type == 4 || out->image_type == 5) {
        out->index = (uint8_t *)malloc(npx);
        if (out->image_type == 5) {
            if (img_size < npx) return -1;
            memcpy(out->index, d + img, npx);
        } else {
            if (img_size < npx / 2) return -1;
            for (size_t k = 0; k < npx / 2; k++) {
                out->index[2 * k] = d[img + k] & 15; /* low nibble = left pixel */
                out->index[2 * k + 1] = d[img + k] >> 4;
            }
        }
    } else if (out->image_type >= 1 && out->image_type <= 3) {
        int bs = out->image_type == 1 ? 2 : out->image_type == 2 ? 3 : 4;
        if (img_size < npx * bs) return -1;
        out->rgba = (uint8_t *)malloc(npx * 4);
        for (size_t k = 0; k < npx; k++) color_at(out->image_type, d + img + bs * k, out->rgba + 4 * k);
    } else {
        return -1;
    }
    return 0;
}

void tim2_free(Tim2Pic *p)
{
    free(p->index);
    free(p->rgba);
    p->index = p->rgba = NULL;
}
