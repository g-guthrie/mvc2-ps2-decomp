#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c064500(struct Actor *),func_0c0438de(struct Actor *),func_0c03489c(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c03edcc(struct Actor *,struct Actor *),func_0c045248(struct Actor *,int);
void func_0c06799c(struct Actor *a){
 struct Actor *child=a->p1c8;
 if(a->b1f9!=2){if(func_0c02a026(a)<0){func_0c064500(a);return;}}
 else{if(func_0c02a026(a)<0){func_0c0438de(a);return;}}
 if((a->b141&63)==2){
 a->b141&=192; child->p1b4=a;func_0c025900(a,0,0);
 child->b1d2=a->b1d2^1;
 if(a->b1f9!=2){child->b1f6=2;child->b1a1=58;}
 else{child->b1f6=1;child->b1a1=59;child->b1f9=2;}
 func_0c03489c(a);
 }
}
void func_0c067a4c(struct Actor *a){
 struct Actor *child=a->p1c8;
 a->b12c=1;if(((char *)&child->w150)[0]==2)a->b12c=0;
 func_0c03edcc(child,a);
 if(((char *)&child->w150)[1]==36)a->f52+=child->f100;
}
void func_0c067a94(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=5;break;case 1:a->b1e9=6;break;case 2:a->b1e9=7;break;}
 func_0c045248(a,29);
}
void func_0c067afc(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=5;break;case 1:a->b1e9=6;break;case 2:a->b1e9=7;break;}
 func_0c045248(a,29);
}
void func_0c067b38(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=2;break;case 1:a->b1e9=3;break;case 2:a->b1e9=zero;break;default:goto done;}
 a->b1a3=1;
 done:func_0c045248(a,21);
}
void func_0c067b78(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=2;break;case 1:a->b1e9=3;break;case 2:a->b1e9=zero;break;default:goto done;}
 a->b1a3=1;
 done:func_0c045248(a,21);
}
