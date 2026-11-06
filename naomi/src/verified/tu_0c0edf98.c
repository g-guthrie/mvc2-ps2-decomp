/* Exact 0x0c0edf98..0x0c0ee064: consume the animation flag and apply mirrored motion tables. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern struct ActorMotionFloatTable2 dat_0c249ea4[],dat_0c249ea8[];
void func_0c0edf98(struct Actor *a)
{
 func_0c02a026(a);
 if(((char *)&a->w150)[1]){
 a->b7++;func_0c0451f2(a);((char *)&a->w150)[1]=0;
 a->f92=a->b1d2?dat_0c249ea4[(unsigned char)a->b1a3].pair[0].x:-dat_0c249ea4[(unsigned char)a->b1a3].pair[0].x;
 a->f104=a->b1d2?dat_0c249ea8[(unsigned char)a->b1a3].pair[0].x:-dat_0c249ea8[(unsigned char)a->b1a3].pair[0].x;
 a->f96=dat_0c249ea4[(unsigned char)a->b1a3].pair[1].x;
 a->f108=dat_0c249ea4[(unsigned char)a->b1a3].pair[1].y;
 }
}
