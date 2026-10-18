typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001EDE70(u8 *p) {
    extern s32 func_0018AA50();
    extern s32 func_0018A580();
    extern void func_00186A60();
    s16 loc;
    u16 *q;
    q = (u16 *)(p + 0x2B8);
    if (func_0018AA50(p, 0x300, &loc, 0) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            p[0x1E8] = 1;
        }
    } else if ((*(u16 *)(p + 0x35E) & 0x2000) != 0) {
        return 0;
    }
    *q = *(u16 *)(p + 0x20E);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] == 2) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
