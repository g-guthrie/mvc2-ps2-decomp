/* func_001D4BC0: forces phase 2 (func_001D5660) unless the owner is in state 21
 * with a non-negative work byte, then dispatches on phase p[4] through the
 * three-entry jtbl_0044E4A0 (src/data/jtbl_0044E4A0.c): func_001D4C10,
 * func_001D4DB0 and func_001D5660, all defined as void f(u8 *p, void *owner). */
typedef unsigned char u8; typedef signed char s8;
typedef void (*OwnerPhaseCallback)(u8 *p, void *owner);
extern OwnerPhaseCallback const jtbl_0044E4A0[3];
void func_001D4BC0(u8 *p, void *context) {
    u8 *owner = context;
    u8 *work = owner + 0x2b8;
    if (owner[0x169] != 21 || *(s8 *)(work + 7) < 0) { p[4] = 2; p[0x13c] = 0; }
    jtbl_0044E4A0[p[4]](p, context);
}
