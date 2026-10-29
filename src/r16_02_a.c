/* func_003F59C0: plot one pixel into an image (packed 4/8/16/24/32-bit formats).
 * MW 3.0: ./try30.sh src/r16_02_a.c "-O3,p -sdatathreshold 0"
 * The redundant `r &= 0xFF;` is load-bearing: the compound assignment makes the
 * IRO keep r as a real local (not expression-propagated), which gives it a low
 * vreg index so it is coloured after mx1/g (retail's a2/a3/t0), and makes the R
 * term the lighter OR operand (retail's `or t5,R,G` with G evaluated first). */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 flags;
    u8 pad04[0x10];
    s32 fmt;
    u8 pad18[4];
    s32 sh0;
    s32 mx0;
    u8 pad24[4];
    s32 sh1;
    s32 mx1;
    u8 pad30[4];
    s32 sh2;
    s32 mx2;
    u8 pad3C[4];
    s32 sh3;
    s32 mx3;
} Img;

typedef struct {
    s16 x;
    s16 y;
    u32 col;
} Pt;

extern u8 *func_003F5900(s32 x, s32 y, Img *img);

s32 func_003F59C0(Img *img, Pt *pt)
{
    u8 *d;
    u32 flags;
    if ((d = func_003F5900(pt->x, pt->y, img)) == 0) {
        return 0;
    }
    flags = img->flags;
    if ((flags & 4) != 0) {
        switch (img->fmt) {
        case 4:
            *(u32 *)d = pt->col;
            break;
        case 2:
            *(u16 *)d = pt->col;
            break;
        case 1:
            *d = pt->col;
            break;
        case 0:
            if (flags & 0x40) {
                *d = pt->col;
            } else {
                u32 a;
                u32 c;
                u32 o;
                s32 hi, lo;
                hi = (flags & 0x10) != 0;
                lo = (pt->x & 1) != 0;
                c = pt->col;
                o = *d;
                if (lo ^ hi) {
                    a = o & 0xF0; c &= 0xF;
                } else {
                    c = (c & 0xF) << 4; a = o & 0xF;
                }
                *d = (a & 0xFF) | c;
            }
            break;
        }
    } else {
        u32 c = pt->col;
        s32 g, r, b, a;
        u32 v;
        g = (c >> 8) & 0xFF;
        r = (c >> 16) & 0xFF;
        r &= 0xFF;
        b = c & 0xFF;
        a = (c >> 24) & 0xFF;
        v = ((r * img->mx0 / 255) << img->sh0) | ((g * img->mx1 / 255) << img->sh1) |
            ((b * img->mx2 / 255) << img->sh2) | ((a * img->mx3 / 255) << img->sh3);
        switch (img->fmt) {
        case 2:
            *(u16 *)d = v;
            break;
        case 3:
            d[0] = v;
            d[1] = v >> 8;
            d[2] = v >> 16;
            break;
        case 4:
            *(u32 *)d = v;
            break;
        }
    }
    return 1;
}
