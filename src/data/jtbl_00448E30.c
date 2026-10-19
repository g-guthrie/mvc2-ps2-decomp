typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);
extern void func_00185060(u8 *);
extern void func_00185080(u8 *);
extern void func_00185150(u8 *);
extern void func_00185180(u8 *);
extern void func_00185250(u8 *);
extern void func_00185290(u8 *);
extern void func_00185380(u8 *);

const StateHandler jtbl_00448E30[7] = {
    func_00185060,
    func_00185080,
    func_00185150,
    func_00185180,
    func_00185250,
    func_00185290,
    func_00185380,
};
