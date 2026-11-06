#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c244230[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c14b8d8(struct Actor *, int, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);

struct Vec3_0c0a5c08 { float x,y,z; };
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c0429a4(struct Actor *,struct Vec3_0c0a5c08 *,int);
void func_0c0a5c08(struct Actor *a)
{
    unsigned char *sub;
    a->b6=a->b6+1;
    a->b1a1=65;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a39a(a,0);
    a->f92=0;
    a->f96=0;
    a->f104=0;
    a->f108=0;
    func_0c0442fa(a);
    a->b35=0;
    a->s30=0;
    sub=(unsigned char *)&a->sub2a4;
    sub[14]=1;
    if (a->b1f9!=2) {
        a->b1f9=0;
        a->f56=a->f41c;
        func_0c0432ca(a);
    }
    func_0c025900(a,1,13);
    func_0c02a0c4(a,22,14);
}
void func_0c0a5ca4(struct Actor *a)
{
    struct Vec3_0c0a5c08 v;
    unsigned char *sub;
    a->b3f8=2;
    a->b328=5;
    if (a->b141==1) {
        a->b141=0;
        v.x=-40.0f;
        v.y=137.142853f;
        func_0c0429a4(a,&v,1);
    }
    if (a->b141==2) {
        a->b6=a->b6+1;
        a->b141=0;
        func_0c14b8d8(a,16,19,16);
        sub=(unsigned char *)&a->sub2a4;
        sub[14]=1;
    }
    func_0c02a026(a);
}
void func_0c0a5d14(struct Actor *a)
{
    unsigned char *sub;
    a->b3f8=2;
    a->b328=5;
    sub=(unsigned char *)&a->sub2a4;
    if (!sub[14]) {
        if (a->b1f9!=2) {
            a->b6=4;
        } else {
            a->b6=a->b6+1;
            a->f92=0;
            a->f96=0;
            a->f104=0;
            a->f108=0;
            a->f108=-0.80357140303f;
            func_0c02a0c4(a,22,15);
            return;
        }
    }
    if (!a->b141) func_0c02a026(a);
}
void func_0c0a5dae(struct Actor *a)
{
    a->b3f9=0;
    a->b3f8=0;
    a->b327=0;
    a->b328=0;
    if (a->f56<a->f41c) {
        a->b6=a->b6+1;
        a->b1f9=0;
        a->f92=0;
        a->f96=0;
        a->f104=0;
        a->f108=0;
        a->f56=a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a,22,16);
    }
    func_0c02a026(a);
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
}
void func_0c0a5e4a(struct Actor *a)
{
    a->b3f9=0;
    a->b3f8=0;
    a->b327=0;
    a->b328=0;
    if (a->b143<0) {
        func_0c025900(a,0,13);
        func_0c0437b8(a);
        return;
    }
    func_0c02a026(a);
}
void func_0c0a5e88(struct Actor *a)
{
    table_0c244230[a->b6](a);
}
