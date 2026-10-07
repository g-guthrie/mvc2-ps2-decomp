/* Accept a live interaction, advancing the stance latch when permitted. */
typedef unsigned char u8;
extern int func_00189310(u8 *,void *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_00451480[];
int func_00222EC0(u8 *p) {
 if (!func_00189310(p,D_00451480,p+0x388)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (p[0x20d]==2) {
  if (*(signed char *)(p+0x1e8) && !p[0x210]) return 0;
  ++*(signed char *)(p+0x1e8);
 }
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=2;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_00455C20[];
int func_002864F0(u8 *p) {
 if (!func_00189310(p,D_00455C20,p+0x3a0)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (p[0x20d]==2) {
  if (*(signed char *)(p+0x1e8) && !p[0x210]) return 0;
  ++*(signed char *)(p+0x1e8);
 }
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=7;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_00455C40[];
int func_00286630(u8 *p) {
 if (!func_00189310(p,D_00455C40,p+0x390)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (p[0x20d]==2) {
  if (*(signed char *)(p+0x1e8) && !p[0x210]) return 0;
  ++*(signed char *)(p+0x1e8);
 }
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=5;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_00456D10[];
int func_0028DE00(u8 *p) {
 if (!func_00189310(p,D_00456D10,p+0x3a0)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (p[0x20d]==2) {
  if (*(signed char *)(p+0x1e8) && !p[0x210]) return 0;
  ++*(signed char *)(p+0x1e8);
 }
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=7;
 func_00186A60(p,0x1d);
 return 1;
}
