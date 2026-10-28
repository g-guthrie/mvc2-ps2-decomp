typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[5]; s8 f5; u8 pad6[2]; s16 f8; u8 padA[4]; s16 fe; u8 pad10[0x60]; u8 f70; } GB;
extern GB *D_004C2840;
extern f32 D_004C25EC;
extern f32 D_004C25E8;
extern s32 D_004C25E4;

void func_0012A6E0(u8 *p) {
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(s32, s32, s32);
    extern void func_003DA650(s32);
    extern void func_00147580();
    extern void func_0012FCC0();
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_003299D0();
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern void func_0012F710(s32);
    extern void func_0012A590(u8 *);
    extern void func_00129870(s32);
    s32 r;
    s16 v;
    s8 *q;
    r = (u16)func_0012ABC0(3, 0);
    q = &D_004C2840->f5;
    switch (*q) {
    case 0:
        func_003DA650(0xD);
        func_003DA650(0xF);
        D_004C2840->f5++;
        D_004C2840->fe = 0;
        D_004C2840->f70 = 0;
        D_004C2840->f8 = 0;
        D_004C25EC = *(f32 *)(p + 0x10);
        D_004C25E8 = *(f32 *)(p + 0x14);
        D_004C25E4 = *(s32 *)(p + 0x18);
        func_00147580();
        func_0012FCC0();
        func_003298B0(0xFF000000, 10, 0);
        break;
    case 1:
        if (func_003299D0() == 0) {
            v = D_004C2840->fe + 1;
            D_004C2840->fe = v;
            if (v >= 8) {
                D_004C2840->f5++;
                D_004C2840->fe = 8;
            }
        }
        break;
    case 2:
        D_004C2840->f8 = func_0012ABA0(r, D_004C2840->f8, 2);
        if (func_001315F0() != 0) {
            D_004C2840->f5 = 3;
        } else if (func_001316D0() != 0) {
            D_004C2840->f5 = 4;
        }
        break;
    case 3:
        if (D_004C2840->f8 == 2) {
            *q = 4;
        } else if (D_004C2840->f8 == 1) {
            *q = 2;
            func_0012F710(4);
        } else if (func_001316D0() != 0) {
            D_004C2840->f5 = 2;
        } else if (D_004C2840->f8 == 0) {
            func_0012A590(p);
        }
        break;
    case 4:
        func_00129870(r);
        break;
    }
}
