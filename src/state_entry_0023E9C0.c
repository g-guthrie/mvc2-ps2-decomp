typedef unsigned char u8;
extern int func_001757E0(void *, int, int);
extern void func_0015D010(void *, const float *);
extern void func_0018C6E0(void *);

void func_0023E9C0(u8 *p) {
    float position[3];
    if (p[0x22] & 2) { p[0x1e6] ^= 1; *(short *)(p + 0x140) = p[0x1e6]; }
    p[0x1b4] = 10;
    func_001757E0(p, 15, 0);
    *(float *)(p + 0x5c) = 0.0f;
    *(float *)(p + 0x60) = 0.0f;
    *(float *)(p + 0x68) = 0.0f;
    *(float *)(p + 0x6c) = 0.0f;
    position[0] = -238.33332824707031250000f;
    position[1] = 169.28570556640625000000f;
    position[2] = 0.0f;
    func_0015D010(p, position);
    func_0018C6E0(p);
}

