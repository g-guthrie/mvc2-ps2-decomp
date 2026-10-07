#pragma padloop on
typedef unsigned char u8;
extern u8 *func_003DA750(int,int,int);
extern void func_001934B0(u8 *),func_00194AA0(u8 *),func_001E16A0(u8 *);
void func_00193430(u8 *owner) {
 int i=0;u8 *p;
 do {
  if ((p=func_003DA750(0,4,1))!=0) {
   *(void (**)(u8 *))(p+0x10)=func_001934B0;
   *(u8 **)(p+0x18)=owner;
   p[1]=owner[1];
   p[0x20]=1;p[0x21]=i;*(short *)(p+0x26)=768;
  }
 } while(++i<2);
}void func_00194A20(u8 *owner) {
 int i=0;u8 *p;
 do {
  if ((p=func_003DA750(0,4,0))!=0) {
   *(void (**)(u8 *))(p+0x10)=func_00194AA0;
   *(u8 **)(p+0x18)=owner;
   p[1]=owner[1];
   p[0x21]=i;*(short *)(p+0x26)=770;p[0x88]=4;
  }
 } while(++i<8);
}void func_001E1620(u8 *owner) {
 unsigned int i=0;u8 *p;
 do {
  if ((p=func_003DA750(0,4,0))!=0) {
   *(void (**)(u8 *))(p+0x10)=func_001E16A0;
   *(u8 **)(p+0x18)=owner;
   p[1]=owner[1];
   *(short *)(p+0x26)=14851;p[0x20]=1;p[0x21]=i;
  }
 } while(++i<10);
}

#pragma padloop off
extern void func_001CEB40(u8 *);
void func_001CEA60(u8 *owner) {
 u8 i;u8 *p;
 for(i=0;i<4;++i) {
  if (!(p=func_003DA750(0,3,0))) break;
  *(void (**)(u8 *))(p+0x10)=func_001CEB40;
  *(u8 **)(p+0x18)=owner;
  p[0x20]=14;p[0x21]=i;*(short *)(p+0x26)=0x2600;
 }
}
