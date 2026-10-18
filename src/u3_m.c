typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00478440[];
extern s32 D_004784C0[];
extern s32 D_004783C0[];
extern s32 D_00478340[];
extern void func_003EB4A0(u8 *, u8 *, s32);
extern void func_003EB810(u8 *, u8 *, s32);

void func_003EB3B0(u8 *dst, u8 *src, s32 m) {
    s32 i, j;
    s32 *tp = D_00478440;
    s32 u, v;
    for (i = 0; i < 8; i++) {
        u = i * 16;
        for (j = 0, v = 0; j < 4; j++) {
            s32 k = *tp++;
            func_003EB4A0(dst + (u << 6) + v, src + m * (D_004783C0[k] << 11) + (D_00478340[k] << 5), m);
            v += 16;
        }
    }
}

void func_003EB720(u8 *dst, u8 *src, s32 m) {
    s32 i, j;
    s32 *tp = D_004784C0;
    s32 u, v;
    for (i = 0; i < 4; i++) {
        u = i * 16;
        for (j = 0, v = 0; j < 8; j++) {
            s32 k = *tp++;
            func_003EB810(dst + (u << 7) + v, src + m * (D_004783C0[k] << 11) + (D_00478340[k] << 5), m);
            v += 16;
        }
    }
}
