/* Consume a placement flag and advance the timed child parameter index. */
typedef unsigned char u8;
void func_0015E210(u8 *owner,u8 *p) {
    if (p[7]) {
        p[7] = 0;
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    if (!--*(short *)(p+0x1e)) {
        p[4] = 1;
        if (++*(short *)(p+0x1c) >= 8) {
            p[4] = 3;
            *(short *)(p+0x1c) = 7;
        }
    }
}
void func_0015E910(u8 *owner,u8 *p) {
    if (p[7]) {
        p[7] = 0;
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    if (!--*(short *)(p+0x1e)) {
        p[4] = 1;
        if (++*(short *)(p+0x1c) >= 8) {
            p[4] = 3;
            *(short *)(p+0x1c) = 7;
        }
    }
}
void func_001600C0(u8 *owner,u8 *p) {
    if (p[7]) {
        p[7] = 0;
        *(float *)(p+0x34) = *(float *)(owner+0x34) + *(float *)(p+0x5c);
        *(float *)(p+0x38) = *(float *)(owner+0x38) + *(float *)(p+0x60);
    }
    if (!--*(short *)(p+0x1e)) {
        p[4] = 1;
        if (++*(short *)(p+0x1c) >= 8) {
            p[4] = 3;
            *(short *)(p+0x1c) = 7;
        }
    }
}
