typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

u8 *func_003F26E0(u32 *a, s32 n, s32 k) {
    u8 *p;
    s32 i, x;
    p = (u8 *)func_003F1F90(a, 0x10000);
    if (p == 0) return 0;
    p += 12;
    for (i = 0; i < n; i++) {
        x = *(s32 *)p;
        p += 4;
        p += x * 8;
    }
    if (k >= *(s32 *)p) return 0;
    p += 4;
    p += k * 8; return p;
}
