#include "objects.h"
extern struct Actor *func_0c037d54(struct Actor *);
extern struct Actor *(*table_0c244c18[])(struct Actor *);
extern void (*table_0c244c28[])(struct Actor *);
struct Actor *func_0c0b2a24(struct Actor *a) { return table_0c244c18[(unsigned char)a->b1f9](a); }
struct Actor *func_0c0b2a3c(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=0; return result; }
 }
 return 0;
}
struct Actor *func_0c0b2a90(struct Actor *a) { return 0; }
struct Actor *func_0c0b2a94(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=1; return result; }
 }
 return 0;
}
void func_0c0b2af4(struct Actor *a) { table_0c244c28[a->b1f7 & 63](a); }
