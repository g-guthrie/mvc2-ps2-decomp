#include "objects.h"

/* View the source record as 32-bit words so SHC preserves the pointer
 * temporary used by the retail call at 0x0c1e1648. */
struct Obj_tu3_05 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_tu3_05 *);
    unsigned char pad2[28 - 20];
    short s28;
    unsigned char pad3[0x84 - 30];
    int l84;
    unsigned char pad4[0xcc - 0x88];
    int l0cc;
    unsigned char pad5[0x12c - 0xd0];
    unsigned char b12c;
};

extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Obj_tu3_05 *func_0c0374da(int, int, int);
extern void func_0c1d91a8(int);
extern void func_0c1d8ff8(int, int);
extern int func_0c1d901e(void);
extern void func_0c1d912a(float *, float *);
extern void func_0c1d917e(float *, float *);

void func_0c1e1610(struct Obj_tu3_05 *a);

void func_0c1e15cc(void)
{
    struct Obj_tu3_05 *a;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e1610;
        a->l84 = ((int *)dat_0c2d964c->p0)[34];
        a->l0cc = 0x800;
        func_0c1d91a8(a->l84);
    }
}

void func_0c1e1610(struct Obj_tu3_05 *a)
{
    float y, x;
    switch (a->b4) {
    case 0:
        a->s28 = a->s28 + 1;
        if (a->s28 >= 200)
            a->s28 = 0;
        func_0c1d8ff8(((int *)dat_0c2d964c->p0)[35], a->l84);
        while (func_0c1d901e() == 0) {
            func_0c1d912a(&x, &y);
            y += (float)a->s28 * 0.005f;
            func_0c1d917e(&x, &y);
        }
        break;
    }
}
