/* Ordinary initialized actor direction at +0x1E6 is 0 or 1. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
extern s32 func_0018AA50(u8 *, u16, s16 *, s32);
extern s32 func_0018A580(u8 *);
extern void func_00186A60(u8 *, s32);
/* Native 32-byte action lookup read view; no DATA ownership claimed. */
extern u8 D_0045DA10[32];
s32 func_0031B480(u8 *p) {
    s16 input;
    s32 action;
    if (p[0x2B8] != 0) return 0;
    if (func_0018AA50(p, 0x140, &input, 1) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if ((s8)p[0x539] != 0) {
        input = *(u16 *)(p + 0x20E);
        if (p[0x1E6] != 0 && ((u16)input & 0x0C00) != 0)
            input = (s16)((u16)input ^ 0x0C00);
    } else {
        input = *(u16 *)(p + 0x354);
    }
    input = (s16)(((u16)input & 0x3C00) >> 10);
    if ((u16)input == 0)
        input = 2 - p[0x1E6];
    if (p[0x20D] == 2)
        { u16 code = (u16)input; code += 0x10; input = (s16)code; }
    action = D_0045DA10[(u16)input];
    if (action == 0) return 0;
    action -= 1;
    if (p[0x20D] != 2 && ((u16)input & (1u << p[0x1E6])) != 0)
        return 0;
    p[0x22] = action;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1B7] = 1;
    p[0x1FD] = 1;
    func_00186A60(p, 21);
    return 1;
}
