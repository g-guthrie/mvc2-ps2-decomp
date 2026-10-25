/* Complete the countdown and clone the selected event with its native value argument. */
#pragma padloop on
typedef unsigned char u8;
extern u8 *func_001B3E30(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_00266190(u8 *p)
{
 p[0x40C]=2;p[0x33C]=5;
 if(--*(short*)(p+0x1C)<=0){
  ++p[6];*(unsigned int*)(p+0x48)=0xE000;
  switch(p[0x20]){
  case 24:func_001B3E30(p,18,5);break;
  case 20:*(float*)(p+0x38)-=17.142856597900391f;func_001B3E30(p,17,5);break;
  case 16:*(float*)(p+0x38)-=8.571428298950195f;func_001B3E30(p,16,5);break;
  }
  func_001757E0(p,22,9);
 }
}
