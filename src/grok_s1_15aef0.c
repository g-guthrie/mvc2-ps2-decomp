typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s16 D_004BF44C;
extern void *D_004C2838;
extern s16 D_004B3BB0[];
extern f32 D_004B3B70[];
extern void func_0015AF90(u8 *);

void residual_0015AEF0(u8 *p)
{
    s32 t = *(s32 *)(p + 0xD4);
    if (t != 0) {
        *(s32 *)(p + 0xD4) = t - 1;
        return;
    }
    if (*(s16 *)(p + 0x1C) != 0) {
        s16 n;
        s16 *t16 = D_004B3BB0;
        f32 *tf = D_004B3B70;
        *(s16 *)(p + 0xCC) = D_004BF44C;
        *(void **)(p + 0x84) = D_004C2838;
        n = *(s16 *)(p + 0x1C);
        n = n - 1;
        *(s16 *)(p + 0x1E) = t16[n];
        n = *(s16 *)(p + 0x1C);
        n = n - 1;
        *(f32 *)(p + 0x74) = tf[n];
    }
    p[4]++;
    func_0015AF90(p);
}
