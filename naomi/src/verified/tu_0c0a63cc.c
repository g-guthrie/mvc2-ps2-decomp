#include "objects.h"
extern int func_0c02849a(void);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c244268[])(struct Actor *);
void func_0c0a63cc(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    a->b7=func_0c02849a();
    a->b7 &= 1;
    a->s28=120;
    if (a->s30<=2) {
        a->b6=4;
        a->s30=a->s30+1;
        if (a->s30==3) func_0c02a0c4(a,22,12);
        else func_0c02a0c4(a,22,11);
    } else a->b6=a->b6+1;
}
void func_0c0a642e(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->b143<0) {
        a->b6=a->b6+1;
        a->s28=10;
        func_0c02a0c4(a,22,13);
        return;
    }
    func_0c02a026(a);
}
void func_0c0a645a(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->s28-- == 0) a->b6=a->b6+1;
}
void func_0c0a647e(struct Actor *a)
{
    if (a->b141) {
        a->b141=0;
        func_0c0344a0(a,a->b33==4 ? 15 : 12);
    }
    if (a->b143<0) {
        a->b3f9=0;
        a->b3f8=0;
        a->b327=0;
        a->b328=0;
        func_0c025900(a,0,13);
        func_0c0437b8(a);
        return;
    }
    func_0c02a026(a);
}
void func_0c0a64e4(struct Actor *a)
{
    table_0c244268[a->b6](a);
}
