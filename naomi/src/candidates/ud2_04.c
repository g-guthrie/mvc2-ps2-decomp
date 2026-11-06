/* Candidate: full 0x0c12f848..0x0c12fab0 extent, five callback entries.
 * 607/616 bytes match. Remaining: call-target register at 0c12f9b2/9b8;
 * countdown register and branch scheduling at 0c12f9f6..0c12f9fe.
 * Callback table 0c24e164..0c24e174 independently identifies 12f9d4.
 * The global at 0c2f8338 is inline, not a pointer; stack vector is 12 bytes.
 */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct Dat_13bb5c dat_0c2f8338;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c1bee94(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern signed char func_0c02a026(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c1c1678(struct Actor *, void *, int);
extern void (*dat_0c24e178[])(struct Actor *);
extern void func_0c13150c(struct Actor *);
extern void func_0c1beeec(struct Actor *);

void func_0c12f848(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 0x10;
    }
    a->b6 = a->b6 + 1;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->s28 = a->b37 * 5;
    a->b1a1 = 0x52;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2] += 1;
    func_0c1bee94(a);
    func_0c02a0c4(a, 22, 5);
}

void func_0c12f8dc(struct Actor *a)
{
    struct LinkedActorVec3 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b140) {
        if ((signed char)a->b140 < 0)
            func_0c02a39a(a, 1);
        else
            func_0c02a684(a, 0, a->s28 + ((unsigned char)a->b14b), 1);
    }
    if (a->b141) {

        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        (*(int *)((char *)a+0x2c4)) = 0x258;
        func_0c02a39a(a, 1);
        v.x = 0;
        v.y = 137.142853f;
        func_0c0429a4(a, &v, 1);
        func_0c1c1678(a, (char *)&a->sub2a4 + 32, 6);
    }
}

void func_0c12f9d4(struct Actor *a);
void func_0c12f9c4(struct Actor *a)
{
    a->b6++;
    a->b32 = 0;
    a->w352 = 0;
    func_0c12f9d4(a);
}
void func_0c12f9d4(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (dat_0c2f8338.pad[3] != 0 || dat_0c2f8338.pad[0] == 5 || --(*(int *)((char *)a+0x2c4)) <= 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        func_0c02a0c4(a, 22, 11);
    } else {
        dat_0c24e178[a->b32](a);
    }
}

void func_0c12fa36(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c13150c(a);
    } else if (a->b141) {
        a->b141 = 0;
        func_0c1beeec(a);
    }
}
