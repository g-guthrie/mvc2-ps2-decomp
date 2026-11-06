#include "objects.h"
extern float dat_0c2d92e8,dat_0c2d92ec;
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c14b8d8(struct Actor *,int,int,int);
extern int func_0c02849a(void);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c0a6030(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    a->b6=a->b6+1;
    func_0c025900(a,1,13);
    if (a->w130) a->f52=dat_0c2d92e8+80.0f;
    else a->f52=dat_0c2d92ec-80.0f;
    a->s28=180;
    func_0c14b8d8(a,15,19,15);
    a->b7=func_0c02849a();
    a->b7 &= 1;
    func_0c0344a0(a,5);
    func_0c02a0c4(a,22,11);
    func_0c02a026(a);
}
extern int dat_0c2d962c;
extern short dat_0c2f847a;
extern void func_0c0346da(struct Actor *,int);
struct Vec3_0c0a6030 { float x,y,z; };
struct EffectFrame_0c0a623a { struct Actor *enemy; struct Vec3_0c0a6030 point; };
extern void func_0c1d330c(struct Actor *,struct Vec3_0c0a6030 *,int,int);
extern void func_0c04af58(struct Actor *,int);
void func_0c0a60ac(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (dat_0c2d962c) return;
    if (a->b525 && a->s28!=30) {
        if ((unsigned char)(func_0c02849a() & 1)) {
            a->b6=a->b6+1;
            a->s28=16;
            func_0c14b8d8(a,12,19,12);
        } else {
            a->b6=a->b6+1;
            a->b7=a->b7 ^ 1;
            a->s28=16;
            func_0c14b8d8(a,13,19,13);
        }
        if (dat_0c2f847a>=24) a->b7=1;
        return;
    }
    if (a->w348 & 0x200) {
        a->b6=a->b6+1;
        a->s28=16;
        func_0c14b8d8(a,12,19,12);
        return;
    }
    if (a->w348 & 0x40) {
        a->b6=a->b6+1;
        a->b7=a->b7 ^ 1;
        a->s28=16;
        func_0c14b8d8(a,13,19,13);
        return;
    }
    if (a->s28-- == 0) {
        a->b6=12;
        a->s28=10;
        func_0c02a0c4(a,22,13);
    }
}
void func_0c0a61e6(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->s28-- == 0) {
        a->b6=a->b6+1;
        a->s28=10;
    }
    func_0c02a026(a);
}
void func_0c0a6210(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->s28-- == 0) {
        a->b6=a->b6+1;
        a->s28=10;
    }
    func_0c02a026(a);
}
void func_0c0a623a(struct Actor *a)
{
    struct EffectFrame_0c0a623a frame;
    frame.enemy=a->p20c;
    a->b3f8=2;
    a->b328=5;
    if (a->s28==10) {
        if (a->b7) {
            a->b35=1;
            a->b33=a->b33+1;
            frame.point.x+=a->w130 ? 400.0f : -400.0f;
            frame.point.y=274.285706f;
            frame.point.x=a->f52+frame.point.x;
            frame.point.y=a->f56+frame.point.y;
            func_0c1d330c(a,&frame.point,1,201);
            func_0c0346da(a,73);
            func_0c04af58(frame.enemy,-(a->b33*4));
        } else {
            a->b6=12;
            func_0c02a0c4(a,22,13);
            return;
        }
    }
    if (a->s28<=0) {
        if (a->s30==3) {
            a->b6=9;
            return;
        }
        a->b6=a->b6+1;
        a->s28=23;
        a->b35=0;
        func_0c0344a0(a,16);
        return;
    }
    a->s28=a->s28-1;
    func_0c02a026(a);
}
void func_0c0a634c(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->s28-- == 0) {
        a->b6=a->b6+1;
        a->s28=20;
        return;
    }
    if (!a->b33) func_0c02a026(a);
}
void func_0c0a6384(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->b143<0) a->b6=a->b6+1;
    func_0c02a026(a);
}
