typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003AFCE0(u8 *p, u8 *q) {
    extern s32 fptosi(f32);
    extern void func_00174910(u8 *, s32);
    extern s32 func_00175700(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    s16 *s;
    u8 *t;
    t = q + 0x2B8;
    s = (s16 *)(p + 0xD0);
    if (t[p[0x21]] == 0) {
        p[4] = 3;
        return;
    }
    if (q[5] != 0) {
        p[4] = 3;
        t[p[0x21]] = 0;
        return;
    }
    s[0] = fptosi(*(f32 *)(q + 0x34));
    s[1] = fptosi(137.14285278320312f + *(f32 *)(q + 0x38));
    *(f32 *)(p + 0x34) = s[0];
    *(f32 *)(p + 0x38) = s[1];
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00174910(p, 0x1900);
    if ((s8)func_00175700(p) < 0) {
        u32 c = p[5];
        p[5] = c + 1;
        func_00175910(p, 0x17, 3, (s32)p[0x22] / 2);
    }
}
