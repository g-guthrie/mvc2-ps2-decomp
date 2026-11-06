#include "objects.h"
struct Place6_18e0d8 { short x, y; char flip, b5; };
extern struct Place6_18e0d8 dat_0c256d84[][4];
extern char func_0c18f21e(struct Actor *);
extern void func_0c029fc4(struct Actor *);
extern void func_0c18f256(struct Actor *,struct Actor *);
extern void (*table_0c257218[])(struct Actor *);
void func_0c18e0d8(struct Actor *a,struct Actor *owner)
{
 float t,x,y;
 if(func_0c18f21e(a))return;
 if(a->b33>=4)return;
 if(owner->b141==0x80)return;
 x=owner->f52;y=owner->f56;
 t=(float)(((struct Place6_18e0d8 *)dat_0c256d84[owner->b141])[a->b33].x<<8)*1.66666663f/256.0f;
 if(!owner->w130)t=-t;
 x+=t;a->f52=x;
 a->f56=y+(float)(((struct Place6_18e0d8 *)dat_0c256d84[owner->b141])[a->b33].y<<8)*2.1428571f/256.0f;
 a->w130=((struct Place6_18e0d8 *)dat_0c256d84[owner->b141])[a->b33].flip^owner->w130;
 ((struct LinkedActor *)a)->b49=((struct Place6_18e0d8 *)dat_0c256d84[owner->b141])[a->b33].b5;
 func_0c029fc4(a);
 func_0c18f256(a,owner);
}
void func_0c18e204(struct Actor *a){table_0c257218[a->b5](a);}
