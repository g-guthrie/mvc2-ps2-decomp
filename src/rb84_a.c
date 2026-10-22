typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x2B8]; s8 b[0x20]; } S;
extern u8 *D_004C2794;
extern u8 D_004C0FC0[8];
extern u8 D_004C0FB8[8];
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_002D7B60(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern s32 func_0018AB10(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u32 v;
    u8 i, v3;
    u32 tu;
    s8 *c, *b0;
    u8 a1;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    p[0x2B9] = *(s8 *)(p + 0x2B9) + 1;
    p[0x2B9] = *(s8 *)(p + 0x2B9) & 3;
    v = D_004C0FC0[*(s8 *)(p + 0x2B9)];
    if (v != 0) {
        func_00176160(p, 0, (u8)v + p[0x25] * 10, 1);
    } else {
        func_00175C00(p, 0);
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        s32 h = *(s16 *)(p + 0x1C);
        if (h == 0) {
            *(s16 *)((s32)p + 0x1C) = 8;
            p[0x1B2] = 0;
            p[0x2C4] = *(s8 *)(p + 0x2C4) + 1;
        } else {
            *(s16 *)((s32)p + 0x1C) = h - 1;
        }
    }
    if (*(s8 *)(p + 0x1B2) == 0x81) goto reset;
    b0 = ((S *)p)->b;
    c = b0 + 0xC;
    if (b0[0xC] == 0) {
        a1 = *(s8 *)(p + 0x211);
        if (*(s8 *)(p + 0x211) != 0) {
            a1 &= (p[0x1E6] ? 1 : 2);
        }
        if (a1) goto reset;
    }
    if (func_0018AB10(p) != 0) {
        s16 w = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = w;
        if ((w & 0x100) != 0) {
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        }
    }
    i = 4;
    v3 = 3;
    for (; i >= 0; i--) {
        if (*(s16 *)(p + 0x1E) >= D_004C0FB8[i]) {
            v3 += i;
            break;
        }
    }
    if (*c < v3) {
        if (*(s16 *)(*(u8 **)(p + 0x220) + 0x434) != 0) {
            s16 t2 = *(s16 *)(p + 0x2C2) - 1;
            *(s16 *)(p + 0x2C2) = t2;
            if (t2 > 0) return;
        }
    }
reset:
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    tu = p[6];
    p[6] = tu + 1;
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    D_004F1F45[0] = 3;
    D_004F1F46[0] = 1;
    func_00175C00(p, 0);
    func_001757E0(p, 0x16, 1);
}
