typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C279C[2];
extern u8 *D_004D3170[][94];
extern u8 D_004B70F0[][4];


void func_001E7750(s32 side)
{
    extern void func_001E7900(u8 *, u8 *);
    u8 *a;
    s8 i;
    s8 j;
    s32 jo;
    s32 io;
    u8 k;
    s32 other;
    u8 *b;
    s8 t;
    u8 u;

    for (i = D_004C279C[side] - 1, io = i * 4; i >= 0; i--, io -= 4) {
        a = *(u8 **)(io + (u32)D_004D3170[side]);
        if (*(s8 *)(a + 0x1B2) != 0) continue;
        t = *(s8 *)(a + 0x1B0);
        u = t;
        if (t == 0) continue;
        other = side ^ 1;
        k = ((u8)u & 6) >> 1;
        for (j = D_004C279C[other] - 1, jo = j * 4; j >= 0; j--, jo -= 4) {
            b = *(u8 **)(jo + (u32)D_004D3170[other]);
            if (*(s8 *)(b + 0x1B3) != 0) continue;
            t = *(s8 *)(b + 0x1B1);
            u = t;
            if (t == 0) continue;
            if (D_004B70F0[k][(u8)(((u8)u & 6) >> 1)] == 0) func_001E7900(a, b);
        }
    }
}
