/* Spawn an effect above the supplied position with unit scale. */
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern void func_0015D620(u8 *);
void func_0015D370(Vec3 *position) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1;
  *(void (**)(u8 *))(p+0x10)=func_0015D620;
  *(short *)(p+0xcc)=186;
  *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(float *)(p+0x38)+=137.14285278320312500000f;
  *(int *)(p+0xd0)=0x31;
  *(short *)(p+0x1c)=0;
  *(float *)(p+0x74)=1.0f;
  *(float *)(p+0x50)=1.0f;
  *(float *)(p+0x54)=1.0f;
  *(float *)(p+0x58)=1.0f;
 }
}
extern void func_0015D730(u8 *);
void func_0015D4C0(Vec3 *position) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1;
  *(void (**)(u8 *))(p+0x10)=func_0015D730;
  *(short *)(p+0xcc)=195;
  *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(float *)(p+0x38)+=137.14285278320312500000f;
  *(int *)(p+0xd0)=0x31;
  *(short *)(p+0x1c)=0;
  *(float *)(p+0x74)=1.0f;
  *(float *)(p+0x50)=1.0f;
  *(float *)(p+0x54)=1.0f;
  *(float *)(p+0x58)=1.0f;
 }
}
extern void func_0015D810(u8 *);
void func_0015D570(Vec3 *position) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1;
  *(void (**)(u8 *))(p+0x10)=func_0015D810;
  *(short *)(p+0xcc)=196;
  *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(float *)(p+0x38)+=137.14285278320312500000f;
  *(int *)(p+0xd0)=0x31;
  *(short *)(p+0x1c)=0;
  *(float *)(p+0x74)=1.0f;
  *(float *)(p+0x50)=1.0f;
  *(float *)(p+0x54)=1.0f;
  *(float *)(p+0x58)=1.0f;
 }
}
