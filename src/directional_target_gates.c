/* Select a target only for the requested input direction and stance. */
typedef unsigned char u8;
extern u8 *func_001E7FD0(u8 *);
u8 *func_00269EB0(u8 *p) {
 if ((p[0x22]=(*(unsigned short *)(p+0x20e)&0xc00)>>10)) {
  if (!p[0x212]) {
  if (p[0x1b7]==0x1) {
   u8 *target=func_001E7FD0(p);
   if (target) { p[0x20b]=0x2; return target; }
  }
 }
 }
 return 0;
}
u8 *func_002FF370(u8 *p) {
 if ((p[0x22]=(*(unsigned short *)(p+0x20e)&0xc00)>>10)) {
  if (!p[0x212]) {
  if (p[0x1b7]==0x1) {
   u8 *target=func_001E7FD0(p);
   if (target) { p[0x20b]=0x3; return target; }
  }
 }
 }
 return 0;
}
u8 *func_003152F0(u8 *p) {
 if ((p[0x22]=(*(unsigned short *)(p+0x20e)&0xc00)>>10)) {
  if (!p[0x212]) {
  if (p[0x1b7]==0x1) {
   u8 *target=func_001E7FD0(p);
   if (target) { p[0x20b]=0x3; return target; }
  }
 }
 }
 return 0;
}
