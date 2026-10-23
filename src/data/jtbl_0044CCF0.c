typedef unsigned char u8;
typedef void (*OwnerCallback)(u8 *, u8 *);
extern void func_001C59D0(u8 *, u8 *);
extern void func_001C5AD0(u8 *, u8 *);
extern void func_001C5B50(u8 *, u8 *);
extern void func_001C5BC0(u8 *, u8 *);
extern void func_001C5CB0(u8 *, u8 *);
extern void func_001C5D50(u8 *, u8 *);
OwnerCallback const jtbl_0044CCF0[6] = {
    func_001C59D0,
    func_001C5AD0,
    func_001C5B50,
    func_001C5BC0,
    func_001C5CB0,
    func_001C5D50,
};
