typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0027D070(void);
extern void func_0027D6B0(void);
extern void func_0027D890(void);
extern void func_0027D8A0(void);
extern void func_0027D8B0(void);
extern void func_0027DAA0(void);
extern void func_0027DAB0(void);
extern void func_0027DBB0(void);
extern void func_0027DD30(void);
extern void func_0027FA60(void);
extern void func_0027FA70(void);
extern void func_0027FA80(void);
extern void func_0027FA90(void);
extern void func_0027FBB0(void);
const Mvc2Callback D_00455290[28] = {
    func_0027D6B0,
    func_0027D070,
    func_0027D890,
    func_0027D8A0,
    func_0027D8B0,
    func_0027DAA0,
    func_0027DAB0,
    func_0027DBB0,
    func_0027DD30,
    func_0027FA60,
    func_0027FA70,
    func_0027FA80,
    func_0027FA90,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    func_0027FBB0,
    0,
    0,
    0,
};
