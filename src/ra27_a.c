typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 flags;
    s32 w;
    s32 h;
    s32 stride;
    u8 *base;
    s32 bpp;
} Img_003F5900;

s32 func_003F5900(s32 x, s32 y, Img_003F5900 *c) {
    if (x < 0 || y < 0 || x >= c->w || y >= c->h) return 0;
    if (c->bpp == 0) {
        if (c->flags & 0x40) {
            s32 r = (s32)c->base + c->stride * y;
            return r + x;
        }
        {
            s32 r = (s32)c->base + c->stride * y;
            return r + x / 2;
        }
    }
    return (s32)c->base + c->stride * y + x * c->bpp;
}
