typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002A6030(u8 *p) {
    u8 *s0 = *(u8 **)(p + 0x1DC);
    u32 v[3];
    s8 t;
    s16 v16;
    extern void func_00175700(u8 *);
    extern s32 func_00182E20(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001548D0(u8 *, u32 *, s32);
    extern void func_001757E0(u8 *, s32, s32);

    func_00175700(p);
    if (func_00182E20(p) != 0) {
        p[0x152] = 1;
    }
    if ((*(s16 *)(p + 0x1E) == 0 && func_00182D30(*(u8 **)(p + 0x1DC)) != 0)
        || (*(s16 *)(p + 0x1E) == 0 && (v16 = *(s16 *)(p + 0x1C) - 1, *(s16 *)(p + 0x1C) = v16, v16 == 0))
        || (*(s16 *)(p + 0x1E) == 0 && *(s16 *)(s0 + 0x434) == 0)) {
        *(s16 *)(p + 0x1E) = 1;
    }
    t = p[0x151];
    if (t != 0) {
        t = (s8)t;
        if (t > 0) {
            s0[0x1B5] = (t & 1) ? 0x21 : 0x22;
            func_0018FDB0(p);
            func_001E3710(p, 0xF);
            p[0x151] = 0;
            v[0] = 0xC2DC0000;
            v[1] = 0x430B4924;
            v[2] = 0;
            func_001548D0(p, v, 1);
            return;
        }
        if (*(s16 *)(p + 0x1E) != 0) {
            u32 u = p[6];
            p[6] = u + 1;
            func_001757E0(p, 0xF, 1);
        }
    }
}
