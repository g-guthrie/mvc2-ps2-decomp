typedef unsigned char u8;
typedef short s16;
extern void func_003868B0(u8 *, u8 *);
void func_003867E0(u8 *p, u8 *q) {
    float x, y;
    p[5]++;
    p[0x14c]=8; p[0x14d]=8; p[0x14e]=8; p[0x14f]=8;
    if (q[1] == 28) { x = -53.33333206176758f; y = 94.28571319580078f; }
    else { x = -53.33333206176758f; y = 79.28571319580078f; }
    if (*(s16 *)(q + 0x140) == 0) {
        *(float *)(p + 0x34) = *(float *)(q + 0x34) + x;
        *(float *)(p + 0x5c) = -2.5f;
    } else {
        *(float *)(p + 0x34) = *(float *)(q + 0x34) - x;
        *(float *)(p + 0x5c) = 2.5f;
    }
    *(float *)(p + 0x38) = *(float *)(q + 0x38) + y;
    *(float *)(p + 0x68) = 0.0f;
    *(float *)(p + 0x60) = 0.0f;
    *(float *)(p + 0x6c) = -1.0714285373687744f;
    p[0x24] = 11;
    func_003868B0(p,q);
}
