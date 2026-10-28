typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8*);
extern void func_001E3A40(u8 *);
void func_00247E40(u8 *p)
{
    u8 *q;
    u32 t;
    if ((s8)func_00175700(p) < 0) { func_001843A0(p); return; }
    switch (*(s8 *)(p + 0x151)) { case 0: break; default:
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 0xB;
        q[0x20D] = 2;
        q[0x1B5] = 0x21;
        p[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
        t = q[0x1E6];
        q[0x1E6] = t ^ 1;
        func_001E3A40(q);
    break; }
}

extern void func_00184540(u8 *);

void func_00248040(u8 *p)
{
    u8 *q;
    u32 t;
    if ((s8)func_00175700(p) < 0) { func_00184540(p); return; }
    switch (*(s8 *)(p + 0x151)) { case 0: break; default:
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x23;
        p[0x1B5] = 0x23;
        q[0x1E6] = p[0x1E6];
        t = q[0x1E6];
        q[0x1E6] = t ^ 1;
    break; }
}
