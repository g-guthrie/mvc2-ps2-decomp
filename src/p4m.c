typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* Local stand-in for the real callee: its body writes extra temporaries,
   which keeps $v1 out of the caller's register choice. */
static char *func_003F1F90(char *a, s32 b, s32 c) {
    s32 t = b * 5;
    return a + t + c * 7;
}

char *func_003F24D0(char *a, s32 idx, s32 c) {
    char *r = func_003F1F90(a, 0x800, c);
    char *q = r + 0xC;
    if (r == 0) return 0;
    return q + idx * 12;
}

char *func_003F2590(char *a, s32 idx, s32 c) {
    char *r = func_003F1F90(a, 0x8000, c);
    s32 off = idx << 4;
    if (r == 0) return 0;
    return (char *)((s32)(r + 0xC) + off);
}
