typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct A { u8 p0[4]; s32 w4; u8 p8[4]; s32 wC; u8 p10[4]; s32 w14; s32 w18; s32 w1C; s32 w20; u8 p24[8]; s32 w2C; s32 w30; } A;
extern s32 func_00400650(s32);
extern void func_00400740(s32);
extern void func_003F9630();
extern void func_003F9660();
extern void func_00400CE8(s32, s32);
extern void func_004007A0(s32, s32);
extern void func_00400CA0(s32, s32);
extern void func_00400CF8(s32, s32);
extern s32 func_00400BC8(s32, s32);
extern void func_004006E8(s32);

s32 func_003FCDE0(A *a, s32 n, s32 x) {
    s32 m;
    s32 r;
    if (func_00400650(a->w4) != 1) func_00400740(a->w4);
    func_003F9630();
    m = a->wC - a->w14;
    a->w20 = 0;
    if (n < m) m = n;
    a->w18 = a->w30 + a->w14;
    a->w1C = m;
    if (m == 0) {
        *((u8 *)a + 1) = 3;
        r = 0;
    } else {
        func_00400CE8(a->w4, m);
        func_004007A0(a->w4, -1);
        func_00400CA0(a->w4, x);
        func_00400CF8(a->w4, a->w30 + a->w14);
        func_00400BC8(a->w4, a->w2C);
        *((u8 *)a + 1) = 2;
        func_004006E8(a->w4);
        r = a->w1C;
    }
    func_003F9660();
    return r;
}
