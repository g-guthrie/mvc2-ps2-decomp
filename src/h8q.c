typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern s16 D_00449230[];
extern void func_001917F0();
void func_00191770(s32 a0, u8 *a1) {
    s32 i;
    if (*(s8 *)(D_004C2840 + 0x88) != 3) {
        i = a1[0] / 5;
        if (i > 10) i = 10;
        func_001917F0(a0, 0, D_00449230[i]);
    }
}
