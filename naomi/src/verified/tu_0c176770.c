/* 0x0c176770..0x0c1768a0: strip spawner with signed-byte easing loop and its follow-up hook. Exact. */
#include "objects.h"
struct Strip1767 { unsigned char pad0[10]; short s10; char b12,b13; unsigned char pad14; char b15; float f16,f20,f24,f28; unsigned char pad32[53-32]; char b53; };
struct StripSpec1767 { char b0; unsigned char pad1[2]; char b3; short s4,s6; char b8,b9,b10,b11,b12; };
extern void func_0c1b91e0(struct LinkedActor *,struct LinkedActor *,int);
extern void func_0c174f68(struct LinkedActor *,void *);
void func_0c176770(struct Actor *a,struct Strip1767 *e,struct StripSpec1767 *p)
{
 struct Actor *owner=a->p20;
 struct Strip1767 *q;
 float v[2];
 char x,y,z,w;unsigned char t;
 int i;
 v[0]=p->s4*1.66666663f;
 v[1]=p->s6*2.1428571f;
 e->s10=p->b0;
 e->b53=p->b3;
 x=p->b8;y=p->b10;z=p->b11;w=p->b12;
 e->b13=p->b9;
 if(owner->w130){w=-w;y=-y;x=-x;z=-z;v[0]=-v[0];}
 e->f24=v[0];
 q=e;
 e->f28=v[1];
 e->f16=owner->f52+v[0];
 e->f20=owner->f56+v[1];
 a->b36=owner->b36;
 i=0;goto cond;
 body:
  q->b12=x;
  x+=y;
  if(y>=0){if((char)(w-x)>=0)goto skip;goto setx;}else{if((char)(w-x)<0)goto skip;}setx:x=w;skip:
  y+=z;if((unsigned char)z){goto zz;zz:if(z<0){if(y>0)goto done;t=1;}else{if(y<0)goto done;t=255;}y=t;}done:;
  a=a->p12;
  q=(struct Strip1767 *)((char *)a+0x88);
  i++;
 cond:
 if(i<=e->b15)goto body;
}
void func_0c176868(struct LinkedActor *a,void *arg)
{
 func_0c1b91e0(a->p24,a,2);
 func_0c174f68(a,arg);
}
