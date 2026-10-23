typedef unsigned char u8;
typedef void (*Callback)(u8 *, u8 *, u8 *);
extern void func_001A5810(u8 *, u8 *, u8 *);
extern void func_001A5880(u8 *, u8 *, u8 *);
Callback const jtbl_004BF750[2] = {
    func_001A5810,
    func_001A5880,
};
