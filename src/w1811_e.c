typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C22D8;
extern s32 D_0047D0E0[];
extern u8 D_004BB618[];

void func_003FDD28(s32 a, s32 b) {
    extern void func_00103C70(s32, s32);
    extern void func_003FE120(s32);
    extern s32 func_003FE190(s32);
    extern void func_00411380();
    extern s32 func_003FE1F8(s32);
    s32 i;
    register s32 f __asm__("$3");
    register s32 one __asm__("$3");
    if (a != 0) {
        one = 1;
        D_004C22D8 = one;
        func_00103C70(a, D_0047D0E0[0]);
        i = 0;
        while (i <= 0xBEBC1FF) {
            func_003FE120(a);
            func_003FE190(a);
            f = D_004C22D8;
            if (f == 0) break;
            i++;
        }
        if (i == 0xBEBC200) {
            func_00411380(D_004BB618);
        }
        func_00103C70(a, b);
        func_003FE1F8(a);
    }
}
