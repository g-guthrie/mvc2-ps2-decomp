/* Forwards the linked actor at +0x1DC and self to func_00179160
 * (real definition in src/tail_leaves.c: void func_00179160(void *, void *)). */
typedef unsigned char u8;
extern void func_00179160(void *, void *);
void func_002FBBC0(u8 *p) { func_00179160(*(u8 **)(p + 0x1dc), p); }
