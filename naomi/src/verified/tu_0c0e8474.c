#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *),func_0c0462a0(struct Actor *),func_0c046dd0(struct Actor *,int),func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern int func_0c046d54(struct Actor *),func_0c0435ce(struct Actor *,float);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int),func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c1fba00(void *,int,int),func_0c044450(struct Actor *,struct Actor *),func_0c0eb5ea(struct Actor *,int),func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c2499f0[];
extern void (*table_0c249a40[])(struct Actor *);
#define RESET a->b5=0;a->b7=0;a->b6=0
extern unsigned char dat_0c2498c4[],dat_0c2498d4[],dat_0c2498e8[],dat_0c2498fc[],dat_0c24990c[],dat_0c24991c[],dat_0c24992c[],dat_0c24993c[],dat_0c24994c[],dat_0c24995c[],dat_0c24996c[],dat_0c24987c[],dat_0c249880[],dat_0c249884[],dat_0c249888[],dat_0c24988c[],dat_0c249890[];
void func_0c0e8474(struct Actor *a);
unsigned char func_0c0e8564(struct Actor *a);
unsigned char func_0c0e85e2(struct Actor *a);
unsigned char func_0c0e8628(struct Actor *a);
unsigned char func_0c0e8698(struct Actor *a);
unsigned char func_0c0e8714(struct Actor *a);
unsigned char func_0c0e87b4(struct Actor *a);
unsigned char func_0c0e882e(struct Actor *a);
unsigned char func_0c0e88cc(struct Actor *a);
unsigned char func_0c0e8952(struct Actor *a);
unsigned char func_0c0e89a2(struct Actor *a);
unsigned char func_0c0e8a10(struct Actor *a);
int func_0c0e8a54(struct Actor *a);
int func_0c0e8a8e(struct Actor *a);
int func_0c0e8ace(struct Actor *a);
int func_0c0e8b20(struct Actor *a);
int func_0c0e8b56(struct Actor *a);
void func_0c0e8b8c();
void func_0c0e8bc8(struct Actor *a);
void func_0c0e8bdc(struct Actor *a);
void func_0c0e8c50(struct Actor *a);
void func_0c0e8d84(struct Actor *a);
void func_0c0e8ea8(struct Actor *a);
void func_0c0e8fcc(struct Actor *a);
void func_0c0e8474(struct Actor *a){if(func_0c0465cc(a))return;if(func_0c046b6c(a))return;if(func_0c0469f4(a))return;if(func_0c046d3c(a))return;if(func_0c0e8698(a))return;if(func_0c0e8714(a))return;if(func_0c0e87b4(a))return;if(func_0c0e882e(a))return;if(func_0c0e88cc(a))return;if(func_0c0e8952(a))return;if(func_0c0e8a10(a))return;if(func_0c0e89a2(a))return;if(func_0c0e8564(a))return;if(func_0c0e85e2(a))return;if(func_0c0e8628(a))return;if(func_0c0e8a8e(a))return;if(func_0c0e8a54(a))return;if(func_0c0462a0(a))return;func_0c045f1c(a);func_0c0463fc(a);}

unsigned char func_0c0e8564(struct Actor *a){struct ActorSub2a4 *state=&a->sub2a4;if(!func_0c046e7e(a,dat_0c2498c4,a->x36c))return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;else a->b1d4++;}if(state->b6)return 0;func_0c047aac(a,a->x36c);RESET;a->b1e9=0;func_0c045248(a,21);return 1;}

unsigned char func_0c0e85e2(struct Actor *a){if(!func_0c046e7e(a,dat_0c2498d4,a->x374))return 0;func_0c047aac(a,a->x374);RESET;a->b1e9=1;func_0c045248(a,21);return 1;}

unsigned char func_0c0e8628(struct Actor *a){if(!func_0c046e7e(a,dat_0c2498e8,a->x37c))return 0;func_0c047aac(a,a->x37c);RESET;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c0e8698(struct Actor *a){if(!func_0c046e7e(a,dat_0c2498fc,a->x384))return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}a->b1a3=0;RESET;a->b1e9=3;func_0c045248(a,29);func_0c1fba00(a->x3a4,0,8);func_0c1fba00(a->x3ac,0,8);return 1;}

