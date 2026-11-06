#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c025900(struct Actor *,char,char),func_0c02a0c4(struct Actor *,int,int),func_0c02a18c(struct Actor *,int,int,int);
extern void (*table_0c24add4[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0fee24(struct Actor *a){table_0c24add4[a->b7](a,&a->sub2a4);}
void func_0c0fee3a(register struct Actor *a,struct ActorSub2a4 *state)
{
 int two=2,zero,mode;register float fzero;
 a->b3f8=two;a->b328=5;a->b1f5=two;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);fzero=0;zero=0;
 if(a->b141){a->b141=zero;a->b1f9=two;a->f92=-10;if(a->b1d2)a->f92=-a->f92;a->f104=fzero;a->f96=21.42857f;a->f108=-1.33928561211f;}
 if(a->b19e){
  if(!func_0c0447bc(a)){
   a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;a->b7=1;
   a->f92=3.3333333f;if(a->b1d2)a->f92=-a->f92;a->f104=fzero;a->f96=6.428571224213f;a->f108=-0.80357140303f;a->b1f9=two;func_0c02a18c(a,1,2,13);return;
  }else{
   struct Actor *other;float offset;
   a->b7++;a->f92=fzero;a->f96=fzero;a->f104=fzero;a->f108=fzero;func_0c0442fa(a);
   other=a->p1b0;a->b1f9=other->b1f9=zero;a->f56=other->f56=a->f41c;other->f52=a->f52;
   offset=-80;a->f92=-0.20833333f;if(a->b1d2){offset=80;a->f92=-a->f92;}other->f52+=offset;
   *(struct Actor **)&state->w8=other;mode=a->b2?3:4;func_0c025900(a,mode,mode);func_0c02a0c4(a,22,13);return;
  }
 }else if(a->f41c>a->f56+34.2857132f){
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;a->b7=two;a->b1f9=zero;a->f56=a->f41c;a->f92=fzero;a->f96=fzero;a->f104=fzero;a->f108=fzero;func_0c02a0c4(a,22,15);
 }
}
