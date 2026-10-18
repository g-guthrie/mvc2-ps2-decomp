typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C[];
extern u8 *D_004C28F4;

void func_003287A0(u8 *a)
{
    extern void func_003DAA40(void);
    extern double func_00119058(f32);
    u8 *s0;
    double c;
    f32 g;
    double r;
    D_004C28F4 = *(u8 **)(a + 0x18) + 0x2B8;
    s0 = *(u8 **)(a + 0x18);
    if (a[1] != s0[1]) { func_003DAA40(); return; }
    if (s0[0x1E4] != 0x15) { func_003DAA40(); return; }
    if (s0[0x169] != 0x14) { func_003DAA40(); return; }
    if (D_004C28F4[0xA] == 0) { func_003DAA40(); return; }
    g = D_004F1F4C[0];
    if (s0[0x1E6] != 0) c = -285.0; else c = 285.0;
    r = func_00119058(g);
    r += c;
    *(f32 *)(s0 + 0x34) = (f32)r;
}
