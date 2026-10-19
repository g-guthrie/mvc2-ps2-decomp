typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_0031E720(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00186A20(u8 *);
extern void func_0031E710(u8 *);
extern void func_0031E770(u8 *);
extern void func_0031E950(u8 *);
extern void func_003288A0(u8 *);

void residual_0031DFA0(u8 *p)
{
    u8 *q = p + 0x2B8;
    int a;

    if (p[7] == 0) {
        p[7]++;
        *(s16 *)(p + 0x1C) = 0;
        p[0x1B7] = 1;
        q[0] = 0;
        func_0018C4B0(p, 5);
        func_0031E720(p);
        a = 9;
        if (p[0x20D] != 2) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            a = 8;
            func_00183D10(p);
        }
        func_001757E0(p, 0x15, (u8)a);
        return;
    }
    if (func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        q[0] = 1;
        func_00186A20(p);
        func_0031E710(p);
        func_0031E770(p);
        func_0031E950(p);
        func_003288A0(p);
    }
}
