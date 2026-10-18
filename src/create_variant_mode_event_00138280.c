typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_001385B0(u8 *);
void func_00138280(u8 mode, u32 argument) {
 u8 *p=func_003DA750(0,6,0);
 if(p){
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_001385B0;
  p[32]=mode;
  *(s16 *)(p+28)=0;
  p[33]=2;
  *(u32 *)(p+220)=0;
  *(u32 *)(p+216)=argument;
 }
}
