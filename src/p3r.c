typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00413A80(u8 *src, u8 *dst, u8 *end) {
    s32 flags;
    s32 mask = 0;
    do {
        if (mask == 0) {
            flags = *(s8 *)src++;
            mask = 0x80;
        }
        if (flags & mask) {
            u32 b = *src++;
            s32 len = b & 0xF;
            u8 *q = dst - ((b >> 4) + 1);
            *dst++ = *q++;
            do {
                *dst++ = *q++;
            } while (len-- != 0);
        } else {
            *dst++ = *src++;
        }
        mask >>= 1;
    } while (dst < end);
}
