typedef signed int s32;

typedef struct {
    s32 pad[2];
    s32 h;
} P;

typedef struct {
    s32 f04;
    s32 f08;
    s32 f10;
    s32 f18;
    s32 f20;
    s32 f24;
    s32 f28;
} Q;

extern s32 func_003F8490(P *, s32);
extern s32 func_003F8448(P *, s32);

s32 func_003F84E8(P *p)
{
    s32 *q = (s32 *)((char *)p + 0x48);
    s32 t6 = q[2];
    s32 a2 = q[1];
    s32 t7 = q[6];
    s32 t0 = q[8];
    s32 t1 = q[4];
    s32 a3 = q[10];
    s32 t4 = q[9];
    s32 t2 = a2 / t6;
    s32 t3 = (t7 - t0 + t1 - 1) / t1;
    s32 t5 = (a3 + t1 - 1) / t1;
    s32 a1 = t1 - ((a3 + t1 - 1) % t1) - 1;
    s32 lt = a3 < t4;

    if (t5 < t3) {
        t0 = t0 + t3 * t1;
        t3 += (t0 - a1) < t7;
    }
    t4 = lt * a1 + t4;
    a1 = t4 / t1;
    if (a1 < t2)
        t2 = a1;
    if (t5 < t2)
        t2 = t5;
    if (t3 < t2)
        t2 = t3;
    if (t6 == 2)
        return func_003F8490(p, t2);
    return func_003F8448(p, t2);
}
