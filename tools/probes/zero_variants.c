typedef unsigned int u32;
typedef unsigned char u8;

void zero_a(u8 *dst, u32 count) {
    int i;
    if (count != 0) {
        for (i = (int)count - 1; i >= 0; i--) {
            *dst++ = 0;
        }
    }
}

void zero_b(u8 *dst, u32 count) {
    int i = (int)count - 1;
    if (count != 0) {
        do {
            *dst++ = 0;
            i--;
        } while (i != -1);
    }
}

void zero_c(u8 *dst, u32 count) {
    u32 i;
    if (count != 0) {
        for (i = count - 1; i != (u32)-1; i--) {
            *dst++ = 0;
        }
    }
}
