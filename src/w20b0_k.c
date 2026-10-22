typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044AE00[];

void func_001A1910(u8 *a, u8 *b) {
    f32 fx, fy, gx, gy;
    u8 *par;
    s32 i, n;
    u8 *q;
    s16 *e, *e2, *e3;
    q = b + 0x2B8;
    e = D_0044AE00 + (a[0x22] * 4 + 2);
    fx = 1.6666666f * (f32)e[0];
    fy = 2.142857f * (f32)e[1];
    if (*(s16 *)(a + 0x140) != 0) fx = -fx;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(q + 0x24) - fx;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(q + 0x28) - fy;
    n = *(s16 *)(a + 0x1E);
    if (n > 1) {
        i = 1;
        do {
            par = *(u8 **)(a + 0xC);
            if (*(s8 *)(par + 0x13C) == 0) break;
            e2 = D_0044AE00 + a[0x22] * 4;
            e3 = D_0044AE00 + (par[0x22] * 4 + 2);
            fx = 1.6666666f * (f32)e2[0];
            fy = 2.142857f * (f32)e2[1];
            gx = 1.6666666f * (f32)e3[0];
            gy = 2.142857f * (f32)e3[1];
            if (*(s16 *)(a + 0x140) != 0) {
                fx = -fx;
                gx = -gx;
            }
            i++;
            *(f32 *)(par + 0x34) = *(f32 *)(a + 0x34) + fx - gx;
            *(f32 *)(par + 0x38) = *(f32 *)(a + 0x38) + fy - gy;
            a = par;
        } while (i < n);
    }
}
