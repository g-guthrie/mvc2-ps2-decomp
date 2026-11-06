#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c18fca4(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c06786c(struct Actor *a)
{
  if (--a->s28 == 0) {
    a->b6++;
    a->s28 = 6;
    a->f112 = -a->f100 / 8.0f;
  }
}
void func_0c067896(struct Actor *a)
{
  a->f100 += a->f112;
  if (--a->s28 == 0) {
    a->b6++;
    a->s28 = 4;
  }
}
void func_0c0678be(struct Actor *a)
{
  struct Actor *child = a->p1c8;
  char event;
  func_0c02a026(a);
  if (a->b140) {
    a->b140 = 0;
    func_0c0346da(a, 23);
  }
  if ((event = a->b141) != 0) {
    if (a->b1f9 != 2)
      child->b1a1 = 56;
    else
      child->b1a1 = 57;
    func_0c04b02a(a);
    a->b141 = 0;
    if (--a->s28 == 0) {
      a->b6++;
      func_0c18fca4(a, 4, 0);
      if (event < 0)
        a->w130 ^= 1;
      if (a->b1f9 != 2)
        a->b158 = 12;
      else
        a->b158 = 17;
      func_0c02a0c4(a, 21, a->b158);
    }
  }
}
