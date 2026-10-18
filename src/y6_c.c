typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002FC150(u8 *p) {
    extern s32 func_00189310();
    extern void func_00186A60();
    extern u8 D_0045C040[];
    if (func_00189310(p, D_0045C040, p + 0x398) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 v = *(s8 *)(p + 0x1E8);
        if (v != 0) return 0;
        p[0x1E8] = v + 1;
    }
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_00185180(u8 *p) {
    extern s32 func_00169CE0();
    extern s32 func_00185380();
    s16 v = *(s16 *)(p + 0x28C) - 1;
    *(s16 *)(p + 0x28C) = v;
    if (v <= 0) return 0;
    if (p[0x20B] & 0x80) return 0;
    if (*(s8 *)(p + 0x539) != 0) {
        if (func_00169CE0(p, 0x1F, 2) != 0) {
            p[7] = 6;
            return func_00185380(p);
        }
        *(s16 *)(p + 0x28C) = 0;
    }
    if ((*(u16 *)(p + 0x35E) & 0xC00) != 0) {
        if ((*(u16 *)(p + 0x362) & 0x120) != 0) {
            p[7] = 6;
            return func_00185380(p);
        }
    }
    return 0;
}
