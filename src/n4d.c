typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern void func_001757E0();
extern s32 func_00175700();
extern void func_001BAD70();
extern s32 func_00175670();
extern void func_0021A340();

void func_0021A2B0(u8 *p, u8 *q) {
    f32 dx;
    u32 t;
    p[0x33C] = 5;
    t = p[7];
    p[7] = t + 1;
    dx = -80.0f;
    *(u8 *)(*(u8 **)(q + 4) + 0x24A) = 0;
    *(s16 *)(p + 0x1C) = 0x32;
    *(u32 *)(p + 0x5C) = 0xBF555555;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        dx = -dx;
    }
    *(f32 *)(p + 0x34) += dx;
    *(f32 *)(p + 0x38) += 51.42857f;
    *(u32 *)(p + 0x60) = 0x3F892492;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_0021A340(p, q);
}

void func_00251FF0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -3.3333333f : 3.3333333f;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x16, 7);
    }
}

extern u8 *D_004D18A0[][3];

s32 func_0028DA30(u8 *p, u8 key) {
    s32 i = 0;
    do {
        u8 *e = D_004D18A0[p[2] + 2][i];
        if (e != p && e[1] == key) { return 1; }
        i++;
    } while (i <= 2);
    return 0;
}
