typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
void func_001B57D0(u8 *p) {
 u8 *parent=*(u8 **)(p+0x18);
 s16 timer;
 *(f32 *)(p+0x38)+=*(f32 *)(p+0x70);
 *(f32 *)(p+0x50)+=*(f32 *)(p+0x5C);
 *(f32 *)(p+0x54)+=*(f32 *)(p+0x60);
 if(!(*(f32 *)(parent+0x54)<1.0f)) {
  p[4]=2;
  p[0x13C]=0;
 }else{
  timer=*(s16 *)(p+0x1C)-1;
  *(s16 *)(p+0x1C)=timer;
  if(timer<=0) {
   *(s16 *)(p+0x1C)=3;
   p[6]=2;
   *(f32 *)(p+0x50)=*(f32 *)(parent+0x50)+0.3f;
   *(f32 *)(p+0x54)=*(f32 *)(parent+0x54)+0.2f;
   *(f32 *)(p+0x5C)=-0.02f;
   *(f32 *)(p+0x68)=0.002f;
   *(f32 *)(p+0x60)=-0.02f;
   /* The native routine writes this same acceleration field twice. */
   *(f32 *)(p+0x68)=0.002f;
  }
 }
}
