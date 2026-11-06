/* Charge-and-release state handlers (table 0x0c24d710 entries 0-3). */
#include "objects.h"
struct ActorSubCharge33 { unsigned char pad0[8]; char b8, b9, b10; unsigned char pad11[20]; unsigned char b31; signed char b32; };
struct Vec3f { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const unsigned char dat_0c24d700[];
extern void (*const table_0c24d710[])(struct Actor *, struct ActorSubCharge33 *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c12357e(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c1d5a0a(struct Vec3f *, char);
#define CALLARG (char)a->b1d2 ^ 1
void func_0c124b60(struct Actor *a, struct ActorSubCharge33 *s);
void func_0c1249a8(struct Actor *a, struct ActorSubCharge33 *s);

void func_0c1248fc(struct Actor *a, struct ActorSubCharge33 *s)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    goto LL; LL:
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    s->b31 = 0;
    s->b32 = 0;
    a->s28 = 60;
    a->s30 = 0;
    a->b1a1 = 76;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 4);
    func_0c1249a8(a, s);
    func_0c0344a0(a, 45);
}

void func_0c1249a8(struct Actor *a, struct ActorSubCharge33 *s)
{
    struct Vec3f v;
    int sound;
    func_0c0442fa(a);
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        a->b1a1 = 76;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    func_0c124b60(a, s);
    if (a->w34e & 0x360)
        s->b32++;
    if (!a->s28--) {
        if (s->b32 >= 8) {
            if (s->b31 < 3) {
                s->b31++;
                func_0c02a0c4(a, 20, (char)s->b31 + 4);
                switch (s->b31) {
                case 1: sound = 4; break;
                case 2: sound = 6; break;
                case 3: sound = 20; break;
                }
                func_0c0344a0(a, sound);
            }
            s->b32 = 0;
            a->s28 = 60;
        } else
            a->b6++;
    }
    if (s->b31 >= 3) {
        v.x = 53.3333321f;
        if (a->w130)
            v.x = -v.x;
        v.x += a->f52;
        v.y = a->f56 + 171.42856f;
        v.z = 0.0f;
        if (!(a->s28 & 15)) {
            func_0c1d5a0a(&v, CALLARG);
            func_0c0346da(a, 75);
        }
    }
}

void func_0c124af8(struct Actor *a, struct ActorSubCharge33 *s)
{
    func_0c124b60(a, s);
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c02a0c4(a, 20, 8);
        s->b9 = 0;
        s->b10 = 0;
    }
}

void func_0c124b32(struct Actor *a)
{
    func_0c12357e(a);
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0437b8(a);
    }
}

void func_0c124b60(struct Actor *a, struct ActorSubCharge33 *s)
{
    unsigned char t;
    if (!s->b8 && s->b31) {
        a->s30++;
        t = dat_0c24d700[s->b31 * 4 + (a->s30 & 3)];
        func_0c02a684(a, 0, a->b37 * 6 + t + 90, 1);
    }
}

void func_0c124bb8(struct Actor *a, struct ActorSubCharge33 *s)
{
    table_0c24d710[a->b6](a, s);
}
