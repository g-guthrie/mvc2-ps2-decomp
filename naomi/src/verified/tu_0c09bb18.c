#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern struct Tbl_ub3_01*dat_0c2f83f8;
extern void func_0c0437b8(struct Actor*),func_0c0438de(struct Actor*),func_0c043324(struct Actor*),func_0c0442fa(struct Actor*),func_0c0432ca(struct Actor*),func_0c02a0c4(struct Actor*,int,int);
extern void (*table_0c2435a0[])(struct Actor*);
void func_0c09bb18(struct Actor*a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->b7++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,1,3);func_0c043324(a);return;}if(func_0c02a026(a)<0)func_0c0438de(a);}

void func_0c09bba6(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}

void func_0c09bbd8(struct Actor *a){table_0c2435a0[a->b6](a);}

void func_0c09bbea(struct Actor *a)
{
    int z = 0;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6 = a->b6 + 1;
    a->b1a1 = 75;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = z;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 4);
}
