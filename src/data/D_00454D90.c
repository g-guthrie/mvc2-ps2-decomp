typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00278300(void);
extern void func_00278670(void);
extern void func_00278680(void);
extern void func_00278BA0(void);
extern void func_00278D00(void);
extern void func_00278D20(void);
extern void func_00278D30(void);
extern void func_00278D40(void);
extern void func_00279020(void);
extern void func_00279270(void);
extern void func_0027A8B0(void);
extern void func_0027AA60(void);
extern void func_0027AA70(void);
extern void func_0027AA80(void);
extern void func_0027AA90(void);
extern void func_0027AAA0(void);
extern void func_0027AB00(void);
extern void func_0027AB60(void);
extern void func_0027ABD0(void);
extern void func_0027AC40(void);
const Mvc2Callback D_00454D90[28] = {
    func_00278680,
    func_00278300,
    func_00278BA0,
    func_00278D00,
    func_00278D20,
    func_00278D30,
    func_00278D40,
    func_00279020,
    func_00279270,
    func_0027AA60,
    func_0027AA70,
    func_0027AA80,
    func_0027AA90,
    func_00278670,
    func_0027A8B0,
    0,
    func_0027AAA0,
    func_0027AB00,
    func_0027AB60,
    func_0027ABD0,
    0,
    0,
    0,
    0,
    func_0027AC40,
    0,
    0,
    0,
};
