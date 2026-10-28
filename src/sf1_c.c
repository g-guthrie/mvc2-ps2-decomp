/* nearmiss: ./try.sh -O3 -Op -fp off -sdatathreshold 0 (3.0.3 and 3.0 same); only loop counter i in $a1 where retail has $a2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
extern u32 D_004D190C[];
extern char D_004B1128[];
extern f32 D_0043E8A0[];

void func_00134610(u8 *p, u8 *q)
{
    extern void func_0011F938(char *, char *, u32);
    char buf[16];
    u8 *dst;
    u32 i;
    int n;
    double k;
    f32 v;
    func_0011F938(buf, D_004B1128, D_004D190C[q[2]]);
    dst = p + 0x1B0;
    n = 0;
    for (i = 0; i < 8; i++) {
        s8 d = buf[i] - 0x30;
        *dst = d;
        if (d < 0) n++;
        dst++;
    }
    k = 1.75;
    v = -(f32)(k *= (double)(u32)n);
    if (q[2] != 0) v = D_0043E8A0[p[0x14C] & 0xF] - 24.0f;
    *(f32 *)(p + 0x64) = v;
}
