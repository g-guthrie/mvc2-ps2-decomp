typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 f0; u32 f4; s32 f8; s32 fC; s32 f10; u32 f14; u32 f18; } S3F;
u32 func_003F0A60(S3F *p, u32 n) {
    extern u32 func_003F0B20(S3F *);
    extern void func_003F0E60(S3F *);
    u32 a, t, k; s32 m = -1;
    t = n + p->f18; t = t + m; a = (p->f18 - 1); a = ~a & t;
    if (func_003F0B20(p) < a) { func_003F0E60(p);
        t = p->f18; k = t - 1; k = ~k; a = (a + t - 1) & k;
        if (func_003F0B20(p) < a) return 0; }
    if (p->fC != 0) return p->f14 + p->f4 - a;
    return p->f14 - p->f4;
}
