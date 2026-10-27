struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x1C]; s16 h1c; u8 pad1e[0x14]; f32 f34; u8 pad38[8]; s32 f40; u8 pad44[0xC]; f32 f50, f54, f58; u8 pad5c[0x1C]; f32 f78, f7c, f80; } S8;
void func_0015CDC0(S8 *p) {
    extern f32 func_00154710(u8 *, u8 *, s32);
    extern double func_00119058(f32);
    extern void func_003DAA40(struct Object *);
    extern u8 D_004450B0[], D_004450C0[], D_004450D0[], D_004450E0[];
    f32 f;
    if (p->h1c > 15) { func_003DAA40((struct Object *)p); return; }
    f = func_00154710(D_004450B0, (u8 *)p + 4, p->h1c);
    p->f50 = f;
    p->f54 = f;
    p->f58 = p->f50;
    f = func_00154710(D_004450C0, (u8 *)p + 5, p->h1c);
    p->f40 = (u16)((u32)(s32)(65536.0 * func_00119058(f) / 360.0 + 0.5));
    f = func_00154710(D_004450D0, (u8 *)p + 6, p->h1c);
    p->f34 = f;
    f = func_00154710(D_004450E0, (u8 *)p + 7, p->h1c);
    p->f78 = f;
    p->f7c = f;
    p->f80 = p->f78;
    p->h1c = p->h1c + 1;
}
