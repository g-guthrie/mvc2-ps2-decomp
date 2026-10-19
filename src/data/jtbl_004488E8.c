typedef unsigned char u8;
typedef void (*Mvc2StateHandler)(u8 *);
extern void func_00176A70(u8 *);
extern void func_00176AB0(u8 *);
extern void func_00176CF0(u8 *);

const Mvc2StateHandler jtbl_004488E8[3] = {
    func_00176A70,
    func_00176AB0,
    func_00176CF0,
};
