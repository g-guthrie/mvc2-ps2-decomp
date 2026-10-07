/* Select the position updater from each signed axis mode. */
typedef unsigned char u8;
extern void func_0032D110(u8 *);
extern void func_0032D170(u8 *);
extern void func_0032D0B0(u8 *);
void func_0032D230(u8 *p) {
 switch (*(signed char *)(p+44)) {
 case 1: func_0032D110(p); break;
 case 2: func_0032D170(p); break;
 default: func_0032D0B0(p); break;
 }
}
extern void func_0032D130(u8 *);
extern void func_0032D1B0(u8 *);
extern void func_0032D0D0(u8 *);
void func_0032D290(u8 *p) {
 switch (*(signed char *)(p+45)) {
 case 1: func_0032D130(p); break;
 case 2: func_0032D1B0(p); break;
 default: func_0032D0D0(p); break;
 }
}
extern void func_0032D150(u8 *);
extern void func_0032D1F0(u8 *);
extern void func_0032D0F0(u8 *);
void func_0032D2F0(u8 *p) {
 switch (*(signed char *)(p+46)) {
 case 1: func_0032D150(p); break;
 case 2: func_0032D1F0(p); break;
 default: func_0032D0F0(p); break;
 }
}
