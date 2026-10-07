/* Spawn a preset effect at its stored three-dimensional position. */
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void func_0032FC00(u8 *);
extern float D_0045E488[3];
extern void *D_004C283C;
void func_0032FE30(void) {
 u8 *p=func_003DA750(0,0x6,0x1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_0032FC00;
  *(short *)(p+0xcc)=0x3; *(void **)(p+0x84)=D_004C283C; *(unsigned int *)(p+0xd0)=0x805;
  *(Vec3 *)(p+0x34)=*(Vec3 *)D_0045E488;
 }
}
extern void func_00338050(u8 *);
extern float D_004B8060[3];
extern void *D_004C283C;
void func_00338100(void) {
 u8 *p=func_003DA750(0,0x5,0x1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00338050;
  *(short *)(p+0xcc)=0x8; *(void **)(p+0x84)=D_004C283C; *(unsigned int *)(p+0xd0)=0x803;
  *(Vec3 *)(p+0x34)=*(Vec3 *)D_004B8060;
 }
}
extern void func_0033A380(u8 *);
extern float D_004B8230[3];
extern void *D_004C283C;
void func_0033A420(void) {
 u8 *p=func_003DA750(0,0x6,0x1);
 if (p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_0033A380;
  *(short *)(p+0xcc)=0x2D; *(void **)(p+0x84)=D_004C283C; *(unsigned int *)(p+0xd0)=0x801;
  *(Vec3 *)(p+0x34)=*(Vec3 *)D_004B8230;
 }
}
