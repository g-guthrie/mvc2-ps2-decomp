/* Complete unregistered translation of 0x0c05429c..0x0c0548c0. */
#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorHandler table_0c23f41c[];
extern ActorFactory table_0c23f424[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern struct Actor *func_0c037d54(struct Actor *);

void func_0c0547dc(struct Actor *a);

extern ActorHandler table_0c23f400[];
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);

void func_0c05429c(struct Actor *a)
{
    table_0c23f400[a->b6](a);
}

void func_0c0542ae(struct Actor *a)
{
    
    float stopped;
    if(a->b255==6) {
        a->b3f0=255;
        a->b3f1=16;
    }
    a->b6++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    
    a->f56=a->f41c;
    a->b1f9=0;
    a->s28=0;
    stopped=0.0f;
    a->b1a1=89;
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    a->f92=stopped;
    a->f96=stopped;
    a->f104=stopped;
    a->f108=stopped;
    func_0c02a0c4(a,22,9);
    func_0c0547dc(a);
}

void func_0c054338(struct Actor *a)
{
    struct LinkedActorVec3 offset;
    a->b3f8=2;
    a->b328=5;
    a->b3f1=a->b255==6?2:0;
    func_0c02a026(a);
    func_0c0547dc(a);
    if(a->b141) {
        a->b6++;
        a->b141=0;
        a->b3f0=0;
        a->b3f1=0;
        offset.x=-25.0f;
        offset.y=98.57143f;
        offset.z=0.0f;
        func_0c0429a4(a,&offset,3);
    }
}

extern void func_0c0451f2(struct Actor *);
extern void func_0c043324(struct Actor *);

void func_0c0543e4(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    if(func_0c02a026(a)<0) {
        a->b6=4;
        func_0c0451f2(a);
        a->f92=a->b1d2?3.33333331f:-3.33333331f;
        a->f104=0.0f;
        a->f96=34.2857132f;
        a->f108=-1.07142854f;
        a->s30=1;
        func_0c02a0c4(a,22,13);
    } else {
        /* The retail test of b141 is discarded before testing b19e. */
        if(a->b141) {}
        if(a->b19e && !(a->b19e&1) && !a->p1b0->b202) {
            a->b6++;
            a->s30=0;
            func_0c02a0c4(a,22,10);
        }
    }
    func_0c0547dc(a);
}

void func_0c054486(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    func_0c02a026(a);
    if(a->b141) {
        a->b6++;
        a->b141=0;
        func_0c0451f2(a);
        a->f52+=a->b1d2?40.0f:-40.0f;
        a->f92=a->b1d2?1.66666663f:-1.66666663f;
        a->f104=0.0f;
        a->f96=42.85714f;
        a->f108=-1.07142854f;
    }
    /* Retail evaluates this event byte without branching on its result. */
    if(a->b140) {}
    func_0c0547dc(a);
}

void func_0c054546(struct Actor *a)
{
    a->b3f8=2;
    a->b328=5;
    func_0c02a026(a);
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    if(a->f96<0.0f) {
        a->b6++;
        a->f92=0.0f;
        a->f104=0.0f;
        a->b3f9=0;
        a->b3f8=0;
        a->b327=0;
        a->b328=0;
        func_0c02a0c4(a,22,a->s30==0?11:14);
    }
    func_0c0547dc(a);
}

void func_0c0545da(struct Actor *a)
{
    func_0c02a026(a);
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    if(!(a->f56>a->f41c)) {
        a->b6++;
        a->f56=a->f41c;
        a->b1f9=0;
        func_0c02a0c4(a,22,a->s30==0?12:15);
        func_0c043324(a);
    }
    func_0c0547dc(a);
}

void func_0c054684(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
    else
        func_0c0547dc(a);
}

void func_0c0546a6(struct Actor *a)
{
    table_0c23f41c[a->b6](a);
}

void func_0c0546b8(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 94;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 23);
}

void func_0c05472e(struct Actor *a)
{
    struct LinkedActorVec3 v;
    float t;

    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 < 0) {
        a->b141 = 0;
        v.x = 25.0f;
        v.y = 165.0f;
        func_0c043014(a, &v);
    }
    if (a->b140) {
        t = a->b1d2 ? 3.3333333f : -3.3333333f;
        a->f52 += t;
    }
}

void func_0c0547dc(struct Actor *a)
{
    if (a->b14b) {
        a->b1a1 = a->b14b;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
}

#pragma noregsave(func_0c054812)
struct Actor *func_0c054812(struct Actor *a)
{
    return table_0c23f424[a->b1f9](a);
}

struct Actor *func_0c05482a(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return r;
        }
    }
    return 0;
}

struct Actor *func_0c0548a2(struct Actor *a)
{
    return 0;
}
