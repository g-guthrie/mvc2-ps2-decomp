#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c1b2e10(struct Actor *,int),func_0c03edcc(struct Actor *,struct Actor *),func_0c045248(struct Actor *,int);
void func_0c0f0c14(struct Actor *a)
{
 struct Actor *parent;
 if(((char *)&a->w150)[1]){((char *)&a->w150)[1]=0;a->b1d2=a->w130=a->b1d2^1;}
 if(func_0c02a026(a)>=0){
  if(a->b141){a->b141=0;parent=a->p1c8;parent->p1b4=a;parent->b1f6=1;parent->b1a1=32;return;}
 }else {goto remove;
remove:func_0c0437b8(a);}
}
void func_0c0f0c84(struct Actor *a)
{
 struct Actor *parent;
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141==2){a->b141=0;func_0c1b2e10(a,5);}
 if(a->b141==1){a->b141=0;parent=a->p1c8;parent->p1b4=a;parent->b1f6=1;parent->b1a1=33;}
}
void func_0c0f0cdc(struct Actor *a){func_0c03edcc(a->p1c8,a);}
void func_0c0f0cea(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=6;break;case 1:a->b1e9=6;break;case 2:a->b1e9=5;break;}
 func_0c045248(a,29);
}
