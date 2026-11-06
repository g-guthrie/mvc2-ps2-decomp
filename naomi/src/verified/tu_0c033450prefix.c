#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c033d16(int,int),func_0c02c9d8(int,int);
extern void func_0c0241f8(void),func_0c0275dc(void),func_0c0267ce(void),func_0c037354(void),func_0c033cbe(void),func_0c033cd8(void),func_0c034358(void);
extern unsigned char dat_0c2d96a8,dat_0c2d96a9;
extern signed char dat_0c22da10[];
void func_0c033450(void)
{
 if(!--dat_0c2d6f84->s8)dat_0c2d6f84->b4++;
 if(dat_0c2d6f84->s8==360)dat_0c2d6f84->s14=1;
 if(dat_0c2d6f84->s8==330)dat_0c2d6f84->s14=2;
 if(dat_0c2d6f84->s8==60)func_0c033d16(0,20);
 if(dat_0c2d6f84->s14==2){dat_0c2d6f84->s12++;if(dat_0c2d6f84->s12>=8){dat_0c2d6f84->s12=0;dat_0c2d6f84->s10++;if(dat_0c2d6f84->s10>=8)dat_0c2d6f84->s10=0;
 dat_0c2d6f84->b5--;if(dat_0c2d6f84->b5==-2)dat_0c2d6f84->s14=3;
 dat_0c2d96a8=1;dat_0c2d96a9=11;func_0c02c9d8(dat_0c2d6f84->b5,7-dat_0c2d6f84->s10);
 }}
 func_0c0241f8();func_0c0275dc();func_0c0267ce();
}
void func_0c03351a(void)
{
 dat_0c2d6f84->b1=1;dat_0c2d6f84->b2=0;dat_0c2d6f84->b3=0;dat_0c2d6f84->b4=0;dat_0c2d6f84->b5=0;dat_0c2d6f84->b6=0;dat_0c2d6f84->b7=0;dat_0c2d6f84->b44++;
 func_0c037354();func_0c033cbe();func_0c033cd8();func_0c034358();
}
signed char func_0c033564(unsigned char c){return dat_0c22da10[c-32];}
