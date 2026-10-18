typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00323180(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_003266E0(u8 *);
    u32 t = p[6];
    if (t == 0) {
        f32 v;
        p[6] = t + 1;
        v = 10.833333015441895f;
        if (*(s16 *)(p + 0x140) != 0)
            v = -v;
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x68) = 0;
        *(s16 *)(p + 0x1C) = 30;
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0)
            func_003266E0(p);
    }
}



void func_002D6D50(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *b, *c, *d;
    f32 v;
    a = (u32 *)(p + 0x5C);
    b = (u32 *)(p + 0x60);
    c = (u32 *)(p + 0x68);
    d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) <= 0) {
        p[6]++;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        if (p[0x1E6] != 0)
            v = 6.666666507720947f;
        else
            v = -6.666666507720947f;
        *(f32 *)(p + 0x5C) = v;
        func_001757E0(p, 2, 2);
    }
}
