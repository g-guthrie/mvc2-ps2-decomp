typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 b[4]; } B4;
typedef struct {
    u8 b0;
    s8 b1;
    s8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    B4 c14;
} S407;

extern u8 D_004BD540[];

s32 func_00407D28(S407 *p, s32 a, s32 b, s32 c, B4 *d)
{
    extern s32 func_0010F148(s32);
    extern void func_0011EB60(u8 *);
    extern void func_00411288(void);
    extern void func_004112B0(void);
    s32 r = 0;
    if (func_0010F148(1) == 1) {
        func_0011EB60(D_004BD540);
        return 0;
    }
    func_00411288();
    if (p->b2 == 0 || p->b2 == 3 || p->b2 == 9) {
        p->b2 = p->b1 = 1;
        r = 1;
        p->w8 = a;
        p->c14 = *d;
        p->wC = b;
        p->w10 = c;
        p->w4 = 0;
    }
    func_004112B0();
    return r;
}
