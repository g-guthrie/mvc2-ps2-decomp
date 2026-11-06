/* Candidate: func_0c162fb0 differs by eight register-assignment bytes
 * at 0c163064-0c163086. The other four functions and both pools are exact. */
#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
#define PARENT_SLOT(p) (*(int *)&(p)->pad10c[0x2c])
extern float dat_0c22f728[],dat_0c22f740[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c028642(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c1af566(struct Actor *,int,int),func_0c037d0c(struct Actor *),func_0c037688(struct LinkedActor *);
void func_0c162fb0(struct Actor *),func_0c162f72(struct LinkedActor *);
void func_0c162e0c(struct LinkedActor *a)
{
 float *positions,*velocities;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b49=-8;a->s28=96;a->pad11[0]=66;a->pad11[1]=66;
 positions=dat_0c22f728;a->f52=positions[a->b32&6];positions+=a->b32&6;a->f56=positions[1];((struct Actor *)a)->f104=0.0f;((struct Actor *)a)->f108=0.0f;
 velocities=dat_0c22f740;((struct Actor *)a)->f92=velocities[a->b32*2];velocities+=a->b32*2;a->f96=velocities[1];
 if(((struct Actor *)a)->w130){a->f52=-a->f52;((struct Actor *)a)->f92=-((struct Actor *)a)->f92;((struct Actor *)a)->f104=-((struct Actor *)a)->f104;}
 a->f52+=a->p24->f52;a->f56+=a->p24->f56;
 ((struct Actor *)a)->b1a1=a->b1a3+48;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,a->b32+4);func_0c1af566((struct Actor *)a,2,0);func_0c162fb0((struct Actor *)a);
}
void func_0c162f72(struct LinkedActor *a){struct Actor *owner=OWNER(a);unsigned char zero=0;PARENT_SLOT(owner)=zero;a->b5++;func_0c02a0c4(a,23,10);}
void func_0c162fb0(struct Actor *a)
{
 struct Actor *owner=OWNER(a);a->b36=owner->b36;
 if(!a->b5){
 if(!func_0c028642(a)){a->b4=2;PARENT_SLOT(owner)=0;return;}
 if(a->b19e || !--a->s28 || a->b19f || ((unsigned char *)owner)[0x159]==22)goto transition;
 if(a->f56<OWNER(a)->f41c){a->f56=OWNER(a)->f41c;transition:func_0c162f72((struct LinkedActor *)a);return;}
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b141){goto feedback;feedback:a->b141=0;func_0c1af566(a,3,a->b32>>1);}
 func_0c02a026(a);func_0c037d0c(a);return;
 }
 if(func_0c02a026(a)<0)a->b4++;
 return;
}
void func_0c1630a4(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1630b2(struct LinkedActor *a){func_0c037688(a);}
