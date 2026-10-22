typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045A980[];

s32 func_002D92E0(u8 *p) {
    extern s32 func_0018AA50(u8 *, s32, u16 *, s32);
    extern void func_0018A990(u8 *, void *);
    extern s32 func_0018A7A0(u8 *);
    extern s32 func_0018A580(u8 *);
    extern void func_00186A60(u8 *, s32);
    u16 v;
    s32 t;
    if (func_0018AA50(p, 0x140, &v, 4) == 0) return 0;
    func_0018A990(p, &v);
    if (*(f32 *)(p + 0x38) < 68.57142639160156f + *(f32 *)(p + 0x430)) {
        if (*(u16 *)(p + 0x35E) & 0x1000) return 0;
    }
    if (p[0x1E4] == 0x15 && p[0x1FD] == 4) {
        if (*(s32 *)(p + 0x2C0) != 0) return 0;
        if (*(s32 *)(p + 0x2BC) == 0) return 0;
        if (func_0018A7A0(p) == 0) return 0;
        if (*(s8 *)(p + 0x1B2) & 0x11) return 0;
        *(s32 *)(p + 0x2F4) = 1;
        *(s32 *)(p + 0x2BC) = *(s32 *)(p + 0x2BC) - 1;
    } else {
        if (p[0x20D] == 2 && *(s8 *)(p + 0x1E8) != 0) return 0;
        if (func_0018A580(p) == 0) return 0;
        if (*(s8 *)(p + 0x539) != 0) {
            t = *(u16 *)(p + 0x20E);
            v = t >> 10;
            if (p[0x1E6] != 0) {
                v = (u32)v & 0xF;
                v = D_0045A980[v];
            }
            *(s32 *)(p + 0x2FC) = v;
        }
        *(s32 *)(p + 0x2F4) = 0;
        *(s32 *)(p + 0x2BC) = 2;
        *(s32 *)(p + 0x2C8) = 1;
        p[0x215] = 0;
    }
    p[0x1B7] = 0;
    *(s8 *)(p + 0x1E8) += 1;
    *(s32 *)(p + 0x2C0) = 0x10;
    p[0x1FD] = 4;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
