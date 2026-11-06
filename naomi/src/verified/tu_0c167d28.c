#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c252020[])(struct LinkedActor *);
void func_0c167d28(struct LinkedActor *a)
{
 int one,zero;struct LinkedActorWccBytes *mark=&a->wcc.bytes;
 a->b5++;a->sdc=a->p24->sdc;one=1;a->sdc.b12c=one;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=one;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 mark->b2=2;mark->b3=8;
 zero=0;a->b36=zero;
 a->f52=a->p24->f52;a->f56=a->p24->f56+139.28571f;
 if(A(a)->w130){a->f52-=-123.33333f;a->f92=2.5f;}
 else{a->f52-=123.33333f;a->f92=-2.5f;}
 a->s28=60;A(a)->b1a1=63;
 A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,3);
}
void func_0c167e3c(struct LinkedActor *a)
{
 struct LinkedActorWccBytes *mark;int zero;
 zero=0;a->b36=zero;mark=&a->wcc.bytes;
 if(A(a)->b1a0){A(a)->b1a0--;return;}
 a->f52+=a->f92;a->f92+=a->f104;
 if(A(a)->b19e){
  A(a)->b1a0=4;
  mark->b3--;
  if(mark->b3<=0)goto done;
  goto s;s:A(a)->b1a1=63;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 }
 if(A(a)->b19f){
  A(a)->b19f=zero;
  mark->b2--;
  if(mark->b2<=0)goto done;
 }
 a->s28--;
 if(a->s28<=0)goto done;
 func_0c02a026(a);func_0c037d0c(a);return;
done:
 a->b5++;func_0c02a0c4(a,23,4);
}
void func_0c167f3e(struct LinkedActor *a)
{
 a->b36=0;
 if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;}
}
void func_0c167f66(struct LinkedActor *a){table_0c252020[(unsigned char)a->b5](a);}
