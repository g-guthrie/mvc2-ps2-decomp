typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

#define RD32(p) ((u32)(p)[0] | ((u32)(p)[1] << 8) | ((u32)(p)[2] << 16) | ((u32)(p)[3] << 24))
#define SW32(x) ((((u32)(x) >> 24) | ((x) << 24)) | ((((x) << 8) & 0xFF0000) | (((x) >> 8) & 0xFF00)))

u8 *func_003F6E70(u8 *p, s32 n, s32 *rate, s32 *chan, s32 *bits, s32 *frames, s32 *mode)
{
    u32 magic;
    u8 *q;
    u32 off;
    u32 size;
    u32 enc;
    s32 x, y;

    magic = RD32(p);
    q = p + 4;
    if (magic != 0x64732E && magic != 0x646E732E) return 0;
    off = RD32(q);
    off = SW32(off);
    q += 4;
    if (n < (s32)off) return 0;
    size = RD32(q);
    q += 4;
    enc = RD32(q);
    q += 4;
    size = SW32(size);
    enc = SW32(enc);
    switch (enc) {
    case 1:
        *mode = 2;
        *bits = 8;
        break;
    case 2:
        *mode = 1;
        *bits = 8;
        break;
    case 3:
        *mode = 0;
        *bits = 16;
        break;
    default:
        return 0;
    }
    x = RD32(q);
    q += 4;
    *rate = SW32(x);
    y = RD32(q);
    *chan = SW32(y);
    if (*mode == 2) {
        *frames = (s32)size / *chan;
    } else if (*mode == 1) {
        *frames = (s32)size / *chan;
    } else if (*mode == 0) {
        *frames = (s32)size / 2 / *chan;
    } else {
        *frames = 0x7FFF0000;
    }
    return p + off;
}
