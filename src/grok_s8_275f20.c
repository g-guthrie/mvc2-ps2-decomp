typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00275A80(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_00275F20(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 0);
    func_00275A80(p);
    func_001757E0(p, 22, 6);
    p[0x1B5] = 64;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    func_001E3210(p, 23);
    *(u32 *)(p + 0x2E0) = 1;
}
