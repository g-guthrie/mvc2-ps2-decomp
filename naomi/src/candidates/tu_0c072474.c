#include "objects.h"
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c191980(struct Actor *, int);
extern void func_0c0438de(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0443ce(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void (*table_0c2410f0[])(struct Actor *);
void func_0c07248a(struct Actor *);
void func_0c0724b2(struct Actor *);
void func_0c0725b0(struct Actor *);
void func_0c072474(struct Actor *a) {
  func_0c0421f4(a);
  func_0c0420f8(a);
  func_0c07248a(a);
}
void func_0c07248a(struct Actor *a) {
  func_0c042018(a);
  func_0c0421b8(a);
  if (!a->b1fe)
    func_0c0724b2(a);
  else
    func_0c0725b0(a);
}
void func_0c0724b2(struct Actor *a) {
  int zero = 0;
  switch (a->b1e8) {
  case 0:
  case 2:
    if (func_0c02a026(a) < 0)
      goto finished;
    if (a->b141) {
      a->b141 = zero;
      func_0c191980(a, 4);
    }
    break;
  case 1:
    if (func_0c02a026(a) < 0) {
    finished:
      func_0c0438de(a);
      break;
    }
    if (a->b141 && ((a->w34e | a->w352) & 0x200) && a->b1fc) {
      a->w352 = zero;
      a->b1a1 = 29;
      a->w1ac = zero;
      a->b19e = zero;
      *(unsigned int *)&a->p1c4 = zero;
      dat_0c2f83f8->arr[a->b2]++;
      func_0c0443ce(a);
      func_0c0344a0(a, 31);
      func_0c02a0c4(a, 11, 4);
    }
    break;
  }
  if (func_0c044e52(a))
    func_0c044f1c(a);
}
void func_0c0725b0(struct Actor *a) {
  switch (a->b1e8) {
  case 0:
  case 1:
    if (func_0c02a026(a) < 0) {
      func_0c0438de(a);
    } else if (func_0c044e52(a))
      func_0c044f1c(a);
    break;
  case 2:
    table_0c2410f0[a->b6](a);
    break;
  }
}
