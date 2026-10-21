/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/preaction_dispatch_heads.c (jtbl_00452358). */
typedef unsigned char u8;
typedef void (*ContextCallback)(u8 *, u8 *);

extern void func_002361F0(u8 *, u8 *);
extern void func_002362B0(u8 *, u8 *);
extern void func_00236350(u8 *, u8 *);

const ContextCallback jtbl_00452358[3] = {
    func_002361F0,
    func_002362B0,
    func_00236350,
};
