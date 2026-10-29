typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00239D60(void);
extern void func_0023A280(void);
extern void func_0023A400(void);
extern void func_0023A5B0(void);
extern void func_0023AD70(void);
extern void func_0023B3B0(void);
extern void func_0023B650(void);
extern void func_0023B8B0(void);
extern void func_0023BA60(void);
extern void func_0023BD70(void);
extern void func_0023BF40(void);
extern void func_0023E880(void);
extern void func_0023E9A0(void);
extern void func_0023EB60(void);
extern void func_0023ED90(void);
extern void func_0023EDD0(void);
extern void func_0023EE00(void);
extern void func_0023EE60(void);
extern void func_0023EEC0(void);
extern void func_0023EF30(void);
const Mvc2Callback D_00452530[28] = {
    func_0023A400,
    func_00239D60,
    func_0023A5B0,
    func_0023AD70,
    func_0023B650,
    func_0023B8B0,
    func_0023BA60,
    func_0023BD70,
    func_0023E880,
    func_0023E9A0,
    func_0023EB60,
    func_0023ED90,
    func_0023EDD0,
    func_0023A280,
    func_0023BF40,
    func_0023B3B0,
    func_0023EE00,
    func_0023EE60,
    func_0023EEC0,
    func_0023EF30,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
