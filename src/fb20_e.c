typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s16 h34;
    s8 b36;
    s8 b37;
    s8 b38;
    s8 b39;
    s8 b3A;
    s8 b3B;
} E3C;

extern u8 D_005852A0[];
extern u8 D_00584EA0[];
extern u8 D_005850A0[];
extern u8 D_004D1770[];
extern E3C D_00584E20[];
extern s32 D_004D17A8;
extern s32 D_004D179C;
extern s32 D_004D17AC;
extern s16 D_00584BC0[];

void func_0038A6A0(void) {
    extern void func_004180C0(s32);
    extern void func_004180D0(void);
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_00416A60(s32, s32, s32, void *);
    extern void func_0038A690(void);
    s32 j;
    s32 i;
    func_004180C0(4);
    func_004180D0();
    func_0011D8F8(D_005852A0, 0, 0xA00);
    func_0011D8F8(D_00584EA0, 0, 0x200);
    func_0011D8F8(D_005850A0, 0, 0x200);
    func_0011D8F8(D_004D1770, 0, 0x90);
    func_0011D8F8(D_00584E20, 0, 0x78);
    D_004D17A8 = 0;
    D_004D179C = -1;
    D_004D17AC = 0;
    D_00584BC0[0] = 0;
    D_00584BC0[1] = 0;
    D_00584BC0[2] = 0;
    D_00584BC0[3] = 0;
    D_00584BC0[4] = 0;
    for (i = 0; i < 0x3B; i++) {
        D_00584BC0[5 + i] = 0;
        D_00584BC0[64 + i] = 0;
        D_00584BC0[123 + i] = 0;
        D_00584BC0[182 + i] = 0;
        D_00584BC0[241 + i] = 0;
    }
    for (j = 0; j < 2; j++) {
        D_00584E20[j].w4 = 2;
        D_00584E20[j].w8 = 0xFFFF0000;
        D_00584E20[j].wC = 0x7A;
        D_00584E20[j].w14 = 0;
        D_00584E20[j].w18 = 0;
        D_00584E20[j].w1C = 0;
        D_00584E20[j].w20 = 0;
        D_00584E20[j].w24 = 0;
        D_00584E20[j].w28 = 0;
        D_00584E20[j].w2C = 0;
        D_00584E20[j].w30 = 0;
        D_00584E20[j].h34 = 0;
        D_00584E20[j].b36 = 0;
        D_00584E20[j].b37 = 0;
        D_00584E20[j].b38 = 0;
        D_00584E20[j].b39 = 0;
        D_00584E20[j].b3A = 0;
        D_00584E20[j].b3B = 0;
    }
    func_00416A60(0x7A, 0xFF, 0, func_0038A690);
}
