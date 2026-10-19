typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001A70B0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);

void func_00247CD0(u8 *p)
{
    u8 *q;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[6]++;
        *(s16 *)(p + 0x1C) = 30;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 32;
        p[0x1B5] = 32;
        q[0x1E6] = p[0x1E6];
        q[0x1E6] ^= 1;
        func_001A70B0(p, 1, 0);
        func_001E3210(p, 34);
    }
}

void func_002A4070(u8 *p)
{
    p[6]++;
    p[437] = p[0x1B7] ? 0x5D : 0x5C;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    p[525] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00183D10(p);
    func_001757E0(p, 21, (p[0x1B7] ? 0x11 : 0x10) & 0xff);
}
