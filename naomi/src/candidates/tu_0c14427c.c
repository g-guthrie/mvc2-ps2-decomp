/* Candidate (1461/1472): func_0c1442d0 schedules the q+32 address before the 0xcc literal and copies the
 * wcc short through r2 instead of r3; func_0c1447f0 final f52+=f92 uses fr1/fr2 instead of fr2/fr3.
 * All other functions and pools match. 0c144424 and 0c144688 are fall-through tail functions. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f9f4[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24fa00[])(struct LinkedActor *);
extern void (*table_0c24fa10[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24fa1c[])(struct LinkedActor *);
extern void (*table_0c24fa2c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c14432a(struct LinkedActor *);
void func_0c144424(struct LinkedActor *,struct LinkedActor *);
void func_0c144688(struct LinkedActor *,struct LinkedActor *);
void func_0c14476c(struct LinkedActor *,struct LinkedActor *);
void func_0c14477a(struct LinkedActor *,struct LinkedActor *);
void func_0c1447b8(struct LinkedActor *,struct LinkedActor *);
void func_0c1447f0(struct LinkedActor *,struct LinkedActor *);

struct LinkedActor *func_0c14427c(struct Actor *p,unsigned char x,unsigned char y)
{
 struct LinkedActor *q;short *slot;
 if((q=func_0c0374da(0,1,0))!=0){q->p16=func_0c14432a;q->w38=0xf04;q->p24=(struct LinkedActor *)p;q->b1=p->b1;q->b32=x;q->b33=y;slot=&q->wcc.short_value;*slot=*(short *)&p->b158;}return q;
}

struct LinkedActor *func_0c1442d0(struct LinkedActor *p,unsigned char x,unsigned char y)
{
 struct LinkedActor *q;short *src,*dst;
 if((q=func_0c0374da(0,1,1))!=0){q->p16=func_0c14432a;q->w38=0xf04;src=&p->wcc.short_value;q->p24=p->p24;dst=&q->wcc.short_value;q->p20=p;q->b1=p->b1;q->b32=x;q->b33=y;*dst=*src;}return q;
}

void func_0c14432a(struct LinkedActor *a){table_0c24f9f4[a->b32](a,a->p24);}

void func_0c144340(struct LinkedActor *a){table_0c24fa00[a->b4](a);}

void func_0c144368(struct LinkedActor *a,struct LinkedActor *p)
{
 a->b4++;
 a->sdc=p->sdc;a->sdc.b12c=1;a->b2=p->b2;a->b1=p->b1;a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;
 a->b36=p->b36;a->sdc.b12c=1;a->b49=-1;a->f60=p->f60;
 A(a)->b1a1=14;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,20);
 a->s28=1;
 func_0c144424(a,p);
}

void func_0c144424(struct LinkedActor *a,struct LinkedActor *p){a->b36=p->b36;table_0c24fa10[(unsigned char)a->b5](a,p);}

void func_0c14443e(struct LinkedActor *a,struct LinkedActor *p)
{
 func_0c1447b8(a,p);func_0c1442d0(a,2,0);a->b5++;
}

void func_0c14445a(struct LinkedActor *a,struct LinkedActor *p)
{
 struct ActorSub2a4 *sub=&A(p)->sub2a4;short *slot=&a->wcc.short_value;
 func_0c1447b8(a,p);
 func_0c02a026(a);
 a->s28++;
 func_0c1442d0(a,1,a->s28&3);
 if(((char *)sub)[8]||*(short *)&A(p)->b158!=*slot){a->b5++;func_0c02a0c4(a,23,21);}
}

void func_0c1444f0(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c14476c(a,owner);}
}

void func_0c144520(struct LinkedActor *a){table_0c24fa1c[a->b4](a);}

void func_0c144532(struct LinkedActor *a,struct LinkedActor *b)
{
 struct LinkedActor *p;
 p=a->p20;
 a->b4++;
 a->sdc=p->sdc;a->sdc.b12c=1;a->b2=p->b2;a->b1=p->b1;a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;
 a->b36=p->b36;a->sdc.b12c=1;a->b49=-1;
 A(a)->b1a1=14;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 if(!a->b33)a->pad11[0]=66;else a->pad11[0]=96;
 a->pad11[1]=66;
 ((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=13;
 a->f52=p->f52;a->f56=p->f56;a->f60=p->f60;
 if(!a->sdc.w130)a->f52+=-53.3333321f;else a->f52+=53.3333321f;
 if(!a->sdc.w130)a->f104=-25.0f;else a->f104=25.0f;
 a->f92=0.0f;
 func_0c02a0c4(a,23,a->b32==2?18:20);
 func_0c144688(a,b);
}

void func_0c144688(struct LinkedActor *a,struct LinkedActor *p){a->b36=p->b36;table_0c24fa2c[(unsigned char)a->b5](a,p);}

void func_0c1446a2(struct LinkedActor *a,struct LinkedActor *p)
{
 struct ActorSub2a4 *sub=&A(p)->sub2a4;struct LinkedActor *q=a->p20;short *slot=&a->wcc.short_value;
 a->f92+=a->f104;
 func_0c1447f0(a,q);
 func_0c02a026(a);
 func_0c037d0c(a);
 if(((char *)sub)[8]||*(short *)&A(p)->b158!=*slot){a->b5++;func_0c02a0c4(a,23,a->b32==2?19:21);return;}
 if(func_0c028642(a))return;
 a->b4++;func_0c14477a(a,p);
}

void func_0c14473c(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c14477a(a,owner);}
}

void func_0c14476c(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}

void func_0c14477a(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}

void func_0c144788(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}

void func_0c1447b8(struct LinkedActor *a,struct LinkedActor *p)
{
 a->f52=p->f52;a->f56=p->f56;
 if(!a->sdc.w130)a->f52+=-211.66666f;else a->f52-=-211.66666f;
 a->f56+=205.71428f;
}

void func_0c1447f0(struct LinkedActor *a,struct LinkedActor *p)
{
 a->f52=p->f52;a->f56=p->f56;a->f60=p->f60;
 if(a->b32==2){if(a->sdc.w130);}else{if(a->sdc.w130);}a->f52+=0.0f;
 a->f52+=a->f92;
}
