typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002C3820(u8 *p) {
    f32 *a, *b, *c, *d;
    u32 vec[4];
    s32 v;
    extern void func_00175700(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001E7FD0(u8 *);
    extern void func_00185770(u8 *, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_0018C6E0(u8 *);
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x60);
    c = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x6C);
    if (func_001864a0(p)) {
        u32 t;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 3);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        if ((v = func_001E7FD0(p)) != 0) {
            u32 t;
            p[0x20B] = 0xC4;
            t = p[6];
            p[6] = t + 2;
            func_00185770(p, v);
            vec[0] = 0xC2A00000;
            vec[1] = 0x431A4924;
            func_0015D010(p, vec);
            p[0x1B4] = 10;
            func_0018C6E0(p);
            *a = 0;
            *b = 0;
            *c = 0;
            *d = 0;
            *(s16 *)(p + 0x1C) = 2;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x6C) = 0xBF892492;
            func_001757E0(p, 0xF, 2);
        }
    }
}
