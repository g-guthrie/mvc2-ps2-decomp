typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00449E20[];
extern u8 D_00449E22[];
extern u8 D_00449E24[];
extern u8 D_00449E25[];

void func_00195B40(u8 *a, u8 *b) {
    extern s32 func_00197560(u8 *, u8 *);
    extern void func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    f32 v, w, x, y;
    s32 k, c;
    if (func_00197560(a, b) == 0) {
        if (a[0x21] < 4) {
            k = *(s8 *)(b + 0x151);
            if (k != 0x80) {
                c = a[0x21];
                x = *(f32 *)(b + 0x34);
                y = *(f32 *)(b + 0x38);
                v = 1.6666666269302368f * (f32)(*(s16 *)(D_00449E20 + k * 24 + (u8)c * 6) << 8) / 256.0f;
                if (*(s16 *)(b + 0x140) == 0) v = -v;
                *(f32 *)(a + 0x34) = x + v;
                *(f32 *)(a + 0x38) = y + 2.142857074737549f * (f32)(*(s16 *)(D_00449E22 + *(s8 *)(b + 0x151) * 24 + a[0x21] * 6) << 8) / 256.0f;
                *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140) ^ *(s8 *)(D_00449E24 + *(s8 *)(b + 0x151) * 24 + a[0x21] * 6);
                a[0x31] = *(s8 *)(D_00449E25 + *(s8 *)(b + 0x151) * 24 + a[0x21] * 6);
                func_00175670(a);
                func_001975C0(a, b);
            }
        }
    }
}
