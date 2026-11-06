#include "objects.h"
#define E(o) ((union ActorSubEffectState *)&(o)->sub2a4)
#define P(o) (*(struct Vec3_tu5_03 *)&(o)->f52)
struct ShortPair { short a, b; };
extern struct Effect1cf *func_0c0374da(void *,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct Vec3_tu5_03 dat_0c260c68;
extern struct Vec3_tu5_03 dat_0c260c74;
extern void (*dat_0c260c80[])(struct Effect1cf *);
extern void (*dat_0c260c90[])(struct Effect1cf *);
extern int dat_0c260cac[];
extern struct Vec3_tu5_03 dat_0c260cc4[];
extern struct Vec3_tu5_03 dat_0c260d0c[];
extern struct ShortPair dat_0c260d30[];
extern void (*dat_0c260d3c[])(struct Effect1cf *);
extern void func_0c03462c(struct Effect1cf *,int);
extern void func_0c1d9314(int,float,float,float,float);
extern float func_0c1ec2c0(int);
extern float func_0c1ebd40(int);
extern void func_0c026932(void);
extern void func_0c037688(struct Effect1cf *);
void func_0c1cf21e(struct Actor *o,int kind,char b32,char b33);
void func_0c1cf258(struct Effect1cf *a);
void func_0c1cf5d6(struct Effect1cf *a);
void func_0c1cfbe0(struct Effect1cf *a);
void func_0c1cf17c(struct Actor *o)
{
    func_0c1cf21e(o,7,0,0);
    func_0c1cf21e(o,7,1,0);
    func_0c1cf21e(o,6,0,1);
    func_0c1cf21e(o,6,1,1);
}
void func_0c1cf1ac(struct Actor *o)
{
    func_0c1cf21e(o,5,3,0);
    func_0c1cf21e(o,7,4,0);
    func_0c1cf21e(o,7,4,1);
    func_0c1cf21e(o,7,4,2);
    func_0c1cf21e(o,7,4,3);
    func_0c1cf21e(o,7,4,4);
    func_0c1cf21e(o,7,4,5);
}
void func_0c1cf1fa(struct Actor *o)
{
    func_0c1cf21e(o,7,5,0);
    func_0c1cf21e(o,7,5,1);
    func_0c1cf21e(o,7,5,2);
}
void func_0c1cf21e(struct Actor *o,int kind,char b32,char b33)
{
    struct Effect1cf *a;
    if((a=func_0c0374da(0,kind,1))!=0){
        a->p16=func_0c1cf258;
        a->p24=o;
        a->b32=b32;
        a->b33=b33;
    }
}
void func_0c1cf258(struct Effect1cf *a)
{
    dat_0c260c80[a->b4](a);
}
void func_0c1cf26a(struct Effect1cf *a)
{
    a->b4++;
    dat_0c260c90[a->b32](a);
    func_0c1cf5d6(a);
}
void func_0c1cf28e(struct Effect1cf *a)
{
    a->lcc=45;
    a->l84=((int *)dat_0c2d964c->p0)[90];
    a->sc.f116=1.0f;
    if(a->b3==7){
        (&a->lcc)[0]=a->lcc|16;
        a->v80=dat_0c260c68;
    }
}
void func_0c1cf2f4(struct Effect1cf *a)
{
    struct Effect1cf *c;
    a->lcc=0x40d;
    a->l84=((int *)dat_0c2d964c->p0)[88];
    a->sc.f120=1.0f;
    a->sc.f124=0.0f;
    a->sc.f128=0.0f;
    if(a->b3==7){
        (&a->lcc)[0]=a->lcc|16;
        a->v80=dat_0c260c68;
    }
    if((c=func_0c0374da(a,(char)a->b3,2))!=0){
        c->p16=func_0c1cf258;
        c->p24=a->p24;
        c->b32=a->b32+1;
        c->b33=a->b33;
    }
}
void func_0c1cf36c(struct Effect1cf *a)
{
    struct Effect1cf *p=a->p8;
    a->lcc=p->lcc;
    a->l84=((int *)dat_0c2d964c->p0)[89];
    a->sc=p->sc;
    a->v80=p->v80;
}
void func_0c1cf3a6(struct Effect1cf *a)
{
    a->lcc=61;
    a->l84=((int *)dat_0c2d964c->p0)[90];
    a->sc.f116=1.0f;
    a->v80=dat_0c260c74;
    a->s30=0xd2;
    func_0c03462c(a,16);
}
void func_0c1cf408(struct Effect1cf *a)
{
    a->b12c=1;
    a->lcc=0x41f;
    a->l84=((int *)dat_0c2d964c->p0)[88+(a->b33&1)];
    a->sc.f120=1.0f;
    a->sc.f124=0.0f;
    a->sc.f128=0.0f;
    a->v80=dat_0c260c68;
    a->ang[0]=a->ang[1]=a->ang[2]=0;
    *(int *)&a->u92.v.x=dat_0c260cac[a->b33];
    a->s28=0;
    a->v104.x=dat_0c260cc4[a->b33].x*0.1000000015f;
    a->v104.y=dat_0c260cc4[a->b33].y*0.1000000015f;
    a->v104.z=dat_0c260cc4[a->b33].z*0.1000000015f;
}
void func_0c1cf4c6(struct Effect1cf *a)
{
    a->lcc=0x413;
    a->l84=((int *)dat_0c2d9650->p0)[183];
    a->sc.f116=1.0f;
    a->sc.f128=1.0f;
    a->sc.f124=1.0f;
    a->sc.f120=1.0f;
    a->v80=dat_0c260c74;
    a->ang[0]=0x1555;
    if(a->b33==2||a->b33==5)a->ang[0]+=0x4000;
    a->u92.v=dat_0c260d0c[a->b33];
    a->s28=dat_0c260d30[a->b33].a;
    a->s30=dat_0c260d30[a->b33].b;
}
void func_0c1cf598(struct Effect1cf *a)
{
    a->b12c=1;
    a->lcc=0x411;
    a->l84=((int *)dat_0c2d9650->p0)[134];
    a->sc.f120=a->sc.f124=a->sc.f128=1.0f;
    a->v80=dat_0c260c74;
    a->s28=0;
}
void func_0c1cf5d6(struct Effect1cf *a)
{
    dat_0c260d3c[a->b32](a);
}
void func_0c1cf5ea(struct Effect1cf *a)
{
    struct Actor *o=a->p24;
    union ActorSubEffectState *e=E(o);
    float f;
    if((a->b12c=e->bytes[a->b33])==0)return;
    a->sc.f116=e->parameter.f4;
    a->pos=((struct Effect1cf *)o)->pos;
    f=o->f80*40.0f;
    if(!o->w130)f=-f;
    a->pos.x+=f;
    a->pos.y+=205.71428f*o->f84;
    if(!o->b1a0){
        a->s28++;
        a->ang[1]=(int)((float)((a->s28+a->s30)*2)*65536.0f/360.0f+0.5f)&0xffff;
        a->ang[2]=(int)((float)((a->s28+a->s30)*3)*65536.0f/360.0f+0.5f)&0xffff;
    }
    {float s=o->f128;func_0c1d9314(a->l84,o->f116,o->f120,s,s);}
}
void func_0c1cf718(struct Effect1cf *a)
{
    struct Actor *o=a->p24;
    union ActorSubEffectState *e=E(o);
    float f;
    if((a->b12c=e->bytes[a->b33])==0)return;
    a->pos=((struct Effect1cf *)o)->pos;
    f=o->f80*40.0f;
    if(!o->w130)f=-f;
    a->pos.x+=f;
    a->pos.y+=205.71428f*o->f84;
    if(!o->b1a0){
        a->s28++;
        a->ang[1]=(int)((float)((a->s28+a->s30)*2)*65536.0f/360.0f+0.5f)&0xffff;
        a->ang[2]=(int)((float)((a->s28+a->s30)*3)*65536.0f/360.0f+0.5f)&0xffff;
        a->sc.f120=(0.5f+0.5f*func_0c1ec2c0((int)((float)(a->s28%360)*65536.0f/360.0f+0.5f)&0xffff))*e->parameter.f4;
        a->sc.f124=(0.5f+0.5f*func_0c1ebd40((int)((float)(a->s28%360)*65536.0f/360.0f+0.5f)&0xffff))*e->parameter.f4;
    }else{
        a->sc.f120=e->parameter.f4*1.0f;
        a->sc.f124=0.0f;
    }
}
void func_0c1cf8a0(struct Effect1cf *a)
{
    struct Effect1cf *p=a->p8;
    a->b12c=0;
    if((a->b4=p->b4)>=2)return;
    if((a->b12c=p->b12c)==0)return;
    a->pos=p->pos;
    a->sc=p->sc;
    a->v80=p->v80;
    a->ang[0]=p->ang[0];
    a->ang[1]=p->ang[1];
    a->ang[2]=p->ang[2];
}
void func_0c1cf908(struct Effect1cf *a)
{
    a->b12c=1;
    func_0c1cfbe0(a);
    a->s28++;
    a->ang[1]=(int)((float)(a->s28*2)*65536.0f/360.0f+0.5f)&0xffff;
    a->ang[2]=(int)((float)(a->s28*3)*65536.0f/360.0f+0.5f)&0xffff;
    if(!a->b5){
        if(--a->s30<=0)a->b5++;
    }else{
        a->sc.f116-=0.0333333351f;
        if(0.0f>a->sc.f116){
            a->b4++;
            a->b12c=0;
        }
    }
}
void func_0c1cf9c0(struct Effect1cf *a)
{
    func_0c1cfbe0(a);
    a->ang[0]+=*(int *)&a->u92.v.x;
    a->ang[1]+=*(int *)&a->u92.v.x;
    a->ang[2]+=*(int *)&a->u92.v.x;
    a->s28++;
    if(!a->b5){
        if((float)a->s28==100.0f)a->b5=1;
    }
    if(!a->b6){
        if((float)a->s28==160.0f)a->b6=1;
    }
    if(a->b5){
        a->v80.x+=a->v104.x;
        a->v80.y+=a->v104.y;
        a->v80.z+=a->v104.z;
    }
    if(a->b6){
        if((a->sc.f120-=0.050000001f)>0.0f)return;
        a->b4++;
        a->b12c=0;
        if(a->b33)return;
        func_0c026932();
        func_0c1cf1fa(a->p24);
        func_0c03462c(a,17);
    }
}
void func_0c1cfac4(struct Effect1cf *a)
{
    if(!a->b5){
        if(--a->s28>0)return;
        a->b5++;
        a->b12c=1;
    }
    func_0c1cfbe0(a);
    a->v80.x+=a->u92.v.x;
    a->v80.y+=a->u92.v.y;
    a->v80.z+=a->u92.v.z;
    if(!a->b6){
        if(--a->s30<=0)a->b6=1;
    }
    if(a->b6){
        a->sc.f120-=0.1000000015f;
        a->sc.f124-=0.1000000015f;
        if(0.0f>(a->sc.f128-=0.1000000015f)){
            a->b4++;
            a->b12c=0;
        }
    }
}
void func_0c1cfb66(struct Effect1cf *a)
{
    func_0c1cfbe0(a);
    a->v80.x+=0.125f;
    a->v80.y+=0.125f;
    if(!a->b5){
        if(--a->s28<0)a->b5++;
    }else{
        a->sc.f120-=0.050000001f;
        a->sc.f124-=0.050000001f;
        if(0.0f>(a->sc.f128-=0.050000001f)){
            a->b4++;
            a->b12c=0;
        }
    }
}
void func_0c1cfbe0(struct Effect1cf *a)
{
    struct Actor *o=a->p24;
    float f;
    a->pos=P(o);
    f=o->f80*40.0f;
    if(!o->w130)f=-f;
    a->pos.x+=f;
    a->pos.y+=205.71428f*o->f84;
}
void func_0c1cfc26(struct Effect1cf *a)
{
    a->b4++;
    a->b12c=0;
}
void func_0c1cfc34(struct Effect1cf *a)
{
    func_0c037688(a);
}
