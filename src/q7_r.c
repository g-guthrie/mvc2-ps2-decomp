typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_0045DA30[];

void func_0031E2C0(u8 *p) {
    extern s8 func_00175700();
    extern void func_0031E710();
    extern void func_0031E770();
    extern void func_0031E950();
    extern void func_00183D10();
    extern void func_001843A0();
    u8 *s;
    u32 m;
    u32 i;
    u32 v;
    s = p + 0x2B8;
    if (func_00175700(p) < 0) {
        if (s[1] != 0 && (m = (u16)(*(s16 *)(p + 0x354) & 0x3C00)) != 0 && (v = D_0045DA30[i = (u16)(m >> 10)]) != 0 && (i & (1 << p[0x1E6])) == 0) {
            p[0x22] = v - 1;
            p[0x20D] = 2;
            p[7] = 0;
            s[0] = 1;
            s[1] = 0;
            func_0031E710(p);
            func_0031E770(p);
            func_0031E950(p);
            func_00183D10(p);
            return;
        }
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x210] = 0;
        p[0x20D] = 0;
        func_001843A0(p);
    } else {
        if ((u16)(*(s16 *)(p + 0x354) & 0x360) != 0) s[1] = 1;
    }
}
