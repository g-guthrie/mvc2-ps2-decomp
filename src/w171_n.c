typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001A9410(u8 *p, u8 *q)
{
    extern void func_00175670(u8 *);
    extern void func_00175580(u8 *, s32, s32, s32);
    u32 *r;
    u32 t;
    r = (u32 *)(p + 0xD0);
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x5C) = 0xBFD55555;
        } else {
            *(u32 *)(p + 0x5C) = 0x3FD55555;
        }
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        *r = (u16)(0x10000 / *(s16 *)(p + 0x1C));
        func_00175580(p, 0x1B, 0xB, 2);
    }
}

extern s16 D_0044CE00[];
extern s16 D_0044CE02[];

void func_001C7C40(u8 *p, u8 *q)
{
    extern void func_00175700();
    u32 t;
    s32 i;
    f32 a, b;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(q + 0x151) == 0) {
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 0x1E;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        i = *(s8 *)(p + 0x150);
        a = 1.6666666269302368f * (f32)*(s16 *)((u8 *)D_0044CE00 + i * 4);
        b = 2.142857074737549f * (f32)*(s16 *)((u8 *)D_0044CE02 + i * 4);
        if (*(s16 *)(p + 0x140) != 0) {
            a = -a;
        }
        *(f32 *)(q + 0x34) = a + *(f32 *)(p + 0x34);
        *(f32 *)(q + 0x38) = b + *(f32 *)(p + 0x38);
    }
}
