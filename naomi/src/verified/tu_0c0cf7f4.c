#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24826c[])(struct Actor *),(*table_0c248278[])(struct Actor *);
void func_0c0cf7f4(struct Actor *a){if(!a->b6){int zero;func_0c044cbc(a);a->b6++;zero=0;a->b1a1=66;a->b1f9=zero;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);func_0c0346da(a,21);func_0c02a0c4(a,20,4);}
 if(a->b1ff==3)func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0cf8ba(struct Actor *a){struct Actor *p=a;table_0c24826c[p->b6](a);}
void func_0c0cf8cc(struct Actor *a){a->b6++;a->s28=24;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f92=a->b1d2?10.0f:-10.0f;a->f104=a->b1d2?-0.078125f:0.078125f;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
void func_0c0cf98a(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->f92 = a->b1d2 ? 4.16666651f : -4.16666651f;
        a->f104 = a->b1d2 ? -0.2864583135f : 0.2864583135f;
        a->b6++;
        a->s28 = 8;
    }
}
void func_0c0cfa16(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(--a->s28<0)func_0c0437b8(a);}
void func_0c0cfa76(struct Actor *a){struct Actor *p=a;table_0c248278[p->b6](a);}
