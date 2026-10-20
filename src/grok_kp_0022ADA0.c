/* ./try.sh src/grok_kp_0022ADA0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_0019DB00(u8 *, int, int);

void func_0022ADA0(u8 *p)
{
    s16 t;
    int a2;

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t <= 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[6]++;
            func_001757E0(p, 0x15, 0x35);
            return;
        }
        p[0x21] ^= 1;
        {
            s8 face = *(s8 *)(p + 0x21);
            s16 cur = *(s16 *)(p + 0x1C);
            a2 = (u8)(face + 11);
            if (cur == 1) {
                a2 = (u8)(a2 + 2);
                *(unsigned int *)(p + 0x5C) = 0;
            }
            func_001757E0(p, 0x16, a2);
        }
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        func_0019DB00(p, *(s8 *)(p + 0x151), p[0x15B]);
        func_0019DB00(p, *(s8 *)(p + 0x151) - 1, p[0x15B]);
        p[0x151] = 0;
    }
    if (*(s8 *)(p + 0x150)) {
        func_0019DB00(p, 0x80, p[0x15B]);
        func_0019DB00(p, 0x81, p[0x15B]);
        func_0019DB00(p, 0x82, p[0x15B]);
        func_0019DB00(p, 0x83, p[0x15B]);
        p[0x150] = 0;
    }
}
