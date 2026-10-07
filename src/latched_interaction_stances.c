/* Consume the interaction latch before selecting the requested stance. */
typedef unsigned char u8;
extern u8 D_00450580[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_002085C0(u8 *p) {
    if (!func_00189310(p,D_00450580,p+0x3A8)) return 0;
    if (!p[0x210]) {
        if (*(signed char *)(p+0x1e8)) return 0;
        p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
    }
    func_0018A990(p,p+0x3A8);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x7;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00450550[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_00208820(u8 *p) {
    if (!func_00189310(p,D_00450550,p+0x3D0)) return 0;
    if (!p[0x210]) {
        if (*(signed char *)(p+0x1e8)) return 0;
        p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
    }
    func_0018A990(p,p+0x3D0);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0xB;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00451460[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_00222CE0(u8 *p) {
    if (!func_00189310(p,D_00451460,p+0x398)) return 0;
    if (!p[0x210]) {
        if (*(signed char *)(p+0x1e8)) return 0;
        p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
    }
    func_0018A990(p,p+0x398);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x4;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00459270[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_002B8400(u8 *p) {
    if (!func_00189310(p,D_00459270,p+0x390)) return 0;
    if (!p[0x210]) {
        if (*(signed char *)(p+0x1e8)) return 0;
        p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
    }
    func_0018A990(p,p+0x390);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x9;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_004592C0[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_002B85F0(u8 *p) {
    if (!func_00189310(p,D_004592C0,p+0x3B0)) return 0;
    if (!p[0x210]) {
        if (*(signed char *)(p+0x1e8)) return 0;
        p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
    }
    func_0018A990(p,p+0x3B0);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x8;
    func_00186A60(p,0x15);
    return 1;
}
