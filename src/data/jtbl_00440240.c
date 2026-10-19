typedef unsigned char u8;
typedef void (*Mvc2StateHandler)(u8 *);
extern void func_0013AA00(u8 *);
extern void func_0013AA10(u8 *);
extern void func_0013AAC0(u8 *);
extern void func_0013ABC0(u8 *);

const Mvc2StateHandler jtbl_00440240[6] = {
    func_0013AA00,
    func_0013AA00,
    func_0013AA10,
    func_0013AAC0,
    func_0013AA00,
    func_0013ABC0,
};
