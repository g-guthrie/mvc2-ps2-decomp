typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044FE70[];
s32 func_001FC380(u8 *o) {
    s32 func_00189310(); void func_0018A990(); void func_00186A60();
    if (func_00189310(o, D_0044FE70, o + 0x398) == 0) return 0;
    if (*(f32*)(o + 0x38) < 137.1428528f + *(f32*)(o + 0x430)) return 0;
    if (*(s8*)(o + 0x1E8) != 0 && o[0x210] == 0) return 0;
    o[0x1E8] = 1;
    func_0018A990(o, o + 0x398);
    o[5] = 0; o[6] = 1; o[7] = 0; o[0x1FD] = 2;
    func_00186A60(o, 0x15);
    return 1;
}
