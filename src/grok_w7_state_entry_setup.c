typedef unsigned char u8;
typedef signed int s32;

typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_00175C00(u8 *, int);
extern void func_001830D0(u8 *, f32 *, int);

void func_002F0480(u8 *p)
{
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        *(s8 *)(p + 0x151) = 0;
        func_001E3210(p, 21);
        func_00175C00(p, 1);
        *(s32 *)(p + 0x2B8) = 0;
        {
            struct { union { f32 range[2]; s32 bits[2]; } values; s32 padding[2]; } position;
            position.values.bits[0] = 0x41ad5555;
            position.values.bits[1] = 0x4320b6db;
            func_001830D0(p, position.values.range, 1);
        }
    }
}

extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_00184540(u8 *);
extern void func_002F1DF0(u8 *);

void func_002F0B10(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        if (p[0x20D] != 2) {
            p[0x20D] = 0;
            func_00183D10(p);
        }
        func_001757E0(p, 21, 19);
        func_001E3210(p, 30);
    }

    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] == 2)
            func_00184540(p);
        else
            func_002F1DF0(p);
    }
}
