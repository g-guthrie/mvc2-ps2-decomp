typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned long long u64;

extern s32 D_004D190C[];
extern u8 D_004B1128[];
extern float D_0043E8A0[];
extern void func_0011F938(void *, void *, s32);
extern u64 func_00100230(void);
extern double dpmul(double, double);
extern float func_00119C90(double);

void func_00134610(u8 *p, u8 *q)
{
    s8 buf[16];
    s32 i;
    s32 n = 0;
    u8 *d;
    float f;
    func_0011F938(buf, D_004B1128, D_004D190C[q[2]]);
    d = p + 0x1B0;
    for (i = 0; i < 8; i++) {
        s8 v = buf[i] - 0x30;
        d[i] = v;
        if (v < 0)
            n++;
    }
    f = func_00119C90(dpmul(1.75, func_00100230()));
    f = -f;
    if (q[2])
        f = D_0043E8A0[p[0x14C] & 0xF] - 24.0f;
    *(float *)(p + 0x64) = f;
}
