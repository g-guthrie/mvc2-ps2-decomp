#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, void *, int);
extern int func_0c03916c(struct Actor *);
extern int func_0c1335f8(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0437b8(struct Actor *), func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void *table_0c23fdbc[];
extern void (*table_0c23ffe8[])(struct Actor *);
extern void (*table_0c240000[])(struct Actor *);
extern void (*table_0c240014[])(struct Actor *);
extern void (*table_0c240054[])(struct Actor *);
extern void (*table_0c24005c[])(struct Actor *);
extern void (*table_0c240064[])(struct Actor *);
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c061148(struct Actor *a);

void func_0c06108c(struct Actor *a)
{
    a->b326 = 0xff;
    func_0c03916c(a);
    func_0c02a026(a);
    if (a->b141)
        func_0c02a684(a, 0, table_0c23fdbc[a->b37], 1);
}

void func_0c0610cc(struct Actor *a) { table_0c23ffe8[a->b33](a); }

void func_0c0610e0(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;

    goto check;
check:
    if (func_0c03916c(a)) {
        p[12] = 0;
        func_0c0437b8(a);
        return;
    }
    func_0c02a026(a);
}

void func_0c061116(struct Actor *a) { table_0c240000[a->b32](a); }

void func_0c06112a(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;
    p[12] = 0;
    table_0c240014[a->b1e9](a);
}

void func_0c061148(struct Actor *a)
{
    int zero;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1fc = zero;
    a->b1f9 = zero;
    a->f56 = a->f41c;
    func_0c0442fa(a);
}

void func_0c061170(struct Actor *a) { table_0c240054[a->b6](a); }

void func_0c061182(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;
    p[12] = 10;
    table_0c24005c[a->b7](a);
}

void func_0c0611d8(struct Actor *a)
{
    int zero;
    a->b7++;
    zero = 0;
    a->b1a1 = 55;
    CLEAR_RECORD;
    func_0c048bb0(a, 5);
    func_0c061148(a);
    func_0c0432ca(a);
    a->b158 = a->b1a3;
    func_0c02a0c4(a, 21, a->b158);
}

void func_0c061232(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;
    if (a->b141) {
        int zero = 0;
        a->b141 = zero;
        if (func_0c1335f8(a, zero, zero)) {
            ((struct ActorSubMoveBytes *)p)->b26 = 1;
            func_0c0344a0(a, 30);
        }
    }
    if (func_0c02a026(a) < 0) {
        p[12] = 0;
        func_0c0437b8(a);
    }
}

void func_0c06128a(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;
    p[12] = 11;
    table_0c240064[a->b7](a);
}

void func_0c0612a6(struct Actor *a)
{
    int zero;
    a->b7++;
    zero = 0;
    a->b1a1 = 56;
    CLEAR_RECORD;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->b1f9 = 2;
    a->f92 /= 8.0f;
    a->f104 /= 8.0f;
    a->f96 /= 8.0f;
    a->f108 /= 8.0f;
    a->b158 = a->b1a3 + 2;
    func_0c02a0c4(a, 21, a->b158);
}
