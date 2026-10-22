typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001D28A0(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 t;
    u32 n;
    f32 f2;
    u8 *a4;
    if (q[5] != 0 || q[0x1E4] != 0x1D || q[0x1FD] != 3) {
        goto L29D8;
    }
    t = *(s8 *)(q + 0x1B2);
    if (t != 0 && ((s8)t & 1) == 0 && p[0x23] == 0) {
        *(s8 *)(p + 0x13C) = 1;
        f2 = 26.666666030883789f;
        a4 = *(u8 **)(q + 0x1C4);
        if (p[0x20] != 0) {
            f2 = -f2;
        }
        *(f32 *)(p + 0x34) = *(f32 *)(a4 + 0x34) + f2;
        *(f32 *)(p + 0x38) = 68.57142639160156f + *(f32 *)(a4 + 0x38);
    }
    if (*(s8 *)(p + 0x13C) == 0) {
        goto end;
    }
    if (p[5] == 0) {
        if ((s8)func_00175700(p) >= 0) {
            goto end;
        }
        if (*(s8 *)(q + 0x1B4) != 0) {
            goto end;
        }
        if (p[0x21] == 0) {
            n = p[5];
            p[5] = n + 1;
            func_001757E0(p, 0x17, 0x17);
            return;
        }
        goto L29D8;
    }
    if ((s8)func_00175700(p) >= 0) {
        goto end;
    }
L29D8:
    n = p[4];
    p[4] = n + 1;
    *(s8 *)(p + 0x13C) = 0;
end:
    return;
}
