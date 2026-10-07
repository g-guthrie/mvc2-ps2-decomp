/* Synchronize a child animation with the signed owner animation selector. */
typedef unsigned char u8;
extern void func_00175700(u8 *),func_001757E0(u8 *,int,int);
void func_00192B50(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 int mode=*(signed char *)(owner+0x161);
 if (mode) {
  p[0x13c]=1;
  if (*(short *)(p+0x1c)!=mode) {
   func_001757E0(p,23,mode); *(short *)(p+0x1c)=mode; return;
  }
  func_00175700(p);
 }
 owner=*(u8 **)(p+0x18);
 if (owner[0]) *(short *)(p+0x1c)=*(signed char *)(owner+0x161);
}
void func_001C8620(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 int mode=*(signed char *)(owner+0x161);
 if (mode) {
  p[0x13c]=1;
  if (*(short *)(p+0x1c)!=mode) {
   func_001757E0(p,23,mode); *(short *)(p+0x1c)=mode; return;
  }
  func_00175700(p);
 }
 owner=*(u8 **)(p+0x18);
 if (owner[0]) *(short *)(p+0x1c)=*(signed char *)(owner+0x161);
}
void func_001CF850(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 int mode=*(signed char *)(owner+0x161);
 if (mode) {
  p[0x13c]=1;
  if (*(short *)(p+0x1c)!=mode) {
   func_001757E0(p,23,mode); *(short *)(p+0x1c)=mode; return;
  }
  func_00175700(p);
 }
 owner=*(u8 **)(p+0x18);
 if (owner[0]) *(short *)(p+0x1c)=*(signed char *)(owner+0x161);
}
