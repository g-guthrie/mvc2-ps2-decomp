typedef unsigned char u8;
extern u8 D_004D18A6 __attribute__((section(".bss")));
extern void func_00183C40(u8 *);
extern void (*D_00448A00[])(u8 *);
void func_001793B0(u8 *p) {
 if (p[1]==24 || p[1]==25 || p[1]==26) p[0x24]=7;
 if (p[0] && !(*(u8 **)(p+0x220))[0x25c]) {
  u8 mask=D_004D18A6;
  if (mask) {
   if (mask & (1 << (p[2]^1))) return;
   if (!p[0x404]) {func_00183C40(p);return;}
  }
  D_00448A00[p[4]](p);
 }
}
