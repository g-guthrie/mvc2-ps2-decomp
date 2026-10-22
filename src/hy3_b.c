typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef float f32;

void func_003CD9B0(u8 *a, u8 *b)
{
    extern void func_003CDB80(u8 *, u8 *);
    extern s8 func_00175670(u8 *);
    if (b[0x1E4] == 0x1D) goto call;
    if (b[5] != 0) goto call;
    if (*(s8 *)(b + 0x1B4) != 0) return;
    if (*(s8 *)(a + 0x31) != 0) a[0x24] = *(s8 *)(b + 0x24);
    switch (a[0x20]) {
    case 4:
    case 3:
        if (*(s32 *)(a + 0xD0) != *(u16 *)(b + 0x168)) goto call;
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    case 2:
    case 1:
        *(s8 *)(a + 0x152) = *(s8 *)(b + 0x152);
    case 0:
        if (func_00175670(a) < 0) goto call;
        if (*(s8 *)(a + 0x151) != 0) {
            f32 v = *(f32 *)(a + 0x118) - 0.125f;
            f32 z = 0.0f;
            *(f32 *)(a + 0x118) = v;
            if (v <= z) *(f32 *)(a + 0x118) = z;
        }
        break;
    case 6:
    case 5:
        func_00175670(a);
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        if (*(f32 *)(a + 0x38) < *(f32 *)(b + 0x430)) {
            u32 t;
            *(f32 *)(a + 0x38) = *(f32 *)(b + 0x430);
            *(f32 *)(a + 0x60) = -*(f32 *)(a + 0x60);
            *(f32 *)(a + 0x60) /= 2.0f;
            *(s16 *)(a + 0x1C) = 1;
            t = a[0x22] ^ 1;
            a[0x22] = t;
            if ((t & 0xFF) == 0) goto call;
        }
        break;
    default:
        break;
    }
    return;
call:
    func_003CDB80(a, b);
}
