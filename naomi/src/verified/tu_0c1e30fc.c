#include "objects.h"

struct Vec_0c1e30fc {
    float x, y, z;
};

struct Obj_0c1e30fc {
    unsigned char pad0[16];
    void (*p16)(struct Obj_0c1e30fc *);
    unsigned char pad1[52 - 20];
    struct Vec_0c1e30fc v52;
    unsigned char pad2[68 - 64];
    int l44;
    unsigned char pad3[0x84 - 72];
    void *p84;
    unsigned char pad4[0xcc - 0x88];
    int lcc;
    unsigned char pad5[0x12c - 0xd0];
    unsigned char b12c;
};

struct Glob_0c1e30fc {
    unsigned char pad[16];
    void *p16;
};

extern struct Obj_0c1e30fc *func_0c0374da(int, int, int);
extern struct Vec_0c1e30fc dat_0c26337c;
extern struct Glob_0c1e30fc **dat_0c2d964c;
extern void func_0c1e2fb0(struct Obj_0c1e30fc *);
extern void func_0c1e28b4(struct Obj_0c1e30fc *);

void func_0c1e30fc(void)
{
    struct Obj_0c1e30fc *a;

    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e2fb0;
        a->p84 = (**dat_0c2d964c).p16;
        a->v52 = dat_0c26337c;
        a->l44 = 0xcaac;
        a->lcc = 0x805;
        func_0c1e28b4(a);
    }
}
