/* Require a live accepted owner before resetting the stance transition. */
typedef unsigned char u8;
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_00226650(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0x1A; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_00248780(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0x6; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_002D95D0(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0xB; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_002EE0A0(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0xE; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_0030CB80(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0xA; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
extern int func_00189150(u8 *);
extern void func_00186A60(u8 *,int);
int func_003226E0(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x1fd]=0x2; p[5]=0; p[7]=0; p[6]=0;
    func_00186A60(p,0x1D);
    return 1;
}
