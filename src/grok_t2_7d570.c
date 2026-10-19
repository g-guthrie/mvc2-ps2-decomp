typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00163D70(u8 *);
extern void func_00178E60(u8 *);
extern s32 func_001864a0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0017D840(u8 *);

void func_0017D570(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x211) != 0) {
        if (p[0x24C] == 0) {
            p[0x24C] = 1;
            func_001E3A10(p);
            func_00163D70(p);
        }
    }
    if (*(s16 *)(p + 0x1E) == 0) {
        if (*(f32 *)(p + 0x60) <= 0.0f) {
            *(s16 *)(p + 0x1E) = 1;
            func_00178E60(p);
        }
    }
    if (p[0x247] != 2) {
        s8 t = *(s8 *)(p + 0x24D) - 1;
        *(s8 *)(p + 0x24D) = t;
        if (t < 0) {
            if (*(s16 *)(p + 0x434) != 0) {
                p[6] = 3;
                *(s8 *)(p + 0x1EA) = -1;
                p[0x210] = 1;
                func_001757E0(p, 13, 30);
                func_0017D840(p);
                return;
            }
        }
    }
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        if (func_001864a0(p) != 0) {
            p[0x1FF] = 2;
            *(s16 *)(p + 0x28C) = 5;
            p[6]++;
            p[0x20D] = 3;
            func_001757E0(p, 13, 26);
        }
    }
}
