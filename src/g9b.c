typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_001757E0();

void func_0026DF70(u8 *p) {
    s32 a = *(s8 *)(p + 0x2BD);
    u8 *q = p + 0x2B8;
    if (a >= 0) {
        u32 b = *(u16 *)(p + 0x35C);
        if (b & 0x300) {
            if (p[0x1B7]) {
                if (b & 0x100) q[5] = a + 1;
            } else {
                if (b & 0x200) q[5] = a + 1;
            }
            if (*(s8 *)(q + 5) >= 5) q[5] = 5;
        }
    }
}


void func_001DC9D0(u8 *p, u8 *q) {
    u8 *t;
    s32 v = 7;
    if (p[0x21]) v = 0;
    *(s8 *)(p + 0x24) = v;
    t = *(u8 **)(*(u8 **)(p + 0xD0) + 0x220);
    *(float *)(p + 0x34) = *(float *)(t + 0x34);
    *(float *)(p + 0x38) = 377.1428527832031f + *(float *)(t + 0x430);
    *(s16 *)(p + 0x1C) = 0x82;
    *(s16 *)(p + 0x1E) = 0x102;
    if (q[0x1E4] != 0x1D || q[5]) p[0x13C] = 0;
    func_001757E0(p, 0x16, 0x47);
}
