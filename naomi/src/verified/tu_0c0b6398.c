#include "objects.h"
/* func_0c0b6398: no twin (38 bytes) */
extern void func_0c045248(struct Actor*,int);
extern void (*table_0c244f60[])(struct Actor *);
void func_0c0b6398(struct Actor *a);
void func_0c0b63be(struct Actor *a);
void func_0c0b63e4(struct Actor *a);
void func_0c0b642a(struct Actor *a);
void func_0c0b6470(struct Actor *a);

void func_0c0b6398(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=zero;break;case 2:a->b1e9=zero;break;}
 func_0c045248(a,29);
}


/* func_0c0b63be: no twin (38 bytes) */
void func_0c0b63be(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=zero;break;case 2:a->b1e9=zero;break;}
 func_0c045248(a,29);
}


/* func_0c0b63e4: no twin (70 bytes) */
void func_0c0b63e4(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=4;goto clr;case 1:goto c1;c1:a->b1e9=3;a->b1a3=1;break;case 2:a->b1e9=6;clr:a->b1a3=zero;break;}
 func_0c045248(a,21);
}


void func_0c0b642a(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=4;a->b1a3=zero;break;case 1:a->b1e9=3;goto light;case 2:goto heavy;heavy:a->b1e9=5;light:a->b1a3=1;break;}
 func_0c045248(a,21);
}

void func_0c0b6470(struct Actor *a)
{
    table_0c244f60[a->b1f7&63](a);
}
