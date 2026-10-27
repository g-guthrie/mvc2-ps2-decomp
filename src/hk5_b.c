typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 D_004C28D0;

void func_001F67E0(u8 *p) {
    s16 v;
    u32 c[3];
    u32 t;
    u8 *q;
    void func_00175700(u8 *);
    void func_001757E0(u8 *, s32, s32);
    s32 func_00182E20(u8 *);
    s32 func_00182D30(u8 *);
    u8 func_0018FDB0(u8 *);
    void func_001549B0(u8 *, u32 *);
    void func_001E3710(u8 *, s32);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 0x32);
        return;
    }
    if (func_00182E20(p) != 0) {
        if (*(u16 *)((p[2] << 1) + (u32)D_004C2840 + 0x106) != 0) {
            t = D_004C28D0;
            D_004C28D0 = t + 1;
            if (D_004C28D0 % 3 == 0) p[0x152] = 2;
        }
    }
    if (func_00182D30(*(u8 **)(p + 0x1DC)) == 0) {
        if (*(s8 *)(p + 0x151) == 0) return;
        p[0x151] = 0;
        D_004C28D0 = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x23;
        p[0x1B5] = 0x23;
        func_0018FDB0(p);
        c[0] = 0xC2D55555;
        c[1] = 0x434DB6DB;
        func_001549B0(p, c);
        func_001E3710(p, 0xC);
        return;
    }
    t = p[7];
    p[7] = t + 1;
    func_001757E0(p, 0xF, 0x32);
}
