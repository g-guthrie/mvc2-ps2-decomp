#include "objects.h"
struct Vec3_0c0a4268 { float x,y,z; };
extern char func_0c02a026(struct Actor *);
extern void func_0c1cea66(struct Actor *,struct Vec3_0c0a4268 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c19fadc(struct Actor *,int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern int func_0c043628(struct Actor *);
extern unsigned int func_0c02849a(void);
extern unsigned char dat_0c24412c[];
extern void (*dat_0c2440e0[])(struct Actor *);
extern void (*dat_0c2440e8[])(struct Actor *);
extern void (*dat_0c244114[])(struct Actor *);
extern void (*dat_0c24411c[])(struct Actor *);
extern void (*dat_0c244124[])(struct Actor *);
extern void (*dat_0c24414c[])(struct Actor *);
extern void (*dat_0c244180[])(struct Actor *);
void func_0c0a42e8(struct Actor *);
void func_0c0a4448(struct Actor *);
void func_0c0a4268(struct Actor *a)
{
    struct Vec3_0c0a4268 v;
    if (a->b141==1) {
        a->b141=0;
        v.x=80.0f;
        v.y=34.2857132f;
        func_0c1cea66(a,&v,2);
        func_0c0346da(a,2);
    }
    if (func_0c02a026(a)<0) a->b5=a->b5+1;
}
void func_0c0a42b8(struct Actor *a)
{
    dat_0c2440e0[a->b6](a);
}
void func_0c0a42ca(struct Actor *a)
{
    a->b6=a->b6+1;
    if (!a->b32) func_0c0a4448(a);
    func_0c0a42e8(a);
}
void func_0c0a42e8(struct Actor *a)
{
    if (func_0c03916c(a)) func_0c0437b8(a);
    else dat_0c2440e8[a->b32](a);
}
void func_0c0a4314(struct Actor *a)
{
    dat_0c244114[a->b7](a);
}
void func_0c0a4326(struct Actor *a)
{
    a->b7=a->b7+1;
    func_0c02a39a(a,0);
    a->f92=0;
    a->f96=0;
    a->f104=0;
    a->f108=0;
    a->f56=a->f41c;
    a->b1fc=0;
    a->b1f9=0;
    func_0c02a0c4(a,19,2);
}
void func_0c0a436c(struct Actor *a)
{
    func_0c02a026(a);
}
void func_0c0a4372(struct Actor *a)
{
    dat_0c24411c[a->b7](a);
}
void func_0c0a4384(struct Actor *a)
{
    a->b7=a->b7+1;
    func_0c0442fa(a);
    func_0c02a0c4(a,19,0);
}
void func_0c0a43a4(struct Actor *a)
{
    func_0c02a026(a);
}
void func_0c0a43e8(struct Actor *a)
{
    dat_0c244124[a->b7](a);
}
void func_0c0a43fa(struct Actor *a)
{
    a->b7=a->b7+1;
    func_0c0442fa(a);
    func_0c02a0c4(a,19,1);
}
void func_0c0a441a(struct Actor *a)
{
    if (a->b141==1) {
        a->b141=0;
        func_0c19fadc(a,14);
        func_0c19fadc(a,10);
    }
    func_0c02a026(a);
}
void func_0c0a4448(struct Actor *a)
{
    if (a->w340 & 0x3f0) {
        if (a->w340 & 0x200) a->b32=5;
        else if (a->w340 & 0x100) a->b32=6;
        else if (a->w340 & 0x80) a->b32=7;
        else if (a->w340 & 0x40) a->b32=8;
        else if (a->w340 & 0x20) a->b32=9;
        else a->b32=10;
    } else a->b32=dat_0c24412c[(func_0c02849a() & 15)*2];
    if (func_0c043628(a)>1) a->b32=5;
}
void func_0c0a44d0(struct Actor *a)
{
    dat_0c24414c[a->b1e9](a);
}
void func_0c0a44e4(struct Actor *a)
{
    dat_0c244180[a->b6](a);
}
