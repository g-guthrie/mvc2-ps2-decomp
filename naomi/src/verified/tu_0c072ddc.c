#include "objects.h"
extern int func_0c03916c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c191980(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c241134[])(struct Actor *),(*table_0c24115c[])(struct Actor *);
void func_0c072ddc(register struct Actor *a)
{
 if(a->b1d0==22&&func_0c03916c(a)){func_0c0437b8(a);return;}
 switch(a->b32){
 case 0:case 2:case 4:
 if(!a->b33){
 func_0c02a026(a);
 if(a->b141){
 float offset;
 a->b141=0;offset=(signed char)a->b140;
 if(a->b1d2)offset=-offset;
 a->f52+=offset;
 }
 }else if(func_0c02a026(a)>=0){
 if(a->b141){a->b141=0;func_0c191980(a,6);}
 }else{a->b32=4;func_0c02a0c4(a,0,0);}
 break;
 case 1:case 3:func_0c02a026(a);break;
 }
}
void func_0c072e9e(struct Actor *a){table_0c241134[a->b1e9](a);}
void func_0c072eb2(struct Actor *a){table_0c24115c[a->b6](a);}
