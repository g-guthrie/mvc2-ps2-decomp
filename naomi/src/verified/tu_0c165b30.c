/* Owner-linked effect actors spawned by 0x0c165b30: per-mode init, follow and expire states. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct FloatPair_0c251e50 { float x, y; };
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern float func_0c1ec2c0(int);
extern struct ActorSub2a4 *dat_0c2fb398;
extern short *dat_0c2fb394;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c251dc0[])(struct LinkedActor *);
extern void (*dat_0c251df0[])(struct LinkedActor *);
extern void (*dat_0c251e08[])(struct LinkedActor *);
extern void (*dat_0c251e40[])(struct LinkedActor *);
extern void (*dat_0c251e60[])(struct LinkedActor *);
extern void (*dat_0c251e70[])(struct LinkedActor *);
extern float dat_0c251e00[];
extern int dat_0c251e18[];
extern struct FloatPair_0c251e50 dat_0c251e50[];
extern unsigned char dat_0c251e80[];
extern struct FloatPair_0c251e50 dat_0c251e84[];
extern struct FloatPair_0c251e50 dat_0c251e88[];
void func_0c165b72(struct LinkedActor *a);
void func_0c165de2(struct LinkedActor *a);
void func_0c165ed6(struct LinkedActor *a);
void func_0c16612e(struct LinkedActor *a);
void func_0c1661d2(struct LinkedActor *a);
void func_0c16633e(struct LinkedActor *a);
void func_0c1666ca(struct LinkedActor *a);
void func_0c1666d8(struct LinkedActor *a);

struct LinkedActor *func_0c165b30(struct LinkedActor *owner,char mode,char sub)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c165b72;a->p24=owner;a->b32=mode;a->b33=sub;a->w38=0x2100;}
 return a;
}
void func_0c165b72(struct LinkedActor *a)
{
 dat_0c2fb398=&A(a->p24)->sub2a4;dat_0c2fb394=&a->wcc.short_value;
 dat_0c251dc0[a->b32](a);
}
void func_0c165b9a(struct LinkedActor *a){dat_0c251df0[a->b4](a);}
void func_0c165bac(struct LinkedActor *a)
{
 void *z;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;
 dat_0c2fb398->b2=1;
 A(a)->b19c=66;A(a)->b19d=66;
 A(a)->b1a1=a->b1a3?50:48;
 z=0;A(a)->w1ac=(int)z;A(a)->b19e=(int)z;A(a)->p1c4=(int)z;
 dat_0c2f83f8->arr[a->b2]++;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 a->f52+=A(a->p24)->b1d2?66.666664124f:-66.666664124f;
 a->f56+=154.28571f;
 A(a)->b13e=32;A(a)->b13f=32;
 A(a)->f92=0.0f;a->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;
 A(a)->f92=A(a->p24)->b1d2?dat_0c251e00[a->b1a3]:-dat_0c251e00[a->b1a3];
 a->b36=(int)z;
 func_0c02a0c4(a,20,0);
}
void func_0c165d38(struct LinkedActor *a)
{
 if(A(a)->b19e||A(a)->b19f){func_0c165de2(a);return;}
 if(!func_0c028642(a)){dat_0c2fb398->b2=0;func_0c1666d8(a);return;}
 a->b36=0;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c037d0c(a);
}
void func_0c165dbe(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){func_0c1666d8(a);return;}
 a->b36=0;
}
void func_0c165de2(struct LinkedActor *a)
{
 a->b4++;dat_0c2fb398->b2=0;func_0c02a0c4(a,20,1);
}
void func_0c165e24(struct LinkedActor *a){dat_0c251e08[a->b4](a);}
void func_0c165e36(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;
 *dat_0c2fb394=a->p24->sdc.w158.short_value;
 a->b36=0;
 func_0c02a0c4(a,23,dat_0c251e18[a->b32]);
 func_0c165ed6(a);
}
void func_0c165ed6(struct LinkedActor *a)
{
 char t;
 if(*dat_0c2fb394!=a->p24->sdc.w158.short_value)goto kill;
 a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;a->sdc.b12c=0;
 if(!(t=((char *)&A(a->p24)->w150)[1]&0xfe))return;
 if(t<0){kill:func_0c1666d8(a);return;}
 a->sdc.b12c=1;
 while(t!=((char *)&A(a)->w150)[1])func_0c02a026(a);
}
void func_0c165f52(struct LinkedActor *a){dat_0c251e40[a->b4](a);}
void func_0c165f90(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;
 A(a)->b19c=66;A(a)->b19d=66;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 a->f52+=A(a->p24)->b1d2?156.66666f:-156.66666f;
 a->f56+=259.28571f;
 A(a)->b13e=64;A(a)->b13f=64;
 a->b36=0;
 if(A(owner)->b255==3)A(a)->b1a1=83;else{goto set;set:A(a)->b1a1=a->b1a3?68:66;}
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 goto s2;s2:A(a)->f92=a->sdc.w130?dat_0c251e50[a->b1a3].x:-dat_0c251e50[a->b1a3].x;
 a->f96=dat_0c251e50[a->b1a3].y;A(a)->f104=0.0f;A(a)->f108=0.0f;
 func_0c02a0c4(a,20,5);
 func_0c16612e(a);
}
void func_0c16612e(struct LinkedActor *a)
{
 if(A(a)->b19f)goto next;
 if(!func_0c028642(a)){func_0c1666d8(a);return;}
 a->b36=0;
 if(!(a->f56>A(a->p24)->f41c)){next:func_0c1661d2(a);return;}
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c037d0c(a);
}
void func_0c1661b2(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0)func_0c1666d8(a);
}
void func_0c1661d2(struct LinkedActor *a)
{
 a->b4++;func_0c02a0c4(a,20,6);
}
void func_0c1661e0(struct LinkedActor *a){dat_0c251e60[a->b4](a);}
void func_0c166214(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;
 A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=69;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 a->f52=a->p24->f52;
 a->f52+=a->sdc.w130?156.66666f:-156.66666f;
 a->f56=a->p24->f56;
 a->f56+=259.28571f;
 A(a)->b13e=64;A(a)->b13f=64;
 A(a)->f92=a->sdc.w130?20.0f:-20.0f;
 a->f96=18.214285f;A(a)->f104=0.0f;A(a)->f108=0.0f;
 a->b36=0;
 func_0c02a0c4(a,20,7);
 func_0c16633e(a);
}
void func_0c16633e(struct LinkedActor *a)
{
 if(A(a)->b19f)goto next;
 if(!func_0c028642(a)){func_0c1666d8(a);return;}
 a->b36=0;
 if(!(a->f56>A(a->p24)->f41c)){next:func_0c1661d2(a);return;}
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c037d0c(a);
}
void func_0c1663fc(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0)func_0c1666d8(a);
}
void func_0c16641c(struct LinkedActor *a){dat_0c251e70[a->b4](a);}
void func_0c16642e(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;
 A(a)->b19c=66;A(a)->b19d=66;
 A(a)->b1a1=A(a)->b33?80:79;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 a->f52+=a->sdc.w130?dat_0c251e84[A(a)->b33].x:-dat_0c251e84[A(a)->b33].x;
 a->f56+=dat_0c251e88[A(a)->b33].x;
 A(a)->b13e=32;A(a)->b13f=32;
 A(a)->f92=0.0f;a->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;
 if(a->sdc.w130)A(a)->f92=6.66666651f;else A(a)->f92=-6.66666651f;
 a->b36=0;
 a->s28=a->s30=2;
 a->b34=dat_0c251e80[A(a)->b33];
 func_0c02a0c4(a,20,0);
}
void func_0c1665b4(struct LinkedActor *a)
{
 if(A(a)->b19f||A(a)->b19e){func_0c1666ca(a);return;}
 if(!func_0c028642(a)){func_0c1666d8(a);return;}
 if(A(a)->b33){
  a->f56+=func_0c1ec2c0(((40-a->b34)&31)<<11)*8.5714283f;
  if(--a->s28==0){a->s28=a->s30;a->b34=++a->b34&31;}
 }
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c037d0c(a);
}
void func_0c1666aa(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0)func_0c1666d8(a);
}
void func_0c1666ca(struct LinkedActor *a)
{
 a->b4++;func_0c02a0c4(a,20,1);
}
void func_0c1666d8(struct LinkedActor *a){a->b4=3;a->sdc.b12c=0;}
void func_0c1666e4(struct LinkedActor *a){func_0c037688(a);}
