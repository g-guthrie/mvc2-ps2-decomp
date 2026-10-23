typedef unsigned char u8;
typedef void (*Callback)(u8 *, u8 *);
extern void func_00242A20(u8 *, u8 *);
extern void func_00242AA0(u8 *, u8 *);
extern void func_00242C60(u8 *, u8 *);
Callback const jtbl_00452A98[3] = {
    func_00242A20,
    func_00242AA0,
    func_00242C60,
};
