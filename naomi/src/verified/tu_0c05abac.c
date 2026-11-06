#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c23f9d4[])(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c0346da(struct Actor *, int);
extern void (*table_0c23f9dc[])(struct Actor *);
void func_0c05abac(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (a->b14b == 0) {
        a->b1f9 = 2;
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->f96 < 0.0f) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        a->f96 = -8.5714283f;
        a->f108 = -0.5357143f;
        func_0c02a0c4(a, 21, 13);
    }
    if (a->b141) {
        a->b1a1 = a->b141;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b141 = 0;
    }
    (void)func_0c02a026(a);
}
void func_0c05ac7c(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 1, 3);
        return;
    }
    (void)func_0c02a026(a);
}
void func_0c05acea(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c05ad3c(struct Actor *a)
{
    table_0c23f9d4[a->b6](a);
}
void func_0c05ad4e(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    (void)func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 58;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 16);
}
void func_0c05adc4(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b140) {
        a->b140 = 0;
        position.x = 66.666664124f;
        position.y = 205.71428f;
        func_0c043014(a, &position);
    }
    if (a->b14b) {
        func_0c0346da(a, 22);
        a->b14b = 0;
    }
}
void func_0c05ae24(struct Actor *a)
{
    table_0c23f9dc[a->b6](a);
}
