/* Advance a moving effect and clear its phase when the timer expires. */
typedef unsigned char u8;

void func_003CD5A0(u8 *p) {
    float delta;
    float timer;

    delta = *(volatile float *)(p + 0x60);
    *(volatile float *)(p + 0x38) = *(volatile float *)(p + 0x38) + delta;
    *(volatile float *)(p + 0x60) += *(volatile float *)(p + 0x6C);
    timer = *(float *)(p + 0x118) - 0.05f;
    *(float *)(p + 0x118) = timer;
    if (timer < 0.0f) {
        p[4]++;
        p[0x13C] = 0;
    }
}
