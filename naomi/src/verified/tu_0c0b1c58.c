#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern float dat_0c244b58[][4];
void func_0c0b1c58(struct Actor *a)
{
 func_0c02a026(a);
 if (!a->b141) {
  a->b7++;
  func_0c0451f2(a);
  a->f92 = a->b1d2 ? dat_0c244b58[(unsigned char)a->b1a3][0] : -dat_0c244b58[(unsigned char)a->b1a3][0];
  a->f104 = a->b1d2 ? dat_0c244b58[(unsigned char)a->b1a3][1] : -dat_0c244b58[(unsigned char)a->b1a3][1];
  a->f96 = dat_0c244b58[(unsigned char)a->b1a3][2];
  a->f108 = dat_0c244b58[(unsigned char)a->b1a3][3];
 }
}
void func_0c0b1d02(struct Actor *a)
{
 if (!a->b141) func_0c02a026(a);
 a->f52 += a->f92; a->f92 += a->f104;
 a->f56 += a->f96; a->f96 += a->f108;
 if (a->f96 < 0) a->b7++;
}
