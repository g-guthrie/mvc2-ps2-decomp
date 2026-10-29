typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00294E60(void);
extern void func_002959A0(void);
extern void func_002959B0(void);
extern void func_00296270(void);
extern void func_002968C0(void);
extern void func_002969F0(void);
extern void func_00296BD0(void);
extern void func_00296DC0(void);
extern void func_00296E60(void);
extern void func_00296F90(void);
extern void func_0029A240(void);
extern void func_0029A3B0(void);
extern void func_0029A670(void);
extern void func_0029AAD0(void);
extern void func_0029AB10(void);
extern void func_0029AD10(void);
extern void func_0029AD70(void);
extern void func_0029ADD0(void);
extern void func_0029AE40(void);
extern void func_0029AEB0(void);
const Mvc2Callback D_00457D60[28] = {
    func_002959A0,
    func_00294E60,
    func_002959B0,
    func_00296270,
    func_002969F0,
    func_00296BD0,
    func_00296DC0,
    func_00296E60,
    func_00296F90,
    func_0029A240,
    func_0029A3B0,
    func_0029A670,
    func_0029AAD0,
    func_0029AB10,
    func_0029AEB0,
    func_002968C0,
    func_0029AD10,
    func_0029AD70,
    func_0029ADD0,
    func_0029AE40,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
