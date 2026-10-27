typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[5]; u8 b5; u8 b6; } A;
typedef struct { u8 p0[5]; u8 b5; } B;
extern A *D_004C2B6C;
extern B *D_004C2840;
extern u8 D_004C2B58;
extern void (*D_0043CD0C[])(s32, s32);
void func_0041C2F0(s32 a, s32 b) {
    extern s32 func_00131660();
    extern s32 func_00131720();
    extern s32 func_0041CB30();
    extern void func_001E3CE0(s32);
    extern s32 func_0041CE80(u8);
    extern void func_0012E780(s32);
    extern void func_003298B0(s32, s32, s32);
    extern void D_0041C400(s32, s32);
    extern void D_0041C4B0(s32, s32);
    s32 v;
    if (func_00131660() != 0) {
        if (D_004C2B6C->b5 != 0) {
            D_0043CD0C[0] = D_0041C400;
            D_0043CD0C[0](a, (u16)b);
            return;
        }
        if (func_0041CB30() == 0) {
            func_001E3CE0(2);
            D_004C2B58 = D_004C2B6C->b6;
            v = func_0041CE80(D_004C2B58);
            D_004C2840->b5 = v;
            func_0012E780(0x19);
            func_003298B0(0xFF000000, 10, 1);
            D_0043CD0C[0] = D_0041C4B0;
        }
    } else if (func_00131720() != 0) {
        D_0043CD0C[0] = D_0041C400;
        D_0043CD0C[0](a, (u16)b);
    }
}
