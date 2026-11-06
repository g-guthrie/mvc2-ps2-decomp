#include "objects.h"
extern unsigned char dat_0c2f8338;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c1d330c(void *,float *,int,int);
extern void func_0c0346da(struct LinkedActor *,int);
extern void (*table_0c257cb8[])(struct LinkedActor *,void *);
void func_0c194810(struct LinkedActor *a,struct LinkedActor *parent)
{
    if(dat_0c2f8338>2||parent->b7>2){a->b5++;a->s28=32;}
}
void func_0c194832(struct LinkedActor *a)
{if(--a->s28==0)a->b5++;}
void func_0c194848(struct LinkedActor *a,void *context)
{
    float *smooth=(float *)&a->pad9b[0];
    struct MotionGlobal_0c2d9260 *bounds;
    float velocity=a->f92;
    if(velocity<0)velocity=-velocity;
    *smooth+=velocity;
    a->f52+=a->f92;a->f92+=a->f104;
    a->f56+=a->f96;a->f96+=a->f108;
    bounds=&dat_0c2d9260;
    if(a->sdc.w130){if(bounds->f8c-a->f52<0)goto close;goto draw;}
    if(bounds->f88-a->f52>0)goto close;
    goto draw;
close:a->b4++;return;
draw:
    if(!(dat_0c2d6f84->flags&3)){
        func_0c1d330c(context,&a->f52,1,137);
        func_0c0346da(a,73);
    }
}
void func_0c19490a(struct LinkedActor *a,void *context)
{
    a->sdc.b12c=0;
    table_0c257cb8[(unsigned char)a->b5](a,context);
}
