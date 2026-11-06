/* Exact 0x0c0fa2f4..0x0c0fa384: reset action substates and select variant strength. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c0fa2f4(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;goto setup;case 1:a->b1e9=3;goto strength;case 2:goto variant;variant:a->b1e9=7;strength:a->b1a3=1;break;}
 setup:
 func_0c045248(a,21);
}
void func_0c0fa338(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=3;goto strength;case 2:goto variant_two;variant_two:a->b1e9=7;strength:a->b1a3=1;break;}
 func_0c045248(a,21);
}
