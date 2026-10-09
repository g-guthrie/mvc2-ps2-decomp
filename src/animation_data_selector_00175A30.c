/* Select animation data by actor kind, phase, and variant.
 * func_00175C00 consumes the returned data pointer. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
u8 *func_00175A30(u8 *p) {
 unsigned phase=p[0x25];
 u8 *base=*(u8 **)(p+0x174);
 u8 *owner=p+0x2B8;
 u8 *result=base+(phase<<8);
 switch(p[1]) {
 case 1:
  if(p[0x216]) result=base+((s8)p[0x30]*128+768)*2+((phase+8)<<5);
  break;
 case 34:
  if(*(u32 *)(p+0xD0)) result=base+((s8)p[0x30]*128+768)*2+((phase+20)<<5);
  break;
 case 55:
  if(owner[8]) result=base+((s8)p[0x30]*128+768)*2+phase*192;
  break;
 case 20:
  if(p[0x216]) result=base+((s8)p[0x30]*128+768)*2+((phase+6)<<5);
  break;
 }
 return result;
}
