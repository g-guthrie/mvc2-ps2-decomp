#include "objects.h"
struct MoveCounters_0c0a4788 { unsigned char pad[124]; short counts[2]; };
extern struct MoveCounters_0c0a4788 *dat_0c2f83f8;
extern float dat_0c2d9300, dat_0c243be8[];
extern void func_0c02a39a(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c14b8d8(struct Actor *,int,int,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c19fadc(struct Actor *,int);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void (*dat_0c244198[])(struct Actor *);
extern void (*dat_0c2441a4[])(struct Actor *);
void func_0c0a4ab2(struct Actor *);
void func_0c0a4788(struct Actor *a)
{
    struct ActorSub2a4 *sub;
    void (*animate)(struct Actor *,int,int);
    float ceiling=dat_0c2d9300-102.85714f;
    if (a->f56>ceiling) a->f56=ceiling;
    a->b1f5=2;
    sub=&a->sub2a4;
    if (sub->w8-- > 0) return;
    sub->w8=0;
    if (a->b19e && sub->b6<2) {
        if (sub->b6==1) a->b1a1=53;
        else a->b1a1=52;
        a->w1ac=0;
        a->b19e=0;
        a->p1c4=0;
        dat_0c2f83f8->counts[a->b2]++;
        sub->b6=sub->b6+1;
        sub->w8=4;
    }
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    func_0c02a026(a);
    animate=func_0c02a0c4;
    if (a->f56<a->f41c) {
        a->b6=5;
        func_0c02a39a(a,0);
        a->f92=0;
        a->f96=0;
        a->f104=0;
        a->f108=0;
        a->f56=a->f41c;
        func_0c043324(a);
        animate(a,21,8);
    } else if (--a->s28==0) {
        a->b6=4;
        func_0c02a39a(a,0);
        a->f108=-1.0f;
        animate(a,21,a->f56>a->f41c+66.666664124f ? 2 : 32);
    } else if (a->b141!=1 && ((a->w348 & 0x300) || (a->w352 & 0x300))) {
        func_0c0a4ab2(a);
    }
}
void func_0c0a4932(struct Actor *a)
{
    struct ActorSub2a4 *sub;
    a->b1f5=2;
    if (a->b143<0) {
        a->b6=2;
        a->w352=0;
        sub=&a->sub2a4;
        sub->b6=0;
        sub->w8=0;
        a->b1a1=51;
        a->w1ac=0;
        a->b19e=0;
        a->p1c4=0;
        dat_0c2f83f8->counts[a->b2]++;
        func_0c14b8d8(a,10,19,10);
        func_0c14b8d8(a,9,19,9);
        func_0c14b8d8(a,11,19,11);
        func_0c0346da(a,75);
        func_0c02a0c4(a,21,(char)a->b7+3);
    }
    func_0c02a026(a);
}
void func_0c0a49f4(struct Actor *a)
{
    if (a->f56<a->f41c) {
        a->b6=a->b6+1;
        a->f92=0;
        a->f104=0;
        a->f96=0;
        a->f108=0;
        a->f56=a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a,21,8);
        return;
    }
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    func_0c02a026(a);
}
void func_0c0a4a7c(struct Actor *a)
{
    a->w352=0;
    a->b1f9=0;
    a->i72=0;
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a4ab2(struct Actor *a)
{
    float *table;
    unsigned char index;
    if (a->s30<2) {
        table=dat_0c243be8;
        index=a->w340>>10;
        a->b35=index;
        table+=index*7;
        if (table[4]) {
            a->b6=a->b6+1;
            a->s28=30;
            a->s30=a->s30+1;
            a->f92=table[0];
            a->f104=table[1];
            a->f96=table[2];
            a->f108=table[3];
            a->b7=(int)table[6];
            a->w130=(int)(!(table[5]<0) ? table[5] : (float)(short)a->w130);
            func_0c19fadc(a,0);
            func_0c19fadc(a,1);
            a->i72=0;
            func_0c02a0c4(a,21,1);
        }
    }
}
void func_0c0a4b86(struct Actor *a)
{
    dat_0c244198[a->b6](a);
}
void func_0c0a4b98(struct Actor *a)
{
    a->b6=a->b6+1;
    a->b1a1=62;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c048bb0(a,5);
    a->f92=0;
    a->f96=0;
    a->f104=0;
    a->f108=0;
    a->b1f9=0;
    a->f56=a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a,0);
    func_0c0432ca(a);
    func_0c02a0c4(a,21,9);
}
void func_0c0a4c16(struct Actor *a)
{
    if (a->b141<1) {
        a->b6++;
        a->b141=0;
        func_0c14b8d8(a,0,19,0);
    }
    func_0c02a026(a);
}
void func_0c0a4c48(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a4c6a(struct Actor *a)
{
    dat_0c2441a4[a->b6](a);
}
