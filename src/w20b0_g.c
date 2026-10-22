typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void (*D_0043CCE0[])(u8 *);

void func_0012A420(u8 *p) {
    extern void func_003DA650(s32);
    extern void func_001489E0(s32, s32);
    extern void func_00148AA0(s32);
    extern void func_00148990();
    extern void func_00146C80(s32);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_003299D0();
    extern s32 func_001316D0();
    extern void func_00129870();
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(s32, s32, s32);
    s32 t;
    u16 m;
    t = *(s8 *)(D_004C2840 + 5);
    if (t == 0) {
        func_003DA650(0xD);
        func_003DA650(0xF);
        *(s8 *)(D_004C2840 + 5) = *(s8 *)(D_004C2840 + 5) + 1;
        *(s16 *)(D_004C2840 + 8) = 0;
        func_001489E0(0, 0);
        func_00148AA0(0);
        func_00148990();
        func_00146C80(1);
        func_003298B0(0xFF000000, 0xA, 0);
        return;
    }
    if ((s8)t == 1) {
        if (func_003299D0() == 0) {
            *(s8 *)(D_004C2840 + 5) = *(s8 *)(D_004C2840 + 5) + 1;
        }
    } else if (func_001316D0() != 0) {
        func_00129870();
    } else {
        m = (s16)func_0012ABC0(3, 0) & 0x3C00;
        if (m == 0x2000 || m == 0x1000) {
            *(s16 *)(D_004C2840 + 8) = func_0012ABA0(func_0012ABC0(3, 0), *(s16 *)(D_004C2840 + 8), 8);
        } else {
            D_0043CCE0[*(s16 *)(D_004C2840 + 8)](p);
        }
    }
}
