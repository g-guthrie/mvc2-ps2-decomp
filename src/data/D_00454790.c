typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0026EEB0(void);
extern void func_0026F460(void);
extern void func_0026F580(void);
extern void func_0026F590(void);
extern void func_0026FD90(void);
extern void func_002701E0(void);
extern void func_00270310(void);
extern void func_00270500(void);
extern void func_002706F0(void);
extern void func_00270880(void);
extern void func_00270AF0(void);
extern void func_002728B0(void);
extern void func_00272A90(void);
extern void func_00272AE0(void);
extern void func_00272C20(void);
extern void func_00272E40(void);
extern void func_00273430(void);
extern void func_00273490(void);
extern void func_002734F0(void);
extern void func_00273560(void);
const Mvc2Callback D_00454790[28] = {
    func_0026F580,
    func_0026EEB0,
    func_0026F590,
    func_0026FD90,
    func_00270310,
    func_00270500,
    func_002706F0,
    func_00270880,
    func_00270AF0,
    func_00272AE0,
    func_00272C20,
    func_00272E40,
    func_00272A90,
    func_0026F460,
    func_002728B0,
    func_002701E0,
    func_00273430,
    func_00273490,
    func_002734F0,
    func_00273560,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
