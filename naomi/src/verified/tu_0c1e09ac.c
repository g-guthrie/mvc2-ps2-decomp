#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1e09a8(struct Obj_tu5_03 *);
extern void func_0c1e0b04(struct Obj_tu5_03 *,int);
extern struct Vec3_tu5_03 dat_0c262650;
extern float dat_0c26265c[];
void func_0c1e09ac(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e09a8;
        a->l84=dat_0c2d964c->p0->entries[30].value;
        a->lcc=0x80f;
        a->pos=dat_0c262650;
        a->angles.array[0]=(int)(dat_0c26265c[0]*65536.0f/360.0f+0.5f)&0xffff;
        a->angles.scalar.l44=(int)(dat_0c26265c[1]*65536.0f/360.0f+0.5f)&0xffff;
        a->angles.scalar.l48=(int)(dat_0c26265c[2]*65536.0f/360.0f+0.5f)&0xffff;
        func_0c1e0b04(a,0);
        func_0c1e0b04(a,1);
        func_0c1e0b04(a,2);
    }
}
