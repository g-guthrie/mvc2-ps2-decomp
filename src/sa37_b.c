typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct SA37_S {
    u8 pad0[2];
    s8 b2, b3, b4, b5, b6, b7;
    u8 pad8[0x4C - 8];
    s8 b4c;
    u8 pad4d[0x50 - 0x4D];
    s8 b50;
    u8 pad51[0x85 - 0x51];
    s8 b85;
    u8 pad86[0x88 - 0x86];
    s8 b88, b89;
    u8 pad8a[0x9E - 0x8A];
    s8 b9e;
    u8 pad9f[0xA9 - 0x9F];
    s8 ba9;
    u8 padaa[0xB4 - 0xAA];
    s8 bb4;
} SA37_S;

extern SA37_S *volatile D_004C2840;
extern u8 D_004F203A[];

void func_003D2B70(void) {
    extern void func_003D6D50(void);
    extern void func_003D6E20(void);
    extern void func_00122840(s32);
    extern void func_003D7DF0(void);
    extern void func_00170F60(void);
    extern void func_003D35C0(void);
    extern void func_00131340(s32);
    SA37_S *g;
    D_004C2840->b2 = 1;
    D_004C2840->b3 = 0;
    D_004C2840->b4 = 0;
    D_004C2840->b5 = 0;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->b9e = 1;
    D_004C2840->b50 = 0;
    g = D_004C2840;
    g->ba9 = g->b89;
    D_004C2840->b85 = 0;
    g = D_004C2840;
    if ((g->b89 | g->b88) != 3) {
        g->b85 = *(s8 *)(D_004F203A + g->b89 * 0x5B8);
    }
    func_003D6D50();
    func_003D6E20();
    func_00122840(0);
    func_003D7DF0();
    func_00170F60();
    D_004C2840->bb4 = 0;
    func_003D35C0();
    g = D_004C2840;
    switch (g->b4c) {
    case 0:
    case 2:
        break;
    case 1:
    case 7:
        func_00131340(100);
        break;
    case 5:
        g->bb4 = 1;
        break;
    default:
        break;
    }
}
