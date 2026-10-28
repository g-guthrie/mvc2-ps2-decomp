typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

void func_003DAC50(u8 *p, s32 n)
{
    s32 i; s32 r; s32 w; r = n & 3; i = 0; w = n / 4;

    if (0 < w) {
        if (w > 8) {
            do {
                ((u32 *)p)[0] = 0;
                i += 8;
                ((u32 *)p)[1] = 0;
                ((u32 *)p)[2] = 0;
                ((u32 *)p)[3] = 0;
                ((u32 *)p)[4] = 0;
                ((u32 *)p)[5] = 0;
                ((u32 *)p)[6] = 0;
                ((u32 *)p)[7] = 0;
                p += 32;
            } while (i < w - 8);
        }
        goto test;
    loop:
        *(u32 *)p = 0;
        i++;
        p += 4;
    test:
        if (i < w) goto loop;
    }
    if (r != 0) {
        for (i = 0; i < r; i++) {
            *p = 0;
            p++;
        }
    }
}
