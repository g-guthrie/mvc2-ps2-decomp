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
extern u8 D_004D18A0;
extern void func_0039C5B0(u8 *, int);

void residual_002D2DD0(u8 *p)
{
    p[0x13C] = 0;
    if (!(D_004D18A0 < 2)) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 30;
        *(s16 *)(p + 0x1E) = 24;
        *(u32 *)(p + 0x60) = 0x419A4924;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(u32 *)(p + 0x5C) = 0x40A00000;
        {
            float dy = -245.0f;
            if (p[0x1E6] == 0) {
                *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
                dy = -dy;
            }
            *(float *)(p + 0x64) = *(float *)(p + 0x34);
            *(float *)(p + 0x34) += dy;
        }
        *(u32 *)(p + 0x68) = 0;
        func_001757E0(p, 18, 0);
        func_0039C5B0(p, 3);
    }
}
