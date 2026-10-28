/* func_003B2380: copies the owner's byte 0x24 and dispatches on phase p[5]
 * through jtbl_00473D80, which is entries 4..6 of jtbl_00473D70
 * (src/data/jtbl_00473D70.c): func_003B23B0 (still an assembly residual), func_003B24E0 (src/g0.c) and
 * func_003B2560 (src/wave14.c), each void f(u8 *p, u8 *owner). */
typedef unsigned char u8;
typedef signed char s8;
typedef void (*OwnerPhaseCallback)(u8 *p, u8 *owner);
extern OwnerPhaseCallback const jtbl_00473D80[3];
void func_003B2380(u8 *p, u8 *owner) {
    p[0x24] = *(s8 *)(owner + 0x24);
    jtbl_00473D80[p[5]](p, owner);
}
