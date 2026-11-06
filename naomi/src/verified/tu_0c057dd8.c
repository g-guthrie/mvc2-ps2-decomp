#include "objects.h"

struct Vec3_0c057dd8 { float x, y, z; };
struct C150 { unsigned char pad[0x150]; unsigned char b150; };
struct C1d2 { unsigned char pad[0x1d2]; char b1d2; };
struct B1a3 { unsigned char pad[0x1a3]; unsigned char b1a3; };
typedef void (*ActorHandler)(struct Actor *);

extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern ActorHandler table_0c23f7e0[];
extern void func_0c056bb8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c04b5cc(struct Actor *, int, int, int);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c057dd8 *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c044548(struct Actor *, struct Actor *);
extern short table_0c23f7f8[];

void func_0c057dd8(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        func_0c043324(a);
        a->b7++;
        func_0c02a0c4(a, 15, 34);
    }
}

void func_0c057e52(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b205 = 0;
        func_0c0437b8(a);
    }
}

void func_0c057e78(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->b205 = 0;
        func_0c0438de(a);
        return;
    }
    if (a->f56 < a->f41c)
        a->f56 = a->f41c;
}

void func_0c057eec(struct Actor *a)
{
    table_0c23f7e0[a->b6](a);
}

void func_0c057efe(struct Actor *a)
{
    a->b6++;
    func_0c056bb8(a);
    func_0c048bb0(a, 10);
    if (a->b255 == 8)
        func_0c02a0c4(a, 15, 61);
    else
        func_0c02a0c4(a, 15, 22);
    func_0c04b5cc(a, 10, 30, 60);
}

void func_0c057f6c(struct Actor *a)
{
    struct Actor *p;
    struct Actor *r;
    struct Vec3_0c057dd8 v;
    float k;
    short *t;

    r = a;
    r->w3e4 = 2;
    if ((&((struct C150 *)r)->b150)[1]) {
        func_0c02a026(r);
        if ((p = func_0c037d54(r)) == 0)
            return;
        r->b6 = 4;
        r->b7 = 0;
        v.x = -146.66666f;
        v.y = 171.42856f;
        func_0c1d4610(r, &v);
        func_0c025900(r, 5, 5);
        r->b1f7 = 0xc5;
        func_0c02a0c4(r, 15, 24);
        func_0c044548(r, p);
        return;
    }
    r->b6++;
    t = table_0c23f7f8;
    k = 0.013020833023f;
    if (!r->b202) {
        if (r->b255 == 8) {
            r->f92 = 5.0f;
            r->f104 = 0;
        } else {
            r->f92 = 5.83333302f;
            r->f104 = k;
        }
        r->s28 = t[((struct B1a3 *)r)->b1a3];
    } else {
        r->f92 = 3.3333333f;
        r->f104 = k;
        r->s28 = t[((struct B1a3 *)r)->b1a3 + 2];
    }
    if (!((struct C1d2 *)r)->b1d2) {
        r->f92 = -r->f92;
        r->f104 = -r->f104;
    }
}
