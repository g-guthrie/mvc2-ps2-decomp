/* Private complete capture-motion and visual-effects group, read from retail. */
#include "objects.h"
#define L(a) ((struct LinkedActor *)(a))
#define D0(a) (*(struct Actor **)&(a)->pad5ba[0])
#define D4(a) (*(struct Actor **)&(a)->pad5ba[4])
#define ORIENTATION(a) ((a)->pad6d[0])
extern struct Actor *func_0c0374da(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25574c[])(struct Actor *,struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a684(struct Actor *,int,int,int),func_0c0445fe(struct Actor *,struct Actor *),func_0c03edcc(struct Actor *,struct Actor *),func_0c04ae30(struct Actor *,int),func_0c04afb4(struct Actor *,int),func_0c037688(struct Actor *),func_0c037d0c(struct Actor *),func_0c029e70(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c0288a8(struct Actor *,int);
extern char func_0c02a026(struct Actor *),func_0c029fc4(struct Actor *);
extern int func_0c0447bc(struct Actor *),func_0c02887e(struct LinkedActorVec3 *,struct LinkedActorVec3 *);
void func_0c182f24(struct Actor *,struct Actor *),func_0c182cf2(struct Actor *,struct Actor *),func_0c182f68(struct Actor *,int),func_0c183058(struct Actor *),func_0c183128(struct Actor *),func_0c1831f0(struct Actor *),func_0c18327c(struct Actor *),func_0c183358(struct Actor *);
void func_0c1829d4(struct Actor *a,struct Actor *owner)
{
 struct Vec3_tu5_03 point;struct Actor *enemy;short dx,i;
 a->b4++;L(a)->sdc=L(owner)->sdc;a->b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->f80=owner->f80;a->f84=owner->f84;a->b1a3=owner->b1a3;a->pad7cc[0]=owner->pad7cc[0];L(a)->b48=L(owner)->b48;L(a)->v80=L(owner)->v80;
 a->b36=owner->b36;L(a)->b49=-1;i=0;a->b36=8;a->b33=i;a->pad178[0x19c-0x178]=70;a->b19d=i;
 a->b1a1=68;a->b19e=a->w1ac=i;a->p1c4=i;dat_0c2f83f8->arr[a->b2]++;
 a->w1ac|=512;*(int *)&owner->sub2a4.b20=4;
 dx=24;if(a->w130)dx=-24;a->f52=owner->f52+dx*1.66666663f;a->f56=owner->f56+342.85712f;
 a->f104=a->f108=0;enemy=owner->p20c;point=((struct Obj_tu5_03 *)enemy)->pos;
 point.y+=(enemy->b13c>>1)*2.1428571f;
 a->b34=((unsigned char)func_0c02887e((struct LinkedActorVec3 *)&a->f52,(struct LinkedActorVec3 *)&point)+4)>>3;
 func_0c0288a8(a,2000);a->s30=20;func_0c02a0c4(a,22,24);a->w130=i;ORIENTATION(a)=((a->b34+8)&31)>>1;
 func_0c183128(a);for(i=2;i<8;i++)func_0c182f68(a,i);
}
void func_0c182b8c(struct Actor *a,struct Actor *owner)
{
 *(int *)&owner->sub2a4.b20=4;
 if(a->i204!=*(unsigned short *)&owner->b158)goto finished; if(owner->b411 || owner->b1d0!=29)goto finished;
 func_0c02a684(owner,1,((dat_0c2d6f84->flags&2)>>1)+11,1);table_0c25574c[a->b5](a,owner);return;
finished:func_0c182f24(a,owner);
}
void func_0c182bf6(struct Actor *a,struct Actor *owner)
{
 if(a->b19e){if(!func_0c0447bc(a))goto stopped;a->b5++;a->b36=8;func_0c02a0c4(a,22,21);return;}
 if(--a->s30!=0)goto moving;
stopped:a->b5=3;a->s30=0;goto done;
moving:a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c037d0c(a);return;
done:;
}
void func_0c182cac(struct Actor *a,struct Actor *owner)
{
 struct Actor *child=a->p1b0;int zero=0;a->b5++;a->b36=child->b36;owner->b19d=zero;owner->b1f7=195;
 func_0c0445fe(a,child);D0(a)=owner->p1c8;a->s28=120;a->s30=0;func_0c182cf2(a,owner);
}
void func_0c182cf2(struct Actor *a,struct Actor *owner)
{
 struct Actor *captured=D0(a);struct Vec3_tu5_03 point;int zero;
 owner->b1ea=1;owner->b1ed=2;a->b36=captured->b36;
 point.x=-320.0f;if(owner->w130)point.x=-point.x;point.x+=owner->f52;point.y=owner->f56+360.0f;
 a->f52=(point.x+a->f52*7.0f)/8.0f;a->f56=(point.y+a->f56*7.0f)/8.0f;
 point=((struct Obj_tu5_03 *)owner)->pos;point.x=40.0f;if(owner->w130)point.x=-point.x;point.x+=owner->f52;point.y=owner->f56+342.85712f;
 a->b34=((unsigned char)func_0c02887e((struct LinkedActorVec3 *)&a->f52,(struct LinkedActorVec3 *)&point)+4)>>3;a->w130=a->b34>>4;
 func_0c02a026(a);func_0c03edcc(a,captured);zero=0;a->w130=zero;ORIENTATION(a)=((a->b34-8)&31)>>1;
 if((a->s30+=4096)==0){func_0c18327c(a);func_0c04ae30(owner,1);func_0c04afb4(captured,-2);if(!captured->w420)a->s28=zero;}
 if(--a->s28<0){a->b5++;a->s30=zero;owner->b1ea=zero;captured->p1b4=owner;captured->b1a1=34;captured->b1f9=2;captured->b1d2=owner->b1d2^1;captured->b1f6=1;
 func_0c02a0c4(a,22,24);a->w130=zero;ORIENTATION(a)=((a->b34+8)&31)>>1;}
}
void func_0c182ed0(struct Actor *a,struct Actor *owner)
{
 float x=40.0f,y;if(owner->w130)x=-40.0f;x+=owner->f52;y=owner->f56+342.85712f;
 a->f52=(x+a->f52*3.0f)/4.0f;a->f56=(y+a->f56*3.0f)/4.0f;
 if((a->s30+=2048)==0)func_0c182f24(a,owner);
}
void func_0c182f24(struct Actor *a,struct Actor *owner)
{a->b4=3;a->b12c=0;}
void func_0c182f30(struct Actor *a,struct Actor *owner)
{owner->s28=50;func_0c037688(a);}
void func_0c182f68(struct Actor *parent,int ordinal)
{
 struct Actor *a;if(!(a=func_0c0374da(parent,1,2)))return;
 L(a)->p16=(void (*)(struct LinkedActor *))func_0c183058;L(a)->p24=L(parent);a->b1=parent->b1;a->b32=ordinal;a->w38=0x3604;D4(a)=D4(parent);
 L(a)->sdc=L(D4(parent))->sdc;a->b12c=1;a->b2=D4(parent)->b2;a->b1=D4(parent)->b1;a->f80=D4(parent)->f80;a->f84=D4(parent)->f84;
 a->b1a3=D4(parent)->b1a3;a->pad7cc[0]=D4(parent)->pad7cc[0];L(a)->b48=L(D4(parent))->b48;L(a)->v80=L(D4(parent))->v80;
 a->b36=D4(parent)->b36;a->b12c=1;a->w130=0;a->b36=8;func_0c029e70(a,27,15);
}
void func_0c183058(struct Actor *a)
{
 struct Actor *parent,*owner;
 float x,y,divisor;
 func_0c029fc4(a);
 owner=D4(a);
 parent=(struct Actor *)L(a)->p24;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&parent->f52;
 x=40.0f;
 if(owner->w130)x=-40.0f;
 x+=owner->f52;
 y=owner->f56+342.85712f;
 divisor=8.0f;
 x-=a->f52;
 x/=divisor;
 y-=a->f56;
 y/=divisor;
 a->f52+=x*a->b32;
 a->f56+=y*a->b32;
 ORIENTATION(a)=(parent->b34&31)>>1;
 if(parent->b4>1){a->b12c=0;func_0c037688(a);}
}
void func_0c183128(struct Actor *parent)
{
 struct Actor *a;if(!(a=func_0c0374da(parent,1,2)))return;
 L(a)->p16=(void (*)(struct LinkedActor *))func_0c1831f0;L(a)->p24=L(parent);a->b1=parent->b1;a->w38=0x3604;D4(a)=D4(parent);
 L(a)->sdc=L(D4(parent))->sdc;a->b12c=1;a->b2=D4(parent)->b2;a->b1=D4(parent)->b1;a->f80=D4(parent)->f80;a->f84=D4(parent)->f84;
 a->b1a3=D4(parent)->b1a3;a->pad7cc[0]=D4(parent)->pad7cc[0];L(a)->b48=L(D4(parent))->b48;L(a)->v80=L(D4(parent))->v80;
 a->b36=D4(parent)->b36;a->b12c=1;L(a)->b49=-1;a->f104=40.0f;a->f108=342.85712f;func_0c02a0c4(a,22,20);
}
void func_0c1831f0(struct Actor *a)
{
 struct Actor *owner,*parent;float x;func_0c02a026(a);owner=D4(a);a->b36=owner->b36;x=a->f104;if(owner->w130)x=-x;
 a->f52=owner->f52+x;a->f56=owner->f56+a->f108;parent=(struct Actor *)L(a)->p24;if(parent->b4>1){a->b12c=0;func_0c037688(a);}
}
void func_0c18327c(struct Actor *parent)
{
 struct Actor *a;if(!(a=func_0c0374da(0,1,0)))return;
 L(a)->p16=(void (*)(struct LinkedActor *))func_0c183358;L(a)->p24=L(parent);a->b1=parent->b1;a->w38=0x3604;D4(a)=D4(parent);
 L(a)->sdc=L(D4(parent))->sdc;a->b12c=1;a->b2=D4(parent)->b2;a->b1=D4(parent)->b1;a->f80=D4(parent)->f80;a->f84=D4(parent)->f84;
 a->b1a3=D4(parent)->b1a3;a->pad7cc[0]=D4(parent)->pad7cc[0];L(a)->b48=L(D4(parent))->b48;L(a)->v80=L(D4(parent))->v80;
 a->b36=D4(parent)->b36;a->b12c=1;a->s30=32;a->b36=8;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&parent->f52;
 func_0c02a0c4(a,22,22);func_0c0346da(a,9);
}
void func_0c183358(struct Actor *a)
{
 struct Actor *owner=D4(a);float x=40.0f,y;if(owner->w130)x=-40.0f;x+=owner->f52;y=owner->f56+342.85712f;
 a->f52=(x+a->f52*3.0f)/4.0f;a->f56=(y+a->f56*3.0f)/4.0f;
 if(func_0c02a026(a)<0){a->b12c=0;func_0c037688(a);}
}
