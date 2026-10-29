typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002F69E0(void);
extern void func_002F7190(void);
extern void func_002F7210(void);
extern void func_002F7570(void);
extern void func_002F7E10(void);
extern void func_002F8330(void);
extern void func_002F8450(void);
extern void func_002F8680(void);
extern void func_002F8890(void);
extern void func_002F8B90(void);
extern void func_002F8DB0(void);
extern void func_002FB410(void);
extern void func_002FB690(void);
extern void func_002FBB60(void);
extern void func_002FBB90(void);
extern void func_002FBBE0(void);
extern void func_002FBC40(void);
extern void func_002FBCA0(void);
extern void func_002FBD10(void);
extern void residual_002FB0E0(void);
const Mvc2Callback D_0045BDA0[28] = {
    func_002F7210,
    func_002F69E0,
    func_002F7570,
    func_002F7E10,
    func_002F8450,
    func_002F8680,
    func_002F8890,
    func_002F8B90,
    func_002F8DB0,
    func_002FB410,
    func_002FB690,
    func_002FBB60,
    func_002FBB90,
    func_002F7190,
    residual_002FB0E0,
    func_002F8330,
    func_002FBBE0,
    func_002FBC40,
    func_002FBCA0,
    func_002FBD10,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
