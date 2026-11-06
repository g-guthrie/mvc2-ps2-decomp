/* Full C translation unit from 0x0c1d0ad0 through its pool at 0x0c1d108c.
 * Every linked byte and all five literal pools match. Returning directly from
 * the two terminal case-2 paths preserves SHC's matching r2 tail jumps.
 * Twelve-byte vector copies use __quick_odd_mvn at 0x0c1fb7a0. */
#include "objects.h"

struct Ref_tu5_03 { struct Obj_tu5_03 *p0; };
extern struct Ref_tu5_03 *dat_0c2d9650;
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1d0ad0(struct Obj_tu5_03 *);
extern void func_0c1d0b98(struct Obj_tu5_03 *);
extern void func_0c1d0d08(struct Obj_tu5_03 *);
extern void func_0c1d0e90(struct Obj_tu5_03 *);
extern void func_0c1d0f70(struct Vec3_tu5_03 *);
extern void func_0c1d0b36(struct Vec3_tu5_03 *);
extern void func_0c1d0ca4(struct Vec3_tu5_03 *);
extern void func_0c1d0e02(struct Vec3_tu5_03 *);
extern void func_0c1d103a(struct Vec3_tu5_03 *);

void func_0c1d0ad0(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        a->f80 += 0.062f;
        a->f84 += 0.062f;
        if ((a->w28 = a->w28 + 1) >= 8)
            a->b4++;
        break;
    case 1:
        a->f80 -= 0.042f;
        a->f84 -= 0.042f;
        if ((a->w28 = a->w28 + 1) < 20)
            break;
        func_0c037688(a);
        return;
    }
}

void func_0c1d0b36(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 1;
        p->p16 = func_0c1d0ad0;
        p->l84 = dat_0c2d9650->p0->lE4;
        p->lcc = 0x411;
        p->pos = *v;
        p->f80 = 1.0f;
        p->f84 = 1.0f;
        p->f88 = 1.0f;
        p->f120 = 1.0f;
        p->f124 = 1.0f;
        p->f128 = 1.0f;
    }
}

void func_0c1d0b98(struct Obj_tu5_03 *a)
{
    a->angles.scalar.l48 += 0x333;
    a->w28++;
    switch (a->b4) {
    case 0:
        a->f80 += 0.57200003f;
        a->f84 += 0.57200003f;
        if ((a->w28 = a->w28 + 1) >= 7)
            a->b4++;
        break;
    case 1:
        a->f80 -= 0.308f;
        a->f84 -= 0.308f;
        if ((a->w28 = a->w28 + 1) < 20)
            break;
        goto finish;
    }

    switch (a->b4) {
    case 0:
        a->f120 += 0.5f;
        a->f124 += 0.5f;
        a->f128 += 0.5f;
        if (a->w28 >= 2)
            goto advance;
        goto out;
    case 1:
        if (a->w28 >= 12)
            goto advance;
        goto out;
advance:
        a->b5++;
        goto out;
    case 2:
        a->f120 -= 0.125f;
        a->f124 -= 0.125f;
        a->f128 -= 0.125f;
        if (a->w28 < 20)
            return;
finish:
        func_0c037688(a);
        return;
    default:
        goto out;
    }
out:
    ;
}

void func_0c1d0ca4(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 1;
        p->p16 = func_0c1d0b98;
        p->l84 = dat_0c2d9650->p0->lE8;
        p->lcc = 0x411;
        p->pos = *v;
        p->f80 = 1.0f;
        p->f84 = 1.0f;
        p->f88 = 1.0f;
        p->f120 = 0.0f;
        p->f124 = 0.0f;
        p->f128 = 0.0f;
    }
}

void func_0c1d0d08(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        a->f80 += 0.4280000031f;
        a->f84 += 0.4280000031f;
        if ((a->w28 = a->w28 + 1) >= 7)
            a->b4++;
        break;
    case 1:
        a->f80 -= 0.2300000042f;
        a->f84 -= 0.2300000042f;
        if ((a->w28 = a->w28 + 1) < 20)
            break;
        goto finish;
    }

    switch (a->b4) {
    case 0:
        a->f120 += 0.5f;
        a->f124 += 0.5f;
        a->f128 += 0.5f;
        if (a->w28 >= 2)
            goto advance;
        goto out;
    case 1:
        if (a->w28 >= 12)
            goto advance;
        goto out;
advance:
        a->b5++;
        goto out;
    case 2:
        a->f120 -= 0.125f;
        a->f124 -= 0.125f;
        a->f128 -= 0.125f;
        if (a->w28 < 20)
            return;
finish:
        func_0c037688(a);
        return;
    default:
        goto out;
    }
out:
    ;
}

void func_0c1d0e02(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 1;
        p->p16 = func_0c1d0d08;
        p->l84 = dat_0c2d9650->p0->lEC;
        p->lcc = 0x411;
        p->pos = *v;
        p->f80 = 1.0f;
        p->f84 = 1.0f;
        p->f88 = 1.0f;
        p->f120 = 0.0f;
        p->f124 = 0.0f;
        p->f128 = 0.0f;
    }
}

void func_0c1d0e90(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        a->f80 += 0.45f;
        a->f84 += 0.45f;
        if ((a->w28 = a->w28 + 1) >= 20)
            a->b4++;
        break;
    case 1:
        a->f80 -= 0.2300000042f;
        a->f84 -= 0.2300000042f;
        if ((a->w28 = a->w28 + 1) < 20)
            break;
        goto finish;
    }

    switch (a->b4) {
    case 0:
        a->f120 += 0.200000003f;
        a->f124 += 0.200000003f;
        a->f128 += 0.200000003f;
        if (a->w28 >= 5)
            goto advance;
        goto out;
    case 1:
        if (a->w28 >= 15)
            goto advance;
        goto out;
advance:
        a->b5++;
        goto out;
    case 2:
        a->f120 -= 0.200000003f;
        a->f124 -= 0.200000003f;
        a->f128 -= 0.200000003f;
        if (a->w28 < 20)
            return;
finish:
        func_0c037688(a);
        return;
    default:
        goto out;
    }
out:
    ;
}

void func_0c1d0f70(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 1;
        p->p16 = func_0c1d0e90;
        p->l84 = dat_0c2d9650->p0->lf0;
        p->lcc = 0x411;
        p->pos = *v;
        p->f80 = 1.0f;
        p->f84 = 1.0f;
        p->f88 = 1.0f;
        p->f120 = 0.0f;
        p->f124 = 0.0f;
        p->f128 = 0.0f;
    }
}

void func_0c1d0fd4(struct Obj_tu5_03 *a)
{
    func_0c1d0b36(&a->pos);
    func_0c1d0ca4(&a->pos);
    func_0c1d0e02(&a->pos);
    func_0c1d0f70(&a->pos);
    func_0c037688(a);
}

void func_0c1d0ffa(struct Obj_tu5_03 *a, struct Vec3_tu5_03 *v)
{
    struct Vec3_tu5_03 l;
    if (a->w130 != 0)
        l.x = a->pos.x - v->x;
    else
        l.x = a->pos.x + v->x;
    l.y = a->pos.y + v->y;
    l.z = 0.0f;
    func_0c1d103a(&l);
}

void func_0c1d103a(struct Vec3_tu5_03 *v)
{
    struct Obj_tu5_03 *p;
    if ((p = func_0c0374da(0, 8, 1)) != 0) {
        p->b12c = 0;
        p->p16 = func_0c1d0fd4;
        p->pos = *v;
    }
}
