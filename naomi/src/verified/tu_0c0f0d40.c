/* Exact 0x0c0f0d40..0x0c0f0df8: clear action substates and select input variants. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c0f0d40(struct Actor *a)
{
 int variant;
 a->b6=a->b7=a->b5=0;
 variant=6;
 switch(a->b4c9){case 0:a->b1e9=variant;break;case 1:a->b1e9=variant;break;case 2:a->b1e9=5;break;}
 func_0c045248(a,29);
}
void func_0c0f0d70(struct Actor *a)
{
 int zero=0,one=1;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=7;goto strength;case 2:a->b1e9=one;strength:a->b1a3=one;break;}
 func_0c045248(a,21);
}
void func_0c0f0dae(struct Actor *a)
{
 int zero=0,one=1;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=7;goto strength;case 2:a->b1e9=one;strength:a->b1a3=one;break;}
 func_0c045248(a,21);
}
