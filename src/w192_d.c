typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_00175700(u8 *);
extern void func_001830D0(u8 *, u32 *, s32);

void func_0020D600(u8 *p)
{
    u32 v[4];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0x6F;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x41C80000;
        v[1] = 0x43474924;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
