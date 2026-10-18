typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 D_004C1460[8];
extern s8 D_004C1458[8];
extern void func_001E3210(u8 *, s32);

s32 func_002FFB30(u8 *p, u8 *q) {
    s8 t;
    s8 d;
    u32 u;
    if (*(u16 *)(p + 0x362) & 0x3C00) {
        q[0xE] = 1;
    }
    if (*(s8 *)(p + 0x539) != 0) {
        t = q[0xF];
        q[0xF] = t - 1;
        if (t == 0) {
            q[0xF] = D_004C1460[p[0x212]];
            q[0xE] = 1;
        }
    }
    if (p[0x425] != 0) {
        t = q[0x10];
        q[0x10] = t - 1;
        if (t == 0) {
            q[0x10] = 6;
            q[0xE] = 1;
        }
    }
    t = q[0xC];
    q[0xC] = t - 1;
    if (t == 0) {
    if (q[0xE] != 0) {
        d = q[0xD];
        if (d < 7) {
            q[0xD] = d + 1;
        }
    } else {
        d = q[0xD];
        if (d > 0) {
            q[0xD] = d - 1;
        }
    }
    q[0xC] = D_004C1458[(s8)q[0xD]];
    q[0xE] = 0;
    u = q[0xB];
    q[0xB] = u + 1;
    u = q[0xB];
    q[0xB] = u & 1;
    q[0x14] = *(s8 *)(q + 0xD);
    if (q[0xB] != 0) {
        func_001E3210(p, 0x1E);
    }
    return 1;
    }
    return 0;
}
