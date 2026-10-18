typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0018A460();

u8 func_0018A310(s32 a, s32 b, s8 *c) {
    s8 v = c[1] - 1;
    c[1] = v;
    if (v == 0) {
        return *(u8 *)c = 0;
    }
    if (func_0018A460() == 0) {
        return 0;
    }
    c[0] = 0;
    return 1;
}

extern void func_001B3D90(u8 *q, u8 *p);
extern void func_00175670(u8 *p);

void func_001B3810(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0x13C] = 0;
    } else {
        func_001B3D90(q, p);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -1;
        func_00175670(p);
    }
}
