typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_0019A540(u8 *),func_001BFE80(u8 *),func_00377910(u8 *);
void func_0019A3D0(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,3,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_0019A540;*(u8 **)(p+0x18)=owner;
  p[0x20]=parameter;*(short *)(p+0x26)=1537;
  *(unsigned short *)(p+208)=*(unsigned short *)(owner+0x168);
 }
}
void func_001BFCA0(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,3,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_001BFE80;*(u8 **)(p+0x18)=owner;
  p[0x20]=parameter;*(short *)(p+0x26)=6656;
  *(unsigned short *)(p+30)=*(unsigned short *)(owner+0x168);
 }
}
void func_003778A0(u8 *owner,int parameter) {
 u8 *p=func_003DA750(0,1,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_00377910;*(u8 **)(p+0x18)=owner;
  p[0x20]=parameter;*(short *)(p+0x26)=5378;
  *(unsigned short *)(p+30)=*(unsigned short *)(owner+0x168);
 }
}
