#include "objects.h"
extern int func_0c04e78e(struct Actor *, int),
    func_0c04e788(struct Actor *, int);
extern void func_0c04e6b2(struct Actor *, void *, int),
    func_0c0453c4(struct Actor *, int);
int func_0c04f8b0(struct Actor *a, void *p) {
  int mode;
  if (!func_0c04e78e(a, 0))
    return 0;
  func_0c04e6b2(a, p, 0);
  mode = a->b1d0;
  if (mode != 6 && mode != 5) {
    a->f56 = a->f41c;
    a->b446 = 1;
  }
  return 1;
}
int func_0c04f906(struct Actor *a, void *p) {
  int mode;
  if (!func_0c04e78e(a, 0))
    return 0;
  func_0c04e6b2(a, p, 0);
  mode = a->b1d0;
  if (mode != 0 && mode != 7) {
    a->f56 = a->f41c;
    a->b446 = 0;
  }
  return 1;
}
int func_0c04f95a(struct Actor *a, void *p) {
  unsigned short mask;
  if (func_0c04e788(a, 0)) {
    func_0c04e6b2(a, p, 0);
    func_0c04e6b2(a, p, 1);
    switch (a->parameter4b4.integer) {
    case 0:
      mask = 0x2800;
      break;
    case 255U:
      mask = 0x2000;
      break;
    case 1:
      mask = 0x2400;
      break;
    }
    a->b1d3 = a->parameter4b4.integer;
    a->w34a = mask;
    func_0c0453c4(a, 2);
    a->w34a = 0;
    if (mask & 0xc00)
      mask ^= a->b1d2 * 0xc00;
    a->w4dc = mask;
  }
  return 0;
}
int func_0c04fa0a(struct Actor *a, void *p) {
  unsigned short mask;
  if (func_0c04e788(a, 5)) {
    func_0c04e6b2(a, p, 0);
    func_0c04e6b2(a, p, 1);
    switch (a->parameter4b4.integer) {
    case 0:
      mask = 0x2800;
      break;
    case 255U:
      mask = 0x2000;
      break;
    case 1:
      mask = 0x2400;
      break;
    }
    a->b1d3 = a->parameter4b4.integer;
    a->w34a = mask;
    func_0c0453c4(a, 13);
    a->w34a = 0;
    if (mask & 0xc00)
      mask ^= a->b1d2 * 0xc00;
    a->w4dc = mask;
  }
  return 0;
}
