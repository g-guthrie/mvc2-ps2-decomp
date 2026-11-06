#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c043324(struct Actor *);
extern void func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0eb60a(struct Actor *);
extern void (*table_0c249a90[])(struct Actor *),(*table_0c249a98[])(struct Actor *);
void func_0c0e976a(struct Actor *),func_0c0e9810(struct Actor *),func_0c0e9832(struct Actor *),func_0c0e9854(struct Actor *);
void func_0c0e96ec(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->f92){float stopped;a->b7++;goto clear;
clear:stopped=0.0f;a->f92=stopped;a->f104=stopped;func_0c02a0c4(a,10,a->b1a3+6);}
}
void func_0c0e9728(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0e974a(struct Actor *a)
{
 if(!a->b201){func_0c0421f4(a);func_0c0420f8(a);}
 func_0c0e976a(a);
}
void func_0c0e976a(struct Actor *a)
{
 if(!a->b201)func_0c042018(a);
 func_0c0421b8(a);
 if(a->b1e8==96){a->s28=0;func_0c0e9854(a);return;}
 if(a->b1e8>=97 && a->b1e8<=99){a->s28=1;func_0c0e9854(a);return;}
 if((unsigned char)a->b1fe==1)func_0c0e9832(a);else func_0c0e9810(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c0e9810(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0e9832(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0e9854(struct Actor *a){table_0c249a90[a->s28](a);}
void func_0c0e9864(struct Actor *a){table_0c249a98[a->b6](a);}
void func_0c0e9876(struct Actor *a)
{
 float stopped=0.0f;
 if(a->f56<a->f41c){
  a->f56=a->f41c;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c043324(a);func_0c0437b8(a);return;
 }
 if(a->b201)func_0c0eb60a(a);
 func_0c02a026(a);
 if(a->b141){
  a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  a->f92=11.666666031f;if(!a->b1d2)a->f92=-a->f92;
  a->f104=stopped;a->f96=-6.428571224213f;a->f108=stopped;a->b1fc=0;a->s30=40;
 }
}
