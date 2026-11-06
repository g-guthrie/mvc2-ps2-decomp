#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void (*table_0c242554[])(struct Actor *,struct MotionContext8a3 *);
extern void (*table_0c242560[])(struct Actor *,struct ActorSub2a4 *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c0346da(struct Actor *,int),func_0c045248(struct Actor *,int);
void func_0c08a66c(struct Actor *a,struct MotionContext8a3 *m)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else{
 if(a->b141&1){
 a->b141^=1;
 position.x=26.6666661f;position.y=167.142853f;
 func_0c043014(a,&position);
 }
 if(a->b141&2)func_0c0346da(a,22);
 }
}
void func_0c08a6c8(struct Actor *a,struct MotionContext8a3 *m)
{
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);
}
void func_0c08a6dc(struct Actor *a,struct MotionContext8a3 *m)
{
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);
}
void func_0c08a6f0(struct Actor *a,struct MotionContext8a3 *m)
{
 int zero=0,one=1;
 a->b5=zero;a->b6=zero;a->b7=zero;
 switch(a->b4c9){case 0:a->b1e9=one;break;case 1:a->b1e9=2;break;case 2:a->b1e9=zero;break;default:goto animate;}
 a->b1a3=one;
 animate:goto select_bank;select_bank:func_0c045248(a,21);
}
void func_0c08a72e(struct Actor *a,struct MotionContext8a3 *m)
{
 int zero=0,one=1;
 a->b5=zero;a->b6=zero;a->b7=zero;
 switch(a->b4c9){case 0:a->b1e9=one;break;case 1:a->b1e9=2;break;case 2:a->b1e9=zero;break;default:goto animate;}
 a->b1a3=one;
 animate:goto select_bank;select_bank:func_0c045248(a,21);
}

void func_0c08a792(struct Actor *a,struct MotionContext8a3 *m){table_0c242554[a->b6](a,m);}
void func_0c08a7a4(register struct Actor *a,struct MotionContext8a3 *m)
{
 a->b6++;a->b1f9=2;a->f92=-30.0f;
 if(a->b1d2)a->f92=-a->f92;
 a->f96=0.26785714f;a->f104=0.0f;a->f108=-0.80357141f;
 func_0c02a39a(a,0);
 a->b1a1=44;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,28);
}
void func_0c08a820(struct Actor *a,struct MotionContext8a3 *m)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
 float stopped=0.0f;
 a->b6++;a->f56=a->f41c;a->b1f9=0;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 func_0c02a0c4(a,21,29);
 }
}
void func_0c08a8a8(struct Actor *a,struct MotionContext8a3 *m)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c08a8ca(register struct Actor *a){table_0c242560[a->b6](a,&a->sub2a4);}
