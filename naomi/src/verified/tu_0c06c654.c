#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c240960[])(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c0344a0(struct Actor *, int);
extern void (*table_0c240968[])(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
void func_0c06c654(struct Actor *a, struct ActorSub2a4 *target)
{
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2) {
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            a->f108 = -0.80357140303f;
            func_0c0438de(a);
        } else {
            a->b1f9 = 0;
            func_0c0437b8(a);
        }
        return;
    }
    if (a->b141 == 0) {
        a->b141 = 0;
        target->b2 = 1;
        a->b27b = 0;
        a->b27a = 16;
    }
}
void func_0c06c6d6(struct Actor *a)
{
    table_0c240960[a->b6](a);
}
void func_0c06c6e8(struct Actor *a)
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
    a->b1a1 = 88;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 54);
}
void func_0c06c75e(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b14b & 1) {
        a->b14b = 0;
        position.x = -21.666666031f;
        position.y = 197.142853f;
        position.z = 0.0f;
        func_0c043014(a, &position);
    } else if (a->b14b & 2) {
        a->b14b = 0;
        func_0c0344a0(a, 30);
    }
}
void func_0c06c7fe(struct Actor *a)
{
    table_0c240968[a->b6](a);
}
void func_0c06c810(struct Actor *a)
{
    (void)func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 51;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
void func_0c06c88a(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
    }
}
