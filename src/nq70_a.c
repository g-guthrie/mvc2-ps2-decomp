typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef int s32;
typedef struct { unsigned char pad[0x430]; f32 g; } O;
typedef struct { unsigned char pad[0x38]; f32 y; } PY;
void func_003A62A0(u8 *p, u8 *o)
{
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    f32 z;
    f32 *a, *b;
    func_00175700(p);
    a = (f32 *)(p + 0x5C); b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    z = 0.0f;
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) { *a = z; *b = z; }
    if (!(((O *)o)->g < ((PY *)p)->y)) {
        p[5]++; *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430); *(s16 *)(p + 0x1C) = 12;
        return;
    }
    switch (*(s8 *)(p + 0x1B3)) { case 0: break; default: { p[5]++; *(s16 *)(p + 0x1C) = 1; return; } }
    func_001E7F60(p);
    if (*(s8 *)(p + 0x1B2) != 0) { p[5]++; *(s16 *)(p + 0x1C) = 1; }
}
