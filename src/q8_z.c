typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00240FE0(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern void func_002413C0();
    extern void func_00241430();
    extern void func_00182C30();
    extern void func_00182DB0();
    extern void func_001266A0();
    extern void func_001757E0();
    u8 *o;
    s32 v;
    u32 t;
    s16 h;
    func_00175700(p);
    func_002413C0(p, q);
    v = *(s8 *)(q + 6);
    if (v > 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x1FE] = 1;
        p[0x20B] = 0xC3;
        p[0x206] = 3;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        o = *(u8 **)(p + 0x1DC);
        o[0x208] = 2;
        o[0x20B] = p[0x20B];
        func_00182C30(o, 0x23);
        func_00182DB0(p, 0x14);
        func_001266A0(p, 0, 5);
        func_001757E0(p, 0x15, 9);
        func_002413C0(p, q);
        func_00241430(p, q);
        return;
    }
    if (v < 0 || (h = *(s16 *)(p + 0x1E) - 1, *(s16 *)(p + 0x1E) = h, h == 0)) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 7));
    }
}
