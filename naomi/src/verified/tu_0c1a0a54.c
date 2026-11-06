#include "objects.h"
extern void (*table_0c258d58[])(struct LinkedActor *);
extern void (*table_0c258d98[])(struct LinkedActor *);
extern void (*table_0c258d9c[])(struct LinkedActor *);
extern void (*table_0c258da0[])(struct LinkedActor *);
extern void func_0c029fc4(struct LinkedActor *);
void func_0c1a0a54(struct LinkedActor *a)
{
 table_0c258d58[a->b32](a);
}
void func_0c1a0a68(struct LinkedActor *a)
{
 struct Actor *parent=(struct Actor *)a->p24;
 table_0c258d98[(unsigned char)a->b5](a);
 if(parent->b19f) { a->b4++; a->sdc.b12c=0; }
}
void func_0c1a0aa0(struct LinkedActor *a)
{
 func_0c029fc4(a);
 if(a->p24->b6!=3) { a->b4++; a->sdc.b12c=0; return; }
 a->f52=a->p24->f52; a->f56=a->p24->f56;
}
void func_0c1a0adc(struct LinkedActor *a)
{
 struct Actor *parent=(struct Actor *)a->p24;
 table_0c258d9c[(unsigned char)a->b5](a);
 if(parent->b19f) { a->b4++; a->sdc.b12c=0; }
}
void func_0c1a0b14(struct LinkedActor *a)
{
 func_0c029fc4(a);
 if(a->p24->b6!=3) { a->b4++; a->sdc.b12c=0; return; }
 a->f52=a->p24->f52; a->f56=a->p24->f56;
}
void func_0c1a0b50(struct LinkedActor *a)
{
 struct Actor *parent=(struct Actor *)a->p24;
 table_0c258da0[(unsigned char)a->b5](a);
 if(parent->b1d0!=29 || parent->b1e9!=9) { a->b4++; a->sdc.b12c=0; }
}
