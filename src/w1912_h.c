typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

s32 func_0019B460(u8 *p) {
    extern s32 func_0019B740();
    extern s32 func_00175670();
    extern void func_001754A0(u8 *, s32, s32);
    u8 *q = *(u8 **)(p + 0x18);
    f32 z;
    if (q[5] == 3 || (*(s8 *)(q + 0x211) & 1) == q[0x1E6]) {
        func_0019B740(p);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    z = 0.0f;
    if (p[5] == 0) {
        func_00175670();
        if (q[0x169] != 0x16) {
            func_0019B740(p);
        } else if (q[0x168] == 0xA || z == *(f32 *)(q + 0x5C)) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001754A0(p, 0x1B, 6);
        }
    } else {
        s8 r = func_00175670();
        if (r < 0) return func_0019B740(p);
    }
}
