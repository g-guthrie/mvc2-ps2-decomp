typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_002B3B20(u8 *p)
{
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        else if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 124))[p[2]]++;
            p[0x15B] = 0;
        }
        break;
    }
}
