#include "runtime_state_types.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern const s32 D_004BEDC0[];

static s32 func_00416770(struct RuntimeOwner *owner, s32 scale)
{
    s32 factor = D_004BEDC0[owner->stateIndex];
    return (scale * factor) >> 3;
}

static s32 func_004167A0(struct RuntimeOwner *p, s32 a1, s32 a2)
{
    s32 r = func_00416770(p, a1);
    return p->unk10 + r + a2 * p->unk0c;
}

typedef struct { s32 f0; s32 pitch; u8 pad8[0xC]; s32 fmt; u8 pad18[0x30]; u8 *pal; } Img33f;

void func_004167D0(Img33f *a, s32 a1, s32 a2, Img33f *b, s32 b1, s32 b2, s32 w, s32 h) {
    s32 y, x;
    s32 apitch = a->pitch;
    s32 bpitch = b->pitch;
    if (a->fmt == 2) {
        if (b->fmt == 2) {
            u16 *dst = (u16 *)func_004167A0((struct RuntimeOwner *)a, a1, a2);
            u16 *src = (u16 *)func_004167A0((struct RuntimeOwner *)b, b1, b2);
            y = 0;
            if (y < h) do {
                u16 *d = dst;
                u16 *s = src;
                x = 0;
                if (x < w) do {
                    *d++ = *s++;
                    x++;
                } while (x < w);
                dst += apitch;
                src += bpitch;
                y++;
            } while (y < h);
        } else if (b->fmt == 1) {
            u16 *d;
            u8 *dst, *src, *s, *pal, *e;
            dst = (u8 *)func_004167A0((struct RuntimeOwner *)a, a1, a2);
            src = (u8 *)func_004167A0((struct RuntimeOwner *)b, b1, b2);
            pal = b->pal;
            y = 0;
            if (y < h) do {
                d = (u16 *)dst;
                s = src;
                x = 0;
                if (x < w) do {
                    e = pal + (*s++) * 4;
                    *d++ = (e[0] >> 3 & 0xFFFF) | ((e[1] >> 3 & 0xFFFF) << 5) | ((e[2] >> 3 & 0xFFFF) << 10) | ((e[3] != 0) << 15);
                    x++;
                } while (x < w);
                dst += apitch * 2;
                src += bpitch;
                y++;
            } while (y < h);
        }
    } else if (a->fmt == 1) {
        if (b->fmt == 1) {
            u8 *d, *dst, *src, *s;
            dst = (u8 *)func_004167A0((struct RuntimeOwner *)a, a1, a2);
            src = (u8 *)func_004167A0((struct RuntimeOwner *)b, b1, b2);
            y = 0;
            if (y < h) do {
                d = dst;
                s = src;
                x = 0;
                if (x < w) do {
                    *d++ = *s++;
                    x++;
                } while (x < w);
                dst += apitch;
                src += bpitch;
                y++;
            } while (y < h);
        }
    }
}
