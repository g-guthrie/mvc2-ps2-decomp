/* Shared action state, timer, effect position, and six actor callbacks. */
#include "objects.h"
extern struct ActorSub2a4 *dat_0c2fb2f0;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0451f2(struct Actor *);
extern void func_0c02a684(struct Actor *,int,int,int);
extern void func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern int func_0c17d824(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void (*dat_0c24d0b0[])(struct Actor *);
void func_0c11d9b0(struct Actor *);
void func_0c11d820(struct Actor *a)
{
    int zero;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1a1 = zero;
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->s28 = 112;
    dat_0c2fb2f0->b0 = zero;
    a->f96 = 3.21428561211f;
    func_0c0451f2(a);
    if (a->b37 & 1) {
        func_0c02a684(a,1,32,1);
        func_0c02a684(a,2,33,1);
    } else {
        func_0c02a684(a,1,35,1);
        func_0c02a684(a,2,36,1);
    }
    func_0c0432ca(a);
    func_0c02a0c4(a,22,4);
}
void func_0c11d8de(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    a->b328 = 5;
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        if (!func_0c17d824(a)) {
            func_0c0437b8(a);
        } else {
            position.x = -11.666666031f;
            position.y = 197.142853f;
            position.z = 0.0f;
            func_0c0429a4(a,&position,1);
        }
    } else {
        func_0c02a026(a);
    }
}
void func_0c11d99c(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b328 = 5;
    a->b6++;
    func_0c11d9b0(a);
}
void func_0c11d9b0(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        int zero = 0;
        a->b3f9 = zero;
        a->b3f8 = zero;
        a->b327 = zero;
        a->b328 = zero;
        a->b6++;
        *(unsigned char *)&dat_0c2fb2f0->b0 = 255;
        func_0c02a684(a,2,19,1);
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f108 = -0.46875f;
        func_0c02a0c4(a,1,9);
    }
}
void func_0c11da68(struct Actor *a) { func_0c0438de(a); }
void func_0c11da6e(struct Actor *a) { dat_0c24d0b0[a->b6](a); }
