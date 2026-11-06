#include "objects.h"
extern void func_0c03efea(struct Actor *,struct Actor *),func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c045248(struct Actor *,int);
void func_0c0e8244(struct Actor *a)
{
 switch(a->p1c8->b14b){
 case 1:func_0c03efea(a->p1c8,a);return;
 case 2:
  if(!(a->p1c8->f56>a->p1c8->f41c))a->p1c8->f56=a->p1c8->f41c;
  break;
 }
 func_0c03edcc(a->p1c8,a);
}
void func_0c0e8292(struct Actor *a){if(a->p1c8->b14b)func_0c03efea(a->p1c8,a);else func_0c03edcc(a->p1c8,a);}
void func_0c0e82ba(struct Actor *a)
{
 switch(a->p1c8->b14b){
 case 1:func_0c03efea(a->p1c8,a);return;
 case 2:
  if(!(a->p1c8->f56>a->p1c8->f41c))a->p1c8->f56=a->p1c8->f41c;
  break;
 }
 func_0c03edcc(a->p1c8,a);
}
void func_0c0e8308(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=7;break;case 1:a->b1e9=7;break;case 2:a->b1e9=11;break;}
 func_0c045248(a,29);
}
