typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_00136D00(u8 *);
extern void func_00170DF0(void *);
extern void *D_004C2830;
extern Float3 D_0043F1A8;
void func_00136C80(void) {
 u8 *p=func_003DA750(0,6,0);
 if(p){
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_00136D00;
  *(s16 *)(p+204)=6;
  *(void **)(p+132)=D_004C2830;
  *(Float3 *)(p+52)=D_0043F1A8;
  *(u32 *)(p+208)=0x20801;
  func_00170DF0(*(void **)(p+132));
 }
}
