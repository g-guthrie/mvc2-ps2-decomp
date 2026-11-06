/* Complete C translation. The setup routine differs in register allocation;
 * five other functions match independently. Whole unit remains a candidate. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25377c[])(struct LinkedActor *,struct LinkedActor *),(*table_0c253780[])(struct LinkedActor *),(*table_0c253790[])(struct LinkedActor *,struct LinkedActor *);
extern short dat_0c25375c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c02a18c(struct LinkedActor *,int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02849a(void);
void func_0c178c22(struct LinkedActor *),func_0c178dd0(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c178bd4(struct LinkedActor *owner,char mode,char value){struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c178c22;a->w38=0x3101;a->p24=owner;a->b1=owner->b1;a->b32=mode;a->b33=value;}return a;}
void func_0c178c22(struct LinkedActor *a){table_0c25377c[a->b32](a,a->p24);}
void func_0c178c38(struct LinkedActor *a){table_0c253780[a->b4](a);}
void func_0c178c4a(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero=0;char one;short *offsets;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;a->sdc.b12c=one;a->b49=-1;
 ((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=16;
 if((unsigned char)a->b33&one)A(a)->b1a1=59;else A(a)->b1a1=60;A(a)->w1ac=zero;A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->pad11[0]=68;a->pad11[1]=68;a->s28=zero;a->b34=24;
 if(owner->sdc.w130){a->b34=-a->b34+32;a->b34&=31;}
 offsets=dat_0c25375c;a->f52=owner->f52;a->f56=owner->f56+offsets[(unsigned char)a->b33*2+1]*2.1428571f;a->f60=owner->f60;A(a)->f92=offsets[(unsigned char)a->b33*2]*1.66666663f;
 if(owner->sdc.w130)A(a)->f92=-A(a)->f92;
 a->f52+=A(a)->f92;func_0c02a0c4(a,23,1);func_0c178dd0(a,owner);
}
void func_0c178dd0(struct LinkedActor *a,struct LinkedActor *owner){a->b36=owner->b36;table_0c253790[(unsigned char)a->b5](a,owner);}
void func_0c178dea(struct LinkedActor *a)
{
 int angle;
 if(func_0c02a026(a)<0){a->b5++;if(!A(a)->w130)angle=a->b34/2;else angle=-((int)a->b34/2)+16;angle&=15;func_0c02a18c(a,23,3,angle);{unsigned int timer;timer=7&func_0c02849a();timer+=4;a->s28=timer;}}
}
