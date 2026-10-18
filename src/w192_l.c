typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct Q { u8 pad0[4]; u8 b4; u8 pad5[0x34 - 5]; f32 f34; u8 pad38[0x140 - 0x38]; s16 h140; u8 pad142[0x25C - 0x142]; u8 b25C; u8 pad25D[0x430 - 0x25D]; f32 f430; } Q;
typedef struct P {
    u8 pad0[4]; u8 b4; u8 pad5[0x14 - 5]; Q *f14; Q *f18; u8 pad1C[5]; u8 b21; u8 pad22[2]; s8 b24;
    u8 pad25[0x34 - 0x25]; f32 f34; f32 f38; u8 pad3C[0xD0 - 0x3C]; Q *fD0; u8 padD4[0x140 - 0xD4]; s16 h140;
} P;
extern s8 D_004C20B0[8];
extern u8 D_004C20A8[8];
extern f32 D_004746C4[];
extern f32 D_004746C0[];
extern void func_003BD830(P *);
extern void func_003BD840(void);
extern void func_001757E0(P *, s32, s32);
extern void func_00175700(P *);

void func_003BC6F0(P *p)
{
    f32 f1;
    Q *q;
    Q **pp = &p->fD0;
    if (p->f18->b25C != 0) {
        func_003BD830(p);
        return;
    }
    if (p->b4 == 0) {
        p->b4 = p->b4 + 1;
        func_003BD840();
        p->b24 = D_004C20B0[p->b21];
        func_001757E0(p, 0x19, D_004C20A8[p->b21]);
    } else if (p->f14->b4 >= 2) {
        func_003BD830(p);
    } else {
        p->h140 = p->f14->h140;
        q = *pp;
        p->f34 = q->f34;
        p->f38 = q->f430 + D_004746C4[p->b21 * 2];
        f1 = D_004746C0[p->b21 * 2];
        if (p->h140 == 0)
            f1 = -f1;
        p->f34 += f1;
        func_00175700(p);
    }
}
