typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A3;
extern u8 D_004D18A0;
extern u8 D_004D18A6;
extern u8 D_0044EE80[];
void func_001DF330(u8 *p, u8 *q) {
    extern void func_00176160();
    u8 *b = q + 0x2B8;
    s8 x;
    s8 y;
    u8 c;
    *(s16 *)(q + 0x3F8) = 2;
    if (*(s16 *)(q + 0x434) == 0) {
        p[4]++;
        return;
    }
    c = (*(u8 **)(q + 0x220))[1];
    if (c == 0x18 || c == 0x19) {
        if (D_004D18A3 != 0 || D_004D18A0 == 6) {
            p[4]++;
            return;
        }
    }
    if ((D_004D18A6 & (1 << (p[2] ^ 1))) != 0) return;
    if (b[8] == 0) return;
    x = b[0x22];
    b[0x22] = x - 1;
    if (x != 0) return;
    b[0x22] = 4;
    y = b[0x21] - 1;
    b[0x21] = y;
    if (y < 0) b[0x21] = 9;
    func_00176160(q, 0, D_0044EE80[*(s8 *)(b + 0x21)] + q[0x25] * 6, 1);
}
