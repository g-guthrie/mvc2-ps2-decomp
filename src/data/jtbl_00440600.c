typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);
extern void func_0013DD80(u8 *);
extern void func_0013DDC0(u8 *);
extern void func_0013DEC0(u8 *);
extern void func_0013DF10(u8 *);
extern void func_0013DFA0(void);

const StateHandler jtbl_00440600[5] = {
    func_0013DD80,
    func_0013DDC0,
    func_0013DEC0,
    func_0013DF10,
    (StateHandler)func_0013DFA0,
};
