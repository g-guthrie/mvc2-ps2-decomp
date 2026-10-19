typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);
extern u8 D_004D18E6;
extern u8 D_004C0DF8[];
extern u8 D_004C0E00[];
extern u8 *D_004C2860;

void residual_002C7640(u8 *p)
{
    {
        s16 *slot = (s16 *)(p + 0x1C);
        if (D_004D18E6)
            *slot = D_004C0DF8[(*(u32 *)(D_004C2860 + 0x1C)) & 7];
        else
            *slot = D_004C0E00[(*(u32 *)(D_004C2860 + 0x1C)) & 7];
    }
    {
        s16 k = *(s16 *)(p + 0x1C);
        if (k == 2) {
            p[6] = 4;
            func_001757E0(p, 21, 5);
        } else if (k == 1) {
            p[6] = 3;
            func_001757E0(p, 19, 1);
        } else if (k == 0) {
            p[6]++;
            *(s16 *)(p + 0x1E) = 60;
            func_001757E0(p, 19, 0);
        }
    }
}
