#include "objects.h"

struct V3 { float x, y, z; };

struct Obj_0c1d9ac0 {
    unsigned char pad0[16];
    void (*p10)(struct Obj_0c1d9ac0 *);
    unsigned char pad1[52 - 20];
    struct V3 v52;
    unsigned char pad1b[4];
    int l44;
    unsigned char pad2[0x84 - 0x48];
    int l84;
    unsigned char pad3[0xcc - 0x88];
    int lcc;
    unsigned char pad4[0x12c - 0xd0];
    unsigned char b12c;
};

struct Inner_0c1d9ac0 {
    int a0;
    int a4;
    int f8;
    unsigned char pad[52 - 12];
    int f52;
};

struct Mid_0c1d9ac0 {
    struct Inner_0c1d9ac0 *p0;
};

extern struct Obj_0c1d9ac0 *func_0c0374da(int, int, int);
extern struct Mid_0c1d9ac0 *dat_0c2d964c;
extern struct V3 dat_0c261cbc[];

void func_0c1d9adc(int b);
void func_0c1d9b46(struct Obj_0c1d9ac0 *a);

void func_0c1d9ac0(void)
{
    int i = 0;

    do {
        func_0c1d9adc(i);
        i = i + 1;
    } while (i < 4);
}

void func_0c1d9adc(int b)
{
    struct Obj_0c1d9ac0 *r;

    if ((r = func_0c0374da(0, 5, 1)) != 0) {
        r->b12c = 1;
        r->p10 = func_0c1d9b46;
        if (b < 2)
            r->l84 = dat_0c2d964c->p0->f8;
        else
            r->l84 = dat_0c2d964c->p0->f52;
        r->lcc = 0x805;
        r->v52 = dat_0c261cbc[b];
    }
}

void func_0c1d9b46(struct Obj_0c1d9ac0 *a)
{
    a->l44 = a->l44 + 0x200;
}
