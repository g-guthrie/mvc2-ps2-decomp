typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_001A14D0(u8 *p, u8 *q)
{
    extern void func_001A1660(u8 *, u8 *);
    extern void func_001A17C0(u8 *, u8 *, int);
    extern void func_001A1910(u8 *, u8 *);
    extern void func_001A1860(u8 *, u8 *);
    extern void func_001A1C50(u8 *, u8 *);
    extern void func_001A0880(u8 *, u8 *);
    extern void func_001A1A90(u8 *, u8 *);
    u8 *r = q + 0x2B8;

    if (q[5] != 0 || q[0x1E4] != 0x15 || q[0x169] != 0x15) {
        p[4] = 2;
        func_001A1660(p, q);
        return;
    }
    if (D_004D18DC & (1 << D_004D18DB))
        return;

    switch (p[5]) {
    case 0:
        func_001A17C0(p, q, 0);
        func_001A1910(p, q);
        func_001A1860(p, q);
        if (r[5] != 0)
            p[5]++;
        break;
    case 1:
        func_001A1C50(p, q);
        func_001A1860(p, q);
        if (r[5] != 1) {
            p[5]++;
            p[0x21] = 0x10;
        }
        break;
    case 2: {
        u32 timer = p[0x21] - 1;
        p[0x21] = timer;
        if ((timer & 0xFF) == 0) {
            p[4] = 2;
            p[0x13C] = 0;
            func_001A17C0(p, q, 2);
        } else {
            func_001A17C0(p, q, 1);
            func_001A0880(p, q);
            func_001A1A90(p, q);
            func_001A1860(p, q);
        }
        break;
    }
    }
}
