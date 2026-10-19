typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_0023B4C0(u8 *);
extern void func_0023B5B0(u8 *);

void func_0023B3D0(u8 *p)
{
    func_001861B0(p);
    func_0018C4B0(p, 5);
    if (p[0x212] == 0) {
        p[6] = 1;
        p[0x20D] = 1;
        func_001757E0(p, 0x14, 3);
        p[0x1B5] = 27;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_0023B4C0(p);
    } else {
        p[6] = 2;
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 4);
        p[0x1B5] = 29;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_0023B5B0(p);
    }
}
