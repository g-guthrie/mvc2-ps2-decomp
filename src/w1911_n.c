typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
typedef int s32;
void func_001B4910(u8 *p) {
    extern void func_00175670(u8 *);
    extern void func_001B5350(u8 *, u8 *);
    extern void func_001B4C00(u8 *, u8 *);
    extern s32 func_001B4BD0(u8 *);
    extern u8 *func_001B3E30(u8 *, s32, s32);
    u8 *s0 = *(u8 **)(p + 0x18);
    u8 *o;
    u32 t;
    func_00175670(p);
    if (p[0x22] & 1) *(s16 *)(s0 + 0x140) ^= 1;
    func_001B5350(s0, p);
    if (p[0x22] & 1) *(s16 *)(s0 + 0x140) ^= 1;
    func_001B4C00(s0, p);
    if (func_001B4BD0(p) == 0 && *(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x24] = 0xA;
        o = func_001B3E30(s0, 0xD, 9);
        if (o != 0) {
            *(f32 *)(o + 0x5C) = *(f32 *)(p + 0x5C);
            *(s16 *)(o + 0x140) = *(s16 *)(p + 0x140);
            o[0x24] = 0xB;
            o[0x22] = p[0x22];
            *(u16 *)(o + 0xD0) = *(u16 *)(p + 0xD0);
            o[0xD1] = p[0xD1];
        }
        o = func_001B3E30(s0, 0xE, 9);
        if (o != 0) {
            *(f32 *)(o + 0x5C) = *(f32 *)(p + 0x5C);
            *(s16 *)(o + 0x140) = *(s16 *)(p + 0x140);
            o[0x24] = 9;
            o[0x22] = p[0x22];
            *(u16 *)(o + 0xD0) = *(u16 *)(p + 0xD0);
            o[0xD1] = p[0xD1];
        }
    }
}
