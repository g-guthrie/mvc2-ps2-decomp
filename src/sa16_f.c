typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001E86B0(u8 *p, u8 *q) {
    extern s32 func_001E8310(void *, void *, int, int);
    extern void func_0018D620(u8 *, u8 *);
    s32 s2, s3, r;
    if (p[0] != 0 && (*(u16 *)(p + 0x1C2) & 0x80) != 0) {
    s2 = *(s16 *)(*(u8 **)(p + 0x1D4) + 2);
    if (s2 > 0 || q[0] == 0) return;
    s3 = *(s16 *)(*(u8 **)(q + 0x1D4) + 0);
    r = 0;
    if (s3 > 0) {
        r = func_001E8310(p, q, s2 & 0x1FFF, s3);
        *(s16 *)(q + 0x1BC) = s3;
    }
    if (r == 0) {
        s3 = *(s16 *)(*(u8 **)(q + 0x1D4) + 2);
        if (s3 > 0) {
            r = func_001E8310(p, q, s2 & 0x1FFF, s3);
            *(s16 *)(q + 0x1BC) = s3;
        }
    }
    if (r != 0) {
        p[0x1B4] = 0xA;
        q[0x1B4] = 0xB;
        p[0x1B1] = 0;
        p[0x201] = 8;
        *(u16 *)(p + 0x1C2) &= 0x7F;
        *(s16 *)(p + 0x1BE) = s2 & 0x1FFF;
        func_0018D620(p, q);
    }
    }
}
