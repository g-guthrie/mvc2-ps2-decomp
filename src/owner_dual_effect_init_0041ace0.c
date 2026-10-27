#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;typedef struct {float x,y,z;} V3;
extern void *func_003DA750(void *,int,int);
extern void func_0041ACC0(u8 *),func_0041AE60(u8 *);
void func_0041ACE0(u8 *p)
{
 u8 *owner=*(u8 **)(p+0x18); u8 *child;
 p[4]++;*(s16 *)(p+0x26)=0x1c05;
 if(p[0x20]==0){
  *(u32 *)(p+0xd4)=0;*(u32 *)(p+0xd0)=0;*(u32 *)(p+0xd8)=2;
  child=func_003DA750(p,1,2);
  if(child){*(void (**)(u8 *))(child+0x10)=func_0041ACC0;*(u8 **)(child+0x18)=*(u8 **)(p+0x18);child[0x20]=1;*(u32 *)(child+0xd4)=255;*(u32 *)(child+0xd0)=255;*(u8 **)(child+0x14)=p;}
 }
 *(Fields *)(p+0xec)=*(Fields *)(owner+0xec);p[0x13c]=1;
 p[2]=owner[2];p[1]=owner[1];*(float *)(p+0x50)=*(float *)(owner+0x50);*(float *)(p+0x54)=*(float *)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];p[0x30]=*(s8 *)(owner+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(owner+0x50);p[0x24]=*(s8 *)(owner+0x24);
 p[0x13c]=1;p[0x24]=10;p[0x14c]=64;p[0x14d]=64;p[0x14e]=32;p[0x14f]=32;
 *(float *)(p+0x50)=1.04999995231628418f;
 if(*(s16 *)(p+0x140)==0)p[0x22]=12;else p[0x22]=4;
 p[0x1b0]=66;p[0x1b1]=66;func_0041AE60(p);
}
