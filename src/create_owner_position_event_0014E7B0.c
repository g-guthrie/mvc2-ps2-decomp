typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;
extern void *func_003DA750(void *,int,int);
extern void func_0014E840(u8 *);
void func_0014E7B0(u8 *owner,int timer,float y) {
 u8 *p=func_003DA750(0,13,1);
 if(p){
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_0014E840;
  *(u32 *)(p+208)=33;
  *(float *)(p+52)=-9.0f;
  *(float *)(p+56)=y;
  ((FloatBits *)(p+60))->bits=0x3E051EB8u;
  *(s16 *)(p+30)=timer;
  *(u8 **)(p+24)=owner;
  *(u8 **)(p+200)=owner+136;
 }
}
