typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0xA]; u8 a; u8 b; u8 pad2[0x12]; s16 h; } S294;

s32 func_00294C50(u8 *a) {
    s16 h = *(s16 *)(a + 0x2D6);
    S294 *p = (S294 *)(a + 0x2B8);
    if (h != 0) {
        if (a[0x1FD] == 5) {
            p->h = 0;
            p->b = 0;
            p->a = 0xFF;
            a[0x215] = 0;
            goto zero;
        } else {
            s16 v = h - 8;
            p->h = v;
            if (v <= 0) {
                p->h = 1;
            }
            return 1;
        }
    }
zero:
    return 0;
}

extern u8 D_0045D720[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);

s32 func_003171B0(u8 *a) {
    if (func_00189310(a, D_0045D720, a + 0x3B0) == 0) {
        return 0;
    }
    if (*(s8 *)(a + 0x2BF) != 0) {
        return 0;
    }
    func_0018A990(a, a + 0x3B0);
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    a[0x1FD] = 8;
    func_00186A60(a, 0x15);
    if (*(s8 *)(a + 0x539) == 0) {
        *(s16 *)(a + 0x2C0) = 2;
    } else {
        *(s16 *)(a + 0x2C0) = a[0x212];
    }
    return 1;
}

extern u8 D_0045A2F0[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);

s32 func_002D1800(u8 *a) {
    if (func_00189310(a, D_0045A2F0, a + 0x3B0) == 0) {
        return 0;
    }
    if (a[0x2B8] != 0) {
        return 0;
    }
    if (a[0x210] == 0) {
        s32 t = *(s8 *)(a + 0x1E8);
        if (t != 0) {
            return 0;
        }
        a[0x1E8] = t + 1;
    }
    func_0018A990(a, a + 0x3B0);
    a[0x1FD] = 9;
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    func_00186A60(a, 0x15);
    return 1;
}

extern u8 D_0045CB00[];

s32 func_00304F20(u8 *a) {
    if (func_00189310(a, D_0045CB00, a + 0x3B0) == 0) {
        return 0;
    }
    if (a[0x20D] == 2) {
        if (a[0x210] == 0) {
            s32 t = *(s8 *)(a + 0x1E8);
            if (t != 0) {
                return 0;
            }
            a[0x1E8] = t + 1;
        }
    }
    func_0018A990(a, a + 0x3B0);
    a[5] = 0;
    a[6] = 0;
    a[7] = 1;
    a[0x1FD] = 0;
    func_00186A60(a, 0x15);
    a[0x1B7] = 2;
    return 1;
}
