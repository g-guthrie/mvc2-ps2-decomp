#include "objects.h"

struct Obj_0c0c3050 { unsigned char pad[24]; unsigned char b24; };
#pragma section n0c3050
void func_0c0c3050(struct Actor *p, struct Obj_0c0c3050 *q) { if (--p->s28 == 0) { q->b24++; p->s28 = 24; } }

#pragma section n02f11a
struct S_0c02f11a { int a; int b; float f8; unsigned char pad[8]; float f20; float f24; };
void func_0c02f11a(struct S_0c02f11a *p) { p->f20 = p->f8 / (float)p->a; p->f24 = 0.0f; }

struct S_0c02f17c { int a; int b; unsigned char pad[8]; float f16; unsigned char pad2[16]; float f36; float f40; };
#pragma section n02f17c
void func_0c02f17c(struct S_0c02f17c *p) { p->f36 = p->f16 / (float)p->a; p->f40 = 0.0f; }

struct S_0c02f1aa { int a; int b; unsigned char pad[4]; float f12; unsigned char pad2[12]; float f28; float f32; };
#pragma section n02f1aa
void func_0c02f1aa(struct S_0c02f1aa *p) { p->f28 = p->f32 = p->f12 / (float)p->b; }

#pragma section n02f644
void func_0c02f644(struct Actor *p) { p->f60 += p->f100; p->f100 += p->f112; }

struct Obj_0c0476d4 { unsigned char b0; unsigned char pad[7]; unsigned short w8; };
struct Out_0c0476d4 { unsigned char b0, b1; };
struct Obj_0c15dbdc { unsigned char pad[20]; struct Actor *p20; };
#pragma section n15dbdc
void func_0c15dbdc(struct Actor *p) { struct Actor *q = ((struct Obj_0c15dbdc *)p)->p20; p->f52 = q->f52; p->f56 = q->f56; }

struct Obj_0c180f3e { unsigned char pad0[4]; unsigned char b4, b5; unsigned char pad1[18]; struct Obj_0c180f3e *p24; };
#pragma section n180f3e
int func_0c180f3e(struct Obj_0c180f3e *p) { p = p->p24; if (p->b5 == 3) return -1; return 0; }

struct Obj_0c1a2328 { unsigned char pad[32]; unsigned char b32; unsigned char pad2[3]; unsigned char b36; unsigned char pad3[12]; char b49; };
#pragma section n1a2328
void func_0c1a2328(struct Obj_0c1a2328 *a, struct Obj_0c1a2328 *b)
{
    b->b36 = a->b36;
    switch (b->b32) {
    case 13: b->b49 = -1; break;
    case 14: b->b49 = -3; break;
    case 15: b->b49 = -2; break;
    }
}

/* Loaded pointers assigned to locals (q, r) land in r5/r6, not in r1-r3. */
struct Obj_0c1b704a { unsigned char pad0[8]; struct Actor *p8; unsigned char pad1[8]; struct Actor *p20; unsigned char pad2[28]; float f52, f56; };
#pragma section n1b704a
void func_0c1b704a(struct Obj_0c1b704a *p, struct Actor *q)
{
    struct Actor *r;
    p->f52 = q->f52;
    q = p->p20;
    r = p->p8;
    p->f56 = r->f56 + q->f108;
}
