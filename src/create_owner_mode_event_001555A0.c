typedef unsigned char u8;
extern void *func_003DA750(void *,int,int);
extern void func_00155600(u8 *);
void func_001555A0(u8 *owner,int kind,u8 mode,u8 variant) {
 u8 *p=func_003DA750(0,kind,1);
 if(p) {
  *(void (**)(u8 *))(p+16)=func_00155600;
  *(u8 **)(p+24)=owner;
  p[32]=mode;
  p[33]=variant;
 }
}
