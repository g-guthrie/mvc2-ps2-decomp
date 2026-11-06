/* Attached animation effect: allocation, normal/alternate update, and cleanup. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c259fb0[])(struct LinkedActor *),(*table_0c259fc0[])(struct LinkedActor *);
void func_0c1af356(struct LinkedActor *),func_0c1af470(struct LinkedActor *),func_0c1af3f2(struct LinkedActor *),func_0c1af4ae(struct LinkedActor *),func_0c1af4f8(struct LinkedActor *),func_0c1af504(struct LinkedActor *);
struct LinkedActor *func_0c1af2b8(struct LinkedActor *owner,char alternate)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){
 a->p24=owner;a->w38=0x1e04;a->p16=func_0c1af356;
 if(alternate){
 a->p16=func_0c1af470;
 a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->sdc.b12c=0;
 }}return a;
}
void func_0c1af356(struct LinkedActor *a){table_0c259fb0[a->b4](a);}
void func_0c1af368(struct LinkedActor *a){
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->sdc.b12c=1;
 a->b36=0;a->sdc.w130=0;func_0c02a0c4(a,23,17);func_0c1af3f2(a);
}
void func_0c1af3f2(struct LinkedActor *a){
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(a->sdc.b141<0)a->b36=0;else a->b36=7;
 if((unsigned char)((struct Actor *)a->p24)->b159!=21)goto retire;
 switch((unsigned char)((struct Actor *)a->p24)->b158){
 case 6:case 8:case 9:goto animate;
 }
 retire:a->b4++;func_0c1af4f8(a);return;
 animate:func_0c02a026(a);
}
void func_0c1af470(struct LinkedActor *a){table_0c259fc0[a->b4](a);}
void func_0c1af482(struct LinkedActor *a){
 a->b4++;a->sdc.b12c=1;a->b36=0;a->sdc.w130=0;
 func_0c02a0c4(a,23,17);func_0c1af4ae(a);
}
void func_0c1af4ae(struct LinkedActor *a){
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(a->sdc.b141<0)a->b36=0;else a->b36=7;
 if((unsigned char)((struct Actor *)a->p24)->b159!=22 || (unsigned char)((struct Actor *)a->p24)->b158!=10){a->b4++;func_0c1af4f8(a);return;}
 func_0c02a026(a);
}
void func_0c1af4f8(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c1af504(a);}
void func_0c1af504(struct LinkedActor *a){func_0c037688(a);}
