typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002483F0(void);
extern void func_00248850(void);
extern void func_00248950(void);
extern void func_00248960(void);
extern void func_00249160(void);
extern void func_00249D00(void);
extern void func_00249F10(void);
extern void func_0024A0D0(void);
extern void func_0024A300(void);
extern void func_0024A540(void);
extern void func_0024A7A0(void);
extern void func_0024B000(void);
extern void func_0024C8E0(void);
extern void func_0024CEF0(void);
extern void func_0024D030(void);
extern void func_0024D1B0(void);
extern void func_0024D460(void);
extern void func_0024D4A0(void);
extern void func_0024D500(void);
extern void func_0024D560(void);
extern void func_0024D5C0(void);
extern void func_0024D620(void);
const Mvc2Callback D_00452E60[28] = {
    func_00248950,
    func_002483F0,
    func_00248960,
    func_00249160,
    func_00249F10,
    func_0024A300,
    func_0024A540,
    func_0024A7A0,
    func_0024B000,
    func_0024CEF0,
    func_0024D030,
    func_0024D1B0,
    func_0024D460,
    func_00248850,
    func_0024C8E0,
    func_00249D00,
    func_0024D4A0,
    func_0024D500,
    func_0024D560,
    func_0024D5C0,
    0,
    func_0024A0D0,
    0,
    func_0024D620,
    0,
    0,
    0,
    0,
};
