/* Metrowerks 3.0: ./try.sh src/grok_dw_3395e0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_003395E0(u8 *p)
{
    s32 t;
    switch (p[4]) {
    case 0:
        *(u32 *)(p + 0x40) = ((u32)(s32)((double)*(s16 *)(p + 0x1C) * 0.5 * 65536.0 / 360.0 + 0.5) & 0xFFFFu);
        t = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = (s16)t;
        if (!((s16)t < 0x2D0))
            *(s16 *)(p + 0x1C) = 0;
        break;
    }
}
