typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2840;
extern void func_0012AD00(u8 *);

void func_001473E0(u8 *p)
{
    u8 *g;
    u32 b;

    b = p[0x20];
    if (b != 0) {
        g = D_004C2840;
        if (*(s16 *)(g + 8) == (b & 0xFF) - 1) {
            if (p[0x21] != 0) {
                if ((s8)g[5] == 3)
                    p[0x13C] = 1;
                else
                    p[0x13C] = 0;
            } else {
                *(u32 *)(p + 0x78) = 0x3F7AE148u;
                *(u32 *)(p + 0x7C) = 0x3F800000u;
                *(u32 *)(p + 0x80) = 0x3EA8F5C3u;
            }
            func_0012AD00(p);
        } else if (p[0x21] != 0) {
            p[0x13C] = 0;
        } else {
            *(u32 *)(p + 0x78) = 0x3E947AE1u;
            *(u32 *)(p + 0x7C) = 0x3EF5C28Fu;
            *(u32 *)(p + 0x80) = 0x3F3851ECu;
            *(s16 *)(p + 0x1E) = 0;
            *(u32 *)(p + 0x74) = 0x3F800000u;
        }
    }
}
