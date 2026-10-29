typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002E0DA0(void);
extern void func_002E13D0(void);
extern void func_002E1460(void);
extern void func_002E18D0(void);
extern void func_002E1BB0(void);
extern void func_002E1CF0(void);
extern void func_002E1E10(void);
extern void func_002E1FC0(void);
extern void func_002E2180(void);
extern void func_002E2230(void);
extern void func_002E2330(void);
extern void func_002E3570(void);
extern void func_002E3880(void);
extern void func_002E3920(void);
extern void func_002E3A10(void);
extern void func_002E3C00(void);
extern void func_002E3C10(void);
extern void func_002E3C70(void);
extern void func_002E3CD0(void);
extern void func_002E3D40(void);
const Mvc2Callback D_0045AF60[28] = {
    func_002E1460,
    func_002E0DA0,
    func_002E18D0,
    func_002E1BB0,
    func_002E1E10,
    func_002E1FC0,
    func_002E2180,
    func_002E2230,
    func_002E2330,
    func_002E3880,
    func_002E3920,
    func_002E3A10,
    func_002E3C00,
    func_002E13D0,
    func_002E3570,
    func_002E1CF0,
    func_002E3C10,
    func_002E3C70,
    func_002E3CD0,
    func_002E3D40,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
