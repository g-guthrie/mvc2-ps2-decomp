/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern void func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c1d2a56(struct LinkedActorVec3 *,int);
extern unsigned char func_0c044e52(struct Actor *),func_0c044846(struct Actor *);
extern short dat_0c23b9d0[],dat_0c23ba08[];
extern void (*table_0c24d728[])(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c046030(struct Actor *),func_0c0464c4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044ae4(struct Actor *);
void func_0c03b37a(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorHandler table_0c23f41c[];
extern ActorFactory table_0c23f424[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
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

void func_0c124d7e(struct Actor *a,struct ActorSub2a4 *sub);
void func_0c124d18(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->b1a1=1;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,7,1);func_0c0346da(a,21);func_0c124d7e(a,sub);
}
void func_0c124d7e(struct Actor *a,struct ActorSub2a4 *sub)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}

void func_0c124da0(struct Actor *a){table_0c24d728[a->b6](a);}

struct Actor *func_0c124db2(struct Actor *a)
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
