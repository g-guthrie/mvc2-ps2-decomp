typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00203360(void);
extern void func_00203B00(void);
extern void func_00203CF0(void);
extern void func_00203D00(void);
extern void func_002047A0(void);
extern void func_00204D70(void);
extern void func_00204EA0(void);
extern void func_00205100(void);
extern void func_00205660(void);
extern void func_002057F0(void);
extern void func_002059E0(void);
extern void func_002078E0(void);
extern void func_00207AB0(void);
extern void func_00207AC0(void);
extern void func_00207BB0(void);
extern void func_00207E90(void);
extern void func_00207F10(void);
extern void func_00207F70(void);
extern void func_00207FD0(void);
extern void func_00208040(void);
const Mvc2Callback D_00450360[28] = {
    func_00203CF0,
    func_00203360,
    func_00203D00,
    func_002047A0,
    func_00204EA0,
    func_00205100,
    func_00205660,
    func_002057F0,
    func_002059E0,
    func_00207AB0,
    func_00207AC0,
    func_00207BB0,
    func_00207E90,
    func_00203B00,
    func_002078E0,
    func_00204D70,
    func_00207F10,
    func_00207F70,
    func_00207FD0,
    func_00208040,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
