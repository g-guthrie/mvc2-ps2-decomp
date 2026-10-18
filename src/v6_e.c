typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00168F80(u8 *o) {
    s32 func_0016A210(); s32 func_00185DD0(); s32 func_00169CE0(); void func_00169C90();
    if (o[0x4A8] > 3) return 0;
    if (func_0016A210(o, 1) == 0) return 0;
    if (func_00185DD0(o) == 0) return 0;
    if (*(s8*)(o + 0x4B9) != 0) return 0;
    if (*(s8*)(o + 0x4B8) == 0) {
        s32 a = 3;
        if (o[0x20D] == 2) a = 4;
        if (func_00169CE0(o, a, 2) == 0) return 0;
    }
    o[0x450] = 3;
    o[0x451] = 0;
    o[0x452] = 0;
    o[0x4A8] = 3;
    func_00169C90(o);
    return 1;
}
