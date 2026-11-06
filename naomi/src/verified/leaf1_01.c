/* Pool-free leaves, one section each. Struct members are named by byte offset. */
#include "objects.h"
struct Obj_0c02f194 { int a; int b; float f8; float f12; float f16; float f20; float f24; float f28; float f32; float f36; float f40; };
struct Obj_0c0c7ff2 { unsigned char pad[24]; unsigned char b24; };
struct Obj_0c1dcb08 { unsigned char pad0[6]; unsigned char b6; unsigned char b7; unsigned char pad1[20]; short s28; unsigned char pad2[116 - 30]; float f116; };

#pragma section n02f194
void func_0c02f194(struct Obj_0c02f194 *p)
{
    p->f20 = p->f24 = p->f8 / (float)p->b;
}

#pragma section n02f1c0
void func_0c02f1c0(struct Obj_0c02f194 *p)
{
    p->f36 = p->f40 = p->f16 / (float)p->b;
}

#pragma section n0c7ff2
void func_0c0c7ff2(struct Actor *p, struct Obj_0c0c7ff2 *q)
{
    if (--p->s28 == 0) {
        q->b24 = q->b24 + 1;
        p->s28 = 10;
    }
    p->f52 += p->f92;
    p->f92 += p->f104;
}

#pragma section n180e1a
void func_0c180e1a(struct Actor *p)
{
    p->b4 = p->b4 + 1;
    p->b5 = 1;
    p->b6 = 0;
}

#pragma section n19ab88
int func_0c19ab88(struct Actor *p, float lim)
{
    float y = p->f56;
    float vy = p->f96;
    int n = 0;
    do {
        y += vy;
        vy += p->f108;
        n++;
    } while (vy > 0.0f || y > lim);
    return n;
}

#pragma section n1b0848
int func_0c1b0848(struct Actor *a, struct Actor *b)
{
    unsigned char r = 0;
    if (a->f52 - b->f52 < 0.0f)
        r = 1;
    return r;
}

#pragma section n1dcb08
int func_0c1dcb08(struct Obj_0c1dcb08 *p)
{
    if ((p->s28)-- == 0) {
        if (++p->b7 > 5)
            return 1;
        p->f116 = 1.0f;
        p->b6 = 1;
        p->s28 = 0;
    }
    return 0;
}
