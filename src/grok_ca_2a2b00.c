typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004D18E6[];
extern u8 D_004C0BA0[4];
extern u8 D_004C0BA4[4];
extern u8 *D_004C2840;
extern s32 func_001841C0(u8 *);
extern int func_001757E0(u8 *, s32, s32);

void func_002A2B00(u8 *p)
{
    if (D_004D18E6[0])
        *(s16 *)(p + 0x1C) = D_004C0BA0[*(u32 *)(D_004C2840 + 0x1C) & 3];
    else
        *(s16 *)(p + 0x1C) = D_004C0BA4[*(u32 *)(D_004C2840 + 0x1C) & 3];
    if (func_001841C0(p) >= 2)
        *(s16 *)(p + 0x1C) = 0;
    switch (*(s16 *)(p + 0x1C)) {
    case 0:
        p[6]++;
        p[0x168] = 0;
        break;
    case 1:
        p[6] += 2;
        p[0x168] = 1;
        break;
    case 2:
        p[6] += 3;
        p[0x168] = 2;
        break;
    }
    func_001757E0(p, 0x13, p[0x168]);
}
