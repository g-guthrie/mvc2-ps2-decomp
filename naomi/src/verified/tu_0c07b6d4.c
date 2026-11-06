/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23fc3c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c07b6d4(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        a->b1a1 = 66;
        a->b1f9 = 1;
        func_0c02a0c4(a, 20, 9);
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c0346da(a, 22);
        func_0c048bb0(a, 5);
    }
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

extern void (*table_0c2416c8[])(struct Actor *),(*table_0c2416d4[])(struct Actor *),(*table_0c2416e4[])(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c192148(struct Actor *);
void func_0c07b83c(struct Actor *),func_0c07b8c0(struct Actor *),func_0c07b9ac(struct Actor *),func_0c07ba42(struct Actor *);
void func_0c07b79c(struct Actor *a){table_0c2416c8[a->b6](a);}
void func_0c07b7ae(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->f92=a->b1d2?16.666666031f:-16.666666031f;a->s28=16;func_0c07b83c(a);}
}
void func_0c07b83c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(--a->s28<0){a->b6++;a->f92=a->b1d2?6.66666651f:-6.66666651f;func_0c02a0c4(a,2,2);func_0c07b8c0(a);}
}
void func_0c07b8c0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c07b91a(struct Actor *a){table_0c2416d4[a->b6](a);}
void func_0c07b92c(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b6++;a->f92=a->b1d2?-13.33333302f:13.33333302f;
 a->f104=0;a->f96=6.428571224213f;a->f108=-0.5357143f;func_0c07b9ac(a);}
}
void func_0c07b9ac(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;func_0c043324(a);
 a->f92=a->b1d2?-6.66666651f:6.66666651f;a->f104=0;a->f96=0;a->f108=0;func_0c07ba42(a);}
}
void func_0c07ba42(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);if(a->b141==6){a->b6++;a->b141=0;}
}
void func_0c07baa0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c07bac2(struct Actor *a){table_0c2416e4[a->b6](a);}
void func_0c07bad4(struct Actor *a){a->b6++;a->b12c=1;a->w130=0;func_0c02a0c4(a,18,0);func_0c192148(a);}
