typedef unsigned char u8;
typedef void (*Callback)(u8 *,u8 *);
extern u8 D_004D18A6 __attribute__((section(".bss")));
extern Callback D_004C1EE8[2],D_004C1FD8[2];
extern void func_003A6DB0(u8 *,u8 *),func_003B2E80(u8 *,u8 *);
void func_003A69B0(u8 *p,u8 *owner) {
 if (!(D_004D18A6 & (1 << (p[2]^1)))) {
  if (owner[0x169]!=22) { func_003A6DB0(p,owner);return; }
  if (owner[5]) func_003A6DB0(p,owner);
  else {
   *(signed char *)(p+0x24)=*(signed char *)(owner+0x24);
   if (!p[0x21]) *(signed char *)(p+0x31)=-1; else *(signed char *)(p+0x31)=1;
   *(float *)(p+0x34)=*(float *)(owner+0x34);
   if (!*(signed char *)(owner+0x1b4)) D_004C1EE8[p[5]](p,owner);
  }
 }
}

void func_003B2A80(u8 *p,u8 *owner) {
 if (!(D_004D18A6 & (1 << (p[2]^1)))) {
  if (owner[0x169]!=22) { func_003B2E80(p,owner);return; }
  if (owner[5]) func_003B2E80(p,owner);
  else {
   *(signed char *)(p+0x24)=*(signed char *)(owner+0x24);
   if (!p[0x21]) *(signed char *)(p+0x31)=-1; else *(signed char *)(p+0x31)=1;
   *(float *)(p+0x34)=*(float *)(owner+0x34);
   if (!*(signed char *)(owner+0x1b4)) D_004C1FD8[p[5]](p,owner);
  }
 }
}
