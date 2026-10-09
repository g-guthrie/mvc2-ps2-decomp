typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;
extern u8 *func_003DA750(void *,int,int);
extern void func_0014A290(u8 *);
extern u32 D_004C27FC;
void func_0014A220(u8 *owner) {
 u8 *p=func_003DA750(0,13,1);
 if(p) {
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_0014A290;
  *(s16 *)(p+204)=3;
  *(u32 *)(p+132)=D_004C27FC;
  *(u32 *)(p+208)=1;
  ((FloatBits *)(p+60))->bits=0xBDCCCCCDu; /* -0.1f */
  *(u8 **)(p+200)=owner+136;
 }
}
