#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
void func_0c08aadc(struct Actor *a)
{
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->f56<a->f41c){
 a->f56=a->f41c;
 a->b1f9=0;
 a->f92=0;
 a->f96=0;
 a->f104=0;
 a->f108=0;
 func_0c044f1c(a);
 }
}
struct Actor *func_0c08ab6c(struct Actor *a)
{
 struct Actor *target;
 if(!(a->w1fa&0xc00)||!a->b1a3||a->b1f9==1)goto rejected;
 if(a->b1fe){
 if(a->b1f9==2){rejected:return 0;}
 if((target=func_0c037d54(a)))a->b1f7=0;
 }else if(a->b1f9!=2){
 if((target=func_0c037d54(a)))a->b1f7=1;
 }else{
 if((target=func_0c037d54(a)))a->b1f7=2;
 }
 return target;
}
