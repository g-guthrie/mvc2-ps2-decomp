typedef unsigned char u8;
typedef void (*StateHandler)(u8 *, u8 *);
extern void func_001A89F0(u8 *, u8 *);
extern void func_001A8A10(u8 *, u8 *);
extern void func_001A8B20(u8 *, u8 *);

const StateHandler jtbl_0044B548[3] = {
    func_001A89F0,
    func_001A8A10,
    func_001A8B20,
};
