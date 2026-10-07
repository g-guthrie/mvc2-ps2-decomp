/* Dispatch the signed state index; the first handler advances it. */
typedef unsigned char u8;
extern void (*D_00446B98[])(u8 *);
void func_00172D10(u8 *p) { D_00446B98[*(signed char *)(p+0x4d1)](p); }
void func_00172D30(u8 *p) { int state=*(signed char *)(p+0x4d1);p[0x4d1]=state+1; }
