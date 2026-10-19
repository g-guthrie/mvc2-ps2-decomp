/* Four reconstructed u8* state handlers selected by func_00176DC0. */
typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);

extern void func_00176DF0(u8 *);
extern void func_00176E20(u8 *);
extern void func_001794A0(u8 *);
extern void func_00179500(u8 *);

const StateHandler jtbl_004BF4C0[4] = {
    func_00176DF0,
    func_00176E20,
    func_001794A0,
    func_00179500,
};
