typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002544D0(void);
extern void func_00254C70(void);
extern void func_00254E80(void);
extern void func_00255660(void);
extern void func_00255670(void);
extern void func_00256E00(void);
extern void func_00258330(void);
extern void func_00258450(void);
extern void func_00258610(void);
extern void func_002587A0(void);
extern void func_00258B90(void);
extern void func_00259180(void);
extern void func_0025AF40(void);
extern void func_0025B420(void);
extern void func_0025B530(void);
extern void func_0025B7D0(void);
extern void func_0025BFB0(void);
extern void func_0025BFF0(void);
extern void func_0025C050(void);
extern void func_0025C0B0(void);
extern void func_0025C120(void);
const Mvc2Callback D_00453620[28] = {
    func_00254E80,
    func_002544D0,
    func_00255670,
    func_00256E00,
    func_00258450,
    func_00258610,
    func_002587A0,
    func_00258B90,
    func_00259180,
    func_0025B420,
    func_0025B530,
    func_0025B7D0,
    func_0025BFB0,
    func_00254C70,
    func_0025AF40,
    func_00258330,
    func_0025BFF0,
    func_0025C050,
    func_0025C0B0,
    func_0025C120,
    0,
    0,
    0,
    0,
    func_00255660,
    0,
    0,
    0,
};
