/* ./try.sh src/grok_jg_0031D2D0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_0031D380(u8 *);

void residual_0031D2D0(u8 *p)
{
    f32 vx;
    f32 vy;

    p[7]++;
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 32;
    *(u32 *)(p + 0x60) = 0x41AB6DB6u;
    *(u32 *)(p + 0x6C) = 0xBF2B6DB6u;
    vx = -213.33332824707031f;
    vy = 3.3333332538604736f;
    if (p[2]) {
        vx = -vx;
        vy = -vy;
    }
    *(f32 *)(p + 0x34) += vx;
    *(f32 *)(p + 0x5C) = vy;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 18, 0);
    func_0031D380(p);
}
