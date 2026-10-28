typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad1[0x20];
    f32 f5c, f60, f64, f68, f6c;
    u8 pad2[0x3C0];
    f32 f430;
} MB;

void func_002D0710(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    MB *m = (MB *)p;
    u32 t = p[6];
    if (t == 0) {
        f32 v;
        p[6] = t + 1;
        v = (p[0x1E6] != 0) ? -7.5f : 7.5f;
        m->f5c = v;
        m->f68 = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBE892492;
    }
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u32 *)(q + 0x1C8) = (u32)p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x20;
        q[0x1E6] = p[0x1E6];
    }
    if (*(s8 *)(p + 0x150) == 0) {
        u32 *z0 = (u32 *)(p + 0x60);
        u32 *z1 = (u32 *)(p + 0x6C);
        m->f34 += m->f5c;
        m->f5c += m->f68;
        m->f38 += m->f60;
        m->f60 += m->f6c;
        if (m->f38 <= m->f430) {
            *z0 = 0;
            *z1 = 0;
            m->f38 = m->f430;
        }
    }
}
