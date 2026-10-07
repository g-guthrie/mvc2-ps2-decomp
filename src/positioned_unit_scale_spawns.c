typedef unsigned char u8;
typedef struct {float x,y,z;} Vec3;
extern u8 *func_003DA750(int,int,int);
extern void *D_004C2838;
extern void func_00157A10(u8 *);
void func_00157BF0(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
 p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_00157A10;
 *(short *)(p+0xcc)=58;*(void **)(p+0x84)=D_004C2838;*(int *)(p+0xd0)=0x800411;
 *(Vec3 *)(p+0x34)=*position;
 *(float *)(p+0x50)=1.0f;*(float *)(p+0x54)=1.0f;*(float *)(p+0x58)=1.0f;
 *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
extern void func_00157C90(u8 *);
void func_00157E60(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
 p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_00157C90;
 *(short *)(p+0xcc)=59;*(void **)(p+0x84)=D_004C2838;*(int *)(p+0xd0)=0x800411;
 *(Vec3 *)(p+0x34)=*position;
 *(float *)(p+0x50)=1.0f;*(float *)(p+0x54)=1.0f;*(float *)(p+0x58)=1.0f;
 *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
extern void func_00157F00(u8 *);
void func_001580D0(Vec3 *position) {
 u8 *p=func_003DA750(0,9,1);
 if(p) {
 p[0x13c]=1;*(void (**)(u8 *))(p+0x10)=func_00157F00;
 *(short *)(p+0xcc)=60;*(void **)(p+0x84)=D_004C2838;*(int *)(p+0xd0)=0x800411;
 *(Vec3 *)(p+0x34)=*position;
 *(float *)(p+0x50)=1.0f;*(float *)(p+0x54)=1.0f;*(float *)(p+0x58)=1.0f;
 *(int *)(p+0x78)=0;*(int *)(p+0x7c)=0;*(int *)(p+0x80)=0;
 }
}
