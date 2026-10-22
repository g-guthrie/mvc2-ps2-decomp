typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0031EBA0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00354460(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    f32 *v5c, *v68;
    s32 m;
    s16 h;
    v68 = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v5c = (f32 *)(p + 0x5C);
    m = *(s8 *)(p + 0x211);
    if (m != 0) {
        if ((s8)m != (1 << p[0x1E6])) goto reset;
    }
    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x20) > 0) return;
        if (*(s16 *)(p + 0x1C) <= 1) return;
        if (*(s8 *)(p + 0x539) == 0) {
            if (((u16)(*(u16 *)(p + 0x35C) | *(u16 *)(p + 0x366)) & 0x300) != 0) {
                p[0x20] = 0xFF;
                *(s16 *)((s32)p + 0x366) = 0;
            }
        } else if (p[0x425] == 0) {
            p[0x20] = 0xFF;
        }
        goto done;
    }
    {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) goto reset;
        h = *(s16 *)(p + 0x1E) ^ 1;
        *(s16 *)(p + 0x1E) = h;
        if (h != 0) {
            if (p[0x20] != 0) {
                p[0x20] = 0;
            } else {
                p[0x20] = 1;
                *(s16 *)(p + 0x1C) = 1;
            }
            if (*(s16 *)(p + 0x1C) == 1) p[0x20] = 1;
        }
        func_00354460(p, *(s16 *)(p + 0x1E));
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + (*(s16 *)(p + 0x1E) * 3 + 0x19)));
        func_001E3210(p, 0x1F);
        return;
    }
reset:
    {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(s32 *)v5c = 0;
        *(s32 *)v68 = 0;
        func_001757E0(p, 0x15, 0x1F);
    }
done:
    ;
}
