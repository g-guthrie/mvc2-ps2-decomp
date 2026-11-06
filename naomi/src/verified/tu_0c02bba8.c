#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c2d7008[],dat_0c2f8338[],dat_0c284024[],dat_0c358480[],dat_0c38b100[],dat_0c2d7088[];
extern void func_0c1fba00(void *,int,int);
extern void func_0c02aa78(void),func_0c02aaac(void),func_0c02a7e0(void);
extern void func_0c023658(int),func_0c034358(void),func_0c033cbe(void),func_0c033cd8(void),func_0c033fd0(int);
extern void func_0c1ed730(void *,int),func_0c1edf50(int),func_0c1eeb60(void);
extern void func_0c1ef190(int,float,float,float),func_0c1e9e80(int,int,int);
extern void func_0c1e8fd0(void *,void *),func_0c1f0f50(void),func_0c1ecda0(void),func_0c037354(void);
void func_0c02bba8(void)
{
 int i;
 dat_0c2d6f84->b1++;
 dat_0c2d6f84->b25=1;
 func_0c1fba00(dat_0c2d7008,0,128);
 func_0c1fba00(dat_0c2f8338,0,192);
 dat_0c2d6f84->b85=dat_0c2d6f84->b24;
 dat_0c2d6f84->b46=0;
 *((char *)dat_0c2d6f84+0x83)=dat_0c2d6f84->pad4f;
 dat_0c2d6f84->b4e=6;
 dat_0c2d6f84->b44=0;
 *((char *)dat_0c2d6f84+0xb2)=3;
 func_0c02aa78();func_0c02aaac();func_0c02a7e0();
 func_0c023658(0);func_0c034358();func_0c033cbe();func_0c033cd8();func_0c033fd0(127);
 func_0c1ed730(dat_0c284024,64);func_0c1edf50(3);func_0c1eeb60();
 func_0c1ef190(0x1d28,1.3333334f,0.300000012f,12000.0f);
 func_0c1edf50(1);func_0c1e9e80(0x808080,128,0x808080);
 func_0c1e8fd0(dat_0c358480,dat_0c38b100);
 func_0c1f0f50();func_0c1ecda0();func_0c037354();
 for(i=0;i<6;i++){
 ((struct Actor *)(dat_0c2d7088+i*0x5a4))->b0=1;((struct Actor *)(dat_0c2d7088+i*0x5a4))->b12c=0;((struct Actor *)(dat_0c2d7088+i*0x5a4))->b524=i;((struct Actor *)(dat_0c2d7088+i*0x5a4))->b1=i;
 ((struct Actor *)(dat_0c2d7088+i*0x5a4))->b52c=i;
 ((struct Actor *)(dat_0c2d7088+i*0x5a4))->b53f=i/2;
 ((struct Actor *)(dat_0c2d7088+i*0x5a4))->b543=2;
 }
}
