typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } S_4BB0;
static void func_00224BB0(S_4BB0 *p) {
    f32 *v1, *a1, *a2, *a3;
    p->f34 += p->f5c;
    v1 = &p->f5c;
    a2 = &p->f68;
    a1 = &p->f60;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    a3 = &p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *v1 = 0; *a1 = 0; *a2 = 0; *a3 = 0;
    }
}

void func_00224E30(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00224BB0((S_4BB0 *)p);
    if (p[0x20D] != 2) {
        func_001757E0(p, 0x16, 2);
    } else {
        func_001757E0(p, 0x16, 3);
    }
}
