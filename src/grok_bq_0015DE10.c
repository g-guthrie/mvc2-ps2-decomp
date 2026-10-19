typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_003DAA40(u8 *);
extern f32 D_00445380[];
extern u32 D_004C2838 __attribute__((section(".sdata")));

void func_0015DE10(u8 *p)
{
    s16 v = *(s16 *)(p + 0x1C);
    if (v < 7) {
        *(s16 *)(p + 0x1C) = (s16)(v + 1);
        return;
    }
    v = *(s16 *)(p + 0x1E);
    if (!(v < 11)) {
        func_003DAA40(p);
        return;
    }
    *(s16 *)(p + 0xCC) = v;
    *(u32 *)(p + 0x84) = D_004C2838;
    *(f32 *)(p + 0x78) = D_00445380[*(s16 *)(p + 0x1C)];
    *(f32 *)(p + 0x7C) = D_00445380[*(s16 *)(p + 0x1C)];
    *(f32 *)(p + 0x80) = D_00445380[*(s16 *)(p + 0x1C)];
    {
        u32 a = 0x3E0BA2E9u;
        u32 b = 0x3D3A2E8Cu;
        *(f32 *)(p + 0x50) += *(f32 *)&a;
        *(f32 *)(p + 0x58) += *(f32 *)&a;
        *(f32 *)(p + 0x54) -= *(f32 *)&b;
    }
    {
        s32 d = -0xBA3;
        if (p[0x21] != 0)
            d = 0xBA3;
        *(s32 *)(p + 0x44) += d;
    }
    *(s16 *)(p + 0x1E) = (s16)(*(s16 *)(p + 0x1E) + 1);
}
