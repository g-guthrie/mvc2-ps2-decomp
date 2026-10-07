/* On the animation flag, advance the step and set the sixty-frame timer. */
typedef unsigned char u8;
extern int func_00175670(u8 *);
int func_001B3240(u8 *p) {
 if (*(signed char *)(p+0x151)==1) { ++p[5];*(short *)(p+0x1c)=60; }
 return func_00175670(p);
}
