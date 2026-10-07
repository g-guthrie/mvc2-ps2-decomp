/* Spawn preset-position effects and run their follow-up initializer. */
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C283C;
extern void func_00338180(u8 *),func_003388E0(u8 *);
extern float D_004B8070[3];
void func_003384F0(void) {
 u8 *p;
 if ((p=func_003DA750(0,5,1))!=0) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00338180;
  *(short *)(p+0xcc)=9; *(void **)(p+0x84)=D_004C283C;
  *(int *)(p+0xd0)=2051; *(Vec3 *)(p+0x34)=*(Vec3 *)D_004B8070;
  func_003388E0(p);
 }
}
extern void func_00338A30(u8 *),func_00338FE0(u8 *);
extern float D_004B80D0[3];
void func_00338BF0(void) {
 u8 *p;
 if ((p=func_003DA750(0,5,1))!=0) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00338A30;
  *(short *)(p+0xcc)=13; *(void **)(p+0x84)=D_004C283C;
  *(int *)(p+0xd0)=2049; *(Vec3 *)(p+0x34)=*(Vec3 *)D_004B80D0;
  func_00338FE0(p);
 }
}
extern void func_00339900(u8 *),func_00339EB0(u8 *);
extern float D_004B81D0[3];
void func_00339AC0(void) {
 u8 *p;
 if ((p=func_003DA750(0,5,1))!=0) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00339900;
  *(short *)(p+0xcc)=11; *(void **)(p+0x84)=D_004C283C;
  *(int *)(p+0xd0)=2049; *(Vec3 *)(p+0x34)=*(Vec3 *)D_004B81D0;
  func_00339EB0(p);
 }
}
