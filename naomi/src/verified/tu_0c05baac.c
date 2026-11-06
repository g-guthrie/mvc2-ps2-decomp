/* Exact 0x0c05baac..0x0c05bb3c: clear action substates and select strength from the input variant. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c05baac(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:goto variant;variant:a->b1e9=4;a->b1a3=zero;goto setup;case 2:a->b1e9=6;strength:a->b1a3=1;break;}
 setup:
 func_0c045248(a,21);
}
void func_0c05baf0(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=4;goto strength;case 2:goto variant_two;variant_two:a->b1e9=6;strength:a->b1a3=1;break;}
 func_0c045248(a,21);
}
