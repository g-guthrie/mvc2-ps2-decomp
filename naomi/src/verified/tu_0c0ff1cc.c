#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025762(void),func_0c02a0c4(struct Actor *,int,int),func_0c043352(struct Actor *),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c24ade4[])(struct Actor *);
void func_0c0ff1cc(struct Actor *a)
{
 a->b328=5;a->b1f5=2;a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);
 if(--a->s28==0){a->b7++;a->s28=8;a->f92=-26.666666031f;if(a->b1d2)a->f92=-a->f92;func_0c025762();a->b327=0;a->b328=0;}
}
void func_0c0ff244(struct Actor *a)
{
 a->b1f5=2;a->f52+=a->f92;a->f92+=a->f104;
 if(--a->s28==0){a->b6++;a->b7=0;a->f92=-6.66666651f;a->f104=0.20833333f;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}func_0c02a0c4(a,22,14);}
}
void func_0c0ff2b0(struct Actor *a)
{
 register float zero=0;
 switch(a->b7){
 case 0:
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(a->f92>0)func_0c043352(a);
  func_0c02a026(a);
  if(a->b141){a->b7=2;a->b141=0;a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;}
  break;
 case 1:
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
  if(a->f56<a->f41c){a->b7++;a->b1f9=0;a->f56=a->f41c;a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;func_0c02a0c4(a,1,3);func_0c043324(a);}
  break;
 case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c0ff40e(struct Actor *a){table_0c24ade4[a->b6](a);}
