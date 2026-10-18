typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s16 D_00460620[];
extern V3 D_00460640[][4];
extern s32 D_004606A0[][4];
extern s32 D_004C283C;

void func_003422F0(s32 idx)
{
    extern u8 *func_003DA750();
    extern void func_003423E0();
    extern s32 func_00417A40();
    u8 *o;
    s32 k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_003423E0;
        *(s32 *)(o + 0xD0) = 0x805;
        k = func_00417A40() % 4;
        *(s16 *)(o + 0xCC) = D_00460620[0];
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_00460640[idx][k];
        *(s32 *)(o + 0x44) = D_004606A0[idx][k];
        o[0x20] = idx;
    }
}
