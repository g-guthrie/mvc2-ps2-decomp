int func_0c02a6f8(const signed char *src, int size, signed char *dst)
{
    int mask=0, flags;
    signed char *end=dst+size;
    do {
        if (mask==0) { flags=*src++; mask=0x80; }
        if ((unsigned int)flags & mask) {
            unsigned int token=(unsigned char)*src++;
            int count=token;
            signed char *copy;
            token >>= 4;
            copy=dst-token-1;
            count &= 15;
            *dst++=*copy++;
            do { *dst++=*copy++; } while(count-- != 0);
        } else *dst++=*src++;
        mask >>= 1;
    } while (dst<end);
    return size;
}
void func_0c02a762(const short *src, short *dst)
{
    int mask=0, flags;
    for (;;) {
        if (mask==0) { flags=*src++; mask=0x8000; }
        if ((unsigned int)flags & mask) {
            register unsigned int token=(unsigned short)*src++;
            unsigned int count=token;
            count >>= 11;
            if (count) token &= 0x7ff;
            else count=(unsigned short)*src++;
            if (token==0) {
                if (count==0) return;
                do { *dst++=0; } while (--count != 0);
            } else {
                short *copy=dst-token;
                do { *dst++=*copy++; } while (--count != 0);
            }
        } else *dst++=*src++;
        mask >>= 1;
    }
}
