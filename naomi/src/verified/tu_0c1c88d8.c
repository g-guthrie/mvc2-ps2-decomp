#include "objects.h"
extern float dat_0c25ead8[][2];
extern unsigned char dat_0c22ffa0[];
extern int **dat_0c2d9658;
extern void func_0c02f644(struct Obj_tu5_03 *);
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1c88d8(struct Obj_tu5_03 *a) {
 a->f116+=0.050000001f;if(a->f116>1.0f) a->f116=1.0f;
 a->w28--;
 if(a->w28<=0) {
  a->b4++;a->pos.x=dat_0c25ead8[a->b32][0];a->pos.y=dat_0c25ead8[a->b32][1];a->pos.z=230.0f;a->f116=1.0f;
  if(!a->b32) a->p20->b4=1;
 } else {
  a->pos.x+=a->f92;a->f92+=a->f104;a->pos.y+=a->f96;a->f96+=a->f108;func_0c02f644(a);
 }
}
void func_0c1c8986(struct Obj_tu5_03 *a) {
 struct Obj_tu5_03 *parent=a->p24;
 if(parent->b4>=3) a->b4++;
 else {
  a->w30--;if(a->w30<=0) {
   a->w30=4;a->pad34++;if(a->pad34>5) a->pad34=0;
   a->l84=(*dat_0c2d9658)[dat_0c22ffa0[a->pad34]];
  }
 }
}
void func_0c1c89e4(struct Obj_tu5_03 *a) {
 a->f116-=0.050000001f;if(a->f116<=0.0f) {a->b4++;a->f116=0.0f;a->b12c=0;}
}
void func_0c1c8a0e(struct Obj_tu5_03 *a) {func_0c037688(a);}
