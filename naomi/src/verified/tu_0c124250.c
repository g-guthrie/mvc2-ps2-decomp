/* Shot-state handlers 0x0c124250..0x0c12476c. */
#include "objects.h"
/* Per-actor shot-state bytes passed to the 0x0c124250 handlers. */
struct ActorSubShot22 { unsigned char pad0[2]; unsigned char b2; unsigned char pad3[8]; char b11; unsigned char pad12[7]; unsigned char b19; unsigned char pad20; unsigned char b21; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c1852e0(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c044548(struct Actor *, struct Actor *);
extern void func_0c044450(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1bc740(struct Actor *, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void (*table_0c24d6c0[])(struct Actor *);
extern void (*table_0c24d6d8[])(struct Actor *);
extern void (*table_0c24d6e0[])(struct Actor *);
void func_0c124586(struct Actor *a, struct ActorSubShot22 *p);
void func_0c12468c(struct Actor *a, struct ActorSubShot22 *p);

void func_0c124250(struct Actor *a, struct ActorSubShot22 *p)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b7++;
        a->f92 = -1.66666663f;
        if (a->w130)
            a->f92 = -a->f92;
        func_0c1852e0(a, 0, 0);
        func_0c1852e0(a, 0, 1);
        func_0c1852e0(a, 0, 2);
        func_0c1852e0(a, 1, 0);
        p->b2 = 1;
        a->s30 = 16;
        p->b11 = 0;
    }
}

void func_0c1242d4(struct Actor *a, struct ActorSubShot22 *p)
{
    void *zero;
    struct Actor *q;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c124586(a, p);
    zero = 0;
    if (!(a->s28 & 15)) {
        a->b1a1 = 57;
        a->w1ac = (int)zero;
        a->b19e = (int)zero;
        *(void **)&a->p1c4 = zero;
        dat_0c2f83f8->arr[a->b2]++;
    }
    if (!a->s28--) {
        a->b7++;
        func_0c02a0c4(a, 22, 13);
        p->b19 = 1;
        p->b2 = (int)zero;
        a->b3f9 = (int)zero;
        a->b3f8 = (int)zero;
        a->b327 = (int)zero;
        a->b328 = (int)zero;
        return;
    }
    if (func_0c0447bc(a)) {
        a->b6++;
        a->b7 = (int)zero;
        a->b1f7 = 4;
        a->b1f7 |= 0x40;
        a->b1f7 |= 0x80;
        q = a->p1b0;
        func_0c044548(a, q);
        q->b6 = (int)zero;
        q->f92 = q->f96 = q->f104 = q->f108 = 0.0f;
        p->b21 = (int)zero;
        a->s28 = 80;
    }
}

void func_0c124404(struct Actor *a)
{
    if (func_0c02a026(a) >= 0)
        return;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0437b8(a);
}

void func_0c124436(struct Actor *a) { table_0c24d6c0[a->b7](a); }

void func_0c124460(struct Actor *a, struct ActorSubShot22 *p)
{
    void *zero;
    struct Actor *q;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c124586(a, p);
    if (!a->s28--) {
        a->b7++;
        zero = 0;
        q = a->p1c8;
        q->p1b4 = a;
        q->b1a1 = 36;
        a->b1a1 = 36;
        q->b1f6 = 15;
        q->b6 = (int)zero;
        a->b205 = p->b21 / 4 + 32;
        func_0c02a0c4(a, 22, 30);
        func_0c1bc740(a, 1, 0);
        p->b19 = 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->b3f9 = (int)zero;
        a->b3f8 = (int)zero;
        a->b327 = (int)zero;
        a->b328 = (int)zero;
    }
}

void func_0c12452e(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c124550(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    table_0c24d6d8[a->b7](a);
}

void func_0c124574(struct Actor *a) { table_0c24d6e0[a->b6](a); }

void func_0c124586(struct Actor *a, struct ActorSubShot22 *p)
{
    if (!a->s30--) {
        a->s30 = 16;
        p->b11 ^= 1;
        a->f92 = !p->b11 ? -0.1041666642f : 0.1041666642f;
    }
}

void func_0c1245e0(struct Actor *a, struct ActorSubShot22 *p)
{
    void *zero;
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c048bb0(a, 5);
    zero = 0;
    a->b1f9 = (int)zero;
    a->f56 = a->f41c;
    a->f92 = -13.33333302f;
    a->f104 = 0.625f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    a->b1a1 = 77;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(void **)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 15, 17);
    func_0c12468c(a, p);
}

void func_0c12468c(struct Actor *a, struct ActorSubShot22 *p)
{
    register float fzero;
    struct Actor *q;
    func_0c02a026(a);
    fzero = 0.0f;
    if (a->b141 & 1) {
        a->f52 += a->f92;
        a->f92 += a->f104;
    }
    if (a->b141 & 2) {
        a->f92 = fzero;
        a->f96 = fzero;
        a->f104 = fzero;
        a->f108 = fzero;
        a->b6++;
        return;
    }
    if (func_0c0447bc(a)) {
        q = a->p1b0;
        a->b1f7 = 2;
        a->b1f7 |= 0x40;
        a->b1f7 |= 0x80;
        a->b7 = 0;
        a->b6 = 0;
        q->f108 = fzero;
        q->f104 = fzero;
        q->f96 = fzero;
        q->f92 = fzero;
        func_0c044450(a, q);
    }
}
