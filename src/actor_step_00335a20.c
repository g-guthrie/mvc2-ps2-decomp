/* One-argument state callback: dispatched as jtbl_004C1878[p[5]](p) in residual_00335A00 (table word at 0x004C1878).
 * Starts after the dispatcher's alignment nop and ends at its own jr ra. */
typedef unsigned char u8;
void func_00335A20(u8 *p){
 p[5]++;
 p[6]++;
 p[6]%=7;
}
