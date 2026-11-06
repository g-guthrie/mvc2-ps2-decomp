#include "objects.h"

struct Vec3_19cc70 { float x, y, z; };
struct Block_19cc70 {
    unsigned char pad0[0x50];
    unsigned char b12c;
    unsigned char pad1[0x54 - 0x51];
    short w130;
    unsigned char pad2[0xc0 - 0x56];
};
struct Rec_19cc70 {
    unsigned char b0;
    unsigned char pad[3];
    float f4;
    short s8, s10;
};
struct Dat_19cc70 {
    unsigned char pad[0x88];
    float f88, f8c;
};
struct Obj_19cc70 {
    unsigned char pad0;
    unsigned char b1, b2;
    unsigned char pad1;
    unsigned char b4;
    unsigned char b5;
    unsigned char pad2[16 - 6];
    void (*p16)(struct Obj_19cc70 *);
    unsigned char pad3[24 - 20];
    struct Obj_19cc70 *p24;
    short s28, s30;
    unsigned char b32;
    unsigned char pad4[36 - 33];
    unsigned char b36;
    unsigned char pad5;
    unsigned short w38;
    unsigned char pad6[48 - 40];
    unsigned char b48;
    unsigned char pad7[52 - 49];
    float f52, f56;
    unsigned char pad8[80 - 60];
    struct Vec3_19cc70 v80;
    float f92, f96, f100, f104, f108;
    unsigned char pad9[0xdc - 112];
    struct Block_19cc70 sdc;
    unsigned char pad10[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
    unsigned char pad11[0x41c - 0x1a5];
    float f41c;
};

typedef void (*Handler_19cc70)(struct Obj_19cc70 *);
typedef void (*Handler2_19cc70)(struct Obj_19cc70 *, struct Obj_19cc70 *);

extern struct Obj_19cc70 *func_0c0374da(int, int, int);
extern void func_0c02a0c4(struct Obj_19cc70 *, int, int);
extern Handler_19cc70 table_0c2588f4[];
extern struct Rec_19cc70 table_0c25887c[];
extern struct Dat_19cc70 dat_0c2d9260;
extern Handler2_19cc70 table_0c258904[];

void func_0c19cc9e(struct Obj_19cc70 *a);
void func_0c19cda2(struct Obj_19cc70 *a);

struct Obj_19cc70 *func_0c19cc70(struct Obj_19cc70 *p, unsigned char b)
{
    struct Obj_19cc70 *q;

    if ((q = func_0c0374da(0, 3, 0)) != 0) {
        q->p16 = func_0c19cc9e;
        q->p24 = p;
        q->b32 = b;
    }
    return q;
}

void func_0c19cc9e(struct Obj_19cc70 *a)
{
    table_0c2588f4[a->b4](a);
}

void func_0c19ccb0(struct Obj_19cc70 *a)
{
    struct Rec_19cc70 *r;
    struct Obj_19cc70 *p;

    p = a->p24;
    a->b4 = a->b4 + 1;
    a->w38 = 0x1004;
    a->sdc = p->sdc;
    a->sdc.b12c = 1;
    a->b2 = p->b2;
    a->b1 = p->b1;
    a->v80.x = p->v80.x;
    a->v80.y = p->v80.y;
    a->b1a3 = p->b1a3;
    a->b1a4 = p->b1a4;
    a->b48 = p->b48;
    a->v80 = p->v80;
    a->b36 = p->b36;
    a->sdc.b12c = 0;
    a->sdc.w130 ^= 1;
    r = &table_0c25887c[a->b32];
    a->b36 = r->b0;
    a->s28 = r->s8;
    a->s30 = r->s10;
    if (a->sdc.w130 == 0)
        a->f52 = dat_0c2d9260.f8c + 53.3333321f;
    else
        a->f52 = dat_0c2d9260.f88 + -53.3333321f;
    a->f56 = p->f41c;
    a->f92 = r->f4;
    if (a->sdc.w130 != 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 23, 20);
    func_0c19cda2(a);
}

void func_0c19cda2(struct Obj_19cc70 *a)
{
    table_0c258904[a->b5](a, a->p24);
}
