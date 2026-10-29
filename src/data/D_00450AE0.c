typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002104B0(void);
extern void func_00210B50(void);
extern void func_00210C70(void);
extern void func_00210CA0(void);
extern void func_00211520(void);
extern void func_002119D0(void);
extern void func_00211B50(void);
extern void func_00211D40(void);
extern void func_00211E70(void);
extern void func_002120D0(void);
extern void func_00212370(void);
extern void func_002146B0(void);
extern void func_002148A0(void);
extern void func_00214A70(void);
extern void func_00214D10(void);
extern void func_00215A00(void);
extern void func_00215A70(void);
extern void func_00215AD0(void);
extern void func_00215B30(void);
extern void func_00215BA0(void);
const Mvc2Callback D_00450AE0[28] = {
    func_00210C70,
    func_002104B0,
    func_00210CA0,
    func_00211520,
    func_00211B50,
    func_00211D40,
    func_00211E70,
    func_002120D0,
    func_00212370,
    func_002148A0,
    func_00214A70,
    func_00214D10,
    func_00215A00,
    func_00210B50,
    func_002146B0,
    func_002119D0,
    func_00215A70,
    func_00215AD0,
    func_00215B30,
    func_00215BA0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
