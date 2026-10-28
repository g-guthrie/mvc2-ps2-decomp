typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef float f32;
typedef int s32;

static void func_003BB8F0(u8 *p) { p[4]++; p[5] = 0; p[6] = 0; p[316] = 1; }

void func_003BBB80(u8 *p)
{
    extern void func_003BBDE0(u8 *);
    extern s32 func_003BD650(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *q;
    s32 f = *(s8 *)(p + 0x1B2);
    if (f != 0) {
        q = *(u8 **)(p + 0x1C4);
        if (q[3] == 0) {
            if (q[0x425] != 0 || (q[1] >= 0x18 && q[1] < 0x1B)) {
                func_003BB8F0(p);
                return;
            } else if ((s8)f & 0x7F) {
                func_003BB8F0(p);
            } else {
                func_003BBDE0(p);
            }
        } else {
            func_003BB8F0(p);
        }
    } else {
        s16 v;
        if (func_003BD650(p) != 0) {
            func_003BB8F0(p);
        } else {
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v != 0) {
                *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
                *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
                func_00175700(p);
                func_001E7F60(p);
            } else {
                func_003BB8F0(p);
            }
        }
    }
}
