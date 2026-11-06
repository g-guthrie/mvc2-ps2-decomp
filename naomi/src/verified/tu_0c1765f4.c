/* Spawned hit effect: place from owner offset and pick an eight-way frame from the direction. */
#include "objects.h"
struct Spawn_0c1765f4 { char b0, b1, b2, b3; short s4, s6; };
struct Box_0c1765f4 { short s0, s2, s4, s6; float f8, f12, f16, f20, f24, f28; unsigned char pad[44 - 32]; float f44; };
extern struct AnimationFrame20 table_0c252e10[];
extern short table_0c252d0e[];
extern void func_0c029f0e(struct Actor *, int, int, unsigned int);
void func_0c1765f4(struct Actor *a, struct Box_0c1765f4 *b, struct Spawn_0c1765f4 *c)
{
 struct Actor *p = a->p20;
 float v[2];
 int dir = c->b1;
 int q;
 short *t;
 v[0] = c->s4 * 1.66666663f;
 if (p->w130) { dir = -dir; v[0] = -v[0]; }
 a->b34 = dir;
 b->f24 = v[0];
 b->f28 = c->s6 * 2.1428571f;
 v[0] = b->f16 = p->f52 + b->f24;
 v[1] = b->f20 = p->f56 + b->f28;
 q = (((unsigned char)dir + 4) & 0xf8) / 8;
 func_0c029f0e(a, 27, 1, (unsigned char)q);
 a->p154 = table_0c252e10;
 a->p1c0 = (struct HitboxSelection_15dc08 *)(a->p16c + a->p154->index * 16);
 t = &table_0c252d0e[(unsigned char)q * 4];
 b->s0 = t[0] * 1.66666663f;
 b->s2 = t[1] * 2.1428571f;
 b->s4 = t[2] * 1.66666663f;
 b->s6 = t[3] * 2.1428571f;
 if (c->b3) { v[0] -= b->s4; v[1] += b->s6; }
 a->f52 = b->f44 = v[0];
 a->f56 = v[1];
 a->b36 = p->b36;
}
