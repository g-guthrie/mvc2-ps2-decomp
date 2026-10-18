typedef signed int s32;
typedef unsigned char u8;
typedef struct U { s32 w[8]; } U;
extern void func_001191F0(double *in, U *out);
extern void func_00119998(U *a, U *b);
void func_00119AB8(double a, double b) {
    U x, y;
    func_001191F0(&a, &x);
    func_001191F0(&b, &y);
    func_00119998(&x, &y);
}
extern s32 D_00634300;
extern s32 func_00104598(s32, s32);
s32 func_0011C3F8(s32 *out, s32 a, s32 b) {
    s32 r;
    D_00634300 = 0;
    r = func_00104598(a, b);
    if (r == -1) {
        s32 e = D_00634300;
        if (e != 0) *out = e;
    }
    return r;
}
