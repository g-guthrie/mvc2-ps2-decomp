#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c2f8cc0,dat_0c2f8cc1,dat_0c2d7008[],dat_0c2f8338[],dat_0c23a9bc[],dat_0c22b5fc[],dat_0c22b3bc[];
extern void (*table_0c23aa00[])(void),(*table_0c23aa08[])(void);
extern void func_0c1f8bb0(int,int),func_0c02aa78(void),func_0c02aaac(void),func_0c1fba00(void *,int,int),func_0c037354(void),func_0c034060(void),func_0c0336a0(void),func_0c023a50(void),func_0c0268b8(void),func_0c0267c4(void),func_0c0275bc(unsigned char *),func_0c0275d0(float),func_0c023658(int),func_0c02a7ea(int,int,int),func_0c026ae6(unsigned char *),func_0c030d64(void),func_0c1cceee(void);
extern int func_0c0230be(void);
void func_0c02ae44(void){dat_0c2d6f84->b1++;dat_0c2d6f84->i20=64;dat_0c2d6f84->b1a=0;dat_0c2d6f84->b8d=0;if(dat_0c2d6f84->b4e){dat_0c2d6f84->b1=dat_0c2d6f84->b4e;dat_0c2d6f84->b4e=0;}dat_0c2f8cc0=1;dat_0c2f8cc1=20;func_0c1f8bb0(0,0);func_0c1f8bb0(1,0);func_0c02aa78();func_0c02aaac();func_0c1fba00(dat_0c2d7008,0,128);func_0c1fba00(dat_0c2f8338,0,192);func_0c037354();func_0c034060();func_0c0336a0();}
void func_0c02aed0(void){table_0c23aa00[dat_0c2d6f84->b2]();}
void func_0c02aee0(void){dat_0c2d6f84->b2++;dat_0c2d6f84->s8=180;func_0c02aa78();func_0c02aaac();func_0c037354();func_0c023a50();func_0c0268b8();func_0c0267c4();func_0c0275bc(dat_0c23a9bc);func_0c0275d0(1.0f);func_0c023658(0);func_0c02a7ea(-1,20,0);}
void func_0c02af36(void){dat_0c2d6f84->s8--;if(!dat_0c2d6f84->s8){if(func_0c0230be())dat_0c2d6f84->s8++;else{dat_0c2d6f84->b1++;dat_0c2d6f84->b2=0;}}else{unsigned char *record;if(dat_0c2d6f84->b41==1)record=dat_0c22b5fc;else record=dat_0c22b3bc;while(*record<100){func_0c026ae6(record);record+=64;}}if(dat_0c2d6f84->s8==155)func_0c030d64();}
void func_0c02b020(void){func_0c1cceee();}
void func_0c02b026(void){table_0c23aa08[dat_0c2d6f84->b2]();}
