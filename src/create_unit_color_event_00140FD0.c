typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_00141040(u8 *);
extern u32 D_004C2818;
void func_00140FD0(void) {
 u8 *p=func_003DA750(0,13,1);
 if(p){
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_00141040;
  *(s16 *)(p+204)=10;
  *(u32 *)(p+132)=D_004C2818;
  *(u32 *)(p+208)=0x00800C00;
  *(float *)(p+120)=1.0f;
  *(float *)(p+124)=1.0f;
  *(float *)(p+128)=1.0f;
 }
}
