/* func_0039D300: ./try.sh src/gr18_c.c "-O3,p -sdatathreshold 0" */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef signed int s32; typedef unsigned int u32;
void func_0039D300(u8 *p) {
    extern void func_0039E450();
    s16 n = *(s16 *)(p + 0x1E);
    u8 *q;
    s16 i;
    if (n == 0) {
        func_0039E450(p);
        return;
    }
    q = *(u8 **)(p + 0xC);
    i = n - 1;
    for (;;) {
        if (*(u16 *)(q + 0x26) != 0x2800) return;
        if (*(s8 *)(q + 0x1B2) != 0) goto hit;
        switch (*(s8 *)(q + 0x1B3)) {
        default:
        hit:
            p[5]++;
            p[0x1B2] = 1;
            return;
        case 0:
            break;
        }
        i = i - 1;
        if (i < 0) break;
        q = *(u8 **)(q + 0xC);
    }
}
