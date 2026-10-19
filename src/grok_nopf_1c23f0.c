/* Metrowerks 3.0: ./try.sh src/grok_nopf_1c23f0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_001757E0(u8 *, int, int);
extern void func_001C24C0(u8 *, u8 *);
extern void func_001C2520(u8 *, u8 *);

void residual_001C23F0(u8 *p, u8 *q)
{
    u8 dir;

    p[7]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
    dir = 0;
    if (*(float *)(p + 52) < *(float *)(q + 52))
        dir = 1;
    if (dir != *(s16 *)(p + 320)) {
        p[214] = p[6];
        p[215] = p[7];
        p[6] = 11;
        p[7] = 0;
        func_001C2520(p, q);
        return;
    }
    if (p[6] != p[214])
        func_001757E0(p, 25, 0);
    func_001C24C0(p, q);
}
