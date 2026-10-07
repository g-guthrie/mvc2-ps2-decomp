/* Periodic visibility toggle and state-pointer dispatch. */
typedef unsigned char u8;
extern u8 *D_004C26D0;
extern void (*D_004492F0[])(u8 *);
void func_0013FCB0(u8 *p) { if ((*(short *)(p+0x1c))++ == 30) { *(short *)(p+0x1c)=0; p[0x13c]=*(signed char *)(p+0x13c)^1; } }
void func_00192E00(u8 *p) { D_004C26D0=p+0xd0; D_004492F0[p[4]](p); }
