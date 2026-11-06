#include "objects.h"
extern void func_0c045248(struct Actor *,int);
extern void (*table_0c24c930[])(struct Actor *);
void func_0c11638c(struct Actor *a){table_0c24c930[a->b1f7&63](a);}
void func_0c1163a4(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=3;break;case 1:a->b1e9=3;break;case 2:a->b1e9=3;break;}
 func_0c045248(a,29);
}
void func_0c1163c8(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=3;break;case 1:a->b1e9=3;break;case 2:a->b1e9=3;break;}
 func_0c045248(a,29);
}
void func_0c1163ec(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;break;case 1:a->b1e9=zero;goto light;case 2:goto six;six:a->b1e9=6;light:a->b1a3=1;break;}
 func_0c045248(a,21);
}
void func_0c11642e(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;break;case 1:a->b1e9=zero;goto light;case 2:goto six;six:a->b1e9=6;light:a->b1a3=1;break;}
 func_0c045248(a,21);
}
