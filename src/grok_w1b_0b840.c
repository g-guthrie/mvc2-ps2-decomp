typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void func_0020B840(u8 *p)
{
    p[6]++;
    p[0x1B5] = p[0x1B7] ? 59 : 57;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 8);
    func_00185490(p);
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 1;
    func_00183D10(p);
    *(s16 *)(p + 0x1C) = 13;
    func_001757E0(p, 21, 9);
}
