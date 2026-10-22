typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A6[];

void func_003967D0(u8 *p, u8 *q) {
    extern void func_003DAA40(u8 *);
    extern s32 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00395920(u8 *, s32, s32);
    u32 t;
    s32 r;
    s16 v;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(u32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        func_003DAA40(p);
        return;
    }
    t = p[5];
    if (t == 0) {
        p[5] = t + 1;
    } else if ((u8)t == 1) {
        func_00175700();
        if ((D_004D18A6[0] & (1 << q[2])) == 0) {
            t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x17, 0x1B);
        }
    } else {
        r = func_00175700();
        if ((s8)r < 0) {
            v = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = v;
            if (v <= 0) {
                t = q[6];
                q[6] = t + 1;
                func_003DAA40(p);
                return;
            }
        }
        if (*(s8 *)(p + 0x151) & 1) {
            *(s8 *)(p + 0x151) &= ~1;
            func_00395920(q, 5, p[0x1E]);
        }
        if (*(s8 *)(p + 0x151) & 2) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = 1;
        }
    }
}
