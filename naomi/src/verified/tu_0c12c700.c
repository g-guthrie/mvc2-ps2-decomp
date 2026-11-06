/* Grab/throw state handlers and dispatchers for one move family. */
#include "objects.h"
extern void (*table_0c24ddd4[])(struct Actor *), (*table_0c24dde0[])(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c241200[], table_0c24120c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c191980(struct Actor *, int);
extern void func_0c13b79c(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c043324(struct Actor *),func_0c0451f2(struct Actor *),func_0c131554(struct Actor *,int);
extern char dat_0c23f384[];
extern void (*table_0c23f388[])(struct Actor *,struct ActorSub2a4 *);
extern void (*table_0c23f39c[])(struct Actor *),(*table_0c23f3b0[])(struct Actor *);
extern void (*table_0c23f3c0[])(struct Actor *,struct ActorSub2a4 *),(*table_0c23f3cc[])(struct Actor *,struct ActorSub2a4 *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c0531c2(struct Actor *),func_0c0531f4(struct Actor *,struct ActorSub2a4 *),func_0c0534b0(struct Actor *),func_0c05375e(struct Actor *),func_0c0539de(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c1d2a56(struct LinkedActorVec3 *,int);
extern unsigned char func_0c044e52(struct Actor *),func_0c044846(struct Actor *);
extern short dat_0c23b9d0[],dat_0c23ba08[];
extern void (*table_0c24ddd4[])(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c046030(struct Actor *),func_0c0464c4(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044ae4(struct Actor *);
void func_0c03b37a(struct Actor *);
extern void (*table_0c24dde0[])(struct Actor *);

void func_0c12c700(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b6++;
    a->b7 = 0;
    a->s28 = 17;
    a->s30 = 0;
    a->b1a3 = 0;
    a->f92 = -8.33333302f;
    if (a->b1d2)
        a->f92 = -a->f92;
    func_0c191980(a, 5);
    func_0c13b79c(a, 0);
    func_0c0344a0(a, 31);
    func_0c02a0c4(a, 22, 7);
}

void func_0c12c76c(struct Actor *a)
{
    int v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!a->b1fd) {
        if (func_0c02a026(a) >= 0)
            return;
        if (--a->s28 == 0)
            goto end;
        a->s30 ^= 1;
        func_0c13b79c(a, a->s30);
        func_0c0344a0(a, 31);
        a->b1a1 = a->s28 + 65;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 22, a->s30 + 7);
        return;
    }
    goto C;
C:
    if (*(signed char *)&a->b1fd != 1 << a->b1d2) {
end:
    a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        a->b7 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        v = 67;
        if (a->b255 == 4 || a->b255 == 5)
            v = 98;
        a->b1a1 = v;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 22, 10);
    }
}





void func_0c12c8ec(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c12c90e(struct Actor *a){table_0c24ddd4[a->b6](a);}

void func_0c12c920(struct Actor *a){table_0c24dde0[a->b7](a);}
