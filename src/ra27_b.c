typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A0;
extern u8 D_004F20B0[];

void func_001E8530(void) {
    extern void func_0018AD80(u8 *, u8 *);
    s32 i, off;
    i = 0;
    if (D_004D18A0 >= 4) {
        off = 0;
        do {
            u8 *p = D_004F20B0 + off;
            if (p[0] != 0) {
                s8 t = p[0x1B3];
                if (t != 0) {
                    u8 *q = *(u8 **)(p + 0x1C8);
                    if (*(s8 *)(q + 0x1B0) & 0x20) {
                        p[0x1B3] = t | 0x40;
                    } else {
                        u8 *r;
                        p[0x1B6] = q[0x1B5];
                        r = D_004F20B0 + q[0x1B8] * 0x5B8;
                        *(u8 **)(p + 0x1CC) = r;
                        p[0x1BA] = r[0x1E6];
                        p[0x1B9] = p[0x1E6];
                        func_0018AD80(p, q);
                    }
                }
            }
            i++;
            off += 0x5B8;
        } while (i < 6);
    }
}
