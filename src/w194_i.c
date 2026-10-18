typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void (*D_004C1D80[2])(u8 *, u8 *);
extern void func_00388680();

void func_00387F20(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    u32 t;
    if (q[0x2C0] == 0) {
        p[4] = 2;
        r[7] = 0;
        return;
    }
    if (r[0xB] != 0) {
        p[4] = 2;
        r[7] = 0;
        r[8] = 0;
        return;
    }
    if (q[5] >= 2) {
        p[4] = 2;
        r[7] = 0;
        r[8] = 0;
        return;
    }
    func_00388680();
    if (r[9] != 0) {
        t = p[5];
        p[5] = t + 1;
        r[8] = 0;
        *(s32 *)(p + 0xD8) = 0;
        *(s32 *)(p + 0xD4) = 1;
        *(s16 *)(p + 0x1C) = 16;
        p[0x24] = 10;
        if (q[0x1E6] == 0) {
            *(u32 *)(p + 0x5C) = 0xC0D55555;
        } else {
            *(u32 *)(p + 0x5C) = 0x40D55555;
        }
        *(s32 *)(p + 0x68) = 0;
    } else {
        D_004C1D80[p[6]](p, q);
    }
}
