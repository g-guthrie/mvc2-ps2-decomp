typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00241110(u8 *p, u8 *q) {
    extern void func_00241430(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_00158C70(f32 *, s32);
    extern void func_001E3A40(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_00182C30(u8 *, s32);
    extern s32 func_00182E20(u8 *);
    extern void func_00182DB0(u8 *, s32);
    extern s32 func_00175700(u8 *);
    extern void func_002413C0(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    f32 v[4];
    s32 t;
    p[0x1FE] = 1;
    p[0x206] = 3;
    o = *(u8 **)(p + 0x1DC);
    func_00241430(p);
    if (((s8 *)p)[0x150]) {
        *(s8 *)((s32)p + 0x150) = 0;
        *(u8 **)(o + 0x1C8) = p;
        o[0x1B5] = 0x35;
        if (*(s16 *)(p + 0x1C)) o[0x1B5] = 0x36;
        func_0018FDB0(p);
        v[0] = *(f32 *)(o + 0x34);
        v[1] = *(f32 *)(o + 0x430);
        func_00158C70(v, o[2]);
        func_001E3A40(p);
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        return;
    }
    if (func_00182D30(o)) {
        *(s16 *)(p + 0x1C) = 0;
        func_00182C30(o, 0x23);
    }
    if (func_00182E20(p)) {
        t = *(s16 *)(p + 0x1C);
        if (t == 0) {
            *(s16 *)(p + 0x1C) = t + 1;
            func_00182DB0(p, 0x14);
        }
    }
    if ((s8)func_00175700(p) >= 0) {
        func_002413C0(p, q);
        return;
    }
    if (*(s16 *)(p + 0x1C) == 0 || *(s16 *)(p + 0x1E) != 0) {
        t = p[7];
        p[7] = t + 1;
        t = o[6];
        o[6] = t + 1;
        *(s8 *)(q + 6) = -1;
        func_001757E0(p, 0x15, 0xB);
        return;
    }
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 1;
    func_001757E0(p, 0x15, 9);
    func_002413C0(p, q);
}
