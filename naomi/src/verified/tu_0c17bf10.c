#include "objects.h"

struct Obj_0c17bf10 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c17bf10 *);
    struct Obj_0c17bf10 *p20;
    struct Obj_0c17bf10 *p24;
    unsigned char pad2[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad3[38 - 34];
    unsigned short w38;
};

typedef void (*Handler_0c17bf10)(struct Obj_0c17bf10 *, struct Obj_0c17bf10 *);

extern struct Obj_0c17bf10 *func_0c0374da(int, int, int);
extern Handler_0c17bf10 dat_0c253c08[];

void func_0c17bfa2(struct Obj_0c17bf10 *p);

struct Obj_0c17bf10 *func_0c17bf10(struct Obj_0c17bf10 *parent, unsigned char kind)
{
    struct Obj_0c17bf10 *a;
    struct Obj_0c17bf10 *b;

    if ((a = func_0c0374da(0, 1, 0)) != 0) {
        a->p16 = func_0c17bfa2;
        a->p24 = parent;
        a->p20 = a;
        a->b32 = kind;
        a->b33 = 0;
        a->w38 = 0x3401;
    }
    if ((b = func_0c0374da((int)a, 1, 2)) != 0) {
        b->p16 = func_0c17bfa2;
        b->p24 = parent;
        b->p20 = a;
        b->b32 = kind;
        b->b33 = 1;
        b->w38 = 0x3401;
    }
    if ((b = func_0c0374da((int)a, 1, 2)) != 0) {
        b->p16 = func_0c17bfa2;
        b->p24 = parent;
        b->p20 = a;
        b->b32 = kind;
        b->b33 = 2;
        b->w38 = 0x3401;
    }
    return a;
}

void func_0c17bfa2(struct Obj_0c17bf10 *p)
{
    dat_0c253c08[p->b4](p, p->p24);
}
