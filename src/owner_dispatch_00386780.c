typedef unsigned char u8;
typedef signed short s16;
typedef void (*ActorCallback)(u8 *, u8 *);
extern ActorCallback const jtbl_004648E0[6];
void func_00386780(u8 *p, u8 *q) {
    if (q[4] >= 2 || p[1] != q[1]) {
        p[4]++;
        p[0x13c] = 0;
    }
    (*(s16 *)(p + 0x1e))++;
    jtbl_004648E0[p[5]](p, q);
}
