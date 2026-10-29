typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002CBDA0(void);
extern void func_002CC450(void);
extern void func_002CC460(void);
extern void func_002CCCE0(void);
extern void func_002CD190(void);
extern void func_002CD2C0(void);
extern void func_002CD4E0(void);
extern void func_002CD720(void);
extern void func_002CD7A0(void);
extern void func_002CD8C0(void);
extern void func_002D0340(void);
extern void func_002D04B0(void);
extern void func_002D06E0(void);
extern void func_002D0D50(void);
extern void func_002D0ED0(void);
extern void func_002D0F10(void);
extern void func_002D0F70(void);
extern void func_002D0FD0(void);
extern void func_002D1040(void);
extern void func_002D10B0(void);
const Mvc2Callback D_0045A070[28] = {
    func_002CC450,
    func_002CBDA0,
    func_002CC460,
    func_002CCCE0,
    func_002CD2C0,
    func_002CD4E0,
    func_002CD720,
    func_002CD7A0,
    func_002CD8C0,
    func_002D0340,
    func_002D04B0,
    func_002D06E0,
    func_002D0ED0,
    func_002D0D50,
    func_002D10B0,
    func_002CD190,
    func_002D0F10,
    func_002D0F70,
    func_002D0FD0,
    func_002D1040,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
