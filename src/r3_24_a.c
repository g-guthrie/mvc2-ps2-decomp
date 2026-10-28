typedef unsigned char u8; typedef signed int s32; typedef unsigned int u32;
typedef struct { s32 f0; s32 f4; u8 *f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; } S3;
extern void func_003F55B0(void *, s32, s32);
void func_003F0B70(S3 *p, u8 *a1, s32 n, s32 a3, s32 t0, s32 t1, s32 t2) {
    s32 a2;
    a2 = (s32)n;
    p->f0 = n;
    p->f8 = a1;
    func_003F55B0(a1, 0, a2 << 4);
    p->f4 = t0 - (a2 << 1);
    p->fC = t2;
    p->f18 = t1;
    if (t2 != 0) {
        p->f14 = (t1 + (a3 + (a2 << 1)) - 1) & ~(t1 - 1);
        p->f10 = p->f14;
    } else {
        p->f14 = (a3 + t0 - (a2 << 1)) & ~(t1 - 1);
        p->f10 = p->f14;
    }
    p->f20 = 0;
    p->f1C = 0;
}
