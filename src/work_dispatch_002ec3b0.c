/* func_002EC3B0: phase dispatch through the two-entry $gp table jtbl_004C11A0
 * (src/data/jtbl_004C11A0.c: func_002EC1F0, func_002EC390). Both entries are
 * defined in src/composite_gp_dispatch_heads.c as void f(u8 *p, u8 *context).
 * Phase byte p[6] is 0 or 1; owner flag 0x20D == 2 forces phase 1. */
typedef unsigned char u8;
typedef void (*WorkPhaseCallback)(u8 *p, u8 *context);
extern const WorkPhaseCallback jtbl_004C11A0[2] __attribute__((section(".sdata")));
void func_002EC3B0(u8 *p, u8 *context) {
    if (p[0x20d] == 2) p[6] = 1;
    jtbl_004C11A0[p[6]](p, context);
}
