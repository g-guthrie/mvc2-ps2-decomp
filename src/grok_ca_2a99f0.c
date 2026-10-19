typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00394780(u8 *, int, int);
extern int func_001757E0(u8 *, int, int);

void func_002A99F0(u8 *p)
{
    f32 vel;

    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    p[0x1B5] = 55;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 0;
    if (p[0x1E6])
        vel = 8.3333330154418945f;
    else
        vel = -8.3333330154418945f;
    *(f32 *)(p + 0x5C) = vel;
    func_00183D10(p);
    func_00394780(p, 2, 0);
    func_001757E0(p, 21, 18);
}
