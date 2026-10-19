typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_001266A0(u8 *, int, int);
extern int func_001757E0(u8 *, int, int);

void func_002724B0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[7]++;
    p[0x1B5] = 62;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    if (p[2])
        func_001266A0(p, 1, 4);
    else
        func_001266A0(p, 1, 3);
    *(s16 *)(p + 0x1C) = 16;
    func_001757E0(p, 22, 0);
}
