#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;typedef struct {u32 words[49];} Fields;typedef struct {float x,y,z;} V3;
extern u8 *D_004C29F8 __attribute__((section(".sdata")));extern u8 *D_004C29FC __attribute__((section(".sdata")));extern int func_001757E0(u8*,int,int);
#define OWNER (*(u8**)(p+0x18))
void func_00399C10(u8*p){
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];*(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);D_004C29F8[1]=1;
 *(float*)(p+0x34)=*(float*)(OWNER+0x34);*(float*)(p+0x38)=*(float*)(OWNER+0x38);p[0x24]=0;
 {float x,y; if(OWNER[0x20D]==2)y=231.428558349609375f;else y=180.0f;*(float*)(p+0x38)+=y;
 if(OWNER[0x20D]==2)x=113.3333282470703125f;else x=120.0f;x=OWNER[0x1E6]?x:-x;*(float*)(p+0x34)+=x;}
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 {float vx;if(OWNER[0x1E6])vx=3.3333332538604736328125f;else vx=-3.3333332538604736328125f;*(float*)(p+0x5C)=vx;}
 p[0x1B0]=66;p[0x1B1]=66;*(s16*)(p+0x1C)=20;D_004C29FC[1]=6;func_001757E0(p,23,2);
}
