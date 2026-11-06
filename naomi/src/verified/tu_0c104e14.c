#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c045248(struct Actor *,int);
extern void (*table_0c24b328[])(struct Actor *);
void func_0c104e14(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else if(a->b141){a->b141=0;position.x=-23.3333321f;position.y=171.42856f;func_0c043014(a,&position);}
}
void func_0c104e5a(struct Actor *a){a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);}
void func_0c104e6e(struct Actor *a){a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);}
void func_0c104e82(struct Actor *a)
{
 int zero=0,one=1;
 a->b5=zero;a->b6=zero;a->b7=zero;
 switch(a->b4c9){case 0:goto low;case 1:a->b1e9=one;a->b1a3=2;break;case 2:low:a->b1e9=zero;a->b1a3=one;break;}
 func_0c045248(a,21);
}
void func_0c104ebe(struct Actor *a)
{
 int zero=0,one=1;
 a->b5=zero;a->b6=zero;a->b7=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=one;break;case 1:case 2:a->b1e9=one;a->b1a3=2;break;}
 func_0c045248(a,21);
}
void func_0c104efa(struct Actor *a){table_0c24b328[a->b6](a);}
