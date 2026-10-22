typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0020DA10(u8 *p, s32 a1)
{
    extern void func_00175700();
    extern void func_0020F250(u8 *);
    extern void func_0020DD10(u8 *, s32);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *v5c, *v60, *v68, *v6c;
    s32 m;
    v6c = (f32 *)(p + 0x6C);
    v68 = (f32 *)(p + 0x68);
    v60 = (f32 *)(p + 0x60);
    v5c = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_0020F250(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_0020DD10(p, a1);
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (((s8)*(s8 *)(p + 0x1B2) & 0x11) != 0) goto act;
        if ((*(u8 **)(p + 0x1C4))[0x216] != 0) goto act;
    }
    m = *(s8 *)(p + 0x211) & 3;
    if (m != 0) {
        if ((m & (p[0x1E6] + 1)) == 0) goto act;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6] = 4;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(s32 *)v5c = 0;
        *(s32 *)v60 = 0;
        *(s32 *)v68 = 0;
        *(s32 *)v6c = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x1B);
        return;
    } else {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h != 0) return;
    }
act:
    {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(s32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 0x35);
    }
}
