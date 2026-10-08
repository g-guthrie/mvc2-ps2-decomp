/* Extract the signed high field stored in a packed 32-bit value. */
typedef signed int s32;
typedef signed long long s64;
typedef unsigned int u32;
typedef unsigned long long u64;

s32 func_0040A2F8(s32 *p) {
    s64 scaled = (s64)p[5] * 2048;
    return (s32)(scaled >> 32);
}

s32 func_0040A338(u32 *p) {
    s64 scaled = (s64)p[1] * 2048;
    return (s32)(scaled >> 32);
}

s32 func_0040BD98(u32 *p) {
    u64 bits = (u64)p[3] << 32;
    return (s32)((s64)bits >> 32);
}

s32 func_0040BDB0(u32 *p) {
    u64 bits = (u64)p[2] << 32;
    return (s32)((s64)bits >> 32);
}
