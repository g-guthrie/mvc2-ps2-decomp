/* Linked actor launch handlers sharing the literal pools at 0x0c18cdec and
 * 0x0c18cf4c. func_0c18cdca continues at 0x0c18ce24 after the first pool. */
#include "objects.h"
#define LA struct LinkedActor

/* Motion block at linked actor offset 0x88 (inside pad9b). */
struct Motion88 {
    unsigned char pad0[16];
    short s16;
    unsigned char pad1[2];
    int i20;
    int i24;
    char b28;
};
#define M88(a) ((struct Motion88 *)(a)->pad9b)
/* Owner block at offset 0x2a4, past the LinkedActor layout. */
struct Owner2a4 {
    unsigned char pad0[19];
    char b19;
};
#define O2A4(b) ((struct Owner2a4 *)((char *)(b) + 0x2a4))

extern struct Glob_0c2f8338_tu1_01 {
    unsigned char pad0[6];
    char b6;
    unsigned char pad1[59 - 7];
    unsigned char b59;
    unsigned short w60;
} dat_0c2f8338;

extern void func_0c029e70(LA *, int, char);
extern void func_0c029fc4(LA *a);
extern void func_0c133c06(LA *a);
extern float func_0c1ebd40(int x);
extern float func_0c1ec2c0(int x);
extern float func_0c1ec0e0(float x, float y);

void func_0c18cca4(LA *a, LA *b)
{
    struct Motion88 *s = M88(a);
    unsigned char one;

    a->b4 = a->b4 + 1;
    a->sdc = b->sdc;
    one = 1;
    a->sdc.b12c = (char)one;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->v80.x = b->v80.x;
    a->v80.y = b->v80.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->v80 = b->v80;
    a->b36 = b->b36;
    s->s16 = b->sdc.w158.short_value;
    s->b28 = 8;
    a->s28 = 0xb4;
    a->s30 = one;
    a->b49 = -4;
    a->sdc.w158.bytes[0] = 10;
    func_0c029e70(a, 27, a->sdc.w158.bytes[0]);
    if (!a->b33)
        s->i20 = 0x4000;
    else
        s->i20 = 0xc000;
    if (a->sdc.w130)
        s->i24 = -0x400;
    else
        s->i24 = 0x400;
    a->f92 = func_0c1ebd40(s->i20) * func_0c1ec0e0(2.0f, (float)s->b28) / 2.0f;
    a->f96 = func_0c1ec2c0(s->i20) * func_0c1ec0e0(2.0f, (float)s->b28) / 2.0f;
    a->f52 = b->f52 + a->f92;
    a->f56 = b->f56 + a->f96 + 137.142853f;
}

void func_0c18cdca(LA *a, LA *b)
{
    struct Motion88 *s = M88(a);

    if (s->s16 != b->sdc.w158.short_value) {
        s->s16 = b->sdc.w158.short_value;
        a->b5 = a->b5 + 1;
        a->s28 = 1;
        return;
    }
    if (b->b6 <= 2 && a->sdc.b140 == 2)
        func_0c029fc4(a);
}

void func_0c18ce40(LA *a, LA *b)
{
    struct Motion88 *s = M88(a);
    struct Owner2a4 *t = O2A4(b);

    if (s->s16 != b->sdc.w158.short_value) {
        a->b5 = a->b5 + 1;
        a->s28 = 8;
        return;
    }
    if (a->sdc.b141) {
        a->sdc.b141 = 0;
        func_0c133c06(a);
    }
    if (dat_0c2f8338.w60 & (1 << dat_0c2f8338.b59))
        return;
    if (!dat_0c2f8338.b6) {
        func_0c029fc4(a);
        if (a->s30 != 0) {
            a->s30 = a->s30 - 1;
            return;
        }
        if (a->sdc.b140 == 0) {
            a->s30 = 1;
            s->i20 += s->i24;
            if (t->b19)
                s->i20 = s->i20 + s->i24;
        }
    }
    a->f92 = func_0c1ebd40(s->i20) * func_0c1ec0e0(2.0, (float)s->b28) / 2.0;
    a->f96 = func_0c1ec2c0(s->i20) * func_0c1ec0e0(2.0, (float)s->b28) / 2.0;
    a->f52 = b->f52 + a->f92;
    a->f56 = b->f56 + a->f96 + 137.142853f;
}
