typedef signed int s32;

typedef struct {
    s32 f00;
    s32 f04;
    void *f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
} Pool;

extern void func_003F55B0(void *, s32, s32);

void func_003F0B70(Pool *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    s32 n;
    Pool *p;
    s32 s3;
    s32 s2;
    s32 s1;
    s32 s0;

    p = a0;
    n = a2;
    s3 = a3;
    s2 = a4;
    s1 = a5;
    s0 = a6;
    p->f00 = n;
    p->f08 = a1;
    func_003F55B0(a1, 0, n << 4);
    p->f04 = s2 - (n << 1);
    p->f0c = s0;
    p->f18 = s1;
    if (s0 != 0) {
        p->f14 = (s3 + (n << 1) + s1 - 1) & ~(s1 - 1);
        p->f10 = p->f14;
    } else {
        p->f14 = (s3 + s2 - (n << 1)) & ~(s1 - 1);
        p->f10 = p->f14;
    }
    p->f20 = 0;
    p->f1c = 0;
}
