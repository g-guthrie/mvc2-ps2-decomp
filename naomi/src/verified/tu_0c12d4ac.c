/* 0x0c12d4ac..0x0c12d598: four variant selectors and their pool; matches
 * retail exactly. The last selector uses the goto/volatile case-2 spelling
 * of tu_0c09d758. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
void func_0c12d4ac(struct Actor *a)
{
 int variant=5;
 a->b7=a->b6=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=variant;break;case 1:a->b1e9=variant;break;case 2:a->b1e9=variant;break;}
 func_0c045248(a,29);
}
void func_0c12d4d0(struct Actor *a)
{
 int variant=5;
 a->b7=a->b6=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=variant;break;case 1:a->b1e9=variant;break;case 2:a->b1e9=variant;break;}
 func_0c045248(a,29);
}
void func_0c12d4f4(struct Actor *a)
{
 int one=1;
 a->b7=a->b6=a->b5=0;
 switch(a->b4c9){
 case 0:a->b1e9=10;goto strength;
 case 1:goto variant_one;variant_one:a->b1e9=11;strength:a->b1a3=one;break;
 case 2:a->b1e9=12;a->b1a3=one;a->b34=2;if(!a->b1d2)a->b34=6;break;
 }
 func_0c045248(a,21);
}
void func_0c12d54a(struct Actor *a)
{
 int zero=0;
 a->b5=zero;a->b6=zero;a->b7=zero;
switch(a->b4c9){case 0:a->b1e9=10;goto strength;case 1:a->b1e9=11;goto strength;case 2:goto two;two:((volatile unsigned char *)a)[0x1e9]=12;strength:a->b1a3=1;break;}
 func_0c045248(a,21);
}
