typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 a[6]; } S24;
typedef unsigned long long u64;
typedef struct { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; } FP;
typedef struct E18 { s32 a0; s32 a1; s32 **a2; s32 a3; s32 a4; s32 a5; } E18;

void func_003FDC70(void)
{
    extern s32 D_004C22D4, D_004C2394, D_004C2398;
    extern volatile s32 D_004C2320;
    extern s32 D_0047D0E0[];
    extern s32 func_00103CD0();
    extern s32 func_00103C70();
    extern void func_003FE190();
    s32 h;
    if (D_004C22D4 == 0) {
        h = func_00103CD0();
        D_004C2394 = func_00103C70(h, D_0047D0E0[0]);
        D_004C2398 = h;
        func_003FE190(D_004C2320);
        { register s32 j __asm__("$3"); j = D_004C2320; }
    }
    D_004C22D4++;
}

void func_003FDAA0(void)
{
    extern s32 D_004C22B4, D_004C22C0, D_004C22BC;
    extern volatile s32 D_004C22C4;
    extern volatile s32 D_004C22B0;
    extern s8 D_0047C620[];
    extern void func_003F9628(), func_003F9630(), func_0040FD38(), func_0040F550(), func_0040F030();
    extern void func_003FB0A8(), func_004000F8(), func_003FF358(), func_003FB398(), func_003FF098();
    extern void func_00411B98(), func_0011D8F8(), func_0040D638(), func_003F9660();
    extern void func_00411720();
    extern s32 func_004115E0();
    extern void func_003FDA60(), func_003FDA80(), func_003FDA00();
    D_004C22B0;
    if (D_004C22B4 == 0) {
        func_003F9628();
        func_003F9630();
        func_0040FD38();
        func_0040F550();
        func_0040F030();
        func_003FB0A8();
        func_004000F8();
        func_003FF358();
        func_003FB398();
        func_003FF098();
        func_00411B98();
        func_0011D8F8(D_0047C620, 0, 0xAC0);
        func_0040D638();
        if (D_004C22C0 == 1) {
            func_00411720(2, 1, func_003FDA60, 0);
            func_00411720(2, 3, func_003FDA80, 0);
            D_004C22BC = func_004115E0(4, func_003FDA00, 0);
        }
        D_004C22C4 = 0;
        func_003F9660();
    }
    D_004C22B4++;
}
