#include "objects.h"
extern void func_0c02a684(struct LinkedActor *,int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);

void func_0c1a0740(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 a->b4++;
 parent=a->p24;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;
 a->b1=parent->b1;
 a->v80.x=parent->v80.x;
 a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;
 a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=1;
 a->b36=14;
 a->sdc.w130=a->p24->sdc.w130;
 a->f52=a->p24->f52;
 a->f56=a->p24->f56;
 a->f60=a->p24->f60;
 a->f52+=a->sdc.w130?-53.33333206176758f:53.33333206176758f;
 a->f56+=34.285714f;
 a->f104=0.0f;
 a->f108=0.0f;
 func_0c029e70(a,27,14);
}

void func_0c1a0808(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 a->b4++;
 parent=a->p24;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;
 a->b1=parent->b1;
 a->v80.x=parent->v80.x;
 a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;
 a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=1;
 a->b36=0;
 a->sdc.w130=a->p24->sdc.w130;
 a->f52=a->p24->f52;
 a->f56=a->p24->f56;
 a->f60=a->p24->f60;
 a->f52+=a->sdc.w130?116.66666412353516f:-116.66666412353516f;
 a->f56+=12.857142448425293f;
 a->f104=0.0f;
 a->f108=0.0f;
 func_0c029e70(a,27,14);
}

void func_0c1a08f8(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 a->b4++;
 parent=a->p24;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;
 a->b1=parent->b1;
 a->v80.x=parent->v80.x;
 a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;
 a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=1;
 a->b36=0;
 a->sdc.w130=a->p24->sdc.w130;
 a->f52=a->p24->f52;
 a->f56=a->p24->f56;
 a->f60=a->p24->f60;
 a->f52+=a->sdc.w130?26.66666603088379f:-26.66666603088379f;
 a->f56+=205.7142791748047f;
 a->f104=0.0f;
 a->f108=0.0f;
 a->f92=a->sdc.w130?5.8333331f:-5.8333331f;
 a->f104=a->sdc.w130?0.41666666f:-0.41666666f;
 a->f96=2.142857074737549f;
 a->f108=0.26785714f;
 func_0c02a684(parent,4,8,1);
 func_0c029e70(a,27,13);
}
