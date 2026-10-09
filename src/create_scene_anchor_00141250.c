typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_001412C0(u8 *);
extern u32 D_004C2818;
extern Float3 D_004B1E38;
void func_00141250(void) {
 u8 *p=func_003DA750(0,13,1);
 if(p) {
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_001412C0;
  *(s16 *)(p+204)=0;
  *(u32 *)(p+132)=D_004C2818;
  *(u32 *)(p+208)=2049;
  *(Float3 *)(p+52)=D_004B1E38;
 }
}
