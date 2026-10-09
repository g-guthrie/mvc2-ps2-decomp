typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_00135E20(u8 *);
extern void func_001360C0(u8 *);
void func_00135DB0(int mode) {
 u8 *p;
 if((p=func_003DA750(0,15,1))!=0) {
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_00135E20;
  *(u32 *)(p+132)=0;
  *(u32 *)(p+208)=0;
  *(s16 *)(p+38)=7;
  p[32]=mode&15;
  if(mode&128)func_001360C0(p);
 }
}
