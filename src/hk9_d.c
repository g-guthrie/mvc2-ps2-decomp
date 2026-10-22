typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BB3D0[];
extern u8 D_004BB3F8[];
extern void func_003FB510(s32, s32, u8 *, s32, s32);
extern void func_003FB128(u8 *);
extern void func_003FD138(u8 *);

s32 func_003FD308(u8 *p, s32 a, s32 b) {
    s32 v;
    s32 t;
    s32 v3;
    func_003FB510(6, 0, p, a, b);
    if (p == 0) {
        func_003FB128(D_004BB3D0);
        return -3;
    }
    v = *(s8 *)(p + 1);
    if (v == 2) {
        func_003FD138(p);
    }
    if (b == 0) {
        *(s32 *)(p + 0x14) = a;
    } else if (b == 1) {
        *(s32 *)(p + 0x14) = *(s32 *)(p + 0x14) + a;
    } else if (b == 2) {
        *(s32 *)(p + 0x14) = *(s32 *)(p + 0xC) + a;
    } else {
        func_003FB128(D_004BB3F8);
        return -3;
    }
    t = *(s32 *)(p + 0x14);
    if (t < 0) {
        *(s32 *)(p + 0x14) = 0;
    } else {
        v3 = *(s32 *)(p + 0xC);
        if (v3 < t) {
            *(s32 *)(p + 0x14) = v3;
        }
    }
    func_003FB510(6, 1, p, a, b);
    return *(s32 *)(p + 0x14);
}
