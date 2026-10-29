typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002AC210(void);
extern void func_002AC370(void);
extern void func_002AC530(void);
extern void func_002AC590(void);
extern void func_002AC9C0(void);
extern void func_002AC9E0(void);
extern void func_002ACB50(void);
extern void func_002ACCB0(void);
extern void func_002AD010(void);
extern void func_002AD360(void);
extern void func_002AD820(void);
extern void func_002ADC00(void);
extern void func_002B19A0(void);
extern void func_002B1B70(void);
extern void func_002B1C20(void);
extern void func_002B1DE0(void);
extern void func_002B22F0(void);
extern void func_002B23B0(void);
extern void func_002B23F0(void);
extern void func_002B2430(void);
extern void func_002B24A0(void);
extern void func_002B2510(void);
extern void func_002B25F0(void);
const Mvc2Callback D_00458BA0[28] = {
    func_002AC530,
    func_002AC370,
    func_002AC9C0,
    func_002AC9E0,
    func_002ACCB0,
    func_002AD010,
    func_002AD360,
    func_002AD820,
    func_002ADC00,
    func_002B1B70,
    func_002B1C20,
    func_002B1DE0,
    func_002B22F0,
    func_002AC210,
    func_002B19A0,
    func_002ACB50,
    func_002B23B0,
    func_002B23F0,
    func_002B2430,
    func_002B24A0,
    0,
    0,
    0,
    0,
    func_002AC590,
    func_002B2510,
    func_002B25F0,
    0,
};
