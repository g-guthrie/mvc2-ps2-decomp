#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern int func_001754A0(u8*,int,int);
void func_001BBE60(u8*p,u8*owner){
 int count;u32 *dst,*src;
 p[4]=1;p[0x13C]=1;src=(u32*)(owner+0xEC);dst=(u32*)(p+0xEC);count=49;
 do {*dst++=*src++;}while(--count>0);
 p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);p[0x24]=*(s8*)(owner+0x24);*(s8*)(p+0x31)=-1;
 *(V3*)(p+0x34)=*(V3*)(owner+0x34);*(float*)(p+0x118)=1.0f;*(short*)(p+0x1C)=0;
 switch(p[0x23]){
 case 7:func_001754A0(p,27,11);break;
 case 0:func_001754A0(p,27,11);break;
 case 1:func_001754A0(p,27,12);break;
 case 2:func_001754A0(p,27,13);break;
 }
}
