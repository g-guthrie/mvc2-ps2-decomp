typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } V4_36c;
typedef struct {
    u16 f0; u16 f2; u16 f4; s16 f6; s16 f8; u16 fA; u16 fC; u16 fE;
    f32 m0[4]; f32 m1[4]; f32 m2[4];
} E36c;
typedef struct {
    u16 f0; u16 f2; u16 f4; u16 f6; u16 f8; u16 fA; u16 fC; u16 fE;
    f32 m0[4]; f32 m1[4]; f32 m2[4];
    u16 f40; u16 f42; u16 f44;
} S36c;

s32 func_003F1730(V4_36c *out, V4_36c *buf, u8 *ctx, s32 n) {
    extern s32 func_003F13E0(void *);
    extern s32 func_003F16D0(u8 *, s32);
    extern s32 func_003F1470(u8 *, s32);
    extern s32 func_003F1410(u8 *, s32);
    extern u8 *func_003F1620(u8 *, u32);
    S36c *src; /*D*/
    s32 cnt; /*D*/
    s32 base; /*D*/
    E36c *e; /*D*/
    s32 i; /*D*/
    if (n >= func_003F13E0(ctx)) return 0;
    *(s32 *)((u8 *)buf + 0xC) = func_003F16D0(ctx, n);
    cnt = func_003F1470(ctx, n);
    *(s16 *)((u8 *)buf + 2) = cnt;
    *(s32 *)((u8 *)buf + 4) = 0x10;
    e = (E36c *)((u8 *)buf + 0x10);
    *(s32 *)((u8 *)buf + 8) = 0;
    for (i = 0; i < cnt; i++) {
        e[i].m0[0] = 0; e[i].m1[0] = 0; e[i].m2[0] = 0;
        e[i].m0[1] = 0; e[i].m1[1] = 0; e[i].m2[1] = 0;
        e[i].m0[2] = 0; e[i].m1[2] = 0; e[i].m2[2] = 0;
        e[i].m0[3] = 0; e[i].m1[3] = 0; e[i].m2[3] = 0;
    }
    base = func_003F1410(ctx, n);
    for (i = 0; i < cnt; i++) {
        src = (S36c *)func_003F1620(ctx, i + base);
        e->f0 = src->f0;
        e->f2 = src->f44;
        e->f6 = src->f8;
        e->f8 = src->fC;
        if (e->f6 != -1) e->f6 = e->f6 - base;
        if (e->f8 != -1) e->f8 = e->f8 - base;
        e->fA = src->f40;
        e->m0[0] = src->m0[0]; e->m1[0] = src->m1[0]; e->m2[0] = src->m2[0];
        e->m0[1] = src->m0[1]; e->m1[1] = src->m1[1]; e->m2[1] = src->m2[1];
        e->m0[2] = src->m0[2]; e->m1[2] = src->m1[2]; e->m2[2] = src->m2[2];
        e->m0[3] = src->m0[3]; e->m1[3] = src->m1[3]; e->m2[3] = src->m2[3];
        e++;
    }
    *out = *buf;
    *(V4_36c **)((u8 *)out + 8) = buf;
    return 1;
}
