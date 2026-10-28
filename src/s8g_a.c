/* Sony EE GCC 2.9 (./trysony29.sh src/s8g_a.c 0 O2): double bit pattern -> int with 9999 clamp.
   The low-word sign extension is formed per branch (y = x << 32) and shifted back once, so
   cross-jumping leaves dsll32 at the join and the lone dsra32 fills the return slot. */
typedef unsigned long long u64;
typedef long long s64;
typedef int s32;

s64 func_00105660(u64 x) {
    s64 e;
    s64 y;
    e = (x << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    x = (x << 12) >> 12;
    x |= 1ULL << 52;
    if (e < 0) {
        e = -e;
        x >>= (s32)(e - 2);
        if ((x & 3) == 3) {
            x = (x >> 2) + 1;
            y = x << 32;
        } else {
            x >>= 2;
            y = x << 32;
        }
    } else {
        x <<= (s32)e;
        y = x << 32;
    }
    return y >> 32;
}
