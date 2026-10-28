typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
void func_00380850(u8 *p) {
    extern void func_00380A40();
    extern s32 func_00182C90();
    extern void func_001843A0();
    extern void func_001845F0();
    u8 *s0 = *(u8 **)(p + 0xD4);
    if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) == p && s0[5] == 2 &&
        !(*(s8 *)(s0 + 0x1B3) != 0 && s0[5] == 3)) {
        s16 v;
        func_00380A40(p);
        if (func_00182C90(s0) != 0) *(s16 *)(p + 0x1C) -= 3;
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t;
            s0[0x20A] = 0;
            s0[0x203] = 8;
            if (*(s16 *)(s0 + 0x434) == 0) {
                s0[0x20A] = 7;
            } else {
                switch (s0[0x20D]) {
                default: func_001843A0(s0); break;
                case 2: func_001845F0(s0); break;
                }
            }
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    } else {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 0;
    }
}
