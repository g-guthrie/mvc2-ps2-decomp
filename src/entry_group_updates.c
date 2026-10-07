typedef unsigned char u8;
extern void func_00159840(u8 *,int);
extern void func_00153F70(u8 *,int,int),func_00154220(u8 *,int,int);
#pragma padloop on
void func_001599F0(u8 *p) {int i=0;do{func_00159840(p,i);}while(++i<10);}
void func_00154120(u8 *p,int input) {int i; signed char mode=input;if(mode<3){i=0;do{func_00153F70(p,mode,i);}while(++i<6);}}
void func_00154390(u8 *p,int input) {int i; signed char mode=input;if(mode<3){i=0;do{func_00154220(p,mode,i);}while(++i<6);}}
