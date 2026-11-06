/* Spawn checks, dispatchers and two hit-reaction setups for one move family. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern ActorHandler table_0c240e8c[];
extern int (*table_0c240e7c[])(struct Actor *);
extern void func_0c1910d0(struct Actor *, int);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern ActorHandler table_0c23f434[];
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern ActorHandler table_0c244f40[];
extern void func_0c025900(struct Actor*,int,int);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c048ce6(struct Actor*);
extern void ;
extern void (*table_0c244f4c[])(struct Actor *);
void func_0c0549e0(struct Actor *a);
void func_0c054a52(struct Actor *a);
void func_0c054ae2(struct Actor *a);

struct Actor *func_0c0b5f58(struct Actor *a)
{
    struct Actor *result;
    if ((a->b34 = (a->w1fa & 0xc00) >> 10) == 0)
        return 0;
    if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return result;
        }
    }
    return 0;
}

int func_0c0b5fae(void) { return 0; }

struct Actor *func_0c0b5fb2(struct Actor *a)
{
    struct Actor *child;
    if(!(a->b34=(a->w1fa&0x1c00)>>10))return 0;
    if((unsigned char)a->b1fe!=1)return 0;
    if((unsigned char)a->b1a3!=1)return 0;
    if(!(a->f56>137.142853f))return 0;
    if((child=func_0c037d54(a))) {
        a->b1f7=0;
        return child;
    }
    return 0;
}

void func_0c0b6014(struct Actor *a)
{
    table_0c244f40[a->b1f7&63](a);
}

void func_0c0b6044(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (a->w1fa & 0x800) {
        a->w130 ^= 1;
        a->b1d2 ^= 1;
    }
    v.x = -83.33333f;
    v.y = 147.857132f;
    func_0c1d4610(a, &v);
    func_0c025900(a, 5, 5);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, a->b1f9 == 2 ? 3 : 0);
}

void func_0c0b60c8(struct Actor *a)
{
    struct LinkedActorVec3 v;
    v.x = -123.33333f;
    v.y = 162.857132f;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 1);
}

void func_0c0b6104(struct Actor *a)
{
    a->b1ea = 1;
    table_0c244f4c[a->b1f7 & 63](a);
}

void func_0c0b6122(void) {}
