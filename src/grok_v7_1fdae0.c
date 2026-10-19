typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_001FD910(u8 *);
extern void func_001FD950(u8 *);

void func_001FDAE0(u8 *p)
{
    u8 st;
    if (p[0x1FC] == 2) {
        st = p[6];
        if (st == 2)
            func_001FD950(p);
        else if (st == 1) {
            func_001FD910(p);
            if (func_001864A0(p) != 0)
                func_001865B0(p);
        } else {
            if ((s8)func_00175700(p) < 0)
                func_00184540(p);
            if (func_001864A0(p) != 0)
                func_001865B0(p);
        }
    } else {
        if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        if (func_001864A0(p) != 0)
            func_001865B0(p);
    }
}
