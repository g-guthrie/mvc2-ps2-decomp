typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0;
    s8 b1;
    s8 b2;
    u8 pad3[0x11];
    s32 w14;
    u8 pad18[2];
    s8 b1a;
    u8 pad1b[0x0F];
    s8 b2a;
    u8 pad2b[0x1F];
    s8 b4a;
    u8 pad4b[3];
    s8 b4e;
    u8 pad4f[10];
    s8 b59;
    u8 pad5a[0x37];
    s8 b91;
} G16;
extern G16 *D_004C2840;
extern s32 D_004C2874;
extern s8 D_004C2A2C;
extern s8 D_004C2A30;
extern u8 D_004F4384[];
extern u8 D_004D18A0[];

void func_003D16E0(void) {
    extern void func_003D6AC0();
    extern void func_003D35C0();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_0011D8F8();
    extern void func_003DA410();
    extern void func_001E2130();
    extern void func_00127C10();
    s8 v;
    s8 t;
    D_004C2874 = 0;
    D_004C2840->b1 = D_004C2840->b1 + 1;
    D_004C2840->w14 = 0x40;
    D_004C2840->b1a = 0;
    D_004C2840->b91 = 0;
    func_003D6AC0();
    v = D_004C2840->b59;
    if (v >= 0) {
        if ((u32)v <= 2 || v == 7) {
            D_004C2840->b1 = 10;
            D_004C2840->b2 = 0;
        }
    } else {
        t = D_004C2840->b4e;
        if (t != 0) {
            D_004C2840->b1 = t;
            D_004C2840->b4e = 0;
        }
    }
    D_004C2A30 = 1;
    D_004C2A2C = 0x14;
    D_004C2840->b2a = 0;
    D_004C2840->b4a = 0;
    func_003D35C0();
    func_003D6D50();
    func_003D6E20();
    func_0011D8F8(D_004F4384, 0, 0x80);
    func_0011D8F8(D_004D18A0, 0, 0xC0);
    func_003DA410();
    func_001E2130();
    func_00127C10();
}
