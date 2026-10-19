typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    s32 pad;
    s32 f04;
    s32 pad2;
    s32 f0c;
    s32 pad3;
    s32 f14;
    s32 f18;
} Pool;

extern s32 func_003F0B20(Pool *);
extern void func_003F0E60(Pool *);

s32 func_003F0A60(Pool *p, s32 n)
{
    s32 a;
    s32 aligned;
    s32 m1;
    s32 y;

    m1 = -1;
    a = p->f18;
    aligned = n + a;
    y = a + m1;
    aligned = aligned + m1;
    aligned = aligned & ~y;
    if ((u32)func_003F0B20(p) < (u32)aligned) {
        func_003F0E60(p);
        a = p->f18;
        y = a + m1;
        aligned = (aligned + a + m1) & ~y;
        if ((u32)func_003F0B20(p) < (u32)aligned)
            return 0;
    }
    if (p->f0c)
        return p->f14 + p->f04 - aligned;
    return p->f14 - p->f04;
}
