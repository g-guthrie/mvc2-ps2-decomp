typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00233320(void);
extern void func_002339E0(void);
extern void func_00233B60(void);
extern void func_00233BE0(void);
extern void func_002342E0(void);
extern void func_00234640(void);
extern void func_00234790(void);
extern void func_002349A0(void);
extern void func_00234B60(void);
extern void func_00235160(void);
extern void func_002355B0(void);
extern void func_00238E90(void);
extern void func_00238EB0(void);
extern void func_00238ED0(void);
extern void func_00238F40(void);
extern void func_00238FB0(void);
extern void func_00239190(void);
extern void func_002394F0(void);
extern void func_002395C0(void);
extern void func_00239700(void);
extern void func_00239C30(void);
const Mvc2Callback D_004521F0[28] = {
    func_00233B60,
    func_00233320,
    func_00233BE0,
    func_002342E0,
    func_00234790,
    func_002349A0,
    func_00234B60,
    func_00235160,
    func_002355B0,
    func_002394F0,
    func_002395C0,
    func_00239700,
    func_00239C30,
    func_002339E0,
    func_00238FB0,
    func_00234640,
    func_00238E90,
    func_00238EB0,
    func_00238ED0,
    func_00238F40,
    0,
    func_00239190,
    0,
    0,
    0,
    0,
    0,
    0,
};
