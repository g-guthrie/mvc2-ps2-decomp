typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0031B330(void);
extern void func_0031B860(void);
extern void func_0031B960(void);
extern void func_0031B9B0(void);
extern void func_0031C190(void);
extern void func_0031CE00(void);
extern void func_0031CF20(void);
extern void func_0031D080(void);
extern void func_0031D240(void);
extern void func_0031D570(void);
extern void func_0031D740(void);
extern void func_00320D90(void);
extern void func_00320DF0(void);
extern void func_00320E50(void);
extern void func_00320ED0(void);
extern void func_00320F40(void);
extern void func_003210D0(void);
extern void func_003211B0(void);
extern void func_00321360(void);
extern void func_003221B0(void);
const Mvc2Callback D_0045DA70[28] = {
    func_0031B960,
    func_0031B330,
    func_0031B9B0,
    func_0031C190,
    func_0031CF20,
    func_0031D080,
    func_0031D240,
    func_0031D570,
    func_0031D740,
    func_003210D0,
    func_003211B0,
    func_00321360,
    func_003221B0,
    func_0031B860,
    func_00320F40,
    func_0031CE00,
    func_00320D90,
    func_00320DF0,
    func_00320E50,
    func_00320ED0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
