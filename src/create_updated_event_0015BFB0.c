typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_0015BF10(u8 *);
extern void func_0015BE90(u8 *);
extern void func_0015BAC0(u8 *);
extern void func_0015BA40(u8 *);
extern u32 D_004C2838;
void func_0015BFB0(void) {
 u8 *p;
 if((p=func_003DA750(0,8,1))!=0) {
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_0015BF10;
  *(u32 *)(p+208)=21;
  *(s16 *)(p+204)=19;
  *(u32 *)(p+132)=D_004C2838;
  *(float *)(p+80)=1.0f;
  *(float *)(p+84)=1.0f;
  *(float *)(p+88)=1.0f;
  func_0015BE90(p);
 }
}

void func_0015BB60(void) {
 u8 *p;
 if((p=func_003DA750(0,8,1))!=0) {
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_0015BAC0;
  *(u32 *)(p+208)=21;
  *(s16 *)(p+204)=17;
  *(u32 *)(p+132)=D_004C2838;
  *(float *)(p+80)=1.0f;
  *(float *)(p+84)=1.0f;
  *(float *)(p+88)=1.0f;
  func_0015BA40(p);
 }
}
