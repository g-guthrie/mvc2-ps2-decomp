#include "objects.h"
extern unsigned char dat_0c243772[],dat_0c243792[];
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c0474f8(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
unsigned char func_0c09dcf8(struct Actor*a){if(!func_0c046e7e(a,dat_0c243772,a->x384))return 0;func_0c047aac(a,a->x384);a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,29);return 1;}
unsigned char func_0c09dd3e(struct Actor*a){if(!func_0c0474f8(a,dat_0c243792,a->x394))return 0;func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;func_0c045248(a,29);return 1;}
unsigned char func_0c09dd84(struct Actor *a)
{
    if (!func_0c046dd0(a, 9)) return 0;
    a->b1e9 = 9;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
int func_0c09ddbe(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=6;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}
