typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00219260(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00186A20(u8 *);
extern void func_00219250(u8 *);
extern void func_002192B0(u8 *);
extern void func_00219490(u8 *);
extern void func_003288A0(u8 *);

void residual_00218AB0(u8 *p)
{
    u8 *s0 = p + 0x2B8;
    int n;

    if (p[7] == 0) {
        p[7] = 1;
        *(s16 *)(p + 0x1C) = 0;
        p[0x1B7] = 1;
        func_0018C4B0(p, 5);
        s0[0] = 0;
        func_00219260(p);
        if (p[0x20D] == 2)
            n = 9;
        else {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            n = 8;
            func_00183D10(p);
        }
        func_001757E0(p, 0x15, n);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        func_00186A20(p);
        s0[0] = 1;
        func_00219250(p);
        func_002192B0(p);
        func_00219490(p);
        func_003288A0(p);
    }
}
