/* Complete state-handler unit, including the pool-skipping epilogue. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c15ba0c(struct Actor *,int,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *),func_0c043324(struct Actor *),func_0c0439c4(struct Actor *);
extern int func_0c02a39a(struct Actor *,int);
extern unsigned char func_0c044e52(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c245d28[])(struct Actor *);
extern int (*table_0c245d34[])(struct Actor *);
void func_0c0bf5c8(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;position.x=58.3333321f;position.y=154.28571f;position.z=0;func_0c043014(a,&position);}
}
void func_0c0bf60c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;a->s28=22;func_0c15ba0c(a,6,0);}
}
void func_0c0bf642(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){a->b6++;func_0c02a0c4(a,21,28);}
}
void func_0c0bf672(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0bf694(struct Actor *a)
{
 if(!a->b6){a->b6++;a->b1a1=86;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,20,7);}
 else if(func_0c02a026(a)<0){func_0c02a39a(a,0);func_0c0437b8(a);}
}
void func_0c0bf736(struct Actor *a){table_0c245d28[a->b6](a);}

void func_0c0bf748(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 80;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 5);
}

void func_0c0bf7c2(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 6);
    }
}

void func_0c0bf830(struct Actor*a){if(func_0c02a026(a)<0)func_0c0439c4(a);else if(a->b141)a->b141=0;}

int func_0c0bf85c(struct Actor *a)
{
    return table_0c245d34[a->b1f9](a);
}
