typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;

void func_002A5160(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_003928D0();
    extern void func_001830D0();
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        q[8] = 0;
        q[9] = 0;
        if (D_004C27A4 <= 3) {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001843A0(p);
            return;
        }
        func_003928D0(p, 3);
        func_003928D0(p, 2);
        func_003928D0(p, 1);
        func_003928D0(p, 0);
        *(u32 *)&v[0] = 0xBFD55555;
        *(u32 *)&v[1] = 0x4302B6DB;
        *(u32 *)&v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
