#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1605d8(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c247988[])(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a626(struct Actor *,int,int,int);
extern void func_0c0c9e20(struct Actor *,void *),func_0c0c9ea0(struct Actor *),func_0c1a9cf0(struct Actor *,int),func_0c15ccc8(struct Actor *,int);
extern unsigned char dat_0c246edc[];
extern void (*table_0c247968[])(struct Actor *),(*table_0c247970[])(struct Actor *),(*table_0c24797c[])(struct Actor *);
void func_0c0c7254(struct Actor *),func_0c0c72d2(struct Actor *),func_0c0c741e(struct Actor *),func_0c0c7472(struct Actor *);
void func_0c0c71d4(struct Actor *a)
{
 int zero;
 a->b7++;func_0c0442fa(a);func_0c02a39a(a,1);
 a->f92/=8.0f;a->f104=0.0f;a->f96/=8.0f;a->f108/=64.0f;func_0c048bb0(a,5);
 zero=0;a->b1a1=61;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,2);func_0c0c7254(a);
}
void func_0c0c7254(struct Actor *a)
{
 func_0c0c72d2(a);func_0c02a026(a);
 if(a->b141){a->b7++;a->b141=0;func_0c0c9e20(a,dat_0c246edc);func_0c0c9ea0(a);func_0c1a9cf0(a,5);func_0c15ccc8(a,4);}
}
void func_0c0c729e(struct Actor *a)
{
 func_0c0c72d2(a);func_0c0c9ea0(a);
 if(func_0c02a026(a)<0){a->f96=0.0f;a->f108=0.0f;func_0c0438de(a);}
}
void func_0c0c72d2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f41c<a->f56))a->f56=a->f41c;
}
void func_0c0c7360(struct Actor *a){struct Actor *p=a;table_0c247968[p->b6](a);}
void func_0c0c7372(struct Actor *a){struct Actor *p=a;table_0c247970[p->b7](a);}
void func_0c0c7384(struct Actor *a)
{
 int zero;
 func_0c02a39a(a,0);func_0c02a626(a,6,0,2);
 if(a->b1f9==2){a->b6=1;func_0c0c7472(a);return;}
 a->b7++;func_0c0442fa(a);a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f56=a->f41c;zero=0;a->b1a1=51;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,10);func_0c02a0c4(a,21,3);func_0c0432ca(a);func_0c0c741e(a);
}
void func_0c0c741e(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){a->b7++;a->b141=0;func_0c1605d8(a,(signed char)a->b1a3);}
}
void func_0c0c7450(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0c7472(struct Actor *a){struct Actor *p=a;table_0c24797c[p->b7](a);}
void func_0c0c7538(struct Actor *);
void func_0c0c74c0(struct Actor *a)
{
 int zero;
 a->b7++;func_0c0442fa(a);
 a->f92/=8.0f;a->f104=0.0f;a->f96/=8.0f;a->f108/=64.0f;func_0c048bb0(a,10);
 zero=0;a->b1a1=52;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,5);func_0c0c7538(a);
}
void func_0c0c7538(struct Actor *a)
{
 func_0c0c72d2(a);func_0c02a026(a);
 if(!a->b141){a->b7++;a->b141=0;func_0c1605d8(a,(signed char)a->b1a3+2);}
}
void func_0c0c7570(struct Actor *a)
{
 func_0c0c72d2(a);
 if(func_0c02a026(a)<0){a->f96=0.0f;a->f108=0.0f;func_0c0438de(a);}
}
void func_0c0c759e(struct Actor *a){struct Actor *p=a;table_0c247988[p->b6](a);}
