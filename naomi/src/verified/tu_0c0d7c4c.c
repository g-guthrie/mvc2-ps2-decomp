#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c248948[])(struct Actor *),(*table_0c248954[])(struct Actor *);
void func_0c0d7c4c(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        a->b1f9 = 1;
        func_0c02a0c4(a, 20, 8);
        a->b1a1 = 85;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c0346da(a, 22);
        func_0c048bb0(a, 5);
    }
    if ((*(unsigned char *)((char *)a + 0x1ff)) == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0d7d14(struct Actor *a){struct Actor *p=a;table_0c248948[p->b6](a);}
void func_0c0d7d26(struct Actor *a){func_0c02a026(a);if(!a->b141){a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f92=a->b1d2?15.83333302f:-15.83333302f;a->f104=a->b1d2?-0.41666666f:0.41666666f;}}
void func_0c0d7dc2(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(func_0c02a026(a)>=0){func_0c043352(a);return;}a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c02a0c4(a,2,2);}
void func_0c0d7e3c(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}
void func_0c0d7e6e(struct Actor *a){struct Actor *p=a;table_0c248954[p->b6](a);}
void func_0c0d7e80(struct Actor *a){func_0c02a026(a);if(!a->b141){a->b6++;a->f92=a->b1d2?-15.83333302f:15.83333302f;a->f104=a->b1d2?0.625f:-0.625f;a->f96=5.0f;a->f108=-0.8333333135f;}}
