typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003141E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32, s32);
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x151] = 0;
        t = p[7];
        p[7] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 80.0f;
        v[1] = 120.0f;
        func_001830D0(p, v, 1, t + 1);
    }
}
