#include "objects.h"
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern short dat_0c2f6830;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,char);
extern void func_0c02a18c(struct Actor *,int,char,char);
extern void (*table_0c24e3bc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24e414[])(struct Actor *,struct Actor *);
void func_0c133d16(struct LinkedActor *);
void func_0c134964(struct Actor *,struct Actor *);
struct LinkedActor *func_0c133c8a(struct LinkedActor *),*func_0c133cd8(struct LinkedActor *);
extern void (*table_0c24e3cc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24e3e4[])(struct LinkedActor *);
extern struct Dat_13bb5c dat_0c2f8338;
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern int func_0c028642(struct Actor *);
extern void (*table_0c24e3ec[])(struct LinkedActor *),(*table_0c24e3f4[])(struct LinkedActor *),(*table_0c24e3fc[])(struct LinkedActor *),(*table_0c24e404[])(struct LinkedActor *),(*table_0c24e40c[])(struct LinkedActor *);
extern void func_0c037688(struct Actor *);
struct LinkedActor *func_0c133b88(struct LinkedActor *owner)
{
 struct LinkedActor *a,*b;
 if(dat_0c2f6830<2)return 0;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c133d16;a->p24=owner;a->b1=owner->b1;a->b32=0;a->b33=0;a->w38=0x301;}
 if((b=func_0c0374da(a,1,2))&&a){b->p16=func_0c133d16;b->p24=owner;b->p20=a;b->b1=owner->b1;b->b32=1;b->b33=0;b->w38=0x301;a->p20=b;}
}
struct LinkedActor *func_0c133c06(struct LinkedActor *owner)
{
 struct LinkedActor *a,*b;
 if(dat_0c2f6830<2)return 0;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c133d16;a->p24=owner->p24;a->p20=owner;a->b1=owner->b1;a->b32=3;a->b33=0;a->w38=0x301;}
 if((b=func_0c0374da(a,1,2))&&a){b->p16=func_0c133d16;b->p24=owner->p24;b->p20=a;b->b1=owner->b1;b->b32=4;b->b33=0;b->w38=0x301;owner->p20=b;}
}
struct LinkedActor *func_0c133c8a(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(owner,1,2))){a->p16=func_0c133d16;a->p24=owner->p24;a->p20=owner;a->b1=owner->b1;a->b32=2;a->b33=0;a->w38=0x301;}
 return a;
}
struct LinkedActor *func_0c133cd8(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(owner,1,2))){a->p16=func_0c133d16;a->p24=owner->p24;a->p20=owner;a->b1=owner->b1;a->b32=5;a->b33=0;a->w38=0x301;}
 return a;
}
void func_0c133d16(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->b36=owner->b36;table_0c24e3bc[a->b4](a,owner);
}
void func_0c133d32(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x30305040u;a->pad178[36]=66;a->b19d=0;a->b1a1=69;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=146.66666f;a->f96=100.71428f;
 if(!a->w130)a->f92=-a->f92;
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=29;func_0c02a0c4(a,a->b159,a->b158);a->b140=0;((struct LinkedActor *)a)->b49=-4;func_0c134964(a,owner);
}
void func_0c133dfc(struct Actor *a,struct Actor *owner)
{
 struct Actor *p=a->p20;short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x20202020u;a->pad178[36]=66;a->b19d=0;a->b1a1=69;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=133.33333f;a->f104=80.0f;
 if(!a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=31;func_0c02a18c(a,a->b159,a->b158,p->b141);((struct LinkedActor *)a)->b49=-4;func_0c134964(a,owner);
}
void func_0c133ea6(struct Actor *a,struct Actor *owner)
{
 struct Actor *p=a->p20;short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x20203030u;a->pad178[36]=66;a->b19d=0;a->b1a1=p->b14b+69;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=160.0f;a->f104=105.0f;
 if(!a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=30;func_0c02a18c(a,a->b159,a->b158,p->b141);((struct LinkedActor *)a)->b49=-4;func_0c134964(a,owner);
}
void func_0c133f80(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x30305040u;a->pad178[36]=66;a->b19d=0;a->b1a1=71;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=83.33333f;a->f96=0.0f;
 if(!a->w130)a->f92=-a->f92;
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=35;func_0c02a0c4(a,a->b159,a->b158);a->b140=0;((struct LinkedActor *)a)->b49=-6;func_0c134964(a,owner);
}
void func_0c13401c(struct Actor *a,struct Actor *owner)
{
 struct Actor *p=a->p20;short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x20202020u;a->pad178[36]=66;a->b19d=0;a->b1a1=71;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=133.33333f;a->f104=80.0f;
 if(!a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=37;func_0c02a18c(a,a->b159,a->b158,p->b141);((struct LinkedActor *)a)->b49=-6;func_0c134964(a,owner);
}
void func_0c1340f4(struct Actor *a,struct Actor *owner)
{
 struct Actor *p=a->p20;short *slot=(short *)&a->f136;
 *(unsigned int *)&a->b13c=0x20203030u;a->pad178[36]=66;a->b19d=0;a->b1a1=71;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f92=160.0f;a->f104=105.0f;
 if(!a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 *slot=*(short *)&owner->b158;
 a->b159=22;a->b158=36;func_0c02a18c(a,a->b159,a->b158,p->b141);((struct LinkedActor *)a)->b49=-6;func_0c134964(a,owner);
}
void func_0c13419e(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 table_0c24e3cc[a->b32](a,owner);
}
void func_0c13420c(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=32;func_0c02a0c4(a,a->b159,a->b158);return;}
 a->f52=owner->f52+a->f92;a->f56=owner->f56+a->f96;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 func_0c02a026(a);
 if(a->b140){
  struct LinkedActor *r;
  a->b140=0;a->b1a1=70;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
  r=func_0c133c8a((struct LinkedActor *)a);if(r){owner=a->p20;((struct LinkedActor *)owner)->p20=r;((struct LinkedActor *)a)->p20=r;}
 }
 func_0c037d0c(a);
}
void func_0c134300(struct Actor *a,struct Actor *owner)
{
 if(owner->b1d0==29){a->f52=owner->f52+a->f92;a->f56=owner->f56+a->f96;}
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c134346(struct LinkedActor *a){table_0c24e3e4[(unsigned char)a->b5](a);}
void func_0c134358(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;struct Actor *p=a->p20;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=34;func_0c02a0c4(a,a->b159,a->b158);return;}
 if(p->b4>=2)goto done;
 a->f52=p->f52+(!p->b32?a->f92:a->f104);a->f56=p->f56;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 a->b159=22;a->b158=31;func_0c02a18c(a,a->b159,a->b158,p->b141);
 if(!func_0c028642(a)){done:a->b4++;a->b12c=0;return;}
 func_0c037d0c(a);
}
void func_0c134440(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->f52=p->f52+(!p->b32?a->f92:a->f104);a->f56=p->f56;
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c134484(struct LinkedActor *a){table_0c24e3ec[(unsigned char)a->b5](a);}
void func_0c134496(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;struct Actor *p=a->p20;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=33;func_0c02a0c4(a,a->b159,a->b158);return;}
 if(p->b4>=2)goto done;
 a->f52=p->f52+(!p->b32?a->f92:a->f104);a->f56=p->f56;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 a->b159=22;a->b158=30;func_0c02a18c(a,a->b159,a->b158,p->b141);
 if(!func_0c028642(a)){done:a->b4++;a->b12c=0;return;}
 func_0c037d0c(a);
}
void func_0c13457c(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->f52=p->f52+(!p->b32?a->f92:a->f104);a->f56=p->f56;
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c1345c0(struct LinkedActor *a){table_0c24e3f4[(unsigned char)a->b5](a);}
void func_0c1345d2(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;struct Actor *p=a->p20;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=38;func_0c02a0c4(a,a->b159,a->b158);return;}
 a->f52=p->f52+a->f92;a->f56=p->f56+a->f96;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 func_0c02a026(a);
 if(a->b140){
  struct LinkedActor *r;
  a->b140=0;
  r=func_0c133cd8((struct LinkedActor *)a);if(r){owner=p->p20;((struct LinkedActor *)owner)->p20=r;((struct LinkedActor *)p)->p20=r;}
 }
 func_0c037d0c(a);
}
void func_0c134698(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->f52=p->f52+a->f92;a->f56=p->f56+a->f96;
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c1346d6(struct LinkedActor *a){table_0c24e3fc[(unsigned char)a->b5](a);}
void func_0c1346e8(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;struct Actor *p=a->p20;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=40;func_0c02a0c4(a,a->b159,a->b158);return;}
 if(p->b4>=2)goto done;
 a->f52=p->f52+(p->b32==3?a->f92:a->f104);a->f56=p->f56;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 a->b159=22;a->b158=37;func_0c02a18c(a,a->b159,a->b158,p->b141);
 if(!func_0c028642(a)){done:a->b4++;a->b12c=0;return;}
 func_0c037d0c(a);
}
void func_0c1347cc(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->f52=p->f52+(p->b32==3?a->f92:a->f104);a->f56=p->f56;
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c134812(struct LinkedActor *a){table_0c24e404[(unsigned char)a->b5](a);}
void func_0c134824(struct Actor *a,struct Actor *owner)
{
 short *slot=(short *)&a->f136;struct Actor *p=a->p20;
 if(*(short *)&owner->b158!=*slot){a->b5++;a->b159=22;a->b158=39;func_0c02a0c4(a,a->b159,a->b158);return;}
 if(p->b4>=2)goto done;
 a->f52=p->f52+(p->b32==3?a->f92:a->f104);a->f56=p->f56;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 a->b159=22;a->b158=36;func_0c02a18c(a,a->b159,a->b158,p->b141);
 if(!func_0c028642(a)){done:a->b4++;a->b12c=0;return;}
 func_0c037d0c(a);
}
void func_0c13490c(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->f52=p->f52+(p->b32==3?a->f92:a->f104);a->f56=p->f56;
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c134952(struct LinkedActor *a){table_0c24e40c[(unsigned char)a->b5](a);}
void func_0c134964(struct Actor *a,struct Actor *owner){table_0c24e414[(unsigned char)(char)a->b32](a,owner);}
void func_0c134978(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c134986(struct Actor *a){func_0c037688(a);}
