typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0013BDC0(void);
extern u8 D_00583BC3[];

extern void func_003D7A50(void *, void *);
extern void func_003D7AD0(void *, void *);
extern void func_003D7D10(void *, void *);
void func_003D79B0(u8 *a, u8 *b) {
    u16 t = *(u16 *)(b + 0x168);
    if (t != 0x1603 && t != 0x1601 && t != 0x1602 && t != 0x161B) {
        u32 v = a[4];
        a[4] = v + 1;
        a[0x13C] = 0;
    } else {
        if (a[5] == 0) {
            func_003D7A50(a, b);
        } else {
            func_003D7AD0(a, b);
        }
        func_003D7D10(a, b);
    }
}

void func_0013BD10(void) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_0013BDC0;
        o[0x23] = D_004C2840[0x89] | D_004C2840[0x88];
        switch (o[0x23]) {
        case 1:
            o[0x20] = 1;
            o[0x21] = 2;
            o[4] = 0;
            o[5] = 0;
            break;
        case 2:
            o[0x20] = 2;
            o[0x21] = 1;
            o[4] = 0;
            o[5] = 0;
            break;
        case 3:
            o[4] = 2;
            D_00583BC3[0] = 3;
            break;
        }
    }
}

extern u8 D_0045AE80[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(void *, s32);
s32 func_002E1120(u8 *a) {
    s32 r;
    if ((r = func_00189310(a, D_0045AE80, a + 0x390)) == 0) return 0;
    if (a[0x20D] == 2 && a[0x210] == 0) {
        s8 v = a[0x1E8];
        if (v != 0) return 0;
        a[0x1E8] = v + 1;
    }
    if (*(s8 *)(a + 0x2C6) != 0) return 0;
    func_0018A990(a, a + 0x390);
    a[5] = 0;
    func_00186A60(a, 0x15);
    a[7] = 0;
    a[6] = 0;
    a[0x1FD] = 1;
    a[0x213] = 0;
    return 1;
}

extern u8 D_00458AB0[];
extern u8 D_00458B30[];
s32 func_002ABB60(u8 *a) {
    u8 *s;
    s32 r;
    if (*(s32 *)(a + 0xD0) == 0) {
        s = D_00458AB0;
    } else {
        s = D_00458B30;
    }
    if ((r = func_00189310(a, s, a + 0x380)) == 0) return 0;
    if (**(s8 **)(a + 0x420) == 0) return 0;
    func_0018A990(a, a + 0x380);
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    a[0x1FD] = s[4];
    func_00186A60(a, 0x1D);
    return 1;
}
