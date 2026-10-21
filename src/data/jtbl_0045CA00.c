/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/indirect_dispatch.c (jtbl_0045CA00). */
typedef unsigned char u8;
typedef void (*ContextCallback)(u8 *, u8 *);

extern void func_00302F30(u8 *, u8 *);
extern void func_00303000(u8 *, u8 *);
extern void func_00303060(u8 *, u8 *);
extern void func_003030D0(u8 *, u8 *);
extern void func_00303140(u8 *, u8 *);

const ContextCallback jtbl_0045CA00[5] = {
    func_00302F30,
    func_00303000,
    func_00303060,
    func_003030D0,
    func_00303140,
};
