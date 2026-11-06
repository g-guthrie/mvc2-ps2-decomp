#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c17c724(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *);
void func_0c17c38c(struct Actor *a)
{
 char *sub=(char *)a+0x88;
 int zero=0;
 if(a->b19e){a->b4=2;a->b5=zero;}
 if(a->b19f){a->b4=2;a->b5=zero;}
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 if(func_0c02a026(a)<0){
  if(--a->s28==0){
   func_0c17c724(a);
   a->s28=1;
   if(--sub[34]==0){
    a->b4++;a->b5=zero;
    func_0c02a0c4(a,21,25);
   }
  }
 }
 func_0c037d0c(a);
}
