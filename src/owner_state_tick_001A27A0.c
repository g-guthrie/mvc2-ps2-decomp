typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_001A28F0(u8 *, u8 *);
extern void func_001A2F20(u8 *, u8 *);
extern void func_001A2B40(u8 *, u8 *);
extern void func_001A2A40(u8 *);
extern int func_001A0880(void *, void *);
extern void func_001A2D60(u8 *, u8 *);

void func_001A27A0(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    s32 countdown;

    if (q[5] != 0 || q[0x1E4] != 0x1A || q[0x169] != 0x14 || q[0x168] != 0) {
        p[4] = 2;
        func_001A28F0(p, q);
        return;
    }
    if (D_004D18DC & (1 << D_004D18DB))
        return;

    if (p[5] == 0) {
        func_001A2F20(p, q);
        func_001A2B40(p, q);
        if ((s8)r[0x3A] == -1) {
            p[5]++;
            p[0x21] = 0xA;
        }
    } else {
        countdown = p[0x21] - 1;
        p[0x21] = countdown;
        if ((countdown & 0xFF) == 0) {
            p[4] = 2;
            p[0x13C] = 0;
            func_001A28F0(p, q);
        } else {
            func_001A2A40(p);
            func_001A0880(p, q);
            func_001A2D60(p, q);
            func_001A2B40(p, q);
        }
    }
}
