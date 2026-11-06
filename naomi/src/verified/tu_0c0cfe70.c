#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0432ca(struct Actor *);
extern void (*dat_0c2482a8[])(struct Actor *);
extern void (*dat_0c2482dc[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c1b0b40(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c025900(struct Actor *,int,int),func_0c044548(struct Actor *,struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c0ce574(struct Actor *),func_0c1b0b40(struct Actor *,int);
extern void func_0c04b02a(struct Actor *),func_0c04c010(struct Actor *,struct Actor *,int),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int),func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c04c010(struct Actor *,struct Actor *,int),func_0c04b02a(struct Actor *),func_0c025762(void);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c02a684(struct Actor *,int,int,int),func_0c1af524(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void (*dat_0c248304[])(struct Actor *);
extern void func_0c1630dc(struct Actor *,int),func_0c0438de(struct Actor *);
void func_0c0cfe70(struct Actor *a)
{
 if(!a->b6){
  a->b6++;
  func_0c02a0c4(a,19,5);
 }
 else func_0c02a026(a);
}
void func_0c0cfe8a(struct Actor *a)
{
 if(!a->b6){
  a->b6++;
  func_0c02a0c4(a,19,4);
 }
 else func_0c02a026(a);
}
void func_0c0cfea4(struct Actor *a)
{
 if(!a->b6){
  a->b6++;
  func_0c02a0c4(a,19,6);
 }
 else func_0c02a026(a);
}
void func_0c0cfebe(struct Actor *a)
{
 func_0c0344a0(a,43);
 a->f92=0.0f;
 a->f96=0.0f;
 a->f104=0.0f;
 a->f108=0.0f;
 a->b1fc=0;
 a->b1f9=0;
 a->f56=a->f41c;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 func_0c0432ca(a);
}
void func_0c0cff06(struct Actor *a)
{
 dat_0c2482a8[a->b1e9](a);
}
void func_0c0cff1a(struct Actor *a)
{
 dat_0c2482dc[a->b6](a);
}
void func_0c0cff2c(struct Actor *a)
{
 if(a->b255==6){
  a->b3f0=255;
  a->b3f1=16;
 }
 a->b6++;
 a->s28=15;
 func_0c0cfebe(a);
 a->b1a1=57;
 a->w1ac=0;
 a->b19e=0;
 a->p1c4=0;
 goto l;l:dat_0c2f83f8->arr[a->b2]++;
 a->w1ac|=0x200;
 func_0c02a0c4(a,22,0);
}

void func_0c0cffcc(struct Actor *a)
{
 struct LinkedActorVec3 v;
 a->b3f8=2;
 a->b328=5;
 a->b3f1=a->b255==6?2:0;
 a->b6++;
 a->b3f0=0;
 a->b3f1=0;
 v.x=0.0f;
 v.y=162.857132f;
 v.z=0.0f;
 func_0c0429a4(a,&v,1);
}
void func_0c0d0020(struct Actor *a)
{
 a->b3f8=2;
 a->b328=5;
 func_0c02a026(a);
 if(a->s28==15){
  func_0c1b0b40(a,4);
  func_0c02a684(a,3,2,1);
 }
 if(--a->s28<0){
  a->b6++;
  a->s28=15;
  func_0c02a0c4(a,22,1);
  a->f96=0.0f;
  a->f108=0.0f;
  a->f92=-13.33333302f;
  a->f104=0.1041666642f;
  if(a->w130){
   a->f92=-a->f92;
   a->f104=-a->f104;
  }
 }
}

void func_0c0d00d8(struct Actor *a)
{
 a->b3f8=2;
 a->b328=5;
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 func_0c02a026(a);
 if(a->b19e){
  if(func_0c0447bc(a)){
   func_0c025900(a,13,7);
   a->b6=6;
   a->s28=47;
   a->s30=0;
   func_0c02a0c4(a,22,4);
   a->b1f7=194;
   func_0c044548(a,a->p1b0);
  }
  else{
   a->b3f9=0;
   a->b3f8=0;
   a->b327=0;
   a->b328=0;
   a->b1f9=2;
   a->b6=4;
   a->f92=-1.66666663f;
   a->f104=0.00651041651145f;
   a->f96=12.85714245f;
   a->f108=-0.5357143f;
   if(!a->w130){
    a->f92=-a->f92;
    a->f104=-a->f104;
   }
   func_0c02a0c4(a,22,2);
  }
  a->b1a0=10;
 }
 else if(--a->s28<0){
  a->b6=5;
  func_0c02a0c4(a,22,3);
  a->b3f9=0;
  a->b3f8=0;
  a->b327=0;
  a->b328=0;
 }
}

void func_0c0d0244(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(a->f56<a->f41c){
  a->f92=0.0f;
  a->f96=0.0f;
  a->f104=0.0f;
  a->f108=0.0f;
  a->f56=a->f41c;
  a->b1f9=0;
  func_0c043324(a);
  func_0c0437b8(a);
 }
}
void func_0c0d02c8(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0ce574(a);
}
void func_0c0d02ea(struct Actor *a)
{
 unsigned char r;
 struct LinkedActorVec3 v;
 register float y;
 a->b3f8=2;
 a->b328=5;
 a->b1ea=1;
 a->b1ed=2;
 func_0c02a026(a);
 if(--a->s28<0){
  if(a->s30==0){
   a->s28=63;
   a->s30++;
   func_0c02a0c4(a,22,5);
   func_0c1b0b40(a,3);
   *(int *)&a->pad10c[0x2f0-0x2cc]=33;
  }
  else{
   *(int *)&a->pad10c[0x2f0-0x2cc]=34;
   a->b6++;
   a->s28=63;
   func_0c02a0c4(a,22,6);
   a->f92=0.0f;
   a->f104=0.0f;
   a->f96=6.428571224213f;
   a->f108=-0.066964284f;
  }
 }
 else if(a->b141){
  a->b141=0;
  a->p1c8->p1b4=a;
  if(a->s30==0){goto l;l:a->p1c8->b1a1=58;}
  else a->p1c8->b1a1=59;
  func_0c04b02a(a);
  func_0c04c010(a->p1c8,a,1);
  y=120.0f;
  if(a->s30){
   v.x=-60.0f;
   v.y=y;
   func_0c1cea66(a,&v,3);
  }
  else{
   r=func_0c02849a()&7;
   v.x=-123.33333f;
   v.y=y;
   func_0c1cea66(a,&v,r+9);
  }
 }
 func_0c03edcc(a,a->p1c8);
}

void func_0c0d0470(struct Actor *a)
{
 struct Actor *t=a->p1c8;
 a->b3f8=2;
 a->b328=5;
 a->b1ea=1;
 a->b1ed=2;
 func_0c02a026(a);
 if(a->b141){
  a->f52+=a->f92;
  a->f92+=a->f104;
  a->f56+=a->f96;
  a->f96+=a->f108;
  if(a->b141<0){
   *(int *)&a->pad10c[0x2f0-0x2cc]=35;
   a->b141=0;
   a->b6++;
   a->f92=-3.3333333f;
   a->f104=0.0520833321f;
   a->f96=4.28571415f;
   a->f108=-0.2678571343422f;
   t->f92=0.0f;
   t->f96=0.0f;
   t->f104=0.0f;
   t->f108=0.0f;
   t->f92=(a->f52-t->f52)/16.0f;
   t->f96=(t->f41c-t->f56)/8.0f;
   if(!a->w130){
    a->f92=-a->f92;
    a->f104=-a->f104;
   }
   return;
  }
 }
 func_0c03edcc(a,a->p1c8);
}

void func_0c0d05ac(struct Actor *a)
{
 a->b3f8=2;
 a->b328=5;
 a->b1ea=1;
 a->b1ed=2;
 func_0c02a026(a);
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 a->p1c8->f52+=a->p1c8->f92;
 a->p1c8->f92+=a->p1c8->f104;
 a->p1c8->f56+=a->p1c8->f96;
 a->p1c8->f96+=a->p1c8->f108;
 if(a->p1c8->f41c>a->p1c8->f56){
  a->p1c8->f92=0.0f;
  a->p1c8->f96=0.0f;
  a->p1c8->f104=0.0f;
  a->p1c8->f108=0.0f;
  a->p1c8->f56=a->p1c8->f41c;
  a->p1c8->b12c=0;
 }
 if(a->f41c>a->f56){
  a->b3f9=0;
  a->b3f8=0;
  a->b327=0;
  a->b328=0;
  a->f56=a->f41c;
  a->b6++;
  a->s28=36;
  func_0c043324(a);
  func_0c02a0c4(a,22,7);
  func_0c04c010(a->p1c8,a,1);
  a->p1c8->b1f6=16;
  a->b1a1=a->p1c8->b1a1=60;
  a->p1c8->f56=a->f41c+51.42857f;
  a->p1c8->b12c=1;
  func_0c04b02a(a);
  *(int *)&a->pad10c[0x2f0-0x2cc]=36;
  func_0c025762();
 }
}

void func_0c0d075c(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28<0)func_0c0437b8(a);
}
void func_0c0d0782(struct Actor *a)
{
 dat_0c248304[a->b6](a);
}
void func_0c0d0794(struct Actor *a)
{
 if(a->b255==6){
  a->b3f0=255;
  a->b3f1=16;
 }
 a->b6++;
 a->s28=128;
 func_0c0cfebe(a);
 func_0c02a684(a,7,a->b37+3,1);
 a->b1a1=56;
 a->w1ac=0;
 a->b19e=0;
 a->p1c4=0;
 goto l2;l2:dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,22,8);
 func_0c1af524(a,5,0);
}
void func_0c0d080e(struct Actor *a)
{
 struct LinkedActorVec3 v;
 a->b3f8=2;
 a->b328=5;
 a->b3f1=a->b255==6?2:0;
 a->b6++;
 a->b3f0=0;
 a->b3f1=0;
 v.x=0.0f;
 v.y=162.857132f;
 v.z=0.0f;
 func_0c0429a4(a,&v,1);
}
void func_0c0d0862(struct Actor *a)
{
 a->b3f8=2;
 a->b328=5;
 a->s28--;
 if(a->b141){
  a->b6++;
  a->b141=0;
  func_0c1af524(a,6,0);
 }
 func_0c02a026(a);
}
void func_0c0d08d8(register struct Actor *a)
{
 register void *zero;
 zero=0;
 a->b3f8=2;
 a->b328=5;
 if(--a->s28<0){
  a->b6++;
  func_0c02a0c4(a,22,9);
  func_0c1af524(a,7,0);
  a->b3f9=0;
  a->b3f8=(int)zero;
  a->b327=(int)zero;
  a->b328=(int)zero;
 }
 else{
  if(a->b141==1){
   a->b141=(int)zero;
   func_0c1630dc(a,0);
   func_0c1630dc(a,3);
  }
  if(a->b141==2){
   a->b141=(int)zero;
   func_0c1630dc(a,1);
   func_0c1630dc(a,2);
  }
 }
 func_0c02a026(a);
}
void func_0c0d096a(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0d098c(struct Actor *a)
{
 if(a->b1f9==2)func_0c0438de(a);
 else func_0c0ce574(a);
}
void func_0c0d09cc(struct Actor *a)
{
 struct LinkedActorVec3 v;
 register float fz=0.0f;
 if(!a->b7){
  if(a->b255==6){
   a->b3f0=255;
   a->b3f1=16;
  }
  a->b7++;
  func_0c0cfebe(a);
  a->f92=-5.0f;
  a->f104=fz;
  if(a->w130)a->f92=-a->f92;
  a->b1a1=61;
  a->w1ac=0;
  a->b19e=0;
  a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,22,10);
 }
 else{
  a->b3f8=2;
  a->b328=5;
  a->b3f1=a->b255==6?2:0;
  func_0c02a026(a);
  if(a->b141){
   a->b6++;
   a->b7=0;
   a->b141=0;
   a->b3f0=0;
   a->b3f1=0;
   v.x=fz;
   v.y=162.857132f;
   v.z=fz;
   func_0c0429a4(a,&v,1);
  }
 }
}
