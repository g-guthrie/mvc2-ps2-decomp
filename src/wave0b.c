typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004C21E8[8];
extern u8 D_004D1926[16];
extern u8 D_004D18E0[16];
extern u8 D_004D18A0[];
extern void func_003D92D0();
extern u8 D_004C1840[8];
extern u8 D_004C1841[8];
extern void func_00186A60();
extern u16 D_004C2784, D_004C2788, D_004C278C, D_004C2790;
extern void func_00131AE0();
extern void func_00133390();
extern void func_00133720();
extern void func_00134C10();
extern void func_00131990();
extern void func_00136110();
extern void func_003DAA40();
extern void func_003BD830();
extern void (*D_004C20B8[2])();
extern void (*D_004C1E78[2])();
extern void func_0039E450();
extern s8 func_00175700();
extern u8 *D_004C2954;
extern void func_00350FD0();
extern void func_001E7F60();

void func_003D91B0(void) {
    u8 v = D_004C21E8[(s8)D_004C2840[0x4D]];
    D_004D1926[0] = v;
    D_004D18E0[0] = v;
    func_003D92D0(D_004D18A0);
}



void func_00128330(void) {
    D_004C2784 = 0;
    D_004C2788 = 0;
    D_004C278C = 0;
    D_004C2790 = 0;
    func_00131AE0();
    func_00133390();
    func_00133720();
    func_00134C10();
    func_00131990();
}

void func_001360C0(u8 *p) {
    p[0x13C] = 0;
    if (p[0x20] == 3) func_00136110(*(s8 *)(D_004C2840 + 0x8F));
    func_003DAA40(p);
}

void func_003BC820(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x25C)) func_003BD830();
    else D_004C20B8[p[4]]();
}

void func_0039CB00(u8 *p) {
    if (*(u16 *)(*(u8 **)(p + 0x18) + 0x168) != *(u16 *)(p + 0x88)) func_0039E450();
    else D_004C1E78[p[4]]();
}

void func_00350AC0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        D_004C2954[3] = 0;
        func_00350FD0(p);
    } else {
        func_001E7F60(p);
    }
}
