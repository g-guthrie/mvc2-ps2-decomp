/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern void *func_0c1fba00(void *,int,unsigned int);
extern void func_0c045248(struct Actor*,int);

void func_0c08625c(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;break;case 1:a->b1e9=one;goto common;case 2:goto two;two:a->b1e9=3;common:((char *)a)[0x1a3]=one;break;}
 func_0c045248(a,21);
}

void func_0c08629e(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;break;case 1:a->b1e9=one;goto common;case 2:goto two;two:a->b1e9=3;common:((char *)a)[0x1a3]=one;break;}
 func_0c045248(a,21);
}

struct Link_0c0862e0 { struct Actor *target; unsigned char pad4[10]; char b14; unsigned char pad15; char b16; };
extern void func_0c02a0c4(struct Actor *, int, int);
int func_0c0862e0(struct Actor *a)
{
    struct Link_0c0862e0 *s = (struct Link_0c0862e0 *)((char *)a + 0x2a4);
    if (a->b1 != 11 || s->b14 || !s->b16)
        return 0;
    goto T; T:
    if (!s->target)
        return 0;
    s = (struct Link_0c0862e0 *)s->target;
    if (a->f56 + 102.85714f > ((struct Actor *)s)->f56)
        func_0c02a0c4(a, 20, 0);
    else
        func_0c02a0c4(a, 20, 1);
    return 1;
}
