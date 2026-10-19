/* Metrowerks 3.0: ./try.sh src/grok_t6_201430.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001E3270(u8 *, int, f32);
extern int func_00185980(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_0034A6B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00185770(u8 *, u8 *);

void residual_00201430(u8 *p)
{
    u8 *q = p + 0x2B8;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)p[0x1B2] < 0) {
        func_001E3270(p, 0x1F, 32.0f);
        q[0x1C] = 0;
        if (((s8)p[0x1B2] & 0x7F) == 0) {
            u8 *s = *(u8 **)(p + 0x1C4);
            if (func_00185980(p) != 0) {
                *(f32 *)(s + 0x38) = *(f32 *)(p + 0x38);
                p[6]++;
                p[7] = 0;
                func_001266A0(p, 5, 5);
                *(u32 *)q = *(u32 *)(p + 0x1C4);
                q[0xD] = 0;
                q[0x16] = 0;
                func_0034A6B0(p, 1);
                func_001757E0(p, 0x16, 0x15);
                p[0x20B] = 0xC5;
                func_00185770(p, *(u8 **)(p + 0x1C4));
                return;
            }
        }
        p[7] = 1;
        *(f32 *)(p + 0x5C) = 10.0f / 3.0f;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = 120.0f / 7.0f;
        *(f32 *)(p + 0x6C) = -45.0f / 56.0f;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0x16, 0xB);
        return;
    }
    {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t == 0) {
            p[7]++;
            func_001E3270(p, 0x1F, 32.0f);
            q[0x1C] = 0;
            *(f32 *)(p + 0x5C) /= 2.0f;
            *(f32 *)(p + 0x68) = 0;
            *(f32 *)(p + 0x60) = -15.0f / 7.0f;
            *(f32 *)(p + 0x6C) = -45.0f / 56.0f;
            func_001757E0(p, 1, 9);
        }
    }
}
