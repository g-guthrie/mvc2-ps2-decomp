/* Spawn an owner-linked child with side-adjusted planar offsets. */
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_00345F40(u8 *);
void func_00345D90(u8 *owner,int parameter,float x,float y) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_00345F40;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; *(short *)(p+0x26)=1;
  if (!owner[0x1e6]) x=-x;
  *(unsigned short *)(p+0x9a)=*(unsigned short *)(owner+0x168);
  p[0x98]=parameter; *(float *)(p+0x90)=x; *(float *)(p+0x94)=y;
 }
}
extern void func_0037F230(u8 *);
void func_0037F080(u8 *owner,int parameter,float x,float y) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_0037F230;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; *(short *)(p+0x26)=6147;
  if (!owner[0x1e6]) x=-x;
  *(unsigned short *)(p+0x9a)=*(unsigned short *)(owner+0x168);
  p[0x98]=parameter; *(float *)(p+0x90)=x; *(float *)(p+0x94)=y;
 }
}
extern void func_0038E570(u8 *);
void func_0038E3B0(u8 *owner,int parameter,float x,float y) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_0038E570;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; *(short *)(p+0x26)=7681;
  if (!owner[0x1e6]) x=-x;
  *(unsigned short *)(p+0x9a)=*(unsigned short *)(owner+0x168);
  p[0x98]=parameter; *(float *)(p+0x90)=x; *(float *)(p+0x94)=y;
 }
}
