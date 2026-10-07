/* Commit the unoccupied stance request and record its selected mode. */
typedef unsigned char u8;
extern int func_00189310(u8 *,void *,u8 *);
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_00455C70[];
int func_002868E0(u8 *p) {
 u8 *slot=p+0x2B8;
 if (p[0x2bb] || !func_00189310(p,D_00455C70,p+0x3B0)) return 0;
 func_0018A990(p,p+0x3B0);
 p[0x5]=0; p[0x7]=0; p[0x6]=0; p[0x1fd]=0xC;
 func_00186A60(p,0x15);
 if (!*(signed char *)(p+0x539)) slot[0x1A]=0x1;
 else slot[0x1A]=p[0x212];
 return 1;
}
extern u8 D_00455C80[];
int func_00286980(u8 *p) {
 u8 *slot=p+0x2B8;
 if (p[0x2bb] || !func_00189310(p,D_00455C80,p+0x3B8)) return 0;
 func_0018A990(p,p+0x3B8);
 p[0x5]=0; p[0x7]=0; p[0x6]=0; p[0x1fd]=0xC;
 func_00186A60(p,0x15);
 if (!*(signed char *)(p+0x539)) slot[0x1A]=0x2;
 else slot[0x1A]=p[0x212];
 return 1;
}
extern u8 D_00456D60[];
int func_0028E1A0(u8 *p) {
 u8 *slot=p+0x2B8;
 if (p[0x2bb] || !func_00189310(p,D_00456D60,p+0x3B0)) return 0;
 func_0018A990(p,p+0x3B0);
 p[0x5]=0; p[0x7]=0; p[0x6]=0; p[0x1fd]=0xC;
 func_00186A60(p,0x15);
 if (!*(signed char *)(p+0x539)) slot[0x1A]=0x1;
 else slot[0x1A]=p[0x212];
 return 1;
}
extern u8 D_00456D70[];
int func_0028E240(u8 *p) {
 u8 *slot=p+0x2B8;
 if (p[0x2bb] || !func_00189310(p,D_00456D70,p+0x3B8)) return 0;
 func_0018A990(p,p+0x3B8);
 p[0x5]=0; p[0x7]=0; p[0x6]=0; p[0x1fd]=0xC;
 func_00186A60(p,0x15);
 if (!*(signed char *)(p+0x539)) slot[0x1A]=0x2;
 else slot[0x1A]=p[0x212];
 return 1;
}
