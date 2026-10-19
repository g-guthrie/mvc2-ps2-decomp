typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern u8 D_004C10C8[];
extern u8 D_004C10CC[];
extern u8 D_004C10D0[];
extern void func_001E3710(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_002E4980(u8 *p)
{
    int x, y;
    switch (p[0x1FC]) {
    case 0:
        *(u8 **)(p + 0x408) = D_004C10C8;
        x = 6;
        y = 0;
        func_001E3710(p, 0x14);
        p[0x1BB] = 0;
        break;
    case 1:
        *(u8 **)(p + 0x408) = D_004C10CC;
        x = 7;
        y = 1;
        func_001E3710(p, 0x15);
        p[0x1BB] = 1;
        break;
    case 2:
        *(u8 **)(p + 0x408) = D_004C10D0;
        x = 8;
        y = 2;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 9, y);
}
