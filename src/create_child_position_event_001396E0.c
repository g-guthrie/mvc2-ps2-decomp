typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_00139760(u8 *);
void func_001396E0(u8 *owner) {
 u8 *p=func_003DA750(0,6,0);
 if(p){
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_00139760;
  *(u8 **)(p+24)=owner;
  *(u8 **)(p+200)=owner+136;
  *(void **)(p+20)=*(void **)(owner+20);
  p[32]=owner[32];p[33]=owner[33];
  *(float *)(p+52)=0.0f;
  *(float *)(p+56)=0.0f;
  *(float *)(p+60)=1.0f;
  *(u32 *)(p+208)=2049;
 }
}
