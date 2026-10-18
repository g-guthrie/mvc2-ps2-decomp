typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_003F89D8(u8 *p, s32 x, s16 *o2, s8 *a3, s8 *t0, s8 *t1, s8 *t2, s32 *t3, s32 *t6, s32 *t5, s16 *a1) {
    *o2 = p[7] << 4;
    *t2 = (p[9] & 3) + 1;
    *t3 = *(u16 *)(p + 0x2A);
    switch (p[8]) {
    case 0:
        *t0 = 0x10;
        { s32 v = *t2; *t1 = v << 1; }
        *t5 = 1;
        *a1 = 0;
        *t6 = *(s32 *)(p + 0xC) / 2;
        break;
    case 1:
        *t0 = 8;
        { s32 v = *t2; *t1 = v; }
        *t5 = 1;
        *a1 = 1;
        *t6 = *(s32 *)(p + 0xC);
        break;
    case 2:
    case 3:
        *t0 = 4;
        { s32 v = *t2; *t1 = v; }
        *t5 = 2;
        *a1 = 2;
        *t6 = *(s32 *)(p + 0xC) << 1;
        break;
    }
    *t1 = 2;
    *t5 = 1;
    *t6 = *(s32 *)(p + 0xC) / 2;
    *t0 = 0x10;
    *a3 = -1;
    return 0;
}

typedef struct { u8 pad[0x60]; s32 (*fn)(s32 *, s32, s32, s32); } O27;
extern u8 D_004BD290[], D_004BD2B8[], D_004BD2E0[], D_004BD308[];
s32 func_00407770(s32 a, s32 b, s32 c) {
    extern void func_00405DC8(u8 *);
    extern O27 *func_00406128(s32);
    extern void func_0011D8F8(void *, s32, s32);
    O27 *o;
    s32 buf[5];
    if (a == 0) {
        func_00405DC8(D_004BD290);
        return -1;
    }
    if (b == 0) {
        func_00405DC8(D_004BD2B8);
        return -1;
    }
    if (c == 0) {
        func_00405DC8(D_004BD2E0);
        return -1;
    }
    o = func_00406128(a);
    if (o == 0) {
        func_00405DC8(D_004BD308);
        return -1;
    }
    func_0011D8F8(buf, 0, 0x14);
    buf[0] = c;
    buf[1] = b;
    if (o->fn != 0) return o->fn(buf, 2, 0, 0);
    return -1;
}
