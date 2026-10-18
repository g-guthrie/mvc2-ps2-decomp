typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_002EC810(u8 *p) {
    extern s32 func_00175700();
    extern s32 func_003A7B20();
    extern void func_001843A0();
    extern void func_001830D0();
    s32 t;
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if (t & 2) {
        p[0x151] = t & ~2;
        { u32 u = p[6]; p[6] = u + 1; }
        *(s16 *)(p + 0x1C) = 0x78;
        *(s16 *)(p + 0x1E) = 0;
        if (func_003A7B20(p, 0, 0) == 0) {
            func_001843A0(p);
        } else {
            v[2] = 0;
            v[0] = 0xC3235555;
            v[1] = 0x434FDB6D;
            p[0x404] = 0;
            p[0x405] = 0;
            func_001830D0(p, v, 1);
        }
    }
}
