typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004CB5C8;
extern s16 D_004B3BB0[];
extern float D_004B3B70[];

void residual_0015AEF0(u8 *p)
{
    int n = *(int *)(p + 0xD4);
    if (n != 0) {
        *(int *)(p + 0xD4) = n - 1;
        return;
    }
    if (*(s16 *)(p + 0x1C) == 0)
        return;
    {
        s16 t = *(s16 *)(p + 0x1DC);
        *(s16 *)(p + 0xCC) = t;
        *(u32 *)(p + 0x84) = (u32)D_004CB5C8;
        *(s16 *)(p + 0x1E) = D_004B3BB0[*(s16 *)(p + 0x1C) - 1];
        *(float *)(p + 0x74) = D_004B3B70[*(s16 *)(p + 0x1C) - 1];
        p[4]++;
    }
}
