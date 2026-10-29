typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002B26E0(void);
extern void func_002B2E30(void);
extern void func_002B3120(void);
extern void func_002B3130(void);
extern void func_002B3920(void);
extern void func_002B3DA0(void);
extern void func_002B3EC0(void);
extern void func_002B4130(void);
extern void func_002B4390(void);
extern void func_002B4970(void);
extern void func_002B4AE0(void);
extern void func_002B4CC0(void);
extern void func_002B7920(void);
extern void func_002B7A90(void);
extern void func_002B7CE0(void);
extern void func_002B7FB0(void);
extern void func_002B7FC0(void);
extern void func_002B8020(void);
extern void func_002B8080(void);
extern void func_002B80E0(void);
const Mvc2Callback D_00458F50[28] = {
    func_002B3120,
    func_002B26E0,
    func_002B3130,
    func_002B3920,
    func_002B3EC0,
    func_002B4130,
    func_002B4390,
    func_002B4970,
    func_002B4CC0,
    func_002B7920,
    func_002B7A90,
    func_002B7CE0,
    func_002B7FB0,
    func_002B2E30,
    func_002B4AE0,
    func_002B3DA0,
    func_002B7FC0,
    func_002B8020,
    func_002B8080,
    func_002B80E0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
