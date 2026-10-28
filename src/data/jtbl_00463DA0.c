typedef unsigned char u8;
typedef signed int s32;
/* Owner-contact phase callbacks: (actor, owner, contact state). */
typedef void (*Mvc2OwnerContactCallback)(u8 *, u8 *, s32 *);
extern void func_0036E750(u8 *, u8 *, s32 *);
extern void func_0036E8D0(u8 *, u8 *, s32 *);
extern void func_0036E9C0(u8 *, u8 *, s32 *);
extern void func_0036E9E0(u8 *, u8 *, s32 *);
extern void func_0036EE40(u8 *, u8 *, s32 *);
extern void func_0036EF10(u8 *, u8 *, s32 *);
extern void func_0036F120(u8 *, u8 *, s32 *);
extern void func_0036F240(u8 *, u8 *, s32 *);
extern void func_0036F450(u8 *, u8 *, s32 *);
const Mvc2OwnerContactCallback jtbl_00463DA0[9] = {
    func_0036E750,
    func_0036E8D0,
    func_0036E9C0,
    func_0036E9E0,
    func_0036EE40,
    func_0036EF10,
    func_0036F120,
    func_0036F240,
    func_0036F450,
};
