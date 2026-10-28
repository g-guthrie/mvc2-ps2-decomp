/* CPU-side asset decoders (no GL). */
#ifndef PORT_DECODE_H
#define PORT_DECODE_H
#include <stddef.h>
#include <stdint.h>

/* One decoded TIM2 picture. index != NULL for 4/8-bit (one byte per pixel);
 * clut is linear (CSM1 already undone), RGBA8 with alpha 0..255.
 * rgba is filled for 16/24/32-bit pictures. */
typedef struct Tim2Pic {
    int w, h, image_type, clut_type, clut_colors, mipmaps;
    uint8_t *index;
    uint8_t *rgba;
    uint8_t clut[256 * 4];
} Tim2Pic;

int tim2_count(const uint8_t *d, size_t n);
int tim2_decode(const uint8_t *d, size_t n, int pic, Tim2Pic *out); /* 0 = ok */
void tim2_free(Tim2Pic *p);

/* ARGB1555 -> RGBA8 as func_00411C10 does (<<3, A = bit15 ? opaque : 0). */
void argb1555_to_rgba8(uint16_t c, uint8_t out[4]);

#endif
