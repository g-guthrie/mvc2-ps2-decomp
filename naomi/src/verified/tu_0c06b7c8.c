#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c06c9ba(struct Actor *),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c240908[])(struct Actor *);
void func_0c06b9be(struct Actor *,struct ActorSubCommandPrefix *);
void func_0c06b7c8(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);func_0c06c9ba(a);
 if(a->b141){a->b141=0;func_0c06b9be(a,(struct ActorSubCommandPrefix *)sub);}
 {char flags=a->b19e;if(flags){if((flags&17)||a->p1b0->b202)goto stop;}}
 {int flags=*(char *)&a->b1fd;if(flags&3){if(!(((unsigned char)a->b1d2+1)&flags&3))goto stop;}}
 if(!(a->f56>a->f41c)){
 a->b6=4;a->f56=a->f41c;a->b1f9=0;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,27);return;
 }
 if(--a->s28)return;
 stop:a->b6++;a->f92/=8.0f;a->f96=0;a->f108=-0.80357140303f;func_0c02a0c4(a,21,53);
}
void func_0c06b90c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){
 a->b6++;a->f56=a->f41c;a->b1f9=0;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,27);
 }
}
void func_0c06b99c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c06b9be(struct Actor *a,struct ActorSubCommandPrefix *sub)
{
 if(sub->command){
 sub->command--;a->b1f5=16;
 {int command=a->b1fe?79:76;
 command+=(unsigned char)a->b1a3*2;
 a->b1a1=command;}
 a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 }
}
void func_0c06ba10(struct Actor *a){table_0c240908[a->b6](a);}
