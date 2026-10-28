typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A5[];
extern s32 (*D_00446160[])(u8 *);
extern s32 func_00169A50(u8 *);

static inline s32 step_nq42c(u8 *p) {
    s8 v;
    D_004D18A5[0] = 0;
    v = *(s8 *)(p + 0x45E) + 1;
    *(s8 *)(p + 0x45E) = v;
    if (v >= *(s8 *)(p + 0x45F)) {
        *(s8 *)(p + 0x45F) = *(s8 *)(p + 0x45E);
        if (*(s8 *)(p + 0x45F) > 0x1F) {
            return 0;
        }
    }
    if (p[5] != 0) {
        return 0;
    }
    if (p[0x494] != 0) {
        return func_00169A50(p);
    }
    return D_00446160[p[0x450]](p);
}

s32 func_00169600(u8 *p) {
    s32 r;
    do {
        r = step_nq42c(p);
    } while (r == 1);
    switch (r) {
    default:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
