typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0, f4, f8, fC; } E413;
extern E413 D_00632610[];

s32 func_00413C00(s32 a, s32 b, s32 c) {
    u8 buf[0x50];
    s32 i;
    s32 *s1;
    E413 *e;
    u32 v, t;
    extern s32 func_003DB9D0(s32);
    extern void func_003E95E0(s32, s32, u8 *, s32);
    extern u32 func_003F5C30(s32, s32, s32);
    extern void func_003F5C00(u8 *, s32, s32, u32);
    extern void func_003EA0D0(s32);

    if ((u32)(a -= 1) >= 16) return 0;
    e = &D_00632610[a];
    if (e->f0 == 0) return 0;
    if (b < 0 || b >= 16) return 0;
    s1 = (s32 *)func_003DB9D0(e->fC) + b;
    func_003E95E0(0, *s1, buf, 0);
    i = 0;
    do {
        v = func_003F5C30(i, 0, c);
        t = (v & 0xFF000000) >> 24;
        if (t == 0xFF) t = 0x80; else t >>= 1;
        func_003F5C00(buf, i, 0, (v & 0xFFFFFF) | (t << 24));
        i++;
    } while (i < 16);
    func_003EA0D0(*s1);
    return 1;
}
