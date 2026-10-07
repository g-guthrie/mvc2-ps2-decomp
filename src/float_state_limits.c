/* Expire the cooldown state and clamp negative vertical velocity. */
typedef unsigned char u8;
void func_001BDA10(u8 *p) {
 float value=*(float *)(p+0x118)-0.100000001490116119384765625f;
 *(float *)(p+0x118)=value;
 if (value<=0.0f) { ++p[4];p[0x13c]=0; }
}
void func_001822B0(u8 *p) {
 float value=*(float *)(p+0x60);
 if(value<0.0f) {
  if(value<-21.428569793701171875f) *(float *)(p+0x60)=-21.428569793701171875f;
 }
}
