/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24123c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern ActorHandler table_0c241220[],table_0c24122c[];
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c1c1678(struct Actor *,unsigned short *,int);
extern void func_0c191980(struct Actor *,int);
extern ActorHandler table_0c24ddf4[], table_0c24de00[];

void func_0c12cdd4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0437b8(a);
    }
}

void func_0c12cdfc(struct Actor *a) { table_0c24ddf4[a->b6](a); }

void func_0c12ce0e(struct Actor *a)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;a->b1f9=0;a->f56=a->f41c;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=96;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,22,14);
}

void func_0c12ce8e(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b141&1){a->b3f0=0;a->b3f1=0;a->b141^=1;
 position.x=10.0f;position.y=145.71428f;func_0c0429a4(a,&position,1);}
 if(a->b141&2){a->b6++;a->b141^=1;a->b200=1;a->w3ea=480;func_0c1c1678(a,&a->w3ea,2);}
}

void func_0c12cf56(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)>=0){if(a->b141&2)func_0c191980(a,7);}
 else{a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;func_0c0437b8(a);}
}

void func_0c12cfaa(struct Actor *a) { table_0c24de00[a->b6](a); }

void func_0c12cfbc(struct Actor *a)
{
 a->b6++;a->b1f9=1;a->f56=a->f41c;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=99;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,21,44);
}
