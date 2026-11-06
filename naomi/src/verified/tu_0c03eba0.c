#include "objects.h"
extern void func_0c04bfe0(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c03ec46(struct Actor *);
void func_0c03eba0(struct Actor *a)
{
 a->b6++; a->b23a++; func_0c04bfe0(a);
 a->b12c=1; a->i72=0;
 *(struct LinkedActorVec3 *)&a->f80=*(struct LinkedActorVec3 *)((char *)a+0x284);
 a->f264=1.0f; func_0c02a0c4(a,13,29);
 a->f96=-8.5714283f; a->f108=-0.80357140303f;
 a->f92=0.0f; a->f104=0.0f; a->s28=20;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&a->p1c8->f52;
 a->f56+=822.85712f;
 if(a->p1c8->b1d2) a->f52+=213.33333f;
 else a->f52-=213.33333f;
 func_0c03ec46(a);
}
void func_0c03ec46(struct Actor *a)
{
 if(--a->s28<0) a->b6++;
}
