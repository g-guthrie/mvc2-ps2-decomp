typedef signed int s32;

typedef struct {
    s32 pad[2];
    s32 h;
} P;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 pad;
    s32 f10;
    s32 pad2;
    s32 f18;
    s32 pad3;
    s32 f20;
    s32 f24;
    s32 f28;
} Q;

extern s32 func_003F8490(P *, s32);
extern s32 func_003F8448(P *, s32);

s32 func_003F84E8(P *p)
{
    Q *q = (Q *)((char *)p + 0x48);
    s32 t6 = q->f08;
    s32 t2 = q->f04 / t6;
    s32 t7 = q->f18;
    s32 t0 = q->f20;
    s32 t1 = q->f10;
    s32 a3 = q->f28;
    s32 t4 = q->f24;
    s32 lt = a3 < t4;
    s32 t3 = (t7 - t0 + t1 - 1) / t1;
    s32 t5 = (a3 + t1 - 1) / t1;
    s32 rem = (a3 + t1 - 1) % t1;
    s32 a1 = t1 - rem - 1;
    s32 v;

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
