typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern u8 D_004C10D4[4];
extern u8 D_004C10D8[4];
extern u8 D_004C10DC[4];
extern void func_001E3710(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_002E4A70(u8 *p)
{
    int x, y;
    switch (p[0x1FC]) {
    case 0:
        *(u8 **)(p + 0x408) = D_004C10D4;
        x = 3;
        y = 0;
        func_001E3710(p, 0x14);
        p[0x1BB] = 0;
        break;
    case 1:
        *(u8 **)(p + 0x408) = D_004C10D8;
        x = 4;
        y = 1;
        func_001E3710(p, 0x15);
        p[0x1BB] = 1;
        break;
    case 2:
        *(u8 **)(p + 0x408) = D_004C10DC;
        x = 5;
        y = 2;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 8, y);
}
