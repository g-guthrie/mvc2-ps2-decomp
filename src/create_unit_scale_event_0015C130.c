typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_0015C020(u8 *);
extern void func_0015C2E0(u8 *);
extern u32 D_004C2838;
void func_0015C130(void) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_0015C020;
  *(u32 *)(p+208)=21;
  *(s16 *)(p+204)=21;
  *(u32 *)(p+132)=D_004C2838;
  *(float *)(p+80)=1.0f;
  *(float *)(p+84)=1.0f;
  *(float *)(p+88)=1.0f;
 }
}

void func_0015C3F0(void) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_0015C2E0;
  *(u32 *)(p+208)=21;
  *(s16 *)(p+204)=21;
  *(u32 *)(p+132)=D_004C2838;
  *(float *)(p+80)=1.0f;
  *(float *)(p+84)=1.0f;
  *(float *)(p+88)=1.0f;
 }
}
