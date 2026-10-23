/* Advance the 1440-tick cycle and convert its selected rotation rate to a wrapped 16-bit angle. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern int dptoli(double);
void func_0033F260(u8 *p) {
 switch(p[4]) {
 case 0:
  ++*(s16*)(p+0x1C);
  if(*(s16*)(p+0x1C)>=1440) *(s16*)(p+0x1C)=0;
  switch(p[0x20]) {
  case 0:
   *(u32*)(p+0x40)=(u16)dptoli(0.5+65536.0*(double)((float)*(s16*)(p+0x1C)/2.0f)/360.0);
   break;
  case 1:
   *(u32*)(p+0x40)=(u16)dptoli(0.5+65536.0*(double)((float)*(s16*)(p+0x1C)/4.0f)/360.0);
   break;
  }
 }
}
