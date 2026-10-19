typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004D18B8;
extern u8 *D_004D18C4;
extern s8 D_004D18D6[];
extern int func_003D90A0(int);
extern f32 D_004F1FDC;
extern void *D_004C283C;
extern void func_00340B20(int);

void residual_00340E70(u8 *p)
{
    u8 *s0;
    u8 *s1;
    f32 cam;
    f32 x;

    s0 = D_004D18B8;
    s1 = D_004D18C4;
    if (D_004D18D6[0] == 3 || D_004D18D6[1] == 3) {
        if (func_003D90A0(1)) {
            if (s0[0x249]) {
                cam = D_004F1FDC;
                x = *(f32 *)(s0 + 0x34);
                if (x <= 50.0f + cam && !(x < cam - 50.0f)) {
                    u32 n = p[4];
                    p[4] = n + 1;
                    *(s16 *)(p + 0x1C) = 100;
                    *(s16 *)(p + 0xCC) = 8;
                    *(void **)(p + 0x84) = D_004C283C;
                    s0 = 0;
                    do {
                        func_00340B20((int)s0);
                        s0 = (u8 *)((int)s0 + 1);
                    } while ((int)s0 < 9);
                }
            } else {
                cam = D_004F1FDC;
                x = *(f32 *)(s1 + 0x34);
                if (x <= 50.0f + cam && !(x < cam - 50.0f)) {
                    u32 n = p[4];
                    p[4] = n + 1;
                    *(s16 *)(p + 0x1C) = 100;
                    *(s16 *)(p + 0xCC) = 8;
                    *(void **)(p + 0x84) = D_004C283C;
                    s0 = 0;
                    do {
                        func_00340B20((int)s0);
                        s0 = (u8 *)((int)s0 + 1);
                    } while ((int)s0 < 9);
                }
            }
        }
    }
}
