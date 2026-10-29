typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002A0C60(void);
extern void func_002A1270(void);
extern void func_002A1410(void);
extern void func_002A1420(void);
extern void func_002A1D00(void);
extern void func_002A2330(void);
extern void func_002A2450(void);
extern void func_002A2730(void);
extern void func_002A2A00(void);
extern void func_002A2A80(void);
extern void func_002A2CC0(void);
extern void func_002A5AA0(void);
extern void func_002A5B70(void);
extern void func_002A5CE0(void);
extern void func_002A5F20(void);
extern void func_002A6B00(void);
extern void func_002A6CE0(void);
extern void func_002A6D40(void);
extern void func_002A6DA0(void);
extern void func_002A6E10(void);
extern void func_002A6E80(void);
const Mvc2Callback D_004583B0[28] = {
    func_002A1410,
    func_002A0C60,
    func_002A1420,
    func_002A1D00,
    func_002A2450,
    func_002A2730,
    func_002A2A00,
    func_002A2A80,
    func_002A2CC0,
    func_002A5B70,
    func_002A5CE0,
    func_002A5F20,
    func_002A5AA0,
    func_002A1270,
    func_002A6B00,
    func_002A2330,
    func_002A6CE0,
    func_002A6D40,
    func_002A6DA0,
    func_002A6E10,
    0,
    0,
    func_002A6E80,
    0,
    0,
    0,
    0,
    0,
};
