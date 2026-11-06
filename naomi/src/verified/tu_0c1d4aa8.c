/* Paired fade/stretch updates for the first fifteen animation frames. */
#include "objects.h"
extern float dat_0c2614e0[];
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1d4aa8(struct Obj_tu5_03 *a)
{
 if(a->w28>14) {func_0c037688(a);return;}
 {
  a->f116=dat_0c2614e0[a->w28];
  {float minimum=0.100000002f;
  if(a->w28<9) {a->f80-=minimum;a->f84+=0.25f;}
  if(a->f80<minimum)a->f80=minimum;
  a->w28++;
  }
 }
}
void func_0c1d4af6(struct Obj_tu5_03 *a)
{
 if(a->w28>14) {func_0c037688(a);return;}
 {
  a->f116=dat_0c2614e0[a->w28];
  {float minimum=0.100000002f;
  if(a->w28<9) {a->f80+=0.25f;a->f84-=minimum;}
  if(a->f84<minimum)a->f84=minimum;
  a->w28++;
  }
 }
}
