typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[4];
    s8 b4;
    s8 b5;
    s8 b6;
    s8 b7;
    u8 pad8[6];
    s16 hE;
} G2840;

extern G2840 *D_004C2840;
extern s8 D_004C2604;
extern void func_0012D950();
extern void func_0012DA00();

void func_0012D830(void)
{
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_003299D0();
    extern s8 func_0012ABB0(u16, s8, s32);
    extern void func_00129060(s32, void (*)());
    extern s32 func_001316D0();
    extern void func_003298B0(u32, s32, s32);
    u16 id;
    s32 v;

    if (D_004C2840->b4 == 2) { v = 0x35; } else { v = 0x11; }
    id = func_0012ABC0(3, 0);
    if (func_003299D0() != 0) {
        return;
    }
    if (D_004C2840->b7 == 0) {
        D_004C2604 = func_0012ABB0(id, D_004C2840->b6, v);
        if (D_004C2840->b6 != D_004C2604) {
            if (D_004C2840->b6 >= D_004C2604) { D_004C2840->b7 = 1; } else { D_004C2840->b7 = 2; }
            D_004C2840->hE = 0xB;
            D_004C2840->b5 = 2;
            func_00129060(8, func_0012D950);
        }
    }
    switch (func_001316D0()) { case 0: break; default: {
        D_004C2840->b5 = 3;
        func_003298B0(0xFF000000, 10, 1);
        func_00129060(8, func_0012DA00);
    } }
}
