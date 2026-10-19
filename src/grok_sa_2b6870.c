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

void func_002B6870(u8 *p)
{
    p[6]++;
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[0x20D] = 0;
    func_00175C00(p, 0);
    func_00185490(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140))
        *(u32 *)(p + 0x5C) = 0x40555555;
    else
        *(u32 *)(p + 0x5C) = 0xC0555555;
    func_001757E0(p, 21, 19);
}
