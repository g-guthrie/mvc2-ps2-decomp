typedef unsigned char u8;
typedef short s16;
extern int func_00174170(void);
extern int func_001757E0(u8*,int,int);
extern void func_001AA040(u8*,u8*),func_001A9FE0(u8*,u8*);
void func_001A9EF0(u8*p,u8*owner){
 u8 side=0;
 ++p[7];*(float*)(p+0x5C)=0;*(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 if(*(float*)(p+0x34)<*(float*)(owner+0x34))side=1;
 if(side!=*(s16*)(p+0x140)){
  *(int*)(p+0xD0)=p[6];*(int*)(p+0xD4)=p[7];p[6]=11;p[7]=0;func_001AA040(p,owner);return;
 }
 if(p[6]!=*(int*)(p+0xD0))func_001757E0(p,23,(u8)((unsigned int)func_00174170()%3));
 func_001A9FE0(p,owner);
}
