typedef signed int s32;
typedef unsigned int u32;
extern void func_004095C8(void);
extern s32 D_00495BB4;
extern s32 D_00495BB0;
extern s32 func_00404438(s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 func_00404468(s32 a);

void func_00410B88(void) {
    volatile s32 *unused = &D_00495BB0;
    s32 n = D_00495BB4;
    s32 x = *unused;
    if (n == 0) { func_004095C8(); n = D_00495BB4; }
    D_00495BB4 = n + 1;
}
s32 func_003F8490(s32 *p, s32 idx) {
    s32 *q = p + 18;
    s32 h = p[2];
    s32 a = q[5] + q[8] * 2;
    func_00404438(h, q[0], idx * 2, a, a + q[7] * 2);
    return func_00404468(h);
}
