typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002E8CC0(void);
extern void func_002E92A0(void);
extern void func_002E93A0(void);
extern void func_002E9420(void);
extern void func_002E9DE0(void);
extern void func_002EAA10(void);
extern void func_002EAB50(void);
extern void func_002EAD20(void);
extern void func_002EB280(void);
extern void func_002EB420(void);
extern void func_002EB5F0(void);
extern void func_002ED090(void);
extern void func_002ED1E0(void);
extern void func_002ED400(void);
extern void func_002ED750(void);
extern void func_002ED790(void);
extern void func_002ED7C0(void);
extern void func_002ED820(void);
extern void func_002ED880(void);
extern void func_002ED8E0(void);
const Mvc2Callback D_0045B430[28] = {
    func_002E93A0,
    func_002E8CC0,
    func_002E9420,
    func_002E9DE0,
    func_002EAB50,
    func_002EAD20,
    func_002EB280,
    func_002EB420,
    func_002ED090,
    func_002ED1E0,
    func_002ED400,
    func_002ED750,
    func_002ED790,
    func_002E92A0,
    func_002EB5F0,
    func_002EAA10,
    func_002ED7C0,
    func_002ED820,
    func_002ED880,
    func_002ED8E0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