unsigned char func_0c0e8714(struct Actor *a){if(!func_0c046e7e(a,dat_0c24990c,a->x38c))return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}a->b1a3=1;RESET;a->b1e9=3;func_0c045248(a,29);func_0c1fba00(a->x3a4,0,8);func_0c1fba00(a->x3ac,0,8);return 1;}

unsigned char func_0c0e87b4(struct Actor *a){if(!func_0c046e7e(a,dat_0c24991c,a->x394))return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}a->b1a3=2;RESET;a->b1e9=3;func_0c045248(a,29);func_0c1fba00(a->x3a4,0,8);func_0c1fba00(a->x3ac,0,8);return 1;}

unsigned char func_0c0e882e(struct Actor *a){if(!func_0c046e7e(a,dat_0c24992c,a->x39c))return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}a->b1a3=3;RESET;a->b1e9=3;func_0c045248(a,29);func_0c1fba00(a->x3a4,0,8);func_0c1fba00(a->x3ac,0,8);return 1;}

unsigned char func_0c0e88cc(struct Actor *a){if(!func_0c046e7e(a,dat_0c24993c,a->x3a4)||!*a->p40c)return 0;if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}func_0c047aac(a,a->x3a4);RESET;if(a->b1f9==2)a->b1e9=12;else a->b1e9=5;func_0c045248(a,29);return 1;}

unsigned char func_0c0e8952(struct Actor *a){if(!func_0c046e7e(a,dat_0c24994c,a->x3ac))return 0;else if(!*a->p40c)return 0;func_0c047aac(a,a->x3ac);RESET;a->b1e9=6;func_0c045248(a,29);return 1;}

unsigned char func_0c0e89a2(struct Actor *a){if(!func_0c046e7e(a,dat_0c24995c,a->x3b4))return 0;func_0c047aac(a,a->x3b4);RESET;a->b1e9=4;func_0c045248(a,21);return 1;}

unsigned char func_0c0e8a10(struct Actor *a){struct Actor *target;struct LinkedActorVec3 p;if(!func_0c046e7e(a,dat_0c24996c,a->x3bc))return 0;else if(!(target=func_0c037d54(a)))return 0;a->b1f7=195;func_0c044450(a,target);return 1;}

int func_0c0e8a54(struct Actor *a){if(!func_0c046dd0(a,9))return 0;a->b1e9=9;a->b5=0;func_0c045248(a,21);a->b6=a->b7=0;return 1;}

int func_0c0e8a8e(struct Actor *a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=13;a->b5=0;func_0c045248(a,29);a->b6=a->b7=0;return 1;}

int func_0c0e8ace(struct Actor *a){if(func_0c0e8b20(a)||func_0c0e8b56(a))return 1;return 0;}

int func_0c0e8b20(struct Actor *a){if(!func_0c046e7e(a,dat_0c24993c,a->x3a4))return 0;else if(!*a->p40c)return 0;a->b258=5;return 1;}

int func_0c0e8b56(struct Actor *a){if(!func_0c046e7e(a,dat_0c24994c,a->x3ac))return 0;else if(!*a->p40c)return 0;a->b258=6;return 1;}

void func_0c0e8b8c(struct Actor *a,int mode){struct ActorSub2a4 *state=&a->sub2a4;if(a->b201&&!a->b5){if((short)--state->w8<=0){mode=a->b1d0;if(mode==29)return;if(mode==21)return;func_0c0eb5ea(a,mode);}}}

void func_0c0e8bc8(struct Actor *a){table_0c249a40[a->b1ff](a);}

void func_0c0e8bdc(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0e8fcc(a);else func_0c0e8ea8(a);}else{if(a->b1f9==1)func_0c0e8d84(a);else func_0c0e8c50(a);}}

