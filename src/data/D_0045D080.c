typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0030C6F0(void);
extern void func_0030CBF0(void);
extern void func_0030CDE0(void);
extern void func_0030D330(void);
extern void func_0030D700(void);
extern void func_0030D720(void);
extern void func_0030D840(void);
extern void func_0030DA10(void);
extern void func_0030DBE0(void);
extern void func_0030DC70(void);
extern void func_0030DDB0(void);
extern void func_0030F090(void);
extern void func_0030F260(void);
extern void func_0030F2E0(void);
extern void func_0030F400(void);
extern void func_0030F670(void);
extern void func_0030F6A0(void);
extern void func_0030F6D0(void);
extern void func_0030F700(void);
extern void func_0030F750(void);
const Mvc2Callback D_0045D080[28] = {
    func_0030CDE0,
    func_0030C6F0,
    func_0030D330,
    func_0030D700,
    func_0030D840,
    func_0030DA10,
    func_0030DBE0,
    func_0030DC70,
    func_0030DDB0,
    func_0030F260,
    func_0030F2E0,
    func_0030F400,
    func_0030F670,
    func_0030CBF0,
    func_0030F090,
    func_0030D720,
    func_0030F6A0,
    func_0030F6D0,
    func_0030F700,
    func_0030F750,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
