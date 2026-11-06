#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f7ac[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7bc[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7cc[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7d0[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7e0[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7e8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7f8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f7fc[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24f80c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c141994(struct LinkedActor *),func_0c141aac(struct LinkedActor *,struct LinkedActor *),func_0c141c14(struct LinkedActor *,struct LinkedActor *),func_0c141dce(struct LinkedActor *,struct LinkedActor *),func_0c141f50(struct LinkedActor *,struct LinkedActor *),func_0c142030(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1418f8(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c141994;a->w38=0x0d01;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
struct LinkedActor *func_0c141946(struct LinkedActor *parent,unsigned char mode,char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da((int)parent,1,2))){a->p16=func_0c141994;a->w38=0x0d01;a->p24=parent->p24;a->p20=parent;a->b1=parent->b1;*(&a->b32)=mode;a->b33=value;}
 return a;
}
void func_0c141994(struct LinkedActor *a){table_0c24f7ac[a->b32](a,a->p24);}
void func_0c1419aa(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7bc[a->b4](a,owner);}
void func_0c1419bc(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 A(a)->f92=0.0f;A(a)->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;
 if(!a->sdc.w130){a->f52-=80.0f;A(a)->f92=-10.0f;}else{a->f52+=80.0f;A(a)->f92=10.0f;}
 a->s28=1;if(!a->b1a3)a->s30=24;else a->s30=48;
 func_0c141aac(a,owner);
}
void func_0c141aac(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7cc[(unsigned char)a->b5](a,owner);}
void func_0c141abe(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;
 if(--a->s28==0){a->s28=12;func_0c141946(a,1,0);}
 if(--a->s30==0){a->b4++;func_0c142030(a,owner);}
}
void func_0c141b22(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7d0[a->b4](a,owner);}
void func_0c141b44(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *parent=a->p20;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=-1;
 A(a)->b1a1=81;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 A(a)->b19c=66;A(a)->b19d=66;
 a->f52=parent->f52;a->f56=parent->f56;a->f60=parent->f60;
 A(a)->f96=10.7142849f;A(a)->f108=-0.669642807f;
 func_0c02a0c4(a,21,28);func_0c141c14(a,owner);
}
void func_0c141c14(struct LinkedActor *a,struct LinkedActor *owner){a->b36=owner->b36;table_0c24f7e0[(unsigned char)a->b5](a,owner);}
void func_0c141c2e(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 func_0c02a026(a);func_0c037d0c(a);
 if(a->sdc.b141){a->b5++;A(a)->f96=-0.535714269f;A(a)->f108=0.0f;}
}
void func_0c141cb4(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(func_0c02a026(a)<0){a->b4++;func_0c142030(a,owner);}
}
void func_0c141d00(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7e8[a->b4](a,owner);}
void func_0c141d12(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 A(a)->f92=0.0f;A(a)->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;
 A(a)->b13e=A(a)->b13f=53;
 if(!a->sdc.w130){a->f52-=80.0f;A(a)->f92=-15.0f;}else{a->f52+=80.0f;A(a)->f92=15.0f;}
 a->s28=1;func_0c141dce(a,owner);
}
void func_0c141dce(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7f8[(unsigned char)a->b5](a,owner);}
void func_0c141e0c(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;
 if(--a->s28==0){a->s28=10;func_0c141946(a,3,0);}
 if(!func_0c028642(a)){a->b4++;func_0c142030(a,owner);}
}
void func_0c141e6e(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f7fc[a->b4](a,owner);}
void func_0c141e80(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *parent=a->p20;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=-1;
 A(a)->b1a1=79;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 A(a)->b19c=66;A(a)->b19d=66;
 a->f52=parent->f52;a->f56=parent->f56;a->f60=parent->f60;
 A(a)->f96=25.7142849f;A(a)->f108=-1.33928562f;
 func_0c02a0c4(a,22,11);func_0c141f50(a,owner);
}
void func_0c141f50(register struct LinkedActor *a,struct LinkedActor *owner){table_0c24f80c[(unsigned char)a->b5](a,owner);}
void func_0c141f94(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 func_0c02a026(a);func_0c037d0c(a);
 if(a->sdc.b141){a->b5++;A(a)->f96=-2.1428571f;A(a)->f108=0.0f;}
}
void func_0c141fe4(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(func_0c02a026(a)<0){a->b4++;func_0c142030(a,owner);}
}
void func_0c142030(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c14203e(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
