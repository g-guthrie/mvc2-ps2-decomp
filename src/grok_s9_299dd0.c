typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void func_00299DD0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 3);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 83;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 10);
}
