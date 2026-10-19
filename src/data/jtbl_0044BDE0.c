typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);
extern void func_001B5700(u8 *);
extern void func_001B57D0(u8 *);
extern void func_001B58C0(u8 *);
extern void func_001B59A0(u8 *);
extern void func_001B59B0(u8 *);

const StateHandler jtbl_0044BDE0[5] = {
    func_001B5700,
    func_001B57D0,
    func_001B58C0,
    func_001B59A0,
    func_001B59B0,
};
