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
extern int func_00174170(void);

void residual_002C2310(u8 *p)
{
    p[6]++;
    if (p[0x20] == 2) {
        func_001757E0(p, 19, 3);
        return;
    }
    {
        int r = func_00174170();
        *(s16 *)(p + 0x1C) = r & 3;
    }
    {
        s16 k = *(s16 *)(p + 0x1C);
        if (k == 3)
            func_001757E0(p, 19, 2);
        else if (k == 2)
            func_001757E0(p, 19, 1);
        else if (k == 1)
            func_001757E0(p, 19, 1);
        else if (k == 0)
            func_001757E0(p, 19, 0);
    }
}
