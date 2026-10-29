typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0028DB50(void);
extern void func_0028E3B0(void);
extern void func_0028E530(void);
extern void func_0028E5C0(void);
extern void func_0028EDB0(void);
extern void func_0028F290(void);
extern void func_0028F3B0(void);
extern void func_0028F5B0(void);
extern void func_0028F7C0(void);
extern void func_0028FFB0(void);
extern void func_00290A50(void);
extern void func_002942A0(void);
extern void func_00294460(void);
extern void func_002945A0(void);
extern void func_00294770(void);
extern void func_00294970(void);
extern void func_00294980(void);
extern void func_002949E0(void);
extern void func_00294A40(void);
extern void func_00294AB0(void);
extern void func_00294C50(void);
extern void func_00294CC0(void);
extern void func_00294D00(void);
const Mvc2Callback D_00457610[28] = {
    func_0028E530,
    func_0028DB50,
    func_0028E5C0,
    func_0028EDB0,
    func_0028F3B0,
    func_0028F5B0,
    func_0028F7C0,
    func_0028FFB0,
    func_00290A50,
    func_00294460,
    func_002945A0,
    func_00294770,
    func_00294970,
    func_0028E3B0,
    func_002942A0,
    func_0028F290,
    func_00294980,
    func_002949E0,
    func_00294A40,
    func_00294AB0,
    0,
    0,
    0,
    func_00294D00,
    func_00294C50,
    func_00294CC0,
    0,
    0,
};
