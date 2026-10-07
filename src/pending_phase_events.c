/* Advance the pending event index and run its completion handler. */
typedef unsigned char u8;
extern int func_00393390(u8 *);
extern void func_00393A20(void);
void func_003938D0(u8 *p) { p[5]++; if (func_00393390(p)) func_00393A20(); }
extern void func_00394080(void);
void func_00393F30(u8 *p) { p[5]++; if (func_00393390(p)) func_00394080(); }
extern void func_00394700(void);
void func_003945B0(u8 *p) { p[5]++; if (func_00393390(p)) func_00394700(); }
