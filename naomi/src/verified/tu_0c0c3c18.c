#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0432ca(struct Actor *),func_0c15dd00(struct Actor *),func_0c15e32c(struct Actor *);
extern void (*table_0c246b58[])(struct Actor *);
extern void (*table_0c246b64[])(struct Actor *);
extern void (*table_0c246b70[])(struct Actor *);
extern void (*table_0c246b7c[])(struct Actor *);
void func_0c0c3c9c(struct Actor *a);
void func_0c0c3e02(struct Actor *a);
void func_0c0c3e52(struct Actor *a);
void func_0c0c3f18(struct Actor *a);
void func_0c0c3f6a(struct Actor *a);

void func_0c0c3c18(struct Actor *a)
{
 int zero;
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 zero=0;
 a->f56=a->f41c;
 a->b1fc=zero;a->b1f9=zero;
 func_0c048bb0(a,5);
 a->b1a1=58;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,10);
 func_0c0432ca(a);
 func_0c0c3c9c(a);
}

void func_0c0c3c9c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b7++;a->b141=0;func_0c15dd00(a);}
}

void func_0c0c3cca(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0c3cec(struct Actor *a){table_0c246b58[a->b6](a);}

void func_0c0c3cfe(struct Actor *a){table_0c246b64[a->b7](a);}

void func_0c0c3d10(struct Actor *a)
{
 int zero;
 struct ActorSubMoveBytes *m=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(m->b8){
  m->b7=-1;
  if(a->b1f9==2){a->b6=2;func_0c0c3f6a(a);}
  else{a->b6=1;func_0c0c3e52(a);}
  return;
 }
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 zero=0;
 a->f56=a->f41c;
 a->b1fc=zero;a->b1f9=zero;
 func_0c048bb0(a,5);
 a->b1a1=58;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,11);
 func_0c0432ca(a);
 func_0c0c3e02(a);
}

void func_0c0c3e02(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b7++;a->b141=0;func_0c15e32c(a);}
}

void func_0c0c3e30(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0c3e52(struct Actor *a){table_0c246b70[a->b7](a);}

void func_0c0c3e94(struct Actor *a)
{
 int zero;
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 zero=0;
 a->f56=a->f41c;
 a->b1fc=zero;a->b1f9=zero;
 func_0c048bb0(a,5);
 a->b1a1=72;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,13);
 func_0c0432ca(a);
 func_0c0c3f18(a);
}

void func_0c0c3f18(struct Actor *a)
{
 struct ActorSubMoveBytes *m=(struct ActorSubMoveBytes *)&a->sub2a4;
 goto call; call:
 func_0c02a026(a);
 if(a->b141){a->b7++;m->b9=1;}
}

void func_0c0c3f48(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0c3f6a(struct Actor *a){table_0c246b7c[a->b7](a);}
