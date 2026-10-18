typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;

extern void func_0031F800();
void func_0031F760(u8 *a, u8 *b) {
    f32 dx;
    u32 t;
    a[0x40D] = 0;
    a[0x40C] = 0;
    dx = -80.0f;
    a[0x33B] = 0;
    a[0x33C] = 0;
    t = a[7];
    a[7] = t + 1;
    (*(u8 **)(b + 4))[0x24A] = 0;
    *(s16 *)(a + 0x1C) = 0x32;
    *(u32 *)(a + 0x5C) = 0xBF555555;
    if (a[0x1E6] != 0) {
        *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
        dx = -dx;
    }
    *(f32 *)(a + 0x34) += dx;
    *(f32 *)(a + 0x38) += 51.42856979f;
    *(u32 *)(a + 0x60) = 0x3F892492;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x6C) = 0;
    func_0031F800(a, b);
}

typedef struct { f32 x, y, z; } V3;
extern s32 func_001748C0();
u8 func_00237E40(u8 *a, u8 *b) {
    V3 v1;
    V3 v2;
    u8 r;
    v1 = *(V3 *)(a + 0x34);
    v2 = *(V3 *)(b + 0x34);
    v1.y += 137.14285278f;
    v2.y += 102.85713959f;
    r = func_001748C0(&v1, &v2);
    return (r + 2) >> 2;
}

