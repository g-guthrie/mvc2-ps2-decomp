typedef unsigned char u8;
typedef signed int s32;
typedef unsigned long long u64;
static s32 func_00420A00(s32 *p)
{
    s32 x = p[2];
    return (s32)((u8 *)p[4] + (x << 3) + 16);
}
static s32 func_00420A20(s32 *p, s32 a1) {
    s32 v = p[2] + a1;
    if (p[5] < v) return 0;
    p[2] = v;
    return 1;
}

s32 func_00420A50(s32 *p) {
    s32 r = func_00420A00(p);
    if (func_00420A20(p, 2) == 0) return 0;
    *p = r;
    *(u64 *)r = 0x1000000000000001ULL;
    *(u64 *)(r + 8) = 14;
    return 1;
}
