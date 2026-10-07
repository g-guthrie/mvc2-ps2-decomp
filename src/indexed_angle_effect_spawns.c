/* Spawn a positioned effect with an indexed side-dependent angle. */
typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern int D_004BF438[2],D_004BF440[2];
extern void func_00159A90(u8 *);
void func_00159B00(Vec3 *position,int side) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00159A90;
  *(short *)(p+0xcc)=32; *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(int *)(p+0x44)=D_004BF438[side]; *(int *)(p+0xd0)=8389893;
 }
}
extern void func_00159BA0(u8 *);
void func_00159C30(Vec3 *position,int side) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_00159BA0;
  *(short *)(p+0xcc)=33; *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(int *)(p+0x44)=D_004BF438[side]; *(int *)(p+0xd0)=8389909;
 }
}
extern void func_0015A1C0(u8 *);
void func_0015A290(Vec3 *position,int side) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_0015A1C0;
  *(short *)(p+0xcc)=14; *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(int *)(p+0x44)=D_004BF440[side]; *(int *)(p+0xd0)=8389895;
 }
}
extern void func_0015A330(u8 *);
void func_0015A400(Vec3 *position,int side) {
 u8 *p=func_003DA750(0,8,1);
 if(p) {
  p[0x13c]=1; *(void (**)(u8 *))(p+0x10)=func_0015A330;
  *(short *)(p+0xcc)=15; *(void **)(p+0x84)=D_004C2838;
  *(Vec3 *)(p+0x34)=*position;
  *(int *)(p+0x44)=D_004BF440[side]; *(int *)(p+0xd0)=8389895;
 }
}
