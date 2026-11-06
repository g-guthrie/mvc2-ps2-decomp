#include "objects.h"

#pragma section n05e0c8
void func_0c07f0c8(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; if (p->f92 * p->f104 > 0.0f) { p->b6++; p->f92 = 0.0f; p->f104 = 0.0f; } }

struct B125_0c125ef0 { unsigned char pad[22]; unsigned char flag; unsigned char pad2[1]; float f24; short t28; };
#pragma section n104ef0
void func_0c125ef0(struct Actor *p4, struct B125_0c125ef0 *p5) { if (!p5->flag) { if (p4->f52 > (float)p5->t28) { p4->f92 = -p5->f24; p4->f104 = -p4->f104; p5->flag = 1; } } else { if ((float)p5->t28 > p4->f52) { p4->f92 = p5->f24; p4->f104 = -p4->f104; p5->flag = 0; } } }

#pragma section n180124
void func_0c1a1124(struct Actor *p) { if ((p->s28)-- == 0) p->b4++; p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }

#pragma section n1b1b5a
void func_0c1d2b5a(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; if (--p->s28 == 0) { p->b4++; p->s28 = 2; } }
