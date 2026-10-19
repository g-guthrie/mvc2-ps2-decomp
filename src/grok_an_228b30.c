typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00228D50(u8 *);
extern int func_0018AB10(u8 *);

void func_00228B30(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        if (*(s16 *)(p + 0x1C) != 0) {
            if (*(s16 *)(p + 0x1E) != 0) {
                *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1E) = 0;
                func_001757E0(p, 0x15, (*(s8 *)(p + 0x150) + 7) & 0xFF);
                return;
            }
        }
        p[6] = 3;
        func_001757E0(p, 0x15, ((p[0x1B7] << 1) + 9) & 0xFF);
    } else {
        s8 h = *(s8 *)(p + 0x151);
        if (h > 0) {
            p[0x151] = 0;
            func_00228D50(p);
        } else if (h < 0) {
            if (func_0018AB10(p))
                *(s16 *)(p + 0x1E) = 0xFF;
        }
    }
}
