typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0025C290(void);
extern void func_0025C930(void);
extern void func_0025CB20(void);
extern void func_0025CB30(void);
extern void func_0025D390(void);
extern void func_0025D970(void);
extern void func_0025DAA0(void);
extern void func_0025DD30(void);
extern void func_0025DFC0(void);
extern void func_0025E0B0(void);
extern void func_0025E420(void);
extern void func_00261930(void);
extern void func_00261AF0(void);
extern void func_00261C30(void);
extern void func_00261DA0(void);
extern void func_00261F60(void);
extern void func_00261FB0(void);
extern void func_00262010(void);
extern void func_00262070(void);
extern void func_002620E0(void);
const Mvc2Callback D_00453DE0[28] = {
    func_0025CB20,
    func_0025C290,
    func_0025CB30,
    func_0025D390,
    func_0025DAA0,
    func_0025DD30,
    func_0025DFC0,
    func_0025E0B0,
    func_0025E420,
    func_00261AF0,
    func_00261C30,
    func_00261DA0,
    func_00261F60,
    func_0025C930,
    func_00261930,
    func_0025D970,
    func_00261FB0,
    func_00262010,
    func_00262070,
    func_002620E0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
