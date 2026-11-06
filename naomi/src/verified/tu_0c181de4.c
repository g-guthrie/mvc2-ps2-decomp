/* Exact 0x0c181de4..0x0c181eac: integrate motion, update the effect timer, and snap to the cached position. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *,int),func_0c037d0c(struct Actor *);
void func_0c181de4(struct Actor *a)
{
 float distance,offset;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if((a->s30+=0x2000)==0)a->b19e=0;
 distance=a->f52-(float)a->i204;
 if(distance<0.0f)distance=-distance;
 offset=13.33333302f;
 if(distance<offset){
 a->b5++;a->s28=30;
 if(a->w130)offset=-13.33333302f;
 a->f52=(float)a->i204+offset;func_0c0346da(a,49);
 }
 func_0c037d0c(a);
}
