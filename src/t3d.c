typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[4]; s8 b4; u8 p5[0x3C]; u8 b41; u8 p42[0x4E]; s8 b90; u8 p91; s8 b92; } G_003D9C30;
extern G_003D9C30 *D_004C2840;
extern void (*D_00477840[])(void);
extern void func_0016E960();
extern void func_003D7310();
extern void func_003DA6F0();
extern void func_00152600();
extern void func_00152660();
extern void func_001861B0();
extern void func_001757E0();
extern void func_0019DED0();
extern u8 *D_004C2794;

void func_003D9C30(void) {
    G_003D9C30 *g = D_004C2840;
    if (g->b90 != 0) {
        func_0016E960();
        if (D_004C2840->b92 < 2) func_003D7310(func_00152600);
        func_003D7310(func_00152660);
    } else {
        g->b41 = 1;
        D_00477840[D_004C2840->b4]();
        func_003DA6F0(6);
        func_003DA6F0(0xD);
        func_003D7310(func_00152600);
    }
}

void func_00231F60(u8 *a, u8 *b) {
    u32 t = a[7];
    s16 *e;
    s16 v;
    a[7] = t + 1;
    b[0x12] = 0;
    func_001861B0(a, b);
    a[0x169] = 0x16;
    a[0x168] = 9;
    func_001757E0(a, a[0x169], a[0x168]);
    b[0x14] = 8;
    a[0x1B5] = 0x52;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    e = (s16 *)((a[2] << 1) + (u32)D_004C2794);
    v = e[0x3E] + 1;
    e[0x3E] = v;
    func_0019DED0(a, 9, 0);
    func_0019DED0(a, 9, 2);
}
