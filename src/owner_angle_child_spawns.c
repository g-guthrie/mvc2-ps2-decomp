/* Spawn an owner-linked child and copy its side and angle fields. */
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_00355C50(u8 *);
void func_00355BE0(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_00355C50;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  *(short *)(p+0x26)=0x900;
  *(unsigned short *)(p+0x1c)=*(unsigned short *)(owner+0x168);
 }
}
extern void func_0038DB70(u8 *);
void func_0038DB00(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_0038DB70;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  *(short *)(p+0x26)=0x1e00;
  *(unsigned short *)(p+0xd0)=*(unsigned short *)(owner+0x168);
 }
}
extern void func_0039BC90(u8 *);
void func_0039BC20(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_0039BC90;
  p[0x20]=parameter; *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  *(short *)(p+0x26)=0x2700;
  *(unsigned short *)(p+0xd0)=*(unsigned short *)(owner+0x168);
 }
}
