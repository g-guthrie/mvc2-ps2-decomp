/* Metrowerks 3.0: ./try.sh src/grok_t6_207510.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s16 D_004B7120[];
extern s8 func_00175700(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001E3270(u8 *, int, f32);
extern void func_001757E0(u8 *, int, int);
extern u8 *func_0034B070(u8 *, int);

void func_00207510(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    p[0x33C] = 5;
    if ((s8)p[0x150] != 0) {
        p[0x150] = 0;
        func_001E3710(p, 0x30);
    }
    if ((s8)p[0x151] != 0) {
        s16 n = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = n;
        if (n >= 8) {
            func_001E3270(p, 0x18, 4.0f);
            p[6]++;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            if (p[0x20D] != 2)
                func_001757E0(p, 0x16, 7);
            else
                func_001757E0(p, 0x16, 9);
        } else {
            u8 *s = func_0034B070(p, 1);
            if (s != 0) {
                f32 f = (f32)D_004B7120[*(s16 *)(p + 0x1C)] * (5.0f / 3.0f);
                *(f32 *)(s + 0x34) = f;
                if (*(s16 *)(p + 0x140) == 0)
                    *(f32 *)(s + 0x34) = -*(f32 *)(s + 0x34);
                *(f32 *)(s + 0x34) += *(f32 *)(p + 0x34);
            }
        }
    }
}
