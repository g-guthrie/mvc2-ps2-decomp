/* Connected movement/partner-action family, 0c0e7aa8..0c0e80d8. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c0442fa(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c03489c(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*dat_0c249758[])(struct Actor *),(*dat_0c24976c[])(struct Actor *),(*dat_0c24977c[])(struct Actor *),(*dat_0c249790[])(struct Actor *);
void func_0c0e7aba(struct Actor *);
void func_0c0e7b1e(struct Actor *);
void func_0c0e7c48(struct Actor *);
void func_0c0e7ca4(struct Actor *);
void func_0c0e7aa8(struct Actor *a){dat_0c249758[a->b6](a);}
void func_0c0e7aba(struct Actor *a)
{
 if(!a->b7){a->b7++;}
 else{
  func_0c02a026(a);
  if(a->b141){a->b6++;func_0c025900(a,5,5);
   a->f92=a->b1d2 ? -3.3333333f : 3.3333333f;
   a->f104=0;a->f96=17.142857f;a->f108=-1.60714281f;
  }
 }
}
void func_0c0e7b1e(struct Actor *a)
{
 if(a->b141)func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f96>0)return;
 if(a->f56>a->f41c)return;
 {
  float stopped=0;a->b6++;a->f56=a->f41c;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c025900(a,0,0);
 }
}
void func_0c0e7bd4(struct Actor *a)
{
 struct Actor *partner;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;partner=a->p1c8;partner->p1b4=a;partner->b1f6=3;partner->b1a1=32;
  a->f92=a->b1d2 ? 3.3333333f : -3.3333333f;
  a->f104=0;a->f96=8.5714283f;a->f108=-0.80357140303f;
  func_0c0442fa(a);dat_0c2d9260.b5=2;dat_0c2d9260.b6=1;
 }
}
void func_0c0e7c48(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;}
}
void func_0c0e7ca4(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0e7cc6(struct Actor *a){dat_0c24976c[a->b6](a);}
void func_0c0e7d04(struct Actor *a)
{
 if(!a->b141)func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->f56=a->f41c;
  if(a->b141){float stopped=0;a->b6++;a->b141=0;
   a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  }
 }
}
void func_0c0e7d90(struct Actor *a)
{
 struct Actor *partner;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;partner=a->p1c8;partner->p1b4=a;partner->b1f6=3;partner->b1a1=33;
  a->f92=a->b1d2 ? 3.3333333f : -3.3333333f;
  a->f104=0;a->f96=8.5714283f;a->f108=-0.80357140303f;
  func_0c0442fa(a);dat_0c2d9260.b5=2;dat_0c2d9260.b6=1;
 }
}
void func_0c0e7e04(struct Actor *a){func_0c0e7c48(a);}
void func_0c0e7e08(struct Actor *a){func_0c0e7ca4(a);}
void func_0c0e7e30(struct Actor *a)
{
 struct Actor *partner;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->f56=a->f41c;a->b1f9=0;}
 if(a->b6 || func_0c02a026(a)<0){
  if(a->b1f9==2)func_0c0438de(a);else func_0c0437b8(a);
  return;
 }
 if(a->b141){a->b6++;a->b141=0;partner=a->p1c8;partner->p1b4=a;partner->b1f6=1;partner->b1a1=34;}
}
void func_0c0e7ee6(struct Actor *a){dat_0c24977c[a->b6](a);}
void func_0c0e7ef8(struct Actor *a){func_0c0e7aba(a);}
void func_0c0e7efc(struct Actor *a){func_0c0e7b1e(a);}
void func_0c0e7f00(struct Actor *a)
{
 struct Actor *partner;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;partner=a->p1c8;partner->p1b4=a;partner->b1f6=3;partner->b1a1=35;
  a->f92=a->b1d2 ? 3.3333333f : -3.3333333f;
  a->f104=0;a->f96=12.85714245f;a->f108=-0.80357140303f;
  func_0c0442fa(a);dat_0c2d9260.b5=2;dat_0c2d9260.b6=1;
 }
}
void func_0c0e7f90(struct Actor *a){func_0c0e7c48(a);}
void func_0c0e7f94(struct Actor *a){func_0c0e7ca4(a);}
void func_0c0e7f98(struct Actor *a){dat_0c249790[a->b6](a);}
void func_0c0e7faa(struct Actor *a)
{
 if(!a->b141)func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){
  int zero=0;float stopped=0;
  a->f56=a->f41c;a->b1f9=zero;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  if(a->b141){a->b6++;a->b141=zero;func_0c03489c(a);}
 }
}
void func_0c0e8044(struct Actor *a)
{
 struct Actor *partner;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;partner=a->p1c8;partner->p1b4=a;partner->b1f6=2;partner->b1a1=36;
  a->f92=a->b1d2 ? -6.66666651f : 6.66666651f;
  a->f96=8.5714283f;a->f108=-0.80357140303f;
 }
}
