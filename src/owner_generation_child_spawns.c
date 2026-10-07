/* Spawn an owner-linked child carrying its generation in the dispatch word. */
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_003A05A0(u8 *);
void func_003A0530(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_003A05A0;
  *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  p[34]=parameter; *(short *)(p+0x26)=10756;
  *(int *)(p+0xd0)=*(unsigned short *)(owner+0x168);
 }
}
extern void func_003CD100(u8 *);
void func_003CD090(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_003CD100;
  *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  p[32]=parameter; *(short *)(p+0x26)=14849;
  *(int *)(p+0xd0)=*(unsigned short *)(owner+0x168);
 }
}
extern void func_003CD720(u8 *);
void func_003CD6B0(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_003CD720;
  *(u8 **)(p+0x18)=owner; p[1]=owner[1];
  p[32]=parameter; *(short *)(p+0x26)=14851;
  *(int *)(p+0xd0)=*(unsigned short *)(owner+0x168);
 }
}
