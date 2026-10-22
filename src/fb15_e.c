typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void *memcpy(void *, const void *, u32);
extern void func_003EB3B0(u8 *, u8 *, s32);

void func_003EB260(s32 w, s32 h, u8 *src, u8 *dst)
{
    s32 i;
    u8 tmp[0x2000];
    s32 k;
    s32 bw;
    u8 *s;
    s32 bh;
    s32 j;
    u8 *t;
    bw = (w - 1) / 128 + 1;
    bh = (h - 1) / 128 + 1;
    for (j = 0; j < bh; j++) {
        for (i = 0; i < bw; i++) {
            s = src + bw * (j * 0x2000) + i * 0x40;
            t = tmp;
            k = 0;
            do {
                memcpy(t, s, 0x40);
                s += bw << 6;
                t += 0x40;
                k++;
            } while (k < 128);
            func_003EB3B0(tmp, dst + bw * (j * 0x2000) + i * 0x100, bw);
        }
    }
}
