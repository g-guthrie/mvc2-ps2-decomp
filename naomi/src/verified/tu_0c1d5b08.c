#include "objects.h"
extern void func_0c037688(struct Obj_tu5_03 *);
extern void func_0c034a1c(int);
extern void (*dat_0c2616c8[])(struct Obj_tu5_03 *);
void func_0c1d5c4a(struct Obj_tu5_03 *);
void func_0c1d5b08(struct Obj_tu5_03 *a)
{
 struct Obj_tu5_03 *parent=a->p24;
 if(((struct Actor *)parent)->b0==0){func_0c037688(a);return;}
 a->pos.x=parent->pos.x;
 a->pos.y=parent->pos.y;
 if(((struct MeActor *)parent)->blk_dc.b13c>80){
  a->pos.y += (float)((((struct MeActor *)parent)->blk_dc.b13c-((struct MeActor *)parent)->blk_dc.b13d)/5)*parent->f84*4.28571415f;
 }else{
  a->pos.y += 30.0f+(float)((struct MeActor *)parent)->blk_dc.b13c*parent->f84*2.1428571f;
 }
 dat_0c2616c8[a->b4](a);
}
void func_0c1d5ba6(struct Obj_tu5_03 *a)
{
 if(a->w30){a->w30--;return;}
 if(!a->b35){
  switch(a->b32){
   case 0:func_0c034a1c(29);break;
   case 1:func_0c034a1c(28);break;
   case 2:func_0c034a1c(27);break;
   case 3:func_0c034a1c(30);break;
   case 4:func_0c034a1c(26);break;
   case 5:func_0c034a1c(29);break;
  }
 }
 a->b12c=1;
 a->w30=10;
 a->f80=1.0f;
 a->b4++;
 func_0c1d5c4a(a);
}
void func_0c1d5c4a(struct Obj_tu5_03 *a)
{
 if(--a->w30){a->f84+=0.15000001f;}
 else{a->f80=1.0f;a->f84=1.5f;a->b4++;a->w30=10;}
}
void func_0c1d5c82(struct Obj_tu5_03 *a)
{
 if(--a->w30){a->f84-=0.050000001f;}
 else{a->f80=1.0f;a->f84=1.0f;a->b4++;a->w30=40;}
}
void func_0c1d5cb6(struct Obj_tu5_03 *a)
{
 if(a->b35){func_0c037688(a);return;}
 if(!--a->w30){a->b4++;a->w30=4;}
}
void func_0c1d5cde(struct Obj_tu5_03 *a)
{
 if(--a->w30){a->f80+=0.25f;a->f84-=0.25f;}
 else{func_0c037688(a);}
}
