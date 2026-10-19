typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00377860(u8 *, u8 *);
extern void func_003DAA40(u8 *);

void func_00377650(u8 *p, u8 *q)
{
    switch (p[5]) {
    case 0:
        if (*(s8 *)(p + 0x1B4)) {
            p[0x1B4] = *(s8 *)(p + 0x1B4) - 1;
            func_00175700(p);
            break;
        }
    case 5:
        if (*(s8 *)(p + 0x1B4)) {
            p[0x1B4] = *(s8 *)(p + 0x1B4) - 1;
            break;
        }
    case 1:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
            p[5] = 3;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            func_001757E0(p, 0x17, 0xC);
        }
        break;
    case 2:
    case 3:
        if (func_00175700(p) < 0) {
            p[5] = 4;
            func_00377860(p, q);
        }
        break;
    case 4:
        func_00377860(p, q);
        p[0] = 0;
        func_003DAA40(p);
        break;
    }
}
