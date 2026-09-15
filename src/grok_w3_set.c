typedef unsigned char u8;
typedef signed short s16;

void residual_00327F90(u8 *p) {
    p[4]++;
    *(s16 *)(p + 0x1c) = 20;
}
