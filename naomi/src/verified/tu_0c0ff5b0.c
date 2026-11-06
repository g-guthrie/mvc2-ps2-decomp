#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24adf4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c0ff5b0(struct Actor *a)
{
    struct LinkedActorVec3 pos;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        goto done;
    }
    if (a->b141 & 1) {
        a->b141 ^= 1;
        pos.x = 26.666666031f;
        pos.y = 188.57143f;
        func_0c043014(a, &pos);
    }
    if (a->b141 & 2) {
        a->b141 ^= 2;
        func_0c0346da(a, 22);
    }
done:
    ;
}
void func_0c0ff616(struct Actor *a) { table_0c24adf4[a->b6](a); }
void func_0c0ff628(struct Actor *a)
{
    int zero=0;float stopped=0;
    a->b6++;a->b1f9=zero;a->f56=a->f41c;a->s28=60;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
    func_0c0442fa(a);func_0c02a0c4(a,20,2);
}
void func_0c0ff66c(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28==0){a->b6++;func_0c02a0c4(a,20,3);}
}
void func_0c0ff69c(struct Actor *a)
{
    if(func_0c02a026(a)<0)func_0c0437b8(a);
}
