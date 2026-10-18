typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_003A3810(u8 *a, u8 *q) {
    u32 s = q[5];
    s32 r;
    if (s != 0) {
        r = 0;
    } else if (s == 2) {
        r = 0;
    } else {
        a = q + 0x2B8;
        if (*(s8 *)(a + 0xE) != 0xF) {
            r = 0;
        } else if (*(s8 *)(a + 0x8) != 0) {
            r = 0;
        } else {
            r = *(s16 *)(*(u8 **)(q + 0x220) + 0x434) != 0;
        }
    }
    return r;
}

void func_002F7240(u8 *p) {
    u32 e;
    u8 *a = p + 0x2B8;
    s32 i;
    if (p[5] == 0) {
        e = p[0x1E4];
        if (e != 0x15 && e != 0x1D && e != 0x12 && e != 0x13) {
            if (*(u16 *)(p + 0x362) & 0x200) {
                i = 0;
                do {
                    if (a[i] != 0) {
                        a[i + 6] = 1;
                        break;
                    }
                    i++;
                } while (i < 6);
            }
        }
    }
}

