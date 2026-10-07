/* Commit a live interaction and reset its phase counters. */
typedef unsigned char u8;
extern int func_00189310(u8 *,void *,u8 *);
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_0045A350[];
int func_002D16F0(u8 *p) {
 if (!func_00189310(p,D_0045A350,p+0x398)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 func_0018A990(p,p+0x398);
 p[0x1fd]=0x5;
 p[0x5]=0; p[0x7]=0; p[0x6]=0; 
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_0045A8F0[];
int func_002D9040(u8 *p) {
 if (!func_00189310(p,D_0045A8F0,p+0x398)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 func_0018A990(p,p+0x398);
 p[0x1fd]=0x5;
 p[0x5]=0; p[0x7]=0; p[0x6]=0; 
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_0045B770[];
int func_002EDDC0(u8 *p) {
 if (!func_00189310(p,D_0045B770,p+0x3B8)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 func_0018A990(p,p+0x3B8);
 p[0x1fd]=0xB;
 p[0x5]=0; p[0x7]=0; p[0x6]=0; 
 func_00186A60(p,0x1d);
 return 1;
}
extern u8 D_0045B760[];
int func_002EDE50(u8 *p) {
 if (!func_00189310(p,D_0045B760,p+0x3D0)) return 0;
 if (!**(signed char **)(p+0x420)) return 0;
 func_0018A990(p,p+0x3D0);
 p[0x1fd]=0xA;
 p[0x5]=0; p[0x7]=0; p[0x6]=0; 
 func_00186A60(p,0x1d);
 return 1;
}
