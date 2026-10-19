typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 D_004D18E6[];
extern u8 *D_004C2840;
extern u8 D_004C0E68[8];
extern u8 D_004C0E70[8];
extern void func_001757E0(u8 *, int, int);

void residual_002C7640(u8 *p)
{
    if (D_004D18E6[0])
        *(s16 *)(p + 0x1C) = D_004C0E68[*(u32 *)(D_004C2840 + 0x1C) & 7];
    else
        *(s16 *)(p + 0x1C) = D_004C0E70[*(u32 *)(D_004C2840 + 0x1C) & 7];
    switch (*(s16 *)(p + 0x1C)) {
    case 2:
        p[6] = 4;
        func_001757E0(p, 21, 5);
        break;
    case 1:
        p[6] = 3;
        func_001757E0(p, 19, 1);
        break;
    case 0:
        p[6]++;
        *(s16 *)(p + 0x1E) = 60;
        func_001757E0(p, 19, 0);
        break;
    }
}
