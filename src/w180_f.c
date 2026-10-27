typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; u32 f1c; } G;
extern G *D_004C2840;

void func_0031EF60(u8 *p) {
    s16 t;
    u32 c;
    f32 a;
    f32 b;
    extern void func_00183D90(u8 *);
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001E3210();
    if (p[0x1B7] != 0 && (D_004C2840->f1c & 1) != 0) {
        func_00183D90(p);
    }
    p[0x209] = 2;
    p[0x206] = 3;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        c = p[7];
        p[7] = c + 1;
        p[0x209] = 0;
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x5C) / 8.0f;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        func_001757E0(p, 0x15, 0x28);
        func_001E3210(p, 0x20);
    }
}
