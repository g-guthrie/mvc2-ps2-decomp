typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00304BA0(void);
extern void func_00305390(void);
extern void func_003053D0(void);
extern void func_003054F0(void);
extern void func_00305CC0(void);
extern void func_00306480(void);
extern void func_003065E0(void);
extern void func_00306770(void);
extern void func_003068C0(void);
extern void func_00306A70(void);
extern void func_00306B30(void);
extern void func_00308100(void);
extern void func_003082F0(void);
extern void func_00308550(void);
extern void func_00308870(void);
extern void func_003088A0(void);
extern void func_003088B0(void);
extern void func_00308910(void);
extern void func_00308970(void);
extern void func_003089E0(void);
extern void func_00308A70(void);
const Mvc2Callback D_0045CB70[28] = {
    func_003053D0,
    func_00304BA0,
    func_003054F0,
    func_00305CC0,
    func_003065E0,
    func_00306770,
    func_003068C0,
    func_00306A70,
    func_00306B30,
    func_003082F0,
    func_00308550,
    func_00308870,
    func_003088A0,
    func_00305390,
    func_00308100,
    func_00306480,
    func_003088B0,
    func_00308910,
    func_00308970,
    func_003089E0,
    0,
    0,
    0,
    func_00308A70,
    0,
    0,
    0,
    0,
};
