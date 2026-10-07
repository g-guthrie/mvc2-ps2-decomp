/* Spawn a linked child carrying the requested effect parameters. */
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_00198710(u8 *);
void func_00198690(u8 *owner,int first,int second) {
 u8 *p=func_003DA750(0,0x3,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_00198710;
  *(u8 **)(p+0x18)=*(u8 **)(owner+0x18);
  *(u8 **)(p+0x14)=owner;
  p[0x20]=first; p[0x22]=second; *(short *)(p+0x26)=0x400;
 }
}
extern void func_001AD260(u8 *);
void func_001AD1E0(u8 *owner,int first,int second) {
 u8 *p=func_003DA750(0,0x3,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_001AD260;
  *(u8 **)(p+0x18)=*(u8 **)(owner+0x18);
  *(u8 **)(p+0x14)=owner;
  p[0x20]=first; p[0x21]=second; *(short *)(p+0x26)=0x1100;
 }
}
extern void func_001C9510(u8 *);
void func_001C9490(u8 *owner,int first,int second) {
 u8 *p=func_003DA750(0,0x3,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_001C9510;
  *(u8 **)(p+0x18)=*(u8 **)(owner+0x18);
  *(u8 **)(p+0x14)=owner;
  p[0x20]=first; p[0x22]=second; *(short *)(p+0x26)=0x1F00;
 }
}
extern void func_001CBE90(u8 *);
void func_001CBE10(u8 *owner,int first,int second) {
 u8 *p=func_003DA750(0,0x3,0);
 if (p) {
  *(void (**)(u8 *))(p+0x10)=func_001CBE90;
  *(u8 **)(p+0x18)=*(u8 **)(owner+0x18);
  *(u8 **)(p+0x14)=owner;
  p[0x20]=first; p[0x21]=second; *(short *)(p+0x26)=0x2000;
 }
}
