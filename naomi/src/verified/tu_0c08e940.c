#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2429a8[])(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void (*table_0c2429b4[])(struct Actor *);
extern void func_0c045248(struct Actor *, int);
void func_0c08e940(struct Actor *a) {
  struct Actor *child;
  if (func_0c02a026(a) < 0) {
    a->w130 ^= 1;
    func_0c0437b8(a);
    return;
  }
  /*retain low event bit*/
  if (a->b141 &= 1) {
    a->b141 = 0;
    child = a->p1c8;
    goto L; L: child->b1f6 = 1;
    child->b1f9 = 2;
    child->b1a1 = a->b1a3 + 34;
    a->b1a1 = a->b1a3 + 34;
    child->b1d2 = a->b1d2;
    a->b1d2 ^= 1;
  }
}
void func_0c08e9b4(struct Actor *a) {
  a->b1ea = 1;
  table_0c2429a8[a->b1f7 & 63](a);
}
void func_0c08e9d2(struct Actor *a) { func_0c03edcc(a->p1c8, a); }
void func_0c08e9e0(struct Actor *a) { table_0c2429b4[a->b1f7 & 63](a); }
void func_0c08e9f8(struct Actor *a) {
  int zero = 0;
  a->b5 = zero;
  a->b7 = zero;
  a->b6 = zero;
  switch (a->b4c9) {
  case 0:
    a->b1e9 = 6;
    break;
  case 1:
    a->b1e9 = 3;
    break;
  case 2:
    a->b1e9 = 10;
    break;
  }
  func_0c045248(a, 29);
}
void func_0c08ea34(struct Actor *a) {
  int zero = 0;
  a->b5 = zero;
  a->b7 = zero;
  a->b6 = zero;
  switch (a->b4c9) {
  case 0:
    a->b1e9 = 6;
    break;
  case 1:
    a->b1e9 = 3;
    break;
  case 2:
    a->b1e9 = 10;
    break;
  }
  func_0c045248(a, 29);
}
void func_0c08ea98(struct Actor *a) {
  int zero = 0;
  char two = 2;
  a->b5 = zero;
  a->b7 = zero;
  a->b6 = zero;
  switch (a->b4c9) {
  case 0:
    a->b1e9 = two;
    break;
  case 1:
    a->b1e9 = zero;
    a->b6 = zero;
    break;
  case 2:
    a->b1e9 = zero;
    a->b32 = 1;
    a->b33 = two;
    a->b6 = 1;
    break;
  }
  a->b1a3 = zero;
  func_0c045248(a, 21);
}
void func_0c08eae6(struct Actor *a) {
  int zero = 0;
  a->b5 = zero;
  a->b7 = zero;
  a->b6 = zero;
  switch (a->b4c9) {
  case 0:
    a->b1e9 = 2;
    break;
  case 1:
    a->b1e9 = zero;
    a->b1a3 = zero;
    a->b6 = zero;
    goto ready;
  case 2:
    a->b1e9 = 5;
    break;
  default:
    goto ready;
  }
  a->b1a3 = zero;
ready:
  goto R; R: func_0c045248(a, 21);
}
