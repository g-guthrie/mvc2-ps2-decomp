/* Five complete routines match 410 code bytes. The table setup at 52d2
 * still differs in two adjacent instructions; both shared pools match. */
#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2441f8[];
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

struct Vec3_0c0a51f0 { float x,y,z; };
extern float dat_0c243da8[];
extern void func_0c02a684(struct Actor *,int,int,int);
extern void func_0c0429a4(struct Actor *,struct Vec3_0c0a51f0 *,int);
void func_0c0a51f0(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1a1 = 63;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 30);
}

void func_0c0a526e(struct Actor *a)
{
    if (a->b141) {
        a->b6=a->b6+1;
        func_0c14b8d8(a,5,19,5);
        a->b141=0;
    }
    func_0c02a026(a);
}
void func_0c0a529e(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a52c0(struct Actor *a)
{
    table_0c2441f8[a->b6](a);
}
void func_0c0a52d2(struct Actor *a)
{
    float *table;
    struct ActorSub2a4 *sub;
    a->b6=a->b6+1;
    a->b1a1=56;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c02a39a(a,0);
    table=dat_0c243da8;
    func_0c02a0c4(a,22,0);
    a->b35=a->w130 ? 1 : 2;
    table+=a->w130 ? 7 : 14;
    if (a->b1f9!=2) func_0c0432ca(a);
    func_0c02a684(a,4,7,1);
    a->f92=table[0];
    a->f104=table[1];
    a->f96=table[2];
    a->f108=table[3];
    a->s28=30;
    a->s30=0;
    a->b33=0;
    sub=&a->sub2a4;
    *(unsigned char *)&sub->s10=0;
    *(unsigned short *)&sub->s12=0;
}
void func_0c0a53dc(struct Actor *a)
{
    struct Vec3_0c0a51f0 v;
    a->b3f8=2;
    a->b328=5;
    if (func_0c02a026(a)>=0 && a->b141==1) {
        a->b141=0;
        v.x=-26.666666031f;
        v.y=137.142853f;
        func_0c0429a4(a,&v,1);
    }
    if (a->b143<0) {
        a->b6=a->b6+1;
        if (a->b1f9!=2) {
            a->b1f9=2;
            a->f56=a->f41c+21.42857f;
        }
        a->b7=0;
        func_0c02a0c4(a,22,3);
        a->w352=0;
        func_0c14b8d8(a,10,19,10);
        func_0c14b8d8(a,9,19,9);
        func_0c14b8d8(a,11,19,11);
    }
    func_0c02a026(a);
}
