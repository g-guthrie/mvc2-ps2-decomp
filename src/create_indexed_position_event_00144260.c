typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_001442F0(u8 *);
extern u32 D_004C2810;
extern Float3 *D_00442550[];
void func_00144260(int index) {
 u8 *p=func_003DA750(0,6,1);
 if(p){
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_001442F0;
  *(s16 *)(p+204)=index+1;
  *(u32 *)(p+132)=D_004C2810;
  *(u32 *)(p+208)=2049;
  p[32]=index;
  *(Float3 *)(p+52)=*D_00442550[index];
 }
}
