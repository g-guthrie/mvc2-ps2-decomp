typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x003F1F90 static copy (real body, verified in src/w2_f.c) */
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

u32 *func_003F2510(u32 *p, u32 n) {
    u32 *e = func_003F1F90(p, 0x1000);
    u32 *b = e + 3;
    u32 *r;
    if (e == 0) r = 0; else r = (u32 *)((u8 *)b + n * 12);
    return r;
}
