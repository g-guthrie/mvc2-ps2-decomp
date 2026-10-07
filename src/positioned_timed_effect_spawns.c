typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern void func_001633B0(u8 *),func_00163520(u8 *),func_00163690(u8 *);
void func_00163310(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
  p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_001633B0;
  *(int *)(p+0xd0)=0x409;*(int *)(p+0xd4)=3;*(short *)(p+0xcc)=35;
  *(void **)(p+0x84)=D_004C2838;*(Vec3 *)(p+0x34)=*position;*(int *)(p+0x48)=910;
  *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
void func_00163480(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
  p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_00163520;
  *(int *)(p+0xd0)=0x409;*(int *)(p+0xd4)=4;*(short *)(p+0xcc)=36;
  *(void **)(p+0x84)=D_004C2838;*(Vec3 *)(p+0x34)=*position;*(int *)(p+0x48)=1820;
  *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
void func_001635F0(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
  p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_00163690;
  *(int *)(p+0xd0)=0x409;*(int *)(p+0xd4)=5;*(short *)(p+0xcc)=37;
  *(void **)(p+0x84)=D_004C2838;*(Vec3 *)(p+0x34)=*position;*(int *)(p+0x48)=1820;
  *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
