typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;

void func_003A3D10(u8 *p, u8 *q, u8 *r) {
    extern void func_003A4250(u8 *);
    extern int func_00174470(const void *);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_0015B200(u8 *, u8 *, s32, s32);
    extern void func_003A4340(u8 *);
    extern void func_001E7F60(u8 *);
    u32 t;
    if (*(s8 *)(r + 4) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60) + *(f32 *)(p + 0x6C);
        t = p[0x23] - 1;
        p[0x23] = t;
        if ((t & 0xFF) == 0) {
            *(s16 *)(p + 0x1E) = (*(s16 *)(p + 0x1E) + *(s16 *)(p + 0x1C)) % 12;
            if (*(volatile s16 *)(p + 0x1E) < 0) {
                *(s16 *)(p + 0x1E) = 11;
            }
            func_003A4250(p);
        }
    }
    if (func_00174470(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B3) == 0) {
        s32 d = *(s32 *)(p + 0xD0) - 1;
        *(s32 *)(p + 0xD0) = d;
        if (d != 0 && *(s16 *)(q + 0x434) != 0 && q[5] == 0 && *(s8 *)(r + 3) != -1 && D_004D18A0 != 5) {
            goto L6C;
        }
    }
    p[5] = 4;
    *(s8 *)(r + 3) = -1;
    func_00175910(p, 0x17, 5, *(s8 *)(p + 0x151));
    return;
L6C:
    if ((t = *(s8 *)(p + 0x1B2)) != 0) {
        if ((s8)t & 1) {
            p[4] = 2;
            p[0x13C] = 0;
            func_0015B200(p, p + 0x34, 1, 0x88);
            return;
        }
        r = *(u8 **)(p + 0x1C4);
        if (r[3] != 0) {
            p[4] = 2;
            p[0x13C] = 0;
            func_0015B200(p, p + 0x34, 1, 0x88);
            return;
        }
        {
            u32 c = p[5];
            p[5] = c + 1;
            p[0x13D] = 1;
            p[0x23] = *(s8 *)(p + 0x13E);
            *(s16 *)(p + 0x1C) = 0x1E0;
            *(s16 *)(p + 0x1E) = 8;
            p[0x21] = 0;
            func_003A4340(p);
            if (r[0x425] != 0 || q[0x425] != 0) {
                *(s16 *)(p + 0x1C) = 1;
                *(s16 *)(p + 0x1E) = 1;
            }
        }
        return;
    }
    {
        func_001E7F60(p);
    }
}
