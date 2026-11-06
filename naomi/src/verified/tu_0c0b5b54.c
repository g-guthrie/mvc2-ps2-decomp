#include "objects.h"
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0b4aa0(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0b4a70(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c155740(struct Actor *, int);
extern int func_0c02849a(void);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c244f18[])(struct Actor *);
extern void (*table_0c244f28[])(struct Actor *);
extern int (*table_0c244f30[])(struct Actor *);

/* Per-character work words overlaying the actor's 0x2a4 block. */
struct ActorWork2ac { unsigned char pad[0x2ac]; int l2ac, l2b0, l2b4, l2b8; };
#define L2AC(a) (((struct ActorWork2ac *)(a))->l2ac)
#define L2B0(a) (((struct ActorWork2ac *)(a))->l2b0)
#define L2B4(a) (((struct ActorWork2ac *)(a))->l2b4)
#define L2B8(a) (((struct ActorWork2ac *)(a))->l2b8)

void func_0c0b5c02(struct Actor *a);
void func_0c0b5d48(struct Actor *a);
void func_0c0b5e1e(struct Actor *a);

void func_0c0b5b54(struct Actor *a)
{
    a->b6++;
    func_0c048bb0(a, 5);
    a->b1a1 = 55;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    if (a->b1f9 == 2) {
        func_0c0442fa(a);
        func_0c02a39a(a, 0);
        a->b158 = 1;
        a->f92 /= 16.0f;
        a->f96 /= 8.0f;
        a->f108 /= 64.0f;
        a->f104 = 0.0f;
    } else {
        a->b158 = 0;
        func_0c0b4aa0(a);
    }
    func_0c02a0c4(a, 21, a->b158);
    func_0c0344a0(a, 5);
    func_0c0b5c02(a);
}

void func_0c0b5c02(struct Actor *a)
{
    int k;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c0b4a70(a);
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 != 2)
            func_0c0437b8(a);
        else
            func_0c0438de(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        L2B4(a) = 1;
        k = 0;
        goto q; q:
        if (L2B0(a))
            L2B4(a) = 0;
        if (a->b1f9 == 2)
            k = 2;
        func_0c155740(a, k);
        L2B8(a) = 1;
    }
}

void func_0c0b5cf0(struct Actor *a){table_0c244f18[a->b6](a);}

void func_0c0b5d02(struct Actor *a)
{
    a->b6++;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1fc = 0;
    a->b1f9 = 0;
    func_0c02a0c4(a, 20, 2);
    func_0c0b5d48(a);
}

void func_0c0b5d48(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c02a0c4(a, 20, 3);
    }
}

void func_0c0b5d72(struct Actor *a)
{
    func_0c0b5e1e(a);
    if (func_0c02a026(a) < 0) {
        if (a->b525) {
            if (func_0c02849a() & 1)
                L2AC(a) = 1;
            else
                L2AC(a) = 0;
        }
        if (L2AC(a) >= 1) {
            func_0c02a0c4(a, 20, 3);
        } else {
            a->b6++;
            func_0c02a0c4(a, 20, 4);
        }
        L2AC(a) = 0;
    }
}

void func_0c0b5dfc(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0b5e1e(struct Actor *a)
{
    if (a->w348 & 0x8000)
        L2AC(a)++;
}

void func_0c0b5e36(struct Actor *a){table_0c244f28[a->b6](a);}

void func_0c0b5e48(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 63;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 23);
}

void func_0c0b5eb6(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 == 15) {
        a->b141 = 0;
        v.x = 26.666666031f;
        v.y = 85.71428f;
        func_0c043014(a, &v);
    }
}

int func_0c0b5f02(struct Actor *a){return table_0c244f30[a->b1f9](a);}
