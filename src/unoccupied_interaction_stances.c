/* Reject occupied child state before resetting the accepted interaction stance. */
typedef unsigned char u8;
extern u8 D_004505D0[];
extern int func_00189660(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_00208930(u8 *p) {
    u8 *state = p+0x2B8;
    if (!func_00189660(p,D_004505D0,p+0x3E0)) return 0;
    if (state[0x3]) return 0;
    func_0018A990(p,p+0x3E0);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0xE;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00451470[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_00222E30(u8 *p) {
    u8 *state = p+0x2B8;
    if (!func_00189310(p,D_00451470,p+0x378)) return 0;
    if (state[0x0]) return 0;
    func_0018A990(p,p+0x378);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x3;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00453150[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_0024D9B0(u8 *p) {
    u8 *state = p+0x2B8;
    if (!func_00189310(p,D_00453150,p+0x388)) return 0;
    if (state[0x1]) return 0;
    func_0018A990(p,p+0x388);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x1;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_00453160[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_0024DA40(u8 *p) {
    u8 *state = p+0x2B8;
    if (!func_00189310(p,D_00453160,p+0x390)) return 0;
    if (state[0x2]) return 0;
    func_0018A990(p,p+0x390);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0x2;
    func_00186A60(p,0x15);
    return 1;
}
extern u8 D_0045AB90[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
int func_002DC4F0(u8 *p) {
    u8 *state = p+0x2B8;
    if (!func_00189310(p,D_0045AB90,p+0x388)) return 0;
    if (state[0x0]) return 0;
    func_0018A990(p,p+0x388);
    p[5]=0; p[6]=0; p[7]=0; p[0x1fd]=0x1;
    func_00186A60(p,0x15);
    return 1;
}
