#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1385f8(struct Actor *, int);
extern void (*table_0c24075c[])(struct Actor *);
void func_0c06989c(struct Actor *a) { table_0c24075c[a->b7](a); }
void func_0c0698ae(struct Actor *a) {
  func_0c02a026(a);
  if (!a->b141) {
    a->b7++;
    a->b1f9 = 2;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = 12.85714245f;
    a->f108 = 0.0f;
  }
}
void func_0c0698e8(struct Actor *a) {
  int *p;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
  if (a->b141) {
    a->b7++;
    a->b141 = 0;
    p = &a->i72;
    *p = (unsigned short)(*p + 0x8000);
    a->f56 += 291.42856f;
  }
}
void func_0c069946(struct Actor *a) {
  int *p;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
  if (a->f41c + 1225.7142334f > a->f56)
    return;
  {
    a->b7++;
    p = &a->i72;
    *p = (unsigned short)(*p + 0x8000);
    a->f56 = a->f41c + 1032.8571f;
    func_0c1385f8(a, 5);
    func_0c02a0c4(a, 19, 5);
  }
}
void func_0c0699be(struct Actor *a) { func_0c02a026(a); }
void func_0c0699c4(struct Actor *a) { func_0c02a026(a); }
void func_0c0699ca(struct Actor *a) {
  a->b12c = 0;
  func_0c02a026(a);
}
void func_0c0699d6(struct Actor *a) {
  a->b12c = 0;
  func_0c02a026(a);
}
