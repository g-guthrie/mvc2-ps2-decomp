typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002DC070(u8 *p) {
    extern s32 func_00174780(u8 *);
    u32 fl;
    f32 f1;
    f32 z;
    s8 v;
    fl = *(u16 *)(p + 0x354);
    if ((fl & 0xC00) != 0) {
        f1 = 3.3333332538604736f;
        if (p[0x210] != 0) f1 = 0.8333333134651184f;
        if (((u16)fl & 0x800) != 0) f1 = -f1;
        *(f32 *)(p + 0x34) += f1;
    }
    if (!(*(f32 *)(p + 0x60) > (z = 0.0f)) && p[0x215] == 0) {
        if (func_00174780(p) != 0) {
            if (((u16)fl & 0x2000) != 0) {
                if ((p[0x15A] & 0xE0) == 0) {
                    v = *(s8 *)(p + 0x152) - 1;
                    *(s8 *)(p + 0x152) = v;
                    if (v <= 0) *(s8 *)(p + 0x152) = 1;
                }
                *(u32 *)(p + 0x60) = 0xC0892492;
                *(u32 *)(p + 0x6C) = 0;
            }
            if (((~*(u16 *)(p + 0x354) & *(u16 *)(p + 0x356)) & 0x2000) == 0) return;
        }
        *(u32 *)(p + 0x60) = 0xC1092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
