/* Complete 668-byte retail span at 0x0c1190dc. Code at 0x0c119210 is a
 * continuation of func_0c1191d4 across the first pool, not a separate entry.
 * func_0c11932a's identical case stores must not be a named local: a local
 * lands in r6 and the tail call then uses r3. */
#include "objects.h"
struct ActorFlagsGlobal { unsigned char pad[5]; unsigned char b5, b6; };
typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);
extern struct ActorFlagsGlobal dat_0c2d9260;
extern ActorSubHandler dat_0c24b6a8[];
extern ActorHandler table_0c24b6b0[];
extern ActorHandler dat_0c24b6bc[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(void *, int, int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c172474(struct Actor *, int, int);
extern void func_0c17aabc(struct Actor *, int, int);
struct Sub2a4_tu1_12 { unsigned char pad[10]; short s10; };
struct Obj_tu1_12 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[20 - 8];
    struct Obj_tu1_12 *p20;
    unsigned char pad2[28 - 24];
    short s28;
    unsigned char pad3[52 - 30];
    float f52, f56;
    unsigned char pad4[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad5[0x130 - 112];
    short w130;
    unsigned char pad6[0x2a4 - 0x132];
    struct Sub2a4_tu1_12 sub2a4;
};
struct Glob_0c2f83f8 { unsigned char b0; };
typedef void (*fn_tu1_12)(struct Obj_tu1_12 *, struct Sub2a4_tu1_12 *);
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern fn_tu1_12 dat_0c244544[];
extern fn_tu1_12 dat_0c24cbfc[];
extern int func_0c026a86(void);
extern ActorHandler table_0c24cc04[];
struct Obj_0c07c778 {
    unsigned char pad0[34];
    unsigned char b34;
    unsigned char pad1[52 - 35];
    float f52, f56;
    unsigned char pad2[0x1a3 - 60];
    unsigned char b1a3;
    unsigned char pad3[0x1f7 - 0x1a4];
    unsigned char b1f7;
    unsigned char pad4[0x1fa - 0x1f8];
    unsigned short w1fa;
    unsigned char pad5[0x1fe - 0x1fc];
    char b1fe;
};
typedef void (*handler_0c07c778)(struct Obj_0c07c778 *);
extern struct Obj_0c07c778 *func_0c037d54(struct Obj_0c07c778 *);
extern handler_0c07c778 dat_0c24cc10[];
void func_0c07c7d8(struct Obj_0c07c778 *p);

void func_0c1190dc(struct Actor *a)
{
    struct Actor *child = a->p1c8;

    func_0c02a026(a);
    if (a->b141 == 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        if (a->b1fd || child->b1fd) {
            a->b6 = a->b6 + 1;
            func_0c02a0c4(a, 15, 1);
            a->s28 = 56;
        }
    }
}

void func_0c119142(struct Actor *a)
{
    struct Actor *child;

    func_0c02a026(a);
    if (--a->s28 == 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c17aabc(a, 1, 9);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x20;
        a->b1a1 = 0x20;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
    }
}

void func_0c1191be(struct Obj_tu1_12 *a)
{
    dat_0c24cbfc[a->b6](a, &a->sub2a4);
}

void func_0c1191d4(struct Actor *a)
{
    struct Actor *child;

    if (func_0c02a026(a) < 0) {
        func_0c0438de(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c17aabc(a, 1, 7);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x21;
        a->b1a1 = 0x21;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
    }
}

void func_0c11926c(struct Actor *a)
{
    struct Actor *child;

    func_0c02a026(a);
    if (--a->s28 == 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c17aabc(a, 1, 9);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        child = a->p1c8;
        child->b1f6 = 1;
        child->b1f9 = 2;
        child->b1a1 = 0x22;
        a->b1a1 = 0x22;
        child->b1d2 = a->b1d2;
        child->b1d2 ^= 1;
    }
}

void func_0c1192e8(struct Actor *a)
{
    a->b1ea = 1;
    table_0c24cc04[a->b1f7](a);
}

void func_0c119304(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c119312(struct Obj_0c07c778 *p)
{
    dat_0c24cc10[p->b1f7 & 63](p);
}

void func_0c11932a(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0:
    case 1:
        a->b1e9 = 1;
        break;
    case 2:
        a->b1e9 = 1;
        break;
    }
    func_0c045248(a, 29);
}
