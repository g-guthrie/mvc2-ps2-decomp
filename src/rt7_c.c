typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 p0[4]; s8 b4; s8 b5; u8 p6[0x7F]; s8 b85; } SP32;
extern SP32 *D_004C2840;
extern s8 D_00583BC7[];
extern u8 D_00583B90[];
void func_0032CD40(void) {
    extern s32 func_0032C180(s32);
    extern void func_001382F0();
    extern void func_00138280();
    s32 t = D_004C2840->b5;
    s8 *q = &D_004C2840->b5;
    switch (t) {
    case 0:
        *q = t + 1;
        if (func_0032C180(1) != 0) {
            D_004C2840->b5 = 0;
        } else if (D_004C2840->b85 == 7) {
            func_001382F0((u8)D_00583BC7[0]);
        } else {
            func_00138280((u8)D_00583BC7[0], 1);
        }
    break;
    case 1:
        if (func_0032C180(1) == 0) {
            if (D_00583B90[D_00583BC7[0]] == 0) {
                D_004C2840->b4 += 1;
                D_004C2840->b5 = 0;
            }
        }
    break;
    }
}
