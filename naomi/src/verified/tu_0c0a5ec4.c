#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2441ec[];
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

struct Vec3_0c0a5ec4 { float x,y,z; };
extern void func_0c0429a4(struct Actor *,struct Vec3_0c0a5ec4 *,int);
void func_0c0a5ec4(struct Actor *a)
{
    a->b6=a->b6+1;
    a->b1a1=65;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f92=0;
    a->f96=0;
    a->f104=0;
    a->f108=0;
    a->b1f9=0;
    a->f56=a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a,0);
    if (a->b255==6) {
        a->b3f0=255;
        a->b3f1=16;
    }
    func_0c0432ca(a);
    a->b35=0;
    a->b33=0;
    a->s28=0;
    a->s30=0;
    func_0c02a0c4(a,22,10);
}
void func_0c0a5f62(struct Actor *a)
{
    struct Vec3_0c0a5ec4 v;
    a->b3f8=2;
    a->b328=5;
    if (a->b141==1) {
        a->b141=0;
        v.x=-26.666666031f;
        v.y=274.285706f;
        func_0c0429a4(a,&v,1);
        func_0c14b8d8(a,14,19,14);
        a->s28=180;
    }
    if (a->b143<0) a->b6=a->b6+1;
    func_0c02a026(a);
}
void func_0c0a5fca(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if (a->s28-- == 0) {
        a->b6=a->b6+1;
        a->s28=120;
    }
}
