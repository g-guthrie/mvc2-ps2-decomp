/* Accept an interaction once and reset the common transition state. */
typedef unsigned char u8;
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *), func_00186A60(u8 *,int);
extern u8 D_00450A60[];
int func_00210750(u8 *p) {
    int result = 0;
    if (!func_00189310(p,D_00450A60,p+0x378)) return result;
    if (p[0x20d] == 2) {
        if (!p[0x210]) {
            if (*(signed char *)(p+0x1e8)) return result;
            p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
        }
    }
    func_0018A990(p,p+0x378);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0;
    func_00186A60(p,21);
    return 1;
}
extern u8 D_00452E10[];
int func_002484E0(u8 *p) {
    int result = 0;
    if (!func_00189310(p,D_00452E10,p+0x378)) return result;
    if (p[0x20d] == 2) {
        if (!p[0x210]) {
            if (*(signed char *)(p+0x1e8)) return result;
            p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
        }
    }
    func_0018A990(p,p+0x378);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0;
    func_00186A60(p,21);
    return 1;
}
extern u8 D_00456CF0[];
int func_0028DC70(u8 *p) {
    int result = 0;
    if (!func_00189310(p,D_00456CF0,p+0x378)) return result;
    if (p[0x20d] == 2) {
        if (!p[0x210]) {
            if (*(signed char *)(p+0x1e8)) return result;
            p[0x1e8] = *(signed char *)(p+0x1e8) + 1;
        }
    }
    func_0018A990(p,p+0x378);
    p[5]=0; p[7]=0; p[6]=0; p[0x1fd]=0;
    func_00186A60(p,21);
    return 1;
}
