typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;

/* 0x001C84D0 */
extern void func_00176160(u8 *, int, int, int);
void func_001C84D0(u8 *a, u8 *b, u8 *c) {
    u8 *s = a + 0xD0;
    do {
        s[4] = c[0];
        func_00176160(b, c[1], c[2] + b[0x25] * 0x57, c[3]);
        if (*(s32 *)(c + 4) == 1) {
            s[5] = 0;
        } else {
            s[5] = 1;
        }
        c += *(s32 *)(c + 4) * 8;
    } while (s[4] == 0);
    *(u8 **)s = c;
}
