typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00176230(s16 *src, s16 *dst) {
    s32 bits;
    s32 mask = 0;
    for (;;) {
        u32 v, cnt;
        if (mask == 0) {
            bits = *src++;
            mask = 0x8000;
        }
        if ((bits & mask) != 0) {
            v = (u16)*src++;
            cnt = v >> 11;
            if (cnt != 0) {
                v &= 0x7FF;
            } else {
                cnt = (u16)*src++;
            }
            if (v == 0) {
                if (cnt == 0) return;
                do {
                    *dst++ = 0;
                } while (--cnt != 0);
            } else {
                u16 *s = (u16 *)(dst - v);
                do {
                    *dst++ = *s++;
                } while (--cnt != 0);
            }
        } else {
            *dst++ = *(u16 *)src++;
        }
        mask >>= 1;
    }
}
