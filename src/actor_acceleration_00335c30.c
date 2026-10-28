/* One-argument state callback: dispatched as jtbl_004C1888[p[7]](p) in func_00335C10 (table word at 0x004C1888).
 * Starts after the dispatcher's alignment nop and ends at its own jr ra. */
typedef unsigned char u8;
void func_00335C30(u8 *p) {
    *(float *)(p + 0x68) = -0.20000000298023224f;
    p[7]++;
}
