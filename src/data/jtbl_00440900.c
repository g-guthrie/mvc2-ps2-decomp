typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);
extern void func_0013FB40(u8 *);
extern void func_0013FC20(u8 *);
extern void func_0013FCB0(u8 *);

const StateHandler jtbl_00440900[4] = {
    func_0013FB40,
    func_0013FC20,
    func_0013FCB0,
    func_0013FB40,
};
