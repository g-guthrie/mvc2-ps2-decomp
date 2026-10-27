typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 D_004C2478;
extern s32 D_004C247C;
extern s32 D_004C2490;
extern s32 D_004C2494;
extern s32 D_004C2498;
extern s32 D_004C249C;
extern s32 D_004C24A8;
extern s32 D_004C24AC;
extern s32 D_004C24B0;
extern s32 D_004C24B4;
extern s32 D_004C24B8;
extern s32 D_004C24BC;
extern u8 D_0048FFF8[];
extern char D_004BE560[];
extern char D_004BE698[];
extern char D_004BE6E0[];
extern char D_004BE710[];
extern char D_004BE738[];

void func_0040E288(void)
{
    extern void func_00410B88(void);
    extern void func_00410F80(void);
    extern void func_004095C8(void);
    extern void func_0040DBB0(void);
    extern void func_0011D8F8(void *, s32, s32);
    extern s32 func_0010ACD0(s32);
    extern void func_0011EB60(char *, ...);
    extern s32 func_00409250(s32, s32, s32, s32);
    extern void func_00409450(s32, void *, s32);
    extern void func_00409460(u8 *, void (*)(void *, u8 *, s32), void *);
    extern void func_00409708(s32, void *, s32, s32, s32);
    extern void func_0040DFA8(void);
    extern void func_0040E008(void *, u8 *, s32);
    u32 s0;
    s32 v[3];

    (void)D_004C2478;
    if (D_004C24A8 == 0) {
        func_00410B88();
        func_00410F80();
        func_004095C8();
        func_0040DBB0();
        s0 = (u32)D_0048FFF8;
        func_0011D8F8((void *)s0, 0, 0x8D0);
        s0 += 0x40;
        D_004C24BC = 0x880;
        D_004C24AC = s0 & -0x40;
        if (D_004C24B0 == 0) {
            D_004C24B0 = func_0010ACD0(0x8D0);
            if (D_004C24B0 == 0) {
                func_0011EB60(D_004BE698, 0x8D0);
                func_0011EB60(D_004BE6E0);
                for (;;) {}
            }
        }
        func_0011EB60(D_004BE560, 0x8D0, D_004C24B0);
        { register s32 t __asm__("$3"); t = D_004C24B0; t += 0x40; t &= -0x40; D_004C24B4 = t;
        D_004C24B8 = func_00409250(1, D_004C24AC, t, D_004C24BC); }
        if (D_004C24B8 == 0) {
            func_0011EB60(D_004BE710);
            for (;;) {}
        }
        func_00409450(D_004C24B8, func_0040DFA8, 0);
        func_00409460((u8 *)D_004C24B8, func_0040E008, 0);
        if (D_004C2494 == 0) {
            D_004C249C = D_004C247C;
            D_004C2490 = (D_004C247C << 10) + 0x40;
            D_004C2494 = func_0010ACD0(D_004C2490);
            if (D_004C2494 == 0) {
                func_0011EB60(D_004BE738, D_004C2490);
                for (;;) {}
            }
            func_0011EB60(D_004BE560, D_004C2490, D_004C2494);
        }
        D_004C2498 = (D_004C2494 + 0x3F) & -0x40;
        v[0] = D_004C249C;
        v[1] = D_004C2498;
        v[2] = D_004C2490;
        func_00409708(0xA, v, 3, 0, 0);
    }
    D_004C24A8++;
}
