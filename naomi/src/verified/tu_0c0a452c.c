#include "objects.h"
struct MoveCounters_0c0a452c { unsigned char pad[124]; short counts[2]; };
extern struct MoveCounters_0c0a452c *dat_0c2f83f8;
extern float dat_0c243be8[];
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a684(struct Actor *,int,int,int);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c14b8d8(struct Actor *,int,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c0a452c(struct Actor *a)
{
    float *table;
    struct ActorSub2a4 *sub;
    a->b6=a->b6+1;
    func_0c048bb0(a,5);
    func_0c0442fa(a);
    func_0c02a39a(a,0);
    table=dat_0c243be8;
    func_0c02a0c4(a,21,0);
    if (a->b1a3 && a->b1f9 != 2) {
        a->b35=a->w130 ? 9 : 10;
        table+=a->w130 ? 63 : 70;
    } else {
        a->b35=a->w130 ? 1 : 2;
        table+=a->w130 ? 7 : 14;
    }
    if (a->b1f9 != 2) func_0c0432ca(a);
    a->f92=table[0];
    a->f104=table[1];
    a->f96=table[2];
    a->f108=table[3];
    a->s28=30;
    a->s30=0;
    sub=&a->sub2a4;
    sub->b6=0;
    sub->w8=0;
    if (a->b255==3) {
        a->b1a1=72;
        a->w1ac=0;
        a->b19e=0;
        a->p1c4=0;
        dat_0c2f83f8->counts[a->b2]++;
        sub->b6=3;
        a->s30=3;
    } else {
        a->b1a1=51;
        a->w1ac=0;
        a->b19e=0;
        a->p1c4=0;
        dat_0c2f83f8->counts[a->b2]++;
    }
}
void func_0c0a468a(struct Actor *a)
{
    a->b1d4=1;
    if (a->b143<0) {
        a->b6=a->b6+1;
        func_0c02a684(a,0,1,1);
        func_0c02a0c4(a,21,3);
        a->b7=0;
        if (a->b1f9!=2) {
            func_0c0451f2(a);
            a->f56=a->f41c+21.42857f;
            if (a->b1a3) {
                func_0c02a0c4(a,21,6);
                a->b7=3;
                a->f52 += a->w130 ? 133.33333 : -133.33333;
            }
        }
        a->w352=0;
        func_0c0346da(a,75);
        func_0c14b8d8(a,10,19,10);
        func_0c14b8d8(a,9,19,9);
        func_0c14b8d8(a,11,19,11);
    }
    func_0c02a026(a);
}
