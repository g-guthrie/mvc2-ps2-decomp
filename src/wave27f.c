typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00175700(u8 *a);
void func_0020AC70(u8 *a) {
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t = a[7];
        a[7] = t + 1;
        a[0x151] = 0;
        *(u32 *)(a + 0x48) = (u16)(*(u32 *)(a + 0x48) + 0x8000);
        *(f32 *)(a + 0x38) += 291.42856f;
    }
}

typedef struct { s16 x, y; } Pair;
extern Pair D_0044DFE0[];
void func_001D1AF0(u8 *a, u8 *b) {
    s32 i = *(s8 *)(b + 0x150);
    s16 x = D_0044DFE0[i].x;
    s16 y = D_0044DFE0[i].y;
    if (*(s16 *)(b + 0x140) != 0) {
        x = -x;
    }
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + 1.6666666f * (f32)x;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + 2.142857f * (f32)y;
}

void func_0031CC30(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t = a[6];
        a[6] = t + 1;
        a[0x151] = 0;
        if (a[0x210] != 0) {
            *(u32 *)(a + 0x5C) = 0xC1700000;
            *(u32 *)(a + 0x60) = 0xC1CDB6DB;
        } else {
            *(u32 *)(a + 0x5C) = 0xC13C9249;
            *(u32 *)(a + 0x60) = 0xC1AB6DB6;
        }
        if (a[0x1E6] != 0) {
            *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
        }
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x6C) = 0;
    }
}
