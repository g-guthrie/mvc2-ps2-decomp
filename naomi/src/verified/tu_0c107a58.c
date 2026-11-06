#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c171188(struct Actor *,char,char),func_0c1713d8(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24b5d4[])(struct Actor *),(*table_0c24b5e4[])(struct Actor *);
void func_0c107b30(struct Actor *,int),func_0c107cc8(struct Actor *,int);

void func_0c107a58(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c107a7a(struct Actor *a){table_0c24b5d4[a->b6](a);}
void func_0c107a8c(struct Actor *a,int b)
{
 int z=0;
 a->b6++;
 func_0c048bb0(a,5);func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1f9=z;a->f56=a->f41c;
 a->b1a1=60;a->w1ac=z;a->b19e=z;*(unsigned int*)&a->p1c4=z;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+12);
 a->s28=4;a->s30=!a->b1a3?8:12;a->b33=z;
 func_0c107b30(a,b);
}
void func_0c107b30(struct Actor *a,int b)
{
 (void)b;
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,21,14);}
}
void func_0c107b5a(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s30==0){
  func_0c171188(a,0,(*(char*)&a->b33)++);
  a->s30=!a->b1a3?8:12;
  if(--a->s28==0){a->b6++;a->s28=40;}
 }
}
void func_0c107be0(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){a->b6++;func_0c02a0c4(a,21,15);}
}
void func_0c107c10(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c107c32(struct Actor *a){table_0c24b5e4[a->b6](a);}
void func_0c107c44(struct Actor *a, int b)
{
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->b1a1 = 50;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 16);
    func_0c107cc8(a, b);
}

void func_0c107cc8(struct Actor *a, int b)
{
    (void)b;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c1713d8(a, 0, 0);
        func_0c1713d8(a, 0, 1);
    }
}

