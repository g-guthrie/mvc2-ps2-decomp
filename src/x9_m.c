typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F7FC8[];

s32 func_0018A380(u8 *a0, u8 *a1, s8 *a2, s32 a3) {
    extern s32 func_0018A460();
    if ((u16)a3 & 0x120) {
        s32 t = D_004F7FC8[a0[2]];
        if (a2[1] - (t * 10 + 4) >= 0) {
            return func_0018A460(a0, a1, a2, a3);
        }
        if ((*(u16 *)(a1 + 2) & 0x8600) == 0) {
            a3 = (u16)(a3 & 0xFEDF);
        }
    }
    if ((u16)a3 & 0x2D0) {
        s32 t = D_004F7FC8[a0[2]];
        if (a2[1] - (t * 10 + 2) >= 0) {
            return func_0018A460(a0, a1, a2, a3);
        }
    }
    a2[0] = 0;
    return 0;
}

