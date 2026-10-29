typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002FBE30(void);
extern void func_002FC2E0(void);
extern void func_002FC360(void);
extern void func_002FC750(void);
extern void func_002FC8E0(void);
extern void func_002FD0B0(void);
extern void func_002FD550(void);
extern void func_002FD660(void);
extern void func_002FD7B0(void);
extern void func_002FD980(void);
extern void func_002FDD30(void);
extern void func_002FDF40(void);
extern void func_002FF2A0(void);
extern void func_002FF3F0(void);
extern void func_002FF760(void);
extern void func_00300170(void);
extern void func_00300430(void);
extern void func_00300460(void);
extern void func_003004C0(void);
extern void func_00300520(void);
extern void func_00300590(void);
const Mvc2Callback D_0045C050[28] = {
    func_002FC360,
    func_002FBE30,
    func_002FC8E0,
    func_002FD0B0,
    func_002FD660,
    func_002FD7B0,
    func_002FD980,
    func_002FDD30,
    func_002FF2A0,
    func_002FF3F0,
    func_002FF760,
    func_00300170,
    func_00300430,
    func_002FC2E0,
    func_002FDF40,
    func_002FD550,
    func_00300460,
    func_003004C0,
    func_00300520,
    func_00300590,
    0,
    0,
    0,
    0,
    func_002FC750,
    0,
    0,
    0,
};
