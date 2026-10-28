/* jtbl_004641B0 state reached from func_0037D220; context is the owner read from p+0x18. */
typedef unsigned char u8;
typedef unsigned int u32;
void func_0037D900(u8 *p, u8 *context) {
    p[4]++;
    p[0x13c] = 0;
    *(u32 *)(context + 0x2e4) = 0;
}
