#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern char dat_0c259fa8[],dat_0c259fab[];
extern void (*table_0c259f98[])(struct LinkedActor *);
void func_0c1af120(struct LinkedActor *);
void func_0c1af298(struct LinkedActor *);
struct LinkedActor *func_0c1af0ec(struct LinkedActor *parent,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1af120; a->p24=parent; a->w38=0x1e03; a->b32=selector; }
 return a;
}
void func_0c1af120(struct LinkedActor *a) { table_0c259f98[a->b4](a); }
void func_0c1af132(struct LinkedActor *a) {
 a->f52=a->p24->f52; a->f56=a->p24->f56;
 if(a->p24->sdc.w130) a->f52+=dat_0c259fa8[a->b32]*1.66666663f;
 a->b36=a->p24->b36; a->b49=-1;
}
void func_0c1af180(struct LinkedActor *a) {
 a->b4++;
 a->sdc=a->p24->sdc; a->sdc.b12c=1;
 a->b2=a->p24->b2; a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x; a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3; a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48; a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->sdc.b12c=1; a->b36=0; a->sdc.w130=0;
 func_0c1af132(a);
 func_0c02a0c4(a,23,dat_0c259fab[a->b32]);
}
void func_0c1af244(struct LinkedActor *a) {
 if(a->p24->sdc.w158.bytes[1]!=19 && a->b32==1) goto advance;
 func_0c1af132(a);
 if(a->b32!=1) {
  if(func_0c02a026(a)<0) {
advance:
   a->b4++; func_0c1af298(a);
  }
 } else func_0c02a026(a);
}
void func_0c1af298(struct LinkedActor *a) { a->b4++; a->sdc.b12c=0; func_0c037688(a); }
