typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002D4370(u8 *p)
{
    extern void func_00175700(u8 *);
    extern u8 *func_0039C5B0(u8 *, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u8 *r;
    u8 *q;
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x15B) > 0) {
        p[0x15B] = 0;
        r = func_0039C5B0(p, 9);
        q = p + 0x2B8;
        if (r == 0) {
            q[8] = 1;
        } else {
            q[8] = 0;
        }
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        p[0x151] = 0;
        r = func_0039C5B0(p, 2);
        if (r != 0) {
            r[0x95] = 4;
        }
        *(s16 *)(p + 0x1E) = 3;
        v[0] = 0x41555555;
        v[1] = 0x42892492;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
