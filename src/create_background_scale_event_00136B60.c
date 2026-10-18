typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_00136BF0(u8 *);
extern u8 *D_004C2924;
extern u32 D_004C2830;
void func_00136B60(void){
 u8 *p=func_003DA750(0,6,1);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_00136BF0;
 *(u8 **)(p+200)=D_004C2924+136;
 *(s16 *)(p+204)=1;
 *(u32 *)(p+132)=D_004C2830;
 *(float *)(p+52)=0.0f;*(float *)(p+56)=-1.0f;*(float *)(p+60)=0.0f;
 *(u32 *)(p+68)=16384;
 *(float *)(p+80)=4.0f;*(float *)(p+84)=4.0f;*(float *)(p+88)=1.0f;
 *(u32 *)(p+208)=2069;
 }
}
