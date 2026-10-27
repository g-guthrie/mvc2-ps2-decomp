typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5C]; s8 b5C; } Z170;

extern s32 D_004C2B30;
extern s32 D_004C2B34;
extern volatile s32 D_004C28AC;
extern volatile s32 D_004C28B0;
extern s32 D_004C28B4;
extern volatile s32 D_004C28B8;
extern s32 D_004C2810, D_004C2814, D_004C2818, D_004C2824, D_004C282C;
extern s32 D_004C2834, D_004C2838;
extern s32 D_004C27D8, D_004C27DC, D_004C27E0, D_004C27E4, D_004C27E8;
extern s32 D_004C27F0, D_004C27F4, D_004C27F8, D_004C27FC, D_004C2804, D_004C2808;
extern u8 D_004C27D0;
extern Z170 *D_004C2840;
extern s32 D_00446860[];
extern s32 D_00446810[];

void func_00170170(s32 a, s32 b)
{
    extern void func_003DF850(s32, s32);
    extern void func_0012DA40(s32, s32, s32);
    extern void func_0016F430(s32, s32);
    extern void func_0016F5B0(s32, s32, s32, s32, s32, s32);
    extern void func_0016F530(s32, s32, s32, s32, s32, s32);
    extern void func_00176230(s16 *, s16 *);
    extern void memcpy(s32, s32, s32);
    extern void func_0016FAA0(void);
    extern void func_00170B30(s32);
    extern void func_0016F640(void);
    extern void func_0016FC80(void);
    extern void func_0016F7D0(void);
    extern void func_0016FF20(void);
    extern void func_0016F810(void);
    extern void func_0016FD80(void);
    extern void func_0016F8A0(void);
    extern void func_0016FFC0(void);
    extern void func_0016FA00(void);
    extern void func_0016FA10(void);
    extern void func_00170140(void);
    extern void func_003D3080(s32);
    extern void func_0012DBE0(void);
    extern void func_0012E6B0(void);
    extern void func_0012E780(s32);
    s32 A0, A1, A2, A3, A4;
    D_004C2B34 = 0;
    D_004C2B30 = 0;
    func_003DF850(1, 0);
    func_003DF850(2, 0);
    switch (a) {
    case 1:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0012DA40(D_00446860[b], D_004C28AC, 2);
        func_0012DA40(D_00446810[b], D_004C28B8, 2);
        A1 = D_004C28B8;
        A0 = D_004C28AC;
        func_0016F430(A0, A1);
        if (b == 3 || b == 12) {
            func_0012DA40(0x3CC, D_004C28AC + 0x41000, 2);
        }
        break;
    case 2:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0012DA40(0x31F, D_004C28AC + 0x61000, 2);
        func_0012DA40(0x320, D_004C28B8, 2);
        A1 = D_004C28B0;
        A0 = D_004C28B8;
        func_00176230((s16 *)A0, (s16 *)A1);
        A2 = D_004C28AC + 0x61000;
        A0 = 0xC50;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2838;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 4:
        A1 = D_004C28B8;
        A0 = D_004C28AC;
        memcpy(A0, A1 + 0x170000, 0x3A000);
        func_0012DA40(0x344, D_004C28B8, 2);
        func_0016FAA0();
        func_00170B30(D_004C2834);
        break;
    case 5:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0016F640();
        func_0016FC80();
        break;
    case 6:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0016F7D0();
        func_0016FF20();
        break;
    case 8:
        A2 = D_004C28B4 + 0x4500;
        A0 = 0xD10;
        A3 = D_004C28B4;
        A4 = 6;
        A1 = D_004C2824;
        func_0016F530(A0, A1, A2, A3, A4, 0);
        break;
    case 9:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0016F810();
        func_0016FD80();
        break;
    case 10:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0016F8A0();
        func_0016FFC0();
        break;
    case 11:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0012DA40(0x34F, D_004C28AC, 2);
        func_0012DA40(0x350, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x810;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2818;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        func_0012DA40(0x3D3, D_004C28AC, 2);
        func_0012DA40(0x3D4, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x950;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27D8;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 12:
        D_004C2B34 = 5;
        D_004C2B30 = 1;
        func_003DF850(1, 1);
        A1 = D_004C28B8;
        A0 = D_004C28AC;
        memcpy(A0, A1 + 0x110000, 0x60000);
        A2 = D_004C28AC;
        A0 = 0x810;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2814;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        func_0016FA00();
        break;
    case 13:
        A1 = D_004C28B8;
        A0 = D_004C28AC;
        memcpy(A0, A1 + 0x51000, 0x29000);
        func_003DF850(1, 1);
        A2 = D_004C28AC;
        A0 = 0x810;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2810;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 14:
        func_0016FA10();
        func_00170140();
        break;
    case 15:
        func_003DF850(1, 1);
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0012DA40(0x357, D_004C28AC + 0x61000, 2);
        func_0012DA40(0x358, D_004C28B8, 2);
        A2 = D_004C28AC + 0x61000;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2808;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 16:
        if (D_004C2840->b5C != 0) {
            func_003D3080(0);
        }
        func_0012DBE0();
        func_0012DA40(0x35E, D_004C28AC, 2);
        func_0012DA40(0x35F, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2804;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        func_0012E6B0();
        func_0012E780(8);
        break;
    case 18:
        func_0012DA40(0x362, D_004C28AC, 2);
        func_0012DA40(0x363, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27FC;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 19:
        func_0012DA40(0x364, D_004C28AC, 2);
        func_0012DA40(0x365, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27F8;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 20:
        func_0012DA40(0x366, D_004C28AC, 2);
        func_0012DA40(0x367, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27F4;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 21:
        func_0012DA40(0x368, D_004C28AC, 2);
        func_0012DA40(0x369, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x850;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27F0;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 23:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_0012DA40(D_00446860[D_004C27D0], D_004C28AC, 2);
        A1 = D_004C28B8;
        A0 = D_004C28AC;
        func_0016F430(A0, A1);
        if (b == 3 || b == 12) {
            func_0012DA40(0x3CC, D_004C28AC + 0x41000, 2);
        }
        break;
    case 24:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        func_00176230((s16 *)(D_004C28B8 + 0x18A000), (s16 *)D_004C28B0);
        A2 = D_004C28AC + 0x61000;
        A0 = 0xC50;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2838;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 25:
        D_004C2B34 = 4;
        D_004C2B30 = 1;
        memcpy(D_004C28AC, D_004C28B8 + 0x100000, 0x61000);
        A2 = D_004C28AC;
        A0 = 0x810;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C2818;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        func_0012DA40(0x3D3, D_004C28AC, 2);
        func_0012DA40(0x3D4, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x950;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27D8;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 27:
        func_0012DA40(0x37D, D_004C28AC, 2);
        func_0012DA40(0x37E, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x910;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27E8;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 28:
        func_0012DA40(0x37F, D_004C28AC, 2);
        func_0012DA40(0x380, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x910;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27E4;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 29:
        func_0012DA40(0x381, D_004C28AC, 2);
        func_0012DA40(0x382, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x910;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27E0;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 30:
        func_0012DA40(0x383, D_004C28AC, 2);
        func_0012DA40(0x384, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0xC90;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2834;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 31:
        func_0012DA40(0x385, D_004C28AC, 2);
        func_0012DA40(0x386, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0xC90;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2834;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 32:
        func_0012DA40(0x387, D_004C28AC, 2);
        func_0012DA40(0x388, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0xC90;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2834;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 33:
        func_0012DA40(0x389, D_004C28AC, 2);
        func_0012DA40(0x38A, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0xC90;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C2834;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 35:
        func_0012DA40(0x38D, D_004C28AC, 2);
        func_0012DA40(0x38E, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0x910;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C282C;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 36:
        func_0012DA40(0x38F, D_004C28AC, 2);
        func_0012DA40(0x390, D_004C28B0, 2);
        A2 = D_004C28AC;
        A0 = 0x910;
        A3 = D_004C28B0;
        A4 = 6;
        A1 = D_004C282C;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    case 37:
        func_0012DA40(0x3CD, D_004C28AC, 2);
        func_0012DA40(0x3CE, D_004C28B8, 2);
        A2 = D_004C28AC;
        A0 = 0x950;
        A3 = D_004C28B8;
        A4 = 6;
        A1 = D_004C27DC;
        func_0016F5B0(A0, A1, A2, A3, A4, 0);
        break;
    }
}
