typedef unsigned char u8;
typedef signed int s32;
typedef signed short s16;

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
            /* Preserve the helper's 16-byte local slot with defined float bit access. */
        struct { union { f32 range[2]; s32 bits[2]; } values; s32 padding[2]; } position;
            position.values.bits[0] = 0x41ad5555;
            position.values.bits[1] = 0x4320b6db;
            func_001830D0(p, position.values.range, 1);
        }
    }
}

extern int func_001757E0(u8 *, int, int);
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

extern void func_001E3710(u8 *, int);

void func_002F1430(u8 *p)
{
    s16 timer;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);

    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        func_001757E0(p, 21, 5);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_001E3710(p, 76);
    }
}

extern void func_003A9A60(u8 *);

void func_002F1360(u8 *p)
{
    struct { union { f32 range[2]; s32 bits[2]; } values; s32 padding[2]; } position;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    --*(s16 *)(p + 0x1C);

    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[0x151] = 0;
        func_00175C00(p, 1);
        *(s32 *)(p + 0x2B8) = 0;
        position.values.bits[0] = 0x4226AAAA;
        position.values.bits[1] = 0x433A6DB6;
        func_001830D0(p, position.values.range, 1);
        func_003A9A60(p);
    }
}

extern void func_001266A0(u8 *, int, int);

void func_002F5390(u8 *p, s16 *timer)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1B0] = 0;
    p[0x200] = 3;
    func_001266A0(p, 1, 1);

    p[0x20] = 2;
    *timer = 8;
    func_001757E0(p, 22, 4);
    p[6] = 6;
    func_00175700(p);
}
