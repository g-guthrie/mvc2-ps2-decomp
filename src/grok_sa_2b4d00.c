typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);

void func_002B4D00(u8 *p)
{
    p[6]++;
    func_00185490(p);
    p[0x20D] = 0;
    func_00183D10(p);
    func_0018C4B0(p, 8);
    if (p[0x269] == 3) {
        p[0x1B5] = 50;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    } else {
        p[0x1B5] = (s8)p[0x1B7] + 48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    func_001757E0(p, 21, 0);
}
