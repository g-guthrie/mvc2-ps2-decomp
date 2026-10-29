typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002BFBC0(void);
extern void func_002C04F0(void);
extern void func_002C05F0(void);
extern void func_002C0670(void);
extern void func_002C1270(void);
extern void func_002C1D30(void);
extern void func_002C1E60(void);
extern void func_002C2020(void);
extern void func_002C21E0(void);
extern void func_002C2280(void);
extern void func_002C2570(void);
extern void func_002C42C0(void);
extern void func_002C44A0(void);
extern void func_002C4610(void);
extern void func_002C4890(void);
extern void func_002C4E40(void);
extern void func_002C4E90(void);
extern void func_002C4EF0(void);
extern void func_002C4F50(void);
extern void func_002C4FC0(void);
extern void func_002C5030(void);
const Mvc2Callback D_00459920[28] = {
    func_002C05F0,
    func_002BFBC0,
    func_002C0670,
    func_002C1270,
    func_002C1E60,
    func_002C2020,
    func_002C21E0,
    func_002C2280,
    func_002C2570,
    func_002C44A0,
    func_002C4610,
    func_002C4890,
    func_002C4E40,
    func_002C04F0,
    func_002C42C0,
    func_002C1D30,
    func_002C4E90,
    func_002C4EF0,
    func_002C4F50,
    func_002C4FC0,
    0,
    0,
    0,
    0,
    func_002C5030,
    0,
    0,
    0,
};
