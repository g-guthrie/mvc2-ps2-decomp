#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f837e, table_0c2434ac[], table_0c2434b0[];
extern ActorHandler table_0c243488[], table_0c24349c[], table_0c2434b4[];
extern void (*table_0c2434e4[])(struct Actor *, struct ActorSub2a4 *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c19d2ac(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c043628(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
void func_0c09a34c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { a->b5++; return; }
    if (a->b141) {
        a->b141 = 0;
        func_0c19d2ac(a, 9, a->s30 == 0 ? 0 : 1);
    }
}
void func_0c09a392(struct Actor *a)
{
    if (func_0c03916c(a)) func_0c0437b8(a);
    else table_0c243488[a->b32](a);
}
void func_0c09a3be(struct Actor *a) { table_0c24349c[a->b6](a); }
void func_0c09a3d0(struct Actor *a)
{
    if (dat_0c2f837e) a->s28 = table_0c2434ac[dat_0c2d6f84->flags & 3];
    else a->s28 = table_0c2434b0[dat_0c2d6f84->flags & 3];
    if (func_0c043628(a) >= 2) a->s28 = 2;
    switch (a->s28) {
    case 0: a->b6++; a->b158 = 0; break;
    case 1: a->b6 += 2; a->b158 = 1; func_0c02a684(a, 5, 0, 1); break;
    case 2: a->b6 += 3; a->b158 = 2; break;
    }
    func_0c02a0c4(a, 19, a->b158);
}
void func_0c09a498(struct Actor *a) { func_0c02a026(a); }
void func_0c09a49e(struct Actor *a)
{
    a->b326 = 255;
    func_0c02a026(a);
    switch ((char)a->b141) {
    case 1: a->b141 = 0; func_0c19d2ac(a, 10, 0); func_0c0346da(a, 73); break;
    case 2: a->b141 = 0; func_0c19d2ac(a, 11, 0); break;
    }
}
void func_0c09a4f4(struct Actor *a) { func_0c02a026(a); }
void func_0c09a4fa(struct Actor *a)
{
    if (a->b6 == 0) { a->b6++; func_0c02a0c4(a, 19, 3); }
    else func_0c02a026(a);
}
void func_0c09a514(struct Actor *a) { table_0c2434b4[a->b1e9](a); }
void func_0c09a528(struct Actor *a) { table_0c2434e4[a->b6](a, &a->sub2a4); }
void func_0c09a53e(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 0);
}
