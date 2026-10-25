#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
extern int func_00174170(void),func_001754A0(u8*,int,int);
extern void func_001D7E50(u8*,void*);
void func_001D8190(u8 *p,void *owner_context) {
 u8 *q=owner_context;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(q+0xEC);p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(float*)(p+0x50)=*(float*)(q+0x50);*(float*)(p+0x54)=*(float*)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];p[0x30]=*(s8*)(q+0x30);
 *(V3*)(p+0x50)=*(V3*)(q+0x50);p[0x24]=*(s8*)(q+0x24);
 if(p[0x21]==0) {p[0x13C]=0;*(s16*)(p+0x1C)=0;*(s16*)(p+0x1E)=17;}
 else {p[0x13C]=1;*(s8*)(p+0x31)=-1;func_001754A0(p,27,(u8)((func_00174170()&3)+6));}
 func_001D7E50(p,q);
}
