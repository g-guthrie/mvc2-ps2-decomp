typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;

void func_003B8830(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B8170(u8 *);
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_003B81F0();
    u8 *s = *(u8 **)(o + 0x14);
    u8 *q;
    u8 *z = s + 0x2B8;
    if (s[5] != 0 || s[0x1E4] != 0x1D || s[0x1FD] != 1) {
        u32 t4 = o[4];
        o[4] = t4 + 1;
        o[0x13C] = 0;
        return;
    }
    if (*z != 0) {
        u32 t5 = o[5];
        o[5] = t5 + 1;
        *(s16 *)(o + 0x1C) = 0x20;
        func_001757E0(o, 0x15, 0x18);
        func_003B8170(o);
        return;
    }
    if ((*(u32 *)(D_004C2840 + 0x1C) & 7) == 0) {
        if ((q = func_003DA750(0, 1, 1)) != 0) {
            *(void **)(q + 0x10) = (void *)func_003B81F0;
            *(u8 **)(q + 0x18) = o;
            *(u32 *)(q + 0x14) = *(u32 *)(o + 0x14);
            q[1] = s[1];
            q[0x20] = 2;
            q[0x21] = 0;
        }
    }
    func_001E7F60(o);
}
