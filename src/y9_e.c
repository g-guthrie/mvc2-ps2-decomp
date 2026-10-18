typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C2838;
extern u32 D_004BF438[2];
extern V3 D_00444E50[];

void func_00159CD0();

void func_00159D80(V3 *a, s32 idx) {
    extern u8 *func_003DA750();
    u8 *o;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00159CD0;
        *(s16 *)(o + 0xCC) = 0x28;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *a;
        *(u32 *)(o + 0x44) = D_004BF438[idx];
        *(V3 *)(o + 0x5C) = D_00444E50[idx];
        *(u32 *)(o + 0xD0) = 0x800515;
    }
}
