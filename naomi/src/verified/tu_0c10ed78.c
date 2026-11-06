#include "objects.h"
typedef void (*handler_0c10ed78)(struct Actor *);
extern handler_0c10ed78 table_0c24bd9c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
void func_0c10ed78(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1f9 = 2;
    a->f92 = 33.3333321f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = -0.7366071343422f;
    a->b1a1 = 48;
    a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 2);
}
void func_0c10eddc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6 = a->b6 + 1;
        func_0c02a0c4(a, 20, 3);
        func_0c043324(a);
    }
}
void func_0c10ee4a(struct Actor*a){if(func_0c02a026(a)<0)func_0c0439c4(a);else if(a->b141)a->b141=0;}
void func_0c10ee76(struct Actor *a)
{
    if (a->w34e & 0x400) {
        a->f92 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = -0.80357140303f;
        func_0c0438de(a);
    } else
        table_0c24bd9c[a->b6](a);
}
