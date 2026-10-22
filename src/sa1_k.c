typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00253E20(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001AD170(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001548D0(u8 *, f32 *, s32);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001843A0(u8 *);
    f32 v[4];
    f32 d, f;
    u32 c;
    u8 *o;
    if ((s8)func_00175700(p) >= 0) {
    switch (*(s8 *)(p + 0x151)) {
    case 1:
        p[0x151] = 0;
        func_001AD170(p, 0, 0);
        func_001AD170(p, 2, 0);
        func_001266A0(p, 0, 0);
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 1;
        o[0x1B5] = 0x24;
        d = *(f32 *)(o + 0x34) - *(f32 *)(p + 0x34);
        v[0] = d;
        if (d > 0.0f) v[0] = -d;
        c = o[0x14C];
        f = (f32)c;
        v[2] = 0.0f;
        v[1] = 2.142857074737549f * f / 1.7999999523162842f;
        func_001548D0(p, v, 1);
        func_00191480(o, p, 1);
        func_001E3710(p, 7);
        break;
    case 2:
        p[0x151] = 0;
        func_001AD170(p, 1, 0);
        break;
    }
        return;
    }
    {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}
