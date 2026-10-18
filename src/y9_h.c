typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;

void func_001C9F10(u8 *p) {
    extern void func_00175670();
    u8 *q;
    u8 c;
    s16 v, h;
    q = *(u8 **)(p + 0x18);
    if (q[0x1E4] != 0x1D || q[0x1FD] != 1) {
        p[4] = 2;
    } else {
        func_00175670(p);
        c = p[0x22];
        p[0x22] = c - 1;
        if (c == 0) {
            p[0x22] = 0;
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v < 0) {
                p[4] = 2;
            } else {
                h = *(s16 *)(p + 0x1E);
                *(s16 *)(p + 0x1E) = h - 1;
                if (h == 0) {
                    p[0x13C] = *(s8 *)(D_004C2840 + 0x1C) & 1;
                    *(s16 *)(p + 0x1E) = 0;
                }
            }
        }
    }
}
