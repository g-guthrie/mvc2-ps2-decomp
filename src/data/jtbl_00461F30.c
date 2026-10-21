/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_00461F30). */
typedef unsigned char u8;
typedef void (*ContextCallback)(u8 *,u8 *);

extern void func_00349780(u8 *,u8 *);
extern void func_00349950(u8 *,u8 *);
extern void func_00349B20(u8 *,u8 *);
extern void func_00349CA0(u8 *,u8 *);
extern void func_00349E80(u8 *,u8 *);
extern void func_0034A060(u8 *,u8 *);

const ContextCallback jtbl_00461F30[6] = {
    func_00349780,
    func_00349950,
    func_00349B20,
    func_00349CA0,
    func_00349E80,
    func_0034A060,
};
