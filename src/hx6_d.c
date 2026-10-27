typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F20E0(u8 *p)
{
    extern void func_00183D90(u8 *);
    extern s32 func_00175700(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185770(u8 *, u8 *);
    u32 tmp[3];
    u8 *s0;

    *(s16 *)(p + 0x3F8) = 2;
    func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if ((s0 = func_001E7FD0(p)) != 0) {
        p[6] = 5;
        p[7] = 0;
        tmp[0] = 0xC312AAAA;
        tmp[1] = 0x432B6DB6;
        func_0015D010(p, tmp);
        func_001266A0(p, 5, 5);
        p[0x20B] = 0xC6;
        func_001757E0(p, 0xF, 0x1D);
        func_00185770(p, s0);
    } else {
        *(s16 *)(p + 0x1E) = 0;
        if (p[0x1E6] != 0) {
            if (*(s8 *)(p + 0x211) & 1) {
                *(s16 *)(p + 0x1E) = 1;
            }
        } else {
            if (*(s8 *)(p + 0x211) & 2) {
                *(s16 *)(p + 0x1E) = 1;
            }
        }
        if (*(s16 *)(p + 0x1E) != 0 || (*(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1) == 0) {
            {
                u32 t6 = p[6];
                p[6] = t6 + 1;
            }
            func_001757E0(p, 0xF, 0x17);
        }
    }
}
