typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_003006B0(void);
extern void func_00300B80(void);
extern void func_00300C00(void);
extern void func_00300C80(void);
extern void func_003015A0(void);
extern void func_00302090(void);
extern void func_003021D0(void);
extern void func_003023A0(void);
extern void func_00302910(void);
extern void func_00302AB0(void);
extern void func_00302C80(void);
extern void func_00304230(void);
extern void func_00304380(void);
extern void func_003045A0(void);
extern void func_003048E0(void);
extern void func_00304920(void);
extern void func_00304950(void);
extern void func_003049B0(void);
extern void func_00304A10(void);
extern void func_00304A80(void);
const Mvc2Callback D_0045C870[28] = {
    func_00300C00,
    func_003006B0,
    func_00300C80,
    func_003015A0,
    func_003021D0,
    func_003023A0,
    func_00302910,
    func_00302AB0,
    func_00304230,
    func_00304380,
    func_003045A0,
    func_003048E0,
    func_00304920,
    func_00300B80,
    func_00302C80,
    func_00302090,
    func_00304950,
    func_003049B0,
    func_00304A10,
    func_00304A80,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
