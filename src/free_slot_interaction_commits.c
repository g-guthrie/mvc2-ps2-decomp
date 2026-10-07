/* Commit an accepted live interaction when its stance slot is free. */
typedef unsigned char u8;
extern int func_00189310(u8 *,void *,u8 *);
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_004505F0[];
int func_002082D0(u8 *p) {
 u8 *slot=p+0x2B8;
 if (!func_00189310(p,D_004505F0,p+0x380)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (*slot) return 0;
 func_0018A990(p,p+0x380);
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0xC;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_00450600[];
int func_00208380(u8 *p) {
 u8 *slot=p+0x2B8;
 if (!func_00189310(p,D_00450600,p+0x388)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (*slot) return 0;
 func_0018A990(p,p+0x388);
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0xA;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_00450610[];
int func_00208430(u8 *p) {
 u8 *slot=p+0x2B8;
 if (!func_00189310(p,D_00450610,p+0x390)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (*slot) return 0;
 func_0018A990(p,p+0x390);
 p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x4;
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_0045ABD0[];
int func_002DC680(u8 *p) {
 u8 *slot=p+0x2B8;
 if (!func_00189310(p,D_0045ABD0,p+0x390)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 if (*slot) return 0;
 func_0018A990(p,p+0x390);
 p[5]=0; p[6]=0; p[7]=0; p[0x1fd]=0x4;
 func_00186A60(p,0x1d);
 return 1;
}
