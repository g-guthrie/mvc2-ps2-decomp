typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0039FAC0(u8 *p, u8 *q)
{
    s32 a;
    u32 t;
    s16 v;
    extern void func_0039FC70(u8 *);
    extern void func_00175700(u8 *);
    extern void func_0039F7E0(u8 *, s32);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);

    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        func_0039FC70(p);
        return;
    }
    p[0x13C] = 1;
    if (q[5] == 0) {
        if (p[0x21] == 0 && p[5] == 0) {
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                t = p[5];
                p[5] = t + 1;
                p[0x151] = 0;
                *(s16 *)(p + 0x1C) = 0x3C;
                a = 0x58;
                if (*(s16 *)(p + 0x140) != 0) {
                    a = -0x58;
                }
                *(f32 *)(p + 0x34) -= 1.66666662693f * (f32)a;
                func_0039F7E0(p, 0x88);
                func_0039F7E0(p, 0x110);
            }
        } else {
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v == 0) goto tail;
            func_00175700(p);
            func_001E7F60(p);
        }
        return;
    }
tail:
    if (p[5] != 0) {
        t = p[4];
        p[4] = t + 1;
        func_001757E0(p, 0x17, 0x15);
    } else {
        func_0039FC70(p);
    }
}
