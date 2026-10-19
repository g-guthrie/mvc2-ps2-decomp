typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern float func_00417440(unsigned int angle);
/* The two phase-byte writes and the intermediate signed conversion are native.
 * Preserve the ordered float operations used by this height adjustment. */
void func_003BD0A0(u8 *p) {
    u8 phase = ++p[0x22];
    p[0x22] = (s8)phase & 31;
    *(float *)(p + 0x38) += 2.142857074737549f * (((38400.0f * (1000.0f * func_00417440((s16)(((40 - p[0x22]) & 31) << 11)))) / 125000.0f) / 256.0f);
}
