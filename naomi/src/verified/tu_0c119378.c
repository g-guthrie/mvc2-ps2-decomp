#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c119378(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=1;break;case 1:a->b1e9=1;break;case 2:a->b1e9=1;break;}
 func_0c045248(a,29);
}
void func_0c11939c(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=2;a->b1a3=zero;break;case 1:a->b1e9=zero;goto light;case 2:goto heavy;heavy:a->b1e9=9;light:a->b1a3=1;break;}
 func_0c045248(a,21);
}
void func_0c1193e0(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=2;a->b1a3=zero;break;case 1:a->b1e9=zero;goto light;case 2:goto heavy;heavy:a->b1e9=9;light:a->b1a3=1;break;}
 func_0c045248(a,21);
}
