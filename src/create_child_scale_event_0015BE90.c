typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_0015BBD0(u8 *);
extern u32 D_004C2838;
void func_0015BE90(u8 *owner) {
 u8 *p=func_003DA750(0,8,1);
 if(p){
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_0015BBD0;
  *(s16 *)(p+204)=18;
  *(u32 *)(p+132)=D_004C2838;
  *(u32 *)(p+208)=25;
  *(u8 **)(p+20)=owner;
  *(u8 **)(p+200)=owner+136;
  *(float *)(p+80)=1.0f;
  *(float *)(p+84)=1.0f;
  *(float *)(p+88)=1.0f;
 }
}
