typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002C51A0(void);
extern void func_002C5B40(void);
extern void func_002C5CF0(void);
extern void func_002C5DE0(void);
extern void func_002C6620(void);
extern void func_002C6E20(void);
extern void func_002C6F60(void);
extern void func_002C7180(void);
extern void func_002C7340(void);
extern void func_002C75C0(void);
extern void func_002C7A50(void);
extern void func_002CB500(void);
extern void func_002CB6E0(void);
extern void func_002CB820(void);
extern void func_002CB9E0(void);
extern void func_002CBB40(void);
extern void func_002CBB50(void);
extern void func_002CBBB0(void);
extern void func_002CBC10(void);
extern void func_002CBC80(void);
const Mvc2Callback D_00459D10[28] = {
    func_002C5CF0,
    func_002C51A0,
    func_002C5DE0,
    func_002C6620,
    func_002C6F60,
    func_002C7180,
    func_002C7340,
    func_002C75C0,
    func_002C7A50,
    func_002CB6E0,
    func_002CB820,
    func_002CB9E0,
    func_002CBB40,
    func_002C5B40,
    func_002CB500,
    func_002C6E20,
    func_002CBB50,
    func_002CBBB0,
    func_002CBC10,
    func_002CBC80,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
