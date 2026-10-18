typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001EDF70(u8 *p) {
    extern s32 func_0018AA50(u8 *, s32, u16 *, s32);
    extern s32 func_0018A580(u8 *);
    extern void func_00186A60(u8 *, s32);
    u16 buf;
    u8 *q;
    q = (u8 *)((s32)p + 0x2B8);
    if (func_0018AA50(p, 0x60, &buf, 1) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            p[0x1E8] = 1;
        }
    } else if ((*(u16 *)(p + 0x35E) & 0x2000) != 0) {
        return 0;
    }
    *(u16 *)q = *(u16 *)(p + 0x20E);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] == 2) {
        p[6]++;
    }
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}
