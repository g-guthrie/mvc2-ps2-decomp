typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C2B58;
extern u8 *D_004C2840;
extern void (*D_0043CD0C[])(s32, s32);
extern void D_0041C4B0(s32, s32);
extern void D_0041C710(s32, s32);
extern void func_0041CA00(s32, s32);

void func_0041C5B0(s32 a, s32 b) {
    u32 v;
    extern u32 func_0012ABC0(s32, s32);
    extern s32 func_0041D020(s32, s32, s32);
    extern s32 func_0041CE80(u8);
    extern void func_0012E780(s32);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_00131660();
    extern s32 func_00131720();
    extern void func_001E3CE0(s32);
    v = func_0012ABC0(3, 0) & 0xFFFF;
    if ((v & 0x90) != 0) {
        if ((v & 0x10) != 0) {
            D_004C2B58 = func_0041D020(D_004C2B58, 0, 1);
        } else {
            D_004C2B58 = func_0041D020(D_004C2B58, 0, -1);
        }
        D_004C2840[5] = func_0041CE80(D_004C2B58);
        func_0012E780(0x19);
        func_003298B0(0xFF000000, 0xA, 1);
        D_0043CD0C[0] = D_0041C4B0;
        D_0043CD0C[0](a, b);
        return;
    }
    if (func_00131660() != 0) {
        func_001E3CE0(3);
        D_0043CD0C[0] = D_0041C710;
        D_0043CD0C[0](a, b);
    } else if (func_00131720() != 0) {
        func_001E3CE0(3);
        func_003298B0(0xFF000000, 0xA, 1);
        D_0043CD0C[0] = func_0041CA00;
        D_0043CD0C[0](a, b);
    }
}
