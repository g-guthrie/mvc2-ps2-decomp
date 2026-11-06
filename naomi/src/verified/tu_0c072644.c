#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0438de(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c241100[])(struct Actor *);
void func_0c072644(struct Actor *a)
{
    if (a->b141) { a->b141 = 0; func_0c0346da(a, 22); }
    if (func_0c02a026(a) < 0) func_0c0438de(a);
    else if (func_0c044e52(a)) func_0c044f1c(a);
}
void func_0c072690(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->f96 = -21.42857f;
        a->f108 = 0;
        if (a->b1fc) a->f96 = -27.8571415f;
        a->f92 = 0;
        a->f104 = 0;
    }
}
void func_0c0726da(struct Actor *a)
{
    unsigned char direction;
    func_0c02a026(a);
    if (a->b19e) {
        a->f92 = 5.83333302f;
        a->f104 = 0;
        a->f96 = 15.0f;
        a->f108 = -1.07142854f;
        if (a->b1d2) a->f92 = -a->f92;
        a->b1d3 = -1;
        direction = a->b1d2;
        func_0c0438de(a);
        a->b1d2 = direction;
        a->w130 = direction;
    } else if (a->f56 < a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c043324(a);
        func_0c02a0c4(a, 1, 3);
    }
}
void func_0c0727ba(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c0727dc(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        a->b1f9 = 0;
        a->b1a1 = 20;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c044cbc(a);
        func_0c048bb0(a, 5);
        func_0c02a0c4(a, 20, 1);
        func_0c0346da(a, 22);
    }
    if (a->b1ff == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
void func_0c0728a2(struct Actor *a) { table_0c241100[a->b6](a); }
