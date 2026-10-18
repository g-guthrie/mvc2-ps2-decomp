typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002D7A30(u8 *p)
{
    extern void func_00175700();
    extern void func_001830D0(u8 *, u32 *, s32);
    extern void func_001D0500(u8 *, s32);
    u32 v[3];
    s32 t;
    u32 k;
    f32 a;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if ((t & 2) != 0) {
        p[0x151] = 0;
        v[0] = 0;
        v[1] = 0x434DB6DB;
        p[0x404] = 0;
        p[0x405] = 0;
        v[2] = 0;
        func_001830D0(p, v, 1);
        return;
    }
    if ((t & 1) != 0) {
        k = p[6];
        p[6] = k + 1;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            a = 13.333333015441895f;
        } else {
            a = -13.333333015441895f;
        }
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) {
            a = 0.4166666567325592f;
        } else {
            a = -0.4166666567325592f;
        }
        *(f32 *)(p + 0x68) = a;
        func_001D0500(p, 0);
    }
}
