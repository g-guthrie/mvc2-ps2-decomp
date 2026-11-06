#include "objects.h"

struct S_0c02f1d6 { int a; int b; float f8; unsigned char pad[8]; float f20; float f24; };
#pragma section n00e1d6
void func_0c02f1d6(struct S_0c02f1d6 *p) { p->f24 = p->f8 / (float)p->b; p->f20 = p->f24 * (float)p->a; p->f24 = -p->f24; }

#pragma section n00e1fc
void func_0c02f1fc(unsigned char *p) { *(float*)(p+32) = *(float*)(p+12) / (float)*(int*)(p+4); *(float*)(p+28) = *(float*)(p+32) * (float)*(int*)(p+0); *(float*)(p+32) = -*(float*)(p+32); }

#pragma section n00e222
void func_0c02f222(unsigned char *p) { *(float*)(p+40) = *(float*)(p+16) / (float)*(int*)(p+4); *(float*)(p+36) = *(float*)(p+40) * (float)*(int*)(p+0); *(float*)(p+40) = -*(float*)(p+40); }

#pragma section n0b3152
void func_0c0d4152(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }

#pragma section n12f14e
void func_0c15014e(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }

struct RS_0c1675a0 { unsigned char pad[8]; float f8; float f12; };
#pragma section n15d204
void func_0c17e204(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }

#pragma section n17fdf8
void func_0c1a0df8(struct Actor *p) { p->f52 += p->f92; if ((p->s28)-- <= 0) p->b5++; }

#pragma section n19a7c2
void func_0c1bb7c2(struct Actor *p) { p->f52 += p->f92; p->f92 += p->f104; p->f56 += p->f96; p->f96 += p->f108; }

#pragma section n1af684
void func_0c1d0684(struct Actor *p) { p->f52 += p->f92; p->f56 += p->f96; p->f60 += p->f100; }

#pragma section n1b8706
void func_0c1d9706(struct Actor *p) { p->f92 += p->f104; p->f96 += p->f108; p->f100 += p->f112; }

#pragma section n1b8732
void func_0c1d9732(struct Actor *p) { p->f52 += p->f92; p->f56 += p->f96; p->f60 += p->f100; }
