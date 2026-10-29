typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002DC390(void);
extern void func_002DC890(void);
extern void func_002DCA10(void);
extern void func_002DCA20(void);
extern void func_002DD120(void);
extern void func_002DD540(void);
extern void func_002DD660(void);
extern void func_002DD870(void);
extern void func_002DDA60(void);
extern void func_002DDB90(void);
extern void func_002DDE30(void);
extern void func_002E0170(void);
extern void func_002E01D0(void);
extern void func_002E0230(void);
extern void func_002E02A0(void);
extern void func_002E0310(void);
extern void func_002E0530(void);
extern void func_002E0600(void);
extern void func_002E0760(void);
extern void func_002E0C90(void);
const Mvc2Callback D_0045AC10[28] = {
    func_002DCA10,
    func_002DC390,
    func_002DCA20,
    func_002DD120,
    func_002DD660,
    func_002DD870,
    func_002DDA60,
    func_002DDB90,
    func_002DDE30,
    func_002E0530,
    func_002E0600,
    func_002E0760,
    func_002E0C90,
    func_002DC890,
    func_002E0310,
    func_002DD540,
    func_002E0170,
    func_002E01D0,
    func_002E0230,
    func_002E02A0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
