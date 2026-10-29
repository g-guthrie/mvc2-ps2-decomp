typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0029B150(void);
extern void func_0029B850(void);
extern void func_0029B9D0(void);
extern void func_0029B9E0(void);
extern void func_0029C340(void);
extern void func_0029CBE0(void);
extern void func_0029CD10(void);
extern void func_0029CF70(void);
extern void func_0029D1E0(void);
extern void func_0029D310(void);
extern void func_0029D650(void);
extern void func_002A0390(void);
extern void func_002A0560(void);
extern void func_002A05F0(void);
extern void func_002A0940(void);
extern void func_002A09E0(void);
extern void func_002A0A10(void);
extern void func_002A0A70(void);
extern void func_002A0AD0(void);
extern void func_002A0B40(void);
const Mvc2Callback D_004580D0[28] = {
    func_0029B9D0,
    func_0029B150,
    func_0029B9E0,
    func_0029C340,
    func_0029CD10,
    func_0029CF70,
    func_0029D1E0,
    func_0029D310,
    func_0029D650,
    func_002A0560,
    func_002A05F0,
    func_002A0940,
    func_002A09E0,
    func_0029B850,
    func_002A0390,
    func_0029CBE0,
    func_002A0A10,
    func_002A0A70,
    func_002A0AD0,
    func_002A0B40,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
