typedef unsigned char u8;
typedef void (*AnimationHandler)(u8 *, u8 *);
extern void func_001A4CB0(u8 *, u8 *);
extern void func_001A4D60(u8 *, u8 *);
extern void func_001A4E10(u8 *);

const AnimationHandler jtbl_0044B2F8[3] = {
    func_001A4CB0,
    func_001A4D60,
    (AnimationHandler)func_001A4E10,
};
