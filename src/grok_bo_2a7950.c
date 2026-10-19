typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 D_004C0BD0;
extern u32 D_004C0BD4;
extern u32 D_004C0BD8;
extern u8 *D_004C2794;
extern void func_001E3710(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_002A7950(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)&D_004C0BD0;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(u32 *)(p + 0x408) = (u32)&D_004C0BD4;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[0x168] = 3;
            p[0x1B5] = 18;
        }
        func_001E3710(p, 0x16);
        *(u32 *)(p + 0x408) = (u32)&D_004C0BD8;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = (s8)p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
