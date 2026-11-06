#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c02a39a(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c0439c4(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern int (*table_0c24d0e8[])(struct Actor *);

void func_0c11e10c(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 63;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c11e186(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a)){
  a->b6++;
  func_0c043324(a);
  func_0c02a0c4(a,20,1);
 }
}
void func_0c11e1f4(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c02a39a(a,0);func_0c0439c4(a);}
 else if(a->b141)a->b141=0;
}
int func_0c11e228(struct Actor *a){return table_0c24d0e8[a->b1f9](a);}
