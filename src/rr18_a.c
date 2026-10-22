typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001FC980(u8 *p) {
    extern void func_00175C00(u8 *, s32);
    extern void func_001E3270(u8 *, s32, f32);
    u8 *q = p + 0x2B8;
    u32 a1 = p[5];
    s32 v;
    if ((a1 != 0 || p[0x1E4] != 0x15) && (a1 != 0 || p[0x1E4] != 0x1D)) {
        v = (s8)q[0x12];
        if (v != 0) {
            v = v - 1;
            q[0x12] = v;
            if ((s8)v == 0) func_00175C00(p, 0);
        }
    }
    if ((s8)q[0x1C] != 0) {
        if (p[5] == 0) {
            a1 = p[0x1E4];
            if ((a1 == 0x1D && p[0x1FD] == 6) || a1 - 10 <= 1 || a1 == 0x1A) return;
        }
        q[0x1C] = 0;
        func_001E3270(p, 0x1F, 32.0f);
    }
    if ((s8)q[0x19] != 0) {
        if (p[5] != 0) {
            q[0x19] = 0;
        } else if (p[0x1E4] != 0x1A) {
            q[0x19] = 0;
        }
    }
}
