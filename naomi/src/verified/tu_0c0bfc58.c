#include "objects.h"
extern void func_0c045248(struct Actor *,int);

void func_0c0bfc58(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=3;break;case 1:a->b1e9=5;break;case 2:a->b1e9=4;break;}
 func_0c045248(a,29);
}

void func_0c0bfc94(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=3;break;case 1:a->b1e9=5;break;case 2:a->b1e9=4;break;}
 func_0c045248(a,29);
}

void func_0c0bfcd0(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}

void func_0c0bfd0e(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}
