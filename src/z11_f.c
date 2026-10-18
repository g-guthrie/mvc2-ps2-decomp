typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002E7310(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern u8 *func_001D45D0(u8 *, s32);
    s32 i;
    u8 *o;
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    if (func_00175700(p) >= 0) {
        s8 a = *(s8 *)(p + 0x151);
        if ((a & 1) != 0) {
            p[0x151] = a ^ 1;
            func_001266A0(p, 1, 1);
            func_001D45D0(p, 6);
        }
    } else {
        i = 0;
        do {
            if ((o = func_001D45D0(p, 7)) == 0) break;
            o[0x21] = i;
            i++;
        } while (i < 16);
        q = *(u8 **)(p + 0x1DC);
        t = q[6];
        q[6] = t + 1;
        t = p[7];
        p[7] = t + 1;
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0x30;
    }
}
