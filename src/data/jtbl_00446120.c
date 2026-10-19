typedef unsigned char u8;
typedef signed int s32;
typedef s32 (*StateHandler)(u8 *, s32);
extern s32 func_00168EE0(u8 *, s32);
extern s32 func_00168EF0(u8 *, s32);
extern s32 func_00168F00(u8 *, s32);
extern s32 func_00168F70(u8 *, s32);
extern s32 func_00169060(u8 *, s32);
extern s32 func_001690F0(u8 *, s32);
extern s32 func_00169180(u8 *, s32);
extern s32 func_00169210(u8 *, s32);
extern s32 func_001692A0(u8 *, s32);
extern s32 func_00169310(u8 *, s32);
extern s32 func_00169380(u8 *, s32);
extern s32 func_00169400(u8 *, s32);
extern s32 func_00169470(u8 *, s32);

const StateHandler jtbl_00446120[14] = {
    func_00168EE0,
    func_00168EF0,
    func_00168F00,
    func_00168F70,
    func_00168F70,
    func_00169060,
    func_001690F0,
    func_00169180,
    func_00169210,
    func_001692A0,
    func_00169310,
    func_00169380,
    func_00169400,
    func_00169470,
};
