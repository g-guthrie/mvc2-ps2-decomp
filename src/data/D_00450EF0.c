typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00215CC0(void);
extern void func_002163F0(void);
extern void func_00216570(void);
extern void func_002165C0(void);
extern void func_00216DA0(void);
extern void func_00217920(void);
extern void func_00217A40(void);
extern void func_00217BA0(void);
extern void func_00217D60(void);
extern void func_00218090(void);
extern void func_00218270(void);
extern void func_0021B4D0(void);
extern void func_0021B530(void);
extern void func_0021B590(void);
extern void func_0021B610(void);
extern void func_0021B690(void);
extern void func_0021B820(void);
extern void func_0021B900(void);
extern void func_0021BAB0(void);
extern void func_0021C900(void);
const Mvc2Callback D_00450EF0[28] = {
    func_00216570,
    func_00215CC0,
    func_002165C0,
    func_00216DA0,
    func_00217A40,
    func_00217BA0,
    func_00217D60,
    func_00218090,
    func_00218270,
    func_0021B820,
    func_0021B900,
    func_0021BAB0,
    func_0021C900,
    func_002163F0,
    func_0021B690,
    func_00217920,
    func_0021B4D0,
    func_0021B530,
    func_0021B590,
    func_0021B610,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