void func_0c0e8c50(struct Actor *a);
void func_0c0e8c50(struct Actor *a);
void func_0c0e8c50(struct Actor *a);
void func_0c0e8c50(struct Actor *a){switch((unsigned char)a->b1e8){case 0:if(func_0c0435ce(a,dat_0c2499f0[0])){a->b158=3;a->b1a1=48;}else{a->b158=0;a->b1a1=0;}func_0c0346da(a,20);a->p3f4=dat_0c24987c;a->b1a7=0;a->pad2a2[0]=1;break;case 1:if(func_0c0435ce(a,dat_0c2499f0[1])){a->b158=4;a->b1a1=49;}else{a->b158=1;a->b1a1=1;}func_0c0346da(a,21);a->p3f4=dat_0c249880;a->b1a7=1;break;case 2:if(func_0c0435ce(a,dat_0c2499f0[2])){a->b158=5;a->b1a1=50;}else{a->b158=2;a->b1a1=2;}func_0c0346da(a,22);a->p3f4=dat_0c249884;a->b1a7=2;break;}a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);}

void func_0c0e8d84(struct Actor *a);
void func_0c0e8d84(struct Actor *a);
void func_0c0e8d84(struct Actor *a);
void func_0c0e8d84(struct Actor *a){switch((unsigned char)a->b1e8){case 0:if(func_0c0435ce(a,dat_0c2499f0[3])){a->b158=3;a->b1a1=54;}else{a->b158=0;a->b1a1=6;}func_0c0346da(a,20);a->p3f4=dat_0c24987c;a->b1a7=0;break;case 1:if(func_0c0435ce(a,dat_0c2499f0[4])){a->b158=4;a->b1a1=55;}else{a->b158=1;a->b1a1=7;}func_0c0346da(a,21);a->p3f4=dat_0c249880;a->b1a7=1;break;case 2:if(func_0c0435ce(a,dat_0c2499f0[5])){a->b158=5;a->b1a1=56;}else{a->b158=2;a->b1a1=8;}func_0c0346da(a,22);a->p3f4=dat_0c249884;a->b1a7=2;break;}a->b19e=a->w1ac=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}

void func_0c0e8ea8(struct Actor *a){switch((unsigned char)a->b1e8){case 0:if(func_0c0435ce(a,dat_0c2499f0[6])){a->b158=3;a->b1a1=51;}else{a->b158=0;a->b1a1=3;}func_0c0346da(a,20);a->p3f4=dat_0c249888;a->b1a7=0;break;case 1:if(func_0c0435ce(a,dat_0c2499f0[7])){a->b158=4;a->b1a1=52;}else{a->b158=1;a->b1a1=4;}func_0c0346da(a,21);a->p3f4=dat_0c24988c;a->b1a7=1;break;case 2:if(func_0c0435ce(a,dat_0c2499f0[8])){a->b158=5;a->b1a1=53;}else{a->b158=2;a->b1a1=5;}func_0c0346da(a,22);a->p3f4=dat_0c249890;a->b1a7=2;break;}a->b19e=a->w1ac=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}

void func_0c0e8fcc(struct Actor *a){switch((unsigned char)a->b1e8){case 0:if(func_0c0435ce(a,dat_0c2499f0[9])){a->b6++;a->b158=3;a->b1a1=57;}else{a->b158=0;a->b1a1=9;}func_0c0346da(a,20);a->p3f4=dat_0c249888;a->b1a7=0;break;case 1:if(func_0c0435ce(a,dat_0c2499f0[10])){a->b6++;a->b158=4;a->b1a1=58;}else{a->b158=1;a->b1a1=10;}func_0c0346da(a,21);a->p3f4=dat_0c24988c;a->b1a7=1;break;case 2:if(func_0c0435ce(a,dat_0c2499f0[11])){a->b6++;a->b158=5;a->b1a1=59;}else{a->b158=2;a->b1a1=11;}func_0c0346da(a,22);a->p3f4=dat_0c249890;a->b1a7=2;break;}a->b19e=a->w1ac=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}
