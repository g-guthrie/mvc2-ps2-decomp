typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 m[16]; } M4;
typedef struct { u8 pad0[0x84]; u8 *w84; u8 pad88[0xCC - 0x88]; s16 hCC; u8 padCE[0x1E4 - 0xCE]; } CTX;
typedef struct { s8 b0; s8 b1; u16 h2; f32 f4; f32 f8; f32 fC; } ENT;
typedef struct { u8 pad[0x1C]; s32 *tab; } TB;
extern TB *D_004C283C;
extern u8 D_00476700[];

void func_003CE980(u8 *p) {
    extern void func_00123090();
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_004171E0();
    extern void func_00417170(void *);
    extern void func_004173C0(f32, f32, f32);
    extern void func_00417A50(f32, f32, f32);
    extern void func_00416D40(M4 *);
    extern void func_001538B0(CTX *, s32, M4 *);
    M4 mtx;
    CTX ctx;
    M4 tmp;
    ENT *e;
    s32 v;
    if (*(s8 *)(p + 0x13C) == 0) return;
    e = *(ENT **)(p + 0xD8);
    if (e == 0) return;
    func_00123090();
    while (e->b0 >= 0) {
        if (e->b0 != 0) {
            func_0011D8F8(&ctx, 0, 0x1E4);
            func_004171E0();
            if ((v = e->b1) != 0) {
                func_00417170(D_00476700 + (s8)v * 12);
            }
            func_004173C0(e->f4, e->f8, e->fC);
            func_00417A50(*(f32 *)(p + 0x78), *(f32 *)(p + 0x7C), *(f32 *)(p + 0x80));
            func_00416D40(&tmp);
            mtx.m[0] = tmp.m[0];
            mtx.m[1] = tmp.m[1];
            mtx.m[2] = tmp.m[2];
            mtx.m[3] = tmp.m[3];
            mtx.m[4] = tmp.m[4];
            mtx.m[5] = tmp.m[5];
            mtx.m[6] = tmp.m[6];
            mtx.m[7] = tmp.m[7];
            mtx.m[8] = tmp.m[8];
            mtx.m[9] = tmp.m[9];
            mtx.m[10] = tmp.m[10];
            mtx.m[11] = tmp.m[11];
            mtx.m[12] = tmp.m[12];
            mtx.m[13] = tmp.m[13];
            mtx.m[14] = tmp.m[14];
            mtx.m[15] = tmp.m[15];
            ctx.w84 = (u8 *)D_004C283C;
            ctx.hCC = e->h2;
            func_001538B0(&ctx, D_004C283C->tab[ctx.hCC], &mtx);
        }
        e++;
    }
}
