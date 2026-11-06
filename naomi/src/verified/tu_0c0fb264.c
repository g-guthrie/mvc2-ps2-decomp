#include "objects.h"
extern unsigned char dat_0c2f8338;
struct MotionPair4 { short x,y; };
extern struct MotionPair4 dat_0c24aa88[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *);
void func_0c0fb264(struct Actor *a)
{
 float offset;
 if(dat_0c2f8338>=2){
  a->b6++;a->b12c=1;a->f100=a->f52;a->f56=a->f41c+-21.42857f;
  offset=106.666664124f;if(a->b2)offset=-106.666664124f;
  a->f52-=offset;func_0c02a0c4(a,18,0);
 }
}
void func_0c0fb2b4(struct Actor *a)
{
 int x,y;struct MotionPair4 *entry;
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,0,0);return;}
 entry=dat_0c24aa88+a->b141;x=entry->x*256;y=entry->y*256;
 if(!a->w130)x=-x;
 a->f92=(float)x*1.66666663f/65536.0f;a->f96=(float)y*2.1428571f/65536.0f;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
}
void func_0c0fb358(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->b5++;a->f52=a->f100;a->f56=a->f41c;func_0c043324(a);}
}
