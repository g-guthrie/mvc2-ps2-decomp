typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002436F0(void);
extern void func_00243CD0(void);
extern void func_00243E50(void);
extern void func_00243EE0(void);
extern void func_00244790(void);
extern void func_00245140(void);
extern void func_002452C0(void);
extern void func_00245470(void);
extern void func_00245620(void);
extern void func_00245B70(void);
extern void func_00245D80(void);
extern void func_00247890(void);
extern void func_00247A10(void);
extern void func_00247CB0(void);
extern void func_002480D0(void);
extern void func_00248110(void);
extern void func_00248140(void);
extern void func_002481A0(void);
extern void func_00248200(void);
extern void func_00248260(void);
const Mvc2Callback D_00452BC0[28] = {
    func_00243E50,
    func_002436F0,
    func_00243EE0,
    func_00244790,
    func_002452C0,
    func_00245470,
    func_00245620,
    func_00245B70,
    func_00247890,
    func_00247A10,
    func_00247CB0,
    func_002480D0,
    func_00248110,
    func_00243CD0,
    func_00245D80,
    func_00245140,
    func_00248140,
    func_002481A0,
    func_00248200,
    func_00248260,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
