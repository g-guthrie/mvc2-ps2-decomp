typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void func_003077F0(u8 *p, void *context)
{
    p[6]++;
    p[0x168] = 2;
    func_0018C4B0(p, 2);
    if (p[0x269] == 3) {
        p[0x1B5] = 53;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    } else {
        p[0x1B5] = 5;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    func_001757E0(p, 8, p[0x168]);
}
