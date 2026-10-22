typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_001DEEF0(u8 *p, u8 *unused) {
    s16 *q = (s16 *)(p + 0xD8);
    s16 a = q[0];
    if (*(s16 *)(p + 0x140) == 0) a = -a;
    *(float *)(p + 0x34) = (float)(a + q[1]);
}

void func_001DF110(u8 *p, u8 *q) {
    extern void func_001DEE30(u8 *, u8 *);
    extern void func_001DEF30(u8 *, u8 *);
    s32 v;
    func_001DEE30(p, q);
    func_001DEEF0(p, q);
    func_001DEF30(p, q);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        u32 t;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(s16 *)(p + 0x1C) = 0x10;
        t = p[5];
        p[5] = t + 1;
    }
}
