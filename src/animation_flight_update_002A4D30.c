typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x7C];
    s16 h7c[2];
} PlayerCounts;
extern PlayerCounts *D_004C2794;
extern f32 data_u32_00458610[4];

void func_002A4D30(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00183D50(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u8 stageByte;
    s8 stage;
    f32 value;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((p[0x1E6] == 0 && *(f32 *)(p + 0x5C) > 0.0f) ||
        (p[0x1E6] != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x5C) = 0;
    }
    stageByte = p[0x15B];
    if (stageByte != 0) {
        stage = (s8)stageByte;
        *(s8 *)(p + 0x1B5) = stage + 0x4D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        p[0x15B] = 0;
    }
    if (*(f32 *)(p + 0x60) > 0.0f) {
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) - 1;
            if (p[0x1E6] != 0) value = -*(f32 *)(data_u32_00458610 + *(s8 *)(p + 0x151) * 2);
            else value = *(f32 *)(data_u32_00458610 + *(s8 *)(p + 0x151) * 2);
            *(f32 *)(p + 0x34) += value;
            {
                f32 *tableY = data_u32_00458610 + 1;
                value = *(f32 *)(tableY + *(s8 *)(p + 0x151) * 2);
            }
            *(f32 *)(p + 0x38) += value;
            p[0x151] = 0;
        }
    } else if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00183D50(p);
        func_001757E0(p, 22, 3);
    }
}
