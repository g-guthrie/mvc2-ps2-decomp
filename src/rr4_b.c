typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 flags;
    s32 pad04[4];
    s32 f14;
    s32 f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40, f44;
} F4b;

u32 func_003F5C30(s32 x, s32 y, F4b *f, u32 z) {
    extern u8 *func_003F5900(s32, s32, F4b *);
    u8 *ptr;
    u32 r;
    u32 a0, a1, a2;
    if ((ptr = func_003F5900(x, y, f)) == 0) return 0;
    if ((f->flags & 4) != 0) {
        switch (f->f14) {
        case 0:
            if ((f->flags & 0x40) != 0) {
                r = *ptr;
            } else {
                u32 b = *ptr;
                if (((x & 1) != 0) ^ ((f->flags & 0x10) != 0)) r = b & 0xF;
                else r = (b >> 4) & 0xF;
            }
            break;
        case 1: r = *ptr; break;
        case 2: r = *(u16 *)ptr; break;
        case 4: r = *(u32 *)ptr; break;
        }
        return r;
    }
    switch (f->f14) {
    case 2: r = *(u16 *)ptr; break;
    case 3: r = ptr[0] | ((ptr[2] << 16) | (ptr[1] << 8)); break;
    case 4: r = *(u32 *)ptr; break;
    }
    z = 255;
    if (f->f3C != 0) z = ((((r >> f->f40) & f->f44) * 255) / f->f44);
    a0 = 0;
    if (f->f18 != 0) a0 = ((((r >> f->f1C) & f->f20) * 255) / f->f20);
    a1 = 0;
    if (f->f24 != 0) a1 = ((((r >> f->f28) & f->f2C) * 255) / f->f2C);
    a2 = 0;
    if (f->f30 != 0) a2 = ((((r >> f->f34) & f->f38) * 255) / f->f38);
    return (z << 24) | (a0 << 16) | (a1 << 8) | a2;
}
