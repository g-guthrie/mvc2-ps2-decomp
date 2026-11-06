/* Actor state handlers and the mode-selection reset sharing one literal pool. */
#include "objects.h"
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c025900(struct Actor *,char,char);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c045248(struct Actor *,char);
extern void (*table_0c2442c0[])(struct Actor *);
void func_0c0a6f1c(struct Actor *a)
{
    struct LinkedActorVec3 v;
    struct Actor *other;
    if (a->b141==1) {
        v.x=-106.666664124f;
        v.y=102.85714f;
        func_0c1cea66(a,&v,2);
        func_0c0346da(a,2);
        a->b141=0;
        other=a->p1c8;
        other->p1b4=a;
        other->b1d2=a->b1d2;
        other->b1a1=33;
        other->b1f6=1;
        func_0c025900(a,0,0);
    }
    if (func_0c02a026(a)<0) func_0c0438de(a);
}
void func_0c0a6f90(struct Actor *a)
{
    table_0c2442c0[a->b1f7 & 63](a);
}
void func_0c0a6fa8(struct Actor *a)
{
    func_0c03edcc(a->p1c8,a);
}
void func_0c0a6fb6(void)
{
}
void func_0c0a6fba(struct Actor *a)
{
    int zero=0;
    a->b5=zero;
    a->b7=zero;
    a->b6=zero;
    switch(a->b4c9) {
    case 0: a->b1e9=5; break;
    case 1: a->b1e9=4; break;
    case 2: a->b1e9=12; break;
    }
    func_0c045248(a,29);
}
void func_0c0a6ff6(struct Actor *a)
{
    int zero=0;
    a->b5=zero;
    a->b7=zero;
    a->b6=zero;
    switch(a->b4c9) {
    case 0: a->b1e9=5; break;
    case 1: a->b1e9=4; break;
    case 2: a->b1e9=12; break;
    }
    func_0c045248(a,29);
}
void func_0c0a7064(struct Actor *a)
{
    int zero=0;
    int seven=7;
    a->b5=zero;
    a->b7=zero;
    a->b6=zero;
    switch(a->b4c9) {
    case 0: a->b1e9=2; goto clear;
    case 1: goto one; one: a->b1e9=7;
clear:
        a->b1a3=zero;
        break;
    case 2: a->b1e9=8; a->b1a3=1; break;
    }
    func_0c045248(a,21);
}
void func_0c0a70aa(struct Actor *a)
{
    int zero=0;
    unsigned char two=2;
    a->b5=zero;
    a->b7=zero;
    a->b6=zero;
    switch(a->b4c9) {
    case 0: goto two;
    case 1: a->b1e9=zero; a->b1a3=1; break;
    case 2: two: a->b1e9=two; a->b1a3=zero; break;
    }
    func_0c045248(a,21);
}
