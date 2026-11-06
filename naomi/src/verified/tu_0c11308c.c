#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c11308c(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=13;break;case 1:a->b1e9=13;break;case 2:a->b1e9=12;break;}
 func_0c045248(a,29);
}
void func_0c1130bc(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=13;break;case 1:a->b1e9=13;break;case 2:a->b1e9=12;break;}
 func_0c045248(a,29);
}
void func_0c1130ec(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=7;goto normal;case 1:a->b1e9=7;a->b1a3=1;break;case 2:a->b1e9=8;normal:a->b1a3=zero;break;}
 func_0c045248(a,21);
}
void func_0c113130(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=7;goto normal;case 1:a->b1e9=7;a->b1a3=1;break;case 2:a->b1e9=9;normal:a->b1a3=zero;break;}
 func_0c045248(a,21);
}
