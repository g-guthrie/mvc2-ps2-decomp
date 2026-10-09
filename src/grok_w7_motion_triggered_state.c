typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern void func_00183D50(u8 *);

void func_002F1600(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if (func_001864A0(p) != 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 40;
        func_00183D50(p);
        func_001757E0(p, 21, 39);
    }
}

extern void func_001830D0(u8 *, f32 *, int);

void func_002F55C0(u8 *p, void *unused)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = -20.0f;
        if (*(s16 *)(p + 0x140) != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(s16 *)(p + 0x1C) = 16;
        {
            struct { union { f32 values[2]; u32 bits[2]; } offsets; u32 padding[2]; } position;
            position.offsets.bits[0] = 0;
            position.offsets.bits[1] = 0x432B6DB6;
            func_001830D0(p, position.offsets.values, 1);
        }
    }
}
