typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;
extern void *func_003DA750(void *,int,int);
extern void func_0014EB20(u8 *);
extern u32 D_004C27FC;
void func_0014EA80(u8 *owner,int timer){
 u8 *p=func_003DA750(0,13,1);
 if(p){
 *(void (**)(u8 *))(p+16)=func_0014EB20;
 *(s16 *)(p+204)=52;
 *(u32 *)(p+132)=D_004C27FC;
 *(u32 *)(p+208)=1057;
 *(float *)(p+52)=-7.5f;
 ((FloatBits *)(p+56))->bits=0xBF75C28F;
 ((FloatBits *)(p+60))->bits=0x3D8F5C29;
 *(u8 **)(p+200)=owner+136;
 *(s16 *)(p+30)=timer;
 *(u8 **)(p+24)=owner;
 }
}
