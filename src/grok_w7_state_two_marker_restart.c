typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern u8 *D_004C2794;

void func_002F3410(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
    if (p[0x1FC] != 2) return;
    if (p[0x15B] == 0) return;
    p[0x15B] = 0;
    p[0x1B5] = 14;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
}
