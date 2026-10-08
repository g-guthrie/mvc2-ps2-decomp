/* Extract the signed high field stored in a packed 32-bit value. */
typedef signed int s32;
typedef signed long long s64;

s32 func_0040A2F8(s32 *p) {
    s64 scaled = (s64)p[5] * 2048;
    return (s32)(scaled >> 32);
}
