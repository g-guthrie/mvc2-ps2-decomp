typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00308CA0(void);
extern void func_00309140(void);
extern void func_00309350(void);
extern void func_003093A0(void);
extern void func_00309C00(void);
extern void func_0030A180(void);
extern void func_0030A2A0(void);
extern void func_0030A530(void);
extern void func_0030A6B0(void);
extern void func_0030A940(void);
extern void func_0030AA50(void);
extern void func_0030B960(void);
extern void func_0030BB40(void);
extern void func_0030BCA0(void);
extern void func_0030BF90(void);
extern void func_0030C430(void);
extern void func_0030C4A0(void);
extern void func_0030C500(void);
extern void func_0030C560(void);
extern void func_0030C5D0(void);
const Mvc2Callback D_0045CDB0[28] = {
    func_00309350,
    func_00308CA0,
    func_003093A0,
    func_00309C00,
    func_0030A2A0,
    func_0030A530,
    func_0030A6B0,
    func_0030A940,
    func_0030AA50,
    func_0030BB40,
    func_0030BCA0,
    func_0030BF90,
    func_0030C430,
    func_00309140,
    func_0030B960,
    func_0030A180,
    func_0030C4A0,
    func_0030C500,
    func_0030C560,
    func_0030C5D0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
