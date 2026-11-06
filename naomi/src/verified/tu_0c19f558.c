/* Exact 0x0c19f558..0x0c19fadc: linked effect actor setup and state callbacks. */
#include "objects.h"
typedef void (*handler_la)(struct LinkedActor *);
extern void func_0c02a684(struct LinkedActor *, int, int, int);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern void func_0c1d53e4(struct LinkedActor *);
extern void func_0c029fc4(struct LinkedActor *);
extern void func_0c02a39a(struct LinkedActor *, int);
extern void func_0c037688(struct LinkedActor *);
extern struct ActorFlags *dat_0c2d6f84;
extern handler_la table_0c258cbc[];
extern handler_la table_0c258ce4[];
extern handler_la table_0c258ce8[];
extern handler_la table_0c258cec[];
extern handler_la table_0c258cf0[];
extern handler_la table_0c258cf4[];
extern handler_la table_0c258cf8[];
extern handler_la table_0c258cfc[];
extern handler_la table_0c258d00[];
void func_0c19fad0(struct LinkedActor *a);

void func_0c19f558(struct LinkedActor *a)
{
 struct LinkedActor *owner;int one;float unity;
 a->b4++;owner=a->p24;a->sdc=owner->sdc;
 one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;
 unity=1.0f;a->b36=owner->b36;a->sdc.b12c=one;a->b36=7;
 ((struct Actor *)a)->f264=unity;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->f52+=a->p24->sdc.w130?160.0f:-160.0f;
 a->v80.y=unity;
 func_0c02a684(owner,6,6,1);func_0c029e70(a,27,13);func_0c1d53e4(a);
 ((struct Actor *)a)->b0=one;
}

void func_0c19f62c(struct LinkedActor *a)
{
 struct LinkedActor *owner;int one;float k;
 a->b4++;owner=a->p24;a->sdc=owner->sdc;
 one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=one;a->b36=0;
 ((struct Actor *)a)->f264=1.0f;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 a->f52+=a->p24->sdc.w130?160.0f:-160.0f;
 k=0.800000012f;
 a->v80.x=k;a->v80.y=k;
 func_0c029e70(a,27,14);
}

void func_0c19f710(struct LinkedActor *a)
{
 if (a->b1 != a->p24->b1) {
  func_0c19fad0(a);
  return;
 }
 table_0c258cbc[a->b32](a);
}

void func_0c19f738(struct LinkedActor *a)
{
 struct LinkedActor *owner = a->p24;
 table_0c258ce4[(unsigned char)a->b5](a);
 if (owner->b1d0 != 30) {
  a->b4++;
  a->sdc.b12c = 0;
 }
}

void func_0c19f772(struct LinkedActor *a)
{
 if (a->p24->sdc.b141 == 2) func_0c029e70(a, 27, 17);
 if (a->p24->sdc.b141 == 3) func_0c029e70(a, 27, 18);
 if (a->p24->sdc.b141 == 4) func_0c029e70(a, 27, 19);
 if (a->p24->sdc.b141 == 5) func_0c029e70(a, 27, 20);
 if (a->p24->sdc.b141 == 6) func_0c029e70(a, 27, 21);
 if (a->p24->sdc.b141 == 7) func_0c029e70(a, 27, 21);
 if (a->p24->sdc.b141 == 8) func_0c029e70(a, 27, 22);
 if (a->p24->sdc.b141 == 9) a->b4++;
}

void func_0c19f82c(struct LinkedActor *a)
{
 table_0c258ce8[(unsigned char)a->b5](a);
}

void func_0c19f83e(struct LinkedActor *a)
{
 func_0c029fc4(a);
 if (a->sdc.b143 < 0)
  a->b4++;
}

void func_0c19f85c(struct LinkedActor *a)
{
 table_0c258cec[(unsigned char)a->b5](a);
}

void func_0c19f86e(struct LinkedActor *a)
{
 func_0c029fc4(a);
 a->f52 += (float)(a->p24->sdc.w130 ? 18 : -18);
 a->f56 = a->f96;
 if (!(dat_0c2d6f84->flags & 1))
  a->f56 += 3.0f;
 if (a->s28-- == 0) {
  a->b4++;
  a->sdc.b12c = 0;
 }
}

void func_0c19f8d6(struct LinkedActor *a)
{
 table_0c258cf0[(unsigned char)a->b5](a);
}

void func_0c19f8e8(struct LinkedActor *a)
{
 func_0c029fc4(a);
 a->f52 += (float)(a->p24->sdc.w130 ? 18 : -18);
 a->l72 += 0x2000;
 if (a->s28-- == 0) {
  a->b4++;
  a->sdc.b12c = 0;
 }
}

void func_0c19f93a(struct LinkedActor *a)
{
 table_0c258cf4[(unsigned char)a->b5](a);
}

void func_0c19f970(struct LinkedActor *a)
{
 func_0c029fc4(a);
 ((struct Actor *)a)->f264 -= 0.02f;
 if (((struct Actor *)a)->f264 < 0.0f)
  ((struct Actor *)a)->f264 = 0.0f;
 if (a->sdc.b143 < 0) {
  a->b4++;
  a->sdc.b12c = 0;
 }
}

void func_0c19f9ac(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 table_0c258cf8[(unsigned char)a->b5]((owner = a->p24, a));
 if (owner->b1d0 != 22) {
  a->b4++;
  a->sdc.b12c = 0;
  func_0c02a39a(owner, 0);
 }
}

void func_0c19f9ee(struct LinkedActor *a)
{
 func_0c029fc4(a);
}

void func_0c19f9f4(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 table_0c258cfc[(unsigned char)a->b5]((owner = a->p24, a));
 if (owner->b1d0 != 22) {
  a->b4++;
  a->sdc.b12c = 0;
  func_0c02a39a(owner, 0);
 }
}

void func_0c19fa36(struct LinkedActor *a)
{
 func_0c029fc4(a);
}

void func_0c19fa3c(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 table_0c258d00[(unsigned char)a->b5]((owner = a->p24, a));
 if (owner->b1d0 != 22) {
  a->b4++;
  a->sdc.b12c = 0;
  func_0c02a39a(owner, 0);
 }
}

void func_0c19fa7e(struct LinkedActor *a)
{
 if (a->sdc.b141 == 1) {
  a->b5++;
  a->sdc.b141 = 0;
 }
 func_0c029fc4(a);
}

void func_0c19fa98(struct LinkedActor *a)
{
 func_0c029fc4(a);
}

void func_0c19fa9e(struct LinkedActor *a)
{
 a->b4++;
 a->sdc.b12c = 0;
}

void func_0c19fad0(struct LinkedActor *a)
{
 func_0c037688(a);
}
