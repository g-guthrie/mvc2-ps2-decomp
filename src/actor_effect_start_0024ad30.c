typedef unsigned char u8;typedef short s16;
typedef struct {float x,y,z;} V3;
typedef struct O O;
extern void func_00175C00(u8*,int),func_00176160(u8*,int,int,int),func_0015B200(O*,V3*,u8,unsigned short),func_001E3710(u8*,u8),func_0024AE10(u8*);
extern int func_001757E0(u8*,int,int);
void func_0024AD30(u8*p){
 /* Retail initializes x and y but leaves pos.z unwritten before the effect call. */
 V3 pos; ++p[7];func_00175C00(p,0);func_00176160(p,5,1,1);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;
 if(*(s16*)(p+0x140)==0)pos.x=*(float*)(p+0x34);else pos.x=*(float*)(p+0x34);
 pos.y=*(float*)(p+0x38)+85.7142791748046875f;
 func_0015B200((O*)p,&pos,1,8);func_001E3710(p,74);func_001757E0(p,19,2);func_0024AE10(p);
}
