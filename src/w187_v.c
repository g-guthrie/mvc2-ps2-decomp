typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x1C]; s16 h1C; s16 h1E; u8 pa[0x14]; f32 f34; f32 f38; u8 p1[0x20]; f32 f5C; f32 f60; u8 p2[4]; f32 f68; f32 f6C; u8 p3[0x143]; s8 b1B3; } PF;
extern s32 func_00174170();
extern s32 func_00174470();
extern void func_001E3210();
extern void func_003CAB00();
extern void func_003CAB20();
extern void func_00175700();
extern void func_001E7F60();

void func_003CB940(PF *p, u8 *q) {
    s32 h;
    if (p->h1E != 0) {
        ((u8 *)p)[0x13C] = 0;
        h = p->h1E - 1;
        p->h1E = h;
        if ((s16)h == 0 && p->h1C != 0) {
            func_001E3210(p, (u8)((u32)func_00174170() % 6 + 0x16));
        }
        return;
    }
    if (func_00174470() == 0) {
        ((u8 *)p)[0x13C] = 0;
        func_003CAB00(p, q);
        return;
    }
    {
        ((u8 *)p)[0x13C] = 1;
        *(s32 *)(q + 0x2B8) = 4;
        if (p->b1B3 != 0) {
            func_003CAB20(p, q, 9);
        } else {
            p->f34 += p->f5C;
            p->f5C += p->f68;
            p->f38 += p->f60;
            p->f60 += p->f6C;
            if (p->f38 < *(f32 *)(q + 0x430)) p->f60 = -p->f60;
            func_00175700(p);
            func_001E7F60(p);
        }
    }
}
