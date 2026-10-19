typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00303000(u8 *, u8 *);
extern u8 *D_004C2794;

void residual_00302F30(u8 *p, u8 *q)
{
    p[7]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x60) = 0xC0092492;
    q[0] = 0;
    p[0x1B5] = (s8)p[0x1B7] + 48;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, (u8)(p[0x1B7] + 4));
    *(s16 *)(p + 0x1E) = (s8)p[0x151];
    p[0x151] = 0;
    func_00303000(p, q);
}
