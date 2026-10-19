typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s16 D_004C81DC;
extern void *D_004CB5C8;
extern s16 D_004B3BB0[];
extern f32 D_004B3B70[];
extern void func_0015AF90(u8 *);

void residual_0015AEF0(u8 *p)
{
    s32 t = *(s32 *)(p + 0xD4);

    if (t) {
        *(s32 *)(p + 0xD4) = t - 1;
        return;
    }
    if (*(s16 *)(p + 0x1C)) {
        s16 n;
        *(s16 *)(p + 0xCC) = D_004C81DC;
        *(void **)(p + 0x84) = D_004CB5C8;
        n = *(s16 *)(p + 0x1C);
        n = n - 1;
        *(s16 *)(p + 0x1E) = D_004B3BB0[n];
        n = *(s16 *)(p + 0x1C);
        n = n - 1;
        *(f32 *)(p + 0x74) = D_004B3B70[n];
    }
    p[4]++;
    func_0015AF90(p);
}
