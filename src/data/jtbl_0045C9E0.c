/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_0045C9E0). */
typedef unsigned char u8;
typedef void (*ContextCallback)(u8 *, u8 *);

extern void func_00302CA0(u8 *, u8 *);
extern void func_00302D80(u8 *, u8 *);
extern void func_00302DE0(u8 *, u8 *);
extern void func_00302E50(u8 *, u8 *);
extern void func_00302ED0(u8 *, u8 *);

const ContextCallback jtbl_0045C9E0[5] = {
    func_00302CA0,
    func_00302D80,
    func_00302DE0,
    func_00302E50,
    func_00302ED0,
};
