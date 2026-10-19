typedef unsigned char u8;
typedef void (*Mvc2StateHandler)(u8 *);
extern void func_0013AA00(u8 *);
extern void func_0013AC00(u8 *);
extern void func_0013AC90(u8 *);
extern void func_0013ABC0(u8 *);

const Mvc2StateHandler jtbl_00440260[6] = {
    func_0013AA00,
    func_0013AA00,
    func_0013AC00,
    func_0013AC90,
    func_0013AA00,
    func_0013ABC0,
};
