#include "objects.h"

struct Obj_0c1ca784 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c1ca784 *);
    unsigned char pad2[0x20 - 20];
    unsigned char b32;
    unsigned char pad3[0x74 - 0x21];
    float f74;
    unsigned char pad4[0x84 - 0x78];
    void *p84;
    unsigned char pad5[0xcc - 0x88];
    int lcc;
    unsigned char pad6[0x12c - 0xd0];
    unsigned char b12c;
};

struct Hold_0c1ca784 { int *row; };

extern struct Obj_0c1ca784 *func_0c0374da(int, int, int);
extern int dat_0c2309c4[];
extern struct Hold_0c1ca784 *dat_0c2d9670;

void func_0c1ca7d8(struct Obj_0c1ca784 *a);

void func_0c1ca784(int param)
{
    struct Obj_0c1ca784 *a;

    if ((a = func_0c0374da(0, 11, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1ca7d8;
        a->p84 = (void *)dat_0c2d9670->row[dat_0c2309c4[param]];
        a->b32 = param;
        a->lcc = 0x820;
        a->f74 = 0.0f;
    }
}

void func_0c1ca7d8(struct Obj_0c1ca784 *a)
{
    switch (a->b4) {
    case 0:
        a->f74 += 0.200000003f;
        if (a->f74 >= 1.0f) {
            a->b4 = a->b4 + 1;
            a->f74 = 1.0f;
        }
        break;
    case 1:
        break;
    }
}
