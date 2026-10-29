typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00222AC0(void);
extern void func_00222F80(void);
extern void func_00223000(void);
extern void func_00223160(void);
extern void func_00223A10(void);
extern void func_00223F40(void);
extern void func_00224070(void);
extern void func_00224280(void);
extern void func_002244F0(void);
extern void func_002245B0(void);
extern void func_00224720(void);
extern void func_002255A0(void);
extern void func_00225710(void);
extern void func_002259F0(void);
extern void func_00225CA0(void);
extern void func_00225D20(void);
extern void func_00225D80(void);
extern void func_00225DE0(void);
extern void func_00225E50(void);
extern void func_00225EB0(void);
const Mvc2Callback D_00451490[28] = {
    func_00223000,
    func_00222AC0,
    func_00223160,
    func_00223A10,
    func_00224070,
    func_00224280,
    func_002244F0,
    func_002245B0,
    func_00224720,
    func_002255A0,
    func_00225710,
    func_002259F0,
    func_00225CA0,
    func_00222F80,
    func_00225EB0,
    func_00223F40,
    func_00225D20,
    func_00225D80,
    func_00225DE0,
    func_00225E50,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
