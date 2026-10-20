/* Metrowerks 3.0: ./try30.sh src/w190_f.c "-O3,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 *func_003F1F00(void *file);
extern u8 *func_003F1F10(u8 *, s32);

u8 *func_003F19B0(u8 *a, s32 n) {
    u8 *r;
    u8 *p;
    s32 i;
    func_003F1F00(a);
    r = func_003F1F10(a, 1);
    if (r == 0) return 0;
    if (*(u32 *)(r + 4) <= (u32)n) return 0;
    p = r + 0xC;
    for (i = 0; i < n; i++) p += *(s32 *)(p + 8);
    return p;
}
