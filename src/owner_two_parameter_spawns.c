/* Spawn an owner-linked child with two byte-sized parameters. */
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_00198710(u8 *);
void func_00198620(u8 *owner,int parameter,int variant) {
 u8 *p=func_003DA750(0,3,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_00198710; *(u8 **)(p+0x18)=owner;
  p[0x20]=parameter; p[0x22]=variant; *(short *)(p+0x26)=1024;
 }
}
extern void func_001C9510(u8 *);
void func_001C9420(u8 *owner,int parameter,int variant) {
 u8 *p=func_003DA750(0,3,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_001C9510; *(u8 **)(p+0x18)=owner;
  p[0x20]=parameter; p[0x22]=variant; *(short *)(p+0x26)=7936;
 }
}
extern void func_0034C0A0(u8 *);
void func_0034BFB0(u8 *owner,int parameter,int variant) {
 u8 *p=func_003DA750(0,1,0);
 if(p) {
  *(void (**)(u8 *))(p+0x10)=func_0034C0A0; *(u8 **)(p+0x18)=owner;
  p[0x20]=parameter; p[0x22]=variant; *(short *)(p+0x26)=1027;
 }
}
