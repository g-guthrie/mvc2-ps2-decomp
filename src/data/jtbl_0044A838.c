typedef unsigned char u8;
typedef void (*StateHandler)(u8 *, u8 *);
extern void func_0019AD20(u8 *, u8 *);
extern void func_0019ADE0(u8 *, u8 *);
extern void func_0019AE90(u8 *, u8 *);

const StateHandler jtbl_0044A838[3] = {
    func_0019AD20,
    func_0019ADE0,
    func_0019AE90,
};
